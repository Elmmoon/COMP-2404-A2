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
