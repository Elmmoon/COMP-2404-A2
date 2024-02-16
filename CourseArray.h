/*
Purpose: A collections class that contains a statically-allocated
         array of Course object pointers.
*/

#ifndef COURSEARRAY_H
#define COURSEARRAY_H

#include "Course.h"
#include "defs.h"

class CourseArray{
  public:
    CourseArray();
    ~CourseArray();
    void add(Course*);
    bool find(int, Course**);
    void print(string);
  private:
    Course* courses[MAX_ARR];
    int nextId;

};

#endif