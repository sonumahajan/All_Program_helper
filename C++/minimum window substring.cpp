/*  Given two strings s and t of lengths m and n respectively, return the minimum window substring 
    of s such that every character in t (including duplicates) is included in the window. 
    If there is no such substring, return the empty string "".
    A substring is a contiguous sequence of characters within the string.
    Example:
      Input: s = "ADOBECODEBANC", t = "ABC"
      Output: "BANC"
*/

class Solution {
public:
    string minWindow(string S, string T) {
        string result;
        if(S.empty() || T.empty())
            return result;
        
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for(int i = 0; i < T.length(); i++){
            map[T[i]]++;
        }
        int minLength = INT_MAX;
        int letterCounter = 0;
        for(int left = 0, right = 0; right < S.length(); right++){
            char c = S[right];
            if(map.find(c) != map.end()){
                window[c]++;
                if(window[c] <= map[c]){
                    letterCounter++;
                }
            }
            if(letterCounter >= T.length()){
                while(map.find(S[left]) == map.end() || window[S[left]] > map[S[left]]){
                    window[S[left]]--;
                    left++;
                }
                if(right - left + 1 < minLength){
                    minLength = right - left + 1;
                    result = S.substr(left, minLength);
                }
                // shrink the window here
                window[S[left]]--;
                left++;
                letterCounter--;
            }
        }
        return result; 
    }
};
