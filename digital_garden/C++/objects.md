## objects

An object is an instance of a class ([[classes]]), creating an object from a class is called **"instantiation"**.

The object is the actual data worked with in the program.

### instantiating_an_object

When an object is instantiated it will contain the attributes and methods declared in the class. ([[classes#declaring_the_class]])

Instantiating an object from a class is done by declaring the class name and then the name of the object to be created:
```cpp
Song back_to_black;
```

Now we have an object `back_to_black` and it will contain everything the class `Song` has set it to contain. To access the attributes and methods we use a `.` after the object name:

```cpp
back_to_black.get_title();
```
 
 This will only work if the member we try to access is public, if it is private we will get an error. ([[general_concepts#Scope#Access Control]]).
 
 