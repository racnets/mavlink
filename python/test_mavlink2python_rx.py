#!/usr/bin/env python

# huch 2010

# test receiving mavlink messages over UDP
# 20101112, oswald berthold

import sys
import socket
import mavlink

from optparse import OptionParser

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
        print "in rx"
        while True:
            data, addr = self.sock.recvfrom( 2048 ) # buffer size is 1024 bytes
            print type(data), len(data), "data:'", data, "'"

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

    parser = OptionParser()
    parser.add_option("-m", "--mavhub",
                      action="store_true", dest="mavhub_enable", default=False,
                      help="enable mavhub communciation")
    (options, args) = parser.parse_args()

    rxsock = DataSock(options.mavhub_enable)
    
    rxsock.start_rx()

# main()

# Admire
if __name__ == '__main__':
    main(sys.argv)

