#include <iostream>
#include <list>

using namespace std;

class Graph {
	int V;
	list<int> *adjlist;
	private:
		void dfsutil(int start, bool visited[]);
	public:
		Graph(int v);
		int addEdge(int v, int w);
		int dfs(int start);
		int bfs(int start);
};


Graph::Graph(int v)
{
	this->V = v;
	adjlist = new list<int>[v];
}

int
Graph::addEdge(int v, int w)
{
	adjlist[v].push_back(w);
	return (0);
}

void
Graph::dfsutil(int start, bool visited[])
{
	cout << start << " ";
	visited[start] = true;
	list<int>::iterator it;
	for(it = adjlist[start].begin(); it != adjlist[start].end(); it++) {
		if (!visited[*it])  {
			dfsutil(*it, visited);
		}
	}
	return;
}

int
Graph::dfs(int start)
{
	bool *visited = new bool[V];	
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	dfsutil(start, visited);
	return (0);
}

int
Graph::bfs(int start) 
{
	list<int> queue;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	queue.push_back(start);

	while (!queue.empty()) {
		int temp = queue.front();
		cout << temp << " ";
		queue.pop_front();
		visited[temp] = true;
		list<int>::iterator it;
		for (it = adjlist[temp].begin(); it != adjlist[temp].end();
								++it) {
			if (!visited[*it])
				queue.push_back(*it);
}
	}
	return (0);
}


int
main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.dfs(2);
	printf("\n");
	g.bfs(2);
}
