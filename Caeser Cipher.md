-----------------------------------------------
# Caeser Cipher
Tags: #Cryptography 
Creation date: 2021-11-28

-----------------------------------------------

A Caeser cipher operates by shifting the alphabet by $n$ characters. Spaces and punctuation are ignored.

If $A=0$, $B=1$, $C=2$ ... $Z=25$ then: $C=E_K(P) \mod n$

In this case $K$ is the amount of bits shifted or the letter that `a` is shifted to.

A Caeser cipher is easy to crack as there are only 25 different keys available to use.

A Caeser cipher has a [[Unicity Distance]] of ~2 characters.

## Example

$P =$ "Foo Bar"

$K =$ 5

| a   | b   | c   | d   | e   | f   | g   | h   | i   | j   | k   | l   | m   | n   | o   | p   | q   | r   | s   | t   | u   | v   | w   | x   | y   | z   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| f   | g   | h   | i   | j   | k   | l   | m   | n   | o   | p   | q   | r   | s   | t   | u   | v   | w   | x   | y   | z   | a   | b   | c   | d   | e   | 

In this table converting from the top row to bottom will encrypt a message, from the bottom row to the top will decrypt a message.

Encryption: $C=E_5(P) =$ "Ktt gfw"

Decryption: $P=E_5(C) =$ "Foo Bar"