#include <gtk/gtk.h>
#include <tree.h>
#include <hash.h>
#include <phonetics.h>
#include <syllabification.h>
#include <parser.h>

typedef struct {
	GtkBuilder *builder;
	gpointer user_data;
} SGlobalData;
SGlobalData data;
Tree* root_phon;
Tree* root_syll;
Hashmap* map_syl_phon;


//Code de la fenêtre : A propos
void callback_about (GtkMenuItem *itemAbout, gpointer user_data);

//Code de la fenêtre : Préférences
void on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer user_data);

//Code executé à chaque fois que l'on modifie le texte du champ : SearchEntry
void on___glade_unnamed_23_search_changed();

//Code de supression des enfants de la flow_box avant de rajouter les nouveaux
void deleteChildren();

//Code pour peupler la flow_box
void insertChildren();


int main(int argc, char *argv []) {

	GtkWindow *fenetre_principale = NULL;
	GtkWindow *fenetre_lancement = NULL;
	GError *error = NULL;
	gchar *filename = NULL;


	/* Initialisation de la bibliothèque Gtk. */
	gtk_init(&argc, &argv);

	/* Ouverture du fichier de la fenêtre principale */
	data.builder = gtk_builder_new();

	/* Création du chemin complet pour accéder au fichier window.glade. */
	/* g_build_filename(); construit le chemin complet en fonction du système */
	/* d'exploitation. ( / pour Linux et \ pour Windows) */
	filename =  g_build_filename ("window.glade", NULL);

	/* Chargement du fichier window.glade. */
	gtk_builder_add_from_file (data.builder, filename, &error);
	g_free (filename);
	if (error){
		gint code = error->code;
		g_printerr("%s\n", error->message);
		g_error_free (error);
		return code;
	}

	/* Affectation des signaux de l'interface aux différents CallBacks. */
	gtk_builder_connect_signals (data.builder, &data);

	/* Récupération du pointeur de la fenêtre popup de chargement du logiciel */
	fenetre_lancement = (GtkWindow*)GTK_WIDGET(gtk_builder_get_object (data.builder, "StartWindow"));

	/* Affichage de la fenêtre popup de chargement du logiciel. */
	gtk_widget_show_all((GtkWidget*)fenetre_lancement);

	//Permet d'attendre que toutes les données soit chargés
	while(gtk_events_pending()){gtk_main_iteration();}

	parser_read("./Lexique382.csv", &root_phon, &root_syll, &map_syl_phon);

	//On ferme la popup de chargement pour ensuite afficher la fenêtre principale
	gtk_window_close(fenetre_lancement);

	/* Récupération du pointeur de la fenêtre principale */
	fenetre_principale = (GtkWindow*)GTK_WIDGET(gtk_builder_get_object (data.builder, "MainWindow"));


	/* Affichage de la fenêtre principale. */
	gtk_widget_show_all((GtkWidget*)fenetre_principale);

	gtk_main();


	return 0;
}


void callback_about (GtkMenuItem *itemAbout, gpointer user_data) {
	/* Transtypage du pointeur user_data pour récupérer nos données. */
	SGlobalData *data = (SGlobalData*) user_data;
	GtkWidget *dialog = NULL;


	/* Récupération de la fenêtre "AboutWindow". */
	dialog =  GTK_WIDGET (gtk_builder_get_object (data->builder, "AboutWindow"));
	gtk_dialog_run (GTK_DIALOG (dialog));

	/* On cache la fenêtre de dialogue. Si on la détruisait le prochain appel */
	/* à ce callback provoquerait un segdefault! */
	gtk_widget_hide (dialog);
}

void on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer user_data) {
	/* Transtypage du pointeur user_data pour récupérer nos données. */
	SGlobalData *data = (SGlobalData*) user_data;
	GtkWidget *dialog = NULL;


	/* Récupération de la fenêtre "AboutWindow". */
	dialog =  GTK_WIDGET (gtk_builder_get_object (data->builder, "PreferenceWindow"));
	gtk_dialog_run (GTK_DIALOG (dialog));

	/* On cache la fenêtre de dialogue. Si on la détruisait le prochain appel */
	/* à ce callback provoquerait un segdefault! */
	gtk_widget_hide (dialog);


}

void on___glade_unnamed_23_search_changed() {

	GtkEntry *entry = NULL;

	//On récupère le widget de la barre de rechercher
	entry = (GtkEntry*)GTK_WIDGET (gtk_builder_get_object (data.builder, "SearchEntry"));

	GtkEntryBuffer *buffer = gtk_entry_get_buffer (entry);

	//On récupère la chaîne de caractère tapée dans la barre de recherche 
	const char* mot = gtk_entry_buffer_get_text(buffer);

	//On vide la flow_box pour pour pouvoir la remplire ensuite
	deleteChildren();

	//Si il y a au moins un caractère recherché dans la barre de recherche on exècute
	if (mot[0] != '\0'){

		char** syllables = syllabicate(root_syll, mot);

		char ** phonetics = fill_phonetics(syllables,map_syl_phon);
		char * string_phon = tab_to_string(phonetics);

		//Création du tableau qui permet de peupler la flow_box
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

void deleteChildren() {

	GtkContainer *flow_box = NULL;
	flow_box = (GtkContainer*)GTK_WIDGET (gtk_builder_get_object (data.builder, "FlowBox"));

	GList* children = gtk_container_get_children (flow_box);

	while(children){
		gtk_widget_destroy(children->data);
		children = children->next;
	}
}




