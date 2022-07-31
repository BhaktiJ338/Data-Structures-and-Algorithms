
int countLesserThanEqualMid(int mid, vector<int>&row){
    int low = 0, high = row.size()-1;
    while(low <= high){
        int m = (low+high)/2;
        if(row[m] <= mid) low = m+1;
        else high = m-1;
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low = 0, high = 1e5;
    int row = matrix.size(), col = matrix[0].size();
    
    while(low <= high){
        int mid = (low+high)/2;
        int cnt = 0;
        for(int i=0; i<row; i++)
            cnt += countLesserThanEqualMid(mid, matrix[i]);
        if(cnt <= (row*col)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}
