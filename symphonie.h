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

void callback_about (GtkMenuItem *itemAbout, gpointer user_data);

void on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer user_data);

void on_SearchEntry_search_changed();

void on_setNumberResultsButton_clicked(gpointer user_data);

void on_closePreference_clicked();

void deleteChildren();

void insertChildren();

#endif /* _SYMPHONIE_H_ */
