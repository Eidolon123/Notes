Allows users to create custom data types to represent more and more complex data.

## Class

A class is a blueprint of a data type, what it looks like and what its made up of in terms of attributes ([[Variables]]) and methods ([[Functions]]).

-	Attribute: also known as **_member data_**, consist of information about an instance of the class.

-	Method: also known as **_member functions_**, are functions that you can use with an instance of the class. We use a `.` before method names to distinguish them from regular functions. For example: `my_object.memberFunction()`. In this case an object has been instantiated from a class that has the function `memberFunction()` associated with it.

### Declaring the class
All classes are declared in the header file ([[Concepts#Multiple Files#Header Files]]). 

An example class declaration for a 'Song' data type:
```cpp
// This would be declared in a .hpp file.
class Song{
	
	// Attributes
	std::string artist;
	std::string title;
	int records_sold;
	
	public:
		
		// Methods
		std::string get_artist();
		std::string get_title();
		void add_records_sold(int sold);
		int get_records_sold();
};
```

In terms of scope ([[Concepts#Scope]]) everything in a class is private unless it is under a `public:` tag. This helps to ensure data is less likely to be accidentally changed. 

### Defining class methods
Having the attributes of a class be private is why there are methods ([[Functions]]) associated with the class called "get_artist", "get_title" and "get_records_sold" these methods will only be able to read the data stored in the objects attributes not write to them, avoiding accidental bugs.  For example:

```cpp
// This is the definition inside the .cpp file.
std::string Song::get_artist(){
	return artist;
}
```

Notice when defining a method associated with class the class must be tagged onto the begging of the definition.

### Constructor

A method ([[Functions]]) used to initialise an object with values in parameters. The constructor will have the same name as the class and will have no return type.
Just like any other method it should be declared in the header file and defined in a **.cpp** file.

Taking the above 'Song' class as an example but with the constructor declared in the public space:
```cpp
// This would be declared in a .hpp file.
class Song{
	
	// Attributes
	std::string artist;
	std::string title;
	int records_sold;
	
	public:
		
		// Constructor declaration
		
		Song(std::string new_title, std::string new_artist);
		
		// Methods
		std::string get_artist();
		std::string get_title();
		void add_records_sold(int sold);
		int get_records_sold();
};
```

In the above example the constructor `Song(std::string new_title, std::string new_artist);` is declared so that when a new Song object is instantiated from the Song class it should have a title and artist from creation.

The definition of the constructor would be as follows:

```cpp
// Inside a .cpp file
Song::Song(std::string new_title, std::string new_artist){
	:	title(new_title), artist(new_artist) {}
}
```

Now when an object is instantiated the title and artist must be provided for example:

```cpp
Song back_to_black("Back to Black", "Amy Winehouse");
```
The song object back_to_black has now been instantiated with the correct values for title and artist.
### Destructor

A destructor allows you to execute any cleanup necessary before an object gets destroyed.

Declared and defined the same as a [[#Constructor]] but

## Object

an instance of a [[#Class]], creating an object from a class is called **"instantiation"**

a student object would be an instance of the student class.

the object is the actual data worked with in the program.

Can create as many objects from the class definition as you want to track them within the program. 

