#include "include/id_generate.h"
#include<stdio.h>
#include<stdlib.h>

/* This function is used to generate new row number for the file which we pass as input. Return type is integer.

Variables used:

fp -> Act as FILE pointer. used for opening a file 
count -> A flag used for counting number of rows existing in file 
buff -> used for storing string read from file. 

*/

int id_generate(char *file)
{
    FILE *fp = fopen(file,"r");
    int count=0;
    char buff[1024];
	do
	{
	 fgets(buff, 1024, (FILE*)fp);
	 count++;
	}while((getc(fp))!=EOF);
    return count;
}
