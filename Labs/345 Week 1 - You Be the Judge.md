-----------------------------------------------
# 345 Week 1 - You Be the Judge
Tags:  #Legal #Uni #Lab 
Creation date: 2021-10-07

-----------------------------------------------

```ad-question
title: Case 1
You are conducting a black-box penetration test. Due to miscommunication (eg wrong network, IP), you attack and compromise the wrong computer. You did intend to attack a computer, but you attacked one which you weren’t authorised to attack.

Are you Guilty or Not guilty?
```

Under the computer misuse act unauthorised access section, the prosecution in this case would have to prove the defendant was aware that they were not authorised. As this was a result of a miscommunication, the pentester would be under the impression that they were completely authorised to attack the machine that they attacked. As long as the pentester stayed within the scope laid out for the original machine they would not be guilty of any offense. As a note it does fall to the pentester to make sure they are attacking the correct machines and a case could be made for negligence for not properly verifying the information given in the contract. In this case I believe the liability fall to whoever supplied to wrong addresses for the pentester.

**Not Guilty**

---

```ad-question
title: Case 2
You break the encryption of a wireless network that you believed to belong to the client but actually belongs to its neighbour. Are you guilty of committing a crime?

Are you Guilty or Not guilty?
```

In this case it falls to the pentester to check and recheck the systems they are attacking belong to the client and fall in the given scope. As in any pentest a signed document with IP ranges, addresses, machine names, etc. should have been given to the pentester before beginning the pentest. As the wireless network that was compromised would not have featured on this document there is no way to prove that the pentester thought they were authorised and they would be prosecuted depending what they did after the compromise under the CMA for unauthorised access and possibly even the human rights act if any sensitive data was found due to the compromise.

**Guilty**

---

```ad-question
title: Case 3
You received written permission allowing you to perform a penetration test from someone who believed they were authorised to give permission but who actually wasn’t. Who is guilty?

- Them (the employee)
- You (the pentester)
- Both
- Nobody

```

**TODO**

---

```ad-question
title: Case 4
You have discovered a new vulnerability of a popular app or OS. Should you disclose it to the public so that system administrators or developers can check whether they are vulnerable?

Yes or No?

```

The vulnerability should be made known to the developers first to give them a chance to make a hotfix and publish it before it becomes common knowledge. This is to avoid bad actors taking advantage and exploiting the vulnerability for personal/criminal enterprises. If after a certain period of time the developers do not respond or seem unwilling to except the information being provided to them, the vulnerability should be made public to *'force their hand'*.

---

```ad-question
title: Case 5
You have developed a new hacking algorithm/tool. It can be used by anyone with relevant skills to compromise computer systems. Should you publish it?

Yes or No?
```

Yes the algorithm or tool could be published without legal recourse on the publisher as long as the correct legal disclaimers are written to accompany the tool. For example the tool `hydra` comes with this legal disclaimer: `Please do not use in military or secret service organizations, or for illegal purposes`.