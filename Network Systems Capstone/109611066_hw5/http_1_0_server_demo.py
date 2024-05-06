from http.http_1_0_server import HTTPServer

if __name__ == '__main__':
    server_ip = "10.0.2.15"
    server = HTTPServer(host=server_ip, port=8080)
    server.set_static("./static")
    server.run()

    while True:
        cmd = input()
        if cmd == 'close' or cmd == 'exit':
            server.close()
            break