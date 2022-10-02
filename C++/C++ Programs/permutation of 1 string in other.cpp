Question-

Suppose we have two strings s1 and s2, we have to write a function to return true if s2 contains the permutation of s1. So we can say that one of the first string's permutations is the substring of the second string. 

Input-
"abc"
"findcab"
Output-
1


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   bool checkInclusion(string s1, string s2) {
      vector <int> cnt1(26), cnt2(26);
      for(int i = 0; i < s1.size(); i++)cnt1[s1[i] - 'a']++;
      int j = 0;
      int required = s1.size();
      for(int i = 0; i < s2.size(); i++){
         char x = s2[i];
         cnt2[x - 'a']++;
         if(cnt1[x - 'a'] && cnt2[x - 'a'] <= cnt1[x - 'a']) required--;
         while(j <= i && cnt2[s2[j] - 'a'] - 1 >= cnt1[s2[j] - 'a']){
            cnt2[s2[j] - 'a']--;
            j++;
         }
         if(i - j + 1 == s1.size() && required == 0){
            return true;
         }
      }
      return false;
   }
};
main(){
   Solution ob;
   cout << (ob.checkInclusion("abc", "findcab"));
}