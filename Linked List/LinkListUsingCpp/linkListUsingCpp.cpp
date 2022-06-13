#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int val)
	{
		data = val;
		next = NULL;
	}
};
Node *getMid(Node *head)
{
	Node *slow = head;
	Node *fast = head->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
Node *Merge(Node *a, Node *b)
{
	Node *result = NULL;
	if (!a)
	{
		return b;
	}
	if (!b)
	{
		return a;
	}
	if (a->data <= b->data)
	{
		result = a;
		result->next = Merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = Merge(a, b->next);
	}
	return result;
}
Node *MergeSort(Node *head)
{
	if (!head || !head->next)
	{
		return head;
	}
	Node *mid = getMid(head);
	Node *left = head;
	Node *right = mid->next;
	mid->next = NULL;
	left = MergeSort(left);
	right = MergeSort(right);
	Node *result = Merge(left, right);
	return result;
}
void insertAtHead(Node *&head, int val)
{
	Node *n = new Node(val);
	n->next = head;
	head = n;
}
void insertAtTail(Node *&head, int val)
{
	Node *n = new Node(val);
	if (head == NULL)
	{
		head = n;
		return;
	}
	Node *temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = n;
}
void print(Node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
void reverse(Node *&head)
{
	Node *prev = NULL;
	Node *current = head;
	Node *nextptr;
	while (current)
	{
		nextptr = current->next;
		current->next = prev;
		prev = current;
		current = nextptr;
	}
	head = prev;
}
Node *temp;
void reverseRecursive(Node *&head)
{
	if (head == NULL || head->next == NULL)
	{
		temp = head;
		return;
	}
	reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
}
Node *reversekNodes(Node *&head, int k)
{
	Node *prev = NULL;
	Node *current = head;
	Node *nextptr;
	int i = 0;
	while (current && i < k)
	{
		nextptr = current->next;
		current->next = prev;
		prev = current;
		current = nextptr;
		i++;
	}
	if (nextptr != NULL)
	{
		head->next = reversekNodes(nextptr, k);
	}
	return prev;
}
void insertCycle(Node *&head, int pos)
{
	Node *temp = head, *target = NULL;
	int i = 0;
	while (temp->next)
	{
		if (pos == i)
		{
			target = temp;
		}
		i++;
		temp = temp->next;
	}
	temp->next = target;
}
Node *detectCycle(Node *&head)
{
	Node *slow = head, *fast = head;
	do
	{
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	fast = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
Node *removeCycle(Node *&head)
{
	Node *slow = head, *fast = head;
	do
	{
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	fast = head;
	while (slow->next != fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
}
int main()
{
	Node *head = NULL;

	// insert value in link list
	cout << "link list:" << endl;
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtHead(head, 2);
	insertAtHead(head, 10);
	insertAtTail(head, 3);
	insertAtTail(head, 9);
	print(head);

	cout << endl;
	// reverse linked list
	cout << "link list reversed:" << endl;
	reverse(head);
	print(head);

	cout << endl;
	// reverse linked list using recursion
	cout << "link list reversed: using recursion" << endl;
	reverseRecursive(head);
	head = temp;
	print(head);

	cout << endl;
	// reverse k nodes in link list
	cout << "link list k nodes reversed:" << endl;
	int k = 4;
	head = reversekNodes(head, k);
	print(head);

	cout << endl;
	cout << "Linked List sorted" << endl;
	head = MergeSort(head);
	print(head);

	cout << endl;
	cout << "Inserting cycle in Linked List at position 3" << endl;
	int pos = 3;
	insertCycle(head, pos);
	cout << "Detecting cycle in Linked List" << endl;
	Node *loopPoint = detectCycle(head);
	cout << "Cycle present in Linked List at node " << loopPoint->data << endl;

	cout << "Remove cycle in Linked List" << endl;
	removeCycle(head);
	print(head);
	return 0;
}