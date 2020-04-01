/**
 * @file count_visitor.h
 * 
 * @brief A function related to counting visitors.
 * 
 * @author Kazi Muhammad Jameel - kazimuhammadjameel@cmail.carleton.ca 
 * 
 */

/**
 * @brief A function to count number of visitors from the file 
 * "visitor_info.csv"
 * 
 * @details The function reads the "visitor_info.c" file and counts
 * total number of visitor visited.
 * 
 * @param[in] fname the name of the file form which the nummber of visitors will be counted.
 * 
 * @return Returns number of visitor as count if the file is read succesfully. 
 * returns -1 if the file cannot be opened.
 * 
 */

int count_visitor(char *fname);