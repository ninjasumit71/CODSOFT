#include <iostream>
#include <conio.h>
const int SIZE = 3;
using namespace std;

void printBoard(char arr[][SIZE]){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

bool isWin(char arr[][SIZE], char ch){
	int count;
	for (int i = 0; i < SIZE; i++){
		count = 0;
		for (int j = 0; j < SIZE; j++){
			if (arr[i][j] == ch)
				count++;
		}
		if (count == SIZE)
			return true;
	}
	for (int i = 0; i < SIZE; i++){
		count = 0;
		for (int j = 0; j < SIZE; j++){
			if (arr[j][i] == ch)
				count++;
		}
		if (count == SIZE)
			return true;
	}
	count = 0;
	for (int i = 0; i < SIZE; i++){
		if (arr[i][i] == ch)
			count++;
	}
	if (count == SIZE)
		return true;
	count = 0;
	for (int i = 0, j = SIZE - 1; i < SIZE; i++, j--){
		if (arr[i][j] == ch)
			count++;
	}
	if (count == SIZE)
		return true;
	return false;
}

bool isDraw(char arr[][SIZE]){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if (arr[i][j] == '-')
				return false;
		}
	}
		return true;
}

int main(){
	char board[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			board[i][j] = '-';
		}
	}
	bool isGameEnd = false;
	int row, col, playerTurn = 1;
	char player;
	while (!isGameEnd){
		system("cls");
		printBoard(board);
		if (playerTurn == 1){
			player = 'X';
			playerTurn = 2;
		}
		else if (playerTurn == 2){
			player = 'O';
			playerTurn = 1;
		}
		do{
			cout << "Player " << player << " Turn" << endl;
			cout << "Enter Row: "; cin >> row;
			cout << "Enter Col: "; cin >> col;
			row--;
			col--;
		} while (!(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '-'));
		board[row][col] = player;
		if (isWin(board, player)){
			system("cls");
			printBoard(board);
			cout << "Player " << player << " Wins" << endl;
			isGameEnd = true;
		}
		else if (isDraw(board)){
			system("cls");
			printBoard(board);
			cout << "Game Draw" << endl;
			isGameEnd = true;
		}
	}
	system("pause");
	return (0);
}