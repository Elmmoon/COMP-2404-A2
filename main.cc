/* 
Purpose: A schedule manager for Carleton University's Fall 2023 and Winter 2024
         semesters. View 'Usage' for a list of instructions and functionalities.
Usage:
    Enter the project directory
    Enter 'make', then './a2' into the command line
    Enter 1 to select a term
        Only 'F23' and 'W24' are available
    Enter 2 to view courses
    Enter 4 to add courses to the schedule
        Courses are added by their course id, which
        can be viewed by entering 2 in the menu
    Enter 3 to view the schedule
    Enter 1 to switch between term schedules
    Enter 5 to clear the current schedule
    Enter 0 to exit
Author: Dylan Yin
ID: 101257186
*/

#include "Control.h"

int main(){
    Control control;
    control.launch();
    return 0;
}