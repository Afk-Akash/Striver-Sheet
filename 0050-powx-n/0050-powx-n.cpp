class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n <= 0) return ans/powerNeg(x,n);
        return power(x,n);
    }
    
    double power(double x, int n){
        if(n==0) return 1;
        if(n == 1 ) return x;
        
        if(n%2) return power(x, n-1)*x;
        else {
            double temp = power(x, n/2);
            return temp * temp;
        }
    }
    
    double powerNeg(double x, int n){
        if(n==0) return 1;
        if(n == -1) return x;
        
        if(n%2) return powerNeg(x, n+1)*x;
        else {
            double temp = powerNeg(x, n/2);
            return temp * temp;
        }
    }
};