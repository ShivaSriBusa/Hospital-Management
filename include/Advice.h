/* A structure is defined to store precaution, diet advise and prescription advised by doctor */

struct patient_advise
{
    /* Variables to stor precaution, diet advice and prescriptiom */
   char *precaution, *diet_advise, *prescription;
}a1;

/*This function takes patients  name and phone number as input and stores precution, diet advice and 
prescription for a patient in the file "patient_advice.csv". Return type is integer as it returns zero*/

int Advice(char *pname,char *ph);
