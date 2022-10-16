from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw
import os

print('This is a program for generating Achievement Certificate...')
print('\nYour certificate will be available in the Certificates directory !')
fname = input('Enter Your First Name: ').strip().title()
mname = input('Enter Your Middle Name: ').strip().title()
lname = input('Enter Your Last Name: ').strip().title()
name = ' '.join([lname, fname, mname])

img = Image.open('AchievementCertificate.png')
draw = ImageDraw.Draw(img)
selectFont = ImageFont.truetype('arial.ttf', size=60)

draw.text(xy=(725,760),text='{}'.format(j['name']),fill=(0,0,0),font=font)

if not os.path.exists('Certificates'):
    os.mkdir('Certificates')
img.save('Certificates\\{} File Certificate.png'.format(sub), 'PNG', resolution=100.0)
