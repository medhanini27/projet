#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "date.h"
#include <gtk/gtk.h>
#include "rendezvousA.h"
enum   
{       
        JOUR,
        MOIS,
	ANNE,
        HEURE,
	CLIENT,
	SALLE,
        COLUMNS
};



void afficher_rendezvous(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char jour [30];
	char mois [30];
	char anne [30];
	char heure [30];
	char salle [30];
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
		column = gtk_tree_view_column_new_with_attributes("  client", renderer, "text",CLIENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" salle ", renderer, "text",SALLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/med/Desktop/projet/src/dateR.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/med/Desktop/projet/src/dateR.txt", "r");
	F = fopen("/home/med/Desktop/projet/src/datatemp.txt", "r");
              while( fscanf(F,"%s %s %d %s  \n",a,b,&c,d)!=EOF)
		{
              while(fscanf(f,"%s %s %s %s %d %s %s %s \n",jour,mois,anne,heure,&r,id,id2,salle)!=EOF)
		{if(strcmp(id,d)==0)
{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, JOUR, jour, MOIS, mois, ANNE, anne,HEURE,heure,CLIENT,convertir(id2),SALLE,salle, -1); 
		}
		}
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}





