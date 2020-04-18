/**
 * @file add_visitor.c
 *
 * @brief Implementation of adding the visitor details to the corresponding file.
 *
 * @author Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca
 * 
 */

#include "../include/add_visitor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/id_generate.h"

/** @details Here the user will be able to input the necessary information i.e. the patient id of the patient and the all the relevant details of the visitor. 
* Following are the information that will be collected:
* • Patient id.
* • Visitor Name.
* • Visitor Address.
* • Visitor Phone number.
*
* After taking the patient id as input, it will check if the patient is admitted in the hospital at that particular moment.
* If with the patient id a match is found in the "general_rooms.csv" and "special_rooms.csv". Then the visitor details will be taken as an input and stored in the "visitor_info.csv" file.
* 
*
* @param[in] Function has three input parameters.
*
* @return Function returns -1 if the file "visitor_info.csv" is not found. Stores information and returns 0 on successful execution.
*/

int add_visitor(char *filename,char *str,char*ph)   {
    int id,field_count=0,row_count=0,t_ph,u_ph;
	char string[1024];
	char *token,*field;
	FILE *fptr1,*fptr2;
	v1.name=(char *)malloc(100);
	v1.address=(char *)malloc(100);
	fptr1=fopen(filename,"r");
	fptr2=fopen("../src/visitor_info.csv","a");
	id=id_generate("../src/visitor_info.csv");
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
        if(strcmp(token,str)==0)    {
            token = strtok(NULL, ",");
            t_ph=atoi(token);
            u_ph=atoi(ph);
        if(t_ph==u_ph)  {
            while (field)   {
                if(field_count==0)  {
                    fprintf(fptr2,"%d,",id);
                    field_count++;
                }
                if(field_count==1)  {
                    fprintf(fptr2,"%s,",str);
                    field_count++;
                }
                if(field_count==2)  {
                    fprintf(fptr2,"%s,",ph);
                    field_count++;
                }
                if(field_count==3)  {
                    printf("\nPlease input visitor name: ");
                    gets(v1.name);
                    fprintf(fptr2,"%s,",v1.name);
                    field_count++;
                }
                if(field_count==4)  {
                    printf("\nPlease input visitor address: ");
                    gets(v1.address);
                    fprintf(fptr2,"%s,",v1.address);
                    field_count++;
                }
                if(field_count==5)  {
                    printf("\nPlease input visitor phone number: ");
                    gets(v1.phoneNo);
                    fprintf(fptr2,"%s\n",v1.phoneNo);
                    field_count++;
                }
                if(field_count==6)  {
                    break;
                }
        field = strtok(NULL, ",");
        field_count++;
        }
    }
        else   {
            printf("\nPhone number did not match!");
        }
    }
        else    {
            printf("\nNo record found!");
        }
    }
    free(v1.name);
    free(v1.address);
    return 0;
}

