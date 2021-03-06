% Author: Tanvir Hasan0
% Date: 22/11/2015

parent(abraham, john).
parent(abraham, sarah).
parent(abraham, jackson).
parent(john, farzana).
parent(jackson,williams).
parent(jackson,harry).
parent(sarah,tina).
parent(farzana,rose).

male(abraham).
male(john).
male(jackson).
male(john).
male(jackson).
male(williams).
male(harry).
female(sarah).
female(tina).
female(rose).
female(farzana).

father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).
son(X, Y) :- parent(Y, X), male(X).
daughter(X, Y) :- parent(Y, X), female(X).
sibling(X, Y) :- parent(Z, X), parent(Z, Y).
brother(X, Y) :- sibling(X, Y), male(X).
sister(X, Y) :- sibling(X, Y), female(X).
cousin(X, Y) :- father(P,X),father(Q,Y),brother(P,Q).
uncle(X,Y) :- brother(X,Z),father(Z,Y).
aunt(X,Y) :- sister(X,Z),mother(Z,Y).
nephew(X,Y):- father(Z,Y),brother(Z,X).
niece(X,Y) :- mother(Z,Y),sister(Z,X).
grandfather(X,Y) :- father(Z,Y),father(X,Z).


input(X,Y):-
    write('Enter Your First Name: '), nl,
    read(X),
    write('Enter Your Second Name: '), nl,
    read(Y),
    ( father(X,Y) ->
      write(X),write(" is  father of "),writeln(Y)
      ; mother(X,Y) ->
      write(X),write(" is  mother of "),writeln(Y)
      ; son(X,Y) ->
      write(Y),write(" is  son of "),writeln(X)
      ; daughter(X, Y) ->
      write(Y),write(" is  daughter of "),writeln(X)
      ; sibling(X, Y) ->
      write(X),write(" is  sibling of "),writeln(Y)
      ; brother(X, Y) ->
      write(X),write(" is  brother of "),writeln(Y)
      ; sister(X, Y) ->
      write(X),write(" is  Sister of "),writeln(Y)
      ; cousin(X, Y) ->
      write(X),write(" is  cousine of "),writeln(Y)
      ; uncle(X,Y) ->
      write(X),write(" is  uncle of "),writeln(Y)
      ; aunt(X,Y) ->
      write(X),write(" is  aunt of "),writeln(Y)
      ; nephew(X,Y) ->
      write(Y),write(" is  nephew of "),writeln(X)
      ; niece(X,Y) ->
      write(Y),write(" is  niece of "),writeln(X)
      ; grandfather(X,Y) ->
      write(X),write(" is  grandfather of "),writeln(Y)
      
    ).
