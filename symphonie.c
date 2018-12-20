#include <gtk/gtk.h>
#include <stdio.h>
#include "symphonie.h"
#include <tree.h>
#include <hash.h>
#include <phonetics.h>
#include <syllabification.h>
#include <parser.h>


#include <word.h>
#include <string.h>
#include <list.h>
#include <rhyme.h>

SGlobalData data;
Tree* root_phon;
Tree* root_syll;
Hashmap* map_syl_phon;
int nbResults = 20;


/*
 *Initializing the Gtk Library
 *Opening the main window file
 *Creating the full path to access the window.glade file
 *g_build_filename () builds the full path depending on the operating system. (/ for Linux and \ for Windows)
 *Loading the window.glade file
 *Assignment of interface signals to different CallBacks
 *Recovering the pointer from the software loading popup window
 *Closing the loading popup and then displaying the main window
 */
int main(int argc, char *argv []) {

	GtkWindow *main_window = NULL;
	GtkWindow *start_window = NULL;
	GError *error = NULL;
	gchar *filename = NULL;


	gtk_init(&argc, &argv);
	data.builder = gtk_builder_new();
	filename =  g_build_filename ("window.glade", NULL);
	gtk_builder_add_from_file (data.builder, filename, &error);
	g_free (filename);
	
	if (error){
		gint code = error->code;
		g_printerr("%s\n", error->message);
		g_error_free (error);
		return code;
	}

	gtk_builder_connect_signals (data.builder, &data);
	start_window = (GtkWindow*)GTK_WIDGET(gtk_builder_get_object (data.builder, "StartWindow"));
	gtk_widget_show_all((GtkWidget*)start_window);


	while(gtk_events_pending()){
		gtk_main_iteration();
	}

	parser_read("./Lexique382.csv", &root_phon, &root_syll, &map_syl_phon);

	gtk_window_close(start_window);
	main_window = (GtkWindow*)GTK_WIDGET(gtk_builder_get_object (data.builder, "MainWindow"));
        
	gtk_widget_show_all ((GtkWidget*)main_window);

	gtk_main();
	return 0;
}




/*
 *Casting the user_data pointer to retrieve our data
 *Retrieving the "AboutWindow" window
 *We hide the dialog window. If we destroy it the next call to this callback would cause a segdefault!
 */
void callback_about (GtkMenuItem *itemAbout, gpointer user_data) {

	SGlobalData *data = (SGlobalData*) user_data;
	GtkWidget *dialog = NULL;

	dialog =  GTK_WIDGET (gtk_builder_get_object (data->builder, "AboutWindow"));
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_hide (dialog);
}



/*
 *Casting the user_data pointer to retrieve our data
 *Retrieving the "PreferenceWindow" window
 *We hide the dialog window. If we destroy it the next call to this callback would cause a segdefault!
 */
void on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer user_data) {

	SGlobalData *data = (SGlobalData*) user_data;
	GtkWidget *dialog = NULL;

	dialog =  GTK_WIDGET (gtk_builder_get_object (data->builder, "PreferenceWindow"));
	gtk_dialog_run (GTK_DIALOG (dialog));

	gtk_widget_hide (dialog);
}

void reverse_string(char * word){
        int i=0;
        int len = strlen(word);
        char temp;
        for (i=0 ; i<len/2 ; i++) {
                temp = word[len-i-1];
                word[len-i-1] = word[i];
                word[i] = temp;
        }
}

/*
 *Retrieving the widget from the search bar
 *Recovering the string typed in the search bar
 *We empty the flow_box so that we can then fill it
 *If there is at least one search character in the search bar you run
 *Creating the table that populates the flow_box
 */
void on_SearchEntry_search_changed() {

	GtkEntry *entry = NULL;

	entry = (GtkEntry*)GTK_WIDGET (gtk_builder_get_object (data.builder, "SearchEntry"));
	GtkEntryBuffer *buffer = gtk_entry_get_buffer (entry);
	const char* mot = gtk_entry_buffer_get_text(buffer);
	fprintf(stderr, "%s\n", mot);
	int i = 0;
	while (mot[i]) {
		fprintf(stderr, "%c %d\n", mot[i]);
		i++;
	}

	deleteChildren();

	if (mot[0] != '\0'){
		char** syllables = syllabicate(root_syll, mot);
		if (!syllables)
			return;
		char ** phonetics = fill_phonetics(syllables,map_syl_phon);
		if (!phonetics)
			return;
		char * string_phon = tab_to_string(phonetics);
		if (!string_phon)
			return;

		reverse_string(string_phon);

		fprintf(stderr, "LIMITE %d\n", nbResults);

		List* liste = match_word(root_phon, nbResults, string_phon);
		if (!liste)
			return;

		insertChildren(liste);
	}
}


void on_setNumberResultsButton_clicked(){
	GtkSpinButton *spin_button = (GtkSpinButton*)GTK_WIDGET(gtk_builder_get_object (data.builder, "spinNumber"));
	nbResults = gtk_spin_button_get_value_as_int (spin_button);
	GtkWindow *preference_window = (GtkWindow*)GTK_WIDGET(gtk_builder_get_object (data.builder, "PreferenceWindow"));
	gtk_window_close(preference_window);
}

void on_closePreference_clicked(){
	GtkWindow *preference_window = (GtkWindow*)GTK_WIDGET(gtk_builder_get_object (data.builder, "PreferenceWindow"));
	gtk_window_close(preference_window);
}



void insertChildren(List* liste) {

	GtkWidget *flow_box = NULL;
	flow_box = GTK_WIDGET (gtk_builder_get_object (data.builder, "FlowBox"));

	for(int i = 0; i < list_count(liste); i++){
		GtkWidget * gtk_flow_box_child_new ();
		char* str = (char*)list_get(liste,i);
		fprintf(stderr, "%s\n", str);
		GtkWidget *label = gtk_label_new (str);
		gtk_flow_box_insert ((GtkFlowBox*)flow_box, label, i);
		gtk_widget_show(label);
	}
}



void deleteChildren() {

	GtkContainer *flow_box = NULL;
	flow_box = (GtkContainer*)GTK_WIDGET (gtk_builder_get_object (data.builder, "FlowBox"));

	GList* children = gtk_container_get_children (flow_box);

	while(children){
		gtk_widget_destroy(children->data);
		children = children->next;
	}
}
