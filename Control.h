/*
Purpose: The main control flow class. Allows the end-user to switch
         between terms, view available courses, view their current 
         schedule, add courses to it, clear it and exit the program.
*/

#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "Schedule.h"

class Control{
  public:
    Control();
    ~Control();
    void launch();
    
  private:
    void initCourses(School*);
    bool addSched(Schedule*);
    bool findSched(string, Schedule**);
    int numScheds;
    School* school;
    Schedule* schedules[MAX_ARR];
};

#endif
