#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void addWord(map<string, string>& dict) {
	string word, translation;
	cout << "Введите слово на английском: ";
	cin >> word;
	cout << "Введите перевод: ";
	cin >> translation;
	dict[word] = translation;
	cout << "Слово добавлено \n";
}

void deleteWord(map<string, string>& dict) {
	string word;
	cout << "Введите слово для того чтобы удалить: ";
	cin >> word;
	auto it = dict.find(word);
	if (it != dict.end()) {
		dict.erase(it);
		cout << "Слово удалено\n";
	}
	else {
		cout << "Слово не найдено\n";
	}
}

void saveWord(map<string, string>& dict) {
	ofstream file("dictionary.txt");
	if (file.is_open()) {
		for (const auto& entry : dict) {
			file << entry.first << " - " << entry.second << endl;
		}
		file.close();
		cout << "Словарь сохранено в файле\n";
	}
	else {
		cout << "Ошибка при открытии файла\n";
	}
}

void searchWord(map<string, string>& dict) {
	string s;
	cout << "Введите слово для поиска: ";
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
	cout << "Словарь:\n";
	for (const auto& entry : dict) {
		cout << entry.first << " - " << entry.second << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	map<string, string> dict;
	dict.insert(make_pair("dog", "Собака"));
	dict.insert(make_pair("cat", "Кошка"));
	dict.insert(make_pair("parrot", "Попугай"));

	int choice;
	do {
		cout << "\n Меню: \n";
		cout << "1. Добавить слово \n";
		cout << "2. Удалить слово \n";
		cout << "3. Найти слово \n";
		cout << "4. Сохранить в файлах \n";
		cout << "5. Показать словарь \n";
		cout << "0. Выйти \n";
		cout << "Выберите действие: ";
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
			cout << "Выход \n";
			break;
		default:
			cout << "Error \n";
		}
	} while (choice != 0);

	return 0;


}