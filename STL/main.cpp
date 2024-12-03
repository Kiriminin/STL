#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void addWord(map<string, string>& dict) {
	string word, translation;
	cout << "������� ����� �� ����������: ";
	cin >> word;
	cout << "������� �������: ";
	cin >> translation;
	dict[word] = translation;
	cout << "����� ��������� \n";
}

void deleteWord(map<string, string>& dict) {
	string word;
	cout << "������� ����� ��� ���� ����� �������: ";
	cin >> word;
	auto it = dict.find(word);
	if (it != dict.end()) {
		dict.erase(it);
		cout << "����� �������\n";
	}
	else {
		cout << "����� �� �������\n";
	}
}

void saveWord(map<string, string>& dict) {
	ofstream file("dictionary.txt");
	if (file.is_open()) {
		for (const auto& entry : dict) {
			file << entry.first << " - " << entry.second << endl;
		}
		file.close();
		cout << "������� ��������� � �����\n";
	}
	else {
		cout << "������ ��� �������� �����\n";
	}
}

void searchWord(map<string, string>& dict) {
	string s;
	cout << "������� ����� ��� ������: ";
	cin >> s;
	auto ptrf = dict.find(s);
	if (ptrf != dict.end())
	{
		system("cls");
		system("color 0B");
		cout << ptrf->second << endl;
	}
	else
	{
		system("cls");
		system("color 0C");
	}
}

void displayDictionary(const map<string, string>& dict) {
	cout << "�������:\n";
	for (const auto& entry : dict) {
		cout << entry.first << " - " << entry.second << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	map<string, string> dict;
	dict.insert(make_pair("dog", "������"));
	dict.insert(make_pair("cat", "�����"));
	dict.insert(make_pair("parrot", "�������"));

	int choice;
	do {
		cout << "\n ����: \n";
		cout << "1. �������� ����� \n";
		cout << "2. ������� ����� \n";
		cout << "3. ����� ����� \n";
		cout << "4. ��������� � ������ \n";
		cout << "5. �������� ������� \n";
		cout << "0. ����� \n";
		cout << "�������� ��������: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addWord(dict);
			break;
		case 2:
			deleteWord(dict);
			break;
		case 3:
			searchWord(dict);
			break;
		case 4:
			saveWord(dict);
			break;
		case 5:
			displayDictionary(dict);
			break;
		case 0:
			cout << "����� \n";
			break;
		default:
			cout << "Error \n";
		}
	} while (choice != 0);

	return 0;


}