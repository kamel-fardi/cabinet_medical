#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "patient.h"
liste creer_liste()
{
    liste liste_patients;
    liste_patients=malloc(sizeof(struct cel));
    liste_patients->suivant=NULL;//il faut le faire sinon suivant peut point ver une memoire qlqnq
    return liste_patients;
}
liste AjouterPatient(liste tete, Patient P)
{
    liste Element_liste=malloc(sizeof(struct cel));
    Element_liste->p=P;
    Element_liste->suivant=NULL;
    if (tete==NULL)
    {
        tete=Element_liste;
        afficherPatient(tete->p);
        printf("\n bien ajoutee\n");
    }
    else
    {
        liste cour=NULL;
        cour=tete;
        while(cour->suivant!=NULL)
        {
            cour=cour->suivant;
        }
        cour->suivant=Element_liste;
        cour=cour->suivant;
        printf("l'ajout de\n");
        afficherPatient(cour->p);
    }

    return tete;
}
void RendezVous(liste tete, int *rdv,int *sansRdv)
{
    *rdv=0;
    *sansRdv=0;
    liste cour=NULL;
    cour=tete;
    if (tete==NULL) return;
    if(tete->suivant==NULL)
    {
        if(tete->p.rdv==1)(*rdv)++;
        if(tete->p.rdv==0)(*sansRdv)++;
    }
    else
    {
        while(cour!=NULL)
        {
            if(cour->p.rdv==1)(*rdv)++;
            if(cour->p.rdv==0)(*sansRdv)++;
            cour=cour->suivant;
        }
    }
}
void ConsulterSalleAttente(liste tete)
{
    liste cour;
    cour=tete;
    if(tete==NULL)
    {
        printf("la salle est vide");
    }
    else
    {
        printf("les patients qui ont des rdvs :\n");
        while(cour!=NULL)
        {
            if(cour->p.rdv==1)
            {
                afficherPatient(cour->p);
            }
            cour=cour->suivant;
        }
        printf("\n");
        cour=tete;
        printf("les patients qui n'ont pas des rdvs :\n");
        while(cour!=NULL)
        {
            if(cour->p.rdv==0)
            {
                afficherPatient(cour->p);
            }
            cour=cour->suivant;
        }
    }

}
liste SupprimePatient(liste tete)
{
    liste cour,pres;
    cour=creer_liste();
    pres=creer_liste();
    pres=tete;
    cour=tete->suivant;
    int r=0,sr=0;
    RendezVous(tete,&r,&sr);
    if(cour->suivant==NULL)
    {
        free(cour);
        return NULL;
    }
    else
    {
        if(r==0){
            tete=cour->suivant;
            free(cour);
            return tete;
        }
            while(cour!=NULL)
            {
            if(cour->p.rdv==1)
                {

                if(cour->suivant==NULL){

                        pres->suivant=NULL;
                        free(cour);
                        return (tete);
                        }
                else{
                    pres->suivant=cour->suivant;
                    free(cour);
                    return(tete);
                }
                }
            pres=cour;
            cour=cour->suivant;

            }
    }
    return 0;
}

void sauvgarderPatients(liste tete,char *chemin)
{
    FILE *f=NULL;
    liste cour;
    cour=creer_liste();
    cour=tete->suivant;
    f=fopen(chemin,"a+");
    if (f==NULL)
    {
        printf("le fichier n'existe pas\n");
    }
    else
    {
        if(cour->suivant==NULL){
            fprintf(f,"%s   %s  %d\n",cour->p.nom,cour->p.prenom,cour->p.rdv);
            fclose(f);
            free(tete);
            free(cour);
            return;}
        else{
        do
        {
            fprintf(f,"%s   %s  %d\n",cour->p.nom,cour->p.prenom,cour->p.rdv);
            cour=cour->suivant;
        }
        while(cour!=NULL);
        fclose(f);
    }
    free(tete);
    free(cour);
}
}
void recupererListePatients(liste tete,char *chemin)
{
    FILE *f=NULL;
    Patient p;
    liste Element_liste=malloc(sizeof(struct cel));
    Element_liste->suivant=NULL;
    f=fopen(chemin,"r+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %d\n",p.nom,p.prenom,&p.rdv)!=EOF)
        {
            printf("%s %s %d\n",p.nom,p.prenom,p.rdv);
            AjouterPatient(tete,p);
        }
    }

    else
    {
        printf("erreur : fichier introuvable");
    }
    fclose(f);
}
void recupererListePatients_binary(liste tete,char *chemin)
{
    FILE *f=NULL;
    Patient p;
    liste Element_liste=malloc(sizeof(struct cel));
    Element_liste->suivant=NULL;
    f=fopen(chemin,"rb+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %d\n",p.nom,p.prenom,&p.rdv)!=EOF)
        {
            printf("%s %s %d\n",p.nom,p.prenom,p.rdv);
            AjouterPatient(tete,p);
        }
    }

    else
    {
        printf("erreur : fichier introuvable");
    }
    fclose(f);
}

void sauvgarderPatients_binary(liste tete,char *chemin)
{
    FILE *f=NULL;
    liste cour;
    cour=creer_liste();
    cour=tete->suivant;
    f=fopen(chemin,"ab+");
    if (f==NULL)
    {
        printf("le fichier n'existe pas\n");
    }
    else
    {
        if(cour->suivant==NULL){
            fprintf(f,"%s   %s  %d\n",cour->p.nom,cour->p.prenom,cour->p.rdv);
            fclose(f);
            free(tete);
            free(cour);
            return;}
        else{
        do
        {
            fprintf(f,"%s   %s  %d\n",cour->p.nom,cour->p.prenom,cour->p.rdv);
            cour=cour->suivant;
        }
        while(cour!=NULL);
        fclose(f);
    }
    free(tete);
    free(cour);
}
}
