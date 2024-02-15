#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
using namespace std;

#include "Course.h"
#include "defs.h"
#include "CourseArray.h"

class School
{
  public:
    School(string);
    ~School();
    void addCourse(Course*);
    bool findCourse(int, Course**);
    void printCourses(string);
  private:
    string name;
    CourseArray courses;
    
};

#endif