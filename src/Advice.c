/**
 * @file advice.c
 *
 * @brief Implementation of advice details to file.
 *
 * @author Shiva Sri Busa - Shivasribusa@cmail.carleton.ca
 * 
 */




#include "include/Advice.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * @briefHere prescription, precaution and diet advice related to a patient will be displayed. The patient will be searched by his name and number from the �patient_advice.csv� file. 
 * Then the corresponding information will be displayed from this file.
 */

int Advice(char *pname,char *ph)
{

// Integer variable of size 100 for size of memory allocated to pointer variable
    int s=100,id;

    // file pointer is created to work with files.
    FILE *fptr;

    id=id_generate("patient_advice.csv");

    // Structure variables allocated memory.

    a1.diet_advise = (char *)malloc(s);
    a1.precaution = (char *)malloc(s);
    a1.prescription =(char *)malloc(s);
       
    // opening file in append mode.
    fptr = fopen("patient_advice.csv", "a");

    // exiting program if file is not found.
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        printf("\nDiet advise for Patient %s\n",pname);
        printf("\nPlease input precaution: ");
        gets(a1.precaution);
        printf("Please input prescription: ");
        gets(a1.prescription);
        printf("Please input diet advice: ");
        gets(a1.diet_advise);
        fprintf(fptr,"%d,%s,%s,%s,%s,%s\n",id,pname,ph,a1.precaution,a1.prescription,a1.diet_advise);
        

     // Closing file read is a good practice.
        fclose(fptr);

     //Freeing the allocated memory to pointer. It is must to free memory after use.
        free(a1.diet_advise);
        free(a1.precaution);
        free(a1.prescription);
    }
    return 0;
}
