#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include "../include/com.h"
#include "../include/change.h"

int main(int argc, char* argv[]){
	setlocale(LC_ALL, "Russian");

	check(argv[2], argv[1]);
		
	return 0;
}

