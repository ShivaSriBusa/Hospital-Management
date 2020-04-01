#pragma warning (disable:4996) // disables error-4996 in visual studio
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "include/count_visitor.h"

/* This function is used to count the number of visitors from the given
input file "visitor_info.csv".  Return type is integer. The functions 
returns the count if the given file is opened successfully and returns -1
if the file cannot be opened or not found.

Variables used:

fptr -> File pointer to open file.
count -> counts number of rows as each row contains a visitor information
buff -> to store string read from file.

*/

int count_visitor(char *fname)
{
    char buff[1024];
    int count=0;;
    FILE *fptr;
    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        printf("\n file opening failed ");
        return -1;
    }
    do
	{
	 fgets(buff, 1024, (FILE*)fptr);
	 count++;
	}while((getc(fptr))!=EOF);
    fclose(fptr);

    // returns count-1 as the first row contains heading for each coloum.
    return count-1;
}
