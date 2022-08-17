#include <iostream>
#include <deque>
#include <queue>
using namespace std;

void printQueue(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n\n";
}

void reverseQueue(queue<int> &q){
	if(q.empty()){return;}
	int ans=q.front();
	q.pop();
	reverseQueue(q);
	q.push(ans);
}

int main()
{
	// reverse a queue
	int i;
	auto it={1,4,2,3,5};
	queue<int> q1(it);
	cout<<"reverse a queue = ";
	printQueue(q1);
	reverseQueue(q1);
	cout<<"reversed queue = ";
	printQueue(q1);


	return 0;
}