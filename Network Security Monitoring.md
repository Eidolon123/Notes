-----------------------------------------------
# Network Security Monitoring
Tags:  
Creation date: 2021-11-02

-----------------------------------------------

The process of collection and analysis of network traffic and endpoint events in order to detect and respond to intrusions. This process is mainly based on collecting and analysing [[Indicators of Compromise]].

Network - Collecting traffic (some) and analyse, logs and alerts from network devices.

## Phases

### Collection

Ideally with infinite bandwidth/money/etc we would collect all traffic/log/event/registry/etc data. This is not possible so we need to carefully select what data we collect and how we will analyse it.

#### Questions to answer

- What are our assets?
	- What are the attack pathways to those assets (Attack Tree/Attack Graphs from redteam)?
- What is the useful data that will allow us to identify an attack? This can also be answered by redteam efforts
	- Where is this useful data?
- The legal and ethical constraints
- Who are the threats? ([[Threat Intelligence]])

 #### Types of data
 
 ##### Full packet data
 
 Collect and store the whole packets of everything on the network. This allows us to have very detailed event reconstruction and relevance to the attack.
 The amount of data collected using this method is huge and usually done using specialised hardware so will be quite expensive.
 
 This is rarely seen in real life, usually turned on when an incident is detected.
 
 ##### Session Data
 
 Collect and store the TCP session data. This means we would collect the TCP and IP headers, giving us information such as: Source and destination IP addresses, port numbers, timestamps and the size of data.
 For non-session based protocols such as UDP we can use heuristics instead.
 
 This allows us to see communication and activity patterns and current location of the attack.
 
 This method collects and stored significantly less data than [[#Full packet data]].
 
 ##### Statistical Data
 
 This method collects and stores some statistical info about the traffic collected. The number of DNS requests can identify the DNS being used as a channel to exfiltrate data for example. High volumes of outgoing traffic is also another identifier of this.
 
 Collects and stored even less data than [[#Session Data]] so can be running basically 24/7
 
 ##### Alert Data
 
 Collecting and storing information from security [[Monitoring]] tools. (Firewalls, IDS, EDR, etc.) These alerts are combined in the [[SEIM]], looked at and stored so when attacked later on, can roll back the tape. Alerts could have evidence attached to them also.
                                                                                                                                                                                                         
### Analysis and Detection

This is usually a fully automated process as the volume of data can be huge.

Signature based is the oldest method of analysing this data, old fashioned but works. Modifications to attacks can bypass this method of detection.

Heuristic rules, where we define normal operations and backlisted operations, write them as rules for the [[Intrusion Detection Systems]]. If the heuristic rules are known to the attacker this can be quite easy to evade.

Machine Learning based analysis is still in it's infancy but is being actively developed. This is where a ML algorithm will be run over the network to learn the normal behaviour of the systems, build a baseline, then anything that deviates from this baseline will generate an alert. The benefit of this approach is that it can detect unknown attacks better than other methods. Anomaly detection is good at new attacks but suffers from false positives. Event classification uses known attacks to train the model, hopefully building in enough variation to detect attacks that have evolved from previous attacks.

### Response