### PEAK FINDING ###
- [x] 1D peak finding
    - [x] Linear Search
    > Position n iff n >= n-1 and n >= n+1, then peak

    - [x] Binary Search
    > Look at n/2 Position  
    > if array[n/2] < array[n/2-1] then look left half  
    > left half 1... n/2 -1 to look for a peak  
    > else if array[n/2] < array[m/2+1] then look right  
    > else peak found at n/2


- [ ] 2D peak finding
>     m  
>  | |C| |  
>n |B|A|D|  
>  | |E| |  
>  
> A is a 2D peak iff (if and only if)  
> A >= B, A >= C, A>=D, A>=E
>
> greedy ascent algorithm:  
> look a direction if greater than go in that direction else go in the opposite direction  
>
> Solution:
> Pick middle column j = m/2
> Find global max on column(j) at (i,j)
> compare (i,j-1), (i,j), (i,j+1) (After finding the max in the row look to the left and right and compare)
> pick left or right if larger
> if (i,j) >= (i,j+1) && (i,j-1) then (i,j) is a 2d peak
> if left or right is larger solve the new problem with half the number of columns  
>
> if you have a single column find the global max == base case  

Reference: https://www.youtube.com/watch?v=HtSuA80QTyo&t=305s
