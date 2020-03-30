#include<stdio.h>
#define size 20

struct patient
{
    char phoneNo[size], emergencyNo[size];
    char date_Adm[20], time_Adm[20], patient_identity[100], date_release[20],time_release[20];
    char *name, *doc_name, *address, *symp, *medication, *allergies,*status;
}p1;

struct patient_advise
{
   char *precaution, *diet_advise, *prescription;
}a1;

