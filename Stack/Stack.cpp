#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void deleteMiddleElement(stack<int> &s, int count, int size)
{
	if (count == size)
	{
		s.pop();
		return;
	}
	int num = s.top();
	s.pop();
	deleteMiddleElement(s, count + 1, size);
	s.push(num);
}

void addBottomElement(stack<int> &s, int x)
{
	if (s.empty())
	{
		s.push(x);
		return;
	}
	int num = s.top();
	s.pop();
	addBottomElement(s, x);
	s.push(num);
}

void printStack(stack<int> s)
{
	while (!s.empty())
	{
		cout << ' ' << s.top();
		s.pop();
	}
}

int checkBalancedParanthesis(vector<char> v)
{
	stack<char> p;
	for (int i = 0; i < v.size(); ++i)
	{
		char ch = v[i];
		if (ch == '{' || ch == '(' || ch == '[')
		{
			p.push(ch);
		}
		else
		{
			int top = p.top();
			if ((top == '{' && ch == '}') || (top == '(' && ch == ')') || (top == '[' && ch == ']'))
			{
				p.pop();
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	if (!p.empty())
	{
		return false;
	}
	return true;
}

vector<int> nextSmallerElement(vector<int> v)
{
	stack<int> s;
	s.push(-1);
	int n = v.size();
	vector<int> a(n);
	for (int i = n - 1; i >= 0; i--)
	{
		int curr = v[i];
		while (s.top() >= curr)
		{
			cout << s.top() << "\n";
			s.pop();
		}
		a[i] = s.top();
		s.push(curr);
	}
	return a;
}

int main()
{
	stack<int> s;
	s.push(2);
	s.push(20);
	s.push(12);
	s.push(8);
	s.push(9);
	s.push(8);

	cout << "Available Stack" << endl;
	printStack(s);

	cout << "\n\n"
		 << "Deleting middle element" << endl;
	deleteMiddleElement(s, 0, s.size() / 2);
	printStack(s);

	int x = 30;
	cout << "\n\n"
		 << "Adding element " << x << " at bottom of stack" << endl;
	addBottomElement(s, x);
	printStack(s);

	vector<char> vect{'{', '(', ')', '('};
	cout << "\n\n";
	checkBalancedParanthesis(vect) ? cout << "Balanced" : cout << "Unbalanced";

	vector<int> v{6, 2, 3, 7, 8, 3};
	cout << "\n\n";
	cout << "Find next smaller element in ";
	cout << "\n\n";
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << "\n\n";

	v = nextSmallerElement(v);
	for (auto i : v)
	{
		cout << i << " ";
	}
	return 0;
}