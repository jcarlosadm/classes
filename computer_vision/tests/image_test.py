""" image test """

import cv2
#cv2.__version__

#%%
img = cv2.imread('dog.jpg', cv2.IMREAD_COLOR)
cv2.namedWindow('img', cv2.WINDOW_KEEPRATIO)
cv2.imshow('img', img)

while True:
    if 0xFF & cv2.waitKey(1) == ord('q'):
        break

cv2.destroyAllWindows()
