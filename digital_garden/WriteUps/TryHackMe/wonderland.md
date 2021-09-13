## recon

### directory scanning

#### Source code > ssh pass for alice

## Alice > Rabbit

### Can run python3.6 as rabbit (sudo -u rabbit python3.6 \<python file> )

### Create random.py to throw shell as rabbit to listener.

## Rabbit > Hatter

### teaParty uses date module and has 'hatter' suid bit set

#### Create new date module ("bin/bash") in tmp, add to path to get shell as hatter

##### SHH in as hatter for better shell

## Hatter > Root

### Run linpeas on target machine, shows pearl as able to set SUID bit

#### GTFO bins for pearl, use cap_set payload 

##### read root.txt in /home/alice/ and user.txt in /home/root/ (everything is upside down here)