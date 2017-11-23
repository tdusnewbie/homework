#include <iostream>
#include <math.h>

using namespace std;

/*Change from BIN to DEC*/

int twoPow(int n)
{
	int temp =1;
	for (int i =0 ;i<n;i++)
		temp *=2;
	return temp;
}

// Normal way (pow of 2)
int changeToDecNor(bool num[])
{
	int decNum = 0;
	int i =31;
	while (i >= 0)
	{
		int temp = num[i];
		int mu = twoPow(i);
		if(num[i] ==1)
		{
			decNum += num[i]*mu;
		}
		i--;
	}
	return decNum;
}

// Computer way (bitwise)
int changeToDecBit(int num)
{
	int temp = num;
	int decNum =0 , digit, i = 0;
	while(temp!=0)
	{
		digit = temp % 10;
		decNum += digit << i;
		temp = temp / 10;
		i++;
	}
	return decNum;
}

int main()
{
	bool num[32] ={1,1,1,1,0,0,0,0};
	cout << "Ta co day bit sau : " <<endl;
	for (int i =31;i >= 0 ;i--)
		cout << num[i];
	cout << endl;
	int temp;
	for (int i =0; i<32;i++)
	{
		temp = temp + num[i]*pow(10,i);
	}
	cout  << temp <<endl;
	int decNum = changeToDecBit(temp);
	cout  << "Sau khi chuyen ve thap phan ta dc : " << decNum << endl;
	return 0;
}