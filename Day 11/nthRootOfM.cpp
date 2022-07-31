
double multiply(double mid, int n){
    double prod = 1.0000;
    while( n > 0){
        prod = prod*mid;
        n--;
    }
    return prod;
}
//function to find nth root of m rounded upto to 6 decimal places using binary search
double findNthRootOfM(int n, long long m) {
	double low = 0, high = m+1, temp = 1e-8;
    while((high - low) > temp){
        double mid = (low+high)/2.0000;
        if(multiply(mid, n) < double(m)){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}
