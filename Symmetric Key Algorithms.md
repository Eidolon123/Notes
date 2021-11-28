-----------------------------------------------
# Symmetric Key Algorithms
Tags: #Cryptography 
Creation date: 2021-11-28

-----------------------------------------------


Also known as secret key algorithms.

This is where both Alice and Bob share a single key that is used to encrypt and decrypt data.

Alice encrypts some plaintext to send to bob: $C=E(P,K_X)$

Bob decrypts this cipher into plaintext so he can read it: $P=D(C,K_Y)$

In this situation $X=Y$ so there is only one key $K$.

This can be rewritten as: $C=E_K(P)$ for encryption and $P=D_K(C)$ for decryption. This means that $D_K(E_K(P)) = P$.