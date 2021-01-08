# BoostedCpp
A variation of C++ algorithms that deal with templating, HPC, Cython, Boost, etc.

### Terminal Style C++
Since certain IDEs are either costly or just overly difficult to get set up (i.e. including boost libraries) so I wanted to go back to basics and build c++ .exe files in the terminal.

#### Creating a New C++ File
Simplist way to create and open notepad for editing is:
```bash
notepad main.cpp
```
This should automatically create the file and open Notepad so you can edit the file.

Once you have a simple block of code, like:
```python
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	return 0;
}
```
You can run:
```bash
g++ -std=c++17 main.cpp -o main
```
This will create an .exe file that was complied with C++17, of which you can then just call:
```bash
main.exe
```
To run the file.

### Adding Boost to Visual Studio
<ol>
	<li>Download Boost from the main site (place in a preferred space i.e. C:/boost/)</li>
	<li>Within the terminal, move to boost folder and run bootstrap.bat (wait for a bit while it compiles everything)</li>
	<li>Add boost directory to libraries to include for C/C++ (within the property manager dialog tab)</li>
	<li>Add boost/stage/lib directory to linked library</li>
</ol>

### Templates
A personal favorite. With templating you don't have to be specific on what the args / return type should be. Within the given template file, there is also this new feature (new for C++11) of folding where you don't have to specify args, they are just unfolded and treated seperately. Its specific name is "Variadic Template Expansion" ([Templates](https://github.com/MckinstryJ/CppVarites/blob/main/C%2B%2B/templating.cpp))

### Pointers
Pointers provide links to a variable's memory address. They provide various benefits one of which is the ability to reduce
memory usage by changing a variable's value via reference and not by the default create copy change copy and return copy.
The current biggest question I have:
<ul>
  <li> Whats the purpose of a double pointer? </li>
</ul>

REF: </br>
[Tutorials Point](https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm)
</br>
File: </br>
[Pointers](https://github.com/MckinstryJ/CppVarites/blob/main/C%2B%2B/pointers.cpp)

### Iterators
Iterators are similar to pointers where each address of a container is held and used as a memory reference.

#### Random-Access Iterators
There are considered as the strongest of all iterator types. Their features include:
<ol>
  <li>Usability: can be used in multi-pass algorithms</li>
  <li>Equality: can be compared for equality with another iterator (A == B)</li>
  <li>Dereferencing: can assign values as well as access them</li>
  <li>Incrementable: iter++ or ++iter</li>
  <li>Relational: can compare iter1 > iter2</li>
  <li>Arithmetic: iter + 1</li>
  <li>Offset: iter[3] (indexing) is allowed</li>
  <li>Swappable: values can be swapped</li>
</ol>

There are other iterators (input, output, forward, bidirectional and random access) and they each have their own ability (reads foward, writes forward, reads/writes forward, reads/writes forward/backward and reads/writes with random access) respectfully but they don't have much more to them besides that.

### Hash maps
A map is similar to that of a dictionary in Python. There is a (key, value) pair for every entry. One can find the value for a given pair with .find() but can also access it via \[] operator. An extension of a a typical map is a hash map. This variation passes the key through a hash function (i.e. mod(key) if the key is an int) and that value is the new key. The point of doing this allows the structure to minimize the search complexity since one would only need to search through the hash key list instead of the entire list.

### Classes
Linking a class to main.cpp is very difficult. So, instead of spending hours figuring that out I just made it easy by building a project in Code::Blocks. Noting the basics to advanced here. A class can hold functions and variables. Its needed to create an object. This object has attributes (variables) and has a certain behavior (function).
<br><br>
"public" information is anything that can be viewed by anyone.
"private" information is hidden and can only be used by the class itself or by other means (more on that later).
"protected" information is anything that can only be viewed privately or from another class that inherted it.
#### Inheritance
As an example, the base class is a Cat but it has inherited the Animal class that is common among all animal objects. The code
highlights what is needed to inhert the constructor of the Animal class.

#### Polymorphism
Overriding a function in an inherted class doesn't work with C++. The power of polymorphism only works with the base class.
Which is within the same Cat / Animal example.

For Visual Studio its slightly different than CodeBlocks. For example, within the implementation file you must
state:
``` python
this->desc = desc
```
... to assign a value to the class variable. In CodeBlocks you could just do:
``` python
desc = desc
```
...and it would be just fine. I personally like VS approach since 'this' makes it clear on where its being
assigned.

### Branches
Branching allows the program to perform an abnormal behavior. They include the following:
<ul>
  <li>break - forces the loop to stop</li>
  <li>goto - forces the code to skip to a defined place in the code</li>
  <li>continue - stops this iteration and moves to the next</li>
  <li>exit - forces the program to stop</li>
  <li>return - causes the function to go to the previous function that called it</li>
</ul>

### Multithreading
The multithreading namespace I created focused on how to get it set up within visual studio.
Using this tutorial: https://youtu.be/IdwJdJw65tU?t=811

The following topics were covered:
<ol>
	<li>Threads with isolated memory</li>
	<li>Threads with global variables (not a big difference)</li>
	<li>...</li>
</ol>

### Pipelining
...

### Predication
...

### Instruction Scheduling
...

### Redorder Buffer
...

### Memory Reordering
...

### Instruction level parallelism
...

### VLIW compilers
...

### Memory
...

### Storage
...

### Fault Tolerance
...

### Multiprocessing
...

### Synchronization
...

### Memory Consistency
...

### Memory Allocation
...

### GPU Programming
...

### Cython / Numba
...

### Tutorial
Holds various topics in common tutorials about C++
