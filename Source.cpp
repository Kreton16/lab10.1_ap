#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* t) // ��������� ����� � �������� �����
{
	ofstream fout(t); // ������� ���� ��� ������
	char ch; // ������� ����������� � �� ������������ ��������
	string s; // �������� ������������ �����
	do
	{
		cin.get(); // ������� ����� ��������� � ��� �� ���� �������
		cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
		cout << "enter line: "; getline(cin, s); // ����� �����
		fout << s << endl; // �������� ���� � ����
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
int ProcessTXT1(char* t) // ���������� �������� ������� ������� + - =
{
	ifstream fin(t); // ������� ���� ��� ����������
	string s; // ���������� �����
	char k = s[0];// �������� ������� ������� + - =
	while (getline(fin, s)) // ���� ����� ��������� �����
	{ // ������� ���� � ���������� ������� + - =
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
	char t[100]; // ��'� ������� �����
	cout << "enter file name 1: "; cin >> t;
	CreateTXT(t); // ����� ����� ����� � ���������
	if(ProcessTXT1(t))
	cout << "String contained minimum 1 group of 'aa' or 'bb' or 'cc'" << endl;
	else
		cout << "String does not contain a groups of 'aa' or 'bb' or 'cc'" << endl;
	return 0;
}