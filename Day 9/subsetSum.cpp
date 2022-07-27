void solve(int ind, vector<int>arr, vector<int>&ans, int sum){
    if(ind == arr.size()){
        ans.push_back(sum);
        return ;
    }
    sum += arr[ind];
    solve(ind+1, arr, ans, sum);
    sum -= arr[ind];
    solve(ind+1, arr, ans, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int>ans;
    solve(0,num, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
