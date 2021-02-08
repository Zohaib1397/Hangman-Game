#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
string words[5] = { "WORD","SENTENCE","WINDOWS","DEBUG","GIT" };
char arr[26] = { 'A','B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
void Body(int size, char arr[], int rand);
bool WIN = true;
bool Loose = true;
char Charact;
int counter = 4;
int main() {
	srand(time(NULL));
	int random = rand() % 5;
	int underscore_size = size(words[random]);
	char* key = new char[underscore_size];
	for (int i = 0; i < underscore_size; i++) {
		key[i] = '_';
	}
	while (Loose==true&&WIN==true) {
		if (counter ==1) {
			Loose = false;
		}
		Body(underscore_size, key,random);
	}
	if (!Loose) {
		cout << "----------You Loose---------\n";
	}
	system("pause");
	return 0;
}
void Body(int size,char array[], int rand) {
	system("cls");
	cout << "\t-------You have " << counter << " Choices--------";
	cout << "\n\n";
	int checker = 0;
	for (int i = 0; i < size; i++) {
		cout << "\t_"<<array[i]<<"_";
	}
	cout << "\n\n";
	for (int i = 0; i < 26; i++) {
		cout << "   " <<arr[i] ;
	}
	cout << "\n";
	cout << "Enter Character: ";
	cin >> Charact;
	Charact = toupper(Charact);
	for (int i = 0; i < 26; i++) {
		if (Charact == arr[i]) {
			arr[i] = '-';
		}
	}
	for (int i = 0; i < size; i++) {
		if (Charact == words[rand][i]) {
			array[i] = Charact;
			checker = 1;
		}
	}
	int add = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] == '_') {
			add++;
		}
	}
	if (add == 0) {
		system("cls");
		cout << "\t-------You Won--------";
		cout << "\n\n";
		for (int i = 0; i < size; i++) {
			cout << "\t_" << array[i] << "_";
		}
		cout << "\n\n";
		for (int i = 0; i < 26; i++) {
			cout << "   " << arr[i];
		}
		cout << "\n";
		WIN = false;

	}
	if (checker == 0) {
		counter--;
	}
}