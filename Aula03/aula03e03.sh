#!/bin/bash
# This script checks the existence of a file
echo "Checking..."
if [[ $# != 1 ]]  ; then
	echo "Número de argumentos inválido. 1 Expectado"
	exit 1
fi

if [[ -f $1 ]] ; then
	echo "$1 existe."
else
	echo "$1 não existe"
fi

ls -l $1

echo "...done."
