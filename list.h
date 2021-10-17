#ifndef list
#define list
#include "patient.h"
typedef struct cel
{
    Patient p;
    struct cel* suivant;
}*liste;
/*typedef struct lis{
Patient ipatient;
struct lis* suivant;
}*element;*/
/*typedef struct t
{
    cellule prem,der,cour;
}*liste;*/
liste creer_liste();
liste AjouterPatient(liste tete, Patient p);//permet d'ajouter un nouveau patient a ala fin de la liste identifiee
                                            //par son pointeur tete

void RendezVous(liste tete,int *rdv,int *sansRdv);//compte et retourner le nombre de patients avec reendez-vous, et sans rdv

void ConsulterSalleAttente(liste tete);//affiche tout d'abord les patients avec rendez-vous ensuite les patients sans rdv

liste SupprimePatient(liste tete);//s'il n'y a aucun patient avec rendez-vous alors c'est le premier patient de la liste qui est supprime
                                 // sinon on supprime le premier patient qui a un rdv


void sauvgarderPatients(liste tete,char *chemin);//sauvgarder les patients dans un fichier accessible selon un chemin

void recupererListePatients(liste tete,char *chemin);//retourner dans une liste chainee les donnees d'un fichier accessible selon un chemin
void sauvgarderPatients_binary(liste tete,char *chemin);
void recupererListePatients_binary(liste tete,char *chemin);







#endif // list
