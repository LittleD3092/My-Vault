標籤: #website 

---

> - [[#color]]
> - [[#background]]
>     - [[#background]]
>         - [[#rgb]]
>         - [[#url photo external local path]]
>         - [[#rgba]]
>         - [[#linear-gradient]]
>             - [[#顏色]]
>             - [[#方向]]
>     - [[#background color]]
>     - [[#background image]]
>     - [[#background repeat]]
>     - [[#background size]]
> - [[#text]]
>     - [[#text-decoration]]
>     - [[#text-transform]]
>     - [[#text-align]]
>     - [[#font-size]]
>     - [[#font-weight]]
>     - [[#font-style]]
>     - [[#font-family]]

# color

```css
color: steelblue;
color: #ba8509;
color: rgb(186, 133, 9);
```

設定顏色

可以用預設的顏色名稱，也可以用十六進位和 rgb 與 [[#rgba]]

# background

設定背景

## background

### rgb

```css
background: rgb(204, 229, 255);
```

使用 rgb 方法設定

### url photo (external & local path)

```css
background: url("https://images.unsplash.com/photo-1485827404703-89b55fcc595e?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=2000&q=80");
background: url("../img/img-1.jpg");
```

使用圖片，可以用本地的路徑，也可以輸入圖片的網址

### rgba

```css
background: rgba(204, 229, 255, 0.4);
```

比起 rgb ，增加了 alpha 可以設定，代表透明度

在設定深淺的時候很好用

### linear-gradient

漸層，可以輸入多個顏色組合漸層，前面加上方向

#### 顏色

```css
background: linear-gradient(to right, red, blue);
background: linear-gradient(to right, red, green, blue, steelblue);
background: linear-gradient(to right, rgb(94, 255, 126), rgba(94, 255, 126, 0));
background: radial-gradient(red 20%, blue 40%, green 55%);
```

#### 方向

`to right`
`to right top`

- `right`
- `top`
- `bottom`
- `left`

可以混合用(斜的)

---

`260deg`

也可以直接打角度

---

```css
background: radial-gradient(red, blue);
```

從中心往外的漸層

---

```css
background: radial-gradient(circle, red, blue);
```

一般的漸層會是橢圓的，在前面多加 `circle` 可以變成正圓形

## background color

```css
background-color: rgb(0,0,0);
```

only accept color

## background image

```css
background-image: url("../img/img-1.jpg");	//works the same
```

## background repeat

```css
background-repeat: no-repeat;
background-repeat: repeat;
```

Is set to repeat by default.

當使用圖片但是圖片不夠大無法塞進去時，就會用重複的方法填滿，可以用這個 [[Property (CSS) | property]] 改善

但是圖片並不會放大塞滿整個背景，其他背景的區塊會是空的

![[css background repeat off 範例.png]]

## background size

```css
//寬 高
background-size: 50px 100px;
background-size: cover;
background-size: contain;
```

1. 設定寬和高
2. 直接設定一張圖要蓋住整個背景
3. 設定圖為最大(但不一定可以蓋住整個畫面)

# text

## text-decoration

```css
.link {
    text-decoration: none;
}
```

移除連結的底線

```css
text-decoration: underline;
```

連結的預設是有底線

```css
text-decoration: line-through;
```

刪除線

```css
text-decoration: overline;
```

頂部加上線

## text-transform

```css
body {
	text-transform: capitalize;
}
```

把所有字的第一個字母變大寫

```css
text-transform: uppercase;
```

所有字母大寫

```css
text-transform: lowercase;
```

所有字母小寫

## text-align

```css
body {
	text-align: center;
}
```

總共有四種可以選:
- `center`
- `right`
- `left`
- `justify`

> `justify`: 延伸那些字到固定長度，讓每行看起來一樣寬

## font-size

```css
body {
	font-size: 1.25em;
}
```

更改字體大小

## font-weight

```css
body {
	font-weight: 100;
	font-weight: 800;
}
```

可以更改字體的粗體，但是一種字形通常有限定幾種字體粗細

在預設的羅馬體， 100 會是最細， 800 會是最粗， 400 會是預設

## font-style

```css
.italics {
	font-style: italic;
	font-style: oblique;
}
```

更改字體種類(斜體)

上面例子的兩個都是斜體

## font-family

```css
body {
	font-family: sans-serif;
	font-family: "Times New Roman", serif;
}
```

更改字形，用逗號可以說明備用的字形，如果前面的字形沒辦法用，就會用下一個

---

參考資料:

[CSS tutorial - youtube](https://youtu.be/1Rs2ND1ryYc)

[[selector]]
[[Units]]