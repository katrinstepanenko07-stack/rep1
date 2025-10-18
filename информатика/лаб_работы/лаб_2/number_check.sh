#!/bin/bash

number=$1
if ((($number % 2) == 0)); then
	echo "Число четное"
else
	echo "Число нечетное"
fi

