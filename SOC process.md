-----------------------------------------------
# SOC process
Tags:  #Security #Uni 
Creation date: 2021-10-05

-----------------------------------------------

## Asset discovery
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

## Event classification and triage

- Collecting, correlating and analysing traffic/log/etc data.
	- This is to pick up on [[Indicators of Compromise]]
	- Remove false positives
	- automation is critical

## Prioritisation and analysis

- Making sure we focus on the most important events
	- APT
	- If the attack targets high value assets
- All attacks should be investigated to gather intel on attackers, if they come back to attack again this could be critical information/evidence allowing us to stop them faster. This is why sometimes we would let the attackers carry out their attack while we monitor, this depends on the situation though, mainly if they end up attacking a honeypot service. We want to find out the who/what/where.

## Recovery

## Assessment and Audit

