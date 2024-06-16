Tag: #network-systems-capstone 
Previous: [[HTTP]]
Link: 

---

```
GET /somedir/page.html HTTP/1.1
Host: www.someschool.edu
Connection: close
User-agent: Mozilla/5.0
Accept-language: fr

```

- The first line is called the ==request line==.
	- There are three fields: method field, URL field, and HTTP version field.
	- The method field can have the following value:
		- `GET`: The browser requests an object.
		- `POST`: Used when filling a form.
		- `HEAD`: Server will respond without the object requested.
		- `PUT`: Upload an object to a specific path on a specific web server.
		- `DELETE`: Delete an object on a web server.
- The subsequent lines are called the ==header lines==.
	- `Host` specifies the host on which the object resides.
		- This line is required by proxy servers.
	- `Connection`: Tells server whether to close TCP connection after response.
	- `User-agent`: The browser type.
	- `Accept-language`: Specify the language that the user prefers to receive. `fr` means French.
- The header lines are ended with an empty line. (<u>1</u>)

A general format of the request message:

![[Pasted image 20221029053911.png|500]]

> The "Entity body" is used for `POST` method.

---

# Reference

1. 王協源. “Network Systems Capstone: Chapter 2: Application Layer.” NYCU ED202, April 23, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.