-----------------------------------------------
# Hashcat
Tags:  #Cheatsheet #Hacking #Tools
Creation date: 2021-10-04

-----------------------------------------------

### Identify Hash

```hash-identifier <hash>```

### Common hash types

```text
900   | MD4                                              | Raw Hash
0     | MD5                                              | Raw Hash
100   | SHA1                                             | Raw Hash
1300  | SHA2-224                                         | Raw Hash
1400  | SHA2-256                                         | Raw Hash
10800 | SHA2-384                                         | Raw Hash
1700  | SHA2-512                                         | Raw Hash
17300 | SHA3-224                                         | Raw Hash
17400 | SHA3-256                                         | Raw Hash
17500 | SHA3-384                                         | Raw Hash
17600 | SHA3-512                                         | Raw Hash
6000  | RIPEMD-160                                       | Raw Hash
600   | BLAKE2b-512                                      | Raw Hash
11700 | GOST R 34.11-2012 (Streebog) 256-bit, big-endian | Raw Hash
11800 | GOST R 34.11-2012 (Streebog) 512-bit, big-endian | Raw Hash
6900  | GOST R 34.11-94                                  | Raw Hash
5100  | Half MD5                                         | Raw Hash
18700 | Java Object hashCode()                           | Raw Hash
17700 | Keccak-224                                       | Raw Hash
17800 | Keccak-256                                       | Raw Hash
17900 | Keccak-384                                       | Raw Hash
18000 | Keccak-512                                       | Raw Hash
21400 | sha256(sha256_bin($pass))                        | Raw Hash
6100  | Whirlpool                                        | Raw Hash
10100 | SipHash                                          | Raw Hash
21000 | BitShares v0.x - sha512(sha512_bin(pass))        | Raw Hash
```

### Crack MD5 hash with rockyou

```hashcat -a 0 -m 0 <hash/hashfile> /usr/share/wordlists/rockyou.txt --show```