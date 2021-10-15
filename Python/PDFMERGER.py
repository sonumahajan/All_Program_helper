from PyPDF2 import PdfFileMerger
import os
n = int(input('Enter the number of files you want to merge:'))
pdfs = []
merger = PdfFileMerger()
i = 0
while i<n:
    filename = input('Enter the filename '+str(i+1)+':')
    if os.path.exists(filename):
        pdfs.append(filename)
        i += 1
    else:
        filename = input('Enter the filename '+str(i+1)+':')    
for pdf in pdfs:
    merger.append(pdf)
finalpath = input('Enter the output filename:')
# if os.path.exists(finalpath):
    # finalpath = 'DBMSFINALPDF1.pdf'
merger.write(finalpath)
