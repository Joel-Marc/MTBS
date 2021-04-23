# MULTI-THREAD IMPLEMENTATION OF BINARY SEARCH

## TO RUN :
1. Add execution privileges to main.sh by using ```chmod +x main.sh```
2. Run ```./main.sh```
3. OUTPUT will be like :
```
Binary Search with iterative method
69420 is not present in array
Execution time was 1391841700 nanoseconds. 1.39184 seconds


Binary Search with multi-threading method
69420 not found in array
Execution time was 426393700 nanoseconds. 0.426394 seconds
```


- **1.cpp :** Multi-thread implementation of BS using POSIX pthread. basic idea is dividing the whole array by the no of threads thus the search runs parallelly on each of the defined spaces. For Ex: if we have a 1000 element array and 4 threads each thread will run for 250 elements , i.e. , first thread will search b/w 0-250 , second 250-500 and so on. Synchronization here not necessary because of no critical region. The value to be searched is 69420 which is not in the array which is loaded in by the file , this is to test the worst case time complexity (For BS worst case is the element not being present).
  
- **3.cpp :** Iterative implementation of BS . It is just there to contrast the speed difference b/w with threads and without threads. Similarly here also the value to be searched is 69420 which is not in the array which is loaded in by the file , this is to test the worst case time complexity (For BS worst case is the element not being present).

- **main.sh :** A shell script that loads 1000 random values (b/w 0-9992) into a new file data.txt , compiles and runs the code and also displays the time taken to run by both of these implementations . Finally deletes the data.txt file.

