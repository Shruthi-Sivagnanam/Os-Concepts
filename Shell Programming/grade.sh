echo "Enter the mark obtained"
read mark
if [ $mark -gt 90 ] 
then
    echo "Grade A"
elif [ $mark -gt 80 ] 
then
    echo "Grade B"
elif [ $mark -gt 70 ] 
then
    echo "Grade C"
elif [ $mark -gt 60 ] 
then
    echo "Grade D"
elif [ $mark -gt 50 ] 
then
    echo "Grade E"
else
    echo "Failed"
fi
