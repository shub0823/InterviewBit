/*
https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest 
rectangle in the histogram.
For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

int Solution::largestRectangleArea(vector<int> &A) {
    
    int n = A.size();
    
    stack<int>  st;
    
    int maxArea = 0;
    int i;
    
    for (i=0; i<n; i++) {
        if (st.empty() || A[i] >= A[st.top()])
            st.push(i);
        else {
            int j = st.top();
            st.pop();
            int w = st.empty() ? i : i-st.top()-1;
            maxArea = max(maxArea, A[j]*w);
            i--;
        }
    }
    while (!st.empty()) {
        int j = st.top();
        st.pop();
        int w = st.empty() ? i : i-st.top()-1;
        maxArea = max(maxArea, A[j]*w);
    }
    
    return maxArea;
}
