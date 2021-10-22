-----------------------------------------------
# Data Types
Tags:  #Coding 
Creation date: 2021-10-06

-----------------------------------------------

## Overview

- Integer
- String
- Vector
- List
- Dictionary

A type can be seen as a restriction on the range of values which can be assumed by a [[Variables|variable]]. For example, if a [[Variables|variable]] is of type 'int' it is restricted to only integer values between 0-infinity. 'bool' is restricted to 1 or 0, true or false.

The correct use of data types can protect against some logic and runtime [[Errors|errors]].

## Typed vs untyped languages

| Untyped                                                                                                | Typed                                               |
| ------------------------------------------------------------------------------------------------------ | --------------------------------------------------- |
| No restriction on values given for [[Variables]]                                                       | [[Variables]] can be constrained by type assignment |
| Operations potentially applied to inappropriate arguments, behaviour can be unpredictable or undefined | Types might or might not appear in the program      |
| PHP, Perl                                                                                              | C, Java, Python                                     |


## Complex type mapping (PHP)

Must rely on strong input validation, can lead to injection etc if validation not good enough.