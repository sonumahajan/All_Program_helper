# 1.0.0-GhostChatBoat

# Discription

created by:             NkTech

Guided by:              Code With Harry (CWD)

Status:                 Under Development

Project Name:           Ghost

Program Type:           Chat Boat

Subscribe:              https://www.youtube.com/channel/UCTwFfEX-EBWe_6FB-ruhWuw

# Features:
1. Can Open Different Urls like : youtube , stackoverflow , Google,Spotify player  and more urls can be added  - try saying : open <website name listed above>
2. can give current time - try saying : what is time 
3. can send email - try saying : send email
4. working on other features.


#Requriments
1. python 3.7 or above
2. Requirements.txt modules
3. Audio input and output device. 

# How to set Up:
1. clone the project using:
            git clone https://github.com/Nktech-Official/1.0.0-GhostChatBoat
            
            
2. pip install -r requirements.txt
                or
    pip3 install -r requirements.txt in linux

3. python Ghost-v1.0.0.py

# Comman errors and solution:
   # Error 1:
          after exicuting requirements.txt file if get any of the following error
           No module named win32com.client
           No module named win32
           No module named win32api
# Solution 1:
            pip install pypiwin32

   # Error 2
    ModuleNotFoundError: No module named 'pywintypes'
   # Solution 2:
    1. go to C:\Users\nktec\AppData\Roaming\Python\Python39\site-packages\pywin32_system32 
    and copy the both file present in this directory named "pythoncom39.dll" and "pywintypes39.dll
    
    2. paste them here 👇
    C:\Users\nktec\AppData\Roaming\Python\Python39\site-packages\win32\lib

    # Note : replace the "nktech" with the your user name or locate to Appdata or where your pyhton is installed. go to roaming .
    
    39 in the file name represent python version (39 means 3.9) you may have different version of python so replace the Python39 with your version The name is formed  by eleminating dot(.) from the version (e.g 3.7.0 will be 37 or 3.8.9 will be 38 etc.)
# Contribution / Development :


Feel free to edit the code and publish your version on your own profile or add your version to this directory.





you can add more query of your choice to perform different tasks

# Note:
Some query's may throw errors as the path of them were given according to my Pc so you have to give the correct location . to make it work correctly I am working on this so that it can automatically update the path  YOu can publish the solution if you find it first.

# Chrome/webbrowser():

chrome is set the browser to open different urls so if you have chrome browser installed just change the path at line 48 in Chrome function.

If you don't have chrome or want to open with other browser just change the path at line 48 & You can also change the Function name as it  is good practice . or you can use webbrowser.open() to open with default browser
