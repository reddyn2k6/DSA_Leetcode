class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long prod=1;
        int k=n;
        while(n>0) {
            int temp=n%10;
            sum+=temp;
            prod*=temp;
            n=n/10;
        }
cout<<sum<<" "<<prod<<endl;
        return (
            k%(sum+prod)==0);
    }
};