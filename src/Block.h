#include<iostream>
#include<graphics.h>

class Block{

	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	bool occupied = false;

public:

	void SetValues(int a, int b, int c, int d){
		x1 = a;
		x2 = b;
		y1 = c;
		y2 = d;
		occupied = false;

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
		occupied = true;
	}

	void DrawKaata(){
		line(x1, y1, x2, y2);
		line(x1, y2, x2, y1);
		occupied = true;
	}

	bool TakeAction(int a){
		if(!occupied){
			if(a==true){
				DrawCircle();
			}
			else{
				DrawKaata();
			}
			return true;
		}
		return false;
	}

};
