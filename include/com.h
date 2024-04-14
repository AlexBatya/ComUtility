#include <windows.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#ifndef OPENCOM_H
#define OPENCOM_H

int openCom(const char*); //скорость обмена
int parity(const char*); // Чётность
int transferRate(const char*); //Скорость передачи (Биты)
int stopBits(const char*); //Стоповые биты
													
int open(const char*); //Непрерывное чтение с com порта
											
void check(const char*, const char*);

#endif
