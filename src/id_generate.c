/**
 * @file id_generate.c
 *
 * @brief A Function related to the allocation of rooms for admitted patients.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

#include "../include/id_generate.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief A function to generate new row number for file passed as an input.
 * 
 * @details This function reads the file passed as an input and counts number of rows in it,
 * it is then used to generate new row number for the file which we pass as input.
 * 
 * @param[in] It takes file name as input parameter.
 * 
 * @return Returns integer(new row number) on successful execution and -1 if file doesm't exist.
 */

int id_generate(char *file)
{
    // Act as FILE pointer. used for opening a file 
    FILE *fp = fopen(file,"r");
    // A flag used for counting number of rows existing in file
    int count=0;
    // Used for storing line read from file. 
    char buff[1024];
     if (!fp)
    {
	   printf("Can't open file\n");
	   return -1;
    }
    // Reads line by line from file pointed by fp
	while(fgets(buff,1024, fp)!= NULL)
	{
	 count++;
	}
    return count;
}
