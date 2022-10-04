    bool isPalindrome(int x) {
        if(x<0) return false;
        int fast=x,slow=x,rhalf=0;
        while(fast/10){
            rhalf = rhalf*10 + slow%10;
            slow /= 10;
            fast /= 100;
        }
        return fast==0?rhalf==slow:slow/10==rhalf; 
    }
