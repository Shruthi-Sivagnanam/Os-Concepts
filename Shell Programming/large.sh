echo "Enter the value of a:"
read a
echo "Enter the value of b:"
read b
echo "Enter the value of c: "
read c
if [ $a -gt $b -a $a -gt $c ]
then 
    echo "A is greatest"
elif [ $b -gt $c ]
then
    echo "B is greatest"
else
    echo "C is greatest"
fi
