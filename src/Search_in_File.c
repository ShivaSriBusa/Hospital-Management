/**
 * @file Search_in_File.c
 *
 * @brief Implmentation of updating patient info to a file.
 *
 * @author Kazi Muhammad Jameel - kazimuhammadjaeel@cmail.carleton.ca
 */

#pragma warning (disable : 4996)  // disables error-4996 in visual studio
#include "include/Search_in_File.h"
#include "include/display_single_patient.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "include/add_patient.h"
#include "include/Advice.h"
#include "include/id_generate.h"

 /** Here the user will be able to update the "Discharge status" in "patient_record.csv" file.
  * To update the "Discharge status" a temporary file "temp.csv" is used.
  * The user will also be able to maintain a list of discharged patients in "discharged_list.csv" file.
  * This files takes the following input:
  * • Patient Name
  * • Patient phone number
  * • Date of release
  * • Time of release
  *
  * @brief After taking in the file "patient_record.csv" and patient name and phone number as input, the
  * the function will check if the patient name and phone number exists in the "patient_record.csv" file.
  * If the patient is found it displays the patient's information on the console invoking "display_single_
  * patient" function, otherwise it displays appropriate message. The user will be able to see if the
  * patient is discharged by looking at the "Discharge status". If the patient is already discharged the
  * function will return to main. If the patient is not discharged, the user will be asked if the patient is
  * being discharged. If yes it will update the "patient_record.csv" file "Discharge status" coloum to "Yes"
  * initially it is "No", and stores the release date and time along with patien's name and phone number to
  * "discharged_list.csv" file. If the patient is not discharged then the function invokes "Advice.c" to
  * store the doctor's advice, prescription and precaution regarding the corresponding patient.
  *
  */

int Search_in_File(char* fname, char* str, char* ph)
{
    // integer variable id  to generate row number by calling id_generate function in "discharged_list.csv". 
    int id;

    // integer variable field_count to keep count of coloum initialted at 0.
    int field_count = 0;

    // integer variable row_count to keep count of row initialted at 0.
    int row_count = 0;

    // integer variable flag to store the return value of the function "display_single_patient".
    int flag;

    // Character variable inp to input a char.
    char inp;

    // Character array string with size 1024 to read a line from a file.
    char string[1024];

    // Character pointer token and field.
    char* token, * field;

    // File pointers to work with files.
    FILE* fp, * fstream, * fptr2, * fptr1;

    // Opening the "discharged_list.csv" in append mode.
    fstream = fopen("discharged_list.csv", "a");

    // Open the file "patient_record" passed as input paramenter. If the file is not found returns -1.
    if ((fp = fopen(fname, "r")) == NULL) {
        return(-1);
    }

    // If the file "patient_record" is found invoke "display_single_patient" and store return value to flag.
    flag = display_single_patient(str, ph);

    // If flag is -1 function terminates and returns to main.
    if (flag == -1) {
        return 0;
    }

    // Else check the "Discharge status" of the patient.
    else {
        printf("\nIs the patient discharged? (Y/N) :");
        scanf("%c", &inp);
        fgetc(stdin);
        // If Discharged return to main as patient is already discharged
        if (inp == 'Y') {
            return 0;
        }
            // Else discharge the patient  or invoke "Advice.c" to enter doctor's advice, prescription and precaution. 
        else {
            printf("\nDo you want to discharge now? (Y/N) :");
            scanf("%c", &inp);
            fgetc(stdin);
            if (inp == 'N') {
                Advice(str, ph);
            }
                // If dischrged, enter release time and date and store in "discharged_list.csv" file.  
                // Also update the "patient_record.csv" files "Discharge_status" to "yes".
            else {
                id = id_generate("discharged_list.csv");
                printf("\nPlease input date of release (DD-MM-YYYY) : ");
                gets(p1.date_release);
                printf("\nPlease input time of release (HH:MM): ");
                gets(p1.time_release);
                fprintf(fstream, "%d,%s,%s,%s,%s\n", id, str, ph, p1.date_release, p1.time_release);
                fclose(fstream);
                fptr1 = fopen("patient_record.csv", "r");
                if (!fptr1){
                    printf("Unable to open the input file!!\n");
                    return 0;
                }
                fptr2 = fopen("temp.csv", "w");
                // Updating "patient_reocrd.csv" file by copying all contents to the temporary file "temp.csv".
                fprintf(fptr2, "ID,Name,Phone Number,Address,Emergency Phone Number,Date of admission (DD-MM-YYYY),");
                fprintf(fptr2, "Time of admission (HH:MM),Symptoms,Doctors name,Identity Number,Medications,Allergies,Discharge status\n");
                while (fgets(string, 1024, fptr1)){
                    field_count = 0;
                    row_count++;
                    if (row_count == 1) {
                        continue;
                    }
                    field = strtok(string, ",");
                    token = field;
                    token = strtok(NULL, ",");
                    if (strcmp(token, str) == 0) {
                        token = strtok(NULL, ",");
                        if (strcmp(token, ph) == 0) {
                            id = id_generate("temp.csv");
                            fprintf(fptr2, "%d,", row_count - 1);
                            while (field){
                                if (field_count == 0) {
                                    fprintf(fptr2, "%s,", str);
                                    field = strtok(NULL, ",");
                                    field_count++;
                                }
                                if (field_count == 11) {
                                    field = (char*)malloc(100);
                                    fprintf(fptr2, "Yes");
                                    free(field);
                                }
                                if (field_count == 1) {
                                    fprintf(fptr2, "%s,", token);
                                    field_count++;
                                }
                                if (field_count != 1) {
                                    fprintf(fptr2, "%s,", field);
                                    field = strtok(NULL, ",");
                                    field_count++;
                                }
                            }
                        }
                    }
                    else {
                        while (field){
                            if (field_count == 1) {
                                fprintf(fptr2, "%s,", token);
                                field_count++;
                            }
                            if (field_count != 1) {
                                fprintf(fptr2, "%s,", field);
                                field = strtok(NULL, ",");
                                field_count++;
                            }
                            if (field_count == 12) {
                                fprintf(fptr2, "%s", field);
                                field = strtok(NULL, ",");
                                field_count = 0;
                            }
                        }
                    }
                }
                fclose(fptr1);
                fclose(fptr2);
                // Remove the old "patient_record.csv" and rename the "temp.csv" to be the updated "patient_record.csv" file.
                remove("patient_record.csv");
                rename("temp.csv", "patient_record.csv");
            }
        }
        return 0;
    }
}




