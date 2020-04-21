/**
 * @file test.c
 *
 * @brief Implementation of automated unit tests.
 *
 * @author sreeram sankarasubram - sreeramsankarasubram@cmail.carleton.ca
 * @author Kazi Muhammad Jameel - KaziMuhammadJameel@cmail.carleton.ca
 * @author Shiva Sri Busa - ShivaSriBusa@cmail.carleton.ca
 * @author Soummyo Priyo Chattopadhyay - SoummyoPriyoChattopa@cmail.carleton.ca
 */

#include "include/test.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define memory_size 50

int test_id_generate(char *fname){
	int count = 0;
    	char buff[1024];
   	FILE *fp = fopen(fname,"r");

	if (!fp){
        	printf("Can't open file\n");
        	return -1;
    	}

	while(fgets(buff,1024, fp) != NULL){
	        count++;
	}

	fclose(fp);
    	return count; /* returns 0 if file is empty */
}

int test_general_rooms(){
	int id = test_id_generate("../test/test_general_rooms.csv");
    	FILE *fptr;

	fptr = fopen("../test/test_general_rooms.csv", "r");
    	if (fptr == NULL){
        	printf("Error!");
        	exit(1);
	}

	if (id > 10){
        	printf("No Rooms available in general ward");
        	fclose(fptr);
        	return 0;
    	}
    	else{
        	printf("Patient can be Admitted in general ward");
        	fclose(fptr);
        	return 1;
    	}
}

int test_special_rooms(){
	int id=test_id_generate("../test/test_special_rooms.csv");
    	FILE *fptr;

	fptr = fopen("../test/test_special_rooms.csv", "r");
    	if (fptr == NULL){
        	printf("Error!");
        	exit(1);
    	}

	if (id > 10){
        	printf("No Rooms available in special ward");
        	fclose(fptr);
        	return 0;
    	}
    	else{
	        printf("Patient can be Admitted in special ward");
        	fclose(fptr);
        	return 1;
    	}
}

int test_disease(char *symptom, char *patient_name,char*ph){
	int ret, flag = 1;
    	FILE *fptr;
    	char *token;
    	int opt;
    	token = strtok(symptom, ";");

	while (token != NULL){
	        printf("\nPatients symptoms: %s",token);
        	flag++;
        	token = strtok(NULL, ";");
    	}

	printf("\n\nPlease input one of the following options:");
    	printf("\n1. Chronic symptoms");
    	printf("\n2. Physical injury symptoms");
    	printf("\n3. Neither chronic nor physical injury");
    	printf("\nInput choice: ");
    	scanf("%d",&opt);

	if (opt == 1){
	        ret = test_special_rooms();
        	if (ret != 0){
		        fptr = fopen("../test/special_rooms.csv", "a");
            		ret = test_id_generate("../test/special_rooms.csv");
            		fprintf(fptr,"%d,%s,%s,",ret,patient_name,ph);
            		fprintf(fptr,"%s","\n");
            		fclose(fptr);
        	}
    	}
    	else if (opt == 2){
        	ret = test_general_rooms();
        	if (ret != 0){
            		fptr = fopen("../test/general_rooms.csv", "a");
            		ret = test_id_generate("../test/general_rooms.csv");
            		fprintf(fptr,"%d,%s,%s,",ret,patient_name,ph);
            		fprintf(fptr,"%s","\n");
            		fclose(fptr);
        	}
    	}
    	else if(opt == 3){
	        printf("No admission Required");
    	}
    	return 0;
}

void test_add_patient(){
	int id;
    	t_p1.address = (char *)malloc(memory_size);
    	t_p1.symp = (char *)malloc(memory_size);
   	t_p1.doc_name = (char *)malloc(memory_size);
    	t_p1.name = (char *)malloc(memory_size);
    	t_p1.medication = (char *)malloc(memory_size);
    	t_p1.allergies = (char *)malloc(memory_size);
    	id = test_id_generate("../test/test_patient_record_3.csv");

	// creating file pointer to work with files
    	FILE *fptr;

	// opening file in writing mode
    	fptr = fopen("../test/test_patient_record_3.csv", "a");

	// exiting program
	if (fptr == NULL){
	        printf("Error!");
        	exit(1);
    	}
    	else{
        	printf("Please input patient name:");
        	gets(t_p1.name);

		printf("Please input patient address:");
        	gets(t_p1.address);

		printf("Please input patient contact number:");
        	gets(t_p1.phone_no);

		printf("Please input patient emergency contact number:");
        	gets(t_p1.emergency_no);

		printf("Please input patient date of admission (DD-MM-YYYY):");
        	gets(t_p1.date_adm);

		printf("Please input patient time of admission (HH:MM) :");
        	gets(t_p1.time_adm);

		printf("Please input patient symptoms:");
        	gets(t_p1.symp);

		printf("Please input doctors attending :");
        	gets(t_p1.doc_name);

		printf("Please input Patient identity number :");
        	gets(t_p1.patient_identity);

		printf("Please input patient medications:");
        	gets(t_p1.medication);

		printf("Please input patient allergies:");
        	gets(t_p1.allergies);

		fprintf(fptr,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",id,t_p1.name,t_p1.phone_no,t_p1.address,t_p1.emergency_no,t_p1.date_adm,t_p1.time_adm,t_p1.symp,t_p1.doc_name,t_p1.patient_identity,t_p1.medication,t_p1.allergies,"No");
        	test_disease(t_p1.symp,t_p1.name,t_p1.phone_no);
        	free(t_p1.address);
        	free(t_p1.allergies);
        	free(t_p1.name);
        	free(t_p1.doc_name);
        	free(t_p1.medication);
		free(t_p1.symp);
	}
	fclose(fptr);
}

int test_count_visitor(char *fname){
	char buff[1024];
   	int count = 0;
    	FILE *fptr;

	fptr = fopen(fname, "r");
    	if (fptr == NULL){
        	printf("\n file opening failed ");
        	return -1;
    	}

	do{
		fgets(buff, 1024, (FILE*)fptr);
	 	count++;
	}
	while((getc(fptr))!=EOF);
    	fclose(fptr);
    	return count;
}

int test_display_single_patient(char *name, char* ph){
	FILE *fp = fopen("../test/test_patient_record.csv","r");
	char string[1024];
    	int row_count = 0;
    	int field_count = 0,t_ph,n=0,u_ph,m=0;
    	char *field,*token;

	if (!fp){
	        printf("Can't open file\n");
        	return -1;
    	}

	while (fgets(string, 1024, fp)){
    		field_count = 0;
    		row_count++;
    		if (row_count == 1){
        		continue;
    		}

		field = strtok(string, ",");
    		token = field;
    		token = strtok(NULL, ",");

		if(strcmp(token,name) == 0){
        		n++;
        		token = strtok(NULL, ",");
        		t_ph = atoi(token);
        		u_ph = atoi(ph);
        		if(t_ph == u_ph){
				m++;
            			while(field){

					if(field_count == 0){
			                	printf("Id:");
                    			    	printf("%s\n",field);
                    				field = strtok(NULL, ",");
                     				field_count++;
                    			}

					if(field_count == 1){
				                printf("Name:");
                    				printf("%s\n",name);
                    				field_count++;
                    			}

					if(field_count == 2){
				                printf("Phone:");
                    				printf("%s\n",token);
                    				field_count++;
                    			}

					if(field_count == 3){
		    		                printf("Address:");
                    				printf("%s\n",field);
                    				field = strtok(NULL, ",");
                    				field_count++;
                    			}

                			if(field_count == 4){
                    				printf("Emergency phone:");
                    				printf("%s\n",field);
                    				field = strtok(NULL, ",");
                    				field_count++;
                   			}

			                if(field_count == 5){
				                printf("Date of Admission:");
                    				printf("%s\n",field);
                    				field = strtok(NULL, ",");
                    				field_count++;
                    			}

					if(field_count == 6){
                    				printf("Time of Admission:");
                    				printf("%s\n",field);
                    				field = strtok(NULL, ",");
                    				field_count++;
                    			}

                			if(field_count == 7){
                    				printf("Symptoms:");
                    				printf("%s\n",field);
                    				field = strtok(NULL, ",");
                    				field_count++;
                    			}

                			if(field_count == 8){
                    				printf("Doctors name:");
                    				printf("%s\n",field);
                    				field = strtok(NULL, ",");
                    				field_count++;
                    			}

					if (field_count == 9){
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
            			}
				printf("\n");
        		}

        	}

    	}

    	if(n == 0){
		printf("\nNo record found!");
	        fclose(fp);
	        return -1;
        }

    	if(m == 0 && n!= 0)    {
	        printf("\nPhone number did not match!");
	        fclose(fp);
	        return -1;
	}
    	fclose(fp);
    	return 0;
}

int test_Advice(char *pname,char *ph){
    	int s=100,id;
    	FILE *fptr;

	id=test_id_generate("../test/test_patient_advice.csv");
    	t_a1.diet_advise = (char *)malloc(s);
    	t_a1.precaution = (char *)malloc(s);
    	t_a1.prescription =(char *)malloc(s);
    	fptr = fopen("../test/test_patient_advice.csv", "a");

	if (fptr == NULL){
        	printf("Error!");
        	exit(1);
    	}
    	else{
        	printf("\nDiet advise for Patient %s\n",pname);
        	printf("\nPlease input precaution: ");
       	 	gets(t_a1.precaution);
        	printf("Please input prescription: ");
        	gets(t_a1.prescription);
        	printf("Please input diet advice: ");
        	gets(t_a1.diet_advise);
        	fprintf(fptr,"%d,%s,%s,%s,%s,%s\n",id,pname,ph,t_a1.precaution,t_a1.prescription,t_a1.diet_advise);
        	fclose(fptr);
        	free(t_a1.diet_advise);
        	free(t_a1.precaution);
        	free(t_a1.prescription);
    	}
    	return 0;
}

int test_search_in_file(char *fname, char *str, char*ph) {
	int id,field_count=0,row_count=0,flag,t_ph,u_ph;
	char inp,string[1024];
	char *token,*field;
	FILE *fp,*fstream,*fptr2,*fptr1;

	fstream = fopen("../test/test_discharged_list.csv", "a");
    	printf("\n");

	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}

	flag=test_display_single_patient(str,ph);
    	if(flag==-1){
       		return 0;
		}
    	else{
    		printf("\nIs the patient discharged? (Y/N) :");
    		scanf("%c",&inp);
    		fgetc(stdin);
		}
	if(inp == 'Y'){
    		return 0;
	}
    else{
		printf("\nDo you want to discharge now? (Y/N) :");
    	scanf("%c",&inp);
    	fgetc(stdin);
	}
	if(inp=='N'){
    		test_Advice(str,ph);
	}
    	else{
        	id = test_id_generate("../test/test_discharged_list.csv");
        	printf("\nPlease input date of release (DD-MM-YYYY) : ");
        	gets(t_p1.date_release);
        	printf("\nPlease input time of release (HH:MM): ");
        	gets(t_p1.time_release);
        	fprintf(fstream,"%d,%s,%s,%s,%s\n",id,str,ph,t_p1.date_release,t_p1.time_release);
        	fclose(fstream);
        	fptr1 = fopen("../test/test_patient_record.csv","r");

		if (!fptr1){
            		printf("Unable to open the input file!!\n");
            		return -1;
        	}
        	fptr2 = fopen("../test/test_temp.csv","w");

        	// copy all contents to the temporary file other except specific line

        	fprintf(fptr2,"ID,Name,Phone Number,Address,Emergency Phone Number,Date of admission (DD-MM-YYYY),");
        	fprintf(fptr2,"Time of admission (HH:MM),Symptoms,Doctors name,Identity Number,Medications,Allergies,Discharge status\n");

		while (fgets(string, 1024, fptr1)){
        	field_count = 0;
            row_count++;
            if (row_count == 1){
            	continue;
            }
            field = strtok(string, ",");
            token = field;
            token = strtok(NULL, ",");
			if(strcmp(token,str) == 0){
            	token = strtok(NULL, ",");
                t_ph = atoi(token);
                u_ph = atoi(ph);
                if(t_ph == u_ph){
           			id = test_id_generate("../test/test_temp.csv");
              		fprintf(fptr2,"%d,",row_count-1);
					while (field){
                   		if(field_count==0){
                  			fprintf(fptr2,"%s,",str);
                   			field = strtok(NULL, ",");
                   			field_count++;
                    	}

						if(field_count == 11){
                   			field=(char *)malloc(100);
                       		fprintf(fptr2,"Yes");
                       		free(field);
                       		field_count++;
                   		}

						if(field_count == 1){
                   			fprintf(fptr2,"%s,",token);
                   			field_count++;
                   		}

						if(field_count != 1){
                      		fprintf(fptr2,"%s,",field);
                       		field = strtok(NULL, ",");
                   			field_count++;
                   		}
                	}
                }
            }
            else{
       			fprintf(fptr2,"\n");
           		while(field){
           			if(field_count == 1){
           			fprintf(fptr2,"%s,",token);
          			field_count++;
           		}

				if(field_count!=1){
					fprintf(fptr2,"%s,",field);
					field = strtok(NULL, ",");
					field_count++;
				}

				if(field_count==12){
					fprintf(fptr2,"%s",field);
					field = strtok(NULL, ",");
					field_count=0;
				}
           }
   		}
	}
	fclose(fptr1);
	fclose(fptr2);
    remove("../test/test_patient_record.csv");
    rename("../test/test_temp.csv","../test/test_patient_record.csv");
}
    return 0;
}

int test_add_visitor(char *filename,char *str,char *ph){
    	int id,field_count = 0,row_count = 0,t_ph,n = 0,m = 0,u_ph;
	char string[1024];
	char *token,*field;
	FILE *fptr1,*fptr2;

	t_v1.name = (char *)malloc(100);
	t_v1.address = (char *)malloc(100);
	fptr1 = fopen(filename,"r");
	fptr2 = fopen("../test/test_visitor_info.csv","a");
	id = test_id_generate("../test/test_visitor_info.csv");

	if (fptr1 == NULL)  {
        	printf("\n file opening failed ");
        	return -1;
    	}

	while (fgets(string, 1024, fptr1))  {
        	field_count = 0;
        	row_count++;
        	if (row_count == 1) {
            		continue;
        	}

		field = strtok(string, ",");
        	token=field;
       	 	token = strtok(NULL, ",");

		if(strcmp(token,str) == 0){
			n++;
            		token = strtok(NULL, ",");
            		t_ph = atoi(token);
            		u_ph = atoi(ph);

        		if(t_ph == u_ph){
				printf("\nRecord found in %s",filename);
				m++;
				while (field){
					if(field_count == 0){
						fprintf(fptr2,"%d,",id);
						field_count++;
					}

					if(field_count == 1)  {
						fprintf(fptr2,"%s,",str);
						field_count++;
					}

					if(field_count == 2)  {
						fprintf(fptr2,"%s,",ph);
						field_count++;
					}

					if(field_count == 3)  {
						printf("\nPlease input visitor name: ");
						gets(t_v1.name);
						fprintf(fptr2,"%s,",t_v1.name);
						field_count++;
					}

					if(field_count == 4)  {
						printf("\nPlease input visitor address: ");
						gets(t_v1.address);
						fprintf(fptr2,"%s,",t_v1.address);
						field_count++;
					}
					if(field_count == 5)  {
						printf("\nPlease input visitor phone number: ");
						gets(t_v1.phone_no);
						fprintf(fptr2,"%s\n",t_v1.phone_no);
						field_count++;
					}
					field = strtok(NULL, ",");
					field_count++;
				}
    			}
		}
    	}
    	if(m == 0 && n != 0){
		printf("\nPhone number did not match in %s!",filename);
		fclose(fptr1);
		fclose(fptr2);
		return -1;
    	}

	if(n == 0){
		printf("\nNo record found %s!",filename);
		fclose(fptr1);
		fclose(fptr2);
		return -1;
    	}
    	free(t_v1.name);
    	free(t_v1.address);
    	return 0;
}

int test_visitor_info(char *name,char *ph){
    	test_add_visitor("../test/test_general_rooms.csv",name,ph);
    	test_add_visitor("../test/test_special_rooms.csv",name,ph);
    	return 0;
}

int test_count_admit(char *f1name, char *f2name){
    	char buff[1024];
    	FILE *f1,*f2;
    	f1 = fopen(f1name,"r");
    	f2 = fopen(f2name, "r");
    	int i = 0, j = 0,count=0;;
    	if (f1 == NULL){
        	printf("\n file opening failed ");
        	return -1;
    	}

	if (f2 == NULL){
        	printf("\n file opening failed ");
        	return -1;
    	}

	do{
		fgets(buff, 1024, (FILE*)f1);
		i++;
	}
	while((getc(f1))!=EOF);

	do{
		fgets(buff, 1024, (FILE*)f2);
		j++;
	}
	while((getc(f2))!=EOF);

	fclose(f2);
    	fclose(f1);
    	count = i+j;
    	/* If file is empty */

	if(count == 2){
		return 0;
	}
    	return count;
}

int test_display_single_visitor(char *name, char *ph){
    	FILE *fp = fopen("../test/test_visitor_info.csv","r");
	char string[1024];
	char *token,*field;
    	int row_count = 0, field_count = 0, u_ph, t_ph,n = 0,m = 0;

	if (!fp) {
       		printf("Can't open file\n");
        	return -1;
    	}
    	while (fgets(string, 1024, fp)){
        	field_count = 0;
            	row_count++;

		if (row_count == 1){
                	continue;
            	}

		field = strtok(string, ",");
            	token = strtok(NULL, ",");

		if(strcmp(token,name) == 0){
			n++;
                	token = strtok(NULL,",");
                	t_ph = atoi(token);
                	u_ph = atoi(ph);

			if(t_ph == u_ph){
				m++;

				while(field){
                        		if(field_count == 0){
                        			printf("\nID:");
                        			//field_count++;
                        		}

                        		if(field_count == 1){
                        			printf("Patient name:");
                        			printf("%s\n",name);
                        			field_count++;
                        		}

					if(field_count == 2){
                        			printf("Patient phone number: %s\n",token);
                        			field_count++;
                        		}

                        		if(field_count == 3){
                        			printf("Visitor name:");
                        		}

                        		if(field_count == 4){
                        			printf("Visitor address:");
                        		}

                        		if(field_count == 5){
                        			printf("Visitor phone number:");
                        		}
                        		printf("%s\n",field);
                        		field = strtok(NULL, ",");
                        		field_count++;
                    		}
                	}

            	}

        }

        if(n == 0){
		printf("\nNo record found!");
        }

        if(m == 0 && n != 0){
		printf("\nPhone number did not match!");
        }
    	fclose(fp);
    	return 0;
}

int test_display_advice(char *name,int ph){
	//Open a .csv file in read mode
	FILE *fp = fopen("../test/test_patient_advice.csv", "r");

	char str[15];
	int n = 0,len,u_ph,m = 0;
	len=sprintf(str,"%d",ph);

	if(strlen(name) >= 50){
        	printf("\nName should not be more than 50 characters");
		return -1;
        }

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
                         			if(field_count == 0){
			     				printf("Id:\t");
			     				printf("%s\n",field);
			     				field = strtok(NULL, ",");
			     				field_count++;
                         			}

		                        	//Display matched/entered patient name
           		 			if(field_count == 1){
			     				printf("Name:\t");
			     				printf("%s\n",name);
			     				field_count++;
	                         		}

     		         			//Display matched/entered patient phone number
                         			if(field_count == 2){
			     				printf("Phone:\t");
			     				printf("%s\n",token);
			     				field_count++;
	                       			}

    		         			//Display patient precaution information
	                         		if(field_count == 3){
				     			printf("Precaution:\t");
				     			printf("%s\n",field);
				     			field = strtok(NULL, ",");
				     			field_count++;
	                         		}

                     		    		//Display patient prescription details
                         			if(field_count == 4){
				     			printf("Prescription:\t");
				     			printf("%s\n",field);
				     			field = strtok(NULL, ",");
				     			field_count++;
	                         		}

				        	//Display patient diet advice details
                		        	if(field_count == 5){
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
   	if(len != 10){
<<<<<<< HEAD
		printf("\nPhone number should be 10 digits \n");
=======
		printf("\nPhone number should be 10 digits");
>>>>>>> master
	        fclose(fp);
	        return -1;
	}
	if(n != 0 && len == 10 ){
<<<<<<< HEAD
		printf("\nNo record found! \n");
=======
		printf("\nNo record found!");
>>>>>>> master
	       	return -1;
	}
	if(n == 0){
	       	//Displaying message if no records found as per entered input values
<<<<<<< HEAD
	       	printf("\nNo record found! \n");
=======
	       	printf("\nNo record found!");
>>>>>>> master
	       	fclose(fp);
	       	return -1;
   	}

    	//Closing the file read is a good practice.
    	fclose(fp);
    	return 0;
}


int test_display_test(char *name, char  *ph){
    	int id,field_count = 0,row_count = 0,t_ph,ch,u_ph;
	char string[1024],inp[10];
	FILE *fptr1,*fptr2;
	int n = 0,m = 0;

	fptr1 = fopen("../test/test_patient_record.csv","r");
	fptr2 = fopen("../test/test_test_details.csv","a");

	id = test_id_generate("../test_/test_test_details.csv");

	if(fptr1 == NULL){
        	printf("\n file opening failed ");
        	return -1;
    	}

	while (fgets(string, 1024, fptr1)){
        	field_count = 0;
            	row_count++;

		if(row_count == 1){
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

	if(n == 0){
		printf("\nNo record found!");
	}
	if(m == 0 && n != 0){
		printf("\nPhone number did not match!");
	}

        fclose(fptr1);
        fclose(fptr2);
	return 0;
}


void test_welcome_message(){
	printf("\n\n\n\n\n");
    	printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    	printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    	printf("\n\t\t\t        =                 WELCOME                   =");
    	printf("\n\t\t\t        =                   TO                      =");
    	printf("\n\t\t\t        =                HOSPITAL                   =");
    	printf("\n\t\t\t        =               MANAGEMENT                  =");
    	printf("\n\t\t\t        =                 SYSTEM                    =");
    	printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    	printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    	printf("\n\n\n\t\t\t ");
    	system("read -p 'Press Enter to continue...' var");
}


int all_test_case(){
    	int count,inp,count_1;
    	char *fptr1, *fptr2;
    	FILE *test_result = fopen("../test/results/results.csv", "a");

	printf("\n1. Test row id generation function.\n");
    	printf("\n2. Test adding patient record function.\n");
    	/* Test function 2 cannot be split because it contains nested function and parameters are passed within a function */
    	printf("\n3. Test availability of rooms function.\n");
    	printf("\n4. Test count of admitted patient's visitor function.\n");
    	printf("\n5. Test search of patient's visitor function.\n");
    	printf("\n6. Test updating patient's record function.\n");
    	printf("\n7. Test add visitor information function.\n");
    	printf("\n8. Test count of admitted patients function.\n");
    	printf("\n9. Test search of patients from patient's record function.\n");
    	printf("\n10. Test display advice of patient function.\n");
    	printf("\n11. Test write patient advice function.\n");
    	printf("\n12. Test write patient's test details function.\n");
    	printf("\n13. Test welcome message function.\n");
    	printf("\nInput your choice of test: ");
    	scanf("%d",&inp);

	switch(inp){
        	case 1:
                	printf("\nTesting row id generation function.\n");

			/* Test case 1 - Input file not present in path */
			count = test_id_generate("../test/disease.csv"); //Passing a file which is not present in the path

                	if(count == -1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Invalid file, Expected Output: -1, Output: %d .\n",count);
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"1)FAIL: Input: Invalid file, Expected Output: -1, Output: %d .\n",count);
                    		printf(t);
                    		fprintf(test_result,t);
                	}

                	/* Test case 2 - Empty Input file */
                	count = test_id_generate("../test/test_patient_record_2.csv"); // file is empty - no header

                	if(count == 0){
                    		char t[100];
                    		sprintf(t,"2)PASS: Input: Empty file, Expected Output: 0, Output: %d .\n",count);
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Empty file, Expected Output: 0, Output: %d .\n",count);
                    		printf(t);
                    		fprintf(test_result,t);
                	}

               		/* Test case 3 - Valid file */
                	count = test_id_generate("../test/test_patient_record_1.csv"); // File has 3 rows including header

                	if(count > -1){
                    		char t[100];
                    		sprintf(t,"3)PASS: Input: valid file, Expected Output: 2, Output: %d .\n",count-1);
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"3)FAIL: Input: Empty file, Expected Output: 2, Output: %d .\n",count);
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	fclose(test_result);
                	break;

        	case 2:
                	printf("\nTesting adding patient record function\n");

                	/* general Test case - check if function add_patient works to add patient record */
                	int bf_test_id = test_id_generate("../test/test_patient_record_3.csv");
                	fgetc(stdin);
                	test_add_patient();
                	int af_test_id = test_id_generate("../test/test_patient_record_3.csv");

			if(af_test_id > bf_test_id){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: valid File, Expected Output: %d, Output: %d .\n",bf_test_id+1, af_test_id);
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",bf_test_id+1, af_test_id);
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 3:
                	printf("\n\nTesting Count of available rooms in general/special ward function.");

                	/* general Test case  - check for availability of rooms */
                	printf("\n");
                	count = test_general_rooms(); //No records currently in general rooms.
                	printf("\n");
                	count_1 = test_special_rooms(); // 1 record in special rooms
                	printf("\n");

			if(count == 1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",0,count-1);
                    		/* Expected output is 0 as there is only header of the file and no patient admitted.
                       		count is decremented by 1 to exclude the header */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
               		else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Expected output will be 0 for no availability */
                    		printf(t);
                    		fprintf(test_result,t);
                	}

                	if(count_1 == 1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",1,count);
                    		/* Expected output is 1 because only 1 patient admitted.
                       		count is decremented by 1 to exclude the header */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Expected output will be 0 for no availability */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 4:
                	/* Testing count of admitted patient's visitor */
                	/* Test case 1  - check for total count of visitors if file exists */

               		count = test_count_visitor("../test/test_visitor_info.csv");

			if(count != -1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",2,count-1);
                    		/* Expected output is 2 as there are 2 visitors.
                       		count is decremented by 1 to exclude the header */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",2,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                 	/* Test case 2  - check for invalid file */
			count = test_count_visitor("../test/test_visitor_info_1.csv");

			if(count == -1){
				char t[100];
				sprintf(t,"1)PASS: Input: Invalid File wrong filename, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output is -1 as file does not exist. */
				printf(t);
				fprintf(test_result,t);
			}
			else{
				char t[100];
				sprintf(t,"2)FAIL: Input: Invalid file wrong filename, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output will be -1 if file is not available */
				printf(t);
				fprintf(test_result,t);
                	}
                	/* Test case 3  - check for valid file at wrong path */
			count = test_count_visitor("../src/test_visitor_info_1.csv");

			if(count == -1){
				char t[100];
				sprintf(t,"1)PASS: Input: Invalid File wrong path, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output is -1 as file does not exist. */
				printf(t);
				fprintf(test_result,t);
			}
			else{
				char t[100];
				sprintf(t,"2)FAIL: Input: Invalid file wrong path, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output will be -1 if file is not available */
				printf(t);
				fprintf(test_result,t);
                	}

			/* Test case 4  - check for invalid file but wrong extension */
 			count = test_count_visitor("../test/test_visitor_info.txt");

			if(count == -1){
				char t[100];
				sprintf(t,"1)PASS: Input: Invalid wrong extension File, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output is -1 as file does not exist. */
				printf(t);
				fprintf(test_result,t);
			}
			else{
				char t[100];
				sprintf(t,"2)FAIL: Input: Invalid wrong extension file, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output will be -1 if file is not available */
				printf(t);
				fprintf(test_result,t);
                	}
                	break;

	        case 5:
        	        /* Testing search of patient's visitor */
	                /* general Test case  - check for patient's visitor if the file exists */
	                t_p1.name = (char *)malloc(memory_size);
        	        printf("\nPlease input patient name: ");
                	fgetc(stdin);
                	gets(t_p1.name);
                	printf("\nPlease input patient phone number: ");
                	gets(t_p1.phone_no);
                	count = test_display_single_visitor(t_p1.name,t_p1.phone_no);
                	free(t_p1.name);

			if(count == 0){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Gives output 0 if function executes successfully */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",-1,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 6:
               		/* Testing update of patient's record */
                	/* general Test case  - check if update patient record works if the file exists */

			fgetc(stdin);
                	t_p1.name = (char *)malloc(memory_size);
               		printf("\nPlease input patient name: ");
                	gets(t_p1.name);
                	printf("\nPlease input patient phone number: ");
                	gets(t_p1.phone_no);
                	count = test_search_in_file("../test/test_patient_record_3.csv",t_p1.name,t_p1.phone_no);
                	free(t_p1.name);

			if(count == 0){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Gives output 0 if function executes successfully */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",-1,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 7:
               		/* Testing adding visitors record */
                	/* general Test case  - check if adding visitors record works if the file exists */
                	fgetc(stdin);
                	t_p1.name = (char *)malloc(memory_size);
               		printf("\nPlease input patient name: ");
                	gets(t_p1.name);
                	printf("\nPlease input patient phone number: ");
                	gets(t_p1.phone_no);
                	count = test_visitor_info(t_p1.name,t_p1.phone_no);
                	free(t_p1.name);

			if(count == 0){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Gives output 0 if function executes successfully */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
               		else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",-1,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 8:
    			/* Testing count of admitted patients */
<<<<<<< HEAD
               		/* Test case 1  - check for total count of admitted patients if file exists */
			fptr1 = "../test/test_general_rooms.csv";
    			fptr2 = "../test/test_special_rooms.csv";
               		count = test_count_admit(fptr1,fptr2);
			if(count != -1){
				char t[100];
               			sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",1,count-2);
               			/* Expected output is 1 as there is only 1 patient admitted.
               			count is decremented by 2 to exclude the header */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid File, Expected Output: %d, Output: %d .\n",1,count);
                    		/* Expected output is 1 as there is only 1 patient admitted. */
                   		printf(t);
                    		fprintf(test_result,t);
                	}

                	/* Test case 2  - check for Invalid file */

			fptr1 = "../test/general_rooms.csv";
			fptr2 = "../test/special_rooms.csv";
			count = test_count_admit(fptr1,fptr2);
			if(count == -1){
				char t[100];
				sprintf(t,"1)PASS: Input: Invalid File, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output is -1 for invalid file.*/
				printf(t);
				fprintf(test_result,t);
			}
	           	else{
				char t[100];
				sprintf(t,"2)FAIL: Input: Invalid File, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output will be -1 if file is not available */
				printf(t);
				fprintf(test_result,t);
                	}

               		/* Test case 3  - check for empty file */
			fptr1 = "../test/test_general_rooms_1.csv";
			fptr2 = "../test/test_special_rooms_1.csv";
			count = test_count_admit(fptr1,fptr2);
			if(count == 0){
				char t[100];
				sprintf(t,"1)PASS: Input: Empty File, Expected Output: %d, Output: %d .\n",0,count);
				/* Expected output is 0 for empty file.*/
				printf(t);
				fprintf(test_result,t);
			}
	            	else{
				char t[100];
			        sprintf(t,"2)FAIL: Input: Empty File, Expected Output: %d, Output: %d .\n",0,count);
   			        /* Expected output will be 0 if file is empty */
			        printf(t);
				fprintf(test_result,t);
               		}
               		break;
=======
               	/* Test case 1  - check for total count of admitted patients if file exists */
				fptr1 = "../test/test_general_rooms.csv";
    			fptr2 = "../test/test_special_rooms.csv";
               	count = test_count_admit(fptr1,fptr2);
				if(count != -1){
					char t[100];
               		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",1,count-2);
               		/* Expected output is 1 as there is only 1 patient admitted.
               		count is decremented by 2 to exclude the header */
                    printf(t);
                    fprintf(test_result,t);
                }
                else{
                	char t[100];
                    sprintf(t,"2)FAIL: Input: Valid File, Expected Output: %d, Output: %d .\n",1,count);
                    /* Expected output is 1 as there is only 1 patient admitted. */
                   	printf(t);
                    fprintf(test_result,t);
                }

                /* Test case 2  - check for Invalid file */

				fptr1 = "../test/general_rooms.csv";
				fptr2 = "../test/special_rooms.csv";
				count = test_count_admit(fptr1,fptr2);
				if(count == -1){
					char t[100];
					sprintf(t,"1)PASS: Input: Invalid File, Expected Output: %d, Output: %d .\n",-1,count);
					/* Expected output is -1 for invalid file.*/
					printf(t);
					fprintf(test_result,t);
				}
	            else{
					char t[100];
					sprintf(t,"2)FAIL: Input: Invalid File, Expected Output: %d, Output: %d .\n",-1,count);
					/* Expected output will be -1 if file is not available */
					printf(t);
					fprintf(test_result,t);
                }

               /* Test case 3  - check for empty file */

				fptr1 = "../test/test_general_rooms_1.csv";
				fptr2 = "../test/test_special_rooms_1.csv";
				count = test_count_admit(fptr1,fptr2);
				if(count == 0){
					char t[100];
					sprintf(t,"1)PASS: Input: Empty File, Expected Output: %d, Output: %d .\n",0,count);
					/* Expected output is 0 for empty file.*/
					printf(t);
					fprintf(test_result,t);
				}
	            else{
			   		char t[100];
			        sprintf(t,"2)FAIL: Input: Empty File, Expected Output: %d, Output: %d .\n",0,count);
   			        /* Expected output will be 0 if file is empty */
			        printf(t);
					fprintf(test_result,t);
               }
               break;
>>>>>>> master

        	case 9:
                	/* Testing search of patient from patient's record */
                	/* general Test case  - check for patient from record if file exists */

			fgetc(stdin);
                	t_p1.name = (char *)malloc(memory_size);
                	printf("\nPlease input patient name: ");
                	gets(t_p1.name);
                	printf("\nPlease input patient phone number: ");
                	gets(t_p1.phone_no);
                	count = test_display_single_patient(t_p1.name,t_p1.phone_no);
                	free(t_p1.name);

			if(count != -1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Expected output is 0 if function executes successfully. */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",-1,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 10:
        		/* Testing display advice of patient */
        		/* general Test case  - check for patient advice if file exists */
<<<<<<< HEAD
               		fgetc(stdin);
         	  	int number;
                	t_p1.name = (char *)malloc(memory_size);
                	printf("\nPlease input patient name: ");
               	 	gets(t_p1.name);
                	printf("\nPlease input patient phone number: ");
                	scanf("%d",&number);
         		count = test_display_advice("p1.name",number); // passing valid inputs
                	//free(t_p1.name);
=======
               	fgetc(stdin);
         	  	int number;
                t_p1.name = (char *)malloc(memory_size);
                printf("\nPlease input patient name: ");
                gets(t_p1.name);
                printf("\nPlease input patient phone number: ");
                scanf("%d",&number);
         		count = test_display_advice("p1.name",number); // passing valid inputs
                //free(t_p1.name);
>>>>>>> master
			if(count == -1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid Inputs, Expected Output: %d, Output: %d .\n",-1,count);
                    		/* Expected output is 0 if function executes successfully. */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid Inputs345, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}

                	//Test case 2: passing wrong name as input

                	count = test_display_advice("sreeram",3439874146); // passing wrong name as input

			if(count == -1){
				char t[100];
                    		sprintf(t,"1)PASS: Input: Invalid name, Expected Output: %d, Output: %d .\n",-1,count);
                   		/* Expected output is -1, if wrong name pass as input*/
                    		printf(t);
                    		fprintf(test_result,t);
	                }
               		else{
				char t[100];
                   		sprintf(t,"2)FAIL: Input: Invalid name, Expected Output: %d, Output: %d .\n",-1,count);
                   		/* Expected output will be -1 if file is not available */
                   		printf(t);
                   		fprintf(test_result,t);
                	}

                	//Test case 3: passing wrong number as input

                	count = test_display_advice("sreeram s",3439877876); // passing wrong number as input

			if(count == -1){
				char t[100];
				sprintf(t,"1)PASS: Input: Invalid number, Expected Output: %d, Output: %d .\n",-1,count);
				/* Expected output is 0 if function executes successfully. */
				printf(t);
				fprintf(test_result,t);
			}
			else{
 			    	char t[100];
 			    	sprintf(t,"2)FAIL: Input: Invalid number, Expected Output: %d, Output: %d .\n",-1,count);
	                	/* Expected output will be -1 if file is not available */
	               		printf(t);
	                	fprintf(test_result,t);
                	}
                	break;

        	case 11:
                	/* Testing writing patient advice */
                	/* general Test case  - write patient advice to patient advice file if file exists */
                	fgetc(stdin);
                	t_p1.name = (char *)malloc(memory_size);
                	printf("\nPlease input patient name: ");
                	gets(t_p1.name);
                	printf("\nPlease input patient phone number: ");
                	gets(t_p1.phone_no);
                	count = test_Advice(t_p1.name,t_p1.phone_no);
                	free(t_p1.name);

			if(count != -1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Expected output is 0 if function executes successfully. */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",-1,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 12:
                	/* Testing writing patient test details function */
                	/* general Test case  - write patient test details to test details file if file exists */
                	fgetc(stdin);
                	t_p1.name = (char *)malloc(memory_size);
                	printf("\nPlease input patient name: ");
                	gets(t_p1.name);
                	printf("\nPlease input patient phone number: ");
                	gets(t_p1.phone_no);
                	count = test_display_test(t_p1.name,t_p1.phone_no);
                	free(t_p1.name);

			if(count != -1){
                    		char t[100];
                    		sprintf(t,"1)PASS: Input: Valid File, Expected Output: %d, Output: %d .\n",0,count);
                    		/* Expected output is 0 if function executes successfully. */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	else{
                    		char t[100];
                    		sprintf(t,"2)FAIL: Input: Valid file, Expected Output: %d, Output: %d .\n",-1,count);
                    		/* Expected output will be -1 if file is not available */
                    		printf(t);
                    		fprintf(test_result,t);
                	}
                	break;

        	case 13:
                 	/* Testing welcome message function */
                 	fgetc(stdin);
                 	test_welcome_message(); // No test cases exist as it just prints pattern on screen
                 	break;
    	}
        return 1;
}
