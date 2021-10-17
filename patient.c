#include <stdio.h>
#include <string.h>
#include "patient.h"
void saisirPatient(Patient *p)
{
    printf("donner votre nom\n");
    fflush(stdin);
    gets(p->nom);

    printf("donner votre prenom\n");
    gets(p->prenom);

    printf("avez vous un rdv 0:non 1:oui\n");
    scanf("%d",&p->rdv);

}
void afficherPatient(Patient p)
{
    if(p.rdv==1)
        {
            printf("le nom de patient: %s\n",p.nom);
            printf("le prenom de patient: %s\n",p.prenom);
            printf("il a un rdv\n");
        }
    else
        {
            printf("le nom de patient: %s\n",p.nom);
            printf("le prenom de patient: %s\n",p.prenom);
            printf("il n'a pas un rdv\n");
        }

}
void enregistrerPatient(Patient p,char *chemin)
{
FILE *f=NULL;
f=fopen(chemin,"a+");
if (f!=NULL)
{
    fprintf(f,"%s   %s  %d",p.nom,p.prenom,p.rdv);
    fclose(f);
}
else printf("erreur : fichier introuvable");
}

void lireDernierPatient(Patient *p,char *chemin)
{
    FILE *f=NULL;

    Patient temporaire[20];

    int compteur =0;

    f=fopen(chemin,"r+");

    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %d\n",p->nom,p->prenom,&p->rdv)!=EOF)
        strcpy(temporaire[compteur].nom,p->nom);
        strcpy(temporaire[compteur].prenom,p->prenom);
        p->rdv=temporaire[compteur].rdv;
    }

    else
    {
        printf("erreur : fichier introuvable");
    }
}
