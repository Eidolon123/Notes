## Declaration and Definition

To keep code clean and modular the declarations and definitions of functions are split into Multiple Files ([[Concepts#Multiple Files]]).

## Function Overloading

Functions can be named the same thing in order to take different data types as parameters. C++ will know what to do when passed the different types.

```cpp
void print_cat_ears(char let) {  std::cout << " " << let << "   " << let << " " << "\n";  std::cout << let << let << let << " " << let << let << let << "\n";} void 
```

```cpp
print_cat_ears(int num) {  std::cout << " " << num << "   " << num << " " << "\n";  std::cout << num << num << num << " " << num << num << num << "\n";}
```

The function print_cat_ears will take either int or char type, either function definition will be executed depending on the type of data passed when it is called:

```cpp
print_cat_ears('A');
```
> calls the definition with char data type

```cpp
print_cat_ears(4);
```
>calls the definition with int data type

## Function Templates

More efficient than overloading if the body of the function is the same

Because the function print_cat_ears from the overloading example has the same body in our overloading functions we can be more efficient by templating it. This happens completely in the .hpp file instead of the .cpp file.

```cpp
template<typename T>
print_cat_ears(T item) {  std::cout << " " << item << "   " << item << " " << "\n";  std::cout << item << item << item << " " << item << item << item << "\n";}
```

This function will now take any data type as long as it works with the function body, in this example a vector would not work as vectors dont work with `<<`.

Not shown in this example but the template will also work for return types.

## Inline Functions

Instead of defining a function in a **.cpp** file, if it is short and consise it can be defined **_inline_** in the **.hpp** file:

```
inline
void function_name(int param1, std::string param2){ function body }
```

## Default Arguments

If a parameter will more than likely have the same argument passed to it everytime a default value can be defined in the function declaration.

```
void function_name(int param1, std:string param2 = "string")
```

When calling this function, if only 1 value is passed as an argument `function_name(4)` the code will not throw an error and use `"string"` as the second argument. 

If the function is defined as:

```
void function_name(int param1 = 4, std:string param2)
```

The call `function_name("string")` will throw an error as it is overriding the default value of param1 with a string and param2 has no value passed to it.