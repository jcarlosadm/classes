import cv2
import face

CONTRAST = 0.5
BRIGHTNESS = 0.5

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

faceDetector = FaceDetector

while True:
	ret, frame = vid.read()
	faceDetector.detect(frame)
	faceDetector.draw()
	cv2.imshow('frame', frame)
	if 0xFF & cv2.waitKey(1) == ord('q'):
		break

cv2.destroyAllWindows()
vid.release()
