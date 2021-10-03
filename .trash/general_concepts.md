## Arguments

## Multiple Files

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

[[Header Files]]

[[Object Oriented Programming]]

## Memory Addresses

[[references]] [[pointers]]
