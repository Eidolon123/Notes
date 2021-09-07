## arguments

## scope

The scope is the region of code that can access an element.

- Global elements can be accessed  everywhere.
- Elements created inside a function have local scope and can only be accessed inside that function. 

### access_control

By default, everything in a class is **private**, meaning class members are limited to the scope of the class. This makes it easier to keep data from mistakenly being altered. If you try to access a private class member, you’ll get an error:

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

## multiple_files

C++ functions are usually split to make code more modular:

-   The declaration in a **.h** header file.
-   The definition in another **.cpp** file.

Need to link files together at compile time if there are multiple

```
g++ file1.cpp file2.cpp -o output_file 
```

**.h** files should be included in the head of the main **.cpp** file with:

```
#include "file.h"
```

### header_files

Used to declare items such as functions ([[functions]]) and classes ([[classes]])


## object_oriented_programming

This concept makes use of [[classes]] and [[objects]] to allow the user to represent complex data types and use them in programs. This is kind of the whole point of C++ over C.