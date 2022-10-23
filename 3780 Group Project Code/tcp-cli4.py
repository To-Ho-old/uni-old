#!/usr/bin/python3

# A simple TCP client (initiating a connection)

import sys,socket

PORT=55000
#DESTIP="142.66.140.13"  # linux1.cs

if len(sys.argv) != 2:
    print("Usage: {} destination_IP_addr".format(sys.argv[0])) 
    sys.exit(1)

try:
    s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    s.connect((sys.argv[1], PORT))

    msg = input("& ")
    while (msg != "bye"):
        if (not msg):
            msg = input("& ")
            continue

        s.send(msg.encode())
        data = s.recv(10)  # a sequence of bytes, receive max 10
        print("First byte received {}".format(int(data[0])))

        msg=input("& ")

    s.close()

except OSError as err:
    print("Oops: {}".format(err.strerror))
    sys.exit(1)
