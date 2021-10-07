-----------------------------------------------
# Endpoint Security Monitoring (ESM)
Tags:  #Security #Uni 
Creation date: 2021-10-07

-----------------------------------------------

ESM is focused on the collection, aggregation and continuous analysis of data from endpoint devices. This is in order to detect and respond to incidents promptly.

The main question is what data do we need?

- OS [[Logs]]
- App service [[Logs]]
- Process activity events
	- Processes that connect to network
	- Works well with whitelist of allowed software 
	- Powershell/CMD Activity
- reg keys
	- Integrity changes
- [[Autostart Extensibility Points]]
- [[Intrusion Detection Systems]] alerts
