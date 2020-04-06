#!/bin/bash
echo "bourne again shell (bash)"
echo

#---------------------------------------------

for i in 1 2 3 4 5 6 7 8 9 10
do
	echo "i=$i"
done
echo

#---------------------------------------------

count="1 2 3 4 5 6 7 8 9 10"
for i in $count
do 
	echo "count=$i"
done
echo

#---------------------------------------------

x=1
while [ $x -le 10 ]
do
	echo "x=$x"
	x=$( expr $x + 1 )
done

#---------------------------------------------
