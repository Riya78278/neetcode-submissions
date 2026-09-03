class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int previous1=st.top();
                st.pop();
                int previous2=st.top();
                st.pop();
                int sum=previous1+previous2;
                st.push(previous2);
                st.push(previous1);
                st.push(sum);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int first=st.top()*2;
                st.push(first);

            }
            else{
                int num=stoi(operations[i]);
                st.push(num);
            }
        }
        int sum=0;
        while(!st.empty()){
            sum = sum+st.top();
            st.pop();
        }
        return sum;
    }
};