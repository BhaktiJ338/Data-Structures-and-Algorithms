//approach 1
//TLE
long long getInversions(long long *arr, int n){
    // Write your code here.
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(i<j && arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

//approach 2

long long merge(long long *nums, int l, int m, int r){
    long long cnt = 0;
        int tmp[r - l + 1];
        int i = l; // index for left subarray
        int j = m+1; // index for right subarray
        int k = 0; // index for temporary array
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
            else {
                tmp[k++] = nums[j++];
                cnt += m+1-i;
            }
        }
        while(i <= m) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++]; 
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
        return cnt;
    }
    
    // mergeSort(nums, 0, nums.size() - 1);
    long long mergeSort(long long *nums, int l, int r){
        long long cnt = 0;
        if(l >= r) return 0;
        int m = l + (r - l) / 2; //middle index, same as (l+r)/2
        cnt+= mergeSort(nums, l, m);
        cnt+= mergeSort(nums, m + 1, r);
        cnt+=merge(nums, l, m, r);
        return cnt;
    }
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long cnt = mergeSort(arr, 0, n-1);
    return cnt;
}
