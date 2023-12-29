// Binary Lifting tutorial by errichto  https://youtu.be/oib-XsjFa-M

Problem link : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

///things to remember -starts
1.Note : following code works if Parent[i]<i; But i have solved it with different modificaiton with help of comment in videos 

2.Note : to avoid parent[i]<i condition in precomputations

we have 2 different ways to avoid above conditions.(used in https://codeforces.com/contest/191/problem/C this problem ) 
1. run for loop as this.

void compute()
{
    for(ll i=0;i<n;i++)
    {
        up[i][0]=par[i];
    }
    for(ll j=1;j<18;j++)
    {
        for(ll i=0;i<n;i++)
        {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
}

2. inside dfs usual for loop as mentiond in below solutions also.

// things to remember -ends

class TreeAncestor {
    vector<vector<int>> up; // int up[N][20];
    vector<int> depth;
    int LOG;
    public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1 << LOG) <= n) {
            LOG++;
        }
        up = vector<vector<int>>(n, vector<int>(LOG));
        depth = vector<int>(n);
        // up[v][j] is 2^j -th ancestor of node v
        parent[0] = 0;
        for(int v = 0; v < n; v++) {
            up[v][0] = parent[v];
            if(v != 0) {
                depth[v] = depth[parent[v]] + 1;
            }
            for(int j = 1; j < LOG; j++) {
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) 
    {
        if(depth[node] < k) 
        {
            return -1;
        }
        for(int j = LOG - 1; j >= 0; j--) 
        {
            if(k >= (1 << j)) 
            {
                node = up[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }
};
