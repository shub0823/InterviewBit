/*
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.
Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.
https://www.interviewbit.com/problems/letter-phone/
*/

string temp="";
unordered_map<char, string> keypad = {
    { '1', "1" },
    { '2', "abc" },
    { '3', "def" },
    { '4', "ghi" },
    { '5', "jkl" },
    { '6', "mno" },
    { '7', "pqrs" },
    { '8', "tuv" },
    { '9', "wxyz" },
    { '0', "0" }
};

void letterComb(int i, string digits, vector<string> &res)
{
    if (digits[i]-'0' >= 0 && digits[i] <= 9) {
        string s = keypad[digits[i]];
        
        for (auto j=0; j<s.length(); ++j) {
            temp += s[j];
            
            if (i == digits.length()-1)
                res.emplace_back(temp);
            else
                letterComb(i+1, digits, res);
            
            temp.pop_back();
        }
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> res;
    letterComb(0, A, res);
    
    return res;
}
