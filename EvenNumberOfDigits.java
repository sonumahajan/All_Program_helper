package com.gulraiz;

public class EvenNumberOfDigits {
    public static void main(String[] args) {
        int[] arr = {12,345,2,6,7896};
        System.out.println(findNumbers(arr));
    }

//    Method-1:
    /*
    static int findNumbers(int[] nums) {
        int evenDigits = 0;
        for(int num : nums){
            int count = 0;
            while(num > 0){
                num = num / 10;
                count++;
            }
            if(count % 2 == 0){
                evenDigits++;
            }
        }
        return evenDigits;
    }
     */

//    Method-2:
    static int findNumbers(int[] nums) {
        int count = 0;
        for(int i=0; i<nums.length; i++){
            if((nums[i]>9 && nums[i]<100) || (nums[i]>999 && nums[i]<10000) || (nums[i]==100000)){
                count++;
            }
        }
        return count;
    }

//    Method-3:
    /*
    static int findNumbers(int[] nums) {
        int count = 0;
        for(int num : nums){
            String s = String.valueOf(num);
            int len = s.length();
            if(len % 2 == 0){
                count++;
            }
        }
        return count;
    }
     */

}
