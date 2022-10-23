import socket
import random
import time
import threading
import struct
import pickle
import _thread
from timer import Timer

def conError():
    print ("connection error")
    s.close()

def estConnection(port, host):
        data, addr = sock.recvfrom(1024) # receive 1
        if data:
            print ("Received {} from {}".format(data,addr))
            sock.sendto(data, addr) # sending 1
            print ("Sending {} to {}".format(data,addr))
            data, addr = sock.recvfrom(1024) # receive 2
        if data:
            print("Connection Established")
            return addr
        else:
            print("Connection Failed")
            sock.close()
def disconnection(data, sock, addr):
        if data == b'terminated':
            sock.sendto(b'okay', addr)
            print("Received close acknowledgement from {}".format(addr))
            print("Connection Closed")
            sock.close()

#create data list
def dataCreate():
    for i in range (dataSize):
            dataList.append(random.randint(1,1001))
			
#insert dataList to a file
def fileCreate():
    file = open("data.txt", "w")
    dataCreate()
    for i in DataList:
        file.write(str(i) + "\n")
    file.close()

#open file
   try:
        file = open(data.txt, 'r')
    except IOError:
        print('Unable to open', data.txt)
        return

# Sets the window size
def windowSizeSet(packetNums):
    global base
    return min(windownSize, packetNums - base)

#send using thread
def sendTo():
	global mutex
    global base
    global timer
	 # Add all the packet to the buffer
    packet = []
    seqNum = 0
    while True:
        data = file.read()
        if not data:
            break
        packet.append(packet.make(seqNum, data))
        seqNum += 1

    packetSeq = len(packet)
    print('I gots', packetSeq)
    windowSize = windowSizeSet(packetSeq)
    sendNext = 0
    base = 0

    # Start the receiver thread
    _thread.start_new_thread(receive, (sock,))

    while base < packetSeq:
        mutex.acquire()
        # Send all the packet in the window
        while sendNext < base + window_size:
            print('Sending packet', sendNext)
            sock.sendto(sendNext,clientAddress)
            sendNext += 1

        # Start the timer
        if not timer.running():
            print('Starting timer')
            timer.start()

        # Wait until a timer goes off or we get an ACK
        while timer.running() and not timer.timeout():
            mutex.release()
            print('Sleeping')
            time.sleep(timerSleep)
            mutex.acquire()

        if timer.timeout():
            # Looks like we timed out
            print('Timeout')
            timer.stop();
            sendNext = base
        else:
            print('Shifting window')
            window_size = set_window_size(packetSeq)
        mutex.release()

    file.close()



#Resources for threading
base = 0
mutex = _thread.allocate_lock()
timer = Timer(timerTimeout)

clientAddress = 
serverAddress = 
timerSleep = 0.10
timerTimeout = 5
windowSize = 3



array = []
for i in range(20):
    array.append(random.randint(1,1001))
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
data_array = pickle.dumps(array)

host = socket.gethostname()
port = 8000
sock.bind((host,port))
address = estConnection(host, port)
sock.sendto(b'close', address)
data, addr = sock.recvfrom(1024)
print(data)
disconnection(data, sock, addr)