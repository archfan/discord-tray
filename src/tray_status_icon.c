#ifdef HAVE_CONFIG_H
#include "../config.h"
#endif

#include <gtk/gtk.h>
#include "tray_status_icon.h"


void on_quit_activate(GtkWidget *menuitem, gpointer user_data)
{
	GdkWindow *client_window = GDK_WINDOW(user_data);

	gdk_window_destroy(client_window);
	gtk_main_quit();
}


/* Right click callback: show popup menu. */
static void on_popup(GtkStatusIcon *icon, guint button,
		guint activate_time, gpointer user_data)
{
	GtkWidget *popup_menu = GTK_WIDGET(user_data);

	gtk_widget_show_all(popup_menu);
	gtk_menu_popup(GTK_MENU(popup_menu), NULL, NULL, NULL, NULL,
		button, activate_time);
}

/* Left click callback: toggle the Discord window visibility. */
static void on_activate(GtkStatusIcon *icon, gpointer user_data)
{
	GdkWindow *client_window = GDK_WINDOW(user_data);

	if (gdk_window_is_visible(client_window)) {
		gdk_window_hide(client_window);
	} else {
		gdk_window_show(client_window);
	}
}

/* Set up the right-click popup menu. */
static GtkMenu *new_popup_menu(GdkWindow *client_window)
{
	GtkWidget *popup_menu = gtk_menu_new();
	GtkWidget *quit_menu_item =
		gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
	
	gtk_menu_shell_append(GTK_MENU_SHELL(popup_menu), quit_menu_item);
	
	g_signal_connect((gpointer) quit_menu_item, "activate",
			G_CALLBACK(on_quit_activate), client_window);

	gtk_widget_show_all(GTK_WIDGET(popup_menu));

	return GTK_MENU(popup_menu);
}

/* Creates a new tray icon: assumes the Discord client is properly installed
 * and uses its icon. Installs the popup_menu as the right-click menu and
 * lets left click to show/hide the Discord cient window. */
void new_tray_icon(GdkWindow *client_window)
{
	GtkStatusIcon *tray_icon =
		gtk_status_icon_new_from_icon_name("discord");
	gtk_status_icon_set_has_tooltip(tray_icon, FALSE);
	gtk_status_icon_set_visible(tray_icon, TRUE);
	g_signal_connect((gpointer) tray_icon, "popup-menu",
		G_CALLBACK(on_popup), new_popup_menu(client_window));
	g_signal_connect((gpointer) tray_icon, "activate",
		G_CALLBACK(on_activate), client_window);
}
