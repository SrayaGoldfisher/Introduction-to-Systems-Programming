#include <iostream>
using namespace std;

double large_of_average (double a[], int size);
int sum_negative (int arr[], int size);
int distance (int arr[], int size);
bool symmetry (int matrix[][3], int size);

void main () {
	int option, num, size;
	double doubleNum;
	cout<< "Menu:\n0. Exit\n1. Display a percent of elements bigger on average \n2. Display a sum of negative elements\n3. Difference between the largest and smallest elements in an array\n4. Is matrix symmetric\n";
	do {
		cout<<"Enter your choice (0-5):"<<endl;
		cin>> option;
		if(option==1) {
			int size;
			cin>>size;
			double* a = new double[size];
			for(int i=0; i<size; i++) {
				cin>>a[i];
			}
			double percent = large_of_average (a, size);
		}
		if(option==2) {
			int size;
			cin>>size;
			int* arr = new int[size];
			for(int i=0; i<size; i++) {
				cin>>arr[i];
			}
			int sum = sum_negative (arr, size);
		}
		if(option==3) {
			int size;
			cin>>size;
			int* arr = new int[size];
			for(int i=0; i<size; i++) {
				cin>>arr[i];
			}
			int dis = distance (arr, size);
		}
		if(option == 4) {
			int matrix[3][3];
			int size;
			cin >> size;
			for(int i = 0; i < 3; i ++)
				for(int j = 0; j < 3; j ++)
					cin >> matrix[i][j];
			bool result = symmetry (matrix, size);
		}
	}
	while(option != 0);
}

double large_of_average (double a[], int size) {
	double* arr = new double[size];
	double sum = 0;
	double average = 0;
	double percent = 0;
	int x = 0;
	int flag = 0;
	double sizeD = size;
	arr = a;
	for(int i = 0; i < size; i ++) {
		sum += a[i];
	}
	average = sum / size;
	for(int j = 0; j < size; j ++) {
		if(a[j] > average) {
			x ++;
		}
	}
	percent = x/sizeD;
	delete []arr;
	return percent;
}

int sum_negative (int arr[], int size) {
	int* arrTemp = new int[size];
	int sum = 0;
	arrTemp = arr;
	for(int i = 0; i < size; i ++) {
		if(arrTemp[i] < 0) {
			sum += arrTemp[i];
		}
	}
	delete []arrTemp;
	return sum;
}

int distance (int arr[], int size) {
	int* arrTemp = new int[size];
	arrTemp = arr;
	int distance, max, min;
	if(size==0)
		return 0;
	else {
		min=arrTemp[0];
		max=arrTemp[0];
	}
	for(int i=0; i<size; i++) {
		if(arrTemp[i]<min)
			min=arrTemp[i];
		if(arrTemp[i]>max)
			max = arrTemp[i];
	}
	distance = max - min;
	delete []arrTemp;
	return distance;
}

bool symmetry (int matrix[][3], int size) {
	int flag = 0;
	if(size != 3)
		return false;
	for(int i = 0; i < size; i ++) {
		for(int j = 0; j < size; j ++) {
			if (matrix[i][j] != matrix[j][i])
				flag = 1;
		}
	}
	/*for(int i = 0; i < 3; i ++)
		delete[] matrix[i];
	delete[] matrix;
	*/
	if (flag == 0)
		return true;
	else
		return false;
}