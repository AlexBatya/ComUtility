#include "../include/com.h"

int openCom(const char* comPort){
	setlocale(LC_ALL, "Russian");

	HANDLE hCom;
  DCB dcb;

	// Открываем COM-порт (COM3)
	hCom = CreateFile(comPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		printf("Error opening the COM port.\n");
		return 1;
	}

	// Получаем текущую конфигурацию COM-порта
	if (!GetCommState(hCom, &dcb)) {
		printf("Error when receiving the COM port configuration.\n");
		CloseHandle(hCom);
		return 1;
	}

	// Выводим значение битности
	
	// printf("Bitness: %d\n", dcb.ByteSize);
	
	// Закрываем COM-порт
	CloseHandle(hCom);

	return dcb.ByteSize;

}

int parity(const char* comPort){

	int par = 0;
	
	HANDLE hCom = CreateFile(comPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		printf("Error opening the COM port.\n");
		return 1;
	}

	// Получаем текущую конфигурацию COM-порта
	DCB dcb;
	if (!GetCommState(hCom, &dcb)) {
		printf("Error when receiving the COM port configuration.\n");
		CloseHandle(hCom);
		return 1;
	}

	// Проверяем наличие чётности
	if (dcb.fParity) {
		par = 1;
	} else {
		par = 0;
	}

	// Закрываем COM-порт
	CloseHandle(hCom);

	return par;
}

int transferRate(const char* comPort){ 

	HANDLE hCom = CreateFile(comPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		printf("Error opening the COM port.\n");
		return 1;
	}

	// Получаем текущую конфигурацию COM-порта
	DCB dcb;
	if (!GetCommState(hCom, &dcb)) {
		printf("Error when receiving the COM port configuration.\n");
		CloseHandle(hCom);
		return 1;
	}

	// Выводим скорость передачи данных (baud rate)
	// printf("transfer rate: %d\n", dcb.BaudRate);
	//
	// Закрываем COM-порт
	CloseHandle(hCom);

	return dcb.BaudRate;
}

int stopBits(const char* comPort){

	HANDLE hCom = CreateFile(comPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		printf("Error opening the COM port.\n");
		return 1;
	}

	// Получаем текущую конфигурацию COM-порта
	DCB dcb;
	if (!GetCommState(hCom, &dcb)) {
		printf("Error when receiving the COM port configuration.\n");
		CloseHandle(hCom);
		return 1;
	}

	// Выводим количество стоповых битов
	// printf("Stop bits: %d\n", dcb.StopBits);
	//
	// Закрываем COM-порт
	CloseHandle(hCom);

	return dcb.StopBits;
}
