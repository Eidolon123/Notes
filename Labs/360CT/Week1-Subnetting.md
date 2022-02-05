 -----------------------------------------------
# Week1-Subnetting
Tags: #Lab #Uni #Networks
Creation date: 2022-01-24

-----------------------------------------------

```ad-question
title: 1 - Which class does each of the following IP addresses belong to?
```

|       IP        |   Bits   | Class |
|:---------------:|:--------:|:-----:|
|  122.10.14.100  | 01111010 |   A   |
| 100.101.110.111 | 01100100 |   A   |
|  174.12.12.174  | 10101110 |   B   |
|  230.140.30.40  | 11100110 |   D   |
|    211.1.1.1    | 11010011 |   C   |
|  180.123.12.3   | 10110100 |   B   |
|   10.11.12.13   | 00001010 |   A   |
|    240.2.4.0    | 11110000 |   E   |

---

IP: 192.168.1.0/24

![[360-subnet1.png]]

```ad-question
title: 2a - Solve this problem using normal subnet masking
```

![[360-subnet-notes.png]]

| Subnet No. | Hosts | Network Address | First Address | Last Address | Broadcast Address |   Subnet Mask   |
|:----------:| ----- |:---------------:|:-------------:|:------------:|:-----------------:|:---------------:|
|     4      | 2     |       .0        |      .1       |     .30      |        .31        | 255.255.255.224 |
|     1      | 10    |       .32       |      .33      |     .62      |        .63        | 255.255.255.224 |
|     2      | 10    |       .64       |      .65      |     .95      |        .96        | 255.255.255.224 |
|     3      | 20    |       .96       |      .97      |     .127     |       .128        | 255.255.255.224 |
|     5      | 20    |      .128       |     .129      |     .158     |       .159        | 255.255.255.224 |

```ad-question
title: 2b - Solve this problem using VLSM
```

![[360-vslm-notes.png]]

| Subnet No. | Hosts | Network Address | First Address | Last Address | Broadcast Address |   Subnet Mask   |
| ---------- |:-----:|:---------------:|:-------------:|:------------:|:-----------------:|:---------------:|
| 4          |   2   |       .0        |      .1       |      .2      |        .3         | 255.255.255.252 |
| 1          |  10   |       .16       |      .17      |     .30      |        .31        | 255.255.255.240 |
| 2          |  10   |       .32       |      .33      |     .62      |        .63        | 255.255.255.240 |
| 3          |  20   |       .64       |      .65      |     .94      |        .95        | 255.255.255.224 |
| 5          |  20   |       .96       |      .97      |     .126     |       .127        | 255.255.255.224 |

```ad-question
title: 2c - Assuming manufacturing had 120 hosts instead of 20, would it be possible to solve this problem with normal subnet masking?
```

No this problem could not be solved with normal subnet masking as there would be too few addresses for the amount of hosts.

---

```ad-question
title: 3 - Design the addressing scheme for the network shown in diagram 2 using VLSM
```

IP: 172.16.0.0/16

![[360-subnet-diag2.png]]

![[360-L1-Q3-Notes.png]]

| Subnet Number | Hosts | Network Address | First Address | Last Address | Broadcast Address |   Subnet Mask   |
|:-------------:|:-----:|:---------------:|:-------------:|:------------:|:-----------------:|:---------------:|
|       1       |   2   |       0.0       |      0.1      |     0.2      |        0.3        | 255.255.255.252 |
|       2       |   4   |       0.8       |      0.9      |     0.14     |       0.15        | 255.255.255.248 |
|       3       |  101  |      0.128      |     0.129     |    0.254     |       0.255       | 255.255.255.128 |
|       4       |  201  |       1.0       |      1.1      |    1.254     |       1.255       |  255.255.255.0  |
|       5       |  302  |       2.0       |      2.1      |    3.254     |       3.255       |  255.255.254.0  | 
