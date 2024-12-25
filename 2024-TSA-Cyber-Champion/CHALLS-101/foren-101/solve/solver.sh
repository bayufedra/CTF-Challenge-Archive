#!/bin/bash

tshark -r packet.pcap -T fields -e data -Y "ip.src==192.168.56.1 && icmp.type==8" | tail -n +2 | cut -c 17-48 | xxd -r -p > img.png
foremost img.png
