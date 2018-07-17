import cv2

rgb = cv2.imread('face.jpg', cv2.IMREAD_COLOR)
gray = cv2.cvtColor(rgb, cv2.COLOR_BGR2GRAY)
face_cascade = cv2.CascadeClassifier('./haarcascade_frontalface_default.xml')
faces = face_cascade.detectMultiScale(gray, 1.2, 5)

for (x, y, w, h) in faces:
    cv2.rectangle(rgb, (x, y), (x + w, y + h), (255, 0, 0), 2)

cv2.imshow('rgb', rgb)
while True:
    if 0xFF & cv2.waitKey(1) == ord('q'):
        break
cv2.destroyAllWindows()
