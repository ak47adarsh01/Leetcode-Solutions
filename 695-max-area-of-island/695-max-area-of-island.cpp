class Solution {
public:
    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>> &a,int i,int j)
    {
       // a[x][y]=0;
         int ans=0;
        for(auto k:d)
        {
            int x=i+k[0];
            int y=j+k[1];
            if(x>=0 && x<a.size() && y>=0  && y<a[0].size())
            {
                if(a[x][y]==1)
                {
                    a[x][y]=0;
                   ans+=dfs(a,x,y);
                }
            }
        }
        return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& a ) {
        int m=a.size();
        int n=a[0].size();
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    a[i][j]=0;
                    res=max(res,dfs(a,i,j));
                }
            }
        }
        return res;
    }
};