/*
Purpose: A representation of a term's schedule that may contain a variety of
         Course object pointers in a 2D array.
         
Complexities: A 2D array is used to represent the grid-like structure of a schedule.
              The outer array (vertical) represents the time slots.
              The inner arrays (horizontal) represent the days.
*/

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

#include "Course.h"
#include "defs.h"

class Schedule
{
  public:
    Schedule(string);
    bool addCourse(Course*);
    void print();
    void clear();
    string getTerm();

  private:
    Course* schedule[NUM_SLOTS][NUM_DAYS];
    string term;

};

#endif