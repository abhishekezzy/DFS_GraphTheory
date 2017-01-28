#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
int main()
{
	int n,m,flag=0,x,y;
	cin>>n>>m;
	vector <vector <int>> v(n+1);
	vector <vector <int>> rev(n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		rev[y].push_back(x);
	}
	int vis[n+1];
	for(int i=1;i<=n;i++)
		vis[i]=0;
	stack <int> s1;
	stack <int> s2;
	stack <int> s3;
	vector <int>::iterator it;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			s1.push(i);
			vis[i]=1;
			while(!s1.empty())
			{
				int k=s1.top();
				flag=0;
				for(it=rev[k].begin();it!=rev[k].end();++it)
				{
					if(!vis[*it])
					{
						vis[*it]=1;
						s1.push(*it);
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					s2.push(k);
					s1.pop();	
				}
			}
		}
	}
	int scc=0;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	while(!s2.empty())
	{
		int i=s2.top();
		s2.pop();
		if(!vis[i])
		{
			s3.push(i);
			vis[i]=1;
			while(!s3.empty())
			{
				int k=s3.top();
				flag=0;
				for(it=v[k].begin();it!=v[k].end();++it)
				{
					if(!vis[*it])
					{
						vis[*it]=1;
						s3.push(*it);
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					s3.pop();	
				}
			}
			scc++;		
		}
	}
	cout<<scc<<endl;
}

