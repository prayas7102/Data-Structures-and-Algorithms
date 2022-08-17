#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

void printQueue(queue<int> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n\n";
}

void reverseQueue(queue<int> &q)
{
	if (q.empty())
	{
		return;
	}
	int ans = q.front();
	q.pop();
	reverseQueue(q);
	q.push(ans);
}

void findFirstNegative(vector<int> v, int k)
{
	deque<int> dq;
	vector<int> ans;
	for (int i = 0; i < k; ++i)
	{
		if (v[i] < 0)
		{
			dq.push_back(i);
		}
	}
	if (dq.size())
	{
		ans.push_back(v[dq.front()]);
	}
	else
	{
		dq.push_back(0);
	}

	for (int i = k; i < v.size(); ++i)
	{
		if (!dq.empty() && i - dq.front() >= k)
		{
			dq.pop_front();
		}
		if (v[i] < 0)
		{
			dq.push_back(i);
		}
		if (dq.size())
		{
			ans.push_back(v[dq.front()]);
		}
		else
		{
			dq.push_back(0);
		}
	}
	for (auto a : ans)
	{
		cout << a << " ";
	}
}
int main()
{
	// reverse a queue
	int i;
	auto it = {1, 4, 2, 3, 5};
	queue<int> q1(it);
	cout << "reverse a queue = ";
	printQueue(q1);
	reverseQueue(q1);
	cout << "reversed queue = ";
	printQueue(q1);

	// first negative elements for k elements
	cout << "first negative elements for k elements" << endl;
	vector<int> v{-1, 2, 3, -4, 5, -6};
	int k = 2;
	findFirstNegative(v, k);

	return 0;
}