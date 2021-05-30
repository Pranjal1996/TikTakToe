#include "Computer.h"
#include<vector>
using namespace std;

void Computer::SetupLevel(int lvl, int plr){
		level = lvl;
		player = plr;
		for(int i = 0; i < 9; i++){
			matrix.push_back(0);
		}
	}

vector<int> Computer::GetEmptyIndices(vector<int> Board){
	vector<int> EmptyIndices = {};
	for(int i=0;i<9;i++){
		if(Board[i]==0){
			EmptyIndices.push_back(i);
		}
	}
	return EmptyIndices;
}

int Computer::GetRandomEmptyBox(){
	std::vector<int> EmptyIndices = GetEmptyIndices(matrix);
	return EmptyIndices[rand()%EmptyIndices.size()];
}

int Computer::CheckWinScore(vector<int> Board,int pl){
	for(int i = 1;i <3;i++){
		if( ((Board[0]==Board[1])&&(Board[1]==Board[2]))||
			((Board[0]==Board[3])&&(Board[3]==Board[6]))||
			((Board[0]==Board[4])&&(Board[4]==Board[8]))||
			((Board[1]==Board[4])&&(Board[4]==Board[7]))||
			((Board[2]==Board[5])&&(Board[5]==Board[8]))||
			((Board[2]==Board[4])&&(Board[4]==Board[7]))||
			((Board[3]==Board[4])&&(Board[4]==Board[5]))||
			((Board[6]==Board[7])&&(Board[7]==Board[8]))){
			if(i==pl){
				return 10;
			}
			else{
				return -10;
			}
		}
	}
	return 0;
}

int Computer::MediumLevelMove(){
	std::vector<int> PossibleMoves = GetEmptyIndices(matrix);
	vector<int> TmpMatrix = matrix;
	for(int i = 0; i < PossibleMoves.size();i++){
		TmpMatrix = matrix;
		TmpMatrix[PossibleMoves[i]] = player;
		if(CheckWinScore(TmpMatrix,player)==10){
			return PossibleMoves[i];
		}
	}
	int opponentPlayer = 3 - player;
	for(int i = 0; i < PossibleMoves.size();i++){
		TmpMatrix = matrix;
		TmpMatrix[PossibleMoves[i]] = opponentPlayer;
		if(CheckWinScore(TmpMatrix,player)== -10){
			return PossibleMoves[i];
		}
	}
	return GetRandomEmptyBox();
}

int Computer::MinMaxScoring(vector<int> Board,int depth,bool maxScore){
	vector<int> PossibleMoves = GetEmptyIndices(Board);
	vector<int> TmpBoard = Board;
	int BestScore,curr_score;
	if(CheckWinScore(Board,player)!=0){
		return CheckWinScore(Board,player) - depth;
	}
	if(PossibleMoves.empty()){
		return 0;
	}
	if(maxScore){
		BestScore = - INT_MAX;
		for(int i=0;i < PossibleMoves.size();i++){
			TmpBoard = Board;
			TmpBoard[PossibleMoves[i]]=player;
			curr_score = MinMaxScoring(TmpBoard,depth+1,false);
			if(curr_score > BestScore){
				BestScore = curr_score;
			}
		}
	}
	else{
		BestScore = INT_MAX;
		int opponentPlayer = 3 - player;
		for(int i=0;i < PossibleMoves.size();i++){
			TmpBoard = Board;
			TmpBoard[PossibleMoves[i]]=opponentPlayer;
			curr_score = MinMaxScoring(TmpBoard,depth+1,true);
			if(curr_score < BestScore){
				BestScore = curr_score;
			}	
		}
	}
	return BestScore;
}

int Computer::MinMaxAI(){
	vector<int> PossibleMoves = GetEmptyIndices(matrix);
	vector<int> TmpBoard = matrix;
	int bestscore= -INT_MAX,move=-1,curr_score;
	for(int i= 0; i < PossibleMoves.size();i++){
		TmpBoard = matrix;
		TmpBoard[PossibleMoves[i]]=player;
		curr_score = MinMaxScoring(TmpBoard,0,false);
		if(curr_score > bestscore){
			move = PossibleMoves[i];
			bestscore = curr_score;
		}
	}

	return move;
}

int Computer::GetNextMoveIndex(Block a[9]){
	for(int i=0;i<9;i++){
		matrix[i] = a[i].GetState();
	}
	if(level == 0){
		return GetRandomEmptyBox();
	}
	else if(level == 1){
		return MediumLevelMove();
	}
	else if(level == 2){
		return MinMaxAI();
	}
}
