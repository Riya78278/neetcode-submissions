class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for(int i = 0; i < strs.size(); i++) {
            ans += to_string(strs[i].size());
            ans += '#';
            ans += strs[i];
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '#') {

                int len = stoi(temp);
                temp = "";

                i++;

                string str = "";

                for(int j = 0; j < len; j++) {
                    str += s[i];
                    i++;
                }

                ans.push_back(str);

                i--;
            }
            else {
                temp += s[i];
            }
        }

        return ans;
    }
};