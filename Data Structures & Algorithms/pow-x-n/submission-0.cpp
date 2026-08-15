class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0;
        double ans=1;
        int m=abs(n);
        while(m){
            if(m&1) ans*=x;
            x*=x;
            m/=2;
        }
        return n>=0?ans:1/ans;
    }
};
