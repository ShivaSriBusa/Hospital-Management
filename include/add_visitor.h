/**
 * @file add_visitor.h
 *
 * @brief Implementation of adding the visitor details to the corresponding file.
 *
 * @author Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca
 * 
 */

#ifndef size
#define size 11
#endif // size
#ifndef  __add_visitor__
#define  __add_visitor__
#endif // __add_visitor__

/** @details Here the user will be able to input the necessary information i.e. the patient id of the patient and the all the relevant details of the visitor. 
* Following are the information that will be collected:
* • Patient id.
* • Visitor Name.
* • Visitor Address.
* • Visitor Phone number.
*
* After taking the patient id as input, it will check if the patient is admitted in the hospital at that particular moment.
* If with the patient id a match is found in the "general_rooms.csv" and "special_rooms.csv". Then the visitor details will be taken as an input and stored in the "visitor_info.csv" file.
* 
*
* @param[in] Function has three input parameters.
*
* @return Function returns -1 if the file "visitor_info.csv" is not found. Stores information and returns 0 on successful execution.
*/

struct visitor
{
    char phone_no[size];
    char *name,*address;
}v1;

int add_visitor(char *filename,char *str,char*ph);
