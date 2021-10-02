//problem link:https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char,int> m={{'I',1},
                                  {'V'  ,     5},
                                  {'X'  ,    10},
                                  {'L'  ,    50},
                                  {'C'  ,    100},
                                  {'D'  ,   500},
                                  {'M'  ,  1000}};
        int result=m[s.back()];
        for(int i=s.length()-2;i>=0;i--)
        {
            if(m[s[i]]<m[s[i+1]])
            {
                result-=m[s[i]];
            }
            else{
                result+=m[s[i]];
            }
        }
        return result;
    }
};
