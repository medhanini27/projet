#include <gtk/gtk.h>

typedef struct
{

char jour[20];
char mois[20];
char anne[30];
char heure[30];

}date;

void afficher_date(GtkWidget *liste);
