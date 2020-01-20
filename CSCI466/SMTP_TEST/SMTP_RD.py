from socket import *

msg = "\r\n I love computer networks!"

endmsg = "\r\n.\r\n"

# Choose a mail server (e.g. Google mail server) and call it mailserver

mailserver = ("list.winthrop.edu", 25)

# Create socket called clientSocket and establish a TCP connection with mailserver

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect(mailserver)

recv = clientSocket.recv(1024).decode()

print(recv)

if recv[:3] != '220':
    print('220 reply not received from server.')

#send HELO command and print server responseself.

heloCommand = 'HELO Alice\r\n'

clientSocket.send(heloCommand.encode())

recvl = clientSocket.recv(1024).decode()

print(recvl)

if recvl[:3] != '250':
    print('250 reply not received from server.')

#send MAIL FROM command and print server response.

mailFrom = "MAIL FROM:<rankindam@yahoo.com>\r\n"
clientSocket.send(mailFrom.encode())
recv2 = clientSocket.recv(1024).decode()
print("After MAIL FROM command: " + recv2)

if recv2[:3] != '250':
    print('250 reply not received from server.')

#Send RCPT TO command and print server response.

rcptTo = "RCPT TO:<damr2@winthrop.edu>\r\n"
clientSocket.send(rcptTo.encode())
recv3 = clientSocket.recv(1024).decode()
print("After RCPT TO command: " + recv3)

if recv3[:3] != '250':
    print('250 reply not received from server.')

#Send DATA command and print server response.

data = "DATA\r\n"
clientSocket.send(data.encode())
recv4 = clientSocket.recv(1024).decode()
print("After DATA command: " + recv4)

if recv4[:3] != '354':
    print('354 reply not received from server.')

#Send message data.

clientSocket.send(msg.encode())

# Message ends with a single period.

clientSocket.send(endmsg.encode())
recv_msg = clientSocket.recv(1024).decode()
print("Response after sending message body: " + recv_msg)

if recvl[:3] != '250':
    print('250 reply not received from server.')

# Send QUIT command and get server response.

quit = "QUIT\r\n"
clientSocket.send(quit.encode())
recv5 = clientSocket.recv(1024).decode()
print(recv5)

clientSocket.close()
