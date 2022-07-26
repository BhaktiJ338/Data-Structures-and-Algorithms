void solve(int ind, vector<int>&ds, vector<int>arr, vector<int>&ans, int sum){
    if(ind == arr.size()){
        ans.push_back(sum);
        return ;
    }
    ds.push_back(arr[ind]);
    sum += arr[ind];
    solve(ind+1, ds, arr, ans, sum);
    ds.pop_back();
    sum -= arr[ind];
    solve(ind+1, ds, arr, ans, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int>ans;
    vector<int>ds;
    solve(0, ds, num, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
