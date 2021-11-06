-----------------------------------------------
# Security Information and Event Management (SIEM)
Tags:  #Security 
Creation date: 2021-11-03

-----------------------------------------------

Accumulates the data from [[Intrusion Detection Systems#Tools]], analyse it and allows us to view is in a unified way. This is useful as individual alerts can seem insignificant. For example if many requests from the same IP the SIEM can correlate these.

Provides the SOC team with a global view of the network and its devices. It can also proactively generate alerts for predefined security events.

## Functions

### Log collection
- Pulls and receives log data from all relevant devices and systems across the network
	- Routers
	- Firewalls
	- [[Intrusion Detection Systems]]
	- Servers
	- Server and Desktop OS
- Can be agent-based and agent-less 

### Monitoring

Monitoring all the data in the SIEM allows us to monitor and identify any events of interest across the network.

This allows us to have continuous:
- User activity monitoring
- Object access monitoring
- File integrity monitoring
- Application log monitoring

### Log analysis

Being able to process and analyse the logs, display accumulated results on the dashboards.

Can include:
- User and entity behaviour analytics (UEBA)
- Privileged user monitoring and audit (PUMA)

### Event Correlation

Correlates events which are distributed across multiple logs or multiple devices. This allows us to look for common trends and attributes that link different events together in a single sequence thus building a more complete picture of the attacker's actions.

### Data visualisation

Dashboards provide a human-friendly representation of the raw data using:

- Graphs
- Charts
- Maps
- Summarised data

### Real-time Alerting

Based on the above analysis the SIEM can alert the [[Security Operations Centre (SOC)]] team of any suspicious activity across the network.

### Log retention and forensics

Provides support to the incident response team in investigating the attacks, so that the attack can be stopped early and consequences mitigated.