#!/usr/bin/python3

# a simple TCP server

import socket,sys,errno

PORT=55000
BUFLEN=1000

try:
    s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    s.bind(('',PORT))

    s.listen(1)
    con, addr = s.accept()

    print("Connection from {}".format(addr))

    data = con.recv(BUFLEN).decode()  # convert from byte array to string using UTF-8
    while (data):
        # get the length of the received message and send it as one byte
        print("Received {}, counting {}".format(data, len(data)))
        con.send(len(data).to_bytes(1, byteorder='big'))
        data = con.recv(BUFLEN).decode()  # convert from byte array to string using UTF-8

    con.close()

except OSError as err:
    print("Oops: {}".format(err.strerror))
    sys.exit(1)


