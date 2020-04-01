/**
 * @file add_patient.c
 *
 * @brief Implementation of adding patient details to file.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

#include<stdio.h>
#include<string.h>
#include "../include/add_patient.h"
#include<stdlib.h>
#include "../include/id_generate.h"
#include "../include/disease.h"

/** @details Here the user will be able to input all the necessary information related to the patient. 

* Following are the information that will be collected:
* • Patient Name.
* • Patient Address.
* • Patient Contact Number and Emergency Contact number.
* • Date of Admission.
* • Time of Admission.
* • Disease symptoms.
* • Doctor attending the patient.
* • Patient contact details.
* • Unique Patient Identity.
* • Medication followed by Patient.
* • Allergies.
* • Discharge status (initially set as No by default)
*
* After taking all the information, patient’s symptoms will be checked to identify if he has a chronic disease
* or a physical injury. The hospital management will identify the symptom as chronic or physical and will pass the input accordingly.
* Any patient information whether admitted or not  will be stored by the software in “patient_details.csv” file. 
* After storing the patient information, Disease function is invoked to check the symptoms and allocate rooms if available. 
*
* @param[in] Function has no input parameters.
*
* @return Function doesn't return anything. 
*/

void add_patient()
{

// Integer variable of size 50 for size of memory allocated to pointer variable
    int s = 50; 

// Integer variable id calls the id_generate function to generate row number for new record.
    int id=id_generate("patient_record.csv"); 

// Structure variables allocated memory.
    p1.address = (char *)malloc(s);
    p1.symp = (char *)malloc(s);
    p1.doc_name = (char *)malloc(s);
    p1.name = (char *)malloc(s);
    p1.medication = (char *)malloc(s);
    p1.allergies = (char *)malloc(s);
    
    // creating file pointer to work with files.
    FILE *fptr;

    // opening file in append mode.
    fptr = fopen("patient_record.csv", "a");

    // exiting program if file not found.
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    //Else details of patient collected and processed.
    else
    {
        printf("Please input patient name:");
        gets(p1.name);
        printf("Please input patient address:");
        gets(p1.address);
        printf("Please input patient contact number:");
        gets(p1.phoneNo);
        printf("Please input patient emergency contact number:");
        gets(p1.emergencyNo);
        printf("Please input patient date of admission (DD-MM-YYYY):");
        gets(p1.date_Adm);
        printf("Please input patient time of admission (HH:MM) :");
        gets(p1.time_Adm);
        printf("Please input patient symptoms:");
        gets(p1.symp);
        printf("Please input doctors attending :");
        gets(p1.doc_name);
        printf("Please input Patient identity number :");
        gets(p1.patient_identity);
        printf("Please input patient medications:");
        gets(p1.medication);
        printf("Please input patient allergies:");
        gets(p1.allergies);

        //fprintf is a function that is used to write records to the file. 
        fprintf(fptr,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",id,p1.name,p1.phoneNo,p1.address,p1.emergencyNo,p1.date_Adm,
                p1.time_Adm,p1.symp,p1.doc_name,p1.patient_identity,p1.medication,p1.allergies,"No");
        
        //Calling disease function to check symptoms.
        disease(p1.symp,p1.name,p1.phoneNo);

        //Freeing the allocated memory to pointer. It is must to free the memory after use.
        free(p1.address);
        free(p1.allergies);
        free(p1.name);
        free(p1.doc_name);
        free(p1.medication);
        free(p1.symp);
    }

    //Closing the file read is a good practice.
    fclose(fptr);
}
