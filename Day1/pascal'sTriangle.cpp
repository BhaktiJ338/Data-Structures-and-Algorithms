class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec{};
        
        for(int i = 0; i<numRows; i++){
            vector<int>v{};
            for(int j = 0; j<i+1; j++){
                if(j==0 || j==i){
                    v.push_back(1);
                }
                else{
                    v.push_back(vec[i-1][j-1] + vec[i-1][j]);
                }
            }
            vec.push_back(v);
        }
        return vec;
    }
   
};


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec(numRows);
        for(int i=0; i<numRows; i++){
            vec[i].resize(i+1);
            vec[i][0]= vec[i][i]= 1;
                for(int j=1; j<i; j++){
                    vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
                }
            
        }
        return vec;
    }
};
