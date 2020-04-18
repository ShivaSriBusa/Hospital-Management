/*
 * @file advice.h
 *
 * @brief A collection of structure and function related to storing advice details in "patient_advice.csv".
 *
 * @author Shiva Sri Busa - shivasribusa@cmail.carleton.ca
 * 
 */

/*
 * @brief A Structure containing necessary variables to store the details of advice given to patients.
 * 
 * @details Patient advice information can be stored using variables of structure struct patient_advise.
 * 
 */

#ifndef __advice__
#define __advice__
#endif // __advice__

struct patient_advise
{
   char *precaution, *diet_advise, *prescription;
}a1;

int advice(char *pname,char *ph);
