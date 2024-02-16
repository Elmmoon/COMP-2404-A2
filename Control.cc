#include <iostream>
using namespace std;
#include <string>

#include "School.h"
#include "Control.h"
#include "View.h"
#include "defs.h"

Control::Control(){
  school = new School("Carleton U. School of Computer Science");
  numScheds = 0;
}

Control::~Control(){
  for (int i = 0; i < numScheds; i++)
    delete schedules[i];
  delete school;
}

void Control::launch(){
  View view;
  string term = "NONE SELECTED";
  int id,choice;
  Schedule* curSched = NULL;
  Course* course;
  bool loop = true;

  initCourses(school);
  while (loop){
    view.showMenu(choice);
    cout << endl;
    switch(choice){
      case 1:
        cout << "Please enter new term: ";
        view.readStr(term);
        if (!findSched(term, &curSched)){
          curSched = new Schedule(term);
          addSched(curSched);
        }
      break;

      case 2:

        school->printCourses(term);
      break;

      case 3:
        if (curSched == NULL)
          cout << "ERROR:  No term selected" << endl;
        else
          curSched->print();
      break;

      case 4:
        if (curSched == NULL)
          cout << "ERROR:  No term selected" << endl;
        else{
          cout << "Please enter course id: ";
          view.readInt(id);
          if (school->findCourse(id, &course))
            curSched->addCourse(course);
          else
            cout << "ERROR:  Course not found" << endl;
        }
        
      break;

      case 5:
        if (curSched == NULL)
          cout << "ERROR:  No term selected" << endl;
        else 
          curSched->clear();
      break;
      case 0:
        loop = false;
    }
  }
}

bool Control::addSched(Schedule* sched){
  if (numScheds == MAX_ARR || sched == NULL)
    return false;
  schedules[numScheds++] = sched;
  return true;
}

bool Control::findSched(string term, Schedule** sched){
  for (int i = 0; i < numScheds; i++){
    if (schedules[i]->getTerm() == term){
      *sched = schedules[i];
      return true;
    }   
  }
  return false;
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau", TUE_THU, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen", WED_FRI, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau", MON_WED, 13, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen", TUE_THU, 8, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet", TUE_THU, 11, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet", MON_WED, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill", MON_WED, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill", MON_WED, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel", TUE_THU, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet", TUE_THU, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin", TUE_THU, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill", MON_WED, 8, 30));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI", MON_WED, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp", WED_FRI, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp", TUE_THU, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau", TUE_THU, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau", MON_WED, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel", TUE_THU, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel", MON_WED, 18, 0));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill", TUE_THU, 8, 30));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill", WED_FRI, 16, 0));
}

