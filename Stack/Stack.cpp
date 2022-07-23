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

void printVector(vector<int> v)
{
	for (auto i : v)
	{
		cout << i << " ";
	}
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
			if (p.empty())
				return false;
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

vector<int> nextOrPrevSmallerElement(vector<int> v, bool next)
{
	stack<int> s;
	int n = v.size();
	vector<int> ans(n);

	if (!next)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int curr = v[i];
			while (!s.empty() && s.top() >= v[i])
			{
				s.pop();
			}
			int res = s.empty() ? -1 : s.top();
			ans[i] = res;
			s.push(curr);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int curr = v[i];
			while (!s.empty() && s.top() >= v[i])
			{
				s.pop();
			}
			int res = s.empty() ? -1 : s.top();
			ans[i] = res;
			s.push(curr);
		}
	}
	return ans;
}

vector<int> nextOrPrevSmallerElementHistogram(vector<int> v, int next)
{
	stack<int> s;
	s.push(-1);
	int n = v.size();
	vector<int> ans(n);
	if (!next)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int curr = v[i];
			while (s.top() != -1 && v[s.top()] >= curr)
			{
				s.pop();
			}
			ans[i] = s.top();
			s.push(i);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int curr = v[i];
			while (s.top() != -1 && v[s.top()] >= curr)
			{
				s.pop();
			}
			ans[i] = s.top();
			s.push(i);
		}
	}
	return ans;
}
int largestAreaRectangle(vector<int> length)
{
	vector<int> next = nextOrPrevSmallerElementHistogram(length, true), prev = nextOrPrevSmallerElementHistogram(length, false);
	int area = -99999;
	int n = length.size();
	for (int i = 0; i < length.size(); ++i)
	{
		if (next[i] != -1)
			area = max(area, length[i] * (next[i] - prev[i] - 1));
		else
			area = max(area, length[i] * (n - prev[i] - 1));
		// cout<<next[i]<<prev[i]<<endl;
	}
	return area;
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

	vector<char> vect{'{', '(', ')', '}', '}'};
	cout << "\n\n";
	checkBalancedParanthesis(vect) ? cout << "Balanced" : cout << "Unbalanced";

	vector<int> v{6, 2, 3, 7, 8, 3};
	cout << "\n\n";
	cout << "Find next smaller element in ";
	cout << "\n\n";
	printVector(v);
	cout << "\n\n";

	// for next smaller element call nextOrPrevSmallerElement(v,false)
	// for next previous element call nextOrPrevSmallerElement(v,true)

	v = nextOrPrevSmallerElement(v, 1);

	printVector(v);

	cout << "\n\n";
	cout << "Largest rectangle in histogram ";
	cout << "\n\n";
	vector<int> length{2, 1, 5, 6, 2, 3};
	printVector(length);
	cout << "= ";
	cout << largestAreaRectangle(length);
	return 0;
}