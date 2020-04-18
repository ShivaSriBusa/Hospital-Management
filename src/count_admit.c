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
*	@details The function reads the "general_rooms.csv" and “special_rooms.csv” file and counts
*	the total number of patients admitted in the hospital.
*   
*   @param[in] Function has no input parameters.
*
*	@return Function returns total number of patients (positive integer) as count on successful execution
*	and returns -1 if the file cannot be opened.
*/

int count_admit()   {
    char buff[1024];
    int i = 0, j = 0,count=0;;
    FILE *fptr1, *fptr2;
    fptr1 = fopen("../src/general_rooms.csv", "r");
    fptr2 = fopen("../src/special_rooms.csv", "r");
    if (fptr1 == NULL)  {
        printf("\n file opening failed ");
        return -1;
    }
    if (fptr2 == NULL)  {
        printf("\n file opening failed ");
        return -1;
    }
    do  {
	    fgets(buff, 1024, (FILE*)fptr1);
	    i++;
	}while((getc(fptr1))!=EOF);
    do  {
	    fgets(buff, 1024, (FILE*)fptr2);
	    j++;
	}while((getc(fptr2))!=EOF);
    fclose(fptr2);
    fclose(fptr1);
    count=i+j;
    return count;
}
