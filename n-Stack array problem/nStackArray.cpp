#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nStackPush(int item, int sn, int *arr, int *next, int *top, int *free)
{
	if (*free == -1)
	{
		// stack is full;
		cout << "\nStack Overflow\n";
		return;
	}
	int i = *free;
	*free = next[i];   // updating next free space
	next[i] = top[sn]; // new next element = top element of stack
	top[sn] = i;	   // top element of stack is index i
	arr[i] = item;	   // push operation in arr
}

int nStackPop(int sn, int *arr, int *next, int *top, int *free)
{
	if (top[sn] == -1)
	{
		// stack is empty;
		cout << "\nStack Under flow\n";
		return -99;
	}
	int i = top[sn];   // index of top element of stack in arr
	top[sn] = next[i]; // updating index of top element
	next[i] = *free;   //
	*free = i;		   // next free space is index of current top element to pop
	return arr[i];
}

int main()
{
	int arr[9], top[3] = {-1, -1, -1}, next[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, free = -1;
	cout << "\n\n"
		 << "n stacks in an array = ";
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		arr[0] = i + 1;
	}

	nStackPush(8, 1, arr, next, top, &free);
	nStackPush(48, 1, arr, next, top, &free);
	nStackPush(83, 1, arr, next, top, &free);
	nStackPush(92, 2, arr, next, top, &free);
	nStackPush(1, 2, arr, next, top, &free);
	nStackPush(9, 2, arr, next, top, &free);
	nStackPush(6, 3, arr, next, top, &free);
	nStackPush(69, 3, arr, next, top, &free);
	nStackPush(56, 3, arr, next, top, &free);

	cout << "Popped element from stack 1 is " << nStackPop(1, arr, next, top, &free) << endl;
	cout << "Popped element from stack 2 is " << nStackPop(2, arr, next, top, &free) << endl;
	cout << "Popped element from stack 3 is " << nStackPop(3, arr, next, top, &free) << endl;
	return 0;
}