#ifndef SERVICELOCATORLOGGING_H
#define SERVICELOCATORLOGGING_H

#include <stdbool.h>
#include "CloggerInterface.h"

typedef bool (*InitCloggerInterface)(CloggerInterface *interface);

bool SetClogger(InitCloggerInterface init);
CloggerInterface* Clogger(void);

#endif