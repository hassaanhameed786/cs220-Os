#!/bin/bash
echo Bourne again shell  
echo
echo "Number checking (even/odd) using shell programming"
echo

#---------------------------------------------------------
echo "using array and for loop"
num="1 2 3 4 5 6 7 8 9 10"
for n in $num
do
q=$( expr $n % 2 )
if [ $q -eq 0 ]
then 
	echo "$n is even"
else
	echo "$n is odd"
fi
done
echo
#----------------------------------------------
echo "table using for loop "
read -p "which table you want: " num
for i in 1 2 3 4 5 6 7 8 9 10
do
echo $num "*" $i "=" $( expr $num \* $n )
done
echo
#---------------------------------------------
echo "table using while loop "
read -p "which talbe you want: " num
q=1
while [ $q -le  10 ]
do
	echo $num "*" $q "=" $( expr $num \* $q )
q=$( expr $q + 1 )
done
echo
#--------------------------------------------
echo "simple function"
num1=20
num2=30
add()
{
c=$( expr $1 + $2 )
echo "addition = $c"
}
add $num1 $num2
echo "value of c =" $c
echo
#--------------------------------------------
echo "switch statement example"
ch='y'
while [ $ch = 'y' -o $ch = 'Y' ]
do	
	echo "1 no of user loged on"
	echo "2 print calender"
	echo "3 print date"
read -p "enter your choice: " d
case $d in
	1) who;;
	2) cal 2018;;
	3) date;;
	*) break;;
esac
echo "do you wish to continue (y/n)"
read ch
done 
