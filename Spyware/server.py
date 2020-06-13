import socket
from sys import stdout
HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 42069        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    string = ''
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            if "0" * 8 in string:
                s.close()
                break
            data = conn.recv(1).decode()

            if not data:
                break
            if not string and data == "0":
                string += data

            elif string == "0":
                if data == "X":

                    string += data
                else:
                    string = ""

            elif string and string != "0":
                if data == "0":
                    string += data
                else:
                    string = ""
            stdout.write(data)