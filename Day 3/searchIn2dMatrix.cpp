//approach 1 - linear search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool b = false;
        
            for(int i=0; i<matrix.size(); i++){
                int fe = matrix[i][0];
                int le = matrix[i][matrix[i].size()-1];
                if(target >= fe && target <= le){
                    for(int j=0; j<matrix[i].size(); j++){
                        if(matrix[i][j] == target) b = true;
                    }
                }
            }
        
        return b;
    }
};

//approach 2 - Binary search in one row

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<m; i++){
            if(target >= mat[i][0] && target <= mat[i][n-1]){
                int l=0, h=n-1, mid;
                while(l<=h){
                    mid = l+(h-l)/2;
                    if(mat[i][mid] == target) return true;
                    else if(target < mat[i][mid]){
                        h = mid-1;
                    }
                    else if(target > mat[i][mid]){
                        l = mid+1;
                    }
                }
            }
        }
        return false;
    }
};

//approach 3 - binary search on entire matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        
        int l = 0, h = m*n-1;
        
        while(l<=h){
            int mid = l+(h-l)/2;
            int mid_val = mat[mid/n][mid%n];
            
            if(mid_val == target) return true;
            
            else if(target < mid_val)h = mid-1;
            
            else l = mid+1;
        }
        return false;
    }
};

//gfg version

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int i = 0, j=M-1;

	    while(i < N && j>=0){
	        if(mat[i][j] == X) return 1;
	        else if(X > mat[i][j]) i++;
	        else j--;
	    }
	    return 0;
	}
};
