""" camera test """

import cv2
#cv2.__version__

vid = cv2.VideoCapture(0)
if vid.isOpened():
    print("webcam ok!")
else:
    print("not found")
    exit(0)

#%%
cv2.namedWindow("frame", cv2.WINDOW_KEEPRATIO)
while True:
    ret, frame = vid.read()
    cv2.imshow('frame', frame)
    if 0xFF & cv2.waitKey(1) == ord('q'):
        break

cv2.destroyAllWindows()
vid.release()
