標籤: #website 

---

用來選取一部分的內容，並且做顏色配置之類的事情

# element selector

最簡單的選取，可以選一個元素( `p`, `h1` 等)

```html
<h1>A Heading.</h1>
<p>Some text.</p>
<h1>Another heading.</h1>
```

```css
p {
	color: red;
}
```

# class selector

比起 [[#element selector]] ，他是用 class 作為選取依據

```html
<h2 class="aclass">A Subheading.</h2>
<p class="aclass">Some more text.</p>
```

```css
.aclass {
	color: blue;
}
```

class 可以寫很多個，用空格隔開

# id selector

```html
<p id="sometext">Some Text.</p>
<p id="sometext">Some More Text.</p>
```

```css
#sometext {
	color: orange;
}
```

> # Class / id / element 順序
> 
> id 會複寫 class ， class 會複寫 element

# Pseudoselectors

## 游標放在上面使用的格式

```css
h2: hover {
	color: red;
}
```

## 選擇其中的子項目

### 選定 `li` 第一個子項目

```css
li: first-child {
	color: steelblue;
}
```

### 選定 `li` 最後一個子項目

```css
li: last-child {
	color: steelblue;
}
```

### 選定 `li` 第 `n` 個子項目

```css
li: nth-child(2) {
	color: steelblue;
}
```

在這個範例中選定的是第二個

### 選定 `li` 唯一一個子項目

```css
li: only-child {
	color: steelblue;
}
```

如果這個子項目是唯一一個，那麼選取起來

## 超連結

```css
#google-link: link {
	
}
```

```css
#google-link: visited {
	
}
```

表示連結在點擊前和點擊後的格式

> ### 小提示
> `ctrl + /` 可以註解掉選擇的範圍

# Advanced Selectors

## 選擇所有跟在 `h2` 後面的 `a` 元素

```css
h2 + a{
	color: red;
}
```

## 選擇同一個 parent 中在 `textarea` 後的 `button`

```css
textarea ~ button {
	color: purple;
}
```

## 選擇在 `ul` 中的下一階子元素 `li`

```css
ul > li {
	color: blue;
}
```

## 選擇在 `ul` 中的「所有」子元素(不只有下一階)

```css
ul li {
	color: green;
}
```

# Attribute Selector

```css
h2 [class=subtitle] {
	color: blue;
}
```

根據內部的值選擇

## 以...開頭的值

```css
img [src^="../img/"] {
	
}
```

## 以...結尾的值

```css
img [src$="../img/"] {

}
```

## 其中有...的值

```css
img [src*="../img/"] {

}
```

## 其中一個 class 是

```css
h2 [class~=article-subtitle]
```

## 其中一個 class 或 class 的開頭是

```css
h2 [class|=article-subtitle] {

}
```

會選取 `article-subtitle` 和 `article-subtitle-...`

---

參考資料:

[css tutorial - youtube](https://youtu.be/1Rs2ND1ryYc)