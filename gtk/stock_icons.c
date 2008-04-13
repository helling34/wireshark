/* stock_icons.c
 * Wireshark specific stock icons
 * Copyright 2003-2008, Ulf Lamping <ulf.lamping@web.de>
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gtk/gtk.h>

#include "gtk/stock_icons.h"

/* these icons are derived from the original stock icons */
#ifdef HAVE_LIBPCAP
#include "../image/toolbar/capture_interfaces_24.xpm"
#include "../image/toolbar/capture_options_24.xpm"
#include "../image/toolbar/capture_start_24.xpm"
#include "../image/toolbar/capture_stop_24.xpm"
#include "../image/toolbar/capture_restart_24.xpm"
#include "../image/toolbar/capture_filter_24.xpm"
#include "../image/toolbar/capture_details_24.xpm"
#endif /* HAVE_LIBPCAP */
#include "../image/toolbar/display_filter_24.xpm"
/* these icons are standard stock icons, but used for Wireshark specific stock icon labels */
#include "../image/toolbar/stock_add_24.xpm"
#include "../image/toolbar/stock_open_24.xpm"
#include "../image/toolbar/stock_ok_20.xpm"
#include "../image/toolbar/stock_save_24.xpm"
#include "../image/toolbar/stock_properties_24.xpm"
#include "../image/wsicon16.xpm"
#include "../image/toolbar/colorize_24.xpm"
#include "../image/toolbar/autoscroll_24.xpm"
#include "../image/toolbar/resize_columns_24.xpm"
#include "../image/toolbar/time_24.xpm"
#include "../image/toolbar/internet_24.xpm"
#include "../image/toolbar/web_support_24.xpm"
#include "../image/toolbar/wiki_24.xpm"
#include "../image/toolbar/conversations_16.xpm"
#include "../image/toolbar/endpoints_16.xpm"
#include "../image/toolbar/graphs_16.xpm"
#include "../image/toolbar/telephony_16.xpm"
#include "../image/toolbar/decode_as_16.xpm"
#include "../image/toolbar/checkbox_16.xpm"
#include "../image/toolbar/file_set_list_16.xpm"
#include "../image/toolbar/file_set_next_16.xpm"
#include "../image/toolbar/file_set_previous_16.xpm"
#include "../image/toolbar/stock_close_24.xpm"
#include "../image/toolbar/icon_color_1.xpm"
#include "../image/toolbar/icon_color_2.xpm"
#include "../image/toolbar/icon_color_3.xpm"
#include "../image/toolbar/icon_color_4.xpm"
#include "../image/toolbar/icon_color_5.xpm"
#include "../image/toolbar/icon_color_6.xpm"
#include "../image/toolbar/icon_color_7.xpm"
#include "../image/toolbar/icon_color_8.xpm"
#include "../image/toolbar/icon_color_9.xpm"
#include "../image/toolbar/icon_color_0.xpm"


typedef struct stock_pixmap_tag{
    const char *    name;
    const char **   xpm_data;
} stock_pixmap_t;

/* generate application specific stock items */
void stock_icons_init(void) {
    GtkIconFactory * factory;
    gint32 i;


    /* register non-standard pixmaps with the gtk-stock engine */
    static const GtkStockItem stock_items[] = {
#ifdef HAVE_LIBPCAP
        { WIRESHARK_STOCK_CAPTURE_INTERFACES,    "_Interfaces",    0, 0, NULL },
        { WIRESHARK_STOCK_CAPTURE_OPTIONS,       "_Options",       0, 0, NULL },
        { WIRESHARK_STOCK_CAPTURE_START,         "_Start",         0, 0, NULL },
        { WIRESHARK_STOCK_CAPTURE_STOP,          "S_top",          0, 0, NULL },
        { WIRESHARK_STOCK_CAPTURE_RESTART,       "_Restart",       0, 0, NULL },
        { WIRESHARK_STOCK_CAPTURE_FILTER,        "_CFilter",        0, 0, NULL },
        { WIRESHARK_STOCK_CAPTURE_FILTER_ENTRY,  "_Capture Filter:",  0, 0, NULL },
        { WIRESHARK_STOCK_CAPTURE_DETAILS,       "_Details",       0, 0, NULL },
#endif
        { WIRESHARK_STOCK_DISPLAY_FILTER,        "_Filter",        0, 0, NULL },
        { WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY,  "_Filter:",  0, 0, NULL },
        { WIRESHARK_STOCK_BROWSE,                "_Browse...",                0, 0, NULL },
        { WIRESHARK_STOCK_CREATE_STAT,           "Create _Stat",           0, 0, NULL },
        { WIRESHARK_STOCK_EXPORT,                "_Export...",                0, 0, NULL },
        { WIRESHARK_STOCK_IMPORT,                "_Import...",                0, 0, NULL },
        { WIRESHARK_STOCK_EDIT,                  "_Edit...",                  0, 0, NULL },
        { WIRESHARK_STOCK_ADD_EXPRESSION,        "_Expression..." ,        0, 0, NULL }, /* plus sign coming from icon */
        { WIRESHARK_STOCK_DONT_SAVE,             "Continue _without Saving",             0, 0, NULL },
        { WIRESHARK_STOCK_ABOUT,                 "_About",                 0, 0, NULL },
        { WIRESHARK_STOCK_COLORIZE,              "_Colorize",              0, 0, NULL },
        { WIRESHARK_STOCK_AUTOSCROLL,            "_Auto Scroll in Live Capture",            0, 0, NULL },
        { WIRESHARK_STOCK_RESIZE_COLUMNS,        "Resize Columns",        0, 0, NULL },
        { WIRESHARK_STOCK_TIME,                  "Time",                  0, 0, NULL },
        { WIRESHARK_STOCK_INTERNET,              "Internet",              0, 0, NULL },
        { WIRESHARK_STOCK_WEB_SUPPORT,           "Web Support",           0, 0, NULL },
        { WIRESHARK_STOCK_WIKI,                  "Wiki",                  0, 0, NULL },
        { WIRESHARK_STOCK_CONVERSATIONS,         "Conversations",         0, 0, NULL },
        { WIRESHARK_STOCK_ENDPOINTS,             "Endpoints",             0, 0, NULL },
        { WIRESHARK_STOCK_GRAPHS,                "Graphs",                0, 0, NULL },
        { WIRESHARK_STOCK_TELEPHONY,             "Telephony",             0, 0, NULL },
        { WIRESHARK_STOCK_DECODE_AS,             "Decode As",             0, 0, NULL },
        { WIRESHARK_STOCK_CHECKBOX,              "Checkbox",              0, 0, NULL },
        { WIRESHARK_STOCK_FILE_SET_LIST,         "List Files",         0, 0, NULL },
        { WIRESHARK_STOCK_FILE_SET_NEXT,         "Next File",         0, 0, NULL },
        { WIRESHARK_STOCK_FILE_SET_PREVIOUS,     "Previous File",     0, 0, NULL },
        { WIRESHARK_STOCK_FILTER_OUT_STREAM,     "Filter Out This Stream",     0, 0, NULL },
        { WIRESHARK_STOCK_ENABLE,                "Enable",                0, 0, NULL },
        { WIRESHARK_STOCK_DISABLE,               "Disable",               0, 0, NULL },
        { WIRESHARK_STOCK_COLOR1,                "Color 1",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR2,                "Color 2",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR3,                "Color 3",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR4,                "Color 4",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR5,                "Color 5",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR6,                "Color 6",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR7,                "Color 7",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR8,                "Color 8",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR9,                "Color 9",                0, 0, NULL },
        { WIRESHARK_STOCK_COLOR0,                "Color 10",                0, 0, NULL }
    };

    static const stock_pixmap_t pixmaps[] = {
#ifdef HAVE_LIBPCAP
        { WIRESHARK_STOCK_CAPTURE_INTERFACES,    capture_interfaces_24_xpm },
        { WIRESHARK_STOCK_CAPTURE_OPTIONS,       capture_options_24_xpm },
        { WIRESHARK_STOCK_CAPTURE_START,         capture_start_24_xpm },
        { WIRESHARK_STOCK_CAPTURE_STOP,          capture_stop_24_xpm },
        { WIRESHARK_STOCK_CAPTURE_RESTART,       capture_restart_24_xpm },
        { WIRESHARK_STOCK_CAPTURE_FILTER,        capture_filter_24_xpm },
        { WIRESHARK_STOCK_CAPTURE_FILTER_ENTRY,  capture_filter_24_xpm },
        { WIRESHARK_STOCK_CAPTURE_DETAILS,       capture_details_24_xpm },
#endif
        { WIRESHARK_STOCK_DISPLAY_FILTER,        display_filter_24_xpm },
        { WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY,  display_filter_24_xpm },
        { WIRESHARK_STOCK_BROWSE,                stock_open_24_xpm },
        { WIRESHARK_STOCK_CREATE_STAT,           stock_ok_20_xpm },
        { WIRESHARK_STOCK_EXPORT,                stock_save_24_xpm },    /* XXX: needs a better icon */
        { WIRESHARK_STOCK_IMPORT,                stock_save_24_xpm },    /* XXX: needs a better icon */
        { WIRESHARK_STOCK_EDIT,                  stock_properties_24_xpm },
        { WIRESHARK_STOCK_ADD_EXPRESSION,        stock_add_24_xpm },
        { WIRESHARK_STOCK_ABOUT,                 wsicon16_xpm },
        { WIRESHARK_STOCK_COLORIZE,              colorize_24_xpm },
        { WIRESHARK_STOCK_AUTOSCROLL,            autoscroll_24_xpm },
        { WIRESHARK_STOCK_RESIZE_COLUMNS,        resize_columns_24_xpm},
        { WIRESHARK_STOCK_TIME,                  time_24_xpm},
        { WIRESHARK_STOCK_INTERNET,              internet_24_xpm},
        { WIRESHARK_STOCK_WEB_SUPPORT,           web_support_24_xpm},
        { WIRESHARK_STOCK_WIKI,                  wiki_24_xpm},
        { WIRESHARK_STOCK_CONVERSATIONS,         conversations_16_xpm},
        { WIRESHARK_STOCK_ENDPOINTS,             endpoints_16_xpm},
        { WIRESHARK_STOCK_GRAPHS,                graphs_16_xpm},
        { WIRESHARK_STOCK_TELEPHONY,             telephony_16_xpm},
        { WIRESHARK_STOCK_DECODE_AS,             decode_as_16_xpm},
        { WIRESHARK_STOCK_CHECKBOX,              checkbox_16_xpm},
        { WIRESHARK_STOCK_FILE_SET_LIST,         file_set_list_16_xpm},
        { WIRESHARK_STOCK_FILE_SET_NEXT,         file_set_next_16_xpm},
        { WIRESHARK_STOCK_FILE_SET_PREVIOUS,     file_set_previous_16_xpm},
        { WIRESHARK_STOCK_FILTER_OUT_STREAM,     display_filter_24_xpm},
        { WIRESHARK_STOCK_ENABLE,                checkbox_16_xpm},
        { WIRESHARK_STOCK_DISABLE,               stock_close_24_xpm},
        { WIRESHARK_STOCK_COLOR1,                icon_color_1_xpm},
        { WIRESHARK_STOCK_COLOR2,                icon_color_2_xpm},
        { WIRESHARK_STOCK_COLOR3,                icon_color_3_xpm},
        { WIRESHARK_STOCK_COLOR4,                icon_color_4_xpm},
        { WIRESHARK_STOCK_COLOR5,                icon_color_5_xpm},
        { WIRESHARK_STOCK_COLOR6,                icon_color_6_xpm},
        { WIRESHARK_STOCK_COLOR7,                icon_color_7_xpm},
        { WIRESHARK_STOCK_COLOR8,                icon_color_8_xpm},
        { WIRESHARK_STOCK_COLOR9,                icon_color_9_xpm},
        { WIRESHARK_STOCK_COLOR0,                icon_color_0_xpm},
        { NULL, NULL }
    };

    /* Register our stock items */
    gtk_stock_add (stock_items, G_N_ELEMENTS (stock_items));

    /* Add our custom icon factory to the list of defaults */
    factory = gtk_icon_factory_new();
    gtk_icon_factory_add_default(factory);

    /* Create the stock items to add into our icon factory */
    for (i = 0; pixmaps[i].name != NULL; i++) {
        GdkPixbuf * pixbuf;
        GtkIconSet *icon_set;

        pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) (pixmaps[i].xpm_data));
        g_assert(pixbuf);
        icon_set = gtk_icon_set_new_from_pixbuf (pixbuf);
        gtk_icon_factory_add (factory, pixmaps[i].name, icon_set);
        gtk_icon_set_unref (icon_set);
        g_object_unref (G_OBJECT (pixbuf));
    }

    /* Drop our reference to the factory, GTK will hold a reference.*/
    g_object_unref (G_OBJECT (factory));
}


