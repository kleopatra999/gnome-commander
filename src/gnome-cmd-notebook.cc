/*
    GNOME Commander - A GNOME based file manager
    Copyright (C) 2001-2006 Marcus Bjurman
    Copyright (C) 2007-2010 Piotr Eljasiak

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include <config.h>

#include "gnome-cmd-includes.h"
#include "gnome-cmd-notebook.h"
#include "utils.h"

using namespace std;


struct GnomeCmdNotebookClass
{
    GtkNotebookClass parent_class;
};


class GnomeCmdNotebook::Private
{
  public:

    Private();
    ~Private();
};


inline GnomeCmdNotebook::Private::Private()
{
}


inline GnomeCmdNotebook::Private::~Private()
{
}


G_DEFINE_TYPE (GnomeCmdNotebook, gnome_cmd_notebook, GTK_TYPE_NOTEBOOK)


static void gnome_cmd_notebook_init (GnomeCmdNotebook *self)
{
    self->priv = new GnomeCmdNotebook::Private;
}


static void gnome_cmd_notebook_finalize (GObject *object)
{
    GnomeCmdNotebook *self = GNOME_CMD_NOTEBOOK (object);

    delete self->priv;

    if (G_OBJECT_CLASS (gnome_cmd_notebook_parent_class)->finalize)
        (* G_OBJECT_CLASS (gnome_cmd_notebook_parent_class)->finalize) (object);
}


static void gnome_cmd_notebook_class_init (GnomeCmdNotebookClass *klass)
{
    gnome_cmd_notebook_parent_class = (GObjectClass *) g_type_class_peek_parent (klass);

    GObjectClass *object_class = (GObjectClass *) klass;

    object_class->finalize = gnome_cmd_notebook_finalize;
}


int GnomeCmdNotebook::find_tab_num_at_pos(gint screen_x, gint screen_y)
{
    if (!GTK_NOTEBOOK (this)->first_tab)
        return -1;

    GtkPositionType tab_pos = gtk_notebook_get_tab_pos (*this);
    GtkWidget *page;

    for (int page_num=0; (page=GnomeCmdNotebook::page(page_num)); ++page_num)
    {
        GtkWidget *tab = gtk_notebook_get_tab_label (*this, page);

        g_return_val_if_fail (tab!=NULL, -1);

        if (!GTK_WIDGET_MAPPED (GTK_WIDGET (tab)))
            continue;

        gint x_root, y_root;

        gdk_window_get_origin (tab->window, &x_root, &y_root);

        int max_x = x_root + tab->allocation.x + tab->allocation.width;
        int max_y = y_root + tab->allocation.y + tab->allocation.height;

        if ((tab_pos == GTK_POS_TOP || tab_pos == GTK_POS_BOTTOM) && screen_x <= max_x)
            return page_num;

        if ((tab_pos == GTK_POS_LEFT || tab_pos == GTK_POS_RIGHT) && screen_y <= max_y)
            return page_num;
    }

    return -1;
}
