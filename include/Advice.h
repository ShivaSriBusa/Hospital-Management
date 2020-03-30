/**
 * @file advice.h
 *
 * @brief A collection of structure and function related to storing advice details in "patient_advice.csv".
 *
 * @author Shiva Sri Busa - shivasribusa@cmail.carleton.ca
 * 
 */

/**
 * @brief A Structure containing necessary variables to store the details of advice given to patients.
 * 
 * @details Patient advice information can be stored using variables of structure struct patient_advise.
 * 
 */



struct patient_advise
{
   char *precaution, *diet_advise, *prescription;
}a1;

int Advice(char *pname,char *ph);
