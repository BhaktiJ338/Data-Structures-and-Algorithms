//------------------------------approach 1 --------------------------------------------

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        int m = v2.size();
        vector<int> v(n+m);
        int i=0,j=0,c=0;
        
        while(i<n&&j<m){
            if(v1[i]<v2[j]){
                v[c++] = v1[i++];
            }else{
                v[c++] = v2[j++];
            }
        }
        
        while(i<n){
            v[c++] = v1[i++];
        }
        while(j<m){
            v[c++] = v2[j++];
        }
        
        if((m+n)==1){
            return v[0];
        }
        
        if((m+n)%2==1){
            return v[(m+n)/2]*1.0;
        }
        else{
            int mid1 = (m+n)/2;
            int mid2 = mid1-1;
            return ((v[mid1]+v[mid2])/2.0);
        }
    }
};


//----------------------------------approach 2 ---------------------------------

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //make sure nums1 is smaller array
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int l = 0, h = n1;
        
        while(l <= h){
            int mid1 = l+(h-l)/2;
            int mid2 = (n1+n2+1)/2 - mid1;
            
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            
            if(l1 <= r2 && l2 <= r1){
                if((n1+n2) % 2 == 0)
                    return (max(l1, l2)+ min(r1, r2))/2.0;
                else
                    return max(l1, l2);
            }
            else if(l1 > r2)
                h = mid1-1;
            
            else if(l2 > r1)
                l = mid1+1;
        }
        return 0.0;
    }
};
