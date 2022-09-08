#include <iostream>
#include <vector>
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

int determineBit(int n, int pos)
{
	int x = n & (1 << pos) != 0;
	return x;
}

// 0-->1
int setBit(int n, int pos)
{
	int x = n | (1 << pos);
	return x;
}

// 1->> 0
int clearBit(int n, int pos)
{
	int x = n & ~(1 << pos);
	return x;
}

int updateBit(int n, int pos, int val)
{
	int x = n & ~(1 << pos);
	int m = x | (val << pos);
	return m;
}

int noOfOnes(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n - 1);
	}
	return count;
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
		 << "unique element in array = " << ans << endl;
}

void findUniqueTwoElement(int arr[], int n)
{
	cout << endl
		 << "two unique element in array = ";
	int xorsum = 0;
	for (int i = 0; i < n; ++i)
	{
		xorsum = xorsum ^ arr[i];
	}
	int itr = 0;
	int pos = 0;
	while (itr != 1)
	{
		itr = xorsum & 1 << pos;
		pos++;
		// xorsum=xorsum>>1;
	}
	int newxor = 0;
	for (int i = 0; i < n; ++i)
	{
		if (determineBit(arr[i], pos - 1))
		{
			newxor ^= arr[i];
		}
	}
	cout << newxor << " ";
	int ans = newxor ^ xorsum;
	cout << ans;
}

void findUniqueThreeElement(int arr[], int n)
{
	cout << endl
		 << "one unique element in array with 3 duplicates= ";
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		int sum = 0;
		if (i <= n)
		{
			for (int j = 0; j < n; j++)
			{
				if (determineBit(arr[j], i))
				{
					sum++;
					cout << arr[j];
				}
			}
			cout << endl;
			v.push_back(sum);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << v[i] << endl;
	}
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

	int n = 5, pos = 3, unique[] = {1, 2, 1, 2, 3, 3, 4, 5, 5}, unique2[] = {1, 2, 2, 3, 3, 4, 5, 5};
	int unique3[] = {1, 1, 1, 2, 3, 3, 3, 5, 5, 5};

	char arr[] = {'a', 'b', 'c'};
	printBinary(n);

	cout << "Calculate the bit at 3rd postion in binary form of " << n << endl;
	cout << determineBit(n, pos) << endl;

	cout << "Set the bit at 1st postion in binary form of " << n << endl;
	cout << setBit(n, 1) << endl;

	cout << "Clear the bit at 2nd postion in binary form of " << n << endl;
	cout << clearBit(n, 2) << endl;

	cout << "Update the bit at 1st postion in binary form of " << n << endl;
	cout << updateBit(5, 1, 1) << endl;

	cout << "No. of ones in binary form of " << n << endl;
	cout << noOfOnes(5) << endl;

	printBinaryOfAlphabets();

	n = 8;
	cout << "\npower of two ?" << n << " " << powerOfTwo(n) << endl;

	arraySubsets(arr, 3);

	findUniqueElement(unique, 9);

	findUniqueTwoElement(unique2, 8);

	findUniqueThreeElement(unique3, 10);

	return 0;
}