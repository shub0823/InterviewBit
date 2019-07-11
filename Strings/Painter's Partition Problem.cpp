/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much
time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that
any painter will only paint contiguous sections of board.
2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003
Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board
Output:
     return minimum time to paint all boards % 10000003
Example
Input : 
  K : 2
  T : 5
  L : [1, 10]
Output : 50
https://www.interviewbit.com/problems/painters-partition-problem/
*/

#define ll long long

bool isPossible (ll int mid, vector<int> &v, int k)
{
    int max_ele = *max_element(v.begin(), v.end());
    
    if (max_ele > mid)
        return false;
    
    ll int sum=0;
    int cnt=1;
    
    for (int i=0; i<v.size();) {
        if ((sum + (ll int)v[i]) > mid) {
            cnt++;
            sum=0;
        }
        else {
            sum += (ll int)v[i];
            i++;
        }
            
    }
    
    if (cnt <= k)
        return true;
    
    return false;
}


int Solution::paint(int A, int B, vector<int> &C) {
    
    ll int start=0, end=0;
    
    for (int i=0; i<C.size(); i++)
        end += C[i];
    
    ll int sol = INT_MAX;
    
    while (start <= end) {
        ll int mid = (end+start)/2;
        if (isPossible(mid, C, A)) {
            sol = min(sol, mid);
            end = mid-1;
        }
        else
            start = mid+1;
    }
    
    return (sol * (ll int)B) % 10000003;
}
