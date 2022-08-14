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
	cout << "\n\n";
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
	if (next)
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
	vector<int> next = nextOrPrevSmallerElementHistogram(length, true);
	vector<int> prev = nextOrPrevSmallerElementHistogram(length, false);
	int area = -99999999;
	int n = length.size();
	for (int i = 0; i < length.size(); i++)
	{
		int l = length[i];
		if (next[i] == -1)
			next[i] = n;
		int b = next[i] - prev[i] - 1;
		area = max(area, l * b);
	}
	return area;
}

int largestAreaRectangle2DArray(vector<vector<int>> v, int n, int m)
{
	int area = largestAreaRectangle(v[0]);
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] != 0)
			{
				v[i][j] = v[i][j] + v[i - 1][j];
			}
		}
		area = max(largestAreaRectangle(v[i]), area);
	}
	return area;
}

int celebrityProblem(vector<vector<int>> v, int n = 3, int m = 3)
{
	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		s.push(i);
	}
	while (s.size() > 1)
	{
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();
		if (v[a][b])
		{
			s.push(b);
		}
		else
			s.push(a);
	}
	int candidate = s.top();

	// checking for row
	for (int i = 0; i < n; ++i)
	{
		if (v[candidate][i] == 0 || candidate == i)
		{
			continue;
		}
		else
		{
			return -1;
		}
	}
	// checking for column
	for (int i = 0; i < m; ++i)
	{
		if (v[i][candidate] == 1 || candidate == i)
		{
			continue;
		}
		else
		{
			return -1;
		}
	}
	return candidate;
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

	//-----------------------------------------------------

	cout << "\n\n"
		 << "Deleting middle element" << endl;
	deleteMiddleElement(s, 0, s.size() / 2);
	printStack(s);

	//-----------------------------------------------------

	int x = 30;
	cout << "\n\n"
		 << "Adding element " << x << " at bottom of stack" << endl;
	addBottomElement(s, x);
	printStack(s);

	//-----------------------------------------------------

	vector<char> vect{'{', '(', ')', '}', '}'};
	cout << "\n\n";
	checkBalancedParanthesis(vect) ? cout << "Balanced" : cout << "Unbalanced";

	//-----------------------------------------------------

	vector<int> v{6, 2, 3, 7, 8, 3};
	cout << "\n\n";
	cout << "Find next smaller element in ";
	cout << "\n\n";
	printVector(v);

	// for next smaller element call nextOrPrevSmallerElement(v,false)
	// for next previous element call nextOrPrevSmallerElement(v,true)

	v = nextOrPrevSmallerElement(v, false);
	printVector(v);

	//-----------------------------------------------------

	cout << "Largest rectangle in histogram ";
	cout << "\n\n";
	vector<int> length{2, 1, 5, 6, 2, 3};
	printVector(length);
	cout << "= ";
	cout << largestAreaRectangle(length);

	//-----------------------------------------------------

	cout << "\n\n"
		 << "Largest rectangle in 2-D array = ";
	vector<vector<int>> rectangleArr{
		{1, 0, 1},
		{1, 1, 1},
		{1, 1, 0}};
	int n = 3, m = 3;
	cout << largestAreaRectangle2DArray(rectangleArr, n, m);

	//-----------------------------------------------------

	cout << "\n\n"
		 << "Celebrity in 2-D array = ";
	vector<vector<int>> celebrityArr{
		{0, 1, 1},
		{0, 0, 0},
		{1, 1, 0}};
	cout << celebrityProblem(celebrityArr, n, m);

	return 0;
}