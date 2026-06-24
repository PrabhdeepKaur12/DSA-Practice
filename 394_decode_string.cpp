class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;

        string current = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                counts.push(num);
                resultStack.push(current);

                num = 0;
                current = "";
            }
            else if (ch == ']') {
                int repeat = counts.top();
                counts.pop();

                string previous = resultStack.top();
                resultStack.pop();

                string temp = "";
                while (repeat--) {
                    temp += current;
                }

                current = previous + temp;
            }
            else {
                current += ch;
            }
        }

        return current;
    }
};