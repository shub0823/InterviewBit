

/*Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.*/

bool check(int a, int b)
{
    string aa = to_string(a);
    string bb = to_string(b);
    
    string s1 = aa + bb;
    string s2 = bb + aa;
    
    return (s1 > s2) ? true : false;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> copy = A;
    
    sort(copy.begin(), copy.end(), check);
    
    string ans= "";
    for (int i=0; i<copy.size(); i++)
        ans += to_string(copy[i]);
    
    if (ans[0] == '0')
        return "0";
    
    return ans;
}
