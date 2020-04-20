/**
 * @file rooms.c
 *
 * @brief A collection of functions related to the checking availability of rooms for admitted patients.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

#include "../include/rooms.h"
#include<stdio.h>
#include<stdlib.h>
#include "../include/id_generate.h"

/**
 * @brief A function to read the file "general_rooms.csv" and retun availability in general ward.
 * 
 * @details room capacity is only for 10 patients. Checks if space is available in "general_rooms.csv".
 * If available, returns flag value as signal to disease function. Disease function process this signal and stores
 * patient details in "general_rooms.csv" file. If it returns a flag for no availability, then appropriate message is displayed.
 * 
 * @return Returns 0 if no availability else returns 1, if room is available.
 */


int general_rooms(){

	int id=id_generate("../src/general_rooms.csv");
    	FILE *fptr;
    	fptr = fopen("../src/general_rooms.csv", "r");
   
	if(fptr == NULL){
        	printf("Error!");
        	exit(1);
    	}
    
	if(id > 10){
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

/**
 * @brief A function to read the file "special_rooms.csv" and return availability in special ward.
 * 
 * @details room capacity is only for 10 patients. Checks if space is available in "special_rooms.csv".
 * If available, returns flag value as signal to disease function. Disease function process this signal and stores
 * patient details in "special_rooms.csv" file. If it returns a flag for no availability, then appropriate message is displayed.
 * 
 * @return Returns 0 if no availability else returns 1 if room is available.
 */

int special_rooms(){
	
	int id=id_generate("../src/special_rooms.csv");
    	FILE *fptr;
    	fptr = fopen("../src/special_rooms.csv", "r");
    
	if (fptr == NULL){
        	printf("Error!");
        	exit(1);
    	}
    
	if(id > 10){
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
