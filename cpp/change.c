#include "../include/change.h"

int transferRateChange(const char* comPort, const char* number){
	HANDLE hCom = CreateFile(comPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		printf("Error opening the COM port.\n");
		return 1;
	}

	DCB dcb;
	if (!GetCommState(hCom, &dcb)) {
		printf("Error when receiving the COM port configuration.\n");
		CloseHandle(hCom);
		return 1;
	}

	// Настройка параметров передачи данных, включая скорость передачи данных
	dcb.BaudRate =  atoi(number); // Новая скорость передачи данных

	if (!SetCommState(hCom, &dcb)) {
		printf("Error when setting the COM port configuration.\n");
		CloseHandle(hCom);
		return 1;
	}

	printf("COM port baud rate set to 9600 bps.\n");

	CloseHandle(hCom);
	return 0;
}
