# Hospital-Management

Hospital-Management is a program  which will help us track and update room status and patient’s status in a hospital. The software includes 
maintaining patient details, providing prescription, precautions and diet advise, providing and maintaining all kinds of test for a patient, billing. 
The purpose of the program is to provide efficient way to manage patient records in the hospital and help in managing room occupancy.



# Authors

- Soummyo Priyo Chattopadhyay - soummyopriyochattopa@cmail.carleton.ca - Carleton University
- Shiva Sri Busa - shivasribusa@cmail.carleton.ca - Carleton University
- Sreeram Sankarasubramanian - sreeramsankarasubram@cmail.carleton.ca - Carleton University
- Kazi Muhammad Jameel - kazimuhammadjameel@cmail.carleton.ca - Carleton University

# Installation

Installation steps are mentioned in [INSTALL.md](https://github.com/ShivaSriBusa/Hospital-Management/tree/master/install.md)

# Usage

To run, you must first install it. Then you can follow instructions mentioned in
[User_Manual.md](https://github.com/ShivaSriBusa/Hospital-Management/blob/dev/doc/User_Manual.md).

# File Structure

File Structure 

```
├── doc 	-> Usage file
│   ├── User_Manual.md
│   ├── Developer_Manual.md
├── assets      -> Flowchart 
├── INSTALL.md 	-> Installation Guide
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file
├── bin 	-> Binary directory
│   ├── HM.exe
├── doc
│   └── html 	-> Doxygen document
├── include 	-> Header files
│   ├── add_patient.h
│   ├── add_visitor.h
│   ├── advice.h
│   └── count_admit.h
│   ├── count_visitor.h
│   ├── disease.h
│   ├── display_advice.h
│   ├── display_single_patient.h
│   ├── display_single_visitor.h
│   ├── id_generate.h
│   └── read_patient.h
│   ├── rooms.h
│   ├── search_in_file.h
│   ├── test_details.h
│   └── visitor_info.h
│   └── welcome_message.h
├── obj 	-> Object files
├── sensor_fusion_config 	-> Doxygen Configuration files
├── sensor_fusion_report.txt 	-> Report data
├── src 	-> Source files 
│   ├── add_patient.c
│   ├── add_visitor.c 
│   ├── advice.c
│   ├── count_admit.c
│   ├── count_visitor.c
│   └── discharged_list.csv     -> dischaged list file 
│   ├── disease.c
│   ├── display_advice.c 
│   ├── display_single_patient.c
│   ├── display_single_visitor.c
│   ├── general_rooms.csv       -> general room details file
│   └── id_generate.c
│   ├── patient_advice.csv      -> patient advice details file
│   ├── patient_record.csv      -> patient record details file
│   ├── read_patient.c
│   ├── rooms.c
│   └── search_in_file.c       
│   ├── source.c
│   ├── special_rooms.csv       -> special room details file
│   ├── test_details.c
│   ├── test_details.csv        -> test details file
│   ├── visitor_info.c       
│   └── visitor_info.csv        -> visitor information file
│   └── welcome_message.c       
└── test
│   ├── include		-> Header file for unittest
│     └── test.h
│   ├── results	        -> Results file for unittest
       └── results.csv
│   ├── patient_advice.csv      
│   ├── test.c 
│   ├── test_test_details.csv
│   ├── test_discharge_list.csv
│   ├── test_general_rooms.csv
│   └── test_patient_advice.csv      
│   ├── test_patient_record.csv
│   ├── test_patient_record_1.csv
│   ├── test_patient_record_2.csv
│   ├── test_patient_record_3.csv
│   ├── test_special_rooms.csv     
│   └── test_visitor_info.csv
│            
```

# For Developers

The developer manual is available [here](https://github.com/ShivaSriBusa/Hospital-Management/tree/dev/doc/developer_manual.md).

# License

This project is licensed under the GPL 2.0 License - see the LICENSE.md file for details

# Acknowledgements

Thank to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.
