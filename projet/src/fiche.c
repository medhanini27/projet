#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fiche.h"
#include "rendezvousA.h"

enum   
{       
        NOM,
        TAILLE,
	POIDS,
        REGIME,
        COLUMNS
};



void afficher_fiche(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom [30];
	char taille [30];
	char poids [30];
	char regime [30];
	char id [30];
	char a [30];
	char b [30];
        char d [30];
	int c;
        store=NULL;

       FILE *f;
       FILE *F;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" taille", renderer, "text",TAILLE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  regime", renderer, "text",REGIME, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/med/Desktop/projet/src/fichemedical.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/med/Desktop/projet/src/fichemedical.txt", "r");
	  F = fopen("/home/med/Desktop/projet/src/datatemp.txt", "r");
              while( fscanf(F,"%s %s %d %s  \n",a,b,&c,d)!=EOF)
		{while(fscanf(f,"%s %s %s %s \n",id,taille,poids,regime)!=EOF)
		{if(strcmp(id,d)==0)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, convertir(id), TAILLE, taille, POIDS, poids,REGIME,regime, -1); 
		}
		}
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	
	}
}


