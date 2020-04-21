/*
 * @file display_advice.c
 *
 * @brief display patient advice details
 *
 * @author Shiva Sri Busa - shivasribusa@cmail.carleton.ca
 *
 */


#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "../include/display_advice.h"
#include "../include/id_generate.h"

/*
 * @brief This function is to display patient advice details
 *
 * @details This function takes the patient name and phone number as an
 * input and display the prescription, precaution and diet advice
 * details related to admitted patient.
 *
 * @param[in] Patient name and patient phone number (char *pname, char *ph)
 *
 * @return This function returns an integer 0 (Zero) upon successful
 * execution.
 */


int display_advice(char *name,int ph){
	
	//Open a .csv file in read mode
	FILE *fp = fopen("../src/patient_advice.csv", "r");
    	
	char str[15];
      
    	int n = 0,len,u_ph,m = 0;
    	
	len = sprintf(str, "%d", ph);
        
	       
    	if(len == 10 ){
        	//Display error message if file format is not .csv
        	if (!fp){
            		printf("Can't open file\n");
            		return -1;
        	}

        	char buf[1024];
       		int row_count = 0;
        	int field_count = 0,t_ph;
        
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
                 		n++;
                 		token = strtok(NULL,",");
                 		t_ph = atoi(token);
                 		u_ph = ph;
            
                 		//Display patient advice details as per entered inputs (Patient name and Phone number)
                 		if(t_ph == u_ph){
	             			m++;
                     			
					while (field){
                         			if(field_count == 0) {
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
                         			}
                     			}
		     			printf("\n");
                 		}
             		}
		}
	}
        
	
    	if(m != 10 && n != 0){
        	printf("\nPhone number should be 10 digits");	        
	}        
    	else if(n == 0){
        	//Displaying message if no records found as per entered input values
        	printf("\nNo record found!");
    	}

    	//Closing the file read is a good practice.
    	fclose(fp);
    	return 0;
}
