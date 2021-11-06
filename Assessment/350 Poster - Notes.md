-----------------------------------------------
# 350 Poster
Tags:  #Assessment #Security
Creation date: 2021-11-01

-----------------------------------------------


## prepare a poster presenting the proposed SOCaaS.

---

## Ideas

https://www.ncsc.gov.uk/collection/supply-chain-security/principles-supply-chain-security/understand-the-risks

https://securityboulevard.com/2021/07/cybersecurity-in-supply-chain-management-risks-to-consider/

https://web.archive.org/web/20150218220339/https://www.cert.gov.uk/wp-content/uploads/2015/02/Cyber-security-risks-in-the-supply-chain.pdf

## Notes on the brief

Your proposal should also address compliance with relevant national and international standards and regulations.

setup a Managed Services SOC (SOC-as-a-Service) in your company which will provide dedicated services (remotely) to the companies in the TTEV’s supply chain.

should be clear, concise, legible and interesting.

Diagrams are good for presenting a lot of information.

TTEV has to share sensitive information across its supply chain (e.g. car part designs and specifications)

## Supply chain definition

Hardware and software, cloud or local storage and distribution mechanisms

## Sections

### Integrity checks 3rd party code

Need to make sure 3rd party code from suppliers hasn't been tampered with before being used.

### Integration with existing IT departments

### SOC Structure

- [[SOC team]]
- [[SOC Roles]]
- [[SOC process]]

### Software/Hardware

- Encryption Standards
- [[Zeek]]
- [[OSSEC]]
- [[Kismet]]

### Threat intelligence

- Dedicated team
- Darknet monitoring for info about company or people looking for info

### Indications of compromise

### Reports

- Brief overview of how reports will be structured

### What guidelines?

- ISO/IEC 27035:2016
	- Prepare
	- Identify
	- Assess
	- Respond
	- Learn	

### Keeping systems online while SOC is implemented

### Governance

### Collaborative cyber security

### Examples of previous attacks

#### Watering hole attacks

A watering hole attack utilises a website that the victim already uses and is familiar with. This site is then targeted in order to infect the victims machine, launching a pivot attack towards the rest of the network. This could compromise the entire supply chain.

This could be mitigated by restricting the use of personal websites on corporate systems with a blacklist.

### Using the ELK stack