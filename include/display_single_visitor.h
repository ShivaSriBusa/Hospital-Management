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
 * @param[in] The function takes name and phone number of the patient as input parameter.
 * 
 * @return Return type is integer. It returns zero displaying appropriate message to the console window
 * and returns back to main.
 */

int display_single_visitor(char *name, char *ph);
