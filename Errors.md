-----------------------------------------------
# Errors
Tags:  #Coding #Security
Creation date: 2021-10-04

-----------------------------------------------

- syntax error
	- not a security issue
- runtime error
	- can be a security issue
	- for example if code controls something in chemical plant, runtime error could result in pressure/temperature/explosion. runtime error could be fault of programmer or from injection from malicious actor.
- logic error
	- can be a security issue
	- most difficult to detect as the program will compile without error.

## Trapped

Trapped errors are for well defined behaviour such as a *divide by zero* error. These are safe as we can trap them and handle them in code.

## Untrapped

Untrapped errors lead to control of the program moving away from the code. Errors such as out of bounds errors can lead to [[Buffer Overflow]] attacks.

If a program does not cause untrapped errors, it is called **safe**.

A language where all the programs are **safe**, is called a **[[Safe Language]]**.
