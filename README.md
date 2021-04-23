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


- **1.cpp :** Multi-thread implementation of BS using POSIX pthread. basic idea is dividing the whole array by the no of threads thus the search runs parallelly on each of the defined spaces. Foe Ex: if we have a 1000 element array and 4 threads each thread will run for 250 elements , i.e. , first thread will search b/w 0-250 , second 250-500 and so on. Synchronization here not necessary because of no critical region.
  
- **3.cpp :** Iterative implementation of BS . It is just there to contrast the speed difference b/w with threads and without threads.

- **main.sh :** A shell script that loads 1000 random values into a new file data.txt , compiles and runs the code and also displays the time taken to run by both of these implementations . Finally deletes the data.txt file.

