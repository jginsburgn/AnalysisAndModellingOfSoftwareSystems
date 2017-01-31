# Class' "Analysis and Modelling of Software Systems" Notes
* [Professor's Cloud 9](https://ide.c9.io/ariellucien/poo2016)
* [Professor's Git Repository](https://github.com/ariellucien/AyMSS17_1)
* Own Cloud9 username: a01021617@itesm.mx or a01021617
* [Own Git Repository](https://github.com/jginsburgn/AnalysisAndModellingOfSoftwareSystems)

## 20170111
### Reference Frames or Frameworks
1. ITIL
2. COBIT
3. CMMI

### Design Patterns (programming good-practices)
1. Singleton

### Architectural (or Structural) Pattern ([Wikipedia](https://en.wikipedia.org/wiki/Architectural_pattern))
1. MVC

### Software Modelling Software (UML, CASE)
1. Rational software architect (IBM)
2. Visual Paradigm Community Edition (Open Source)
3. Draw.io
4. Lucid Charts (Google) [with Oxygen for code generation from diagrams]

## 20170118
### [Software Design Patterns](https://en.wikipedia.org/wiki/Software_design_pattern)
They can be [classified](https://en.wikipedia.org/wiki/Software_design_pattern#Classification_and_list):

1. Creation

  * Singleton: a single instance exists for the duration of the program. It is never deleted and created only once, when needed. Is this a memory leak?
  * Factory Method: encapsulate the creation of objects so that final user does not worry about intermediate operations in the creation.
  * [Prototype](https://en.wikipedia.org/wiki/Prototype_pattern): a base instance is taken as a model for creating new instances. Deep copy becomes important as well as the cloning of objects through the return value, that is not a pointer but the instance itself ([Example @ Wikipedia](https://en.wikipedia.org/wiki/Return_value_optimization#Summary)):

  
   ```c++
	PrototypedClass clone() {
	   return PrototypedClass();
	}
	```
	See also: `C++` idiom [CRTP](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) or Curiously Recurring Template Pattern.

  * Builder
  * Abstract Factory

2. Structure
3. Behavior
4. et cetera.

##20170125
###`C++` Constructors

####There are three kinds of cunstructors:

* Default: all parameters have a default value.

```C++
Base (int a = 0) {...}
```
or
```C++
Base () {...}
```

* Custom, With Parameters, or Explicit: it has at least one parameter without a default value.

```C+
Base (int a, int b = 0) : a(a) {...}
```

* Copy

```C++
Base (const Base &) {...}
```

* [Move](http://en.cppreference.com/w/cpp/language/move_constructor) `C++11`: takes an Rvalue and makes it a reference so that 

####Constructors exist in three fashions:

* Explicit
* Implicit
* Delete

####There are [types of values](http://en.cppreference.com/w/cpp/language/value_category) in the language, including:

* Lvalue: left value.
* Rvalue: right value.

####`C++` Keywords:
* [`explicit`](http://en.cppreference.com/w/cpp/language/explicit): this is to disable the possibility of implicit calling of a parameter constructor by assignation, i.e.:

```C++
//Considering the existing constructor of the Base class as follows
Base (int a) {...}

//Having the following statement is allowed
Base base = 5; //In which case the above constructor will be called with a = 5
```

With the use of the `explicit` keyword, the last statement in the last block of code would not be possible, i.e.:

```C++
//Considering the explicit specified constructor of the Base class
explicit Base (int a) {...}

//Having the following statement is not allowed
Base base = 5;
```
* [`delete`](http://en.cppreference.com/w/cpp/language/function#Deleted_functions) in the context of deleted functions, not memory allocation.
* [`default` (see = default ; syntax)](http://en.cppreference.com/w/cpp/language/function#Function_definition)

### Glossary
* Partial [virtual](http://en.cppreference.com/w/cpp/language/virtual) method: a method that has an implementation, which is generic, but is intended to be specifically implemented in child classes.
* [Pure virtual method](http://en.cppreference.com/w/cpp/language/abstract_class): a method that does not have an implementation, but is intended to be implemented in child classes. Has de following syntax:

```C++
virtual RetType methodsName() = 0;
```
* Interface \<\<interface>>: it can only have pure virtual methods and static attributes and it cannot be instantiated.
* Abstract Class \<\<abstract>>: it should at least have a pure virtual method, but it can have partial virtual methods and regular methods; however it cannot be instantiated.
* Template Class \<\<template>>: it has implementations for generic types.
