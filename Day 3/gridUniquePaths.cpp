// approach 1 - Recursion
class Solution {
public:
    int countpaths(int i,int j, int m, int n){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        return countpaths(i+1, j, m, n) + countpaths(i, j+1, m, n);
    }
    
    int uniquePaths(int m, int n) {
        return countpaths(0,0,m,n);
    }
};


// approach 2 - DP
class Solution {
public:
    int countpaths(int i,int j, int m, int n, vector<vector<int>>&dp){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = countpaths(i+1, j, m, n, dp) + countpaths(i, j+1, m, n, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countpaths(0,0,m,n,dp);
    }
};


// approach 3 - Combinomatrics
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double ans = 1;
        
        for(int i=1; i<=r; i++){
            ans = ans * (N-r+i)/i;
        }
        
        return (int) ans;
    }
};
