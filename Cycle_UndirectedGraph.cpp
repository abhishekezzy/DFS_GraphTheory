#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,x,y,parent,flag=0;
	    cin>>n>>m;
	    vector <vector <int>> adj(n);
	    for(int i=0;i<m;i++)
	    {
	    	cin>>x>>y;
	    	adj[x].push_back(y);
			adj[y].push_back(x);	    
		}
	    int color[n],cycle=0;
		//initializing the color array with 0 since they are univisited
		for(int i = 0; i < n; i++)
			color[i]=0;
		//Stack data structure is used to solve DFS	
		vector <int>::iterator it;
		stack < int > s;
		for(int i=0;i<n;i++)
		{
		    for(it=adj[i].begin();it!=adj[i].end();++it)
		    {
		        if(*it==i)
		        {
		            cycle=1;
		            break;
		        }
		    }
		}
		if(cycle==0)
		{
	    	for(int i=0;i<n;i++)
	    	{
	    		if(color[i]==0)
	    		{
	    			s.push(i);
	    			color[i]=1;
	    			parent = i;
	    			//DFS Implementation
	    			while(!s.empty())
	    			{
	    				int k = s.top();
	    				s.pop();
	    				for(it=adj[k].begin();it!=adj[k].end();++it)
	    				{
	    					if(color[*it]==1 && *it!=parent)
	    					{
	    						//cout<<*it<<endl;
	    						cycle=1;
	    						goto end;
	    					}
	    					else if(color[*it]==0)
	    					{
	    						color[*it]=1;
	    						s.push(*it);
	    						//break;
	    					}	
	    				}
	    				parent = k;
	    			}
	    		}
	    	}
	    }
	    end:
		if(cycle==1)
			cout<<"1"<<endl;
		else
			cout<<"0"; 
	}
}
