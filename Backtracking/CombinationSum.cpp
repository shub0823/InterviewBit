/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:
[2, 2, 3]
[7]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
See Expected Output
https://www.interviewbit.com/problems/combination-sum/
*/

void combSum(int st, vector<int>&row, int sum, vector<vector<int> >&res, vector<int>&a, int k)
{
    if (sum == k) {
        res.emplace_back(row);
        return;
    }
    
    if (sum>k || st == a.size())
        return;
    
    row.emplace_back(a[st]);
    sum += a[st];
    combSum(st, row, sum, res, a, k);
    sum -= row[row.size()-1];
    row.pop_back();
    combSum(st+1, row, sum, res, a, k);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> >res;
    vector<int> a,row;
    sort(A.begin(), A.end());
    
    a.emplace_back(A[0]);
    
    for (int i=1; i<A.size(); i++)
        if (A[i-1] != A[i])
            a.emplace_back(A[i]);
    
    combSum(0, row, 0, res, a, B);
    return res;
}
