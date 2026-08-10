# A. Weird Sum
**Platform:** Codeforces
**Difficulty:** N/A
**Topic:** matrices

## Problem Statement
A. Weird Sum
time limit per test2 seconds
memory limit per test256 megabytes

Egor has a table of size 
n×m
𝑛
×
𝑚
, with lines numbered from 
1
1
 to 
n
𝑛
 and columns numbered from 
1
1
 to 
m
𝑚
. Each cell has a color that can be presented as an integer from 
1
1
 to 
10
5
10
5
.

Let us denote the cell that lies in the intersection of the 
r
𝑟
-th row and the 
c
𝑐
-th column as 
(r,c)
(
𝑟
,
𝑐
)
. We define the manhattan distance between two cells 
(
r
1
,
c
1
)
(
𝑟
1
,
𝑐
1
)
 and 
(
r
2
,
c
2
)
(
𝑟
2
,
𝑐
2
)
 as the length of a shortest path between them where each consecutive cells in the path must have a common side. The path can go through cells of any color. For example, in the table 
3×4
3
×
4
 the manhattan distance between 
(1,2)
(
1
,
2
)
 and 
(3,3)
(
3
,
3
)
 is 
3
3
, one of the shortest paths is the following: 
(1,2)→(2,2)→(2,3)→(3,3)
(
1
,
2
)
→
(
2
,
2
)
→
(
2
,
3
)
→
(
3
,
3
)
.

Egor decided to calculate the sum of manhattan distances between each pair of cells of the same color. Help him to calculate this sum.

Input

The first line contains two integers 
n
𝑛
 and 
m
𝑚
 (
1≤n≤m
1
≤
𝑛
≤
𝑚
, 
n⋅m≤100000
𝑛
⋅
𝑚
≤
100
000
) — number of rows and columns in the table.

Each of next 
n
𝑛
 lines describes a row of the table. The 
i
𝑖
-th line contains 
m
𝑚
 integers 
c
i1
,
c
i2
,…,
c
im
𝑐
𝑖
1
,
𝑐
𝑖
2
,
…
,
𝑐
𝑖
𝑚
 (
1≤
c
ij
≤100000
1
≤
𝑐
𝑖
𝑗
≤
100
000
) — colors of cells in the 
i
𝑖
-th row.

Output

Print one integer — the the sum of manhattan distances between each pair of cells of the same color.

Examples
input
Copy
2 3
1 2 3
3 2 1

output
Copy
7

input
Copy
3 4
1 1 2 2
2 1 1 2
2 2 1 1

output
Copy
76

input
Copy
4 4
1 1 2 3
2 1 1 2
3 1 2 1
1 1 2 1

output
Copy
129

Note

In the first sample there are three pairs of cells of same color: in cells 
(1,1)
(
1
,
1
)
 and 
(2,3)
(
2
,
3
)
, in cells 
(1,2)
(
1
,
2
)
 and 
(2,2)
(
2
,
2
)
, in cells 
(1,3)
(
1
,
3
)
 and 
(2,1)
(
2
,
1
)
. The manhattan distances between them are 
3
3
, 
1
1
 and 
3
3
, the sum is 
7
7
.