#include <stdlib.h>
#include "CloggerImplementation.h"

/* \TODO: Implement your own logging implementation using the printf logger as a guide.
 *        but with your desired behavior. Rebuild and assign the implementation at runtime
 *        using the syntax SetClogger(GetClogger);
 */

static CLOGGER_RESULT clog_log(const CLOGGER_LEVEL level, const char* const message) {
    // \TODO: 
    return CLOGGER_SUCCESS;
}

static CLOGGER_RESULT clog_set_level(const CLOGGER_LEVEL level) {
    // \TODO: 
    return CLOGGER_SUCCESS;
}

bool GetLogger(CloggerInterface *interface) {
    if (interface == NULL) {
        return false;
    }

    interface->log = (CloggerLogFunctionPointer)clog_log;
    interface->setLevel = (CloggerSetLevelFunctionPointer)clog_set_level;

    return true;
}