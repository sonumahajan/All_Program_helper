import cv2
cap = cv2.VideoCapture(0)
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
while True:
    ret,frame = cap.read()
    gray_img = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray_img,1.32,5)
    for (x,y,w,h) in faces:
        gray_frame = gray_img[y:y+w,x:x+h]
        eyes = eye_cascade.detectMultiScale(gray_frame)
        if len(eyes)>1:
            biggest = (0,0,0,0)
            for i in eyes:
                if i[3]>biggest[3]:
                    biggest = i
            biggest = np.array([i],np.int32)
        elif len(eyes) ==1:
            biggest = eyes
        else:
            pass
        for(ex,ey,ew,eh) in biggest:
            
    cv2.imshow('Frame',frame)
    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
