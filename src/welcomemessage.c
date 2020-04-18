/*
 * @file display_advice.c
 *
 * @brief Display Welcome Message 
 * 
 * @author Shiva Sri Busa - shivasribusa@cmail.carleton.ca
 * 
 */


#include<stdio.h>
#include<stdlib.h>
#include "include/welcomeMessage.h"

/*
 * @brief A function to display welcome message for Hospital management system.
 * 
 * @details This function execute and it will display welcome message for Hospital management system.
 *
 * @return no return
 */

void welcomeMessage(){

    //Displaying Welcome message
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                HOSPITAL                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t ");
    system("read -p 'Press Enter to continue...' var");
}
