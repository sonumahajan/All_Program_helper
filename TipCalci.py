# Tip Calculator
bill_value = float(input("Enter the total value of bill :\n"))
tip_per = 12
per_head = (150/5)*(1+(tip_per)/100)
print('Each person has to pay $'+"{0:.2f}".format(per_head))
