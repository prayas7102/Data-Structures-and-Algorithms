#include <iostream>
#include <algorithm>
#include <climits>

const long long M = 1e9 + 7;

using namespace std;

int gcd(int a, int b)
{
	if (!b)
		return a;
	// cout<<a<<b<<endl;
	return gcd(b, a % b);
}

void Swap(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << "numbers after swapping " << a << " " << b << endl;
}

int binExpRec(int a, int b)
{
	if (!b)
		return 1;
	long long res = binExpRec(a, b / 2);
	if (b & 1)
	{
		return (a * res * res) % M;
	}
	return (res * res) % M;
}

int binExpItr(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = (a * 1LL * ans) % M;
		}
		a = (a * a * 1LL) % M;
		b >>= 1;
	}
	return ans;
}

int main()
{
	cout << "gcd of two numbers 10 and 12 = " << gcd(10, 12) << endl;
	cout << "gcd of two numbers 10 and 85 = " << __gcd(10, 85);

	cout << endl
		 << endl;

	int a = 10999, b = 27650;
	cout << "swap two numbers using bit manipulation " << a << " " << b << endl;
	Swap(a, b);

	cout << endl;
	cout << "Power of a number using binary exponentiation (recursive) " << a << " " << b << " = " << binExpRec(a, b) << endl;

	cout << endl;
	cout << "Power of a number using binary exponentiation (iterative) " << a << " " << b << " = " << binExpItr(a, b) << endl;

	cout << endl;

	return 0;
}