#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "Schedule.h"
#include "defs.h"

Schedule::Schedule(string t){
    term = t;
    clear();
}


bool Schedule::addCourse(Course* course){
    if (course == NULL || course->getTerm() != term){
        cout << "ERROR:  Course not found" << endl;
        return false;
    }
    WeekDayType day1, day2;
    TimeSlotType time;
    if (!course->computeDays(day1, day2)){
        cout << "ERROR:  Invalid date" << endl;
        return false;
    }
    if (!course->computeSlot(time)){
        cout << "ERROR:  Invalid time" << endl;
        return false;
    }
    schedule[day1][time] = course;
    schedule[day2][time] = course;      
    return true;
}

void Schedule::print(){

}

void Schedule::clear(){
    for (int i = 0; i < NUM_SLOTS; i++){
        for (int x = 0; i < NUM_DAYS; i++)
            schedule[i][x] = NULL;
    }
}

string Schedule::getTerm(){
    return term;
}