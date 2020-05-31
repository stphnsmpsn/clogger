/usr/bin/gcc -Wall -fPIC -c -Idevel/inc ./devel/src/CloggerImplementation.c ./devel/src/Clogger.c ./devel/src/NullCloggerImplementation.c ./devel/src/PrintfCloggerImplementation.c ./devel/src/NullFunctions.c
mv *.o ./build
gcc -shared -o ./build/libclogger.so ./build/CloggerImplementation.o ./build/Clogger.o ./build/NullCloggerImplementation.o ./build/PrintfCloggerImplementation.o ./build/NullFunctions.o
sudo rm -rf /usr/include/stphnsmpsn/clogger
sudo mkdir -p /usr/include/stphnsmpsn/clogger
sudo cp  ./devel/inc/*.h /usr/include/stphnsmpsn/clogger
sudo cp build/libclogger.so /usr/lib
