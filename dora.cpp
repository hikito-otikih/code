#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() ; 
        vector<int>pos(n) ; 
        vector<vector<int>>g(n/2) ; 
        for(int i = 0 ; i < n ; i++){
            pos[row[i]] = i/2; 
        }
        for(int i=0;i<n;i++)
        {
            if(row[i]%2==0)
            {
                g[i/2].push_back(pos[row[i]+1]) ;  
            }
            else 
            {
                g[i/2].push_back(pos[row[i]-1]) ; 
            }
        }
        vector<int>vis(n/2,0) ; 
        auto dfs = [&](int u,auto&& dfs_ref)->int
        {
            vis[u] = 1; 
            for(auto v : g[u])
            {
                if(!vis[v])
                {
                    return dfs_ref(v,dfs_ref)+1 ; 
                }
            }
            return 1 ; 
        };
        int res = 0 ; 
        for(int i=0;i<n/2;i++)
        {
            if(!vis[i])
            {
                res+=dfs(i,dfs)-1 ; 
            }
        }
        return res ; 
    }
};


int main()
{
    vector<int> test = {5 ,0 ,3 ,4, 2 ,1}; 
    Solution s;
    int result = s.minSwapsCouples(test);
    cout << "Minimum swaps needed: " << result << endl;
}