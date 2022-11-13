#include <iostream>
#include <queue>
using namespace std;

vector<int> v;

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

class Nodevalue
{
public:
	int maxNode, minNode, maxSize;
	Nodevalue(int maxNode, int minNode, int maxSize)
	{
		this->maxNode = maxNode;
		this->minNode = minNode;
		this->maxSize = maxSize;
	}
};

Nodevalue LargestBSTSubTree(Node *root)
{
	if (!root)
		return Nodevalue(INT_MIN, INT_MAX, 0);

	auto left = LargestBSTSubTree(root->left);
	auto right = LargestBSTSubTree(root->right);

	if (left.maxNode < root->data && right.minNode > root->data)
	{

		return Nodevalue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + root->data);
	}
	return Nodevalue(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
}

void InOrderTraversal(Node *root)
{
	if (!root)
		return;
	InOrderTraversal(root->left);
	cout << root->data << " ";
	v.push_back(root->data);
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

Node *BalanceBST(int s, int e)
{
	if (s > e)
		return NULL;
	int mid = (s + e) / 2;
	Node *root = new Node(v[mid]);
	root->left = BalanceBST(s, mid - 1);
	root->right = BalanceBST(mid + 1, e);
	return root;
}

Node *rightmost(Node *root)
{
	if (root->right == NULL)
		return root;
	return rightmost(root->right);
}

void flatten(Node *root)
{
	// converts to single link list
	if (root == NULL)
		return;
	Node *nextright;
	Node *rightMOST;

	while (root)
	{
		if (root->left)
		{
			rightMOST = rightmost(root->left);
			nextright = root->right;
			root->right = root->left;
			root->left = NULL;
			rightMOST->right = nextright;
		}
		root = root->right;
	}
}

Node *buildBstFromPreOrder(vector<int> &A, int &i, int bound)
{
	if (i == A.size() || A[i] > bound)
	{
		return NULL;
	}
	Node *root = new Node(A[i++]);
	root->left = buildBstFromPreOrder(A, i, root->data);
	root->right = buildBstFromPreOrder(A, i, bound);
	return root;
}

Node *buildBstFromInorder(vector<int> v, int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	Node *root = new Node(v[mid]);
	root->left = buildBstFromInorder(v, start, mid - 1);
	root->right = buildBstFromInorder(v, mid + 1, end);
	return root;
}

void convertBstToSortedDLL(Node *root, Node **headDLL)
{
	if (!root)
		return;
	static Node *prev = NULL;
	convertBstToSortedDLL(root->right, headDLL);
	if (!prev)
		*headDLL = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	convertBstToSortedDLL(root->left, headDLL);
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

	cout << " Make a balanced search tree out of the given tree "
		 << "\n\n";
	levelOrderTraversal(BalanceBST(0, v.size() - 1));

	Node *headDLL = NULL;
	convertBstToSortedDLL(root, &headDLL);
	while (headDLL != NULL)
	{
		cout << headDLL->data << " ";
		headDLL = headDLL->right;
	}

	cout << LargestBSTSubTree(root).maxSize;

	return 0;
}