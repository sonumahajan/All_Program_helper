from __future__ import unicode_literals
import os
import youtube_dl
from pathlib import Path


file_loc = input("Enter File name: ")
folder_loc = input("Enter the folder name to create: ")

if not os.path.exists(folder_loc):
	os.makedirs(folder_loc)



downloaded = []

arr = []

with open(file_loc) as down:
	arr = down.readlines()

# os.chdir(folder_loc)

for ar in arr:
	try:
		line = ar.replace('\n', '').replace(' ', '')
		final_arr = ar.split('**')
		ydl_opts = {'format':'18'}
		video = final_arr[0]
		title = ""
		# print(final_arr)
		with youtube_dl.YoutubeDL(ydl_opts) as ydl:
			info_dict = ydl.extract_info(video, download=False)
			title = info_dict['title']
			print(downloaded.count(title))
			ydl.download([video])
		# print(f"{title}-{video.split('/')[-1]}.mp4")
		files = os.listdir()
		downloaded_vid = ""
		if 'watch?v=' in video:
			downloaded_vid = video.split('watch?v=')[-1]
		else:
			downloaded_vid = video.split('/')[-1]
		downloaded_vid = downloaded_vid.replace(' ', '').strip()
		# final_vidname = ""
		# for vid in files:
		# 	if downloaded_vid in vid:
		# 		final_vidname = vid
		# 		# print(final_vidname, "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
		# 		break
		# print(f'{title}{downloaded_vid}.mp4')
		# print(video, "++++++++++++++++++++++++++++++++++++")
		# print(final_arr, "++++++++++++++++++++++++++++++++++++")
	# 	if video == final_arr[-1] or video == final_arr:
	# 		# if 'watch?v=' in video:
	# 		print("Moving FIle +++++++++++++++++++++++++", final_vidname)
	# 		os.system(f"move .\\{final_vidname} .\\\"{folder_loc}\"\\\"{title}.mp4\"")
	# 		# else:
	# 			# os.system(f"move .\\{final_vidname} .\\\"{folder_loc}\"\\\"{title}.mp4\"")
	# 		# print(f"move .\\\"{title}-{video.split('/')[-1]}.mp4\" .\\\"{folder_loc}\"\\\"{title}.mp4\"")
		# print(downloaded, title, "**********************************************************8")
		final_arr[2] = final_arr[2].replace('\n', '')
		# print(downloaded_vid, "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<")
		file_name_final = ""
		for vid in files:
			if downloaded_vid in vid:
				file_name_final = vid
		if title not in downloaded:
			os.system(f"ffmpeg -i \"{file_name_final}\" -ss {final_arr[1]} -to {final_arr[2]} -async 1 \"{folder_loc}\"/\"{file_name_final.replace(f'-{downloaded_vid}', '')}\"")
			downloaded.append(title)
		else:
			print(f'\"{folder_loc}\"/\"{title}-{downloaded.count(title)}.mp4\"')
			os.system(f"ffmpeg -i \"{file_name_final}\" -ss {final_arr[1]} -to {final_arr[2]} -async 1 \"{folder_loc}\"/\"{file_name_final.replace(f'-{downloaded_vid}', '')}-{downloaded.count(title)}.mp4\"")
			downloaded.append(title)
	except Exception as e:
		print(e)


print("[+] All tasks completed, cleaning up unnecessary files!")
for p in Path(".").glob("*.mp4"):
	p.unlink()

# ydl_opts = {}
# video = 'https://www.youtube.com/watch?v=iF7sXHzWbMI'
# with youtube_dl.YoutubeDL(ydl_opts) as ydl:
# 	info_dict = ydl.extract_info(video, download=False)
# 	print(info_dict.get('title', None))
	# ydl.download(['https://www.youtube.com/watch?v=BaW_jenozKc'])


# link = input("Enter the video link: ")
# file_name_1 = input("Enter File Name: ")
# start_time = input("Enter Start time: ")
# end_time = input("Enter Ende time: ")

# # print(link)
# # file_name = print(yt.title)
# YouTube(link).streams.first().download()
# os.system(f"ffmpeg -i {file_name}.mp4 -ss {start_time} -t {end_time} -async 1 {file_name}.mp4")
# # os.system(f"for /F %A IN ('youtube-dl {link}') DO ffmpeg -ss {start_time} -i %~A -t {end_time} -c copy {file_name}.mp4")