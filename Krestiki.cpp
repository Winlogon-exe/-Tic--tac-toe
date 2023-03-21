#include <iostream>
#include<vector>
#include<iomanip>
using namespace std;
const int rows = 3;
const int cols = 3;

void PrintArray(char arr[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout <<"\t" << arr[i][j];
		}
		cout << endl;
	}
}




int CheckWin(char arr[rows][cols], char player)
{
	// 0 - не завершена 
	// 1 - победа игрока 1
	// 2 - победа игрока 2
	// 3 - ничья
	int i = 0;
	
	do {
		PrintArray(arr);
		char symbol;
		if (player == 'X') {
			symbol = 'O';
			player = 'O';
		}
		else {
			symbol = 'X';
			player = 'X';
		}
		cout << "Ходит игрок " << player << endl;
		int choice;
		cin >> choice;
		if (choice == 1 && arr[0][0] == '1')
			arr[0][0] = symbol;
		else if (choice == 2 && arr[0][1] == '2')
			arr[0][1] = symbol;
		else if (choice == 3 && arr[0][2] == '3')
			arr[0][2] = symbol;
		else if (choice == 4 && arr[1][0] == '4')
			arr[1][0] = symbol;
		else if (choice == 5 && arr[1][1] == '5')
			arr[1][1] = symbol;
		else if (choice == 6 && arr[1][2] == '6')
			arr[1][2] = symbol;
		else if (choice == 7 && arr[2][0] == '7')
			arr[2][0] = symbol;
		else if (choice == 8 && arr[2][1] == '8')
			arr[2][1] = symbol;
		else if (choice == 9 && arr[2][2] == '9')
			arr[2][2] = symbol;
		else {
			cout << "Некорректный ход. Попробуйте еще раз." << endl;
			continue;
		}
		if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
		{
			i = (arr[0][0] == symbol ? 1 : 2);
			system("cls");
			cout << "ПОБЕДИЛ ИГРОК " << player << "!" << endl;
			PrintArray(arr);
		}
		else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
		{
			i = (arr[1][0] == symbol ? 1 : 2);
			system("cls");
			PrintArray(arr);
			cout << "ПОБЕДИЛ ИГРОК " << player << "!" << endl;
		}
		else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
		{
			i = (arr[2][0] == symbol ? 1 : 2);
			system("cls");
			PrintArray(arr);
			cout << "ПОБЕДИЛ ИГРОК " << player << "!" << endl;
		}
		else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
		{
			i = (arr[0][0] == symbol ? 1 : 2);
			system("cls");
			PrintArray(arr);
			cout << "ПОБЕДИЛ ИГРОК " << player << "!" << endl;
			return i;
		}
		else if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])
		{
			i = (arr[0][1] == symbol ? 1 : 2);
			system("cls");
			PrintArray(arr);
			cout << "ПОБЕДИЛ ИГРОК " << player << "!\n" << endl;
			return i;
		}
		else if (arr[0][2] == arr[2][2] && arr[1][2] == arr[2][2])
		{
			i = (arr[0][2] == symbol ? 1 : 2);
			system("cls");
			PrintArray(arr);
			cout << "ПОБЕДИЛ ИГРОК " << player << "!\n" << endl;
			return i;
		}
		else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
		{
			i = (arr[0][0] == symbol ? 1 : 2);
			system("cls");
			PrintArray(arr);
			cout << "ПОБЕДИЛ ИГРОК " << player << "!\n" << endl;
			return i;
		}
		else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
		{
			i = (arr[0][2] == symbol ? 1 : 2);
			system("cls");
			PrintArray(arr);
			cout << "ПОБЕДИЛ ИГРОК " << player << "!\n" << endl;
			return i;
		}
	} while (i == 0);
	

	return i;
}




int main() {

	system("cls");
	setlocale(LC_ALL, "RUS");
	int side; char player;
	char arr[rows][cols] = {
		{'1','2','3'},
		{'4','5','6',},
		{'7','8','9',}
	};
	cout << "\t" << "\t" << "\t" << "КРЕСТИКИ, НОЛИКИ" << endl << endl;
	cout << "Выберите сторону " << endl << "1.Крестики" << endl << "2.Нолики" << endl; cin >> side;
	if (side == 1)
	{
		player = 'X';
	}
	else
	{
		player = 'O';
	}
	if (side == 1)
	{
		system("cls");
		cout << "Вы играете за X\n";
		cout << endl << "Игра началась!\n\n" << endl;
		int result = CheckWin(arr,player);
		if (result != 1 && result != 2)
			cout << "НИЧЬЯ" << endl;
	}
	else if (side == 2)
	{
		system("cls");
		cout << "Вы играете за 0\n\n";
		cout << endl << "Игра началась!\n\n" << endl;
		int result = CheckWin(arr, player);
		if (result != 1 && result != 2)
			cout << "НИЧЬЯ" << endl;
	}
	else
		cout << "Некорректный ввод" << endl;
	
	

	
	return 0;
}
