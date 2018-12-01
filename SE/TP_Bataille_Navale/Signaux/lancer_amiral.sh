#!/bin/bash

if( test $# -ne 2 ) then
    echo "Usage: $0 <taille> <nb bateux>"
    exit 1
fi

fich_mer="ficMer"
line=$1
column=$1
nbbat=$2


if [  -f "$fich_mer" ]
then
	rm "$fich_mer"

	pkill navire
	pkill amiral
fi

../Mer/init_fich_mer "$fich_mer" "$line" "$column"

#### lancement du amiral
./amiral "$fich_mer" "$nbbat"
