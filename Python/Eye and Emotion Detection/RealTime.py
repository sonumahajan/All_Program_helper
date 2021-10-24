import os
import cv2
import numpy as np
from tensorflow.keras.models import load_model
from keras.preprocessing import image
from imutils.video import FPS

model = load_model('model.h5')

face_haarcascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
cap = cv2.VideoCapture(0)
emotions = ['angry','disgust','fear','happy','sad','surprise','neutral']
emotions = np.array(emotions)
emotions = emotions.reshape((len(emotions),1))
fin = []
fps = FPS().start()
while True:
    ret,test_img = cap.read()
    if not ret:
        continue
    gray_img =cv2.cvtColor(test_img,cv2.COLOR_BGR2GRAY)
    faces_detected = face_haarcascade.detectMultiScale(gray_img,1.32,5)
    for (x,y,w,h) in faces_detected:
        gray_frame = gray_img[y:y+w,x:x+h]
        model_gray_frame = cv2.resize(gray_frame,(48,48))
        img_pixels = image.img_to_array(model_gray_frame)
        img_pixels = np.expand_dims(img_pixels,axis=0)
        img_pixels /=255
        predictions = model.predict(img_pixels)
        fin.append(predictions[0])
    resized_img = cv2.resize(test_img,(250,250))
    cv2.imshow('Facial emotion analysis',resized_img)
    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'):
        break
    fps.update()
fps.stop()
print("Elapsed time: {:.2f}".format(fps.elapsed()))
print("approx FPS : {:.2f}".format(fps.fps()))
fin = np.array(fin)
mean = np.mean(fin,axis = 0)
print('Your emotion most of the time is:',np.argmax(mean))
cap.release()
cv2.destroyAllWindows()
    
