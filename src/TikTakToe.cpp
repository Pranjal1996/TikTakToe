#include "Block.h"
#include<graphics.h>
using namespace std;

int x = 0;
int y = 0;


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
for(int i = 0; i>=0; i++){


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
		if(validTurn){
			player = !player;
		}

}

getch();
closegraph();
return 0;

}
