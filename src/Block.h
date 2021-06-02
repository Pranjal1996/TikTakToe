#include<iostream>
#include<graphics.h>
#include <string.h>
using namespace std;

class Block {

	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	bool occupied = false;
	int DrawTeller = 0;
	bool printMessage = false;
	char Message[];
	public:

	void SetValues(int a, int b, int c, int d) {
	x1 = a;
	x2 = b;
	y1 = c;
	y2 = d;
	occupied = false;
	printMessage = false;
	//Message = "";
	}
	void SetMessage(string a){
		strcpy(Message,a.c_str());
		printMessage= true;
	}

	void PrintBlock() {
	setcolor(WHITE);
	rectangle(x1, y1, x2, y2);
	//Prints PLAY on the Play button
	if(printMessage){
	settextstyle(10, 0, 1);
	outtextxy(x1+(x2-x1)/3, y1 +(y2-y1)/8, Message);
	}
	}

	bool BlockClick(int a, int b) {

	if (a > x1 && a < x2 && b > y1 && b < y2) {
	return true;
	}
	else {
	return false;
	}
	}

	void DrawCircle() {
	circle((x1 + x2) / 2, (y1 + y2) / 2, 24);
	occupied = true;
	DrawTeller = 1;
	}

	void DrawKaata() {
	line(x1, y1, x2, y2);
	line(x1, y2, x2, y1);
	occupied = true;
	DrawTeller = 2;
	}

	bool TakeAction(int a) {
	if (!occupied) {
	if (a == true) {
	DrawCircle();
	}
	else {
	DrawKaata();
	}
	return true;
	}
	return false;
	}

	int GetState(){
		return DrawTeller;
	}

	int GetOccuState(){
		return occupied;
	}

	void Reset(){
		occupied = false;
		DrawTeller = 0;
	}
	};
