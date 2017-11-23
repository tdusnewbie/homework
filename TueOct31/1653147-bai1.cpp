#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// /*Change from BIN to DEC*/

// // Normal way (pow of 2)
// int changeToDecNor(string num)
// {
// 	int decNum;
// 	int i =0;
// 	while (i < num.size())
// 	{
// 		int temp = stoi(num.at(i));
// 		decNum += pow(temp,i);
// 	}
// 	return decNum;
// }

// // Computer way (bitwise)
// int changToDecBit(string num)
// {
// 	int temp=stoi(num);
// 	int decNum, digit, i =0;
// 	while(temp!=0)
// 	{
// 		digit=temp%10;
// 		decNum+=digit<<i;
// 		temp=temp/10;
// 		i++;
// 	}
// 	return decNum;
// }

/*Change from DEC to BIN*/

// Normal way (mod 2)
void changeToBinMod(int &num)
{
	int rem;
	if (num <= 1)
	{
		cout << num;
		return;
	}
	rem = num % 2;
	int temp = num / 2;
	changeToBinMod(temp);
	cout << rem;
}

// Computer way (bitwise)

void changeToBinBit(int &num)
{
	int saved = num,temp;
	for(int i =31;i >=0 ;i--)
	{
		temp = saved  >> i;
		if(temp & 1)
			cout << "1";
		else 
			cout << "0";
	}
	cout << endl;
}

/*Main Function to fix bugs*/

int main()
{
	int a,b;
	cout << "Nhap a = " ;
	cin >> a;
	cout << "a o dang nhi phan la (chia cho 2): ";
	changeToBinMod(a);
	cout << endl;
	cout << "a o dang nhi phan la (xu ly bit) : ";
	changeToBinBit(a);
	cout << endl;
	cout << "Nhap b = " ;
	cin >> b;
	cout << "b o dang nhi phan la (chia cho 2): ";
	changeToBinMod(b);
	cout << endl;
	cout << "b o dang nhi phan la (xu ly bit) : ";
	changeToBinBit(b);
	cout << endl;
	int _and = a & b;
	int _or = a |b;
	int _xor = a ^ b;
	int _not = ~a;
	cout << "a AND b  = " << _and << endl;
	cout << "a OR b = " << _or << endl;
	cout << "a XOR b = " << _xor << endl;
	cout << "NOT (a) = "  << _not <<endl;
	int right = a >>1;
	int left = b << 2;
	cout << "a dich phai 1 bit : " << right <<endl;
	cout << "b dich tra 2 bit : " << left <<endl;
	return 0;
}