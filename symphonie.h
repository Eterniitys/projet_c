#ifndef _SYMPHONIE_H_
#define _SYMPHONIE_H_

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

extern void callback_about (GtkMenuItem *itemAbout, gpointer user_data);

extern void on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer user_data);

extern void on_SearchEntry_search_changed();

//extern void on_setNumberResultsButton_clicked(self, button);

extern void deleteChildren();

extern void insertChildren();

#endif /* _SYMPHONIE_H_ */
