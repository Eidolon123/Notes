-----------------------------------------------
# Network Forensic Analysis
Tags:  #Security #Uni 
Creation date: 2021-11-04

-----------------------------------------------

## Packet Analysis

Capture and interpret live network traffic data. This allows us to understand the network, who is on the network and what services are being used, who is using them and what for.

## ARP data

Address Resolution Protocol is used to find MAC to IP mapping.

## DHCP data

Dynamic Host Configuration Protocol is used to assign MAC to IP mapping.

The host broadcasts trying to find a DHCP server, may get many replies from DHCP servers. Host then broadcasts requesting an IP, DHCP server replies with IP.

## Analysing Port Scanning

- ARP Scans
- TCP connect
- TCP SYN scan
- TCP FIN scan
- TCP XMAS scan
- TCP NULL scan
- UDP scan
- Application layer scans

## DNS Traffic

Domain name system provides the Hostname to IP mapping, as well as MX.

Host makes request with hostname, DNS replies with IP of that hostname.

## HTTP Packets

## Examining abnormal traffic

- Unusual addresses
- Unusual volumes of traffic
- Unusual exfiltration of data
- Unusual events (login from a strange place)
- Unusual absence of data (logs have been deleted)

### Discovering this abnormal traffic

- Broadcasts
	- Normal would be an ARP broadcast
	- Suspicious would be 100s or 1000s of broadcasts in quick succession.


## Spoofing

- MAC spoofing
	- Allows a user to impersonate or hide an identity

- IP spoofing
	- Creating IP packets with forged source IP addresses io impersonate a legit system. Often used in DoS attacks or to avoid detection.

- ARP spoofing
	- Sending faked ARP messages in the network. The purpose is to associate the MAC address with the IP address of another legit host causing 