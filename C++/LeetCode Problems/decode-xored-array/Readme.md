# 1720. Decode XORed Array
## Easy

There is a hidden integer array arr that consists of n non-negative integers. <br>

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3]. <br>

You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0]. <br>

Return the original array arr. It can be proved that the answer exists and is unique. <br>

 

Example 1: <br>

Input: encoded = [1,2,3], first = 1 <br>
Output: [1,0,2,1] <br> 
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3] <br>

Example 2: <br>

Input: encoded = [6,2,7,3], first = 4 <br>
Output: [4,2,0,7,4] <br>

 

Constraints: <br>

    2 <= n <= 104
    encoded.length == n - 1
    0 <= encoded[i] <= 105
    0 <= first <= 105

