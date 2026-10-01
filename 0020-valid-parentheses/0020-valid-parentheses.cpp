class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        if(s[0] == ')' || s[0] == '}' || s[0] == ']' || s[n-1] == '(' || s[n-1] == '{' || s[n-1] == '['){
            return false;
        }
        for(int i =0; i <n;i++){
            if(st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(!st.empty() && s[i] == ')'){
                    if(st.top() != '(') return false;
                    st.pop();
                }
                else if(!st.empty() && s[i] == '}'){
                    if(st.top() != '{') return false;
                    st.pop();
                }
                else if(!st.empty() && s[i] == ']'){
                    if(st.top() != '[') return false;
                    st.pop();
                }
            }
        }
        return st.empty() ? true : false;
    }
};