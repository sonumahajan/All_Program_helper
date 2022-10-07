import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ValidateIPAdd {

    public static boolean ValidateIP(String input_IP)
    {
        String numRange = "(\\d{1,2}|(0|1)\\" + "d{2}|2[0-4]\\d|25[0-5])" + "\\." 
              + "(\\d{1,2}|(0|1)\\" + "d{2}|2[0-4]\\d|25[0-5])" + "\\." 
              + "(\\d{1,2}|(0|1)\\" + "d{2}|2[0-4]\\d|25[0-5])" + "\\." 
              + "(\\d{1,2}|(0|1)\\" + "d{2}|2[0-4]\\d|25[0-5])";
        
        Pattern ip_pattern = Pattern.compile(numRange); 
        Matcher match= ip_pattern.matcher(input_IP);
        return match.matches();
    }
    public static void main(String[] args) 
    { 
        String strFalse = "00.500.ip.add";    
        String strTrue = "255.255.255.0";
        
        System.out.println("The Result is:"+ValidateIP(strFalse));
        System.out.println("The Result is:"+ValidateIP(strTrue));
       
    }
}
