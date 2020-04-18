/**
 * @file disease.c
 *
 * @brief This function to allocate room in general ward/special ward if patient has physical injury/chronic symptoms 
 * based on availability. If none of those symptoms then patient is not admitted.
 *
 * @author sreeram sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca
 * 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/disease.h"
#include "../include/rooms.h"
#include "../include/id_generate.h"

/** @details room capacity is only for 10 patients. Disease function process this signal retuned by rooms function and stores
 * patient details in "general_rooms.csv" file if symptoms are related to physical injury, If it returns a flag for 
 * no availability, then appropriate message is displayed. If symptoms are related to chronic, patient details are stored
 * in "special_rooms.csv". If symptoms are neither physical nor chronic then displays appropriate message.
 * 
 * @param[in] It takes patient symptoms separated by a demiliter ";" in the file along with patient name and patient phone number.
 * 
 * @return Returns 0 on successful execution and -1 if file doesn't exist.
 * 
 */

int disease(char *symptom, char *patient_name,char*ph)
{
    int ret, flag = 1;
    FILE *fptr;
    char *token;
    int opt;
    token = strtok(symptom, ";");
    while (token != NULL)
    {
        printf("\nPatients symptoms: %s",token);
        flag++;
        token = strtok(NULL, ";");
    }
    printf("\n\nPlease input one of the following options:");
    printf("\n1. Chronic symptoms");
    printf("\n2. Physical injury symptoms");
    printf("\n3. Neither chronic nor physical injury");
    printf("\nInput choice: ");
    scanf("%d",&opt);
    if (opt == 1)
    {
        ret = special_rooms();
        if (ret != 0)
        {
            fptr = fopen("../src/special_rooms.csv", "a");
            ret = id_generate("../src/special_rooms.csv");
            fprintf(fptr,"%d,%s,%s,",ret,patient_name,ph);
            fprintf(fptr,"%s","\n");
            fclose(fptr);
        }
    }
    else if (opt == 2)
    {
        ret = general_rooms();
        if (ret != 0)
        {
            fptr = fopen("../src/general_rooms.csv", "a");
            ret = id_generate("../src/general_rooms.csv");
            fprintf(fptr,"%d,%s,%s,",ret,patient_name,ph);
            fprintf(fptr,"%s","\n");
            fclose(fptr);
        }
    }
    else if(opt==3)
    {
        printf("No admission Required");
    }
    return 0;
}
