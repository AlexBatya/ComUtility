#include "../include/com.h"

void check(const char* comPort, const char* command){

	if(strcmp(command, "check") == 0){
		printf("Bitness: %d\n", openCom(comPort));
		printf("Parity: %d\n", parity(comPort));
		printf("Transfer rate: %d\n", transferRate(comPort));
		printf("Stop bits: %d\n", stopBits(comPort));
	}
	else if (strcmp(command, "bits") == 0){
		printf("%d\n", openCom(comPort));
	}
	else if(strcmp(command, "parity") == 0){
		printf("%d\n", parity(comPort));
	}
	else if(strcmp(command, "speed") == 0){
		printf("%d\n", transferRate(comPort));
	}
	else if(strcmp(command, "stopBits") == 0){
		printf("%d\n", stopBits(comPort));
	}
	

}
