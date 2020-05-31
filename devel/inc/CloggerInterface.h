#ifndef SERVICELOCATORCLOGGERINTERFACE_H
#define SERVICELOCATORCLOGGERINTERFACE_H

typedef enum {
    CLOGGER_INVALID_SIGNAL = -2,
    CLOGGER_ERROR = -1,
    CLOGGER_SUCCESS = 0,
    CLOGGER_IGNORED = 1
} CLOGGER_RESULT;

typedef enum {
    CLOGLVL_FINEST,
    CLOGLVL_FINER,
    CLOGLVL_FINE,
    CLOGLVL_INFO,
    CLOGLVL_WARNING,
    CLOGLVL_CRITICAL,
} CLOGGER_LEVEL;

typedef CLOGGER_RESULT (*CloggerLogFunctionPointer)(const CLOGGER_LEVEL level, const char* const message);
typedef CLOGGER_RESULT (*CloggerSetLevelFunctionPointer)(const CLOGGER_LEVEL level);

typedef struct {
    CloggerLogFunctionPointer log;
    CloggerSetLevelFunctionPointer setLevel;
} CloggerInterface;

#endif