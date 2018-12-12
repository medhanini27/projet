#include <gtk/gtk.h>

typedef struct
{

char nom[20];
char prenom[20];
char gsm[30];
char email[30];

}profiles;

void afficher_profiles(GtkWidget *liste);
