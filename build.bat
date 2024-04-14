gcc -c ./cpp/openCom.c ./cpp/check.c ./cpp/openPort.c ./cpp/change.c
ar rcs ./lib/libcom.a openCom.o check.o openPort.o change.o

del openCom.o check.o openPort.o change.o

gcc -o ./build/DataCom ./src/main.c -L./lib -lcom 
