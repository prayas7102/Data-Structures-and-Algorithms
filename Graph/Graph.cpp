#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
	int V; 
	vector<list<int>> adj;
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);
// prints adjancey list
	void printAdjList();
	// prints BFS traversal from a given source s
	void BFS(int s);

// prints BFS traversal from a given source s
	void DFS(int s);

};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::printAdjList(){
	int pos=0;
	cout<<"Adjancey List"<<endl;
	for(auto i: adj){
		if(i.size()){
			cout<<pos<<"--> ";
			for(auto j:i){
				cout<<j<< " ";
			}
		}
		cout<<endl;
		pos++;
	}
}
void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V,false);

	// Create a queue for BFS
	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto adjacent: adj[s])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.printAdjList();
	cout<<endl;
	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
