## What is Network Security Monitoring (NSM)?

The primary objective of NSM is the timely detection and effective response to any computer security intrusions or incidents. 

An incident in this context can be defined as:
> Violation or imminent threat of violation of computer security policies, acceptable use policies, or standard security practices. *(Generic Definition)*

**or**

> Any unlawful, unauthorised or unacceptable action/activity that involves a computer system, cell phone, tablet and any other electronic device with an operating system or that operates on a computer network. *(Specific definition)*

## What does NSM do?

When we capture network traffic and system activity data we also want to collect and analyse ***[[#Indicators of Compromise IOC]]***. These allow us to identify and understand the actions, intentions and capabilities of any attacker. 

### Indicators of Compromise (IOC)

IoC can be network or host based and include:

- IPs
- Protocol signatures
- Directory names
- File names
- Persistence mechanism
- Login, usernames and passwords
- checksums

## Signature based IDS

## anomaly based IDS

### Zeek (Bro)

An example of an IDS that has behavioural analytics

Can extract and store payloads

Traffic analysis

- Runs one event engine per protocol per data stream
- policy script interpreter, can describe company security policy in a script so zeek can implement it.

Uses signatures

## Host based IDS

### OSSEC

A client is deployed on the host, data is then sent to the server. Even if end point is compromised the evidence of attack is safe on the server

Monitors:  
- File integrity (system files)  
- System logs/events  
- Installed software  
- Network connections  
- Etc.  
- Client/Server architecture  
- Processing is on the server  
- Forensic evidence is on the server


## Wireless IDS

### Kismet

lightweight, can be run on mobile devices

Monitors:  
•File integrity (system files)  
•System logs/events  
•Installed software  
•Network connections  
•Etc.  
•Client/Server architecture  
•Processing is on the server  
•Forensic evidence is on the server

