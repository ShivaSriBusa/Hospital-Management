/**
 * @file display_advice.h
 *
 * @brief A Function that reads and displays content of patient_advice.csv.
 *
 * @author Shiva Sri Busa - Shivasribusa@cmail.carleton.ca
 * 
 */

/**
 * @brief A function to allocate room in general ward/special ward if patient has physical injury/chronic symptoms 
 * based on availability. If none of those symptoms then patient is not admitted.
 * 
 * @details Here prescription, precaution and diet advice related to a patient will be displayed. 
 * The patient will be searched by his name and number from the �patient_advice.csv� file. 
 * Then the corresponding information will be displayed from this file.
 *
 * @param[in] patient name and patient phone number.
 * 
 * @return Return value is int.
 */




int display_advice(char *name,char *ph);
