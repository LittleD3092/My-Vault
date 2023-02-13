Tag: #computer-networks 
Previous: [[HTTP]]
Link: 

---

[TOC]

---

==Web cache== (also called a ==proxy== server) is a network entity that satisfies HTTP requests on the behalf an origin web server. It acts like a server, and can handle requests. If a client request a file that the proxy has, the proxy send response immediately. However, if proxy server doesn't have the file, the proxy server send request to the original server.

![[Pasted image 20221029154558.png|400]]

- Web cahe is purchased and installed by an ISP. 
	- For example, a university might install a cache on its campus network and configure all of the compus browsers to point to the cache.
- Reasons that proxy server exist:
	- A web cache can reduce the response time for a client request.
	- Web cache can reduce traffic on an institution's access link to the Internet.

## Conditional GET

One problem of web caching is that the object stored on the proxy server might be outdated. Thankfully, HTTP has a mechanism ==conditional GET== to solve this.

Let's see how this works:

1. Client request for an object.
2. Proxy sends a request to the original server.
```
GET /fruit/kiwi.gif HTTP/1.1
Host: www.exotiquecuisine.com
```
3. Original server respond with object to proxy. Proxy then respond the object for the client, also saves a cache on the proxy server.
```
HTTP/1.1 200 OK
Date: Sat, 3 Oct 2015 15:39:29
Server: Apache/1.3.0
Last-Modified: Wed, 9 Sep 2015 09:23:24
Content-Type: image/gif

(data data data)...
```
4. If another browser request the same object, proxy server first ask original server whether the object is modified.
```
GET /fruit/kiwi.gif HTTP/1.1
Host: www.exotiquecuisine.com
If-modified-since: Wed, 9 Sep 2015 09:23:24
```
5. The web server sends a response message to the cache that specifies `304 Not Modified`. In other cases which the object is modified, original server will include the object in the entity body.
```
HTTP/1.1 304 Not Modified
Data: Sat, 10 Oct 2015 15:39:29
Server: Apache/1.3.0 (Unix)

(empty entity body)
```

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.