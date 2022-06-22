echo Enter a character
read ch
case $ch in
    a|e|i|o|u ) echo "It is a vowel" ;;
    * ) echo "It is not a vowel";;
esac
