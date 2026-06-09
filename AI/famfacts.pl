% Gender Facts

male(george).
male(john).
male(sam).
male(kevin).
male(tom).

female(martha).
female(mary).
female(susan).
female(lisa).


% Parent Facts

parent(george,john).
parent(martha,john).

parent(george,susan).
parent(martha,susan).

parent(john,sam).
parent(mary,sam).

parent(john,lisa).
parent(mary,lisa).

parent(susan,kevin).

parent(lisa,tom).


% Rules

father(X,Y) :-
    male(X),
    parent(X,Y).

mother(X,Y) :-
    female(X),
    parent(X,Y).

sibling(X,Y) :-
    parent(Z,X),
    parent(Z,Y),
    X \= Y.

brother(X,Y) :-
    male(X),
    sibling(X,Y).

sister(X,Y) :-
    female(X),
    sibling(X,Y).

grandparent(X,Y) :-
    parent(X,Z),
    parent(Z,Y).

grandfather(X,Y) :-
    male(X),
    grandparent(X,Y).

grandmother(X,Y) :-
    female(X),
    grandparent(X,Y).

uncle(X,Y) :-
    brother(X,Z),
    parent(Z,Y).

aunt(X,Y) :-
    sister(X,Z),
    parent(Z,Y).

ancestor(X,Y) :-
    parent(X,Y).

ancestor(X,Y) :-
    parent(X,Z),
    ancestor(Z,Y).

#                 George ----- Martha
#                     |
#       --------------------------------
#       |                              |
#      John ----- Mary               Susan
#       |                              |
#   ----------------                 Kevin
#   |              |
#  Sam           Lisa
#                  |
#                Tom