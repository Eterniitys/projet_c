#ifndef _SYMPHONIE_H_
#define _SYMPHONIE_H_

#include <gtk/gtk.h>
#include <hash.h>
#include <parser.h>
#include <phonetics.h>
#include <syllabification.h>
#include <tree.h>

typedef struct {
  GtkBuilder *builder;
  gpointer user_data;
} SGlobalData;

/**
 * \fn void callback_about(GtkMenuItem *itemAbout, gpointer user_data)
 *
 * Display the window named "A propos".
 * \return void
 */
void callback_about(GtkMenuItem *itemAbout, gpointer user_data);

/**
 * \fn void on_itemPreference_activate(GtkMenuItem *itemPreference, gpointer
 * user_data)
 *
 * Display the window named "Préférences".
 * \return void
 */
void on_itemPreference_activate(GtkMenuItem *itemPreference,
                                gpointer user_data);

/**
 * \fn void on_SearchEntry_search_changed()
 *
 * Code executed each time the text of the field "SearchEntry" is modified.
 * Search new rhymes and filled the flowbox.
 * \return void
 */
void on_SearchEntry_search_changed();

/**
 * \fn void on_setNumberResultsButton_clicked()
 *
 * Get the number of results wanted by the user.
 * \return void
 */
void on_setNumberResultsButton_clicked();

/**
 * \fn void on_closePreference_clicked()
 *
 * Close the window named "Préférences" when button is clicked.
 * \return void
 */
void on_closePreference_clicked();

/**
 * \fn void deleteChildren()
 *
 * Delete results in the flowbox from a list.
 * \return void
 */
void deleteChildren();

/**
 * \fn void insertChildren()
 *
 * Insert results in the flowbox from a list.
 * \return void
 */
void insertChildren();

#endif /* _SYMPHONIE_H_ */
