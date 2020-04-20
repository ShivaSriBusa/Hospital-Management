/**
 * @file display_advice.h
 *
 * @brief A Function that reads and displays content of patient_advice.csv.
 *
 * @author Shiva Sri Busa - Shivasribusa@cmail.carleton.ca
 *
 */

/**
 * @brief A function to display patient advice details
 *
 * @details Here prescription, precaution and diet advice related to a patient will be displayed.
 * The patient will be searched by patient name and phone number from the patient_advice.csv file.
 * Then the corresponding information will be displayed from this file.
 *
 * @param[in] patient name and patient phone number.
 *
 * @return Return value is int.
 */

#ifndef __display_advice__
#define __display_advice__
#endif // __display_advice__
int display_advice(char *name, int ph);