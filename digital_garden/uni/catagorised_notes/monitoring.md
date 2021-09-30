## monitoring infrastructure

### IDS - intrusion detection systems

#### network intrusion detection system

A NIDS is an independent platform that monitors network traffic and examines hosts to identify intruders. They connect to network hubs or network taps and are often placed in a [[#DMZ]] or network border. They then capture network traffic and analyse individual packets for malicious content.

If a NIDS protocol is well-placed within a network it can monitor total network traffic without impacting performance on the network. It also does not add to the traffic volume.

#### host-based intrusion detection system

A HIDS is an agent installed directly onto a host machine to monitor for malicious traffic that goes through system calls, application logs, file system modification, etc.
For example, it would monitor password attempt patterns to see if it is similar to a known bruteforce attack pattern. 

As it operates on a host machine it can also work in environments where the network traffic in encrypted.

Effective as it can detect events that a [[#network intrusion detection system]] may miss such as software integrity breaches.

#### perimeter intrusion detection system

PIDS act as an early warning system, cost effective as can just be affixed to the current system without much adjustment.

#### vm-based intrusion detection system

A combination of the above three ID systems but deployed remotely via a virtual machines. Is still being improved as a system.

### DMZ

A demilitarized zone (DMZ) refers to a host or network that acts as a secure and intermediate network or path between an organization's internal network and the external, or non-propriety, network.

A DMZ serves as a front-line network that interacts directly with the external networks while logically separating it from the internal network.

A demilitarized zone may also be known as a network perimeter or perimeter network.

### collect, correlate and analyse

A soc cant get all information because it would be too expensive, so they need to collect as much relevant info as possible. Then bring all info to central position to soc, correlate info (is this the same attack etc).


### Where to deploy sensors?
A network diagram can be invaluable to IDS planning. When looking at the diagram, evaluate key network choke points or collections of systems that are sensitive to business operations.

PASTA
VAST
TRIKE
Attack trees
