#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
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
		if (!dq.empty() && i >= k + dq.front())
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
	stack<int> s;
	int n = q.size();
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
	for (int i = 0; i < n - k; ++i)
	{
		int ans = q.front();
		q.push(ans);
		q.pop();
	}
}

void firstNonRepeatingElement(string &s)
{
	map<char, int> m;
	queue<char> q;
	for (int i = 0; i < s.length(); ++i)
	{
		m[s[i]]++;
		q.push(s[i]);
		while (!q.empty())
		{
			if (m[q.front()] > 1)
			{
				q.pop();
			}
			else
			{
				s[i] = q.front();
				break;
			}
		}
		if (q.empty())
			s[i] = '#';
	}
}

void interleaveQueue(queue<int> &q2)
{
	stack<int> st;
	int n = q2.size() / 2;
	for (int i = 0; i < n; i++)
	{
		st.push(q2.front());
		q2.pop();
	}
	while (!st.empty())
	{
		q2.push(st.top());
		st.pop();
	}
	for (int i = 0; i < n; i++)
	{
		q2.push(q2.front());
		q2.pop();
	}
	for (int i = 0; i < n; i++)
	{
		st.push(q2.front());
		q2.pop();
	}
	while (!st.empty())
	{
		q2.push(q2.front());
		q2.pop();
		q2.push(st.top());
		st.pop();
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
	reverseKelementsQueue(q1, k);
	printQueue(q1);

	// reverse first k elements of queue
	cout << "reverse first k elements of queue = ";
	printQueue(q1);
	reverseKelementsQueue(q1, k);
	printQueue(q1);

	// first non repeating element of string
	string s = "aaabbcdeff";
	cout << "first non repeating element of string = " << s << " is ";
	firstNonRepeatingElement(s);
	cout << s << endl
		 << endl;

	// interleave the first half of queue with other half
	cout << "interleave the first half of queue with other half\n";
	auto itr = {9, 6, 7, 8, 2, 3, 4, 1};
	queue<int> q2(itr); // size of queue should be even
	printQueue(q2);
	interleaveQueue(q2);
	printQueue(q2);

	return 0;
}