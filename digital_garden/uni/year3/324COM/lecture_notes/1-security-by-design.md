## Objectives

be able to look at different examples of code and understand what is happening.

## Secure Programming vs Programming For Security

Secure programming involves fixing exploitable errors in code.

programming for security involves incorporating security features such as:

-	Cryptography
-	Password management

Incorporating these features does not guarantee security.

### What Does Guarantee Security?

Nothing really can guarantee security. Secure and defensive programming can just help to increase the security of the system.

## Defensive Programming

A strategy to address logic and runtime bugs or errors. This does not make it a byproduct of secure programming. It helps but is not its primary objective.

-	syntax error
	-	not a security issue
-	runtime error
	-	can be a security issue
	-	for example if code controls something in chemical plant, runtime error could result in pressure/temperature/explosion. runtime error could be fault of programmer or from injection from malicious actor.
-	logic error
	-	can be a security issue
	-	most difficult to detect
