
#include "Block.h"
#include<iostream>
#include<graphics.h>
using namespace std;

int x = 0;
int y = 0;

int player = 0;
bool validTurn = false;

class PlayButton{
	int x1;
	int x2;
	int y1;
	int y2;

public:

	//Setting the values for rectangle
	void SetButton(int a, int b, int c, int d){
		x1 = a;
		x2 = b;
		y1 = c;
		y2 = d;
	}

	//Printing from the given values
	void PrintButton(){
			setcolor(WHITE);
			rectangle(x1, y1, x2, y2);
			}

	//If Play Button is clicked
	bool ClickButton(int a, int b){
			if (a >= x1 && a <= x2 && b >= y1 && b <= y2){
			return true;
			}
			else{
		return false;
			}
			}

};

bool TurnTeller(int a){

	//If Kaata is played
	if (a == true){
		delay(50);
		settextstyle(4, 4, 1);
		outtextxy(360, 135, "Gola's   Turn");
		return true;
	}

	//If Gola is played
	else{
		delay(50);
		settextstyle(4, 4, 1);
		outtextxy(360, 135, "Kaata's Turn");
		return false;
	}
}

//Function for printing TicTacToe box, telling the turn and breaking at winning
void PlayGame(){

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
	for(int j = 0; j< 9;j++){
	a[j].PrintBlock();
	}

	//Infinite loop
	while(true){

	while (!ismouseclick(WM_LBUTTONDOWN)){
	delay(500);
	}

	validTurn = false;

	getmouseclick(WM_LBUTTONDOWN,x,y);
	//cout << "x is "<<x<<endl;
	//cout << "y is "<<y<<endl;

	//If block is clicked
	for(int j = 0; j< 9;j++){
	if (a[j].BlockClick(x, y)){

	//Take action. In other words, print Kaata or Gola
	validTurn = a[j].TakeAction(player);

	}
	}

//Gola Winning
	if(a[0].GetState() == 1 && a[3].GetState() == 1 && a[6].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	else if(a[1].GetState() == 1 && a[4].GetState() == 1 && a[7].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	else if(a[2].GetState() == 1 && a[4].GetState() == 1 && a[8].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	else if(a[0].GetState() == 1 && a[4].GetState() == 1 && a[8].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	else if(a[2].GetState() == 1 && a[4].GetState() == 1 && a[6].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	else if(a[0].GetState() == 1 && a[1].GetState() == 1 && a[2].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	else if(a[3].GetState() == 1 && a[4].GetState() == 1 && a[5].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	else if(a[6].GetState() == 1 && a[7].GetState() == 1 && a[8].GetState() == 1){
		outtextxy(360, 135, "Gola Wins!!!!");
		break;
	}

	//Kaata Winning
		if(a[0].GetState() == 2 && a[3].GetState() == 2 && a[6].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

		else if(a[1].GetState() == 2 && a[4].GetState() == 2 && a[7].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

		else if(a[2].GetState() == 2 && a[4].GetState() == 2 && a[8].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

		else if(a[0].GetState() == 2 && a[4].GetState() == 2 && a[8].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

		else if(a[2].GetState() == 2 && a[4].GetState() == 2 && a[6].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

		else if(a[0].GetState() == 2 && a[1].GetState() == 2 && a[2].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

		else if(a[3].GetState() == 2 && a[4].GetState() == 2 && a[5].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

		else if(a[6].GetState() == 2 && a[7].GetState() == 2 && a[8].GetState() == 2){
			outtextxy(360, 135, "Kaata Wins!!!!");
			break;
		}

	if(validTurn){
	player = !player;
	}

	TurnTeller(player);

	}

}

int main(){

int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);

//Defining a variable Play
PlayButton Play;

//Setting the values for Play button
Play.SetButton(220, 325, 65, 100);
//Printing from set values
Play.PrintButton();

//Prints PLAY on the Play button
settextstyle(10, 4, 1);
outtextxy(293, 94, "PLAY");
//Prints "Designed by The Narayan Brothers" at downmost right
settextstyle(10, 4, 1);
outtextxy(630, 470, "Designed by The Narayan Brothers");
//Prints "Welcome to The KaataGola Game" on the middle at the top
settextstyle(10, 4, 1);
outtextxy(480, 30, "Welcome To The KaataGola Game!!!");

PlayGame();

getch();
closegraph();
return 0;
}
