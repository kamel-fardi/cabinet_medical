#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "list.h"
int main()
{
    liste l=creer_liste();;
    int rdv=0,sansRdv=0;
    Patient kamel,ahmed,hocine;
    char chemin[]="lienfichier/patients.txt";
    char cheminb[]="lientfichier/patientsb.txt";


    //saisirPatient(&o->p);
    /*saisirPatient(&ahmed);
    AjouterPatient(l,ahmed);
    saisirPatient(&hocine);
    AjouterPatient(l,hocine);
    saisirPatient(&kamel);
    AjouterPatient(l,kamel);
    printf("============affichage====================\n");
    ConsulterSalleAttente(l);
    printf("=============supp==================\n");
    l=SupprimePatient(l);
    RendezVous(l,&rdv,&sansRdv);
    printf("les rdv :%d\nles sansRDV :%d\n",rdv,sansRdv);
    printf("============affichage====================\n");
    ConsulterSalleAttente(l);
    printf("======================================\n");
    sauvgarderPatients(l,chemin);*/
    //enregistrerPatient(kamel,chemin);

    recupererListePatients(l,chemin);
    ConsulterSalleAttente(l);
    sauvgarderPatients_binary(l,cheminb);
    //lireDernierPatient(&kamel,chemin);
    return 0;
}
