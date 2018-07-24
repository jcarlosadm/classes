import cv2

class FaceDetector:
	def __init__(self):
		self.FACE_CASCADE = cv2.CascadeClassifier('./haarcascade_frontalface_default.xml')
		self.gray = None
		self.faces = None
		self.image = None

	def detect(self, image):
		''' detect face '''
		self.image = image
		self.gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
		self.faces = self.FACE_CASCADE.detectMultiScale(self.gray, 1.2, 5)

	def draw(self):
		''' draw face '''
		for (x, y, w, h) in self.faces:
			cv2.rectangle(self.image, (x, y), (x + w, y + h), (255, 0, 0), 2)
