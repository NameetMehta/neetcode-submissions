class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(it!="+" && it!="-" && it!="*" && it!="/"){
                st.push(stoi(it));
            }
            else if(it=="+"){
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                st.push(first+second);
            }
            else if(it=="-"){
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                st.push(second-first);
            }
            else if(it=="*"){
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                st.push(first*second);
            }
            else if(it=="/"){
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                st.push(second/first);
            }
        }
        return st.top();
    }
};
