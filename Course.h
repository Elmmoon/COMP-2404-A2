#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "defs.h"
#include "Time.h"

using namespace std;

class Course{
  public:
    Course(string, string, int, char, string, LectDaysType, int, int);
    ~Course();
    bool computeDays(WeekDayType&, WeekDayType&);
    bool computeSlot(TimeSlotType&);
    bool lessThan(Course*);
    void print();
    int getId();
    string getTerm();
    string getInstructor();
    string getCourseCode();
    void setId(int);

  private:
    int id;
    string term;
    string subject;
    int code;
    char section;
    string instructor;
    LectDaysType days;
    Time* time;

};

#endif