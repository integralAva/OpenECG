#ifndef __WARNING_H_
#define __WARNING_H_

#include "System.h"

typedef enum{
    WAR_NOR,
    WAR_ANOR,
    WAR_MID,
    WAR_AMID,
    WAR_Clear
}WarningType;

void CreatWaring(WarningType war);

#endif

