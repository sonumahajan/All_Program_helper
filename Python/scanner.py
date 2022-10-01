#!/bin/python3

import sys
import socket
from datetime import datetime

if len(sys.argv) == 2:
    target = socket.gethostbyname(sys.argv[1])
else:
    print("Invalid Syntex")
    print("Syntex: python3 scanner.py <ip>")

print("-" * 50)
print("Scanning Target: " + target)
print("Time: " + str(datetime.now()))

try:
    for port in range(50, 85):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        socket.setdefaulttimeout(1)
        result = s.connect_ex((target, port))
        if result == 0:
            print("Port {} is open.".format(port))
        s.close()
except KeyboardInterrupt:
    print("\n Exiting Program.")
    sys.exit()
except socket.gaierror:
    print("\n This host could not be resolved")
    sys.exit()
except socket.error:
    print("\n Unable to Connect this server")
    sys.exit()
    
