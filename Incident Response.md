-----------------------------------------------
# Incident Response
Tags:  #Security #Uni 
Creation date: 2021-10-06

-----------------------------------------------


Incident response is the  main reactive job of the [[Security Operations Centre (SOC)|SOC]]

This is where we detect and respond to security incidents that happen on our systems and network.

## Three stages of Incident Response

The security response process can be broken down into three stages: [[#Preparation]], [[#Detection and Evaluation]] and [[#Response]].

![[security-incident-response-process.png]]

### Preparation

In this stage our primary objective is to make sure we have all the information we will need in order to counter any incident detected. First and foremost in this preparation is **asset discovery**. This is where all devices, servers, end-points and access-points in the network are mapped.

In an ideal work the [[Information Technology Service Management]] system has already logged all items in the system and the asset discovery phase would just be collecting the data from the **configuration management database (CMDB)**. More often than not though it is best practice to carry out your own discovery processes while just being informed by the CMDB. This is to ensure the SOC always has the correct information when it needs it. To keep this information up to date it is common practice to perform periodic scans of the network to check for changes.

In the preparation phase [[policies-and-procedures]] are created also.

### Detection and Evaluation

The detection and evaluation phase is where we are finding potential compromises and analysing them to see if they need to be dealt with or not. **[[Indicators of Compromise]]** are what we are looking at in the first stages of detection and evaluation.

Analysis of IoC should be largely automated in order to avoid trivial or false-positive IoC being delivered to the SOC. Once an IoC has been detected the next phase is [[#Triage]].

#### Triage

The process of triage comes from the medical world and is used to determine the severity of an incident to better inform on which incidents need a more urgent response. In terms of a SOC triage is split into three sub-processes: Verification, Initial Classification and Assignment. This whole process needs to be undertaken quickly and efficiently with a focus on incidents involving critical assets, all compromises should be investigated however.

##### Stages of Triage

- Verification
	- Where an analyst, probably a [[SOC team|tier 1 analyst]], will confirm it is a previously unseen incident.
- Initial Classification
	- Where the type and severity of the incident is initially determined.
- Assignment
	- Where the incident is assigned to a particular analyst or team of analysts depending on the severity of the incident. 

Once triage has been completed an [[#Analysis]] of the compromise should begin, in order to do this completely the analyst will often have to perform additional **data collection**. This can be in the form of [[Threat Intelligence]], [[Monitoring|monitoring]] information or something like login logs of a particular system.

#### Analysis

The goal of the analysis of the compromise are to answer the following questions as fully as possible:

- What
	- What exactly in the network was compromised?
- Where
	- Where in the network is the compromised system?
- How
	- How did they compromise the system?
- When
	- When did the compromise happen?
- Why
	- Why was that system compromised? Was the system of critical importance?


The [[OODA]] loop is another approach to the detection and evaluation phase.

### Response

The response phase can be broken down into 4 further sub-processes: [[#Containment]], [[#Recovery]], [[#Reporting]] and [[#Further analysis]]

#### Containment

We need to ensure that any compromise does not spread unchecked through the rest of the network. Unless the compromise is in a honeypot system then it could be left to spread through the honeynet, but not beyond obviously. 

#### Recovery

The recovery after a compromise often involves the rebuilding of systems and recovery of data from backup images. In extreme cases such as complex or advanced persistent threats the replacement of hardware may be necessary, this is often not the case though.

A choice has to be made during the recovery process: Do we recovery quickly and potentially destroy evidence or do we investigate further at the cost of operational resources? The former option is likely to be used when the recovery is focused around critical systems or the threat is more advanced/serious, with the latter option used in cases of less seriousness.  

#### Reporting

The reporting stage will normally involve recording all information relevant to the incident in the appropriate knowledge base, then informing management of what exactly occurred.

It is important in this stage to make sure reports are being used to further the security of the operation and not just archived and forgotten. This is where [[#Further analysis]] comes in.

#### Further analysis

This is where the SOC needs to consider what exactly when wrong and how to mitigate against the same or similar attacks happening again. It can be useful in this stage to change any relevant [[policies-and-procedures]] to ensure the same attack cannot happen again.