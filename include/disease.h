/**
 * @file disease.h
 *
 * @brief A Function related to the allocation of rooms for admitted patients.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

/**
 * @brief A function to allocate room in general ward/special ward if patient has physical injury/chronic symptoms 
 * based on availability. If none of those symptoms then patient is not admitted.
 * 
 * @details room capacity is only for 10 patients. Disease function process this signal retuned by rooms function and stores
 * patient details in "general_rooms.csv" file if symptoms are related to physical injury, If it returns a flag for 
 * no availability, then appropriate message is displayed. If symptoms are related to chronic, patient details are stored
 * in "special_rooms.csv". If symptoms are neither physical nor chronic then displays appropriate message.
 * 
 * @param[in] It takes patient symptoms separated by a demiliter ";" in the file along with patient name and patient phone number.
 * 
 * @return Returns 0 on successful execution.
 */

int disease(char *symptom, char *patient_name,char*ph);