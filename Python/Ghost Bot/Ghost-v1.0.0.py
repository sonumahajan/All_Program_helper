"""
created by:   NkTech
Guided by:    Code With Harry (CWD)
Status:       Under Development
Project Name: Ghost
Discription:  Uses Google speech recongination Api for python.
Subscribe:   https://www.youtube.com/channel/UCTwFfEX-EBWe_6FB-ruhWuw
"""

import pyttsx3 #pip install pyttsx3
import speech_recognition as sr #pip install speechRecognition
import datetime # Inbuilt-Module
import wikipedia #pip install wikipedia
import webbrowser # Inbuilt-Module
import os # Inbuilt-Module
import smtplib # Inbuilt-Module

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)


def speak(audio):
    """
    engine.say() :
        Adds an utterance to speak to the event queue.
        @param text: Text to sepak
        @type text: unicode
        @param name: Name to associate with this utterance. Included in notifications about this utterance.
        @type name: str
    
    engine.runAndWait():
        Runs an event loop until all commands queued up until this method call
        complete. Blocks during the event loop and returns when the queue is
        cleared.

        @raise RuntimeError: When the loop is already running


    """
    engine.say(audio)
    engine.runAndWait()

def Chrome(url):
    webbrowser.register('chrome',
	None,
	webbrowser.BackgroundBrowser("C://Program Files//Google//Chrome//Application//chrome.exe"))
    webbrowser.get('chrome').open(url)
def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour <12:
        speak("Good Morning!")
        print("Good Morning!")

    elif hour>=12 and hour<18:
        speak("Good Afternoon!")   
        print("Good Afternoon!")

    else:
        speak("Good Evening!")  
        print("Good Evening!")

    print("I am Ghost, Your Assistance. \nMade by Nk Tech, \nPlease tell me how can I help you")      
    speak("I am Ghost! Your Assistant. Made by Nk Tech, Please tell me how can I help you")

def takeCommand():
    #It takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1.5
        r.non_speaking_duration = 1.2
        r.energy_threshold = 1800
        audio = r.listen(source)

    try:
        print("Recognizing...")    
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        speak("I did not get it....")   
        print("I did not get it....\nSay that again please") 
        speak("Say that again please")
        speak("or press ctrl+c to exit ")
        return "None"
    return query

def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    speak("Enter Your email address.")
    email = input("Enter Your email address:")
    speak("enter your password")
    password = input("Enter your password:")
    server.login(email, 'your-password')
    server.sendmail(email, to, content)
    server.close()


if __name__ == "__main__":
    wishMe()
    while True:
        query = takeCommand().lower()

        # Logic for executing tasks based on query
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)
            speak("Next query please.")
            speak("or press ctrl+c to exit ")

        elif 'open youtube' in query:
            Chrome("youtube.com")
            speak("Next query please.")
            speak("or press ctrl+c to exit ")

        elif 'open google' in query:
            Chrome("google.com")
            speak("Next query please.")
            speak("or press ctrl+c to exit ")

        elif 'open stackoverflow' in query:
            Chrome("stackoverflow.com")
            speak("Next query please.")
            speak("or press ctrl+c to exit ")
        
        elif 'open chrome' in query:
            chromePath = "C://Program Files//Google//Chrome//Application//chrome.exe"
            os.startfile(chromePath)
            speak("Next query please.")
            speak("or press ctrl+c to exit ")



        elif 'play music' in query:
            # open spotify in webbrowser you can also play offline music by giving path to it, Or any other online music player by changing url
            Chrome("open.spotify.com")
            speak("Next query please.")
            speak("or press ctrl+c to exit ")

        elif 'time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")    
            speak(f"Sir, the time is {strTime}")
            speak("Next query please.")
            speak("or press ctrl+c to exit ")

        elif 'open code' in query:
            # change path according to your pc location
            codePath = "C:\\Users\\nktec\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codePath)
            speak("Next query please.")
            speak("or press ctrl+c to exit ")
        
        elif 'send email' in query:
            try:
                speak ("Enter recivers Email address please.")
                to = input("Enter recivers Email address:")
                speak("What should I say?")
                content = takeCommand()
                sendEmail(to, content)
                speak("Email has been sent!")
                speak("Next query please.")
                speak("or press ctrl+c to exit ")
            
            except Exception as e:
                print(e)
                speak("Sorry sir. I am not able to send this email")
                speak("or press ctrl+c to exit ") 