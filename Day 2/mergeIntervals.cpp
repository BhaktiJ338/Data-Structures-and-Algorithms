vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    
    if(intervals.size() <= 1) return intervals;
    
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>>vec;
    vec.push_back(intervals[0]);
    
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0] <= vec.back()[1]){
            vec.back()[1] = max(vec.back()[1], intervals[i][1]);
        }
        else{
            vec.push_back(intervals[i]);
        }
    }
    return vec;
}
