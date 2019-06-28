/*

Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

*/

vector<int> max_subarray_non_neg_int(vector<int> &A)
{
    int n = A.size();
    int i=0, maxNumber = 0, pos_count = 0,start = 0, end=-1;
    int final_start = -1, final_end = -1;
    long long int sum=0, maxSum = 0;

    vector<int> res;

    while (i<n) {
        if (A[i] >= 0) {
            sum += A[i];
            pos_count++;
            end++;
        }
        if (sum>maxSum) {
            maxSum = sum;
            final_start = start;
            final_end = end;
        }
        else if (maxSum == sum && pos_count>maxNumber) {
            maxNumber = pos_count;
            final_start = start;
            final_end = end;
        }

        if (A[i] < 0) {
            pos_count = 0;
            start = i+1;
            end = i;
            sum = 0;
        }

        i++;
    }

    if (final_start != -1 && final_end != -1) {
        for (int i=final_start; i<=final_end; i++)
            res.push_back((A[i]));
    }

    return res;
}
