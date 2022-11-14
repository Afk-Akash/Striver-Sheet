class Solution {
public:
    void solve(vector<vector<int>> &temp , int j, vector<bool>&vis)
    {
        vis[j]=1;
        for(int i=0;i<temp[j].size();i++)
        {
            if(!vis[temp[j][i]]) {solve(temp, temp[j][i], vis);}
        }
    }
    
    int removeStones(vector<vector<int>>& s) {
        map<int,vector<int>> mp;
        int n = s.size();
        vector<vector<int>> temp(n);
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(i!=j && (s[j][0]==s[i][0] || s[j][1]==s[i][1]))
                    temp[i].push_back(j);
            }
        }
        int res=0;
        
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                res++;
                vis[i] = 1;
                
                for(int j=0;j<temp[i].size() ;j++)
                {
                    if(!vis[temp[i][j]]) solve(temp, temp[i][j], vis);
                }
            }
            
        }
        return n-res;
    }
};