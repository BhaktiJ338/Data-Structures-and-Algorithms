//----------------------------------------------approach 1 ---------------------------------------------

class Solution {
	void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
		vector < vector < int >> & vis) {
		if (i == n - 1 && j == n - 1) {
			ans.push_back(move);
			return;
		}

		// downward
		if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
			vis[i][j] = 1;
			solve(i + 1, j, a, n, ans, move + 'D', vis);
			vis[i][j] = 0;
		}

		// left
		if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
			vis[i][j] = 1;
			solve(i, j - 1, a, n, ans, move + 'L', vis);
			vis[i][j] = 0;
		}
		// right 
		if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
			vis[i][j] = 1;
			solve(i, j + 1, a, n, ans, move + 'R', vis);
			vis[i][j] = 0;
		}

		// upward
		if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
			vis[i][j] = 1;
			solve(i - 1, j, a, n, ans, move + 'U', vis);
			vis[i][j] = 0;
		}

	}
	public:
		vector < string > findPath(vector < vector < int >> & m, int n) {
			vector < string > ans;
			vector < vector < int >> vis(n, vector < int > (n, 0));

			if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis);
			return ans;
		}
};

//----------------------------------------------approach 2 ---------------------------------------------

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>>&mat, int n, vector<string>&ans, string path, vector<vector<int>>&visited, int diri[], int dirj[]){
        
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        string dir = "DLRU";
        for(int k=0; k<4; k++){
            int nexti = i + diri[k];
            int nextj = j + dirj[k];
            
            if(nexti < n && nextj < n && nexti >= 0 && nextj >= 0 && !visited[nexti][nextj] && mat[nexti][nextj] == 1){
                visited[i][j] = 1;
                solve(nexti, nextj, mat, n, ans, path+dir[k], visited, diri, dirj);
                visited[i][j] = 0;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        vector<string>ans;
        int diri[] = {1, 0, 0, -1};     //deviations of i in DLRU directions resp
        int dirj[] = {0, -1, 1, 0};     //deviations of j in DLRU directions resp
        vector<vector<int>>visited(n, vector<int>(n, 0));
        if(mat[0][0] == 1) solve(0, 0, mat, n, ans, "", visited, diri, dirj);
        return ans;
    }
};
