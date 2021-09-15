## information_security

### CIA_triage

Not the CIA (American spy agency), abbreviation of the three main factors of information security.

![[cia_triad.png]]

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



## computer_misuse_act



## general_data_protection_regulation



## other

