struct element{
    enum { _int, _char } type;
    union { int ival; char cval; } val;
};

inline void push_int(stack<element> &result,int num){
    element e; e.type = element::_int; e.val.ival = num;
    result.push(e);
}

inline void push_back_int(vector<element> &result,int num){
    element e; e.type = element::_int; e.val.ival = num;
    result.push_back(e);
}

inline void push_back_char(vector<element> &result,char ch){
    element e; e.type = element::_char; e.val.cval = ch;
    result.push_back(e);
}

vector<element> InfixToPostfix(string expr){
    vector<element> result;
    stack<char> S;
    for(int i=0;i<(int)expr.size();i++){
        if(expr[i] == '(') S.push(expr[i]);
        else if(expr[i] == ')'){
            while(!S.empty() and S.top() != '('){ push_back_char(result,S.top()); S.pop(); }
            S.pop();
        }
        else if(expr[i] == '+' or expr[i] == '-'){
            while(!S.empty() and S.top() != '('){ push_back_char(result,S.top()); S.pop(); }

            S.push(expr[i]);
        }
        else if(expr[i] == '*' or expr[i] == '/' or expr[i] == '%'){
            while(!S.empty() and S.top() != '(' and S.top() != '+' and S.top() != '-'){ push_back_char(result,S.top()); S.pop(); }
            S.push(expr[i]);
        }
        else{
            int num = expr[i] - '0';
            while('0' <= expr[i+1] and expr[i+1] <= '9'){ num *= 10; num += expr[i+1] - '0'; }
            push_back_int(result,num);
        }
    }
    while(!S.empty()) push_back_char(result,S.top());
    return result;
};

int CalcPostfix(vector<element> expr){
    stack<element> S;
    for(int i=0;i<(int)expr.size();i++){
        if(expr[i].type == element::_int) S.push(expr[i]);
        else{
            int A = S.top().val.ival; S.pop();
            int B = S.top().val.ival; S.pop();
            char op = expr[i].val.cval;
            if(op == '+') push_int(S,A+B);
            else if(op == '-') push_int(S,A-B);
            else if(op == '*') push_int(S,A*B);
            else if(op == '/') push_int(S,A/B);
            else if(op == '%') push_int(S,A%B);
        }
    }
    return S.top().val.ival;
}
