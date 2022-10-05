    int lengthOfLongestSubstring(string s) {
          unordered_set<char>st;
        int ans=0;
        int i=0;
        for(int j=0; j<s.size();){
            if(st.find(s[j])==st.end()){
                st.insert(s[j++]);
                ans=max(ans, j-i);
            }
            else
                st.erase(s[i++]);                
        }
        return ans;
    }
