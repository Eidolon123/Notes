-----------------------------------------------
# Cryptography
Tags: #Cryptography
Creation date: 2021-11-28

-----------------------------------------------

Cryptography is the study of [[encryption]] principals and methods. The concepts will be used in an [[Information Theory]] context.

## Terms

### Alice

Alice is the 1st communicating party 

### Bob

Bob is the 2nd communicating party

### Charlie/Eve

Charlie or eve are the attackers or intruders that tries to know what is being exchanged.

### Plaintext $P$

Text readable by humans, unmodified

### Ciphertext $C$

Text or message that has been enciphered/encrypted.

### Cipher

A cipher is the [[encryption]] algorithm, transforming plaintext to cipher text.

[[Block Cipher]]

[[Stream Cipher]]

### Key $K$

A parameter used in the encryption algorithm.

### Kerckhoff's principle

Kerckhoff's principle is that the Key $K$ is secret while the algorithm is public. 

### Encipher/Encrypt $E$

Convert $P$ to $C$ through some method $E$.

$C=E(P,K_X)$

### Decipher/Decrypt $D$

Convert $C$ to plaintext $P$ through some method $D$.

$P=D(C,K_Y)$

### Intruders

#### Passive

Intruders that only listen to communications.

#### Active

Intruders that listen to communications and modify them.

### Cryptanalysis

The study of principles and methods of deciphering $C$ without knowing $K$. This could also include working out what $K$ is.

### Cryptology

The field containing both cryptography and cryptanalysis.

### Substitution

Using a predefined set of rules to replace characters in a piece of text with alternative characters.

### Transposition

Rearranging characters in a piece of text using a predefined set of rules.

### Compression

### Expansion

### Padding

