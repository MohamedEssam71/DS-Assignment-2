#include "StackApplication.h"

void StackApplication::longestValidParentheses(std::string s) {
    Stack<char> st;
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            st.push('(');
        }
        else{
            if(st.isEmpty()) continue;
            else{
                st.pop();
                ans+=2;
            }
        }
    }
    std::cout << ans << std::endl;
}

void StackApplication::postFix(std::string s) {
    Stack<char>st;
    std::string post = "";
    int n = s.size();
    for(int i = 0; i < n; ++i){
        if(isalnum(s[i]))post.push_back(s[i]);
        else{
            switch (s[i]) {
                case '+':
                    if(st.isEmpty()) st.push(s[i]);
                    else{
                        while(!st.isEmpty() &&
                        (st.top() == '*' || st.top() == '/' ||
                        st.top() == '^' || st.top() == '-' ||
                        st.top() == '+')){

                            char temp = st.pop();
                            post += temp;
                        }
                        st.push(s[i]);
                    }
                    break;
                case '-':
                    if(st.isEmpty()) st.push(s[i]);
                    else {
                        while (!st.isEmpty() &&
                        (st.top() == '*' || st.top() == '/' ||
                        st.top() == '^' || st.top() == '+' ||
                        st.top() == '-')) {

                            char temp = st.pop();
                            post += temp;
                        }
                        st.push(s[i]);
                    }
                    break;
                case '*':
                    if(st.isEmpty()) st.push(s[i]);
                    else {
                        while (!st.isEmpty() &&
                        (st.top() == '*' ||
                        st.top() == '/' ||
                        st.top() == '^')) {

                            char temp = st.pop();
                            post += temp;
                        }
                        st.push(s[i]);
                    }
                    break;
                case '/':
                    if(st.isEmpty()) st.push(s[i]);
                    else {
                        while (!st.isEmpty() &&
                        (st.top() == '*' ||
                        st.top() == '/' ||
                        st.top() == '^')){

                            char temp = st.pop();
                            post += temp;
                        }
                        st.push(s[i]);
                    }
                    break;
                case '^':
                    st.push(s[i]);
                    break;
                case '(':
                    st.push(s[i]);
                    break;
                case ')':
                    while(!st.isEmpty() && (st.top() != '(')){
                        char temp = st.pop();
                        post += temp;
                    }
                    st.pop();
                    break;
            }
        }
    }
    while(!st.isEmpty()){
        post += st.pop();
    }
    std::cout << post << std::endl;
}
