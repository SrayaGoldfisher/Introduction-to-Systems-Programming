#include <iostream> 
#include <math.h>
using namespace std;

int printNumber(int howMuch, double num, int flag) {
	if (howMuch>1) {
		if (flag == 1)
			cout << " + " << howMuch << " * " << num;
		else {
			cout << howMuch << " * " << num;
			flag=1;
		}
	}
	if(howMuch == 1) {
		if (flag == 1)
			cout << " + " << num;
		else {
			cout << num;
			flag=1;
		}
	}
	return flag;
}


int main() {
	//get 3 numbers from the user, and print them by order from the small to large
	double num1,num2,num3, numMax, numMin, numMed;
	cin>>num1>>num2>>num3;
	if(num1>=num2 && num1>=num3) {
		numMax = num1;
		if(num2>=num3) {
			numMed = num2;
			numMin = num3;
		}
		else {
			numMed = num3;
			numMin = num2;
		}
	}
	if(num1<=num2 && num1<=num3) {
		numMin = num1;
		if(num2>=num3) {
			numMed = num3;
			numMax = num2;
		}
		else {
			numMed = num2;
			numMax = num3;
		}
	}
	if(num1<=num2 && num1>=num3) {
		numMed = num1;
		if(num2>=num3) {
			numMax = num2;
			numMin = num3;
		}
		else {
			numMax = num3;
			numMin = num2;
		}
	}
	if(num1<=num3 && num1>=num2) {
		numMed = num1;
		if(num2>=num3) {
			numMax = num2;
			numMin = num3;
		}
		else {
			numMax = num3;
			numMin = num2;
		}
	}
	cout<< numMin<<", "<<+numMed<<", "<<+numMax <<endl;
	
	//get from user number, calculate and print
	double money, tempMoney;
	int twoHund, oneHund, fifty, ten, five, shnekel, shekel, halfShekel, tenAg, flag=0;
	cin>>money;
	if (money<0)
		cout << "Error!"<<endl;
	else { //create case for every type of money.
		tempMoney = money;
		twoHund = money / 200;
		tempMoney = tempMoney - (twoHund*200);
		flag = printNumber(twoHund, 200, flag);

		oneHund = tempMoney / 100;
		tempMoney = tempMoney - (oneHund*100);
		flag = printNumber(oneHund, 100, flag);

		fifty = tempMoney / 50;
		tempMoney = tempMoney - (fifty*50);
		flag = printNumber(fifty, 50, flag);

		ten = tempMoney / 10;
		tempMoney = tempMoney - (ten*10);
		flag = printNumber(ten, 10, flag);

		five = tempMoney / 5;
		tempMoney = tempMoney - (five*5);
		flag = printNumber(five, 5, flag);

		shnekel = tempMoney / 2;
		tempMoney = tempMoney - (shnekel*2);
		flag = printNumber(shnekel, 2, flag);

		shekel = tempMoney / 1;
		tempMoney = tempMoney - (shekel*1);
		flag = printNumber(shekel, 1, flag);

		halfShekel = tempMoney / 0.5;
		tempMoney = tempMoney - (halfShekel*0.5);
		flag = printNumber(halfShekel, 0.5, flag);

		tenAg = (tempMoney+0.00000001) / 0.1;
		tempMoney = tempMoney - (tenAg*0.1);
		flag = printNumber(tenAg, 0.1, flag);
	}
	cout << "\n";
	
	//calculate days in months according to terms
	int year, month;
	cin>>year>>month;
	//verify validation of the input
	if (year <=0 || month<=0 || month>12) {
		if (year <= 0){
			if (month<=0 || month>12){
				cout<<"Error, not a real month or year"<<endl;
			}
			else
				cout<<"Invalid year "<<endl;
		}
		else
			cout<<"Invalid month "<<endl;
	}
	else {
		switch (month){
			case 2: 
				if ((year % 4 != 0) || (year % 400 != 0 && year % 100 == 0)){
					cout<<"28 days"<<endl;
				}
				else
					cout<<"29 days"<<endl;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				cout<<"30 days"<<endl;
				break;
			default:
				cout<<"31 days"<<endl;
		}
	}

	//calculate x1 x2 according to 3 numbers-a,b,c by equation
	long double a, b, c, minusB, shoresh, x1, x2, chezka, temp;
	//get from user three numbers
	cin>>a>>b>>c;
	minusB = -1 * b;
	temp  = pow(b, 2) - (4 * a * c);
	//verify validation of the sqrt
	if(temp >= 0) {
		shoresh = sqrt(temp);
		if ((2*a) != 0) {
			//calculate x1, x2
			x1 = (minusB + shoresh)/(2 * a);
			x2 = (minusB - shoresh)/(2 * a);
			if (x1 == x2)
				cout<<"x1=x2="<<x1;
			else
				cout<<"x1="<<x1<<"   x2="<<x2;
		}
		else
			cout<<"Error, no real roots!";
	}
	else {
		cout<<"Error, no real roots!";
	}
	cout<<"\n";
	
	return 0;
	}