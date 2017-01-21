#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
int main()
{
	//No. of vertex and edges in the graph
	int n,e,e1,e2,flag=0;
	cin>>n>>e;
	//Using adjacency list to represent graph
	vector < vector <int> > v(n+1);
	vector <int>::iterator it;
	//cycle=0 denotes no cycle while cycle=1 denotes a cycle in the graph
	int cycle=0;
	for(int i=0;i<e;i++)
	{
		cin>>e1>>e2;
		v[e1].push_back(e2); 
	}
	//color array marks all the nodes visited (in the stack) with 1, unvisited with 0 and finished with 2
	int color[n+1];
	//initializing the color array with 0 since they are univisited
	for(int i=1;i<=n;i++)
		color[i]=0;
	//Stack data structure is used to solve DFS	
	stack < int > s;
	for(int i=1;i<=n;i++)
	{
		if(color[i]==0)
		{
			s.push(i);
			color[i]=1;
			//DFS Implementation
			while(!s.empty())
			{
				flag=0;
				int k = s.top();
				for(it=v[k1].begin();it!=v[k1].end();++it)
				{
					if(color[*it]==1)
					{
						cycle=1;
						s.push(*it);
						goto end1;
					}
					else if(color[*it]==0)
					{
						color[*it]=1;
						s.push(*it);
						flag=1;
						break;
					}	
				}
				if(cycle==1)
					break;
				if(flag==0)
				{
					color[k]=2;
					s.pop();
				}
			}
		}
	}
	end:
	while(!s.empty)
	{
		count++;
		s.pop();
	}
	for(int i=1;i<=n;i++)
	{
		cout<<color[i]<<endl;
	}
	if(cycle==1)
		cout<<"Yes. Length: "<<count;
	else
		cout<<"No";
}

