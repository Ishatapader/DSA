class Solution {
public:
    string decodeString(string s) {
        stack<int> numberStack;
        stack<string> stringStack;
        string currString = "";
        int currNum = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            } else if (ch == '[') {
                stringStack.push(currString);
                numberStack.push(currNum);
                currNum = 0;
                currString = "";
            } else if (ch == ']') {
                int repeated = numberStack.top();
                numberStack.pop();
                string prev = stringStack.top();
                stringStack.pop();
                string temp = "";
                for (int i = 0; i < repeated; i++) {
                    temp += currString;
                }
                currString = prev + temp;
            } else {
                currString += ch;
            }
        }
        return currString;
    }
};