/**
 * @file display_single_visitor.h
 * 
 * @brief A function to display information about a visitor who visited a patient.
 * 
 * @author Kazi Muhammad Jameel - kazimuhammadjameel@cmail.carleton.ca 
 * 
 */

/**
 * @brief A function to display information of a visitor who visited a patient from
 * the "visitor_info.csv" file.
 * 
 * @details This function displays the visitor information on consle window by searching
 * the visited patients name and phone number from the file "visitor_info.csv". 
 * 
 * @param[in] name a charachter pointer that will contain the name of a patient for whom the visitor
 * information is to be displayed.
 * @param[in] ph a character pointer that will contain the phone number of a patient for whom the visitor
 * information is to be displayed.
 * 
 * @return Return type is integer. It returns 0 if file is found and patient information is
 * displayed. And returns -1 if file cannot be opened.
 */

#ifndef __display_single_visitor__
#define __display_single_visitor__
#endif // __display_single_visitor__

int display_single_visitor(char *name, char *ph);
