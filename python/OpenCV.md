標籤: #python 

---

# import

```python
import cv2 as cv
```

# read images & video

## cv.imread()

```python
img = cv.imread('Photos/cat.jpg')
```

使用相對路徑

## cv.imshow()

```python
cv.imshow('Cat', img)
```

將圖片用一個視窗顯示，第一個字串是視窗名字，第二個放圖片

## cv.waitKey()

```python
cv.waitKey(0)
```

等待幾毫秒，如果是 `0` 則等待任意鍵輸入

## cv.VideoCapture()

```python
capture = cv.VideoCapture(0)
capture = cv.VideoCapture('Videos/dog.mp4')
```

裡面可以放整數(讀取攝影機)，或者放字串(影片的路徑)

## capture.read()

```python
while True:
	isTrue, frame = capture.read()
	cv.imshow('Video', frame)
	
	if cv.waitKey(20) & 0xFF==ord('d')
		break
```

將影片其中一幀讀取到 `frame` ，如果成功 `isTrue` 就是 `true` ，不成功是 `false`

## capture.release()

```python
capture.release()
```

釋放空間

## cv.destroyAllWindows

```python
cv.destroyAllWindows()
```

# Resize and Rescale

```python
def rescaleFrame(frame, scale = 0.75):
	width = int(frame.shape[1] * scale)
	height = int(frame.shape[0] * scale)
	
	dimensions = (width, height)
	
	return cv.resize(frame, dimensions, interpolation = cv.INTER_AREA)
```

上面的函式把圖片 * 0.75 倍

---

參考資料:

[OpenCV Course - youtube](https://youtu.be/oXlwWbU8l2o)

---

link:

