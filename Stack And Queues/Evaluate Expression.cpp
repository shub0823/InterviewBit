/*
https://www.interviewbit.com/problems/evaluate-expression/
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

int Solution::evalRPN(vector<string> &A) {
    //take one by one the elements (strings) of vector
    string s = A.back();
    A.pop_back();
    
    //check whether the string is associated to any operator
    if (s=="+" or s=="-" or s=="*" or s=="/") {
        int op2 = evalRPN(A);
        int op1 = evalRPN(A);
        
        if (s=="+")
            return op1+op2;
        if (s=="-")
            return op1-op2;
        if (s=="*")
            return op1*op2;
        if (s=="/")
            return op1/op2;
    }
    else
        return stoi(s);
}
