# libclogger

A Simple Logging Library for C. 

## About

libclogger supports standard logging levels (Finest, Finer, Fine, Info, Warning, and Critical), and has the ability to set the level of the active Clogger implementation. Log levels are enumerated in contant case and prefixed with `CLOGLVL_`. 

The provided sample implementation, PrintfCloggerImplementation, will drop all log records finer than it's internal setting. This means, setting the Clogger level to Info means all log records with levels `CLOGLVL_FINE`, `CLOGLVL_FINER`, `CLOGLVL_FINEST` will be dropped. 

A skeleton for a custom implementation is provided and can be implemented as you see fit and assigned at runtime using `SetClogger(GetClogger)`. 

## Installation

A convenience script is provided to build and create the library using GCC and move files to their proper locations. Simply run `./build.sh` to build and install this library on your linux system. 

## Usage 

After installing, in your own application, include `clogger.h` from `/usr/unclude/stphnsmpsn/clogger`

An example is shown below: 

```
#include "stphnsmpsn/clogger/Clogger.h"

int main(const int argc, const char const **argv) {
  // We haven't yet set a logger - that's ok; null implementation protects us from crashes
  Clogger()->log(CLOGLVL_INFO, "Program Started");
  
  // Now we will set our logger
  SetClogger(GetPrintfClogger);
  Clogger()->log(CLOGLVL_INFO, "Program Started");
  return 0;
}
```
You will see output similar to:
`[2020-05-31 19:17:41] [INFO] Program Started`
