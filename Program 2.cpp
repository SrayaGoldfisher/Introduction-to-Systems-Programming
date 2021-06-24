#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define _USE_MATH_DEFINES  


void triangle1(int num);
void triangle2(int num);
int  digits_sum(int num);
void natural3nums(int num);
double sinus(double x);
int neastprime(int n);

void main () {
	int option, num;
	double doubleNum;
	cout<< "Menu:\n\n0. Exit\n1. Display triangle1\n2. Display triangle2\n3. sum of digits\n4. sum of 3 natural numbers\n5.sinus\n6.neastprime\n\n";
	do {
		cout<<"Enter your choice (0-6):"<<endl;
		cin>> option;

		if(option==1) {
			cin>>num;
			triangle1(num);
		}
		if(option==2) {
			cin>>num;
			triangle2(num);
		}
		if(option==3) {
			cin>>num;
			cout<<digits_sum(num)<<endl;;
		}
		if(option==4) {
			cin>>num;
			natural3nums(num);
		}
		if(option==5) {
			cin>>doubleNum;
			cout<<sinus(doubleNum)<<endl;
		}
		if(option ==6) {
			cin>>num;
			cout<<neastprime(num)<<endl;
		}
	}
	while(option!=0);
}

void triangle1(int num) {
	string triang = "";
	int temp = 1;
	for ( int i = num; i > 0; i -- ) {
		for ( int j = temp; j > 0; j -- )
			triang += "*";
		triang += "\n";
		temp ++;
	}
	cout << triang;
}

void triangle2(int num) {
	string triang = "";
	int temp = num;
	for ( int i = 1; i <= num; i ++ ) {
		for ( int j = 0; j < temp; j ++ )
			triang += "*";
		triang += "\n";
		temp --;
	}
	cout << triang;
}

int  digits_sum(int num) {
	int sum=0;
	int x;
	while ( num > 0 ) {
		x = num % 10;
		num = num / 10;
		sum += x;
	}
	return sum;
}

void natural3nums(int num) {
	string str;
	for(int i = 1; i < num; i++) {
		for(int j = 1; j < num; j++) {
			for(int k = 1; k < num; k++) {
				if((i + j + k == num) && (i != j) && (i != k) && (j != k) && (j > i) && (k > j)) {
					str = std::to_string(i)+"+"+std::to_string(j)+"+"+std::to_string(k);
					cout << str <<endl;
				}
			}
		}
	}
}

double sinus(double x) {
	double M_PI = 3.14;
	int flag = 0;
	double sinx = 0, factorial;
	while ((x > (2 * M_PI)) || (x < (-2 * M_PI))) {
		if (x > (2 * M_PI))
			x = x - 2 * M_PI;
		else
			x = x + 2 * M_PI;
	}
	for (int i = 1; i <= 21; i = i + 2) {
		factorial = 1;
		for ( int j = 1; j <= i; j ++ )
			factorial = factorial * j;
		if ( flag == 0 ) {
			sinx = sinx + ( pow ( x, i ) / factorial );
		flag = 1;
		}
		else {
			sinx = sinx - ( pow ( x, i ) / factorial );
			flag = 0;
		}
	}
	return sinx;
}
int neastprime(int n) {
	int result = 0;
	int prime = 1;
	int flag = 0;
	int prime2 = 1;
	for(int i = n; i > 1; i--) {
		flag = 0;
		for(int j = 2; j < i; j++) {
			if((i % j == 0) && (i != j)) {
				flag = 1;
			}
		}
		if(flag == 0) {
			prime = i;
			break;
		}
	}
	for(int i = n; i >= n; i++) {
		flag = 0;
		for(int j = 2; j < i; j++) {
			if((i % j == 0) && (i != j)) {
				flag = 1;
			}
		}
		if(flag == 0) {
			prime2 = i;
			break;
		}
	}
	if((n - prime) <= (prime2 - n))
		result = prime;
	else
		result = prime2;
	return result;
}
