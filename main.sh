#1000 RANDOM no are generated for the search , 
#the number to be searched will not be in this range  
#because we want to test the worst case time for each of the methods

calc(){ awk "BEGIN { print "$*" }"; }

for i in `seq 1000`
do
  echo `shuf -i 0-9992 -n1` >> data.txt
done
s=1000000000.0


 
start=`date +%s%N`
echo "Binary Search with iterative method `g++ 3.cpp && echo " " &&  ./a.out  ` "
end=`date +%s%N`
t=`expr $end - $start`
echo "Execution time was `expr $t` nanoseconds. `calc $t/$s` seconds" 


echo " " && echo " "
start=`date +%s%N`
echo "Binary Search with multi-threading method `g++ -pthread -w 1.cpp && echo " " && ./a.out`  "
end=`date +%s%N`
t=`expr $end - $start`
echo "Execution time was `expr $t` nanoseconds. `calc $t/$s` seconds"

rm data.txt
