#ifndef size
#define size 11
#endif // size
#ifndef  __add_patient__
#define  __add_patient__
#endif // __add_patient__

struct patient
{
    char phoneNo[size], emergencyNo[size];
    char date_Adm[size], time_Adm[size], patient_identity[size], date_release[size],time_release[size];
    char *name, *doc_name, *address, *symp, *medication, *allergies,*status;
}p1;
void add_patient();
