
# Reviewing DFS and BFS

Personal algorithm practice: A simple algorithm to find the exit of a maze using DFS and BFS search methods.


## dfs

DFS is an algorithm that explores until it can no longer proceed. If the exit is not found, it backtracks and retries with a different route. It can be easily implemented using a recursive process that checks the four directions (up, down, left, right) in order and explores cells that can be traversed.

(If stack overflow is a concern, it can be implemented using an explicit stack.)

Looking at the execution results, you can see that it takes a detour since it explores until it can no longer proceed.

- ex1 result

``` c
  1  2  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X
  X  3  4  5  6  X  X  X  X  X  X  X 26 27 28  X  X  X  X  X  X  O  O  O  O  O  O  O  X  X
  X  O  X  X  7  X  X  X  X  X  X  X 25  X 29  X  X  X  X  X  X  O  X  X  X  X  X  O  O  X
  X  O  X  X  8  X  X  X  X  X  X  X 24  X 30 31 32 33 34 35 36 37  X  X  X  X  X  X  O  X
  X  X  X  X  9 10 11 12 13 14  X  X 23  X  X  X  X  X  X  X  X 38  X  X  X  X  X  X  O  X
  X  X  X  X  X  X  X  X  X 15  X  X 22  X  X  X  X  X  X  X  X 39 40 41 42  O  O  O  O 55
  X  X  X  X  X  X  X  X  X 16  X  X 21  X  X  X  X  X  X  X  X  X  X  X 43  X  X  X  X 54
  X  X  X  X  X  X  X  X  X 17 18 19 20  O  X  X  X  X  X  X  X  X  X  X 44  X  X  X  X 53
  X  X  X  X  X  X  X  X  X  X  X  X  X  O  X  X  X  X  X  X  X  X  X  X 45  X  X  X  X 52
  X  X  X  X  X  X  X  X  X  X  X  X  X  O  O  O  O  O  O  O  O  O  X  X 46 47 48 49 50 51
```


- ex2 result

``` c
  1  2  X  X  X  X  X  X  X  X  X  X  X  X  X
  X  3  4  5  X  X  X  X  X  X  X  O  O  O  X
  X  X  X  6  X  X  X  X  X  X  X  O  X  O  X
  X  O  X  7  O 15 16 17  O  O  O  O  X  O  X
  X  O  X  8  X 14  X 18  X  X  X  X  X  O  X
  X  O  X  9  X 13  X 19  X  X  X  X  X  O  X
  X  O  X 10 11 12  X 20  O  O  O  O  O 30 31
  X  O  X  X  X  O  X 21  X  X  X  X  X 29  X
  X  O  O  O  O  O  X 22 23 24 25 26 27 28  X
  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X
```

(During backtracking, the recursive process steps[x][y] = 0 ensures that the traversed path is reset to 0.)


## bfs

Due to the 'First-In, First-Out' (FIFO) nature of a queue, elements added earlier (i.e., closer cells) are dequeued first.

BFS utilizes this queue behavior by first adding all reachable cells from the current position to the queue. Then, it dequeues cells from the front and proceeds with the next exploration.

As a result, unlike DFS, BFS guarantees finding the shortest path.


- ex1 result

``` c
  1  2  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X
  X  3  4  5  6  X  X  X  X  X  X  X 26 27 28  X  X  X  X  X  X 39 40 41 42 43 44 45  X  X
  X  4  X  X  7  X  X  X  X  X  X  X 25  X 29  X  X  X  X  X  X 38  X  X  X  X  X 46  O  X
  X  5  X  X  8  X  X  X  X  X  X  X 24  X 30 31 32 33 34 35 36 37  X  X  X  X  X  X  O  X
  X  X  X  X  9 10 11 12 13 14  X  X 23  X  X  X  X  X  X  X  X 38  X  X  X  X  X  X  O  X
  X  X  X  X  X  X  X  X  X 15  X  X 22  X  X  X  X  X  X  X  X 39 40 41 42 43 44 45 46 47
  X  X  X  X  X  X  X  X  X 16  X  X 21  X  X  X  X  X  X  X  X  X  X  X 43  X  X  X  X  O
  X  X  X  X  X  X  X  X  X 17 18 19 20 21  X  X  X  X  X  X  X  X  X  X 44  X  X  X  X  O
  X  X  X  X  X  X  X  X  X  X  X  X  X 22  X  X  X  X  X  X  X  X  X  X 45  X  X  X  X  O
  X  X  X  X  X  X  X  X  X  X  X  X  X 23 24 25 26 27 28 29 30 31  X  X 46 47  O  O  O  O
```

- ex2 result


``` c
  1  2  X  X  X  X  X  X  X  X  X  X  X  X  X
  X  3  4  5  X  X  X  X  X  X  X 17 18 19  X
  X  X  X  6  X  X  X  X  X  X  X 16  X 20  X
  X  O  X  7  8  9 10 11 12 13 14 15  X  O  X
  X  O  X  8  X 10  X 12  X  X  X  X  X  O  X
  X 21  X  9  X 11  X 13  X  X  X  X  X  O  X
  X 20  X 10 11 12  X 14 15 16 17 18 19 20 21
  X 19  X  X  X 13  X 15  X  X  X  X  X 21  X
  X 18 17 16 15 14  X 16 17 18 19 20 21  O  X
  X  X  X  X  X  X  X  X  X  X  X  X  X  X  X
```
