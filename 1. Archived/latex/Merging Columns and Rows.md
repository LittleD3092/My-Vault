標籤: #latex 

---

在格子裡打上這些指令，就可以合併儲存格

# column

```latex
\multicolumn{num_cols}{alignment}{contents}
```

# row

需要在 [[Preamble]] 裡面 include package

```latex
\usepackage{multirow}
```

```latex
\multirow[valign]{num_rows}{width}{contents}
```

`valign`: 可以是 `t`(top), `c`(center), `b`(bottom)，代表要靠上還是靠下
`width`: 寬度，如果用 `*` 就是自動設定

---

參考資料:

[latex full course - youtube](https://youtu.be/fCzF5gDy60g)

---

link:

[[Table & Tabular Environments]]
[[Preamble]]
[[Document Environment]]