class Solution {
public:
    void DFS(int v,vector<vector<int>> &graph,vector<int> &disc,vector<int> &low,vector<int> &parent,vector<vector<int>> &ans)
    {
        static int time = 0;
        disc[v] = low[v] = time;
        
        time += 1;
        
        for(int i=0;i<graph[v].size();i++)
        {
            if(disc[graph[v][i]] == -1) //unvisited vertex
            {
                parent[graph[v][i]] = v;
                DFS(graph[v][i],graph,disc,low,parent,ans);
                low[v] = min(low[v],low[graph[v][i]]);
                
                if(low[graph[v][i]] > disc[v]) //condition for critical edge..edge's lowest is greater than our max
                {
                    ans.push_back({v,graph[v][i]});
                }
            }
            else
                if(parent[v] != graph[v][i]) //back edge
                    low[v] = min(low[v],low[graph[v][i]]);
        }
    }
    
    void helper(int v,vector<vector<int>> &graph,vector<vector<int>> &ans)
    {
        vector<int> disc(v,-1);
        vector<int> low(v,-1);
        vector<int> parent(v,-1);
        
        for(int i=0;i<v;i++)
        {
            if(disc[i] == -1) //unvisited
                DFS(i,graph,disc,low,parent,ans);
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
            
        }
        vector<vector<int>> ans;
        
        helper(n,graph,ans);
        return ans;
        
    }
};