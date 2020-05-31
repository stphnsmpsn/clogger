#include <stddef.h>

#include "Clogger.h"
#include "NullFunctions.h"

static CloggerInterface clogger = {
        .log = (CloggerLogFunctionPointer)NullReturnUninitialized,
        .setLevel = (CloggerSetLevelFunctionPointer)NullReturnUninitialized,
};

bool SetClogger(InitCloggerInterface init) {
    if (init == NULL)
        return false;

    return init(&clogger);
}

CloggerInterface *Clogger(void) {
    return &clogger;
}