#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* t) // створення файлу з введених рядків
{
	ofstream fout(t); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	do
	{
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		fout << s << endl; // записали його у файл
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
int ProcessTXT1(char* t) // обчислення загальної кількості символів + - =
{
	ifstream fin(t); // відкрили файл для зчитування
	string s; // прочитаний рядок
	char k = s[0];// загальна кількість символів + - =
	while (getline(fin, s)) // поки можна прочитати рядок
	{ // скануємо його і обчислюємо кількість + - =
		for (unsigned i = 1; i < s.length(); i++)
			if ((s[i] == 'a' && s[i] == k) || (s[i] == 'b' && s[i] == k) || (s[i] == 'c' && s[i] == k))
				return true;
			else
				k = s[i];
	}
	return false;
}

int main()
{
	// text files
	char t[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> t;
	CreateTXT(t); // ввели рядки файлу з клавіатури
	if(ProcessTXT1(t))
	cout << "String contained minimum 1 group of 'aa' or 'bb' or 'cc'" << endl;
	else
		cout << "String does not contain a groups of 'aa' or 'bb' or 'cc'" << endl;
	return 0;
}