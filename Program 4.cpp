#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int num_of_app(string file_name,string word);
string long_word(string file_name);
void sum_even(int matrix[][5], int row, int column, int *num_of_rows, int * num_of_col);

void main() {
	int option;
	string file_name, word;
	cout << "Menu:\n0. Exit\n1. Display a num of appearances string in file \n2. Display a longest word in the file \n3. Display a number of even rows and columns. \n";
	do { 
		cout << "Enter your choice (0-3):" << endl;
		cin >> option;
		
		if(option == 1) {
			cin >> file_name >> word;
			num_of_app(file_name, word);
		}

		if(option == 2) {
			cin >> file_name;
			long_word(file_name);
		}

		if(option == 3) {
			int size = 5;
			int matrix[5][5];
			int sumRow = 0;
			int sumCol = 0;
			int * num_of_col = new int;
			int * num_of_row = new int;
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					cin >> matrix[i][j];
			sum_even(matrix, size, size, num_of_row, num_of_col);
			cout << "num of even rows= " << * num_of_row << endl << endl << "num of even column=" << * num_of_col << endl;
		}
	}
	while(option != 0) ;
}

//A function that receives a file name and a word from the user. The function counts how many times the word appears in the file
int num_of_app(string file_name, string word) {
	int sum = 0 ;
	string readWord;
	ifstream file;
	file.open(file_name);
	if(!file.is_open())
		return 0;
    	while(file >> readWord) {
		if(word == readWord)
			sum++;
    	}
	file.close();
	return sum;
}

//A function that receives a file name from the user. The function will return the longest word in the file
string long_word(string file_name) {
	string long_word, readWord;
	ifstream file;
	file.open(file_name);
	if(!file.is_open()) 
		return "";
    	while(file >> readWord) {
		if(readWord.length() >= long_word.length())
			long_word = readWord;
    	}
	return long_word;
}

//Function that receives as a parameter, an array of rows*columns of integers
//The function finds the number of rows that have an even sum, and the number of columns that have an even sum
//The main function in the program picks up the array from the user, and prints an appropriate message
void sum_even(int matrix[][5], int row, int column, int *num_of_rows, int * num_of_col) {
	int sumRow = 0; 
	int countRow = 0; 
	int countCol = 0;
	int sumCol = 0;
	int size = 5;
	for(int i = 0; i < size; i++) {
		sumRow = 0; 
		sumCol = 0;
		for(int j = 0; j < size; j++) {
			sumRow = sumRow + matrix[i][j];
			sumCol = sumCol + matrix[j][i];
		}
		if((sumRow % 2) == 0) {
			countRow++;
		}
		if((sumCol % 2) == 0) {
			countCol++;
		}
	}
	*num_of_rows = countRow;
	*num_of_col = countCol;
}
