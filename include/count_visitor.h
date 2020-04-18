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
 * "visitor_info.csv". 
 * 
 * @details The function reads the "visitor_info.csv" file and counts
 * total number of visitors visited. This function can read any file with any given name
 * but will return an integer which will not be usefull.
 * 
 * @param[in] fname the name of the file form which the number of visitors will be counted.
 * 
 * @return Returns number of visitors as count-1 (subtracting 1 because top row of the file
 * contains header for the coloum) on successful executionand returns -1 if file cannot be opened. 
 * Returns -1 if the file cannot be opened.
 * 
 */

#ifndef __count_visitor__
#define __count_visitor__
#endif // __count_visitor__

int count_visitor(char *fname);