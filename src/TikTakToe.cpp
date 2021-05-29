#include "Block.h"
#include<iostream>
#include<graphics.h>
using namespace std;

int x = 0;
int y = 0;

int player = 0;
bool validTurn = false;

bool TurnTeller(int a) {

//If Kaata is played
if (a == true) {
delay(50);
settextstyle(4, 4, 1);
outtextxy(360, 135, "Gola's   Turn");
return true;
}
//If Gola is played
else {
delay(50);
settextstyle(4, 4, 1);
outtextxy(360, 135, "Kaata's Turn");
return false;
}
}

//Function for printing TicTacToe box, telling the turn and breaking at winning
void PlayGame() {

settextstyle(4, 4, 1);
outtextxy(360, 135, "Kaata's Turn");
Block a[9];

//Setting the values for blocks
a[0].SetValues(200, 250, 200, 250);
a[1].SetValues(250, 300, 200, 250);
a[2].SetValues(300, 350, 200, 250);
a[3].SetValues(200, 250, 250, 300);
a[4].SetValues(250, 300, 250, 300);
a[5].SetValues(300, 350, 250, 300);
a[6].SetValues(200, 250, 300, 350);
a[7].SetValues(250, 300, 300, 350);
a[8].SetValues(300, 350, 300, 350);

//Printing the blocks
for (int j = 0; j < 9; j++) {
a[j].PrintBlock();
}

//Infinite loop
while (true) {

while (!ismouseclick(WM_LBUTTONDOWN)) {
delay(500);
}

getmouseclick(WM_LBUTTONDOWN, x, y);
//cout << "x is "<<x<<endl;
//cout << "y is "<<y<<endl;

validTurn = false;

//If block is clicked
for (int j = 0; j < 9; j++) {
if (a[j].BlockClick(x, y)) {

//Take action. In other words, print Kaata or Gola
validTurn = a[j].TakeAction(player);

}
}

//Gola Winning

//Vertical
int q = 0;
int w = 3;
int e = 6;
int x1 = 225;
int x2 = 200;
int y1 = 225;
int y2 = 350;
bool win = false;
for(int i = 0; i<3; i++){

	if(a[q+i].GetState() == 1 && a[w+i].GetState() == 1 && a[e+i].GetState() == 1) {
		outtextxy(360, 135, "Gola Wins!!!!");
		setcolor(CYAN);
		line(x1+i*50, x2, y1+i*50, y2);
		win = true;
		break;
}
}

if(win == true){
	break;
}

//Diagonal
q = 0;
w = 4;
e = 8;
x1 = 200;
x2 = 200;
y1 = 350;
y2 = 350;
win = false;
for(int i = 0; i<2; i++){

	if(a[q+i+i].GetState() == 1 && a[w].GetState() == 1 && a[e-i-i].GetState() == 1){

		outtextxy(360, 135, "Gola Wins!!!!");
		setcolor(CYAN);
		line(x1+i*150, x2, y1-i*150, y2);
		win = true;
		break;
	}
}

if(win == true){
	break;
}

//Horizontal
q = 0;
w = 1;
e = 2;
x1 = 200;
x2 = 225;
y1 = 350;
y2 = 225;
win = false;
for(int i = 0; i<3; i++){

	if(a[q+i+i+i].GetState() == 1 && a[w+i+i+i].GetState() == 1 && a[e+i+i+i].GetState() == 1){

			outtextxy(360, 135, "Gola Wins!!!!");
			setcolor(CYAN);
			line(x1, x2+i*50, y1, y2+i*50);
			win = true;
			break;
		}
}

if(win == true){
	break;
}

//Kaata Winning

//Vertical
q = 0;
w = 3;
e = 6;
x1 = 225;
x2 = 200;
y1 = 225;
y2 = 350;
win = false;
for(int i = 0; i<3; i++){

	if(a[q+i].GetState() == 2 && a[w+i].GetState() == 2 && a[e+i].GetState() == 2) {
		outtextxy(360, 135, "Kaata Wins!!!!");
		setcolor(CYAN);
		line(x1+i*50, x2, y1+i*50, y2);
		win = true;
		break;
}
}

if(win == true){
	break;
}

//Diagonal
q = 0;
w = 4;
e = 8;
x1 = 200;
x2 = 200;
y1 = 350;
y2 = 350;
win = false;
for(int i = 0; i<2; i++){

	if(a[q+i+i].GetState() == 2 && a[w].GetState() == 2 && a[e-i-i].GetState() == 2){

		outtextxy(360, 135, "Kaata Wins!!!!");
		setcolor(CYAN);
		line(x1+i*150, x2, y1-i*150, y2);
		win = true;
		break;
	}
}

if(win == true){
	break;
}

//Horizontal
q = 0;
w = 1;
e = 2;
x1 = 200;
x2 = 225;
y1 = 350;
y2 = 225;
win = false;
for(int i = 0; i<3; i++){

	if(a[q+i+i+i].GetState() == 2 && a[w+i+i+i].GetState() == 2 && a[e+i+i+i].GetState() == 2){

			outtextxy(360, 135, "Gola Wins!!!!");
			setcolor(CYAN);
			line(x1, x2+i*50, y1, y2+i*50);
			win = true;
			break;
		}
}

if(win == true){
	break;
}
//Draw
int i = 0;
for(; i<9; i++){

	if(a[i].GetOccuState() == false){
		break;
	}
}
if (i == 9){
	outtextxy(360, 135, "!!!!!!Draw!!!!!!");
	break;
}

if (validTurn) {
player = !player;
}

TurnTeller(player);

}


}

void PrintIntroPage(){
	//Prints "Designed by The Narayan Brothers" at downmost right
	settextstyle(10, 4, 1);
	outtextxy(630, 470, "Designed by The Narayan Brothers");
	//Prints "Welcome to The KaataGola Game" on the middle at the top
	settextstyle(10, 4, 1);
	outtextxy(480, 30, "Welcome To The KaataGola Game!!!");
}

int main() {

int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);

PrintIntroPage();
//Defining a variable Play
Block Play;
//Setting the values for Play button
Play.SetValues(220, 325, 65, 100);
outtextxy(293, 94, "PLAY");
//Printing from set values
Play.PrintBlock();

while (!ismouseclick(WM_LBUTTONDOWN)) {
delay(500);

getmouseclick(WM_LBUTTONDOWN, x, y);
//cout << "x is "<<x<<endl;
//cout << "y is "<<y<<endl;

if (Play.BlockClick(x, y)) {
cleardevice();
PrintIntroPage();
PlayGame();

}
}

getch();
closegraph();
return 0;
}
