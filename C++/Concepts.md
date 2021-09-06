## Arguments

## Scope

The scope is the region of code that can access an element.

- Global elements can be accessed  everywhere.
- Elements created inside a function have local scope and can only be accessed inside that function. 

## Multiple Files

C++ functions are usually split to make code more modular:

-   The declaration in a **.hpp** header file.
-   The definition in another **.cpp** file.

Need to link files together at compile time if there are multiple

```
g++ file1.cpp file2.cpp -o output_file 
```

**.hpp** files should be included in the head of the main **.cpp** file with:

```
#include "file.hpp"
```

## Object oriented programming

Allows users to create custom data types to represent more and more complex data.

A [[Class]] defines what the [[Object]] will contain and look like.
