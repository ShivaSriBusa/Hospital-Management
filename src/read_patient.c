/**
 * @file read_patient.c
 *
 * @brief Implementation of reading patient details from file.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

#include<stdio.h>
#include<string.h>
#include "../include/read_patient.h"

/** @details Reads patient details from "patient_record.csv" file, if file exists. Reads line by line from the file.
 * 
 * @param[in] No input paramater. Does not take any values as input parameter.
 * 
 * @return Returns 0 on successful execution and -1 if file doesn't exist.
 * 
 */

int read_patient()
{
    FILE *fp=fopen("../src/patient_record.csv","r");
	char string[1024];
	char *field;
    int row_count = 0;
    int field_count = 0;
     if (!fp) {
        printf("Can't open file\n");
        return -1;
    }
    while (fgets(string, 1024, fp))
        {
            field_count = 0;
            row_count++;
            if (row_count == 1)
            {
                continue;
            }
            field = strtok(string, ",");
            while (field)
            {
                if (field_count == 0)
                {
                    printf("Id:");
                }
                if (field_count == 1)
                {
                    printf("Name:");
                }
                if (field_count == 2)
                {
                    printf("Phone:");
                }
                if (field_count == 3)
                {
                    printf("Address:");
                }
                if (field_count == 4)
                {
                    printf("Emergency phone:");
                }
                if (field_count == 5)
                {
                    printf("Date of Admission:");
                }
                if (field_count == 6)
                {
                    printf("Time of Admission:");
                }
                if (field_count == 7)
                {
                    printf("Symptoms:");
                }
                if (field_count == 8)
                {
                    printf("Doctors name:");
                }
                if (field_count == 9)
                {
                    printf("Identity Number:");
                }
                if (field_count == 10)
                {
                    printf("Medication:");
                }
                if (field_count == 11)
                {
                    printf("Allergies:");
                }
                if (field_count == 12)
                {
                    printf("Discharge status:");
                }
                printf("%s\n",field);
                field_count++;
                field = strtok(NULL, ",");
                            }
        }
        return 0;
}
