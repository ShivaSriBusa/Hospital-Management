#define size 10

/* Structure containing necessary variables to store the details of patients */

struct patient 
{
    //For storing phone number
    char phoneNo[size], emergencyNo[size];
    // For storing date and time of admission and release of patients
    char date_Adm[20], time_Adm[20], date_release[20],time_release[20]; 
    //For storing unique patient_identity number (manual input - not auto generated)
    char  patient_identity[100];
    //For storing regular Patient details (patient name, address, symptoms, medication, allergies and discharge status)
    char *name, *address, *symp, *medication, *allergies,*status;
    //For storing doctors name
    char *doc_name;
}p1;

/* Function "add_patient" takes input from hospital, details of patients and stores it in "patient_record.csv" */

void add_patient();
