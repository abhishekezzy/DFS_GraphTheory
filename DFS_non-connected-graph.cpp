#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
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
	//DFS for all vertices
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			stack <int> s;
			s.push(i);
			visited[i]=1;
			cout<<i<<" ";
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
	}
}
