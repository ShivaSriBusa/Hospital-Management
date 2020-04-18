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

<<<<<<< HEAD
#ifndef __advice__
#define __advice__
#endif // __advice__

struct patient_advise
=======


struct patient_advice
>>>>>>> 5342b606f0daa433dd5e559e4a7ddada0e686775
{
   char *precaution, *diet_advise, *prescription;
}a1;

int advice(char *pname,char *ph);
<<<<<<< HEAD
=======

>>>>>>> 5342b606f0daa433dd5e559e4a7ddada0e686775
