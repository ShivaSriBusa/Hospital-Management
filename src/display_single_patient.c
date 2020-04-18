/**
 * @file dispaly_single_patient.c
 *
 * @brief Implementation of display a particular patient who is admitted to the hospital.
 *
 * @author Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/display_single_patient.h"

/** @details Here the user will be able to input the necessary information related to the patient. 
* Following are the information that will be collected:
* • Patient id.
* • Patient Phone number.
* After taking the patient id, it will check if the patient is admitted in the hospital at that particular moment.
* If with the patient id a match is found in the "patient_record.csv" file then it will display all the corresponding details of the patient that are stored in the "patient_record.csv" file.
* 
*
* @param[in] Function has two input parameters.
*
* @return Function prints a message "No record found" if the file "patient_record.csv" does not contain that patient information and returns -1. Else returns 0 on successful execution. 
*/

int display_single_patient(char *name, char *ph)    {
    FILE *fp=fopen("../src/patient_record.csv","r");
	char string[1024];
    int row_count = 0;
    int field_count = 0,t_ph,u_ph,n=0;
    char *field,*token;
     if (!fp)   {
        printf("Can't open file\n");
        return -1;
    }
    while (fgets(string, 1024, fp)) {
    field_count = 0;
    row_count++;
    if (row_count == 1) {
        continue;
    }
    field = strtok(string, ",");
    token=field;
    token = strtok(NULL, ",");
    if(strcmp(token,name)==0)   {
        n++;
        token = strtok(NULL, ",");
        t_ph=atoi(token);
        u_ph=atoi(ph);
        if(t_ph==u_ph)  {
            while (field)   {

                if (field_count == 0)   {
                    printf("Id:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                     field_count++;
                    }
                if (field_count == 1)   {
                    printf("Name:");
                    printf("%s\n",name);
                    field_count++;
                    }
                if (field_count == 2)   {
                    printf("Phone:");
                    printf("%s\n",token);
                    field_count++;
                    }
                if (field_count == 3)   {
                    printf("Address:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 4)   {
                    printf("Emergency phone:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 5)   {
                    printf("Date of Admission:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 6)   {
                    printf("Time of Admission:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 7)   {
                    printf("Symptoms:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 8)   {
                    printf("Doctors name:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 9)   {
                    printf("Identity Number:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 10)  {
                    printf("Medication:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 11)  {
                    printf("Allergies:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
                if (field_count == 12)  {
                    printf("Discharge status:");
                    printf("%s\n",field);
                    field = strtok(NULL, ",");
                    field_count++;
                    }
            }printf("\n");
        }
    else    {
        printf("\nPhone number did not match!");
        fclose(fp);
        return -1;
                }
        }
    if(n==0)    {
        printf("\nNo record found!");
        fclose(fp);
        return -1;
        }
    }
    fclose(fp);
    return 0;
}
