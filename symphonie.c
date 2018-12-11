#include <gtk/gtk.h>
      typedef struct
      {
        GtkBuilder *builder;
        gpointer user_data;
      } SGlobalData;
        SGlobalData data;
      void callback_about (GtkMenuItem *itemAbout, gpointer user_data);

      void on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer user_data);
      
      void on___glade_unnamed_23_search_changed();
      
      void deleteChildren();
      
      void insertChildren();

      int
      main(int argc, char *argv [])
      {
      
        GtkWidget *fenetre_principale = NULL;

        GError *error = NULL;
        gchar *filename = NULL;
        /* Initialisation de la bibliothèque Gtk. */
        gtk_init(&argc, &argv);

        /* Ouverture du fichier Glade de la fenêtre principale */
        data.builder = gtk_builder_new();

        /* Création du chemin complet pour accéder au fichier window.glade. */
        /* g_build_filename(); construit le chemin complet en fonction du système */
        /* d'exploitation. ( / pour Linux et \ pour Windows) */
        filename =  g_build_filename ("window.glade", NULL);

        /* Chargement du fichier window.glade. */
        gtk_builder_add_from_file (data.builder, filename, &error);
        g_free (filename);
        if (error)
        {
          gint code = error->code;
          g_printerr("%s\n", error->message);
          g_error_free (error);
          return code;
        }

        /* Affectation des signaux de l'interface aux différents CallBacks. */
        gtk_builder_connect_signals (data.builder, &data);

        /* Récupération du pointeur de la fenêtre principale */
        fenetre_principale = GTK_WIDGET(gtk_builder_get_object (data.builder, "MainWindow"));
        
        
        /* Affichage de la fenêtre principale. */
        gtk_widget_show_all (fenetre_principale);

        gtk_main();
        
        
        return 0;
      }
      

      void
      callback_about (GtkMenuItem *itemAbout, gpointer user_data)
      {
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
      
      void
      on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer user_data)
      {
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
      
      void
      
      on___glade_unnamed_23_search_changed()
      {
      	
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
	  NULL
	};  	      	
        
        deleteChildren();    
        insertChildren(tab);
        
      }
      
      void insertChildren(char* tab[]){
      
      	GtkWidget *flow_box = NULL;
      	
      	printf("insert\n"); 
      	
      	
	
        
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
      
      void deleteChildren(){
      	GtkContainer *flow_box = NULL;
      	flow_box = (GtkContainer*)GTK_WIDGET (gtk_builder_get_object (data.builder, "FlowBox"));
      	
      	GList* children = gtk_container_get_children (flow_box);
      	
      	printf("delete\n");
      	
      	
        while(children){
		gtk_widget_destroy(children->data);
		children = children->next;
        }
      }
     
     
