//approach 1
//find all possible permutations , print permutation
//that appears right after input permutation.

//approach 2
//using c++ in-Built function

//approach 3
vector<int> nextPermutation(vector<int> &p, int n)
{
    //  Write your code here.
    if(p.size() <= 1) return p;
    int ind1, ind2;
    for(ind1=n-2; ind1>=0; ind1--)
        if(p[ind1] < p[ind1+1]) break;
    
    if(ind1 < 0){
        reverse(p.begin(), p.end());
        return p;
    }
    else{
        for(ind2=n-1; ind2>ind1; ind2--)
            if(p[ind2] > p[ind1]) break;
        
        swap(p[ind1], p[ind2]);
        reverse(p.begin()+ind1+1, p.end());
        return p;
    }
}
