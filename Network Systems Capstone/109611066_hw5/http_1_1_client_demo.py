from http.http_1_1_client import HTTPClient
import os
import glob
import xml.etree.ElementTree as ET
import json

if __name__ == '__main__':
    server_ip = "10.0.2.15"
    sid = "123"
    client = HTTPClient()

    target_path = "./target"
    response = client.get(url=f"http://{server_ip}:8080/")
    file_list = []
    if response and response.headers['content-type'] == 'text/html':
        root = ET.fromstring(response.get_full_body().decode())
        links = root.findall('.//a')
        file_list = []
        for link in links:
            file_list.append(link.text) 

    for file in glob.glob(os.path.join(target_path, '*.txt')):
        os.remove(file)

    for file in file_list:
        response = client.get(f"http://{server_ip}:8080/static/{file}", stream=True)
        file_path = f"{target_path}/{file}"
        if response:
            print(f"{file_path} begin")
            with open(file_path, "wb") as f:
                while True:
                    content = response.get_stream_content()
                    if content is None:
                        break
                    f.write(content)
            print(f"{file_path} end")
        else:
            print("no response")

    body = json.dumps({"id": sid}).encode()
    headers = {"Content-Type": "application/json", "Content-Length": len(body)}
    response = client.post(f"http://{server_ip}:8080/hello", headers=headers, body=body)
    if response:
        print(response.get_full_body().decode())
    
    