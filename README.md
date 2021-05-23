### How to run this in your local machine ?

Just keep the 'json.hpp' file and the 'dataset.json' file in the same directory where you will be running the 'code.cpp' file and see the top 5 closest vehicles from you after running the code :)

### Overview of the code
- In this console application, I used euclidean algorithm as the metric for getting nearest vehicles to current coordinates. 
- The dataset is being read from a JSON file that has 1 lakh objects each having it's own primary key(Id), x-coordinate and y-coordinate.
- The algorithm uses heaps for getting top 5 nearest vehicles from current location.
- I have maintained a heap that can carry atmost 5 elements at a time. If the size of heap is less than 5, then simply keep pushing the vehicles into it, else while iterating through the objects, if I find some vehicle having distance smaller than the root vehicle of the heap and the size of heap is 5, then only push that vehicle into the heap and pop the root vehicle, else pushing it is of no use. 
- The time complexity of the approach is O(Nlog(K)) where N is the number of vehicles and K is the number of nearest vehicles we want. In this case, time complexity becomes almost O(N) since K is only 5. This algorithm can work well for upto 10 lakh vehicles. 
