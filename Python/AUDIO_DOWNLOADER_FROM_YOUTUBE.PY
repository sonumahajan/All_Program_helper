import pafy
from pydub import AudioSegment
link=input("ENTER YOUR LINK HERE:")
url=link
video=pafy.new(url)
audio=video.audiostreams
for i in audio:
	print(i.bitrate,i.get_filesize())

X=audio[3].download("D:\\file.mp3")  #PATH WHERE THE FILE WILL BE DOWNLOADED
AudioSegment.from_wav(X).export("D:\\file.mp3", format="mp3") #PATH WHERE MP3 FILE WILL BE EXPORTED
