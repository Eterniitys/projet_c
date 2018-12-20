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


//Main code of the graphical interface
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



//Code of the window : A propos
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


//Code of the window : Préférences
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



//Code executed each time the text of the field is modified : SearchEntry
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

	deleteChildren();

	if (mot[0] != '\0'){
		char** syllables = syllabicate(root_syll, mot);
		char ** phonetics = fill_phonetics(syllables,map_syl_phon);
		char * string_phon = tab_to_string(phonetics);

		char* tab[] = { 
			"Perlis",
			"Wilkes",
			"Hamming",
			"Minsky",
			"Wilkinson",
			"McCarthy",
			"Dijkstra",
			"Bachman",
			"Knuth",
			"Newell et Simon",
			"Perlis",
			"Wilkes",
			"Hamming",
			"Minsky",
			"Wilkinson",
			"McCarthy",
			"Dijkstra",
			"Bachman",
			"Knuth",
			"Newell et Simon",
			"Perlis",
			"Wilkes",
			"Hamming",
			"Minsky",
			"Wilkinson",
			"McCarthy",
			"Dijkstra",
			"Bachman",
			"Knuth",
			"Newell et Simon",
			"Perlis",
			"Wilkes",
			"Hamming",
			"Minsky",
			"Wilkinson",
			"McCarthy",
			"Dijkstra",
			"Bachman",
			"Knuth",
			"Newell et Simon",
			"Perlis",
			"Wilkes",
			"Hamming",
			"Minsky",
			"Wilkinson",
			"McCarthy",
			"Dijkstra",
			"Bachman",
			"Knuth",
			"Newell et Simon",
			"Perlis",
			"Wilkes",
			"Hamming",
			"Minsky",
			"Wilkinson",
			"McCarthy",
			"Dijkstra",
			"Bachman",
			"Knuth",
			"Newell et Simon",
			NULL
		};
		
		insertChildren(tab);		 
	}
}


/*void on_setNumberResultsButton_clicked(self, button){
	printf("on_setNumberResultsButton_clicked\n");
}*/


//Code to populate the flow_box
void insertChildren(char* tab[]) {

	GtkWidget *flow_box = NULL;
	flow_box = GTK_WIDGET (gtk_builder_get_object (data.builder, "FlowBox"));

	int i = 0;
	while(tab[i]!=NULL){
		GtkWidget * gtk_flow_box_child_new ();
		char* str = tab[i];
		GtkWidget *label = gtk_label_new (str);
		gtk_flow_box_insert ((GtkFlowBox*)flow_box, label, i);
		gtk_widget_show(label);
		i++; 
	}
}


//Code for removing children from the flow_box before adding the new ones
void deleteChildren() {

	GtkContainer *flow_box = NULL;
	flow_box = (GtkContainer*)GTK_WIDGET (gtk_builder_get_object (data.builder, "FlowBox"));

	GList* children = gtk_container_get_children (flow_box);

	while(children){
		gtk_widget_destroy(children->data);
		children = children->next;
	}
}
