#!/bin/bash
read input
while true; do
	curr=${input:0:10}
	if [[ "$curr" == "" ]]; then
		break
	else
		echo $curr
		input=${input:10}
	fi
done
