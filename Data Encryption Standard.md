-----------------------------------------------
# Data Encryption Standard (DES)
Tags: #Cryptography 
Creation date: 2021-11-28

-----------------------------------------------

DES uses some standard, for example ASCII binary standard, to convert $P$ into binary code.

This binary code is then split into 64bit blocks which produced 64 bits of $C$ when ran through the algorithm.

$K$ is initially 64bits long but every 8th bit is discarded resulting in a 56bit key used in the algorithm.

## How it works

The algorithm involves 19 stages.

### Stage 1

Initial transposition of the 64bit block of $P$. This is where we perform transposition by moving the bits around in the following way, where each number represents the bit at that position in the original 64bit block.

|     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 58  | 50  | 42  | 34  | 26  | 18  | 10  | 2   |
| 60  | 52  | 44  | 36  | 28  | 20  | 12  | 4   |
| 62  | 54  | 46  | 38  | 30  | 22  | 14  | 6   |
| 64  | 56  | 48  | 40  | 32  | 24  | 16  | 8   |
| 57  | 49  | 41  | 33  | 25  | 17  | 9   | 1   |
| 59  | 51  | 43  | 35  | 27  | 19  | 11  | 3   |
| 61  | 53  | 45  | 37  | 29  | 21  | 13  | 5   |
| 63  | 55  | 47  | 39  | 31  | 22  | 15  | 7   | 

### Stage 2-17

$P_t$ is then split into two 32bit blocks $L_0$ and $R_0$.

$R_1 = L_0 \oplus R_0$

$L_1 = R_0$

This is then repeated until you have $L_{15}$ and $R_{15}$

### Stage 18

$R_{16}$ = 