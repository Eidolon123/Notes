## Create a Reference

Creating a reference to a [[Variables|variable]] essentially creates an alias to it, it is like creating a copy but if something is done to the reference it is also done to the original. These aliases cannot be changed later on to reference anything else.

Example of a reference creation:

```cpp
int five = 5; // Normal int variable

int &cinq = five;
```

Now if an action is performed on `cinq` it will also affect the variable `five`.

## Pass-by-reference
 Passing by reference is when parameters are passed to a [[Functions|function]] as references instead of the original variable (This is known as pass-by-value).
 
 This is done when we want to modify the value of the argument passed to the function. It also avoids the performance cost of creating copies of [[Variables]] or [[Objects]] for this purpose.
 
 Example code:
 
 ```cpp
 void swap(int &i, int &x){
 	int temp = i;
	i = x;
	x = temp;
 }
 
 int main(){
 	int a = 100;
	int b = 200;
	
	swap(a,b);
	
	std::cout << a << "\n";
	std::cout << b;
 }
 ```

Output:

```
200
100
```

Output without using references:

```
100
200
```

### Const

The `const` keyword tells the compiler that we wont be changing the data it is assigned to.

Example code:

```cpp
int timesTwo(int const &i){
	return i*2;
}
```

In the above function we are not modifying `i`, just returning its value * 2. If the value of `i` were to change inside the function the compiler will throw an error.

Example code that would throw an error:

```cpp
void timesTwo(int const &i){
    i += i;
}
```

Error on compile:

```error
error: assignment of read-only reference ‘i’
	i += i;
```

## Memory Addresses

The `&` operator is used to create a reference but can also be used to get the address of an object.

Example code:

```cpp
int box_count = 3;
std::cout << &box_count << "\n";
```

Output:

```cpp
0x7ffd7caa5b54
```
>This is the hexadecimal memory address of the variable `box_count`.

