/*
 *
 *   Copyright (C) 2012-2018 by C.H. Huang
 *   plushuang.tw@gmail.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  ---
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations
 *  including the two.
 *  You must obey the GNU Lesser General Public License in all respects
 *  for all of the code used other than OpenSSL.  If you modify
 *  file(s) with this exception, you may extend this exception to your
 *  version of the file(s), but you are not obligated to do so.  If you
 *  do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source
 *  files in the program, then also delete it here.
 *
 */

/*
 * This file base on GTK+ 2.0 Tree View Tutorial - custom-list.h
 */

#ifndef UGTK_NODE_LIST_H
#define UGTK_NODE_LIST_H

#include <gtk/gtk.h>
#include <UgetNode.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UGTK_TYPE_NODE_LIST              (ugtk_node_list_get_type ())
#define UGTK_NODE_LIST(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), UGTK_TYPE_NODE_LIST, UgtkNodeList))
#define UGTK_NODE_LIST_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass),  UGTK_TYPE_NODE_LIST, UgtkNodeListClass))
#define UGTK_IS_NODE_LIST(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UGTK_TYPE_NODE_LIST))
#define UGTK_IS_NODE_LIST_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass),  UGTK_TYPE_NODE_LIST))
#define UGTK_NODE_LIST_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj),  UGTK_TYPE_NODE_LIST, UgtkNodeListClass))

typedef struct UgtkNodeList       UgtkNodeList;
typedef struct UgtkNodeListClass  UgtkNodeListClass;

// ----------------------------------------------------------------------------
// UgtkNodeList : GtkTreeModel for UgetNode real and fake nodes.

struct UgtkNodeList
{
	GObject     parent;  // this MUST be the first member

	UgetNode*   root;
	gint        stamp;   // Random integer to check whether an iter belongs to our model

	gint        n_fake;
	gboolean    root_visible;  // show root as first item
};

// ------------------------------------

struct UgtkNodeListClass
{
	GObjectClass  parent_class;
};

UgtkNodeList*  ugtk_node_list_new (UgetNode* root, gint n_fake, gboolean root_visible);

GType  ugtk_node_list_get_type (void);

#ifdef __cplusplus
}
#endif

#endif // UGTK_NODE_LIST_H
