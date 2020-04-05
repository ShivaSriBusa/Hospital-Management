/*
 * @file display_advice.c
 *
 * @brief Display patient advice details
 * 
 * @author Shiva Sri Busa - shivasribusa@cmail.carleton.ca
 * 
 */
 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "include/display_advice.h"

/* 
 * @brief This function is to display patient advice details
 *
 * @details This function takes the patient name and phone number as an
 * input and display the prescription, precaution and diet advice
 * details related to admitted patient.
 *
 * @param[in] Patient name and patient phone number (char *pname, char * ph)
 *
 * @return This function returns an integer 0 (Zero) upon successful
 * execution.
 */



int display_advice(char *name,char *ph){
    //Open a .csv file in read mode
    FILE *fp = fopen("patient_advice.csv", "r");

    //Display error message if file format is not .csv
    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    char buf[1024];
    int row_count = 0;
    int field_count = 0;
    while (fgets(buf, 1024, fp)){
        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }
        
        char *field = strtok(buf, ",");
        char *token=field;
        token = strtok(NULL,",");
        if(strcmp(token,name) == 0){
            token = strtok(NULL,",");
			
	    //Display patient advice details as per entered inputs (Patient name and Phone number)
            if(strcmp(token,ph) == 0){
                while (field){
                    if (field_count == 0) {
			printf("Id:\t");
			printf("%s\n",field);
			field = strtok(NULL, ",");
			field_count++;
                    }
		    //Display matched/entered patient name
                    if (field_count == 1) {
			printf("Name:\t");
			printf("%s\n",name);
			field_count++;
                    }
					
		    //Display matched/entered patient phone number
                    if (field_count == 2) {
			printf("Phone:\t");
			printf("%s\n",token);
			field_count++;
                    }
					
		    //Display patient precaution information
                    if (field_count == 3) {
			printf("Precaution:\t");
			printf("%s\n",field);
			field = strtok(NULL, ",");
			field_count++;
                    }				
		    //Display patient prescription details
                    if (field_count == 4) {
			printf("Prescription:\t");
			printf("%s\n",field);
			field = strtok(NULL, ",");
			field_count++;
                    }
					
		    //Display patient diet advice details
                    if (field_count == 5) {
			printf("Diet advice:\t");
			printf("%s\n",field);
			field = strtok(NULL, ",");
			field_count++;
			break;
                    }
                }
		printf("\n");
            }
            else{
		//Displaying message if no records found as per entered input values
                printf("\nNo record found!");
            }
        }
    }
    //Closing the file read is a good practice.
    fclose(fp);
    return 0;
}
