-----------------------------------------------
# Intrusion Detection Systems
Tags:  #Uni #Security #IDS
Creation date: 2021-10-05

-----------------------------------------------

Detects attacks by matching criteria which are not present during normal operation. The blocking of normal functions can also indicate compromise.

Host based has moved more towards [[End-Point Detection Response]] and [[Antivirus]]

## Tools

[[Snort]]
[[Zeek]]
[[Suricata]]
[[OSSEC]]
[[Kismet]]
[[Modsecurity]]

## Network Intrusion Detection System (NIDS)

A NIDS is an independent platform that monitors network traffic and examines hosts to identify intruders. They connect to network hubs or network taps and are often placed in a [[#DMZ]] or network border. They then capture network traffic and analyse individual packets for malicious content.

If a NIDS protocol is well-placed within a network it can monitor total network traffic without impacting performance on the network. It also does not add to the traffic volume.

## Host-based Intrusion Detection System (HIDS)

A HIDS is an agent installed directly onto a host machine to monitor for malicious traffic that goes through system calls, application logs, file system modification, etc.
For example, it would monitor password attempt patterns to see if it is similar to a known bruteforce attack pattern. 

As it operates on a host machine it can also work in environments where the network traffic in encrypted.

Effective as it can detect events that a [[#network intrusion detection system]] may miss such as software integrity breaches.

## Perimeter Intrusion Detection System (PIDS)

PIDS act as an early warning system, cost effective as can just be affixed to the current system without much adjustment.

## VM-based Intrusion Detection System (VMIDS)

A combination of the above three ID systems but deployed remotely via a virtual machines. Is still being improved as a system.

## Where to deploy sensors?

The IDS is only as good as the data that they can see.

A network diagram can be invaluable to IDS planning. When looking at the diagram, evaluate key network choke points or collections of systems that are sensitive to business operations.

PASTA
VAST
TRIKE
Attack trees
