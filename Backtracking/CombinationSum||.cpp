/*
e integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :
Given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
https://www.interviewbit.com/problems/combination-sum-ii/
*/

void combUtil(int st, vector<int> &row, int sum, vector<vector<int> >&res, vector<int> &a, int k)
{
    if (sum == k) {
        res.emplace_back(row);
        return;
    }
    
    if (sum>k || st == a.size())
        return;
    
    row.emplace_back(a[st]);
    sum += a[st];
    combUtil(st+1, row, sum, res, a, k);
    
    sum -= row[row.size()-1];
    row.pop_back();
    
    for (auto end=st+1; end<a.size() && a[st] == a[end]; ++end)
        st++;
    
    combUtil(st+1, row, sum, res, a, k);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end());
    vector<vector<int> >res;
    vector<int> row;
    
    combUtil(0, row, 0, res, A, B);
    
    return res;
}

