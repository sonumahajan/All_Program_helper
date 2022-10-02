word = input("Input word:\n")

print("\""+word+"\" is" + (word.lower() != word.lower()[::-1])*" not" + " a palindrome.")
