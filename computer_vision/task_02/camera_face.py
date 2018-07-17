import cv2

'''

refs:
https://docs.opencv.org/3.4/d7/d8b/tutorial_py_face_detection.html
https://github.com/LiuXiaolong19920720/smile-detection-Python

'''

##### CONFIG ##############################

CONTRAST = 0.5
BRIGHTNESS = 0.5

# load classifiers
FACE_CASCADE = cv2.CascadeClassifier('./haarcascade_frontalface_default.xml')
EYE_CASCADE = cv2.CascadeClassifier('haarcascade_eye.xml')
SMILE_CASCADE = cv2.CascadeClassifier('haarcascade_smile.xml')

##### END OF CONFIG #######################

def detect_eyes(img_gray, img_color):
    ''' detect eyes '''
    eyes = EYE_CASCADE.detectMultiScale(img_gray)
    for (ex, ey, ew, eh) in eyes:
        cv2.rectangle(img_color, (ex, ey), (ex + ew, ey + eh), (0, 255, 0), 2)

def detect_smile(img_gray, img_color, img_frame, x, y):
    ''' detect smile '''
    smile = SMILE_CASCADE.detectMultiScale(img_gray,scaleFactor= 1.16,
            minNeighbors=35,minSize=(25, 25),flags=cv2.CASCADE_SCALE_IMAGE)

    for (x2, y2, w2, h2) in smile:
        cv2.rectangle(img_color, (x2, y2), (x2+w2, y2+h2), (255, 0, 0), 2)
        cv2.putText(img_frame,'Smile',(x,y-7), 3, 1.2, (0, 255, 0), 2, cv2.LINE_AA)

def detect_face(img_frame):
    ''' detect face, eyes and smile '''
    gray = cv2.cvtColor(img_frame, cv2.COLOR_BGR2GRAY)
    faces = FACE_CASCADE.detectMultiScale(gray, 1.2, 5)

    for (x, y, w, h) in faces:
        cv2.rectangle(img_frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
        
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img_frame[y:y+h, x:x+w]
        
        detect_eyes(roi_gray, roi_color)

        detect_smile(roi_gray, roi_color, img_frame, x, y)

vid = cv2.VideoCapture(0)
if vid.isOpened():
    print("webcam ok!")
else:
    print("not found")
    exit(0)

#%%
vid.set(cv2.CAP_PROP_BRIGHTNESS, BRIGHTNESS)
vid.set(cv2.CAP_PROP_CONTRAST, CONTRAST)
cv2.namedWindow("frame", cv2.WINDOW_KEEPRATIO)

while True:
    ret, frame = vid.read()
    detect_face(frame)
    cv2.imshow('frame', frame)
    if 0xFF & cv2.waitKey(1) == ord('q'):
        break

cv2.destroyAllWindows()
vid.release()
