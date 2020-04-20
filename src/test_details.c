/*
 * @file test_details.c
 *
 * @brief This function has all the test details 
 *
 * @author Shiva Sri Busa - shivasribusa@cmail.carleton.ca
 *
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/test_details.h"
#include "../include/id_generate.h"

int display_test(char *name, char  *ph){
        //Variable intialisation
	int id,field_count = 0,row_count = 0,t_ph,ch,u_ph;
	char string[1024],inp[10];
	FILE *fptr1,*fptr2;
	int n = 0,m = 0;
	
	//open file in read mode
	fptr1 = fopen("../src/patient_record.csv","r");

	//open file in append mode
	fptr2 = fopen("../src/test_details.csv","a");
	id = id_generate("../src/test_details.csv");
        
        //display message if no file found
	if (fptr1 == NULL){
        	printf("\n file opening failed ");
        	return -1;
    	}
   
	while (fgets(string, 1024, fptr1)){
        	field_count = 0;
            	row_count++;

            	if (row_count == 1){
                	continue;
            	}
            
		char *field = strtok(string, ",");
            	char *token = field;
            	token = strtok(NULL,",");
            
		if(strcmp(token,name) == 0){
			n++;
                	token = strtok(NULL,",");
                	t_ph = atoi(token);
                        u_ph = atoi(ph);
                
			if(t_ph == u_ph){
				m++;
                    		
				while(field){
                        		if(field_count == 0){
                            			fprintf(fptr2,"%d,%s,",id,name);
                            			field_count++;
                        		}
                        
					if(field_count == 1){
                            			fprintf(fptr2,"%s,",token);
                            			field_count++;
                            			field = strtok(NULL,",");
                        		}
                        
					if(field_count == 6){
                            			printf("\n%s",field);
                            			printf("\nIs the symptom chronic (C) / Physical (P) ? ");
                            			printf("\nPress 1 for chronic");
                            			printf("\nPress 2 for physical");
                            			printf("\nPlease input your choice:");
                            			scanf("%d",&ch);
                            			fgetc(stdin);
                            			
						if(ch == 1){
                                			printf("\nList of Test available: ");
                                			printf("\n1. Blood Test (B)");
                                			printf("\n2. Urine Test (U)");
                                			printf("\n3. Weight check (W)");
                                			printf("\nInput your choices (separated by ';') : ");
                                			gets(inp);
                                			fprintf(fptr2,"%s\n",inp);
                            			}
                            			else if(ch == 2){
                                			printf("\nList of Test available: ");
                                			printf("\n1. X-Ray (X)");
                                			printf("\n2. Pressure Check (P)");
                                			printf("\n3. MRI Scan (M)");
                                			printf("\nInput your choices (separated by ';') : ");
                                			gets(inp);
                                			fprintf(fptr2,"%s\n",inp);
                            			}
                            			else{
                                			printf("\n Wrong choice");
                            			}
                        		}
                        		field_count++;
                        		field = strtok(NULL,",");
                    		}
                	}
        	}
	}
	
	//display if no record found
        if(n == 0){
		printf("\nNo record found!");
	}

	//displays if phone number doesn't match as per the record
	if(m == 0 && n != 0){
		printf("\nPhone number did not match!");
	}

        fclose(fptr1);
        fclose(fptr2);
	return 0;
}
