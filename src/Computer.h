#pragma once
#include "Block.h"
#include<vector>
using namespace std;

class Computer{
	int level = 0;
	vector<int> matrix; // 0 for empty 1 for gola 2 for kaata
	int player = 0; //computer player is 1 or 2

	public:

	void SetupLevel(int lvl, int plr);
	vector<int> GetEmptyIndices(vector<int> v);
	int GetRandomEmptyBox();
	int CheckWinScore(vector<int> v,int pl);
	int MediumLevelMove();
	int MinMaxScoring(vector<int> Board,int depth,bool maxScore);
	int MinMaxAI();
	int GetNextMoveIndex(Block a[9]);
};