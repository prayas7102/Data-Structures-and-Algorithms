#include <iostream>

using namespace std;

void printBinary(int n)
{
	cout << "Binary form of " << n << endl;
	for (int i = 10; i >= 0; i--)
	{
		int k = (n >> i) & 1;
		cout << k << " ";
	}
	cout << endl
		 << endl;
}

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

void noOfOnes(int n)
{
	cout << "No. of ones in binary form of " << n << endl;
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n - 1);
	}
	cout << count << endl;
}

void printBinaryOfAlphabets()
{
	cout << endl
		 << "Alphabets in binary form \n\n";
	for (char c = 'A'; c <= 'B'; c++)
	{
		cout << c << endl;
		printBinary(int(c));
	}
	for (char c = 'a'; c <= 'b'; c++)
	{
		cout << c << endl;
		printBinary(int(c));
	}

	char A = 'A';
	char a = A | (1 << 5); // A to a
	cout << "Changing " << A << " to " << a << "\n";
	A = a & ~(1 << 5);
	cout << "Changing " << a << " to " << A << "\n";
}

bool powerOfTwo(int n)
{
	// n = 8 == 100, n-1 = 7 = 011
	int ans = n & n - 1;
	return !ans;
}

void arraySubsets(char arr[], int n)
{
	// 1<<n = 1*(2^n)
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				cout << arr[j] << " ";
		}
		cout << endl;
	}
}

void findUniqueElement(int arr[], int n)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = ans ^ arr[i];
	}
	cout << endl
		 << "find unique element = " << ans << endl;
}

int main()
{
	// “x” with an integer “y” denoted as ‘(x<<y)’ is equivalent to
	// multiplying x with 2^y (2 raised to power y).
	// eg: lets take N=22; which is 00010110 in Binary Form.
	// Now, if “N is left-shifted by 2” i.e N=N<<2 then N will become N=N*(2^2).
	// Thus, N=22*(2^2)=88 which can be written as 01011000.

	// “x” with an integer “y” denoted as ‘(x>>y)‘ is equivalent to
	// dividing x with 2^y.
	// eg: lets take N=32; which is 100000 in Binary Form.
	// Now, if “N is right-shifted by 2” i.e N=N>>2 then N will become N=N/(2^2).
	// Thus, N=32/(2^2)=8 which can be written as 1000.

	int n = 5, pos = 3, unique[] = {1, 2, 1, 2, 3, 3, 4, 5, 5};
	char arr[] = {'a', 'b', 'c'};
	printBinary(n);
	determineBit(n, pos);
	setBit(n, 1);
	clearBit(n, 2);
	updateBit(5, 1, 1);
	noOfOnes(5);
	printBinaryOfAlphabets();
	n = 8;
	cout << "\npwer of two ?" << n << " " << powerOfTwo(n) << endl;
	arraySubsets(arr, 3);
	findUniqueElement(unique, 9);
	return 0;
}