import java.util.Scanner;

public class Anagram {
  static Scanner input = new Scanner(System.in);

  static int[] countFrequency(String str) {
    int countFrequencyStr[] = new int[26];
    char arr[] = str.toCharArray();

    for (int i = 0; i < arr.length; i++) {
      int ascii = (int) arr[i];
      if (ascii >= 65 && ascii <= 90)
        countFrequencyStr[ascii - 65]++;
      else if (ascii >= 97 && ascii <= 122)
        countFrequencyStr[ascii - 97]++;
    }

    return countFrequencyStr;
  }

  static void isAnagram(String str1, String str2) {
    int countFrequencyStr1[] = countFrequency(str1);
    int countFrequencyStr2[] = countFrequency(str2);

    boolean isAnangram = true;
    for (int i = 0; i < 26; i++) {
      if (countFrequencyStr1[i] != countFrequencyStr2[i]) {
        isAnangram = false;
        break;
      }
    }
    System.out.println(isAnangram ? "Anagrams" : "Not Anagrams");
  }

  public static void main(String[] args) {
    // String str1 = input.next();
    // String str2 = input.next();

    isAnagram("anagram", "margana"); // -> It's a Anagram

    // isAnagram("anagramm", "marganaa"); // -> It's a Not Anagram

    // isAnagram("Hello", "hello");  // -> It's a Anagram
    input.close();
  }
}
