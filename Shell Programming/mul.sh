echo "Enter the value of n: "
read n 
for x in 1 2 3 4 5
do
    ans=`expr $n \* $x`
    echo "$n * $x = $ans"
    sleep 1
done
