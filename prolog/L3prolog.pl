mot(article,un).
mot(article,chaque).
mot(nom,criminel).
mot(nom,'big kahuna burger').
mot(verbe,manage).
mot(verbe,aime).

phrase(Mot1,Mot2,Mot3,Mot4,Mot5 ):-
mot(article,Mot1),mot(nom,Mot2),mot(verbe,Mot3),mot(article,Mot4),mot(nom,Mot5).

genN(1,[]).
genN(N,R) :-
    N > 1,
    N1 is N-1,
    genN(N1,R1),
    append(R1,[N1],R),!.

inverser([],X,X).
inverser([H|T],X,Acc) :- inverser(T,X,[H|Acc]).
inverserF(L1,L2) :- inverser(L1,L2,[]).


palaindrom(L1,L1) :- inverserF(L1,L1).

k(X,[X|_],1) :- !.
k(X,[_|T],N) :- M is N-1, k(X,T,M).
