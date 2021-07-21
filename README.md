# SENG1120 - Data Structures
## Assignment 2
### Task
Using the Linked List developed in assignment 1, adapt it to be a template and store Card objects instead of strings. Wrap it in a custom Queue data structure and then further wrap it in both a HandOfCards and DeckOfCards, which will together interface with a premade demo file to play the casino game Blackjack.

DeckOfCards should have functionality to generate a deck from scratch and shuffle it using the C++ `rand` library. HandOfCards, DeckOfCards and Card should all make use of overloaded output operators to allow for ordered and well formatted output.

### Compile
`make clean && make`

### Run
`./assignment2`
