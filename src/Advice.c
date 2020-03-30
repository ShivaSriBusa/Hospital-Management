#pragma warning (disable : 4996)  // disables error-4996 in visual studio
#include "E:\C Project\Hospital-Management\include\Advice.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int Advice(char *pname,char *ph)
{
    int s=100,id;
    FILE *fptr;
    id=id_generate("patient_advice.csv");
    a1.diet_advise = (char *)malloc(s);
    a1.precaution = (char *)malloc(s);
    a1.prescription =(char *)malloc(s);
    fptr = fopen("patient_advice.csv", "a");
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
        fclose(fptr);
        free(a1.diet_advise);
        free(a1.precaution);
        free(a1.prescription);
    }
    return 0;
}
