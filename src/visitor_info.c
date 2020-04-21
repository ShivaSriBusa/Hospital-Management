/**
 * @file visitor_info.c
 *
 * @brief Implementation of displaying the visitor details from the corresponding "visitor.csv" file.
 *
 * @author Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca
 * 
 */

#include "../include/visitor_info.h"
#include "../include/add_visitor.h"
#include<stdio.h>
#include<stdlib.h>

/** @details Here the user will be able to input the necessary information of the visitor. 
* Following are the information that will be collected:
* • Patient Name.
* • Patient Phone number.
*
* After taking the visitor name and phone number as input, it will pass these parameters to add_visitor function to add visitor details if patient is admitted either in general or special ward.
* If with the visitor details a match is found in either of the files then the visitor details will be displayed.
* 
*
* @param[in] Function has two input parameters.
*
* @return Function returns 0 on successful exection. 
*/

int visitor_info(char *name,char *ph)
{
    add_visitor("../src/general_rooms.csv",name,ph);
    add_visitor("../src/special_rooms.csv",name,ph);
    return 0;
}
