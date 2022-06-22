echo "Enter two number: "
read a b
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "Enter your choice: "
read choice
case $choice in
    1)
        c=`expr $a + $b `
        echo $c ;;
    2)
        c=`expr $a - $b `
        echo $c ;;
    3)
        c=`expr $a \* $b `
        echo $c ;;
    4)
        c=`expr $a \/ $b `
        echo $c ;;
    *)
        echo "Invaild choice" 
esac
