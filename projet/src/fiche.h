#include <gtk/gtk.h>

typedef struct
{

char nom[20];
char taille[20];
char poids[30];
char regime[30];

}fiche;

void afficher_fiche(GtkWidget *liste);
