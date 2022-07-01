//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

//Approach 1

void setZeros(vector<vector<int>> &matrix)
{
    vector<int>rows(matrix.size(), -1);
    vector<int>cols(matrix[0].size(), -1);
	for(int i = 0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(rows[i] == 0 || cols[j] == 0) matrix[i][j] = 0;
        }
    }
}

//Approach 2

void setZeros(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
	int col0 = 1; 
    for(int i=0; i<rows; i++){
        if(matrix[i][0] == 0) col0 = 0;
         for(int j=1; j<cols; j++){
              if(matrix[i][j] == 0){
                      matrix[i][0] = matrix[0][j] = 0;
              }
         }
    }
    for(int i=rows-1; i>=0; i--){
        for(int j=cols-1; j>=1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
        if (col0 == 0) matrix[i][0] = 0;
    }
    
}
