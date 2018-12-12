#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "profiles.h"
#include <gtk/gtk.h>

enum   
{       
        NOM,
        PRENOM,
	GSM,
        EMAIL,
        COLUMNS
};



void afficher_profiles(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom [30];
	char prenom [30];
	char gsm [30];
	char email [30];
	char id [30];
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
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  gsm", renderer, "text",GSM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  email", renderer, "text",EMAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/med/Desktop/projet/src/profiles.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/med/Desktop/projet/src/profiles.txt", "r");
	  
            
	while(fscanf(f,"%s %s %s %s %d %s  \n",nom,prenom,gsm,email,&r,id)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, GSM, gsm,EMAIL,email, -1); 
		}
		}
		
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	
	
}





