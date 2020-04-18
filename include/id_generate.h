/**
 * @file id_generate.h
 *
 * @brief A Function related to the allocation of rooms for admitted patients.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

/**
 * @brief A function to generate new row number for file passed as an input.
 * 
 * @details This function reads the file passed as an input and counts number of rows in it,
 * it is then used to generate new row number for the file which we pass as input.
 * 
 * @param[in] It takes file name as input parameter.
 * 
 * @return Returns integer, a new row number on successful execution.
 */

int id_generate(char *file);
