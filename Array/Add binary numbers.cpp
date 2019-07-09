/*Given two binary strings, return their sum (also a binary string).
Example:
a = "100"
b = "11"
Return a + b = “111”.*/

void swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void rev(string &s)
{
    int n=s.size();
    
    for (int i=0; i<n/2; i++)
        swap(s[i], s[n-1-i]);
}

string Solution::addBinary(string A, string B) {
    
    int m=A.size()-1;
    int n=B.size()-1;
    int carry=0;
    int a,b;
    string res="";
    string s1,s2;
    
    while (m>=0 || n>=0) {
        if (m != -1) {
            s1 = A[m];
            a = stoi(s1);
        }
        else
            a=0;
        
        if (n != -1) {
            s2 = B[n];
            b = stoi(s2);
        }
        else
            b=0;
        
        if (a+b+carry == 0) {
            res += '0';
            carry = 0;
        }
        
        else if (a+b+carry == 1) {
            res += '1';
            carry = 0;
        }
        
        else if (a+b+carry == 2) {
            res += '0';
            carry = 1;
        }
        
        else if (a+b+carry == 3) {
            res += '1';
            carry = 1;
        }
        
        if (m != -1)
            m--;
        if (n != -1)
            n--;
    }
    
    if (carry == 1) {
        res += '1';
    }
    
    rev(res);
    
    
    return res;
}
