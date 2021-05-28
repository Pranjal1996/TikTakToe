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

//Left Vertical
if (a[0].GetState() == 1 && a[3].GetState() == 1 && a[6].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(225, 200, 225, 350);
break;
}

//Middle Vertical
else if (a[1].GetState() == 1 && a[4].GetState() == 1 && a[7].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(275, 200, 275, 350);
break;
}

//Right vertical
else if (a[2].GetState() == 1 && a[5].GetState() == 1 && a[8].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(325, 200, 325, 350);
break;
}

//Top left to bottom right diagonal
else if (a[0].GetState() == 1 && a[4].GetState() == 1 && a[8].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(200, 200, 350, 350);
break;
}

//Top right to bottom left diagonal
else if (a[2].GetState() == 1 && a[4].GetState() == 1 && a[6].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(350, 200, 200, 350);
break;
}

//Top horizontal
else if (a[0].GetState() == 1 && a[1].GetState() == 1 && a[2].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(200, 225, 350, 225);
break;
}

//Middle horizontal
else if (a[3].GetState() == 1 && a[4].GetState() == 1 && a[5].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(200, 275, 350, 275);
break;
}

//Down horizontal
else if (a[6].GetState() == 1 && a[7].GetState() == 1 && a[8].GetState() == 1) {
outtextxy(360, 135, "Gola Wins!!!!");
setcolor(CYAN);
line(200, 325, 350, 325);
break;
}

//Kaata Winning

//Left Vertical
if (a[0].GetState() == 2 && a[3].GetState() == 2 && a[6].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(225, 200, 225, 350);
break;
}

//Middle Vertical
else if (a[1].GetState() == 2 && a[4].GetState() == 2 && a[7].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(275, 200, 275, 350);
break;
}

//Right vertical
else if (a[2].GetState() == 2 && a[5].GetState() == 2 && a[8].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(325, 200, 325, 350);
break;
}

//Top left to bottom right diagonal
else if (a[0].GetState() == 2 && a[4].GetState() == 2 && a[8].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(200, 200, 350, 350);
break;
}

//Top right to bottom left diagonal
else if (a[2].GetState() == 2 && a[4].GetState() == 2 && a[6].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(350, 200, 200, 350);
break;
}

//Top horizontal
else if (a[0].GetState() == 2 && a[1].GetState() == 2 && a[2].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(200, 225, 350, 225);
break;
}

//Middle horizontal
else if (a[3].GetState() == 2 && a[4].GetState() == 2 && a[5].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(200, 275, 350, 275);
break;
}

//Down horizontal
else if (a[6].GetState() == 2 && a[7].GetState() == 2 && a[8].GetState() == 2) {
outtextxy(360, 135, "Kaata Wins!!!!");
setcolor(CYAN);
line(200, 325, 350, 325);
break;
}

//Draw
else if (a[0].GetOccuState() == true && a[1].GetOccuState() == true && a[2].GetOccuState() == true && a[3].GetOccuState() == true && a[4].GetOccuState() == true && a[5].GetOccuState() == true && a[6].GetOccuState() == true && a[7].GetOccuState() == true && a[8].GetOccuState() == true) {
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
Play.SetMessage("PLAY");
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
