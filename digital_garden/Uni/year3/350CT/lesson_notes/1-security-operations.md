## 

If you are an organisation of interest you **will** be targeted

#### The attackers
-	nation state
-	organised crime
	-	can both have high budgets and smart actors

#### Attack methods are evolving
-	many attacks are unpredictable:
	-	file-less
	-	malware-less
	-	complex anti-detection
	-	anti forensics
	-	multistage
	
#### no system is secure and the defenses will eventually be breached
- we must assume hackers are in the network
- we can make their lives miserable and kick them out before they do damage

## stuff

-	70% of attacks are opportunistic and done by automatic tools
-	29% are persistent targeted well organised attacks, will not back down.
	-	Will target high value targets
	-	this module will focus on the 29%/1% of attacks. Using a SOC to stop the sophisticated attacks.

## The cyber kill chain

developed by Lockheed Martin as part of intelligence driven defense, the stage of an attack:
-	recon
	-	Need to control leaks of information from employees
	-	run threat intel, looking at darknet for info being sold and distributed about the organisation. Or anyone looking for information about the company.
-	weaponisation
	-	after IDing weakness will create tailor made malware and tools to attack the target
-	delivery
	-	using the attack vector
-	installation
-	command and control
	-	lateral movement, persistence, etc

Making the lives of attackers difficult at each step will make it more likely to detect an attack.

## security operations

standard methods no longer substantial enough to stop attacks (AV firewall etc).
We have to manually monitor traffic and alerts, then react to what the alerts say.
High volume of various data to perform analysis on.

## security operations centre (SOC)

The team monitoring and responding to alerts coming from security systems. Is essentially a virtual equivalent to a physical security control room.

actions can be proactive (pentests) or reactive.

SOC will create, implement and enforce organisation security policies.

### implementation

-	in-house SOC
	-	mainly used by large organisations (banks, ISPs, large companies)
	-	expensive
-	virtual soc
	-	medium sized organisation
	-	comprised of IT team members and other employees
	-	as and when something happens these other employees are pulled to act as a SOC
-	managed security service provider (mssp or SOCaaS)
	-	Contracted by other organisations to act as a remote SOC
	-	one of the most common SOC solutions
-	collaborative cyber security
	-	teaming up of multiple SOCs to work together
	-	for example all energy companies in the UK would link their SOCs together so if one company is attacked, all other companies would start to monitor for the same threat
	-	good for detecting attack campaigns

### Roles and responsibilities

-	monitoring
	-	infrastructure
	-	data
	-	designed to be able to decide if something is a false pos or a threat
-	incident response
-	threat intel
-	risk amanagement
-	info assurance
-	information security compliance
-	security governance

### SOC team

-	tier1 sec analyst
	-	manage security monitoring tools
	-	run vulnerability scanning analysis
	-	filter security alerts, forwarding them to tier 2 sec analyst
-	tier2 sec analyst (incident responder)
	-	responding to tier 1 alerts
	-	leveraging emerging threat intel
	-	determines and directs remediation and recovery efforts
-	tier3 expert sec analyst (threat hunter)
	-	reviews asset discovery and culn assessment data
	-	explores ways to identify stealthy threats using the latest threat intel
	-	pentest production systems
	-	recommends how to optimise security monitoring tools based on therat hunting discoveries
-	tier4 SOC manager (operations and management)
	-	manages the escalation process and reviews incident reports
	-	develops and executes crisis communications plan to ciso and stakeholders
	-	runs

### SOC process

- Asset discovery
	- need to know where all machines are, maintaining up to date inventory of all assets
		- run active and passive scans on the network to get full picture of network
	- need to know business process, which machines should or should not be communicating
	- need to know which systems are critical assets, potential pathways 
		- also machines these rely on
	- network infrastructure
	- where to set up monitors
- event classification and triage
	- collecting correlating and analysing traffic/log/etc
		- filter out false positive
		- pick up on IOCs
		- automation is critical
	- when event happens first thing is triage
	- need to decide which events are higher priority or can be looked at later
	- no event ignored, some just more urgent
	- **everything** should be documented
		- need to revisit situations to learn lessons
		- need docs in case of formal legal/disciplinary actions
-	prioritisation and analysis
	-	focus on most impactful events
		-	is attack opportunistic or targets APT attack?
	-	earlier stage questions:
		-	who
		-	what
		-	where
		-	this intel is vital if attackers return to attack again
-	remediation and recovery
	-	Quick ID and response is critical
-	assessment and audit
-	assessing the organisation security posture
-	can involve pentesting

## defense in depth

-	layering security of infrastructure and information
-	starting with the asset in the centre, build a layer upon layer of security enforcement (policy/processes/tools/etc)
-	need to still monitor those defenses
	-	tools:
		-	vuln scanners
		-	behavioral monitors
		-	IDS - Intrusion Detection System

### monitoring infrastructure

#### collect, correlate and analyse
cant get all information because too expensive, need to collect as much relevant info as possible. bring info to central position to soc, correlate info (is this the same attack etc)


#### Where to deploy sensors?

PASTA
VAST
TRIKE
Attack trees

