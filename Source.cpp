// Крестики нолики
#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
// '.' - пустая клетка
// 'X' -  крестик
// '0' - нолик

char field[ROWS][COLS] = {
	{ '.', '.', '.' },
	{ '.', '.', '.' },
	{ '.', '.', '.' },
};

// 1 - крестики
// 2 - нолики
int turn = 1;

void print_field();
void save();
void load();
bool is_exist();
void turn_X();
void turn_0();
bool checkX(int row, int col);
bool check0(int row, int col);

int main() {
	setlocale(LC_ALL, "Russian");
	
	try {
		while (true) {
			if (turn == 1) {
				print_field();
				turn_X();
			}
			else
				if (turn == 2) {
				print_field();
				turn_0();
			}
		}
	}
	catch (const char ex) {
		system("cls");
		print_field();
		switch (ex) {
			case 'X': cout << "Победили крестики!\n"; break;
			case'0': cout << "Победили нолики!\n"; break;
		}
	}


	return 0;
}
// Проверка хода крестиков
bool checkX(int row, int col) {
	// Главная диагональ
	if (row == col) {
		string tmp;
		for (int i = 0; i < ROWS; i++)
			tmp += field[i][i];
		if (tmp == string(ROWS, 'X'))
			return true;
	}
	// Побочная диагональ
	if (row + col == ROWS - 1) {
		string tmp;
		for (int i = 0, j = 2; i < ROWS; i++, j--)
			tmp += field[i][j];
		if (tmp == string(ROWS, 'X'))
			return true;
	}
	// Текущая колонка
		string tmp;
		for (int i = 0; i < ROWS; i++)
			tmp += field[i][col];
		if (tmp == string(ROWS, 'X'))
			return true;	
	// Текущий ряд
	if (field[row] == string(ROWS, 'X'))
		return true;

	return false;		
}
// Проверка хода ноликов
bool check0(int row, int col) {
	// Главная диагональ
	if (row == col) {
		string tmp;
		for (int i = 0; i < ROWS; i++)
			tmp += field[i][i];
		if (tmp == string(ROWS, '0'))
			return true;
	}
	// Побочная диагональ
	if (row + col == ROWS - 1) {
		string tmp;
		for (int i = 0, j = 2; i < ROWS; i++, j--)
			tmp += field[i][j];
		if (tmp == string(ROWS, '0'))
			return true;
	}
	// Текущая колонка
	string tmp;
	for (int i = 0; i < ROWS; i++)
		tmp += field[i][col];
	if (tmp == string(ROWS, '0'))
		return true;
	// Текущий ряд
	if (field[row] == string(ROWS, '0'))
		return true;

	return false;
}
void print_field() {
	cout << "Tic-tac-toe!\n";
	for (int i = 0; i < ROWS * 2 - 1; i++) {
		for (int j = 0; j < COLS * 2 - 1; j++)
			if (i % 2 == 0 && j % 2 == 0)
				cout << ' ' << field[i / 2][j / 2];
			else
				if (i % 2 != 0 && j % 2 != 0)
					cout << "-|";
				else
					if (j % 2 != 0)
						cout << " |";
					else
						cout << "--";
		if (i % 2 != 0)
			cout << "-";
		cout << endl;
	}
}
// Ход крестика
void turn_X() {
	int R, C;
	cout << "Ход крестика!\n";
	do {
		cout << "Введите ряд: ";
		cin >> R;
		if (R < 1 || R > ROWS)
			cout << "Выход за пределы поля.\n";
	} while (R < 1 || R > ROWS);

	do {
		cout << "Введите ряд: ";
		cin >> C;
		if (C < 1 || C > COLS)
			cout << "Выход за пределы поля.\n";
	} while (C < 1 || C > COLS);
	R--; C--;
	field[R][C] = 'X';
	if (checkX(R, C))
		throw 'X';
	turn = 2;
	system("cls");
}
// Ход нолика
void turn_0() {
	int R, C;
	cout << "Ход нолика!\n";
	do {
		cout << "Введите ряд: ";
		cin >> R;
		if (R < 1 || R > ROWS)
			cout << "Выход за пределы поля.\n";
	} while (R < 1 || R > ROWS);

	do {
		cout << "Введите ряд: ";
		cin >> C;
		if (C < 1 || C > COLS)
			cout << "Выход за пределы поля.\n";
	} while (C < 1 || C > COLS);
	R--; C--;
	field[R][C] = '0';
	if (check0(R, C))
		throw '0';
	turn = 1;
	system("cls");
}