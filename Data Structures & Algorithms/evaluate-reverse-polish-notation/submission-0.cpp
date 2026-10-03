class Solution {
public:
    stack<int> st;

    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {

                int secondnum = st.top();
                st.pop();

                int firstnum = st.top();
                st.pop();

                if (tokens[i] == "+") {
                    st.push(firstnum + secondnum);
                }
                else if (tokens[i] == "-") {
                    st.push(firstnum - secondnum);
                }
                else if (tokens[i] == "*") {
                    st.push(firstnum * secondnum);
                }
                else {
                    st.push(firstnum / secondnum);
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};