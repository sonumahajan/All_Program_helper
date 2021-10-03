def romanToInt(s):
     #Defining the Roman Number Values
     a={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}

     #Total value to be returned
     val=0

     #Counter Variable to track the length of string
     i=0

     #IDEA:- The Roman number will be in always in Descending Order(Right <Left)
     while i <len(s)-1:
          
          if a[s[i]]>=a[s[i+1]]:
              val=val+a[s[i]]

          #if we come accross the String like (Right > left) we will do Substraction   
          else:
              val=val-a[s[i]]
          i+=1

     #We will be leaving the last Letter and Count it's value at the end.
     val+=a[s[-1]]
     return val

n=input()
print(romanToInt(n))
