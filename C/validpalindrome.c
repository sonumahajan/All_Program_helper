bool isPalindrome(char * s){
      char str[200001] = {0};
    for (int i = 0, j = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
            str[j] = s[i];
            j++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            str[j] = s[i] - 'A'+ 'a';
            j++;
        }
    }
    for (int i = 0, j = strlen(str) - 1; i <= j; i++, j--) {
        if (str[i] != str[j])
            return false;
    }
    return true;

}