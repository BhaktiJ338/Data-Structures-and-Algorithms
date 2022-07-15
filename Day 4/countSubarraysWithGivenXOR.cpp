int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int count = 0, xxor=0;
    int n = arr.size();
    unordered_map<int, int>mp;
    for(int i =0; i<n; i++){
        //xxor stores xor of elements till ith element
        xxor = xxor ^ arr[i];
        //if curr xor = required xor , increment count
        if(xxor == x) count++;
        //if currxor XOR required xorr already exist in map 
        //count will be count + freq of currxor & required xorr
        // If above XOR exists in map, then there is another previous prefix with same             XOR, i.e., there is a subarray ending at i with XOR equal to B.
        if(mp.find(xxor ^ x) != mp.end()) count += mp[xxor ^ x];
        //everytime u r going to update/increment freq of currxor
        mp[xxor]++;
    }
    return count;
}
