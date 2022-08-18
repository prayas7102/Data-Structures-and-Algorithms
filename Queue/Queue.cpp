#include <iostream>
#include <deque>
#include <queue>
#include <stack>
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
		ans.push_back(0);
	}

	for (int i = k; i < v.size(); ++i)
	{
		// deleting element to check k elements in dq
		// diff b/w i and dq.front() <= k
		if (!dq.empty() && i >= k+dq.front())
		{
			dq.pop_front();
		}
		// adding element
		if (v[i] < 0)
		{
			dq.push_back(i);
		}
		// ans array updated
		if (dq.size())
		{
			ans.push_back(v[dq.front()]);
		}
		else
		{
			ans.push_back(0);
		}
	}
	for (auto a : ans)
	{
		cout << a << " ";
	}
}

void reverseKelementsQueue(queue<int> &q, int k)
{
	stack<int>s;
	int n=q.size();
	for (int i = 0; i < k; ++i)
	{
		int ans = q.front();
		s.push(ans);
		q.pop();
	}
	for (int i = 0; i < k; ++i)
	{
		int ans = s.top();
		q.push(ans);
		s.pop();
	}
	for (int i = 0; i < n-k; ++i)
	{
		int ans = q.front();
		q.push(ans);
		q.pop();
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
	vector<int> v{1, -2, 3, -4, 5, 6};
	int k = 2;
	findFirstNegative(v, k);

	// reverse first k elements of queue
	cout << "\n\nreverse first k elements of queue = ";
	printQueue(q1);
	reverseKelementsQueue(q1,k);
	printQueue(q1);

	return 0;
}