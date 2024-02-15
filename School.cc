#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "CourseArray.h"
#include "School.h"

School::School(string n){
    name = n;
}

School::~School(){}

void School::addCourse(Course* course){
    courses.add(course);
}

bool School::findCourse(int id, Course** course){
    return courses.find(id, course);
}

void School::printCourses(string term){
    cout << term << ": " << endl;
    courses.print(term);
}