#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "evenement.h"
#include <gtk/gtk.h>

enum   
{       
        JOUR,
        MOIS,
	ANNE,
        HEURE,
	CLIENT,
        COLUMNS
};



void afficher_evenement(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char jour [30];
	char mois [30];
	char anne [30];
	char heure [30];
	char id [30];
	char id2[30];
	char a [30];
	char b [30];
        char d [30];
	int c,r;
        store=NULL;

       FILE *f;
       FILE *F;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",MOIS, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  anne", renderer, "text",ANNE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  type", renderer, "text",CLIENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/med/Desktop/projet/src/evenement.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/med/Desktop/projet/src/evenement.txt", "r");
	
              while(fscanf(f,"%s %s %s %s %s  \n",jour,mois,anne,heure,id2)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, JOUR, jour, MOIS, mois, ANNE, anne,HEURE,heure,CLIENT,id2, -1); 
		}
		}
		
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	
}





