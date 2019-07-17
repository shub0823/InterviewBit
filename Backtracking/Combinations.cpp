/*
https://www.interviewbit.com/problems/combinations/
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
Make sure the combinations are sorted.
To elaborate,
    Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
    Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:
[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
    Example : itertools.combinations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points. 
*/

void comb(int st, int k, vector<vector<int> > &v, vector<int> &a, vector<int> &row)
{
    int n = a.size();
    
    if (row.size() == k) {
        v.emplace_back(row);
        return;
    }
    if (st >= n)
        return;
    
    row.emplace_back(a[st]);
    comb(st+1, k, v, a, row);
    row.pop_back();
    comb(st+1, k, v, a, row);
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > v;
    vector<int> vv;
    
    for (auto i=1; i<=A; i++)
        vv.emplace_back(i);
    vector<int> row;
    comb(0, B, v, vv, row);
    return v;
}
