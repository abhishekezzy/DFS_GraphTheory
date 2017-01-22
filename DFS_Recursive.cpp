#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
void dfs(int s, vector < vector <int>> &v,int visited[])
{
	visited[s]=1;
	cout<<s<<" ";
	vector <int>::iterator it;
	for(it=v[s].begin();it!=v[s].end();++it)
	{
		if(!visited[*it])
			dfs(*it,v,visited);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector < vector<int>> v(n);
	int e1,e2;
	for(int i = 0;i < m;i++)
	{
		cin>>e1>>e2;
		v[e1].push_back(e2);
	}
	int visited[n];
	int s;
	cin>>s;
	for(int i = 0;i < n;i++)
		visited[i]=0;
	dfs(s,v,visited);
}

