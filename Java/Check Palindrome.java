
class Solution {
    int isPlaindrome(String S) {
        // code here
        char c[]=S.toCharArray();
        int flag=0;
        int n=S.length();
        for(int i=0;i<(n/2)+1;i++){
            if(c[i]==c[n-1-i]){
                flag=1;
            }
            else{
                flag=0;
                break;
            }
        }
        if(flag==1){
            return(1);
        }
        else{
            return(0);
        }
    }
};
