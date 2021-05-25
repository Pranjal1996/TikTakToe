#include<iostream>
#include<graphics.h>
using namespace std;

int x = 0;
int y = 0;

class Block{

	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

public:

	void SetValues(int a, int b, int c, int d){
		x1 = a;
		x2 = b;
		y1 = c;
		y2 = d;

	}

	void PrintBlock(){
		setcolor(WHITE);
		rectangle(x1, y1, x2, y2);
	}

	bool BlockClick(int a, int b){

		if (a > x1 && a < x2 && b > y1 && b < y2){
			return true;
		}
		else{
	return false;
		}
		}

	void DrawCircle(){
		circle((x1+x2)/2, (y1+y2)/2, 24);
	}

	void DrawKaata(){
		line(x1, y1, x2, y2);
		line(x1, y2, x2, y1);
	}

	bool TakeAction(int a){
		if(a==true){
			DrawCircle();
			return true;
		}
		else{
			DrawKaata();
			return false;
		}
	}

};

int main(){

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int player = 0;

	Block a1, a2, a3, b1, b2, b3, c1, c2, c3;

a1.SetValues(200, 250, 200, 250);
a2.SetValues(250, 300, 200, 250);
a3.SetValues(300, 350, 200, 250);
b1.SetValues(200, 250, 250, 300);
b2.SetValues(250, 300, 250, 300);
b3.SetValues(300, 350, 250, 300);
c1.SetValues(200, 250, 300, 350);
c2.SetValues(250, 300, 300, 350);
c3.SetValues(300, 350, 300, 350);

a1.PrintBlock();
a2.PrintBlock();
a3.PrintBlock();
b1.PrintBlock();
b2.PrintBlock();
b3.PrintBlock();
c1.PrintBlock();
c2.PrintBlock();
c3.PrintBlock();

for(int i = 0; i>=0; i++){


	while (!ismouseclick(WM_LBUTTONDOWN)){
		delay(500);
	}

		getmouseclick(WM_LBUTTONDOWN,x,y);
		//cout << "x is "<<x<<endl;
		//cout << "y is "<<y<<endl;

		if (a1.BlockClick(x, y)){
			a1.TakeAction(player);
			player = !player;
		}

		if (a2.BlockClick(x, y)){
			a2.TakeAction(player);
			player = !player;
		}

		if (a3.BlockClick(x, y)){
			a3.TakeAction(player);
			player = !player;
		}

		if (b1.BlockClick(x, y)){
			b1.TakeAction(player);
			player = !player;
		}

		if (b2.BlockClick(x, y)){
			b2.TakeAction(player);
			player = !player;
		}

		if (b3.BlockClick(x, y)){
			b3.TakeAction(player);
			player = !player;
		}

		if (c1.BlockClick(x, y)){
			c1.TakeAction(player);
			player = !player;
		}

		if (c2.BlockClick(x, y)){
			c2.TakeAction(player);
			player = !player;
		}

		if (c3.BlockClick(x, y)){
			c3.TakeAction(player);
			player = !player;
		}

}

getch();
closegraph();
return 0;

}
