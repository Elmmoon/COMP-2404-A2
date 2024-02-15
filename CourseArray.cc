#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "defs.h"
#include "CourseArray.h"

CourseArray::CourseArray(){
    nextId = COURSE_ID;
}

void CourseArray::add(Course* course){
    if (nextId == MAX_ARR + COURSE_ID - 1)
        return;
    int i = 0;
    for (; i < nextId - COURSE_ID; i++){
        if (course->lessThan(courses[i])){
            for (int x = MAX_ARR + COURSE_ID; x > i; x--)
                courses[x] = courses[x-1];
            break;
        }
    }
    courses[i] = course;
    course->setId(nextId++);
}

bool CourseArray::find(int id, Course** c){
    for (int i = 0; i < nextId - COURSE_ID; i++){
        if (courses[i]->getId() == id){
            c = &courses[i];
            return true;
        }
    }
    c = NULL;
    return false;
}

void CourseArray::print(string term){
    for (int i = 0; i < nextId - COURSE_ID; i++){
    if (courses[i]->getTerm() == term){
        courses[i]->print();
    }
}
}