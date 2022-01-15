-----------------------------------------------
# Access Control - Code
Tags:  #Coding
Creation date: 2021-10-04

-----------------------------------------------

By default, everything in a [[Classes|class]] is **private**, meaning [[Classes|class]] members are limited to the [[Scope (Coding)]] of the class. This makes it easier to keep data from mistakenly being altered. If you try to access a private class member, you’ll get an error:

```error
error: 'population' is a private member of 'City'
```

But sometimes you need access to class members, and for that, there is `public`. You can use it to make everything below accessible outside the class:

```cpp
class City {

	int population;  
	
public: // stuff below is public  
	void add_resident(); 
};
```

In this example `population` is still private and not accessible but the [[Functions|funciton]] `add_resident()` is accessible outside the class.