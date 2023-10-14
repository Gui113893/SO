#!/bin/bash

function main(){
	if [ -f $1 ]; then
		declare -A array
		i=0
		while read number; do
			array[$i]=$number
			i=$((i+1))
		done < $1
		echo "Before:"
		for ((i = 0; i < ${#array[@]}; i++)); do
			echo "${array[$i]}"
		done

		for ((ind = 0; ind < ${#array[@]}; ind++)); do
			min_index=$ind
			for ((j = ind+1; j < ${#array[@]}; j++)); do
				if [[ array[$j] -lt array[$min_index] ]]; then
					min_index=$j
				fi
			done
			aux=${array[$ind]}
			array[$ind]=${array[$min_index]}
			array[$min_index]=$aux 
		done
		echo "After:"
		for ((i = 0; i < ${#array[@]}; i++)); do
			echo "${array[$i]}"
		done
	else
		echo "File $1 don't exist"
		return 0
	fi
}

main $1
