#include <stdlib.h>
#include "NullFunctions.h"
#include "NullCloggerImplementation.h"

bool GetNullClogger(CloggerInterface *interface)
{
    if (interface == NULL) {
        return false;
    }

    interface->log = (CloggerLogFunctionPointer)NullReturnUninitialized;
    interface->setLevel = (CloggerSetLevelFunctionPointer)NullReturnUninitialized;

    return true;
}