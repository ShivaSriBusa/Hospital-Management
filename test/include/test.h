/**
 * @file test.c
 *
 * @brief Implementation of automated unit tests.
 *
 * @author sreeram sankarasubram - sreeramsankarasubram@cmail.carleton.ca
 * @author Kazi Muhammad Jameel - KaziMuhammadJameel@cmail.carleton.ca
 * @author Shiva Sri Busa - ShivaSriBusa@cmail.carleton.ca
 * @author Soummyo Priyo Chattopadhyay - SoummyoPriyoChattopa@cmail.carleton.ca
 */

#define size 11

struct test_patient{
    char phone_no[size], emergency_no[size];
    char date_adm[size], time_adm[size], patient_identity[size], date_release[size],time_release[size];
    char *name, *doc_name, *address, *symp, *medication, *allergies,*status;
}t_p1;

struct test_patient_advise{
   char *precaution, *diet_advise, *prescription;
}t_a1;

struct test_visitor{
    char phone_no[size];
    char *name,*address;
}t_v1;

int test_general_rooms();
int test_id_generate(char *fname);
int test_special_rooms();
int test_disease(char *symptom, char *patient_name,char*ph);
void test_add_patient();
int test_count_visitor(char *fname);
int test_display_single_patient(char *name, char* ph);
int test_advice(char *pname,char *ph);
int test_Search_in_File(char *fname, char *str, char*ph);
int test_add_visitor(char *filename,char *str,char *ph);
int test_visitor_info(char *name,char *ph);
int test_count_admit(char *f1name, char *f2name);
int test_display_single_visitor(char *name, char *ph);
int test_display_advice(char *name,int ph);
int test_display_test(char *name, char  *ph);
void test_welcome_message();
int all_test_case();
