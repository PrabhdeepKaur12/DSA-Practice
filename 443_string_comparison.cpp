class Solution {
public:
    int compress(vector<char>& chars) {
     string result = "";

        int n = chars.size();

        for(int i = 0; i < n; i++) {

            char current = chars[i];

            int count = 1;

            while(i + 1 < n && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }

            result += current;

            if(count > 1) {
                result += to_string(count);
            }
        }

        chars.clear();

        for(char ch : result) {
            chars.push_back(ch);
        }

        return chars.size();
    }
};