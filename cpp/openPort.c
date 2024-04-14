#include "../include/com.h"

int open(const char* comPort){
	HANDLE hCom;
	DWORD bytesRead;
	char buffer[1024]; // Буфер для чтения данных

	// Открыть COM-порт для чтения
	hCom = CreateFile(comPort, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		printf("Error opening the COM port.\n");
		return 1;
	}

	// Непрерывно читать данные из COM-порта
	while (1) {
		if (!ReadFile(hCom, buffer, sizeof(buffer), &bytesRead, NULL)) {
			printf("Error reading from COM port.\n");
			break;
		}

		// Обработать прочитанные данные здесь
		printf("Received %d bytes: %s\n", bytesRead, buffer);
	}

	// Закрыть COM-порт
	CloseHandle(hCom);
}
