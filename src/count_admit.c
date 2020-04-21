/**
 * @file count_admit.c
 *
 * @brief Implementation of counting the number of patients admitted in the hospital.
 *
 * @author Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/count_admit.h"

/**
 *
 * @details The function reads the "general_rooms.csv" and “special_rooms.csv” file and counts
 * the total number of patients admitted in the hospital.
 *
 * 
 * @param[in] Function has no input parameters.
 *
 * @return Function returns total number of patients (positive integer) as count on successful execution
 * and returns -1 if the file cannot be opened.
 */

int count_admit(char *f1name, char *f2name){
    char buff[1024];
    FILE *f1,*f2;

    /* Opening general ward and special ward files to check admitted patients */

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

    /* Reading file line by line and increasing count for each line */

    do{
	 fgets(buff, 1024, (FILE*)f1);
	 i++;
	}while((getc(f1))!=EOF);
    do{
	 fgets(buff, 1024, (FILE*)f2);
	 j++;
	}while((getc(f2))!=EOF);

    /* Closing file is a good practice */

    fclose(f2);
    fclose(f1);
    count=i+j;

    /* If file is empty */
    
    if(count==2){
		return 0;
	}
    return count;
}
