-----------------------------------------------
# Static Code Analysis
Tags: #Coding #Security #Uni   
Creation date: 2021-10-22

-----------------------------------------------

Static code analysis is where we examine code without executing it to try and discover security vulnerabilities.

Static code analysis is what is called a 'computationally intractable' problem. The only way to 100% know what code does is to run it and find out. That counters that static part of our objective. Also if the code that is run never stops we will never find out what it does.

Ultimately this means that we will never be able to determine [[Non-trivial]] properties of code with static analysis.

We have to accept that static code analysis cannot possibly find every programming issue.

## Example

```
bother(function f){
	if(is_safe(f)){
		call unsafe();
	}
}

b = bother;
bother(b);
```

![[324 diagram.png]]


