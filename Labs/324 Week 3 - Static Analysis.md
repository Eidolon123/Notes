-----------------------------------------------
# 324 Week 3 - Static Analysis
Tags:  #TODO #Coding #Lab 
Creation date: 2021-10-07

-----------------------------------------------


## Lab 1

```c
main(void) {
	int i;   
	for (i = 0; i < 10l; i++) {
	printf("%d\n",i);    
	}
}
```

```ad-question
title: What does this report tell us?
```
This code is designed to print out the numbers 0-9 in order to the terminal. 

![[324-week3-lab1.png]]

```ad-question
title: What does this report tell us?
```

Incorrect types for operand of `<` (int, long int)

incorrect use of `main(void)`, should be `void main()`

