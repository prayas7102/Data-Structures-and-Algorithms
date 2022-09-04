#include <iostream>

using namespace std;

void determineBit(int n, int pos)
{
	cout << "Calculate the bit at 3rd postion in binary form of " << n << endl;
	int x = n & (1 << pos) != 0;
	cout << x << endl;
}

// 0-->1
void setBit(int n, int pos)
{
	cout << "Set the bit at 1st postion in binary form of " << n << endl;
	int x = n | (1 << pos);
	cout << x << endl;
}

// 1->> 0
void clearBit(int n, int pos)
{
	cout << "Clear the bit at 2nd postion in binary form of " << n << endl;
	int x = n & ~(1 << pos);
	cout << x << endl;
}

void updateBit(int n, int pos, int val)
{
	cout << "Update the bit at 1st postion in binary form of " << n << endl;
	int x = n & ~(1 << pos);
	int m = x | (val << pos);
	cout << m << endl;
}

int main()
{
	int n = 5, pos = 3;
	determineBit(n, pos);
	setBit(n, 1);
	clearBit(n, 2);
	updateBit(5, 1, 1);
	int x = 0 << 1;
	cout << x;

	return 0;
}