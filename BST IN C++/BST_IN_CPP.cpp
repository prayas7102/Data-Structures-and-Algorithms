#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	int val;
	Node *left;
	Node *right;
	Node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};
Node *buildTree(Node *root)
{
	cout << "Enter Data" << endl;
	int data;
	cin >> data;
	root = new Node(data);
	if (data == -1)
	{
		return NULL;
	}
	cout << "Enter data to left of " << data << endl;
	root->left = buildTree(root->left);
	cout << "Enter data to right of " << data << endl;
	root->right = buildTree(root->right);
	return root;
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
			cout << temp->val << " ";
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
void inOrderTraversal(Node *root)
{
	if (!root)
	{
		return;
	}
	inOrderTraversal(root->left);
	cout << root->val << " ";
	inOrderTraversal(root->right);
}
void preOrderTraversal(Node *root)
{
	if (!root)
	{
		return;
	}
	cout << root->val << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
	if (!root)
	{
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->val << " ";
}
void buildTreeFromLevelOrder(Node *&root)
{
	cout << "Enter value of root node" << endl;
	int data;
	cin >> data;
	root = new Node(data);
	queue<Node *> tree;
	tree.push(root);
	while (!tree.empty())
	{
		Node *node = tree.front();
		tree.pop();
		cout << "Enter left node of " << node->val << endl;
		int left;
		cin >> left;
		if (left != -1)
		{
			node->left = new Node(left);
			tree.push(node->left);
		}
		cout << "Enter right node of " << node->val << endl;
		int right;
		cin >> right;
		if (right != -1)
		{
			node->right = new Node(right);
			tree.push(node->right);
		}
	}
}
int main()
{
	Node *root = NULL;
	root = buildTree(root);

	cout << endl
		 << "level order traversal of tree" << endl;
	levelOrderTraversal(root);

	cout << endl
		 << "inorder traversal of tree" << endl;
	inOrderTraversal(root);

	cout << endl
		 << "postorder traversal of tree" << endl;
	postOrderTraversal(root);

	cout << endl
		 << "preorder traversal of tree" << endl;
	preOrderTraversal(root);

	cout << endl
		 << endl
		 << "Build tree from level Order" << endl;
	Node *topRoot = NULL;
	buildTreeFromLevelOrder(topRoot);

	cout << endl
		 << "level order traversal of tree" << endl;
	levelOrderTraversal(topRoot);

	return 0;
}