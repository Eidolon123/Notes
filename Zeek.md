-----------------------------------------------
# Zeek
Tags:  #Security #IDS
Creation date: 2021-11-03

-----------------------------------------------

Uses signatures and behavioural analysis. Can load [[Snort]] signature rules.

Can extract and store payloads for evidence.

Runs one event engine per protocol per datastream, as soon as a new session is detected it will start analysing it.

Has a policy script interpreter, allowing the company to write their security policies in script form for Zeek to implement.