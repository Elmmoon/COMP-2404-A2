#ifndef TIME_H
#define TIME_H

#include "defs.h"

class Time
{
  public:
    Time(int=0, int=0);
    void print();
    bool computeSlot(TimeSlotType&);
    bool setFromSlot(TimeSlotType);

  private:
    int  hours;
    int  minutes;
    void set(int, int);
    int  convertToMins();
};

#endif
