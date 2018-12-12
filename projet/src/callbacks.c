#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "date.h"
#include "profile.h"
#include "rendezvous.h"
#include "verfier.h"
#include "rendezvousA.h"
#include "profiles.h"
#include "evenement.h"
#include "fiche.h"


void
on_button_155_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4;
GtkWidget *window;
char x[50];
char y[50];
char z[50];
char w[50];
char a[50];
char b[50];
int c,r;
char d[50];
char prenoms[50];
char noms[50];
char gsms[50];
char ids[50];
char emails[50];

FILE* f ;
FILE* ftemp;
FILE* F;
GtkWidget *treeview3;



input1=lookup_widget(button,"gsm");
input2=lookup_widget(button,"nom");
input3=lookup_widget(button,"prenom");
input4=lookup_widget(button,"adresse");


strcpy(x,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(y,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(w,gtk_entry_get_text(GTK_ENTRY(input4)));
f=fopen("/home/med/Desktop/projet/src/profiles.txt","r");
ftemp=fopen("/home/med/Desktop/projet/src/temp.txt","a+");
F=fopen("/home/med/Desktop/projet/src/datatemp.txt","r");
if(f !=NULL) 
	{while (fscanf(F,"%s %s %d %s \n",a,b,&c,d)!=EOF)
           
			{while (fscanf(f,"%s %s %s %s %d %s \n",prenoms,noms,gsms,emails,&r,ids)!=EOF)
				{if(strcmp(d,ids)!=0)
					{fprintf(ftemp,"%s %s %s %s %d %s \n",prenoms,noms,gsms,emails,r,ids);
					}
				}
			}
			
		
	}
fprintf(ftemp,"%s %s %s %s %d %s \n",y,z,x,w,c,d);
fclose(F);
fclose(f);
fclose(ftemp);
remove ("/home/med/Desktop/projet/src/profiles.txt");
rename ("/home/med/Desktop/projet/src/temp.txt","/home/med/Desktop/projet/src/profiles.txt");
treeview3=lookup_widget(button,"treeview152");
afficher_profile(treeview3);
}








void
on_button159_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *treeview5;
char x[50];
char y[50];
char z[50];
char w[50];
char a [30];
char b [30];
char d [30];
char e [30];
int c;
FILE* f ;
FILE *F;
strcpy(e,"bureau");
input3=lookup_widget(button, "combobox151");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
input4=lookup_widget(button, "combobox152");
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
input5=lookup_widget(button, "combobox153");
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
input6=lookup_widget(button, "combobox154");
strcpy(w,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));

f=fopen("/home/med/Desktop/projet/src/dateD.txt","a+");
F = fopen("/home/med/Desktop/projet/src/datatemp.txt", "r");
while( fscanf(F,"%s %s %d %s  \n",a,b,&c,d)!=EOF)
{
if(f !=NULL) 
	{
		fprintf(f,"%s %s %s %s %d %s %s \n",x,y,z,w,c,d,e);
	}
	}
fclose(f);
treeview5=lookup_widget(button,"treeview151");
afficher_date(treeview5);
}


void
on_button160_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4;
GtkWidget *window;
GtkWidget *treeview5;
char x[50];
char y[50];
char z[50];
char w[50];
char jour[50];
char mois[50];
char annee[50];
char heure[50];
char id [30];
char a [30];
char b [30];
char d [30];
char e [30];
int c,r;
FILE *F; 
FILE *Ftemp;
FILE *f;



input1=lookup_widget(button,"combobox151");
input2=lookup_widget(button,"combobox152");
input3=lookup_widget(button,"combobox153");
input4=lookup_widget(button,"combobox154");


strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(w,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));

	F=fopen("/home/med/Desktop/projet/src/dateD.txt","a+");
	Ftemp=fopen ("/home/med/Desktop/projet/src/temp.txt","a+");
        f = fopen("/home/med/Desktop/projet/src/datatemp.txt", "r");
        while( fscanf(f,"%s %s %d %s  \n",a,b,&c,d)!=EOF)
	{if (F!=NULL){
	
		while (fscanf(F,"%s %s %s %s %d %s %s \n",jour,mois,annee,heure,&r,id,e)!=EOF)
			{
			if((strcmp(x,jour)!=0)||(strcmp(y,mois)!=0)||(strcmp(z,annee)!=0)||(strcmp(w,heure)!=0)||(strcmp(d,id)!=0))
				{

									fprintf(Ftemp,"%s %s %s %s %d %s %s \n",jour,mois,annee,heure,r,id,e);}

}
}
}
	
fclose(Ftemp);
fclose(F);
fclose(f);
remove ("/home/med/Desktop/projet/src/dateD.txt");
rename ("/home/med/Desktop/projet/src/temp.txt","/home/med/Desktop/projet/src/dateD.txt");
treeview5=lookup_widget(button,"treeview151");
afficher_date(treeview5);
}







void
on_button1_clicked                     (GtkWidget       *button , gpointer         user_data)

{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *input;
GtkWidget *input2;
GtkWidget *output;
char x[50];char y[50];
char ext[50];
int verif;
GtkWidget *treeview1;
GtkWidget *treeview2;
GtkWidget *treeview3;
GtkWidget *treeview4;
GtkWidget *treeview5;

 
window1=lookup_widget(button,"window1");
input=lookup_widget(button,"entry1");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input)));
input2=lookup_widget(button,"entry2");
strcpy(y,gtk_entry_get_text(GTK_ENTRY(input2)));
verif=verifier(x,y);
if( verif==1){
window=create_admin();
gtk_widget_hide(window1);
gtk_widget_show_all(window);
treeview1=lookup_widget(window,"treeview155");
afficher_profiles(treeview1);
treeview2=lookup_widget(window,"treeview157");
afficher_evenement(treeview2);
treeview3=lookup_widget(window,"treeview152");
afficher_profile(treeview3);}
else if( verif==2){
window=create_adherant();
gtk_widget_hide(window1);
gtk_widget_show_all(window);
treeview2=lookup_widget(window,"treeview158");
afficher_evenement(treeview2);
treeview3=lookup_widget(window,"treeview152");
afficher_profile(treeview3);
treeview4=lookup_widget(window,"treeview154");
afficher_rendezvousA(treeview4);
treeview5=lookup_widget(window,"treeview160");
afficher_fiche(treeview5);}
else if( verif==3){
window=create_coach();
gtk_widget_hide(window1);
gtk_widget_show_all(window);
treeview3=lookup_widget(window,"treeview152");
afficher_profile(treeview3);
treeview4=lookup_widget(window,"treeview153");
afficher_rendezvous(treeview4);
treeview5=lookup_widget(window,"treeview151");
afficher_date(treeview5);  }
else if( verif==4){
window=create_nutretioniste();
gtk_widget_show_all(window);
gtk_widget_hide(window1);
treeview3=lookup_widget(window,"treeview152");
afficher_profile(treeview3);
treeview4=lookup_widget(window,"treeview153");
afficher_rendezvous(treeview4);
treeview5=lookup_widget(window,"treeview151");
afficher_date(treeview5);  }
else if( verif==5){
window=create_Dietecien();
gtk_widget_hide(window1);
gtk_widget_show_all(window);
treeview3=lookup_widget(window,"treeview152");
afficher_profile(treeview3);
treeview4=lookup_widget(window,"treeview153");
afficher_rendezvous(treeview4);
treeview5=lookup_widget(window,"treeview151");
afficher_date(treeview5);  }
else if( verif==6){
window=create_kinee();
gtk_widget_hide(window1);
gtk_widget_show_all(window);
treeview3=lookup_widget(window,"treeview152");
afficher_profile(treeview3);
treeview4=lookup_widget(window,"treeview153");
afficher_rendezvous(treeview4);
treeview5=lookup_widget(window,"treeview151");
afficher_date(treeview5);  }
else if( verif==-1){
strcpy(ext,"erreur:user name/ password uncorrect");
output=lookup_widget(button,"label8");
gtk_label_set_text(GTK_LABEL(output),ext);}

}

void
on_button162_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
char x[50];
char y[50];
char z[50];
char w[50];
int r;
FILE *f;
input=lookup_widget(button,"entry163");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input)));
input1=lookup_widget(button,"entry164");
strcpy(y,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"entry165");
strcpy(w,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button, "combobox159");
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
if(strcmp(z,"adherant")==0)
{r=2;}
else if(strcmp(z,"coach")==0)
{r=3;}
else if(strcmp(z,"nutritioniste")==0)
{r=4;}
else if(strcmp(z,"dietecien")==0)
{r=5;}
else if(strcmp(z,"kine")==0)
{r=6;}
f=fopen("/home/med/Desktop/projet/src/users.txt","a+");
fprintf(f,"%s %s %d %s  \n",x,y,r,w);
fclose(f);
}


void
on_button163_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
char x[50];
char y[50];
char z[50];
char w[50];
int r;
FILE *f;
FILE *F;
input=lookup_widget(button,"entry166");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("/home/med/Desktop/projet/src/users.txt","r");
F=fopen("/home/med/Desktop/projet/src/temp.txt","a+");
while(fscanf(f,"%s %s %d %s  \n",x,y,&r,w)!=EOF)
{if(strcmp(w,z)!=0)
{fprintf(F,"%s %s %d %s  \n",x,y,r,w);
}
}
fclose(F);
fclose(f);
remove ("/home/med/Desktop/projet/src/users.txt");
rename ("/home/med/Desktop/projet/src/temp.txt","/home/med/Desktop/projet/src/users.txt");
}






void
on_button173_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *combobox1;
GtkWidget *combobox2;
GtkWidget *combobox3;
GtkWidget *combobox4;
GtkWidget *combobox5;
GtkWidget *treeview4;
GtkWidget *output;
FILE *f;
FILE *f1;
FILE *f2;
char role[20];char HH[20];int x;
char t[50];char d[20],a[20],b[20],c[20],id[20],k[50],g[50],id2[50];
int r,e,e2;
int y=0;
char z[50],a2[50],b2[50],c2[50],d2[50],g2[50],k2[50],a1[50],b1[50],o[50],o2[50];
char JJ[50],MM[50],AA[50];
combobox1=lookup_widget(button, "combobox161");
combobox2=lookup_widget(button, "combobox162");
combobox3=lookup_widget(button, "combobox163");
combobox4=lookup_widget(button, "combobox164");
combobox5=lookup_widget(button, "combobox165");

strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(JJ,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(MM,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
strcpy(AA,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
strcpy(HH,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));
f=fopen("/home/med/Desktop/projet/src/dateR.txt","a+");
f1=fopen("/home/med/Desktop/projet/src/datatemp.txt","r");
f2=fopen("/home/med/Desktop/projet/src/dateD.txt","r");

if(strcmp(role, "kine")== 0) x=6;
else if (strcmp(role, "coach")== 0) x=3;
else if (strcmp(role, "dietecien")== 0) x=5;
else if (strcmp(role, "nutricioniste")== 0) x=4;
while(fscanf(f1,"%s %s %d %s\n",a1,b1,&r,id)!=EOF)
{strcpy(id2,id);}
while(fscanf(f2,"%s %s %s %s %d %s %s \n",a,b,c,d,&e,g,o)!=EOF)
{
  if ((strcmp(a, JJ)== 0) && (strcmp(b, MM)== 0) && (strcmp(c, AA)== 0) && (strcmp(d, HH)== 0) && (e==x))
     {
      strcpy(z,g);
      y=1;
      while(fscanf(f,"%s %s %s %s %d %s %s %s \n",a2,b2,c2,d2,&e2,g2,k2,o2)!=EOF)
          {
          if ((strcmp(a2, JJ)== 0) && (strcmp(b2, MM)== 0) && (strcmp(c2, AA)== 0) && (strcmp(d2, HH)== 0) && (e2==x)&&(strcmp(g2, z)== 0))
               {y=0;
		break;}
	  
          }
     }
}

      

if (y==0)
{ strcpy(t,"il faut choisir un autre rendez vous");
output=lookup_widget(button,"label76");
gtk_label_set_text(GTK_LABEL(output),t);
}

else if (y==1)
{    fprintf(f,"%s %s %s %s %d %s %s %s \n",JJ, MM,AA,HH,x,z,id2,o);
     
strcpy(t,"rendez vous valider");
output=lookup_widget(button,"label76");
gtk_label_set_text(GTK_LABEL(output),t);
treeview4=lookup_widget(button,"treeview154");
afficher_rendezvousA(treeview4);}
fclose(f2);
fclose(f1);
fclose(f);






}




void
on_button185_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *treeview2;
char x[50];
char y[50];
char z[50];
char w[50];
char v[50];
FILE* f ;

input3=lookup_widget(button, "combobox166");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
input4=lookup_widget(button, "combobox167");
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
input5=lookup_widget(button, "combobox168");
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
input6=lookup_widget(button, "combobox169");
strcpy(w,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
input7=lookup_widget(button, "combobox170");
strcpy(v,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));

f=fopen("/home/med/Desktop/projet/src/evenement.txt","a+");
if(f !=NULL) 
	{
		fprintf(f,"%s %s %s %s %s \n",z,w,x,y,v);
	}
	
fclose(f);
treeview2=lookup_widget(button,"treeview157");
afficher_evenement(treeview2);
}


void
on_button186_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4,*input5;
GtkWidget *window;
char x[50];
char y[50];
char z[50];
char w[50];
char v[50];
char jour[50];
char mois[50];
char annee[50];
char heure[50];
char type [30];
FILE *F; 
FILE *Ftemp;
GtkWidget *treeview2;



input1=lookup_widget(button,"combobox168");
input2=lookup_widget(button,"combobox169");
input3=lookup_widget(button,"combobox166");
input4=lookup_widget(button,"combobox167");
input5=lookup_widget(button,"combobox170");


strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(w,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(v,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));


	F=fopen("/home/med/Desktop/projet/src/evenement.txt","a+");
	Ftemp=fopen ("/home/med/Desktop/projet/src/temp.txt","a+");
	if (F!=NULL){
	
		while (fscanf(F,"%s %s %s %s %s \n",jour,mois,annee,heure,type)!=EOF)
			{
			if((strcmp(x,jour)!=0)||(strcmp(y,mois)!=0)||(strcmp(z,annee)!=0)||(strcmp(w,heure)!=0)||(strcmp(v,type)!=0))
				{fprintf(Ftemp,"%s %s %s %s %s \n",jour,mois,annee,heure,type);}

}
}
	
fclose(Ftemp);
fclose(F);
remove ("/home/med/Desktop/projet/src/evenement.txt");
rename ("/home/med/Desktop/projet/src/temp.txt","/home/med/Desktop/projet/src/evenement.txt");
treeview2=lookup_widget(button,"treeview157");
afficher_evenement(treeview2);
}


void
on_button188_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *output;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
char z[50];
char ext[50];
char a[50];
char d[50];
char b[50];
char c[50];
FILE *f;


input=lookup_widget(button,"entry167");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));

strcpy(ext,convertir(z));
output=lookup_widget(button,"label65");
gtk_label_set_text(GTK_LABEL(output),ext);
output2=lookup_widget(button,"label66");
output3=lookup_widget(button,"label67");
output4=lookup_widget(button,"label68");
f=fopen("/home/med/Desktop/projet/src/fichemedical.txt","a+");
while(fscanf(f,"%s %s %s %s \n",a,b,c,d)!=EOF)
{if(strcmp(z,a)==0)
{
gtk_label_set_text(GTK_LABEL(output2),b);
gtk_label_set_text(GTK_LABEL(output3),c);
gtk_label_set_text(GTK_LABEL(output4),d);
break;}
else
{
gtk_label_set_text(GTK_LABEL(output2),"pas de donne");
gtk_label_set_text(GTK_LABEL(output3),"pas de donne");
gtk_label_set_text(GTK_LABEL(output4),"pas de donne");
}
}
fclose(f);
}


void
on_button189_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
char z[50];
char a[50];
char d[50];
char b[50];
char c[50];
char e[50];
char x[50];
int y,w;
FILE *f;
FILE *F;
FILE *ff;
FILE *fff;

f=fopen("/home/med/Desktop/projet/src/fichemedical.txt","a+");
F=fopen("/home/med/Desktop/projet/src/fichemedicaltemp.txt","a+");
ff=fopen("/home/med/Desktop/projet/src/fichemedicalk.txt","a+");
fff=fopen("/home/med/Desktop/projet/src/fichemedicalktemp.txt","a+");
input=lookup_widget(button,"entry167");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));
while(fscanf(f,"%s %s %s %s \n",a,b,c,d)!=EOF)
{if(strcmp(z,a)!=0)
{fprintf(F,"%s %s %s %s \n",a,b,c,d);}
}
input1=lookup_widget(button,"combobox171");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
input2=lookup_widget(button,"spinbutton1");
input3=lookup_widget(button,"spinbutton2");
y=gtk_spin_button_get_value(GTK_SPIN_BUTTON (input2));
w=gtk_spin_button_get_value(GTK_SPIN_BUTTON (input3));
fprintf(F,"%s %d %d %s \n",z,y,w,x);
while(fscanf(ff,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{if(strcmp(z,a)!=0)
{fprintf(fff,"%s %s %s %s %s \n",a,b,c,d,e);}
}
fprintf(fff,"%s %d %d %s %s \n",z,y,w,d,e);
fclose(f);
fclose(F);
fclose(ff);
fclose(fff);
remove ("/home/med/Desktop/projet/src/fichemedicalk.txt");
rename ("/home/med/Desktop/projet/src/fichemedicalktemp.txt","/home/med/Desktop/projet/src/fichemedicalk.txt");

remove ("/home/med/Desktop/projet/src/fichemedical.txt");
rename ("/home/med/Desktop/projet/src/fichemedicaltemp.txt","/home/med/Desktop/projet/src/fichemedical.txt");










}


void
on_button191_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *window2;
GtkWidget *window3;
GtkWidget *window4;
GtkWidget *window6;
GtkWidget *window7;
GtkWidget *window8;
window4=lookup_widget(button,"admin");
window2=lookup_widget(button,"adherant");
window3=lookup_widget(button,"Dietecien");
window6=lookup_widget(button,"coach");
window7=lookup_widget(button,"kinee");
window8=lookup_widget(button,"nutretioniste");
gtk_widget_hide(window4);
gtk_widget_hide(window2);
gtk_widget_hide(window3);
gtk_widget_hide(window6);
gtk_widget_hide(window7);
gtk_widget_hide(window8);
window=create_window1();
gtk_widget_show_all(window);
}


void
on_button194_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input2;
GtkWidget *treeview4;
FILE *F;
FILE *f;
FILE *f1;
char a[50],b[50],c[50],d[50],m[50],n[50],a1[50],b1[50],id[50],id2[50],o[50];
int e,r,i=1,y;
f=fopen("/home/med/Desktop/projet/src/dateR.txt","a+");
F=fopen("/home/med/Desktop/projet/src/rendezvoustemp.txt","a+");
f1=fopen("/home/med/Desktop/projet/src/datatemp.txt","r");
while(fscanf(f1,"%s %s %d %s\n",a1,b1,&r,id)!=EOF)
{strcpy(id2,id);}
input2=lookup_widget(button,"spinbutton3");
y=gtk_spin_button_get_value(GTK_SPIN_BUTTON (input2));
while(fscanf(f,"%s %s %s %s %d %s %s %s \n",a,b,c,d,&e,m,n,o)!=EOF)
{if((strcmp(n,id2)!=0)||(i!=y))
{fprintf(F,"%s %s %s %s %d %s %s %s \n",a,b,c,d,e,m,n,o);}
if (strcmp(n,id2)==0)
{i=i+1;}
}
fclose(f);
fclose(F);
fclose(f1);
remove ("/home/med/Desktop/projet/src/dateR.txt");
rename ("/home/med/Desktop/projet/src/rendezvoustemp.txt","/home/med/Desktop/projet/src/dateR.txt");

treeview4=lookup_widget(button,"treeview154");
afficher_rendezvousA(treeview4);
}


void
on_button199_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
char z[50];
char ext[50];
char a[50];
char d[50];
char b[50];
char c[50];
char e[50];
FILE *f;


input=lookup_widget(button,"entry167");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));

strcpy(ext,convertir(z));
output=lookup_widget(button,"label65");
gtk_label_set_text(GTK_LABEL(output),ext);
output2=lookup_widget(button,"label66");
output3=lookup_widget(button,"label67");
output4=lookup_widget(button,"label68");
f=fopen("/home/med/Desktop/projet/src/fichemedicalk.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{if(strcmp(z,a)==0)
{strcat(d," ");
strcat(d,e);
gtk_label_set_text(GTK_LABEL(output2),b);
gtk_label_set_text(GTK_LABEL(output3),c);
gtk_label_set_text(GTK_LABEL(output4),d);
break;}
else
{
gtk_label_set_text(GTK_LABEL(output2),"pas de donne");
gtk_label_set_text(GTK_LABEL(output3),"pas de donne");
gtk_label_set_text(GTK_LABEL(output4),"pas de donne");
}
}
fclose(f);
}



void
on_button200_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
char z[50];
char a[50];
char d[50];
char b[50];
char c[50];
char a1[50];
char d1[50];
char b1[50];
char c1[50];
char e[50];
char x[50];
FILE *f;
FILE *F;
FILE *ff;
ff=fopen("/home/med/Desktop/projet/src/fichemedical.txt","a+");
f=fopen("/home/med/Desktop/projet/src/fichemedicalk.txt","a+");
F=fopen("/home/med/Desktop/projet/src/fichemedicalktemp.txt","a+");
input=lookup_widget(button,"entry167");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));
while(fscanf(ff,"%s %s %s %s \n",a1,b1,c1,d1)!=EOF)
{if(strcmp(z,a1)==0)
{break;}
}
while(fscanf(f,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{if(strcmp(z,a)!=0)
{fprintf(F,"%s %s %s %s %s \n",a,b,c,d,e);}
}
input1=lookup_widget(button,"combobox171");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
fprintf(F,"%s %s %s %s \n",z,b1,c1,x);
fclose(f);
fclose(F);
remove ("/home/med/Desktop/projet/src/fichemedicalk.txt");
rename ("/home/med/Desktop/projet/src/fichemedicalktemp.txt","/home/med/Desktop/projet/src/fichemedicalk.txt");

}


void
on_button205_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
char z[50];
char ext[50];
char a[50];
char d[50];
char b[50];
char c[50];
char e[50];
FILE *f;


input=lookup_widget(button,"entry167");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));

strcpy(ext,convertir(z));
output=lookup_widget(button,"label65");
gtk_label_set_text(GTK_LABEL(output),ext);
output2=lookup_widget(button,"label66");
output3=lookup_widget(button,"label67");
output4=lookup_widget(button,"label68");
f=fopen("/home/med/Desktop/projet/src/fichemedicaln.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{if(strcmp(z,a)==0)
{strcat(d," ");
strcat(d,e);
gtk_label_set_text(GTK_LABEL(output2),b);
gtk_label_set_text(GTK_LABEL(output3),c);
gtk_label_set_text(GTK_LABEL(output4),d);
break;}
else
{
gtk_label_set_text(GTK_LABEL(output2),"pas de donne");
gtk_label_set_text(GTK_LABEL(output3),"pas de donne");
gtk_label_set_text(GTK_LABEL(output4),"pas de donne");
}
}
fclose(f);
}


void
on_button206_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
char z[50];
char a[50];
char d[50];
char b[50];
char c[50];
char a1[50];
char d1[50];
char b1[50];
char c1[50];
char e[50];
char x[50];
FILE *f;
FILE *F;
FILE *ff;
ff=fopen("/home/med/Desktop/projet/src/fichemedical.txt","a+");
f=fopen("/home/med/Desktop/projet/src/fichemedicaln.txt","a+");
F=fopen("/home/med/Desktop/projet/src/fichemedicalntemp.txt","a+");
input=lookup_widget(button,"entry167");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));
while(fscanf(ff,"%s %s %s %s \n",a1,b1,c1,d1)!=EOF)
{if(strcmp(z,a1)==0)
{break;}
}
while(fscanf(f,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{if(strcmp(z,a)!=0)
{fprintf(F,"%s %s %s %s %s \n",a,b,c,d,e);}
}
input1=lookup_widget(button,"combobox171");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
fprintf(F,"%s %s %s %s \n",z,b1,c1,x);
fclose(f);
fclose(F);
remove ("/home/med/Desktop/projet/src/fichemedicaln.txt");
rename ("/home/med/Desktop/projet/src/fichemedicalntemp.txt","/home/med/Desktop/projet/src/fichemedicaln.txt");
}


void
on_button211_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
char z[50];
char ext[50];
char a[50];
char d[50];
char b[50];
char c[50];
char e[50];
FILE *f;


input=lookup_widget(button,"entry167");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input)));

strcpy(ext,convertir(z));
output=lookup_widget(button,"label65");
gtk_label_set_text(GTK_LABEL(output),ext);
output2=lookup_widget(button,"label66");
output3=lookup_widget(button,"label67");
output4=lookup_widget(button,"label68");
f=fopen("/home/med/Desktop/projet/src/fichemedicalk.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{if(strcmp(z,a)==0)
{strcat(d," ");
strcat(d,e);
gtk_label_set_text(GTK_LABEL(output2),b);
gtk_label_set_text(GTK_LABEL(output3),c);
gtk_label_set_text(GTK_LABEL(output4),d);
break;}
else
{
gtk_label_set_text(GTK_LABEL(output2),"pas de donne");
gtk_label_set_text(GTK_LABEL(output3),"pas de donne");
gtk_label_set_text(GTK_LABEL(output4),"pas de donne");
}
}
fclose(f);
}


void
on_button300_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *treeview5;
char x[50];
char y[50];
char z[50];
char w[50];
char a [30];
char b [30];
char d [30];
char e [50];
int c;
FILE* f ;
FILE *F;

input3=lookup_widget(button, "combobox151");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
input4=lookup_widget(button, "combobox152");
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
input5=lookup_widget(button, "combobox153");
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
input6=lookup_widget(button, "combobox154");
strcpy(w,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
input7=lookup_widget(button, "combobox155");
strcpy(e,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));


f=fopen("/home/med/Desktop/projet/src/dateD.txt","a+");
F = fopen("/home/med/Desktop/projet/src/datatemp.txt", "r");
while( fscanf(F,"%s %s %d %s  \n",a,b,&c,d)!=EOF)
{
if(f !=NULL) 
	{
		fprintf(f,"%s %s %s %s %d %s %s \n",x,y,z,w,c,d,e);
	}
	}
fclose(f);
treeview5=lookup_widget(button,"treeview151");
afficher_date(treeview5);
}


void
on_button301_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4,*input5;
GtkWidget *window;
GtkWidget *treeview5;
char x[50];
char y[50];
char z[50];
char w[50];
char jour[50];
char mois[50];
char annee[50];
char heure[50];
char id [30];
char a [30];
char b [30];
char d [30];
char e [30];
int c,r;
FILE *F; 
FILE *Ftemp;
FILE *f;



input1=lookup_widget(button,"combobox151");
input2=lookup_widget(button,"combobox152");
input3=lookup_widget(button,"combobox153");
input4=lookup_widget(button,"combobox154");
input5=lookup_widget(button,"combobox155");

strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(z,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(w,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(e,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
	F=fopen("/home/med/Desktop/projet/src/dateD.txt","a+");
	Ftemp=fopen ("/home/med/Desktop/projet/src/temp.txt","a+");
        f = fopen("/home/med/Desktop/projet/src/datatemp.txt", "r");
        while( fscanf(f,"%s %s %d %s  \n",a,b,&c,d)!=EOF)
	{if (F!=NULL){
	
		while (fscanf(F,"%s %s %s %s %d %s %s \n",jour,mois,annee,heure,&r,id,e)!=EOF)
			{
			if((strcmp(x,jour)!=0)||(strcmp(y,mois)!=0)||(strcmp(z,annee)!=0)||(strcmp(w,heure)!=0)||(strcmp(d,id)!=0))
				{

									fprintf(Ftemp,"%s %s %s %s %d %s %s \n",jour,mois,annee,heure,r,id,e);}

}
}
}
	
fclose(Ftemp);
fclose(F);
fclose(f);
remove ("/home/med/Desktop/projet/src/dateD.txt");
rename ("/home/med/Desktop/projet/src/temp.txt","/home/med/Desktop/projet/src/dateD.txt");
treeview5=lookup_widget(button,"treeview151");
afficher_date(treeview5);
}


void
on_treeview152_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *entry111,*entry112,*entry113,*entry114;
GtkTreeIter iter;
GtkTreeModel *model;
gchar *string,*string1,*string2,*string3,*string4;
model=gtk_tree_view_get_model(treeview);
gtk_tree_model_get_iter(model,&iter,path);
gtk_tree_model_get(model,&iter,0,&string,-1);
gtk_tree_model_get(model,&iter,1,&string1,-1);
gtk_tree_model_get(model,&iter,2,&string2,-1);
gtk_tree_model_get(model,&iter,3,&string3,-1);
entry111=lookup_widget(GTK_TREE_VIEW(treeview),"nom");
entry112=lookup_widget(GTK_TREE_VIEW(treeview),"prenom");
entry113=lookup_widget(GTK_TREE_VIEW(treeview),"gsm");
entry114=lookup_widget(GTK_TREE_VIEW(treeview),"adresse");


gtk_entry_set_text(GTK_ENTRY(entry111),string);
gtk_entry_set_text(GTK_ENTRY(entry112),string1);
gtk_entry_set_text(GTK_ENTRY(entry113),string2);
gtk_entry_set_text(GTK_ENTRY(entry114),string3);
}



