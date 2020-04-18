/**
 * @file search_in_file.h
 * 
 * @brief A function related to updating patient information.
 * 
 * @author Kazi Muhammad Jameel - kazimuhammadjameel@cmail.carleton.ca 
 * 
 */

/**
 * @brief A function to search a patient from a file, with the file name, patients name and phone number
 * passed as input. 
 * 
 * @details This function reads a file "patient_record.csv" passed as an input, and searches if the 
 * name and phone number of a patient which is also passed as an input to this function  is available 
 * in the given file. If the patient is found, it dispalys the patients information by invoking a function 
 * "display_single_patient". From the displayed information the user can know if the patient is discharged
 * or not by looking at the discharge status. If the patient is already discharged it does nothing and
 * returns back to the main function, if the patient needs to be discharged,the function updates the 
 * "pateint_record.csv" as discharged for the patient and updates the "discharged_list.csv". The 
 * "discharged_list.csv" contains list of patients  name who are discharged with their release time and 
 * date. And if the patient is not discharged it allows the user to input doctor's advice, prescription 
 * and precatuions by invoking a separate function "advice".
 * 
 * @param[in] fname name of a file from which the patient will be searched.
 * @param[in] str name of a character poninter that will contain the name of a patient to be searched.
 * @param[in] ph name of a character pointer that will contain the phone number of a patient to be searched
 * 
 * @return the function returns integer. Returns 0 if the function is executed successfully. Returns -1
 * if the input patient name and phone number is not found in the given file "patient_record.csv".
 */

/* This header file contains the definition for the function "Search_in_File.c". The funtion is used to 
search a patient by his name and phone number, display the patients information by invoking "display_single
_patient" and update "patient_record.csv" and "discharged_list.csv if the patient is discharged; or input
 doctor's advice, precatution and prescriptio if not discharged by invoking a separate function "Advice".*/

#ifndef __search_in_file__
#define __search_in_file__
#endif // __search_in_file__
int search_in_file(char *fname, char *str, char*ph);

