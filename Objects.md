## Objects

An object is an instance of a class, creating an object from a class is called **"instantiation"**.

The object is the actual data worked with in the program.

### Instantiating an Object

When an object is instantiated it will contain the attributes and methods [[Classes#Declaring the Class|declared in the class]].

Instantiating an object from a [[Classes|class]] is done by declaring the class name and then the name of the object to be created:
```cpp
Song back_to_black;
```

Now we have an object `back_to_black` and it will contain everything the class `Song` has set it to contain. To access the attributes and methods we use a `.` after the object name:

```cpp
back_to_black.get_title();
```
 
 This will only work if the member we try to access is [[Access Control - Code|public]], if it is [[Access Control - Code|private]] we will get an error.
 
 