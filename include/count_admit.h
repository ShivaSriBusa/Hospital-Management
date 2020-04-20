/**
 * @file count_admit.h
 *
 * @brief Implementation of counting the number of patients admitted in the hospital.
 *
 * @author Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca
 *
 */

#ifndef __count_admit__
#define __count_admit__
#endif // __count_admit__

/**
*
*	@details The function reads the "general_rooms.csv" and “special_rooms.csv” file and counts
*	the total number of patients admitted in the hospital.
*
*
*   @param[in] Function has no input parameters.
*
*	@return Function returns total number of patients (positive integer) as count on successful execution
*	and returns -1 if the file cannot be opened.
*/

int count_admit(char *f1name, char *f2name);
