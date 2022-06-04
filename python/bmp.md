標籤: #python 

---

bmp 是一種不壓縮的圖片，因此每個像素點都使用了 rgb 來儲存，檔案大小較大。但也因為每個像素點都使用一個 rgb 儲存，因此常做為測試數據

# 格式

bmp 圖片由兩個部分組成

1. [[#開頭]]
2. [[#rgb 數據]]

## 開頭

| 偏移 | 長度(字節) | 描述                                        |
| ---- | ---------- | ------------------------------------------- |
| `00` | 2          | bmp 的文件標示 "BM" 的 ASCII 碼 (`42` `4D`) |
| `02` | 4          | 文件大小 (字節)                             |
| `06` | 2          | 保留                                        |
| `08` | 2          | 保留                                        |
| `0A` | 4          | rgb 數據的偏移量 (字節)                     |
| `0E` | 4          | bmp 文件開頭中訊息塊的長度                  | 
| `12` | 4          | 寬度 (像素)                                 |
| `16` | 4          | 高度 (像素)                                 |
| `1A` | 2          | 圖像調色板的個數，一般是 `1`                |
| `1C` | 2          | 顏色位數： `1`, `8`, `24` (全彩), `32` ...  |
| `1E` | 4          | 壓縮方式： `0` (不壓縮), `1`, `2`           |
| `22` | 4          | rgb 數據的大小 (byte), 必須是 4 的倍數      |
| `26` | 4          | `00` `00` `00` `00`                         |
| `2A` | 4          | `00` `00` `00` `00`                         |
| `2E` | 4          | `00` `00` `00` `00`                         |
| `32` | 4          | `00` `00` `00` `00`                         |

### 例子

如果有一個 24 位元的 bmp 圖像來說：

- 開頭的數據量一般總是 54 byte
- 訊息塊：從 `0E` 到 `35` 之間的 40 byte
- 圖像調色板：個數為 1
- 顏色位數： 24
- 壓縮方式：不壓縮
- rgb 數據大小：例如一行有三個像素，每個像素有三個 byte ，總共有 9 個 byte ，但是因為 rgb 的數據大小必須是 4 的倍數，因此變成 12 byte ，後面多出來的 3 個 byte 會補 0

#### 用 python 產生 bmp 開頭

```python
class bmp:
    """ bmp data structure """

    def __init__(self, w=1080, h=1920):
        self.w = w
        self.h = h

    def calc_data_size (self):
        if((self.w*3)%4 == 0):
            self.dataSize = self.w * 3 * self.h
        else:
            self.dataSize = (((self.w * 3) // 4 + 1) * 4) * self.h

        self.fileSize = self.dataSize + 54

    def conv2byte(self, l, num, len):
        tmp = num
        for i in range(len):
            l.append(tmp & 0x000000ff)
            tmp >>= 8

    def gen_bmp_header (self):
        self.calc_data_size();
        self.bmp_header = [0x42, 0x4d]
        self.conv2byte(self.bmp_header, self.fileSize, 4) #file size
        self.conv2byte(self.bmp_header, 0, 2)
        self.conv2byte(self.bmp_header, 0, 2)
        self.conv2byte(self.bmp_header, 54, 4) #rgb data offset
        self.conv2byte(self.bmp_header, 40, 4) #info block size
        self.conv2byte(self.bmp_header, self.w, 4)
        self.conv2byte(self.bmp_header, self.h, 4)
        self.conv2byte(self.bmp_header, 1, 2)
        self.conv2byte(self.bmp_header, 24, 2) #888
        self.conv2byte(self.bmp_header, 0, 4)  #no compression
        self.conv2byte(self.bmp_header, self.dataSize, 4) #rgb data size
        self.conv2byte(self.bmp_header, 0, 4)
        self.conv2byte(self.bmp_header, 0, 4)
        self.conv2byte(self.bmp_header, 0, 4)
        self.conv2byte(self.bmp_header, 0, 4)

    def print_bmp_header (self):
        length = len(self.bmp_header)
        for i in range(length):
            print("{:0>2x}".format(self.bmp_header[i]), end=' ')
            if i%16 == 15:
                print('')
        print('')
```

## rgb 數據

### 使用 python 在 bmp 圖上畫線與矩形

```python
    def paint_bgcolor(self, color=0xffffff):
        self.rgbData = []
        for r in range(self.h):
            self.rgbDataRow = []
            for c in range(self.w):
                self.rgbDataRow.append(color)
            self.rgbData.append(self.rgbDataRow)

    def paint_line(self, x1, y1, x2, y2, color):
        k = (y2 - y1) / (x2 - x1)
        for x in range(x1, x2+1):
            y = int(k * (x - x1) + y1)
            self.rgbData[y][x] = color

    def paint_rect(self, x1, y1, w, h, color):
        for x in range(x1, x1+w):
            for y in range(y1, y1+h):
                self.rgbData[y][x] = color
```

### 將 bmp 寫入文件

```python
    def save_image(self, name="save.bmp"):
        f = open(name, 'wb')

        #write bmp header
        f.write(array.array('B', self.bmp_header).tobytes())

        #write rgb data
        zeroBytes = self.dataSize // self.h - self.w * 3

        for r in range(self.h):
            l = []
            for i in range(len(self.rgbData[r])):
                p = self.rgbData[r][i]
                l.append(p & 0x0000ff)
                p >>= 8
                l.append(p & 0x0000ff)
                p >>= 8
                l.append(p & 0x0000ff)

            f.write(array.array('B', l).tobytes())

            for i in range(zeroBytes):
                f.write(bytes([0x00]))

        #close file
        f.close()
```

### main

```python
if __name__ == '__main__':
    image = bmp(500, 500)
    image.gen_bmp_header()
    image.print_bmp_header()

    image.paint_bgcolor(0x00ff00)

    image.paint_line(50, 50, 450, 450, 0xff0000)
    image.paint_rect(100, 100, 100, 200, 0x0000ff)

    image.save_image("save1.bmp")
```

# 完成品

```python
import struct
import array
import numpy as np

# this is the path of bmp picture
BMP_PATH = "face.bmp"

class bmp:

	def __init__(self, path):
		# open file of chosen path
		f = open(path, "rb")

		# ========== header ==========

		# get header buffer
		bmp_header_b = f.read(0x36)

		# unpack header buffer to tuple
		bmp_header_tuple = struct.unpack('<2sI2H4I2H6I', bmp_header_b)

		# save as class elements
		self.tag = bmp_header_tuple[0]
		self.fileSize = bmp_header_tuple[1]
		#reserved bmp_header_tuple[2]
		#reserved bmp_header_tuple[3]
		self.rgbOffset = bmp_header_tuple[4]
		self.infoSize = bmp_header_tuple[5]
		self.width = bmp_header_tuple[6]
		self.height = bmp_header_tuple[7]
		self.pane = bmp_header_tuple[8]
		self.color = bmp_header_tuple[9]
		self.compress = bmp_header_tuple[10]
		self.rgbSize = bmp_header_tuple[11]
		#reserved bmp_header_tuple[12]
		#reserved bmp_header_tuple[13]
		#reserved bmp_header_tuple[14]
		#reserved bmp_header_tuple[15]

		# ========== image ==========

		# read other buffer (rgb data buffer)
		bmp_rgb_data_b = f.read()

		# convert byte buffer to list
		list_b = array.array('B', bmp_rgb_data_b).tolist()

		# convert to img list
		img = np.reshape(list_b, (self.height, self.width, 3)).tolist()

		# save as class elements
		self.img = img

	def print_bmp_header(self):
		print("tag      :{}".format(self.tag))
		print("fileSize :{}".format(self.fileSize))
		print("rgbOffset:{}".format(self.rgbOffset))
		print("infoSize :{}".format(self.infoSize))
		print("width    :{}".format(self.width))
		print("height   :{}".format(self.height))
		print("pane     :{}".format(self.pane))
		print("color    :{}".format(self.color))
		print("compress :{}".format(self.color))
		print("rgbSize  :{}".format(self.rgbSize))
	
	def convert_color_to_blue(self):
		np_img = np.array(self.img)
		np_img[:, :, 0] = 255
		self.img = np_img.tolist()

	def convert_color_to_green(self):
		np_img = np.array(self.img)
		np_img[:, :, 1] = 255
		self.img = np_img.tolist()

	def convert_color_to_red(self):
		np_img = np.array(self.img)
		np_img[:, :, 2] = 255
		self.img = np_img.tolist()

	def save_image(self, name="save.bmp"):
		f = open(name, 'wb')

		bmp_header = struct.pack('<2sI2H4I2H6I', self.tag, self.fileSize, 0, 0, self.rgbOffset, self.infoSize, self.width, self.height, self.pane, self.color, self.compress, self.rgbSize, 0, 0, 0, 0)

		#write bmp header
		f.write(array.array('B', bmp_header).tobytes())

		#write rgb data
		zeroBytes = self.width * 3 % 4
		if zeroBytes != 0:
			zeroBytes = 4 - zeroBytes

		for r in range(self.height):
			for c in range(self.width):
				pixel = struct.pack('3B', self.img[r][c][0], self.img[r][c][1], self.img[r][c][2])
				f.write(pixel)

			for i in range(zeroBytes):
				f.write(bytes([0x00]))

		#close file
		f.close()

if __name__ == "__main__":
	img = bmp(BMP_PATH)
	img.convert_color_to_blue()
	img.save_image()
```

---

參考資料:

[用 python 生成 bmp 圖片](http://exasic.com/article/index.php?md=py-bmp)
[用 python 讀取 bmp 圖片](http://exasic.com/article/index.php?md=py-bmp2)

---

link:

