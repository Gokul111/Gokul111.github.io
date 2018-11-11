#!usr/bin/python3
'''
Python script to find duplicate image in a folder.
NOTE:
    input folder should only contain images.
    original image will be moved to output folder.
    duplicate image will be available in the input folder itself.
'''

###########################
# importing all modules
###########################
import os,hashlib,shutil
from tkinter import filedialog
from tkinter import *
'''
shutil------for moving
hashlib-----for calculating hash
os----------for getting files
Tkinter-----for GUI
'''
#################################################
#selecting the input and output folder
#################################################
root=Tk()
root.withdraw()
inputfolder=filedialog.askdirectory(title='Open your image folder')
inputfolder=inputfolder.replace('/','\\')

outputfolder=filedialog.askdirectory(title='Open your output folder')
outputfolder=outputfolder.replace('/','\\')

##############################################
# dettecting duplicate image
#############################################
os.chdir(inputfolder) # changing directory to my image folder

imagefiles=os.listdir()  # getting all image files

dictionary={} # dictionary for storing hash and file name

for files in imagefiles:
    print(files)
    with open(files,'rb') as img:
        data=img.read() #read image and store in data
    filehash=hashlib.md5(data).hexdigest()  # calculating th hash of file
    dictionary[filehash]=files  # key=hash & value=filename

for files in dictionary:
    filename=dictionary[files] # getting the file name of original image
    shutil.move(filename,outputfolder) # moving original image to output folder

'''
Ater the execution duplicate image will be available in input folder itself
'''
######################################
# removing the duplicated images
######################################
statement=input('Do you want to delete the duplicated images.(Y/N): ').lower()
if statement=='y':
    files=os.listdir()
    for fil in files:
        os.remove(fil)
    print('Duplicate files removed')
else:
    print('Please delete the images manually')
    



    
