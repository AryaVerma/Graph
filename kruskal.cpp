
#include<bits/stdc++.h>
using namespace std;



class Edge{
    public:
           int u;int v;int w;
 };
class Subset{
    public:
           int parent;
           int ranke;
};
int find(Subset subsets[],int s)
{
    if(subsets[s].parent!=s)
        subsets[s].parent=find(subsets,subsets[s].parent);
    return subsets[s].parent;
}
void Union(Subset subsets[],int x,int y)
{
     int xroot = find(subsets, x);
     int yroot = find(subsets, y);
    if (subsets[xroot].ranke < subsets[yroot].ranke)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].ranke > subsets[yroot].ranke)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].ranke++;
    }

}
int comp(const void* a,const void *b)
{
    Edge *edgea=(Edge*)a;
    Edge* edgeb=(Edge*)b;
    return edgea->w  > edgeb->w;
}
int main()
{
     int n; /*Number of Vertices*/
     cin>>n;
     int e;  /* Number of edges*/
     cin>>e;
     Edge *edge=new Edge[e];
     for(int i=0;i<e;i++)
     {
         cin>>edge[i].u>>edge[i].v>>edge[i].w;
     }
     qsort((void*)edge,e,sizeof(edge[0]),comp);/*Sorting the edges by their weights*/
     Subset *subsets=new Subset[n];
     for(int i=0;i<n;i++)
     {
         subsets[i].parent=i;
         subsets[i].ranke=0;
     }
     int reqEdges=0;
     int currEdge=0;
     int result[n-1];
     while(reqEdges<n-1 && currEdge<e)
     {
        Edge next_edge=edge[currEdge++];
        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);
        if (x != y)
        {
            result[reqEdges++] = next_edge.w;
            Union(subsets, x, y);
        }
     }
     for(int i=0;i<n-1;i++)
        cout<<result[i]<<endl;
}
