/**
 * @file rooms.h
 *
 * @brief A collection of functions related to the checking availability of rooms for admitted patients.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

/**
 * @brief A function to read the file "general_rooms.csv" and retun availability in general ward.
 * 
 * @details room capacity is only for 10 patients. Checks if space is available in "general_rooms.csv".
 * If available, returns flag value as signal to disease function. Disease function process this signal and stores
 * patient details in "general_rooms.csv" file. If it returns a flag for no availability, then appropriate message is displayed.
 * 
 * @return Returns 0 if no availability else returns new row number for patient to be added, if room is available.
 */

int general_rooms();

/**
 * @brief A function to read the file "special_rooms.csv" and return availability in special ward.
 * 
 * @details room capacity is only for 10 patients. Checks if space is available in "special_rooms.csv".
 * If available, returns flag value as signal to disease function. Disease function process this signal and stores
 * patient details in "special_rooms.csv" file. If it returns a flag for no availability, then appropriate message is displayed.
 * 
 * @return Returns 0 if no availability else returns new row number for patient to be added, if room is available.
 */

int special_rooms();
