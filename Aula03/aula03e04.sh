#!/bin/bash
space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n \
	| tail -1 | cut -d "%" -f1 -)
echo "largest occupied space = $space%"
case $space in
	[0-6]?)
		Message="All OK."
		;;
	[7-8]?)
		Message="Cleaning out. One partition is $space % full."
		;;
	[9][0-8])
		Message="Better buy a new disk. One partition is $space % full."
		;;
	[9][9])
		Message="I'm drowning here! There's a partition at $space %!"
		;;
	*)
		Message="I seem to be running with a non-existent disk..."
		;;
esac
echo $Message
