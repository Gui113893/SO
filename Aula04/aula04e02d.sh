#!/bin/bash
function compare(){
	if [[ $1 -eq $2 ]]; then
		return 1
	elif [[ $1 -lt $2 ]]; then
		return 2
	else
		return 3
	fi
	return 0
}

function main(){
	echo -n "Enter number: "
	read n1;
	echo -n "Enter number: "
	read n2;
	compare n1 n2
	case $? in
		1)
			echo $n1" == "$n2
			;;
		2)
			echo $n2" > "$n1
			;;
		3)
			echo $n1" > "$n2
			;;
		*)
			echo "Error"
	esac
	return 0
}

main 
