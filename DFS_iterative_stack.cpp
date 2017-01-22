#include<bits/stdc++.h>
using namespace std;
int main()
{
	//No. of vertex and edges in the graph
	int n,e,e1,e2;
	cin>>n>>e;
	//Using adjacency list to represent graph
	vector < vector <int> > v(n);
	for(int i=0;i<e;i++)
	{
		cin>>e1>>e2;
		v[e1].push_back(e2); 
	}
	//visited array marks all the nodes visited with 1
	int visited[n];
	//initializing all the nodes with 0 since they are univisited
	r(i,n)
		visited[i]=0;
	//Stack data structure is used to solve DFS	
	stack <int> s;
	int source;
	cin>>source;
	s.push(source);
	//visited[source]=1;
	//DFS Implementation
	while(!s.empty())
	{
		int k =s.top();
		s.pop();
		if(visited[k]==0)
		{
			visited[k]=1;
			cout<<k<<" ";
			vector <int>::iterator it;
			for(it = v[k].begin();it!=v[k].end();++it)
			{
				if(visited[*it]==0)
					s.push(*it);
			}
		}
	}
}
