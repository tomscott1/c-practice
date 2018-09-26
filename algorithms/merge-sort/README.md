## Merge sort

1 Array A

2 is split into L and R (splits)

3 L and R go to L' and R' which are sorted arrays

4 then L' and R' are merged into sorted array A

1 input size n

2 L/R 2 arrays of size n/2

3 2 sorted arrays of size n/2

4 sorted array of size n


Merge assumes two sorted arrays as input

L'    R'
20    12
3	    11
7	    9
2	    1


step 1 compare 2 and 1 write down 1 and cross it out
step 2 compare 2 and 9 write done 2 and cross it out
continue walking up the array
