/*

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/

vector<int> Solution::plusOne(vector<int> &A) 
{
    int n = A.size()-1;

    if (A[n] < 9)
        A[n]++;
        
    else {
        A[n] = 0;
        //case where the number is 1 digit only so we just need to insert 1 before 0
        if (n==0)
            A.insert(A.begin(), 1);
        else {
            A[n-1]++;
        }

        n--;

       //loop till we encounter every digit of array and check whether it is greater than 10 or not
        while (A[n] >= 10) {
            A[n] = 0;
            if (n==0) {
                A.insert(A.begin(), 1);//carry from previous digit as it was greater than or equal to 10
                break;//since we have traversed first digit of number (most important digit)
            }
            else {
                A[n-1]++;
            }
            n--;
        }
    }

    //remove the initial zeros as they are of no meaning, that is, 000123 is 123
    while (*A.begin() == 0)
        A.erase(A.begin());

    return A;
}
