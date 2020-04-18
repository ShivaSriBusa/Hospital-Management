/**
 * @file dispaly_single_patient.h
 *
 * @brief Implementation of display a particular patient who is admitted to the hospital.
 *
 * @author Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca
 * 
 */

#ifndef __display_single_patient__
#define __display_single_patient__
#endif // __display_single_patient__

/** @details Here the user will be able to input the necessary information related to the patient. 
* Following are the information that will be collected:
* • Patient id.
* • Patient Phone number.
* After taking the patient id, it will check if the patient is admitted in the hospital at that particular moment.
* If with the patient id a match is found in the "patient_record.csv" file then it will display all the corresponding details of the patient that are stored in the "patient_record.csv" file.
* 
*
* @param[in] Function has two input parameters.
*
* @return Function prints a message "No record found" if the file "patient_record.csv" does not contain that patient information and returns -1. Else returns 0 on successful execution. 
*/

int display_single_patient(char *name, char *ph);
