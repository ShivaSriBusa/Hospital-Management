/*
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

/*
 * @brief Here prescription, precaution and diet advice related to a patient will be displayed.
 * The patient will be searched by patient name and phone number from the patient_advice.csv file. 
 * Then the corresponding information will be displayed from this file.
 */

int advice(char *pname,char *ph){
    // Integer variable of size 100 for size of memory allocated to pointer variable
    int SIZE=100,id;

    // File pointer is created to work with files.
    FILE *fptr;

    //Integer variable id calls the id_generate function to generate row number.
    id = id_generate("patient_advice.csv");

    // Structure variables allocated memory.
    a1.diet_advise = (char *)malloc(SIZE);
    a1.precaution = (char *)malloc(SIZE);
    a1.prescription = (char *)malloc(SIZE);
       
    // Opening file in append mode.
    fptr = fopen("patient_advice.csv", "a");

    //Exiting program if file is not found.
    if (fptr == NULL){
        printf("Error!");
        exit(1);
    }
    else{
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
