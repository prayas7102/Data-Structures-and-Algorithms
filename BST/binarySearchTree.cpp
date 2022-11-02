#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;

	Node(int val)
	{
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};

void levelOrderTraversal(Node *root)
{
	queue<Node *> container;
	container.push(root);
	container.push(NULL);
	while (!container.empty())
	{
		Node *temp = container.front();
		container.pop();
		if (temp)
		{
			cout << temp->data << " ";
			if (temp->left)
				container.push(temp->left);
			if (temp->right)
				container.push(temp->right);
		}
		else
		{
			cout << endl;
			if (container.empty() != 1)
			{
				container.push(NULL);
			}
		}
	}
}

Node *InsertIntoNode(Node *root, int data)
{
	if (root == NULL)
	{
		Node *newNode = new Node(data);
		return newNode;
	}
	if (data < root->data)
	{
		root->left = InsertIntoNode(root->left, data);
	}
	else
	{
		root->right = InsertIntoNode(root->right, data);
	}
	return root;
}

void takeInput(Node *&root)
{
	int data;
	cin >> data;
	while (data != -1)
	{
		root = InsertIntoNode(root, data);
		cin >> data;
	}
}

int minValue(Node *&root)
{
	Node *temp = root;
	while (temp->left)
	{
		temp = temp->left;
	}
	return temp->data;
}

int maxValue(Node *&root)
{
	Node *temp = root;
	while (temp->right)
	{
		temp = temp->right;
	}
	return temp->data;
}

int main()
{
	Node *root = NULL;
	takeInput(root);
	levelOrderTraversal(root);

	cout << "\n";

	cout << "Minimum Value " << minValue(root) << "\n\n";
	cout << "Maximum Value " << maxValue(root) << "\n\n";

	return 0;
}