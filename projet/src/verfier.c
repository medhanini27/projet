#include <stdio.h>
#include <string.h>
#include <verfier.h>

int verifier (char Username[], char Password[])
{
FILE*f;
char login1[20];char password1[20];char id[20];
int r;int c=-1;
FILE *Ftemp;
Ftemp=fopen("/home/med/Desktop/projet/src/datatemp.txt","w");


f=fopen("/home/med/Desktop/projet/src/users.txt","r");
if(f !=NULL) {
while(fscanf(f,"%s %s %d %s \n",login1,password1,&r,id)!=EOF){ 
if ( strcmp(Username, login1)== 0){
if ( strcmp(Password, password1)== 0){
c=r;
fprintf(Ftemp,"%s %s %d %s \n",login1,password1,r,id);
              }
           }
         }
      }

fclose(f);
fclose(Ftemp);
return c;
}
