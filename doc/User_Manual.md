# Introduction

Hospital-Management is a software that tracks and record patient information and status in a hospital, visitors inforamtion and also effectively allocate available rooms to patients getting admitted.

# Installation

Please refer to [INSTALL.md](https://github.com/ShivaSriBusa/Hospital-Management/tree/dev/install.md) file for installation instructions.

# Usage

The user needs to input the following line to execute the Hosptial-Management software and select an appropriate choice. 

```
./bin/HM -a
```
The above command "HM -a" executes application program.
Please note that the binary is located in the bin folder.

The choices are:

1. The first choice is "Add Patient Information". Here you will need to input the patient name, address, contact number,emergency contact number, date of admission (DD-MM-YYYY), time of admission (HH:MM), symptoms, attending doctor's name, patient identity number, medications and allergies. Need to press "Enter" after each entry.
After entering the above informations the software will ask to input the type of symptoms the patient has. The options are: (1) Chronic symptoms, (2) Physical injury symptoms and (3) Neither chronic nor physical. Choosing option (1), displays "Patient can be admitted in special ward", if room in special ward is available, else it displays "No roomsavailable in special ward", of no room is available. For option (2) it displays simialr messages for general ward. For option (3) it displays "No admission required".

2. The second choice is "Display all Patient Information". This option will display all patients information admitted or not.

3. The third choice is "Display prescription, precaution and diet advice". This option ask you to enter the required patients name and phone number. If the patient is found then his precaution, prescription and diet advice is displayed. If the patient is not found, it dispalys "No record found".

4. The fourth choice is "Display information on Patient Admitted". This option gives two more option. (1) Display a patient information and (2) Display total number of Patients  Admitted. If option (1) is chose, it will ask for the desired patient's name and phone number. If patient is found it displays the desired patient's information. If the patient is not found, it displays "No record found!". For option (2), the total number of admitted patients will be displayed.

5. The fifth choice is "Update admitted Patients Record". This option will ask the desired patient's name and phone number. Upon entering desired patients name and phone number it displays the patient's information if found and displays "No reocrd found!" if not found. If desired patient is found it asks if the patient is discharged. If the patient is discharges as displayed then you need to enter "Y". If not discharghed enetr "N", and it will ask if you want to disharge the patient now. If you enter "Y", you need to enter the discharging date and time. If you enter "N", you can enter the patients precaution, prescription and diet advice.

6. The sixth choice is "Add visitor information". It asks for the desired patient's name and phone number. If the desired patient is found, you can enter the visiotr's name, address and phone number. If the ddesired patient is not found it displays "No reocord found!".

7. The seventh choice is "Display Visitor Information". It gives you two options. (1) Dispaly a visitot information and (2) Display total number of visitor. If option (1) is chose, it asks for desired patient's name and phone number. If the patient is found it displays all its visitors information. If the patient is not found it displays "No record found!". If option (2) is chose, it displays total number of visitors.

8. The eighth choice is "Test Details for Patient Symptoms". It gives you to choose from several test from a list of available test for chronic symptoms and physical injury symptoms.

Each options runs a single time. To rerun with different option you need to execute the program with a different choice as needed.

# Testing

Unit testing is done for each functions defined in the software. The test cases can be run using the command below:

```
./bin/HM -t
```

This displays a list of functions to be tested. Upon selecting a test is performed and corresponding result is displayed.

# Help

User can run the below command to know the details about input parameters.

```
./bin/HM -h
```

# Data Files Generation

Information regarding patient is stored in  "patient_record.csv", patient's advices are recorded in "patient_advice.csv", information about discharged patients are recorded in "discharged_list.csv", room informations are recorded in "general_rooms.csv" and "special_rooms.csv", visitor information is reocrded in "visitor_info.csv" and test details of a patient is recorded in "test_details.csv". All these files can be found in 'src' folder.
Test resuts are recorded for each individual functions are stored in their respective "csv" file which can be found in the 'test' folder. 
To generate clean data and test files, you need to the following:

```
make clean && make
```

Then run the `HM` binary again
