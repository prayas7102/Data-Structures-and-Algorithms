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

void InOrderTraversal(Node *root)
{
	if (!root)
		return;
	InOrderTraversal(root->left);
	cout << root->data << " ";
	InOrderTraversal(root->right);
}

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

Node *deleteNode(Node *root, int data)
{

	if (!root)
		return root;

	if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			delete root;
			return NULL;
		}
		else if (root->left && !root->right)
		{
			delete root;
			root = root->left;
			return root;
		}
		else if (!root->left && root->right)
		{
			delete root;
			root = root->right;
			return root;
		}
		else
		{
			int mini = minValue(root->right);
			root->data = mini;
			root->right = deleteNode(root->right, mini);
			return root;
		}
	}

	else if (root->data > data)
	{
		root->left = deleteNode(root->left, data);
		return root;
	}

	else
	{
		root->right = deleteNode(root->right, data);
		return root;
	}
	return root;
}

Node *findNode(Node *root, int data)
{
	if (!root)
		return NULL;
	if (root->data == data)
	{
		return root;
	}
	if (root->data > data)
	{
		root->left = findNode(root->left, data);
	}
	else
	{
		root->right = findNode(root->right, data);
	}
}

Node *LCA(Node *root, Node *first, Node *second)
{
	if (!root)
	{
		return NULL;
	}
	if (root->data > first->data && root->data > second->data)
	{
		return LCA(root->left, first, second);
	}
	if (root->data < first->data && root->data < second->data)
	{
		return LCA(root->right, first, second);
	}
	return root;
}

int InorderPredecessor(Node *val)
{
	Node *rightTree = val->left;
	int ans = rightTree->data;
	while (!rightTree)
	{
		ans = rightTree->data;
		cout << ans;
		rightTree = rightTree->right;
	}
	return ans;
}

int InorderSuccessor(Node *val)
{
	Node *leftTree = val->right;
	int ans = leftTree->data;
	while (!leftTree)
	{
		ans = leftTree->data;
		leftTree = leftTree->left;
	}
	return ans;
}

int main()
{
	Node *root = NULL;
	takeInput(root);

	cout << "InOrderTraversal of BST" << endl;
	InOrderTraversal(root);

	cout << "\n\n";

	cout << "LevelOrderTraversal of BST" << endl;
	levelOrderTraversal(root);

	cout << "\n";

	cout << "Minimum Value " << minValue(root) << "\n\n";
	cout << "Maximum Value " << maxValue(root) << "\n\n";

	cout << "Tree after deleting 38 from tree"
		 << "\n\n";
	root = deleteNode(root, 30);
	levelOrderTraversal(root);
	cout << "\n";

	Node *first = findNode(root, 38);
	Node *second = findNode(root, 60);
	Node *third = findNode(root, 34);

	cout << " Inorder Predecessor of 34: " << InorderPredecessor(third) << "\n\n";
	cout << " Inorder Successor of 34: " << InorderSuccessor(third) << "\n\n";

	cout << " LCA of 38 & 60: " << LCA(root, first, second)->data << "\n\n";
	return 0;
}