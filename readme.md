### heapsort

#### how to use:
```bash
gcc hs.c -lm -g && ./a.out 10   
```

##### sample output: 
```
initial: 13 92 99 50 96 83 90 9 74 87                                      
build complete binary tree:                                                
                                                                           
                                   13                                      
                 92------------------------------------99                  
        50------------------96                 83------------------90
   9----------74       87

-
heapfy:
                                   9
                 13------------------------------------83
        50------------------87                 99------------------90
   92----------74       96

-
heapsort:

                                   99 
                 96------------------------------------92
        90------------------87                 83------------------74
   50----------13       9
```
