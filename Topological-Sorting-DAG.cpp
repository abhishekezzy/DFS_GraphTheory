#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
int main()
{
	int n, m, e1, e2, flag = 0;
	cin>>n>>m;
	int visited[n+1];
	for(int i = 1; i <= n; i++)
		visited[i] = 0;
	vector < vector <int>> v(n+1);
	vector <int>::iterator it;
	for(int i = 1;i <= m; i++)
	{
		cin >> e1 >> e2;
		v[e1].push_back(e2);
	}
	stack <int> s1;
	stack <int> s2;
	for(int i = 1;i <= n; i++)
	{
		if(visited[i]==0)
		{
			s1.push(i);
			visited[i]=1;
			while(!s1.empty())
			{
				flag = 0;
				int k = s1.top();
				for(it = v[k].begin(); it != v[k].end(); ++it)
				{
					if(visited[*it] == 0)
					{
						s1.push(*it);
						visited[*it] = 1;	
						flag = 1;
						break;
					}
				}
				//Reverse order processing (Topological Sort trick)
				if(flag == 0)
				{
					s2.push(k);
					s1.pop();	
				}
			}		
		}
	}
	while(!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
}

