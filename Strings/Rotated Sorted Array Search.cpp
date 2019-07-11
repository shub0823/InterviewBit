/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
You are given a target value to search. If found in the array, return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Input : [4 5 6 7 0 1 2] and target = 4
Output : 0
NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
https://www.interviewbit.com/problems/rotated-sorted-array-search/
*/

int searchKey(const vector<int> &a, int l, int r, int k)
{
    if (l>r)
        return -1;
    
    int mid = (l+r)>>1;
    
    if (a[mid] == k)
        return mid;
    
    //if l....mid is sorted
    if (a[l] <= a[mid]) {
        if (k >= a[l] && k<a[mid])
            return searchKey(a,l, mid-1, k);
            
        else
            return searchKey(a, mid+1, r, k);
    }
    
    //if mid....r is sorted
    else if (a[mid] <= a[r]) {
        if (k>=a[mid] && k<a[r])
            return searchKey(a, mid+1, r, k);
        else
            return searchKey(a, l, mid, k);
    }
}


int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    int index =  searchKey(A, 0, n-1, B);
    return index;
}   
