/*
https://www.interviewbit.com/problems/rain-water-trapped/
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Example :
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
//method 1

int Solution::trap(const vector<int> &A) {
    int l=0, r = A.size()-1;
    int lMax=0, rMax=0, vol=0;
    
    while (l<r) {
        if (A[l]<A[r]) {
            if (A[l] >= lMax)
                lMax = A[l];
            else
                vol += lMax-A[l];
            ++l;
        }
        else {
            if (A[r] >= rMax)
                rMax = A[r];
            else
                vol += rMax-A[r];
            --r;
        }
    }
    return vol;
}

//method 2
int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    
    left[0] = A[0];
    for (int i=1; i<n; i++)
        left[i] = max(left[i-1], A[i]);
    
    right[n-1] = A[n-1];
    for (int i=n-2; i>=0; i--)
        right[i] = max(right[i+1], A[i]);
    
    int vol=0;
    for (int i=0; i<n; i++)
        vol += min(left[i], right[i]) - A[i];
    return vol;
}

