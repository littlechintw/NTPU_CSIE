#include <bits/stdc++.h>
#define _WIN32_WINNT 0x0500
// If use codeblock, you can ignor it.
// If you get an error say `redefined`, you may have to delete second line.
#include<windows.h>
#include "functions.h"
#include "board.cpp"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);
	init_print();
	board game;
	game.start();

	return 0;
}
