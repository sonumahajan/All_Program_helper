//    Input:  str = “UN was established on 24-10-1945. India got freedom on 15-08-1947.”
//    Output: 2
//    Explanation: 2 distinct years i.e. 1945 and 1947 have been referenced.
//
//            Input: str = “Soon after the World War 2 ended on 02-09-1945. The UN was established on 24-10-1945.”
//    Output: 1
//    Explanation: Only 1 Year, i.e 1945 has been referenced .

import java.util.HashSet;
import java.util.Set;

public class UniqueYear {

    public static int distinctYear(String str) {
        String str2 = "";
        Set<String> uniqueYear = new HashSet<>();


        for(int i=0;i<str.length();i++){
            if(Character.isDigit(str.charAt(i))){
                str2 += str.charAt(i);
            }

            if (str.charAt(i) == '-') {
                str2="";
            }
            if(str2.length()==4){
                uniqueYear.add(str2);
                str2="";
            }
        }
        return uniqueYear.size();
    }
    public static void main(String[] args) {
        String str="UN was established on 24-10-1945. India got freedom on 15-08-1947.";
        System.out.println(distinctYear(str));
        System.out.println();
    }


}
