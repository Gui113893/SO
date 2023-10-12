#!/bin/bash
function imprime_msg()
{
	echo "A minha primeira funcao"
	return 0
}


function showInfo()
{
	Data=$(date)
	User=$(whoami)
	PC=$(hostname)

	echo "Data:" $Data
	echo "User:" $User
	echo "Pc:" $PC
}

