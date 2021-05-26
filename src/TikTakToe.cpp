#include "Block.h"
#include<iostream>
#include<graphics.h>
using namespace std;

int x = 0;
int y = 0;


bool TurnTeller(int a){
if (a == true){
delay(50);
settextstyle(4, 4, 1);
outtextxy(360, 135, "Gola's   Turn");
return true;
}
else{
delay(50);
settextstyle(4, 4, 1);
outtextxy(360, 135, "Kaata's Turn");
return false;
}
}

int main(){

int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);

int player = 0;
bool validTurn = false;

Block a[9];

a[0].SetValues(200, 250, 200, 250);
a[1].SetValues(250, 300, 200, 250);
a[2].SetValues(300, 350, 200, 250);
a[3].SetValues(200, 250, 250, 300);
a[4].SetValues(250, 300, 250, 300);
a[5].SetValues(300, 350, 250, 300);
a[6].SetValues(200, 250, 300, 350);
a[7].SetValues(250, 300, 300, 350);
a[8].SetValues(300, 350, 300, 350);

for(int j = 0; j< 9;j++){
a[j].PrintBlock();
}

settextstyle(10, 4, 1);
outtextxy(630, 470, "Directed by The Narayan Brothers");
settextstyle(10, 4, 1);
outtextxy(480, 30, "Welcome To The KaataGola Game!!!");
settextstyle(4, 4, 1);
outtextxy(360, 135, "Kaata's Turn");

while(true){

while (!ismouseclick(WM_LBUTTONDOWN)){
delay(500);
}

validTurn = false;

getmouseclick(WM_LBUTTONDOWN,x,y);
//cout << "x is "<<x<<endl;
//cout << "y is "<<y<<endl;

for(int j = 0; j< 9;j++){
if (a[j].BlockClick(x, y)){
validTurn = a[j].TakeAction(player);

}
}

if(a[0].GetState() == 1 && a[3].GetState() == 1 && a[6].GetState() == 1){
	outtextxy(360, 135, "Gola Wins!!!!");
	break;
}

if(validTurn){
player = !player;
}

TurnTeller(player);

}

getch();
closegraph();
return 0;

}
