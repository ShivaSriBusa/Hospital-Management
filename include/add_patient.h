/**
 * @file add_patient.h
 *
 * @brief A collection of structure and function related to storing patient details in "patient_records.csv".
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

#ifndef size
#define size 11
#endif

/**
 * @brief A Structure containing necessary variables to store the details of patients.
 * 
 * @details Patient information can be stored using variables of structure struct patient.
 * Everything is stored in the form of character array and character pointer.
 * 
 */

struct patient
{
    // For storing phone number
    char phoneNo[size], emergencyNo[size];
    // For storing date and time of admission and release of patients
    char date_Adm[size], time_Adm[size], date_release[size],time_release[size];
    // For storing unique patient_identity number (manual input - not auto generated)
    char patient_identity[size];
    // For storing regular Patient details (patient name, address, symptoms, medication, allergies and discharge status)
    char *name, *address, *symp, *medication, *allergies,*status;
    // For storing doctors name
    char *doc_name;
}p1;

/**
 * @brief A Function to store the details of patients in "patient_record.csv".
 * 
 * @details Function "add_patient" takes input from hospital, details of patients and stores it in "patient_record.csv". 
 * Invokes disease function which identifies symptom and allocates room accordingly based on availability.
 * 
 * @return Return value is void.
 *
 */ 

void add_patient();
