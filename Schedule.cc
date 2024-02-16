#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "Schedule.h"
#include "Time.h"
#include "defs.h"
#include "View.h"

Schedule::Schedule(string t){
    term = t;
    clear();
}


bool Schedule::addCourse(Course* course){
    View view;
    if (course == NULL){
        view.printStr("ERROR:  Course not found\n");
        return false;
    }
    if (course->getTerm() != term){
        view.printStr("ERROR:  This course does not match the term selected\n");
        return false;
    }
    WeekDayType day1, day2;
    TimeSlotType time;
    if (!course->computeDays(day1, day2)){
        view.printStr("ERROR:  Invalid date\n");
        return false;
    }
    if (!course->computeSlot(time)){
        view.printStr("ERROR:  Invalid time\n");
        return false;
    }
    schedule[time][day1] = course;
    schedule[time][day2] = course;      
    return true;
}

void Schedule::print(){
    Time temp;
    cout << "   SCHEDULE FOR CURRENT TERM:  " << term << endl << endl;
    cout << setfill('-') << setw(104) << "" << endl;
    cout << left << setfill(' ') << setw(9) << "|" << setw(4) << "";
    cout << setw(3) << "" << setw(15) << "MON";
    cout << setw(3) << "" << setw(15) << "TUE";
    cout << setw(3) << "" << setw(15) << "WED";
    cout << setw(3) << "" << setw(15) << "THU";
    cout << setw(3) << "" << setw(15) << "FRI" << "|" << endl;
    cout << setfill('-') << setw(104) << "" << endl;

    for (int i = 0; i < NUM_SLOTS; i++){
        cout << "| " << setfill(' ');
        temp.setFromSlot((TimeSlotType)i);
        temp.print();
        cout << left << setfill(' ') << setw(6) << " |";
        for (int x = 0; x < NUM_DAYS; x++){
            if (schedule[i][x] != NULL)
                cout << setw(18) << schedule[i][x]->getCourseCode();
            else 
                cout << setw(18) << "";
        }
        cout << "|" << endl;

        cout << "| " << setw(5) << "" << setw(6) << " |";
        for (int x = 0; x < NUM_DAYS; x++){
            if (schedule[i][x] != NULL)
                cout << setw(5) << "CN:" << setw(13) << schedule[i][x]->getId();
            else 
                cout << setw(18) << "";
        }
        cout << "|" << endl;
        
        cout << "| " << setw(5) << "" << setw(6) << " |";
        for (int x = 0; x < NUM_DAYS; x++){
            if (schedule[i][x] != NULL)
                cout << setw(5) << "Pr:" << setw(13) << schedule[i][x]->getInstructor();
            else 
                cout << setw(18) << "";
        }
        cout << "|" << endl;
        if (i != NUM_SLOTS - 1)
            cout << "|" << setfill('-') << setw(102) << "" << "|" << endl;
    }
    cout << setfill('-') << setw(104) << "" << endl;
}

void Schedule::clear(){
    for (int i = 0; i < NUM_SLOTS; i++){
        for (int x = 0; x < NUM_DAYS; x++)
            schedule[i][x] = NULL;
    }
}

string Schedule::getTerm(){
    return term;
}