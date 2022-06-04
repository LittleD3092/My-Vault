標籤: #資料結構 

---

# [[Big-O Notation|Complexity]]

| Action    | Static Array | Dynamic Array |
| --------- | ------------ | ------------- |
| Access    | $O(1)$       | $O(1)$        |
| Search    | $O(n)$       | $O(n)$        |
| Insertion | N/A          | $O(n)$        |
| Appending | N/A          | $O(1)$        |
| Deletion  | N/A          | $O(n)$        | 

# Dynamic Array

可以以 Static Array 作 Dynamic Array

1. 創建一個 static array
2. 加入數字，同時觀察存了幾個數字
3. 若再加入數字會超過 static array 的範圍，創建一個有 2 倍原始空間的 static array 並把原始的數字存進去

---

參考資料:

[Data Structures Easy to Advanced Course](https://youtu.be/RBSGKlAvoiM)

---

link:

