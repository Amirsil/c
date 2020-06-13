import socket
from sys import stdout
HOST = '127.0.0.1'
PORT = 42069
SECRET_KEY = "0XDEADBEEF"
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    string = ''
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            if string == SECRET_KEY:
                s.close()
                break
            data = conn.recv(1).decode()
            if (string + data) in SECRET_KEY:
                string += data
            else:
                string = ""
            stdout.write(data)
