    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case ')': if (paren.empty() || paren.top()!='(') 
                    return false; 
                          else
                          paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{')return false; 
                          else
                          paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[')return false; 
                          else
                          paren.pop(); break;
                default: paren.push(c); // pass
            }
        }
        return paren.empty() ;
    }
