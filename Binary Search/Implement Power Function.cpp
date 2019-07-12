int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    //d is the prime number which will be used to reduce very large int by taking mod to d.
    //thus we have to calculate (x^n) mod d without inbuilt power function
    
    if (n==0)
        return (1 % d);
    
    long long ans=1, base=x;
    
    while (n>0) {
        if (n % 2 == 1) {
            ans = (ans * base) % d;
            n--;
        }
        else {
            base = (base * base) % d;
            n /= 2;
        }
    }
    if (ans<0)
        ans = (ans + d) % d;
    
    return ans;
}
