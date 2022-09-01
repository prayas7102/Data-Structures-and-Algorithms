#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;
	Node(int num)
	{
		data = num;
		left = NULL;
		right = NULL;
	}
};

class cmp
{
public:
	bool operator()(Node *a, Node *b)
	{
		return a->data > b->data;
	}
};

void traverse(Node *root, vector<string> &ans, string temp)
{
	if (root->left == NULL && root->right == NULL)
	{
		ans.push_back(temp);
		return;
	}
	traverse(root->left, ans, temp + '0');
	traverse(root->right, ans, temp + '1');
}

int main()
{
	std::vector<int> v{5, 9, 12, 13, 16, 45};
	priority_queue<Node *, vector<Node *>, cmp> pq;
	for (int i = 0; i < v.size(); ++i)
	{
		Node *temp = new Node(v[i]);
		pq.push(temp);
	}
	while (pq.size() > 1)
	{
		Node *left = pq.top();
		pq.pop();
		Node *right = pq.top();
		pq.pop();
		Node *newnode = new Node(left->data + right->data);
		newnode->left = left;
		newnode->right = right;
		pq.push(newnode);
	}
	Node *root = pq.top();
	vector<string> ans;
	string temp = "";
	traverse(root, ans, temp);
	for (auto &s : ans)
	{
		cout << s << " ";
	}
	return 0;
}