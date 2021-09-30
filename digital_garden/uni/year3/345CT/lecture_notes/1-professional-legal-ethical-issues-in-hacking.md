## information_security

### CIA_triage

Not the CIA (American spy agency), abbreviation of the three main factors of information security.

![[cia-triad.png]]

#### confidentiality

Ensuring information is only disclosed and available to those with the authority to see and use it.

#### integrity

-	Preventing the modification of data by unauthorised personnel.
-	Preventing unintentional modification of data by unauthorised personnel.
-	Preserving internal and external consistency.
	-	Internal: Logical connection within the data.
	-	External: Logical connection between the objects in the real world and their representations in the system.
	-	Data can be said to be internally and externally consistent when a given input provides the exact expected output. Having unauthorised modifications to the data could result in a non expected output from the same input.

#### availability

Guaranteeing that authorised users have uninterrupted access to the system/information.

### other_factors

-	Authenticity: Confirming the origin and identity of info source.
-	Identification: confirming the users identity.
-	Authentication: confirming the ***evidence*** of a users identity.
-	Accountability: Ensuring a user is held accountable for their actions.
-	Non-repudiation: Removing a users ability to deny their actions.
-	Privacy: The protection of information that could identify a user.
-	Organisational security policy: A **high level** statement of the structure, processes and mechanisms covering information security.

## threats_and_ethical_hackers

### threats

Cyber attacks can be separated into three main categories:

#### technical_attacks

An attack from an outside source, usually targeting vulnerabilities in systems employed by the target organisation.

#### social_engineering

An attack that targets the employees of a company through various tactics:

-	Tailgating: Following someone into a building or doorway in order to bypass the need to gain an ID card or access device.
-	Baiting: An attack where the target is provided something that would be of use to them but is in fact something malicious. 
-	Phishing: An attack where the attacker assumes the identity of an authority figure or organisation in order to get the target to give them sensitive information.
-	Whaling: Similar to phishing but targeted at specific individuals that are usually high up in an organisation. These attack usually come with a lot more prep time than regular phishing.
-	Scareware: Where the target is shown lots of false alarms and notifications in order to convince them that their machine has already been compromised. The attackers then use this to get the target to install software that actually compromises the machine. This attack technique works best on less technologically literate people.


#### insider_threats

An attack that misuses the trust relations within an organisation (rogue actor).

### ethical_hackers

The difference between a white hat and black hat is that white hats have permission to do what they do and comply with all the relevant laws and regulations. When executing pen tests or red team attacks it is vital that the ethical hacker stay within organised scope. An ethical hacker also acts within the best interest of the organisation and treats all information discovered as confidential ([[#confidentiality]]).

#### how_it_works

Before a pen test takes place a formal contract with the client will be agreed upon. This contract will lay out several aspects of the pen test: (Covered more in week2).

-	White-box
	-	Hacker is given information such as WiFi passwords,  source code, network info and internal accounts. Gives the hacker a much broader view of the box and takes less time due to having the information already. Can be cheaper as well.
-	Black-box
	-	Hacker is given no information about the box in order to simulate a real-world attack much more closely.

#### skills

Hackers will often need to have a base knowledge of the full span of digital technologies as clients could be using anything in their setups. This need for a broad knowledge base is why ethical hacking is usually a team effort. Each member of the team will specialise in one or two aspects of ethical hacking and as a team will be able to deal with any situation they find in the field.

##### soft_skills

While it is okay to specialise in specific areas, all ethical hackers should posses the correct soft skills to enable them to act efficiently in a team setting.

-	Teamwork
-	Coordination
-	Cooperation
-	Problem Management
-	Report Writing

## security_clearance



## laws

Where the impact of the crime is, is who will be chasing you down. for example if a British national hacks into a US server, the British national would have to be extradited to the US for prosecution.

### common_law

-	UK
-	US
-	Australia
-	Canada

The decision on the case is decided by a jury of common people. Judge then decided sentence if guilty

### civil_law

-	Germany
-	France
-	etc

In this system the judge decides if the defendant is guilty

### islamic_law

-	some Muslim countries

### uk_law

#### computer_misuse_act 1990, 2006, 2015

##### relevant_sections
-	unauthorised_access
	-	The prosecution must be able to prove the defendant was aware that they were not authorised and had an intent.
	-	Max prison sentence 12 months / unlimited fine.

-	unauthorised_access_with_intent_to_commit_or_facilitate_commission_of_further_offenses

	-	The prosecution must be able to prove the defendant carried out the attack to further some other criminal intention (theft, etc).

	-	Max prison of 12 months for summary or 5 years for an indictment (an/or fine).

>A summary is for a non serious crime, if more serious it goes to indictment.

-	unauthorised_modification_of_computer_material

	-	This covers the intentional distribution of malware.

	-	max prison of 12 months
-	Unauthorised act in relation to a computer results, directly or indirectly, in serious damage to the economy, the environment, national security or human welfare, or a significant risk of such damage

	-	This aims to protect UK infrastructure, national security  and economy.
	-	max sentence of 14 years, can go up to life if risk of life involved


##### amendments

-	2006
	-	To comply with the European Convention on Cyber Crime  
	-	Increased maximum penalties  
	-	Made clear that DoS is a crime  
	-	Made the development/distribution or use of hacking tools illegal  
		-	if there is an intent to commit or assist in the commission of a crime  
	-	that covers virtually every tool that an ethical hacker will use


#### human_rights_act 1998 (article 8)

Article 8 is the most relevant section of the human rights act as it involves peoples privacy and family life.

> Private life means that a human has the right to live their life privately without government interference.

-	Everyone has the right to respect for their private family life and correspondence.
-	This can only be infringed when it is to:
	-	protect national security
	-   protect public safety
	-   protect the economy
	-   protect health or morals
	-   prevent disorder or crime, or
	-   protect the rights and freedoms of other people.

> It can be easy to violate the first clause of article 8 (the right to privacy in correspondence) when performing network-level snooping to access user passwords etc.

#### regulation_of_investigatory_powers_act

Mainly gives law enforcement and security services greater power of surveillance.
-	If law enforcement asks for your passwords and encryption keys you are required to give them, automatically guilty if you do not (2-3 years).

##### ripa_and_hackers

-	If performing traffic interception, get explicit written permission in the rules of engagement.
-	Be very careful about what you intercept on other peoples networks (wired, wireless, Bluetooth)
-	

#### investigatory_powers_act_2016

**Snoopers Charter**

Allows the UK authorities to run wild by:
-	bulk collecting communications data
-	targeted and bulk interception of communications
-	targeted and bulk equipment interference (hacking)

Requires CSP to retain connection records for 1 year.

It can be harder to perform these actions on journalists, lawyers and doctors.

#### communications_act_2003

-	section 127(1) covers offensive and threatening messages sent of a public electronic communications network (email, social engineering etc)
-	section 127(2) covers causing annoyance by sending messages known to be false (hoax calls, email).
> Should be careful when targeting employees.

#### data_protection_act

Governs the protection of personal data in the UK.
-	its purpose is to ensure that the information stored on individuals is:
	-	correct and up to date
	-	not being misused

Second guiding principal:

Personal data shall be obtained only for one or more specified and lawful purposes,  
and shall not be further processed in any manner incompatible with that purpose or  
those purposes.

Data registered under the DPA cannot be used for the purpose of security testing. If there is a violation of the DPA the client will be liable not you.

#### general_data_protection_regulation_2018



##### principals

Official:

(data should be)
-	processed lawfully and fairly in a transparent manner
-	collected for a specific, explicit and legitimate purpose and not further processed in a manner that is incompatible with those purposes
-	adequate, relevant and limited to what is necessary in relation to the purposes for which they are processed
-	accurate and kept up to date where necessary
-	kept in a form which permits identification of data subjects for no longer than necessary for the purposes for which the personal data are processed
-	processed in a manner that ensures appropriate security of the personal data, including protection against unauthorised or unlawful processing and against accidental loss, destruction or damage, using appropriate  technical or organisational measures

summary:

-	data should be processed lawfully and fairly, must be transparent.
-	data needs to be collected for a legitimate, specific, explicit purpose. Any processing beyond this purpose is unlawful.
-	data should be limited to what is relevant to the purpose of the data.
-	data should always be accurate and up to date.
-	If the data is in a form that can ID the data subject it should only be kept that way for however long is absolutely necessary.
-	When data is processed it should be have appropriate security measures in place against damage, loss or unauthorised/unlawful processing.