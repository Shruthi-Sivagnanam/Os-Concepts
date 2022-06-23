echo "Enter the number"
read n
i=2
m=`expr $n / 2`
until [ $i -gt $m ]; do
    q=`expr $n % $i`
    if [ $q -eq 0 ]; then
        echo "Not a prime number"
        exit
    fi
    i=`expr $i + 1`
done
echo "Prime number"
