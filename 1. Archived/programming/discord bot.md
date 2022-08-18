標籤: #python

---

[discord developer](https://discord.com/developers/applications)
1. 在這個連結創建機器人帳號

2. 創建後在設定裡面先設定權限之類的東西

3. 使用邀請連結把機器人加入到伺服器之中

[replit](https://replit.com/) 可以讓程式碼線上執行，免費，而且自己的電腦不需要開著
> 在 [replit](https://replit.com/) 上程式碼大家都可以看到，所以要注意 token 的保密
> - `.env` 檔案在 [replit](https://replit.com/) 上是保密的，可以在這上面存 token
> 
> ### env 檔案的內容 :
> ```env
> TOKEN = [token here]
> ```
> 
> ### 主程式需要的內容 : 
> ```python
> import os
> 
> ...
> 
> client.run( os.getenv('TOKEN') )
> ```
> 這樣就可以安全登入 discord bot

# token

這個東西就像是機器人的密碼，必須放在程式裡面，並且不可以外洩給其他人

# discord 函式庫

```python
import discord
```

# 登入 event

```python
@client.event
async def on_ready():
	print('We have logged in as {0.user}'.format(client))
```

當登入成功，就會執行這一段函式

# 收訊息 event

```python
@client.event
async def on_message(message):
	if message.author == client.user:
		return
		
	if message.content.startswith('$hello'):
		await message.channel.send('hello!')
```

這個函式可以在收到訊息的時候觸發，並且讀取裡面的內容作出回應

# 從其他網站 api 讀取名言佳句

```python
import requests			#這個函式庫可以讀取 html ，不過是 json 格式
import json				#幫助我們處理讀取的內容

...

def get_quote():
	response = requests.get("https://zenquotes.io/api/random")
	json_data = json.loads(response.text)
	quote = json_data[0]['q'] + " -" + json_data[0]['a']
	return(quote)
```

# 使用 replit database

```python
from replit import db

...

def update_encouragements(encouraging_message):
	if "encouragements" in db.keys():
		encouragements = db["encouragements"]
		encouragements.append(encouraging_message)
		db["encouragements"] = encouragements
	else:
		db["encouragements"] = [encouraging_message]
		
def delete_encouragements(index):
	encouragements = db["encouragements"]
	if len(encouragements) > index:
		del encouragements[index]
		db["encouragements"] = encouragements
```


---

參考資料:

[discord developer](https://discord.com/developers/applications)
[how to create discord bot - youtube](https://youtu.be/SPTfmiYiuok)