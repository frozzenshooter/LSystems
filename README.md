# L-systems (Lindenmayer-Systems)
L-systems are a theoretical framework introduced by A. Lindenmayer. Originaly designed to study the development of multicellular organism, in computer graphics they can be used to visualize realistic plant structures and develpoment processes. In the following paragraphs a short overview is provided, a description with more details can be found in the provided pdf in the docs/ folder. 

## General idea
L-systems follow the simple concept of rewriting. Rewriting describes the process of successivly replacing parts of an inital object(string) with rewriting rules/productions.
They are apllied simultaneously and replace all elements in a given object.

The inital object is called the axiom, which will be rewritten by the predetermined productions.
Each complete rewrite is called generation with a new result object(string).

## Example

Axiom: 
* a

Productions: 
* a -> ab
* b -> a

Rewriting:
1. generation: **a**
1. generation: **ab**
1. generation: **aba**
1. generation: **abaab**
1. ...
   
## Trutle interpretation
The result of each generation can be interpreted as turtle commands. These commands can be used to generate a graphical representation of the result.
For example a F as a Non-Terminal can be used to draw a line with a predetermined lenght and width from the current position and with the current direction.

## Example symbols and their interpretation
Symbol | Interpretation
------------ | -------------
__F__ | Move forward for a length d (in the current direction) and draw a line
__f__ | Move forward for a length d without drawing a line
__+__ | Turn left by angle δ
__-__ | Turn right by angle δ

## Usage
To build the code CMake files are provided. In order to use the cmake files create a new folder "build" navigate into it and use following command (if needed with an additonal generator, e.g. XCode):
```
/build> cmake ..
```

## Further comments
All details and further references can be found in the provided documentation in the docs/ folder. 
