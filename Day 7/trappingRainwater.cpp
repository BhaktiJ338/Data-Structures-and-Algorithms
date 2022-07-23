//---------------------------approach 1 -------------------------

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = 1;
        int ans = 0;
        for(int i=0; i<n; i++){
            int lmax = height[i], rmax=height[i];
            for(int j=0; j<=i; j++){
                lmax = max(lmax, height[j]);
            }
            for(int j=i; j<n; j++){
                rmax = max(rmax, height[j]);
            }
            ans += min(lmax, rmax) - height[i];
        }
        return ans;
    }
};

//---------------------------approach 2 ------------------------
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int>prefix(n, 0);
        vector<int>suffix(n, 0);
        prefix[0] = height[0];
        suffix[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
        for(int i=n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }
        for(int i=0; i<n; i++){
            ans += min(prefix[i], suffix[i])-height[i];
        }
        return ans;
    }
};

//---------------------------approach 3 -------------------------

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l=0, r=n-1, leftmax=0, rightmax=0;
        while(l <= r){
            //there is bar at right which is greater than or equal to left bar
            if(height[l] <= height[r]){
                //if left bar height is greater than leftmax, update leftmax
                if(height[l] >= leftmax) 
                    leftmax = height[l];
                //else leftmax itself is the bar with max height, 
                else
                    ans += leftmax - height[l];//gives water trapped at ith index
                l++;
            }
            //left bar is greater than right bar
            else{
                //if right bar height is greater than rightmax, update rightmax
                if(height[r] >= rightmax) 
                    rightmax = height[r];
                //else rightmax itself is the bar with max height, 
                else
                    ans += rightmax - height[r];
                r--;
            }
        }
        
        return ans;
    }
};
