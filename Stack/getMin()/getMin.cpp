#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;
int minElement = INT_MAX;
void push(stack<int> &s, int x)
{
	if (s.empty())
	{
		s.push(x);
		minElement=x;
	}
	else
	{
		if (minElement > x)
		{
			int n = 2 * x - minElement;
			s.push(n);
			minElement = x;
		}
		else
			s.push(x);
	}
}

int pop(stack<int> &s)
{
	if (s.empty())
	{
		return -1;
	}
	int top = s.top();
	s.pop();
	if (minElement > top)
	{
		int preminElement = minElement;
		int n = 2 * minElement - top;
		minElement = n;
		return preminElement;
	}
	else
		return top;
}

int top(stack<int> &s)
{
	if (s.empty())
	{
		return -1;
	}
	return s.top();
}

int isEmpty(stack<int> s)
{
	return s.empty();
}

int getMinElement(stack<int> &s)
{
	if (s.empty())
	{
		return -1;
	}
	return minElement;
}

int main()
{
	stack<int> s;
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 8);
	cout << pop(s) << endl;
	cout << pop(s) << endl;
	cout << top(s) << endl;
	cout << isEmpty(s) << endl;
	cout << getMinElement(s);
	return 0;
}