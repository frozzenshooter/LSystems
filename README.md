# LSystems (Lindenmayer-Systems)
L-systemas are a theoretical framework introduced by Lindenmayer. Originaly designed to study the development of multicellular organism, in computer graphics they can be used to visualize realistic plant structures and develpoment processes.

## General idea
L-systems follow the simple concept of rewriting. Rewriting describes the process of successivly replacing parts of an inital object(string) with rewriting rules/productions.
On the contrary to context-free Chomsky grammars L-systems doesn't apply productionrules sequentially. They apply it in a simulataneously way and replace all letters in a given word at once.

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

TODO: BETTER ADDITIONS

The result of each generation can be interpreted as geometric commands. These commands can be used to generate a graphical representation of the result string.
Each (Non-)Terminal of the result can represent an action like draw a line or change change rotation.

For example a F as a Non-Terminal can be used to draw a line with a predetermined lenght and width from the current position and with the current direction.

## Example symbols and their interpretation
Symbol | Interpretation
------------ | -------------
__F__ | Move forward for a length d (in the current direction) and draw a line
__f__ | Move forward for a length d without drawing a line
__+__ | Turn left by angle δ
__-__ | Turn right by angle δ

## Usage

## Further comments
