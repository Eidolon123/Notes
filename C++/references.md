## create_a_reference

Creating a reference to a variable essentially creates an alias to it, it is like creating a copy but if something is done to the reference it is also done to the original. These aliases cannot be changed later on to reference anything else.

Example of a reference creation:

```cpp
int five = 5; // Normal int variable

int &cinq = five;
```

Now if an action is performed on `&cinq` it will also affect the variable `five`.

## pass_by_reference
 Passing by reference is when parameters are passed to a function as references instead of the original variable.
 
 This is done when we want to modify the value of the argument passed to the function. It also avoids the performance cost of creating copies of variables or objects for this purpose.
 
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



## memory_addresses
