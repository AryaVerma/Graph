#include<bits/stdc++.h>
using namespace std;
#define inf 1e9


/* Note:
        All the vertices are considered as indexed 0
*/

int minKey(int key[],bool mstSet[],int n){
    int min_=inf+1;
    int ind=-1;
    for(int i=0;i<n;i++)
    if(mstSet[i]==false && key[i]<min_)
    {
        min_=key[i];
        ind=i;
    }
    return ind;
}

void showMst(int parent[],int key[],vector<vector<pair<int,int>>>& g)
{
    int ans=0;
    for(int i=1;i<g.size();i++)
       {
           cout<<parent[i]<<" connected to "<<i<<" with weight equal to "<<key[i]<<endl;
           ans+=key[i];
       }
    cout<<"Total minimum cost of joining all the cities is "<<ans<<endl;
}


int main()
{
     int n;
     cin>>n;
     int e;
     cin>>e;
     vector<vector<pair<int,int>>> g(n);
     for(int i=0;i<e;i++)
     {
         int u,v,w;
         cin>>u>>v>>w;
         u--;v--;
         g[u].push_back({v,w});
         g[v].push_back({u,w});
     }
     int parent[n]={-1};
     int key[n];
     bool mstSet[n]={false};
     for(int i=0;i<n;i++)
        key[i]=inf;

     key[0]=0;
     parent[0]=-1;
     for(int i=0;i<n;i++){
        int ver=minKey(key,mstSet,n);
        mstSet[ver]=true;
        for(auto neighbours:g[ver])
        {
            int j=neighbours.first;
            int w=neighbours.second;
            if(mstSet[j]==false && key[j]>w )
            {
                key[j]=w;
                parent[j]=ver;
            }
        }
     }
     showMst(parent,key,g);
}
