import sys, time
from socket import *

# Get the server hostname and port as command line arguments
argv = sys.argv
host = argv[1]
port = argv[2]
timeout = 1 # in seconds

# Create UDP client socket
clientSocket = socket(AF_INET, SOCK_DGRAM)

# Set socket timeout as 1 second
clientSocket.settimeout(1)

# Command line argument is a string, change the port into integer
port = int(port)

#Sequence number of the ping message
ptime = 0

# Ping for 10 times
while ptime < 10:
    ptime += 1
    #Format the message to be sent
    data = "Ping" + str(ptime) + "" + time.asctime()

    try:
        # Sent time
        RTTb = time.time()

        # Send the UDP packet with the ping message
        clientSocket.sendto(data, (host, port))

        # Recieve the server response
        message, address = clientSocket.recvfrom(1024)

        # Received time
        RTTa = time.time()
        # Display the server response as an output
        print("Reply from " + address[0] + ": " + message.decode())
        # Round trip time is the difference between sent and received time
        print("RTT: " + str(RTTa - RTTb))

    except:
        # Server does not respond
        # Assume the package is lost
        print "Request timed out."
        continue

# Close the client socket
clientSocket.close()
