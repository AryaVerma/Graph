#include<bits/stdc++.h>
using namespace std;
#define inf 1e9




int minKey(int key[],bool mstSet[],int n){
    int min_=inf+1;
    cout<<"Error"<<endl;
    int ind=-1;
    for(int i=0;i<n;i++)
    if(mstSet[i]==false && key[i]<min_)
    {
        min_=key[i];
        ind=i;
    }
    return ind;
}

void showMst(int parent[],vector<vector<int>>& g)
{
    for(int i=1;i<g.size();i++)
        cout<<parent[i]<<" connected to "<<i<<" with weight equal to "<<g[parent[i]][i]<<endl;
}


int main()
{
     int n=6;
     vector<vector<int>> g={{0, 1, 1, 100, 0, 0},
                               {1, 0, 1, 0, 0, 0},
                               {1, 1, 0, 0, 0, 0},
                               {100, 0, 0, 0, 2, 2},
                               {0, 0, 0, 2, 0, 2},
                               {0, 0, 0, 2, 2, 0}};
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
        for(int j=0;j<n;j++)
        {
            if(mstSet[j]==false && key[j]>g[ver][j] && g[ver][j]>0)
            {
                key[j]=g[ver][j];
                parent[j]=ver;
            }
        }
     }
     showMst(parent,g);
}
