//------------------------------approach 1 ---------------------------------------

void printUniqueSubsets(int ind, vector<int>&ds, set<vector<int>>&ans, vector<int>arr){
    if(ind == arr.size()){
        ans.insert(ds);
        return;
    }
    ds.push_back(arr[ind]);
    printUniqueSubsets(ind+1, ds, ans, arr);
    ds.pop_back();
    printUniqueSubsets(ind+1, ds, ans, arr);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int>ds;
    set<vector<int>>ans;
    printUniqueSubsets(0,ds, ans, arr);
    vector<vector<int>>res(ans.begin(), ans.end());
    return res;
}

//------------------------------approach 2 ---------------------------------------


class Solution {
public:
    
    void printUniqueSubsets(int ind, vector<int>&ds, vector<vector<int>>&ans, vector<int>arr, int n){ 
    
        ans.push_back(ds);
        for(int i=ind; i<n; i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            printUniqueSubsets(i+1, ds, ans, arr, n);
            ds.pop_back();
        }
    }

    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int>ds;
        vector<vector<int>>ans;
        int n = arr.size();
        printUniqueSubsets(0,ds, ans, arr, n);
        return ans;
    }
};
