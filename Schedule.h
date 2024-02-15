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