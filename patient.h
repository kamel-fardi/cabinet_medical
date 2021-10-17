#ifndef patient
#define patient
typedef struct
{
    char nom[20],prenom[20];
    int rdv;
}Patient;
/*typedef struct lis
{
    Patient p;
    struct lis* suivant;
}*liste_patients;*/
void saisirPatient(Patient *p);
void afficherPatient(Patient p);
void enregistrerPatient(Patient p,char *chemin);
void lireDernierPatient(Patient *p,char *chemin);



#endif // patient
