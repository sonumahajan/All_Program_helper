from PIL import Image
output_size = (450, 350)
i = Image.open(input('Enter the filename:'))
i.thumbnail(output_size)
i.save(input('Enter the output filename:')+'.png')