#Type the year for which you want to get the calandar
print((lambda year :'\n'.join([__import__('calendar').month(int(year), month,4) for month in range(1,13)]))(input() or '2022'))
