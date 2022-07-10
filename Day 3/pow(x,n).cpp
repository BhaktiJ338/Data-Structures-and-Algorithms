//using binary expontiation

class Solution {
public:
    
    double myPow(double x, int n) {
        double ans = 1;
        long pow = n;
        if(pow<0) 
            pow = -1 * pow;
        while(pow>0){
            if(pow%2==0){
                x = x * x;
                pow = pow/2;
            }else if(pow%2!=0){
                ans = ans*x;
                pow = pow-1;
            }
        }
        if(n<0) ans = (double) (1.0) / double(ans);
        return ans;
    }
};
