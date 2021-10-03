    // Question Link:
    // https://leetcode.com/problems/check-if-the-sentence-is-pangram/
    public static void main(String[] args) {
        String str = "thequickbrownfo";
        System.out.print(pangram(str));
    }

//    Method-1:

    static boolean pangram(String sentence){
        if(sentence.length() < 26) {
            return false;
        }
        for(Character chr: sentence.toCharArray()){
            if (sentence.indexOf(chr) == -1) {
                return false;
            }
        }
        return true;
    }


//    Method-2:
    static boolean pangram(String sentence){
        boolean[] arr = new boolean[26];
        for (int i=0; i<sentence.length(); i++) {
            arr[sentence.charAt(i) - 97] = true;
        }
        for (int i=0; i<26; i++) {
            if(arr[i] == false) {
                return false;
            }
        }
        return true;
    }