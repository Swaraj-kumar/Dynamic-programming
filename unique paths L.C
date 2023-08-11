/*we are trying to traverse grids from (m-1 n-1) to (0,0)
we will calculate total paths to reach (0,0)
if we reach (0,0) then we return 1 else if we are reaching out of bound then return 0
since we can travel either left or up we keep adding up to which ever path we move to i.e left + up
*/

// RECURSSION
// T.c -> O(2^m*n), S.C -> O(n)
// s.c -> o((m-1,n-1)*(n*m) here m-1,n-1 is path length

class Solution {
public:
    int fun(int i,int j){
        if(i == 0 && j == 0)return 1;
        if(i < 0 || j < 0)return 0;
        
        int left = fun(i,j-1);
        int up = fun(i-1,j);
        return (up + left);
    }
    
    int uniquePaths(int m, int n) {
        return fun(m-1,n-1);
    }
};

Approach 2(Memoization)
T.c - > o(n*m)
s.c -> o((m-1,n-1)*(n*m) here m-1,n-1 is path length and n*m is dp size

class Solution {
public:
    int fun(int i,int j,vector<vector<int>> &dp){
        if(i == 0 && j == 0)return 1;
        if(i < 0 || j < 0)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int left = fun(i,j-1,dp);
        int up = fun(i-1,j,dp);
        return dp[i][j] = (up + left);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp);
    }
};


Approach 3(Tabulation)
T.c - > o(n*m)
s.c -> o(n*m) 

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                int up = 0,left = 0;
                if(i > 0)up = up + dp[i-1][j];
                if(j > 0)left = left + dp[i][j-1];
                
                dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


Approach 4(Space Optimization)
T.c - > o(n*m)
s.c -> o(n*m) 


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }
                else{
                int up = 0,left = 0;
                if(i > 0)up = prev[j];
                if(j > 0)left = curr[j-1];
                
                curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};


