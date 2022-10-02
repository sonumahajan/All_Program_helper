import datetime
currentDate = datetime.datetime.now()

deadline= input ('PLESE ENTER YOUR DATE OF BIRTH IN GIVEN FORMAT(dd/mm/yyyy):')
deadlineDate= datetime.datetime.strptime(deadline,'%d/%m/%Y')
print ('YOUR BIRTHDAY:',deadlineDate)
daysLeft =currentDate - deadlineDate
print('AGE IN DAYS:',daysLeft)

years = ((daysLeft.total_seconds())/(365.242*24*3600))
yearsInt=int(years)


months=(years-yearsInt)*12

monthsInt=int(months)


days=(months-monthsInt)*(365.242/12)
daysInt=int(days)

hours = (days-daysInt)*24
hoursInt=int(hours)

minutes = (hours-hoursInt)*60
minutesInt=int(minutes)

seconds = (minutes-minutesInt)*60
secondsInt =int(seconds)

print('YOU ARE {0:d} YEARS, {1:d}  MONTHS, {2:d}  DAYS, {3:d}  HOURS, {4:d} \
 MINUTES, {5:d} SECONDS OLD.'.format(yearsInt,monthsInt,daysInt,hoursInt,minutesInt,secondsInt))

print('YOUR AGE IN YEARS:',yearsInt,'YEARS')


MONTHS=yearsInt*12+monthsInt
print('YOUR AGE IN MONTHS:',MONTHS,'MONTHS')

DAYS= ((daysLeft.total_seconds())/(24*3600))
DAYSINT=int(DAYS)
print('YOUR AGE IN DAYS:',DAYSINT,'DAYS')

HOURS= ((daysLeft.total_seconds())/(3600))
HOURSINT=int(HOURS)
print('YOUR AGE IN HOURS:',HOURSINT,'HOURS')

MINUTES= ((daysLeft.total_seconds())/(60))
MINUTESINT=int(MINUTES)
print('YOUR AGE IN MINUTES:',MINUTESINT,'MINUTES')


WEEKS= ((daysLeft.total_seconds())/(24*3600*7))
WEEKSINT=int(WEEKS)
print('YOUR AGE IN WEEKS:',WEEKSINT,'WEEKS')
