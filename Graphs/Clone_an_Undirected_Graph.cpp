
#include<bits/stdc++.h>
using namespace std;

struct GraphNode
{
	int val;


	vector<GraphNode*> neighbours;
};


GraphNode *cloneGraph(GraphNode *src)
{

	map<GraphNode*, GraphNode*> m;
	queue<GraphNode*> q;

	
	q.push(src);
	GraphNode *node;

	node = new GraphNode();
	node->val = src->val;

	
	m[src] = node;
	while (!q.empty())
	{
		
		GraphNode *u = q.front();
		q.pop();
		vector<GraphNode *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			// Check if this node has already been created
			if (m[v[i]] == NULL)
			{
				
				node = new GraphNode();
				node->val = v[i]->val;
				m[v[i]] = node;
				q.push(v[i]);
			}

			
			m[u]->neighbours.push_back(m[v[i]]);
		}
	}

	
	return m[src];
}

GraphNode *buildGraph()
{
	
	GraphNode *node1 = new GraphNode();
	node1->val = 1;
	GraphNode *node2 = new GraphNode();
	node2->val = 2;
	GraphNode *node3 = new GraphNode();
	node3->val = 3;
	GraphNode *node4 = new GraphNode();
	node4->val = 4;
	vector<GraphNode *> v;
	v.push_back(node2);
	v.push_back(node4);
	node1->neighbours = v;
	v.clear();
	v.push_back(node1);
	v.push_back(node3);
	node2->neighbours = v;
	v.clear();
	v.push_back(node2);
	v.push_back(node4);
	node3->neighbours = v;
	v.clear();
	v.push_back(node3);
	v.push_back(node1);
	node4->neighbours = v;
	return node1;
}

void bfs(GraphNode *src)
{
	map<GraphNode*, bool> visit;
	queue<GraphNode*> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty())
	{
		GraphNode *u = q.front();
		cout << "Value of Node " << u->val << "\n";
		cout << "Address of Node " <<u << "\n";
		q.pop();
		vector<GraphNode *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			if (!visit[v[i]])
			{
				visit[v[i]] = true;
				q.push(v[i]);
			}
		}
	}
	cout << endl;
}

int main()
{
	GraphNode *src = buildGraph();
	cout << "BFS Traversal before cloning\n";
	bfs(src);
	GraphNode *newsrc = cloneGraph(src);
	cout << "BFS Traversal after cloning\n";
	bfs(newsrc);
	return 0;
}
