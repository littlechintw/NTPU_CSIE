#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void setColor(int color){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

void init_print(){
	printf("=======================================\n");
	printf("| Sevens                         v1.1 |\n");
	printf("---------------------------------------\n");
	printf("| Creater: littlechin                 |\n");
	printf("---------------------------------------\n");
	printf("| Copyright (c) 2020 littlechin       |\n");
	printf("=======================================\n\n");
}
