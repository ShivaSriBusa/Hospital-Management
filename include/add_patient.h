/**
 * @file add_patient.h
 *
 * @brief Implementation of adding patient details to file.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

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
* Any patient information whether admitted or not  will be stored by the software in “patient_record.csv” file. 
* After storing the patient information, Disease function is invoked to check the symptoms and allocate rooms if available. 
*
* @param[in] Function has no input parameters.
*
* @return Function doesn't return anything. 
*/

void add_patient();
