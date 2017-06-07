#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
int main()
{
	//No. of vertex and edges in the graph
	int n, e, e1, e2;
	cin >> n >> e;
	//Using adjacency list to represent graph
	vector < vector <int> > v(n);
	for(int i = 0; i < e; i++)
	{
		cin >> e1 >> e2;
		v[e1].push_back(e2); 
	}
	
	//visited array marks all the nodes visited with 1
	int visited[n];
	//initializing all the nodes with 0 since they are univisited
	for(int i = 0; i < n; i++)
		visited[i]=0;
		
	//Stack data structure is used to solve DFS	
	stack <int> s;
	int source;
	cin>>source;
	cout << source << " ";
	s.push(source);
	visited[source] = 1;
	
	//DFS Implementation
	while(!s.empty())
	{
		int k =s.top();
		s.pop();
		vector <int>:: iterator it;
		for(it = v[k].begin(); it != v[k].end(); ++it)
		{
			if(visited[*it] == 0)
			{
				s.push(k);
				visited[*it]=1;
				cout << *it << " ";
				s.push(*it);
				break;
			}				
		}
	}
}
