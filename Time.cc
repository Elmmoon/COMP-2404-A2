#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"
#include "defs.h"


Time::Time(int h, int m)
{
  set(h, m);
}

void Time::set(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

bool Time::computeSlot(TimeSlotType& slot){
  if (minutes == 0){  
    switch (hours){
      case 10:
        slot = SLOT_1000;
        break;
      case 13:
        slot = SLOT_1300;
        break;
      case 16:
        slot = SLOT_1600;
        break;
      case 18:
        slot = SLOT_1800;
        break;
      default:
        slot = BAD_TIME_SLOT;
        return false;
    }
  }
  else if (minutes == 30){
    switch (hours){
      case 8:
        slot = SLOT_0830;
        break;
      case 11:
        slot = SLOT_1130;
        break;
      case 14:
        slot = SLOT_1430;
        break;
      default:
        slot = BAD_TIME_SLOT;
        return false;
    }
  }
  else{
    slot = BAD_TIME_SLOT;
    return false;
  }
  return true;
}

bool Time::setFromSlot(TimeSlotType slot){
  switch (slot){
    case SLOT_0830:
      hours = 8;
      minutes = 30;
      break;
    case SLOT_1000:
      hours = 10;
      minutes = 0;
      break;
    case SLOT_1130:
      hours = 11;
      minutes = 30;
      break;
    case SLOT_1300:
      hours = 13;
      minutes = 0;
      break;
    case SLOT_1430:
      hours = 14;
      minutes = 30;
      break;
    case SLOT_1600:
      hours = 16;
      minutes = 0;
      break;
    case SLOT_1800:
      hours = 18;
      minutes = 0;
      break;
    default:
      return false;
  }
  return true;
}

int Time::convertToMins()
{
  return (hours*60 + minutes);

}

void Time::print()
{
  cout << right << setfill('0')<<setw(2)<<hours<<":"
       << right << setfill('0')<<setw(2)<<minutes;
}

