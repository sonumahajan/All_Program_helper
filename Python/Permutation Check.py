## Read input.

def arePermutation(str1, str2):
    
    n1 = len(str1) 
    n2 = len(str2)
    if (n1 != n2):
        return False

    # Sort both strings 
    a = sorted(str1) 
    str1 = "".join(a) 
    b = sorted(str2) 
    str2 = "".join(b)

    # Compare sorted strings 
    for i in range(0, n1, 1): 
        if (str1[i] != str2[i]): 
            return False
  
    return True

## Print output.

str1 = input()
str2 = input()
if (arePermutation(str1, str2)):
    print("true") 
else: 
    print("false")
