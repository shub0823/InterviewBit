/*
/*Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space. This is a function problem and we had to complete below function.
*/

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    
    //variable used for segregating positve(starts with 1) and non-positive(-ve and 0) numbers in given vector
    int j=0;
    
    //segregating the numbers such that all non-positive numbers appear on left side  and positive on right side of index j 
    for (int i=0; i<n; i++) {
        if (A[i] <= 0) {
            swap(A[i], A[j]);
            j++;
        }
    }
    
    //use array elements as index and to make its presence, we change the positive value to negative
    for (int i=j; i<n; i++) {
        
        //abs(A[i])+j-1 because index starts from 0 while positive number starts with 1
        if (abs(A[i])+j-1 >= 0 && abs(A[i])+j-1 < n) {
            if (A[abs(A[i])+j-1]>0)
                A[abs(A[i])+j-1] = -A[abs(A[i])+j-1];
        } 
            
    }
   
    for (int i=j; i<n; i++)
        if (A[i] > 0)
            return i-j+1;    //returning i-j+1 because indexing starts with 0 and we had used array elements as index
    
    return (n-j+1);
}
