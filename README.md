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
4. ASCII based artstyle - Make game feel, like it was made in the terminal (ncurses?).
5. Scalability - Possible more than one player. Either conected via LAN (?) or on local machine.
## Technology
>SDL2
>C++
## Cards
Each card would have one positive and one negative effect (possibly random generation of cards?).

Positive effects:
1. Increase base armor
2. Gain n% life steal
3. Gain n armor penetration
4. Turrets shoot double bullets
5. Bullets shatter to smaller parts on hit
6. Bullets set enemies in flames
7. Bullets freeze enemies

Negative effects:
1. Enemies increased health
2. Enemies increased armor
3. Enemies increased speed
4. Less base armor
5. Turrets less accurate(???)

Card choosing menu would appear often, making player change playstyle flexibly.
Cards effects overlap creating unique cobos. This also affects enemy units, as negative effects can cause them to be really powerful.
## Graphical style
SDL2 generated graphics that should represent terminal-based apps. SDL2 allows to make sprites move in distance smaller than one terminal cell, rotate them, change sizes and overlap on each other.
## Design patterns
1. [Flyweight (Pyłek)](#https://refactoring.guru/pl/design-patterns/flyweight)
2. ...

## UML Class diagram
![UML Class Diagram image](/assets/UML_Diagram_sketch.png)
