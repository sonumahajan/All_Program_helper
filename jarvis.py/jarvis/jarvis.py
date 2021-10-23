import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import os
import email
import smtplib        #simple mail transfer protocol client
import pyjokes
import pywhatkit       #play songs
import twilio          #=   used for making calls and messages
import randfacts      # random facts

#from easySpeech import speech

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def greetings():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("Good Morning!!")
    elif hour >=12 and hour >5:
        speak("Good Afternoon!!")
    elif hour >=5 and hour <0:
        speak("Good Evening!!")

    speak("I am your presonal Assitant Please tell me how can I help you.")                


def greet_end():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 8:
        speak("Have a nice day ahead!!")
    elif hour >=8 and hour < 12:
        speak("Good Night !  Sweet Dreams ! Take Care !")

def takecommand():
    #it takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1   #ctr on pause theshold and try new things by changing setting
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio,language='en-in')
        print(f"user said: {query}\n")

    except Exception as ex:
        print("Failed to Recognize...\n  Say it again please...")
        speak("Failed to Recognize...\n  Say it again please...")
        return "None"

    return query    


def sendEmail(to,content):
    server = smtplib.SMTP('smpt.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.login('nspurtiscn2001@gmail.com',"lifespo@123")
    server.sendmail('nspurtiscn2001@gmail.com',to,content)
    server.close()


if __name__ == "__main__":
    #speak("Spurti!..How are you?")
    greetings()
    while True:
    #if 1:
        query = takecommand().lower()

        if 'wikipedia' in query:
            speak("Searching Wikipedia...")
            query = query.replace("wikipedia","")
            results = wikipedia.summary(query , sentences=2)
            speak("According to wikipedia..")
            print(results)
            speak(results)

        elif 'open youtube' in query:
            webbrowser.open("youtube.com")

        elif 'open watsapp' in query:
            watsappPath = "C:\\Users\\spurti c narkhedkar\\AppData\\Local\\WhatsApp\\WhatsApp.exe"
            os.startfile(watsappPath)   

        elif 'open instragram' in query:
            webbrowser.open("instagram.com")

        elif 'open facebook' in query:
            webbrowser.open("facebook.com")

        elif 'open google' in query:
            webbrowser.open("google.com")

        elif 'open stackoverflow' in query:
            webbrowser.open("stackoverflow.com")        

        elif 'play music' in query:
            speak("Which song would you like to hear?")
            command = takecommand()
            song = command.replace('play music','')
            speak('Playing'+song)
            pywhatkit.playonyt(song)
            print(song)
            

            #speak("Here you go with music")
            #music_dir = 'Music'
            #songs = os.listdir(music_dir)
            #print(songs)
            #random = os.startfile(os.path.join(music_dir,songs[1]))
        
        elif 'play video' in query:
           command = takecommand()
           video = command.replace('play video','')
           speak('Playing'+video)
           pywhatkit.playonyt(video)
           print(video)

        elif 'tell me a joke' in query:
            speak(pyjokes.get_joke())
            print(pyjokes.get_joke())

        elif 'tell me a fact' in query:
            speak("Did you know  that ")
            speak(randfacts.getFact())
            print(randfacts.getFact())    

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%I:%M:%p")
            speak(f"Hello mam,current time is {strTime}")     

        elif 'open code' in query:
            codePath = "C:\\Users\\spurti c narkhedkar\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codePath)

        elif 'your admin' in query:
            speak("name of my admin in spurti narkhedkar")    
    
        elif 'email to Ram' in query:
            try:
                speak("What should I say?")
                content = takecommand()
                to = "nspurtiscn2001@gmail.com"
                sendEmail(to,content)
                speak("Email has been sent")
            except Exception as ex:
                print(ex)
                speak("Failed to send the email.please try again")
        
        elif 'exit' in query:
            speak("Personal assitant exitted \nThank you!!\nHave a nice day!!")
            greet_end()
            break