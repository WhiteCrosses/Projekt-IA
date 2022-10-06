# Concept
Tower defence based game with ASCII artstyle.

# Table of Contents
1. [Desired mechanics](#Desired-mechanics:)
2. [Technology](#Technology)
3. [Cards](#Cards)
4. [Graphical style](#graphical-style)
5. [Design patterns](#design-patterns)

## Desired mechanics:
1. Touhou - inspired playstyle.
2. Randomness - best achieved by system of cards that player chooses. Their effect would stack creating (possibly) interesting combos.
3. Very rapid flow of the game. A lot happening on the screen. Little time to act when e.g. choosing card or making other decisions.
## Technology
>SDL2
>C++
## Cards
Each card would have one positive and one negative effect (possibly random generation of cards?).

Card choosing menu would appear often, making player change playstyle flexibly.
## Graphical style
SDL2 generated graphics that should represent terminal-based apps. SDL2 allows to make sprites move in distance smaller than one terminal cell, rotate them, change sizes and overlay.
## Design patterns
1. [Flyweight (Pyłek)](#https://refactoring.guru/pl/design-patterns/flyweight)
2. ...