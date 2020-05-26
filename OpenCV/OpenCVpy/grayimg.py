import cv2

original = cv2.imread('../data/cat.jpg')
grayImage = cv2.cvtColor(original, cv2.COLOR_BGR2GRAY)

cv2.imshow('Original Image', original)
cv2.imshow('Gray Image', grayImage)

cv2.waitKey(5000)
cv2.destroyAllWindows()
