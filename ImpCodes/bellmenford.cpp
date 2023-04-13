Distance from the Source (Bellman-Ford Algorithm) -----GFg
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& v, int s) {
        // Code here
        vector<int> dis(n,1e8);
        dis[s]=0;
        int t=n-1;
        while(t--)
        {
        for(auto val : v)
        {
            int u=val[0];//node-1
            int v=val[1];//node-2
            int wt=val[2];//weight
            if(dis[u]+wt<dis[v])
            {
                dis[v]=dis[u]+wt;
            }
        }
        }

        for(auto val : v)
        {
            int u=val[0];
            int v=val[1];
            int wt=val[2];
            if(dis[u]+wt<dis[v])
            {
                return {-1};//negative cycle
            }
        }
        return dis;
    }
};
