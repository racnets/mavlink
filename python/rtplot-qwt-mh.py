#!/usr/bin/env python

# huqk / huch 2010

# The Python version of Qwt-5.0.0/examples/data_plot
# modified to read mk debug or plaintext packets via udp
# from gumstix aboard the kopter
# 20100708, oswald berthold

# 

# for debugging, requires: python configure.py  --trace ...
if False:
    import sip
    sip.settracemask(0x3f)

import random
import sys
from datetime import datetime

from PyQt4 import Qt
import PyQt4.Qwt5 as Qwt
from PyQt4.Qwt5.anynumpy import *

import socket
from fccom import mkpackage
from fccom import c_marshal
from fccom import qk_datatypes
from struct import *
from ctypes import *

import numpy as np

import time
from optparse import OptionParser

import mavlink

#UDP_IP = "192.168.1.10"
MAVHUB_DEFAULT_HOST = "192.168.1.2"
MAVHUB_DEFAULT_PORT = 32001
UDP_IP = "0.0.0.0"
UDP_PORT = 5555

class DataSock():
    def __init__(self, *args):
        # socket
        self.sock = socket.socket(socket.AF_INET, # socket
                                  socket.SOCK_DGRAM ) # UDP
        self.sock.bind( (UDP_IP,UDP_PORT) )
        # self.sock.settimeout(0.1)

        if args[0]:
            print "connecting to mavhub"
            self.sock.connect((MAVHUB_DEFAULT_HOST, MAVHUB_DEFAULT_PORT))

    def start_rx(self):
        # receive network packets forever
        while True:
            data, addr = self.sock.recvfrom( 2048 ) # buffer size is 1024 bytes
            print type(data), len(data)
            print "data:'", data, "'"
            # bytes = pack(str(len(data)) + 'B', *data)
            # strct = mavlink.mavlink_message_t()
            # memmove(addressof(strct), bytes, len(bytes))
            a = mavlink.mavlink_message_t()
            b = mavlink.mavlink_huch_attitude_t()
            mavlink.mavlink_message_from_data(a, data, len(data))
            # a = mavlink.mavlink_message_t()
            # memmove(addressof(a), data, len(data))
            # print addressof(a)
            print a
            print "len", a.len, "seq", a.seq, "sysid", a.sysid, \
                  "compid", a.compid, "msgid", a.msgid, \
                  "payload", a.payload, "ck_a", a.ck_a, "ck_b", a.ck_b
            mavlink.mavlink_msg_huch_attitude_decode(a, b)
            print b
            print b.xacc, b.yacc
            #del a
            # print 0 + int(data[1])
            #time.sleep(0.5)
            # try:
            #     data, addr = self.sock.recvfrom( 2048 ) # buffer size is 1024 bytes
            #     a = mavlink.mavlink_message_t()
            #     memmove(addressof(a), data, len(data))
            #     print a
            #     print data
            #     print addr
            # except:
            #     # print "timeout?"
            #     print "failed"
            #     return


def main(args):
    
    rxsock = DataSock(options.mavhub_enable)

    rxsock.start_rx()

# main()

# Admire
if __name__ == '__main__':
    main(sys.argv)

# Local Variables: ***
# mode: python ***
# End: ***
