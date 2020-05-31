#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <execinfo.h>
#include <signal.h>
#include "PrintfCloggerImplementation.h"

static const char* const LOG_LEVELS[] = {
    "FINEST",
    "FINER",
    "FINE",
    "INFO",
    "WARNING",
    "CRITICAL",
};

static CLOGGER_LEVEL logLevel = CLOGLVL_INFO;

static CLOGGER_RESULT clog_printf_log(const CLOGGER_LEVEL level, const char* const message) {
    if(level < logLevel){
        return CLOGGER_IGNORED;
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%d-%02d-%02d %02d:%02d:%02d] [%s] %s\r\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, LOG_LEVELS[level], message);
    return CLOGGER_SUCCESS;
}

static CLOGGER_RESULT clog_printf_set_level(const CLOGGER_LEVEL level) {
    logLevel = level;
    return CLOGGER_SUCCESS;
}

bool GetPrintfClogger(CloggerInterface *interface) {
    if (interface == NULL) {
        return false;
    }

    interface->log = (CloggerLogFunctionPointer)clog_printf_log;
    interface->setLevel = (CloggerSetLevelFunctionPointer)clog_printf_set_level;

    return true;
}