#include<bits/stdc++.h>
using namespace std;

class Graph
{
	public:
	int V;
	list<int> *adj;
	
	Graph(int V)
	{
		this->V = V;
		adj = new list<int> [V];

	}	
	void addedge(int u  , int v);
	void print();
	void bsf(int s);
	void dfs(int v);
	void dfsutil(int v , bool visited[]);
	bool iscyclic();
	bool iscyclicutl(int v , bool visited[] , bool recstack[]);
	void isbfscycle();
};


void Graph::addedge(int u , int v )
{
	adj[u].push_back(v);
}

void Graph::bsf(int s)
{
	bool *visited = new bool [V];
	for(int i = 0 ; i < V ; i++)
		visited[i] = false;
	
	list<int> queue;


	visited[s] = true;
	queue.push_back(s);

	list<int> :: iterator i;
	while(!queue.empty())
	{
		int val  = queue.front();
		cout << val << " ";
		queue.pop_front();

		for( i = adj[val].begin() ; i != adj[val].end() ; i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}	

}
void Graph::print()
{
	for(int i = 0 ; i < V ; i++)
	{
		cout<<"adjecent edges of edge are "<< i << endl;
		for(auto x = adj[i].begin() ; x  != adj[i].end() ; x++)
		{
			
			cout << *x << " ";
		}
		cout << endl;
	}

}

void Graph::dfsutil(int v , bool visited[]  )
{
	visited[v] = true;
	cout << v << " ";
	
	list<int> :: iterator i;
	for(i = adj[v].begin() ; i != adj[v].end() ; i++)
		if(!visited[*i])
			dfsutil(*i , visited);
}

void Graph::dfs(int v)
{
	bool *visited = new bool[V];
	for(int i=0 ;i < V ; i++)
	{
		visited[i] = false;
	}

	dfsutil( v  , visited);
}


bool Graph::iscyclicutl(int v , bool visited[] , bool recstack[])
{
	if(visited[v] == false)
	{
		visited[v] = true;
		recstack[v] = true;

		list<int>:: iterator i ;
		for( i = adj[v].begin() ; i != adj[v].end() ; i++)
		{
			if( !visited[*i] && iscyclicutl(*i , visited , recstack))
				return true;
			else if(recstack[*i] )
				return true;
				
		}
	}
	recstack[v] = false;
	return false;

}

bool Graph::iscyclic()
{
	bool *visited = new bool [V];
	bool *restack  = new bool [V];

	for(int i =0 ; i < V ; i++)
	{
		visited[i] = false;
		restack[i] = false;
	}

	for(int i =0 ; i < V ; i++)
		if(iscyclicutl(i , visited , restack))
			return true;

	return false;
	

}

void Graph::isbfscycle()
{
	vector<int> in_degree(V ,0);

	int count = 0;
	for(int u = 0 ; u < V ; u++)
	{
		for(auto x : adj[u])
			in_degree[u]++;
	}	

	queue<int> q;
	for(int u =0 ; u < V ;u++)
	{
		if(in_degree[u] == 0 )
			q.push(u);
	}
	
	vector<int> top_order;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		top_order.push_back(v);

		list<int>:: iterator i;
		for(i = adj[v].begin() ; i != adj[v].end() ; i++)
		{
			if(--in_degree[*i] == 0)
				q.push(*i);
		}
	
	 count++;
	}
	
	if(count ==0)
		cout << "No cycle" << endl;
	else
		cout << "Cycle"<<endl;
}

int main()
{
	int V = 5;
	Graph g(V);

	g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3); 
  
	
//	g.print();
//	g.bsf(2);
//	g.dfs(2);

	// check cycle for directed graph using dfs //
//	if(g.iscyclic())
//		cout << "Cycle present" << endl;
//	else
//		cout << "Cycle absent"<<endl;

	//check cycle for directed graph using bfs//

	g.isbfscycle();
	return 1;
}

