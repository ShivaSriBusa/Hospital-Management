/*
 * @file source.c
 *
 * @brief This function is to display list of options/services in the hospital
 *
 * @author Shiva Sri Busa - shivasribusa@cmail.carleton.ca
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/add_patient.h"
#include "../include/welcome_message.h"
#include "../include/visitor_info.h"
#include "../include/add_visitor.h"
#include "../include/advice.h"
#include "../include/count_admit.h"
#include "../include/count_visitor.h"
#include "../include/disease.h"
#include "../include/display_advice.h"
#include "../include/display_single_patient.h"
#include "../include/display_single_visitor.h"
#include "../include/id_generate.h"
#include "../include/read_patient.h"
#include "../include/rooms.h"
#include "../include/search_in_file.h"
#include "../test/include/test.h"
#include "../include/test_details.h"


/*
 * @brief This function is to display list of options/services in the hospital
 *
 * @details This function takes the 1,2,3,4,5,6 and 7 are the input values and displays/calls the associated function.
 * For option 1 : Add Patient Information
 * For option 2 : Display all Patient Information
 * For option 3 : Display prescription, precaution and diet advise
 * For option 4 : Display information on Patient Admitted
 * For option 5 : Update admitted Patients Record
 * For option 6 : Add Visitor Information
 * For option 7 : Display Visitor Information
 * and any other value ii will call default choice and it will display 'Invalid choice' message
 *
 * @return This function returns an integer 0 (Zero) upon successful execution.
 */

int main(int argc, char *argv[]){
	int opt;
    
	while ((opt = getopt(argc, argv, "hat")) != -1){
        	
		switch(opt){
            		case 'h':
                		printf("-t Runs automated unit testing and exits\n");
                		printf("-a Runs main program and exits\n");
                		return 0;
                		break;
            		case 't':
                		/* Run automated unit testing */
                		printf("Running automated unit testing\n");
                		all_test_case();
                		printf("Automated testing has completed\n");
                		return 0;
               			break;
            		case 'a':
                		/* Run main Hospital Management program */
                		printf("Running Hospital Management Program\n");
                		int inp,s=100,id,c;
    			
			welcome_message();
    			system("clear");
    			
			printf("\nPlease select one of the following:");
    			printf("\n1. Add Patient Information");
    			printf("\n2. Display all Patient Information");
    			printf("\n3. Display prescription, precaution and diet advise");
   			printf("\n4. Display information on Patient Admitted");
    			printf("\n5. Update admitted Patients Record");
    			printf("\n6. Add Visitor Information");
    			printf("\n7. Display Visitor Information");
    			printf("\n8. Test Details for Patient Symptoms");
    			printf("\nInput choice: ");
    			scanf("%d",&inp);
    			
			fgetc(stdin);
    			
			switch(inp){
    				case 1:
        				add_patient();
        				break;

    				case 2:
        				read_patient();
        				break;

    				case 3:
					id = id_generate("../src/patient_advice.csv");
        				p1.name = (char *)malloc(s);
        				int number;
        				
					if(id > 1){
            					printf("\nPlease input patient name: ");
            					gets(p1.name);
                                                
						if(strlen(p1.name) >= 50){
                                                        printf("\nName should not be more than 50 characters");	
							while(strlen(p1.name) >= 50){               						
        							printf("\nPlease input patient name: ");
            							gets(p1.name);	
							        continue;				                
        						}							
						}
						printf("\nPlease input patient phone number: ");
            					scanf("%d",&number);

						char str[15];
						int len;
						len = sprintf(str, "%d", number);                                               
						
						if(len != 10){
							printf("\nPhone number should be 10 digits"); 							
							
							while(len != 10){               						
        							printf("\nPlease input patient phone number: ");
            							scanf("%d",&number);	
							        len = sprintf(str, "%d", number);
								if(len != 10){
									printf("\nPhone number should be 10 digits");
								}								
            							continue;				                
        						}
						}
            					display_advice(p1.name,number);	
        				}
        				else{
            					printf("\nNo record found ");
        				}

        				free(p1.name);
        				break;

				case 4:
        				printf("\n1. Display a Patient Information");
       					printf("\n2. Display total number of Patients Admitted");
        				printf("\nInput choice: ");
        				scanf("%d", &inp);
        				
					fgetc(stdin);
        				
					if(inp == 1){
            					p1.name = (char *)malloc(s);
            					printf("\nPlease input patient name: ");
            					gets(p1.name);
            
						printf("\nPlease input patient phone number: ");
            					gets(p1.phone_no);
            					
						display_single_patient(p1.name,p1.phone_no);
            					free(p1.name);
        				}
        				else if(inp == 2){
            					c = count_admit();
            					printf("\nTotal number of admitted patients = %d",c-2);
        				}
        				break;

    				case 5:
        				p1.name = (char *)malloc(s);
        				printf("\nPlease input patient name: ");
        				gets(p1.name);

        				printf("\nPlease input patient phone number: ");
        				gets(p1.phone_no);

        				search_in_file("../src/patient_record.csv",p1.name,p1.phone_no);
        				free(p1.name);
        				break;

    				case 6:
        				p1.name = (char *)malloc(s);
        				printf("\nPlease input patient name: ");
        				gets(p1.name);

        				printf("\nPlease input patient phone number: ");
        				gets(p1.phone_no);

        				visitor_info(p1.name,p1.phone_no);
        				free(p1.name);
        				break;

    				case 7:
        				printf("\n1. Display a visitor Information");
        				printf("\n2. Display total number of visitors");
        				printf("\nInput choice: ");
        				scanf("%d", &inp);
        				
					fgetc(stdin);
        				if(inp == 1){
            					p1.name = (char *)malloc(s);
            					printf("\nPlease input patient name: ");
            					gets(p1.name);

            					printf("\nPlease input patient phone number: ");
           					gets(p1.phone_no);
            					display_single_visitor(p1.name,p1.phone_no);
            					free(p1.name);
        				}
        				else if(inp == 2){
            					c = count_visitor("../src/visitor_info.csv");
            					printf("\nTotal number of visitors = %d",c-1);
        				}
        				break;
    				
				case 8:
        				p1.name = (char *)malloc(s);
        				printf("\nPlease input patient name: ");
        				gets(p1.name);
        				
					printf("\nPlease input patient phone number: ");
        				gets(p1.phone_no);
        				display_test(p1.name,p1.phone_no);
        				free(p1.name);
        				break;
    				
				default:
        				printf("Invalid choice");
        				break;
    			}
    			return 0;
		}
	}
}
