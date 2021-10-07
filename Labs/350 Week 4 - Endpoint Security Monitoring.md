-----------------------------------------------
# 350 Week 4 - Endpoint Security Monitoring
Tags:  #Security #Lab #Uni #TODO
Creation date: 2021-10-07

-----------------------------------------------

## Task 1
```ad-question
title: Log Evidence
Complete the below list of logs and other sources where evidence of detecting and/or investigating an intrusion can be found.
```

When deploying our network security monitoring (NSM) infrastructure, setting up the detection rules and acting upon intelligence, we should be aware of where the relevant data and evidence can be found.

 The different state of an attack will leave traces in different places:

- **Reconnaissance**:
	- [[Darknet]] analysis – is someone looking for (requesting/buying) info about our organisation?
	- Web server logs
	- DNS server logs
	- Planted external honeynets/[[honeypot]]s with a deceptive website, ie secret domain looking like you have sensitive data

- **Scanning**:
	 - Firewall logs
	 - Web application firewall (WAF) logs
	 - NextGen firewall logs
	 - [[Honeypot]] logs
	 - [[Intrusion Detection Systems|IDS]] Logs (SNORT)
	 - Specialist port scanning detector logs - PortSentry and Scanlogd are two examples of these detectors.
	 - Resource monitoring
	 - Application/service logs

- **Exploitation**:
	- Event logs for scripts being run
	- Process Creation
	- File uploads
	- Registry keys
	- Modification to config files
	- SSH logs
	- System logs (Win syslogs, Linux syslogs)
	- Built-in mitigation has been disabled
	- AAA (Authorisation, Authentication, etc) logs

- **Privilege escalation**:
	- [[Power Shell]] Logs
	- [[Bash]] Logs
	- Event Logs
	- Monitoring for custom user made scripts that would be more susceptible to priv esc
	- Account creation logs
	- Registry keys
	- AAA (Authorisation, Authentication, etc) logs
	- DC and IDM logs ([[Active Directory]], etc.)

- **Data exfiltration**:
	- Unusually high network traffic
	- Data Loss Prevention DLP Logs
	- UBA logs
	- FW logs

- **Lateral movement**:
	- (Most of the above)
	- Account Creation Logs
	- Account access location
	- Start on boot applications
	- Checking for users that don't normally log into multiple machines in a day.
	- New executables
	- Unplanned internal scans
	- 

- **Social engineering**:
	- Human Firewall (Security Department, reports from employees)
	- Spam Filter
	- Threat Intelligence
	- LinkedIn
	- OSINT Framework
	- Spam email from inside company
	- Checking for credential leaks

---

## Task 2

```ad-question
title: Windows Security Components 1
Using Process Explorer utility from Sysinternals, find the files implementing the security components of the Windows operating system (some of them were discussed in the last article).
```



---

## Task 3

```ad-question
title: Windows Security Components 2
Determine SIDs for entries presented below.

Hint: use PsGetSID tool from the Sysinternals suite.
```

```
DESKTOP\Guest = 
DESKTOP\root = 
BUILTIN\Network Configuration Operators = 
BUILTIN\Users = 
TESTDOMAIN\Share_R = 
TESTDOMAIN\Share_RW =
```


---

## Task 4

```ad-question
title: Windows Security Components 3
Determine principals for entries presented in the feed below.

Hint: use PsGetSID tool from the Sysinternals suite.
```

```
S-1-5-21-3615843234-1321834752-1894537791-500 = 
S-1-5-21-3615843234-1321834752-1894537791-518 = 
S-1-5-21-3615843234-1321834752-1894537791-516 = 
S-1-5-32-551 = 
S-1-5-32-573 =
```

---
