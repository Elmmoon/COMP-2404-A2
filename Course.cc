#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "Time.h"
#include "defs.h"

Course:: Course(string t, string s, int c, char se, string i, LectDaysType d, int h, int m){
    term = t;
    subject = s;
    code = c;
    section = se;
    instructor = i;
    days = d;
    time = new Time(h, m);
}

Course::~Course(){
    delete time;
}

bool Course::computeDays(WeekDayType& day1, WeekDayType& day2){
    switch (days){
        case MON_WED:
            day1 = MON;
            day2 = WED;
            break;
        case TUE_THU:
            day1 = TUE;
            day2 = THU;
            break;
        case WED_FRI:
            day1 = WED;
            day2 = FRI;
            break;
        default:
            day1 = BAD_WEEK_DAY;
            day2 = BAD_WEEK_DAY;
            return false;
    }
    return true;
}

bool Course::computeSlot(TimeSlotType& slot){
    return time->computeSlot(slot);
}

bool Course::lessThan(Course* course){
    if (subject < course->subject)
        return true;
    else if (subject == course->subject){
        if(code < course->code)
            return true;
        else if (code == course->code){
            if (term < course->term)
                return true;
            if (term == course->term){
                if (section < course->section)
                    return true;
            }
        }
    }
    return false;
}

string Course::getTerm(){
    return term;
}

string Course::getInstructor(){
    return instructor;
}

string Course::getCourseCode(){
    return subject + " " + to_string(code) + "-" + section;
}

void Course::setId(int i){
    id = i;
}

int Course::getId(){
    return id;
}

void Course::print(){
    cout << left << setfill(' ') << setw(5) << id << " Term: " << setw(5) << term <<
     " " << setw(4) << subject << " " << setw(4) << code << " " << setw(2) << section <<  
     " " << days << " ";
    time->print();
    cout << "   Instr: " << left << instructor << endl; 
}