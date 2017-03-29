# Class's "Analysis and Modelling of Software Systems" Notes
* [Professor's Cloud 9](https://ide.c9.io/ariellucien/fp2016)
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
2. Factory Method
3. Prototype
4. Proxy
5. Visitor

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

  *  [Proxy](https://en.wikipedia.org/wiki/Proxy_pattern)

3. Behavior

	* Visitor Pattern: This pattern is employed to extend extant classes (called `Elements`) by extracting the algorithm to add, and placing it into a `Visitor`. An `Element` implements an `accept` method which calls a `visit` method of the `Visitor`, with itself as the only argument. Therefore, method dispatching depends on both the `Visitor` and the `Element` used; this is called double dispatching. At a contrast, one would need to change the signature of the `accept` method, by changing its argument type, for every kind of visitor, not allowing the use of polymorphism. (See also [Wikipedia](https://en.wikipedia.org/wiki/Visitor_pattern#Details))

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

## 20170215

### [Software Development Methodologies](https://en.wikipedia.org/wiki/List_of_software_development_philosophies#Software_development_methodology) [See also](https://en.wikipedia.org/wiki/Software_development_process#Approaches)

There are several categories of software development methodologies; some follow:

#### Traditional

Some specific methodologies in this category include:

* Protoype
* Iterative

The sequence of steps are usually:

* Analysis
* Design
* Coding
* Implementation
* Testing

#### Object Oriented

* RUP

#### Agile

Some specific methodologies include:

* Pair Programming
* SCRUM

Some characteristics include:

* Short periods

### UML
* A **Case Use Diagram** only describes components that interact with the user. For example, DB should never appear in a use case diagram, as it never interacts directly with the user. Therefore only human-machine interactions are documented here.

* ```<<includes>>``` Denotes an obligatory step in a Case Use Diagram.
* ```<<extends>>``` Denotes an optional step in a Case Use Diagram.
* ```<<stereotype>>``` Allows the extension of UML by adding a new constraint in relationships.

## Glossary
* Partial [virtual](http://en.cppreference.com/w/cpp/language/virtual) method: a method that has an implementation, which is generic, but is intended to be specifically implemented in child classes.
* [Pure virtual method](http://en.cppreference.com/w/cpp/language/abstract_class): a method that does not have an implementation, but is intended to be implemented in child classes. Has de following syntax:

```C++
virtual RetType methodsName() = 0;
```
* Interface \<\<interface>>: it can only have pure virtual methods and static attributes and it cannot be instantiated.
* Abstract Class \<\<abstract>>: it should at least have a pure virtual method, but it can have partial virtual methods and regular methods; however it cannot be instantiated.
* Template Class \<\<template>>: it has implementations for generic types.
