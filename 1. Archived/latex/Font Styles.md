標籤: #latex 

---

設定字體的粗體、斜體等

這些粗細與斜體可以疊加，例如

```latex
\textbf{ \textit{Bold and italic text} }
```

# 粗體

```latex
\textbf{Bold text}
```

# 斜體

```latex
\textit{Italic text}
```

# 底線

```latex
\underline{Underlined text}
```

> 注意
> ```latex
> \underline{text}
> ```
> 不會換行，他會把畫上底線的字串變成一整塊
> 可以用其他 package 達成底線會換行的效果
> ```latex
> \usepackage{ulem}
> 
> ...
> 
> \uline{text}
> ```

---

參考資料:

[latex full course - youtube](https://youtu.be/fCzF5gDy60g)

---

link:

[[Font Size]]