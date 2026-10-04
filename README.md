# DSA Assignment 2 – Question 5

**Subject:** PCCST303 – Data Structures and Algorithms
**College:** Vimal Jyothi Engineering College
**Student Name:** Devananda V S
**Roll No:** 21
**Branch:** CC
**Year/Semester:** Second Year – IIIrd Semester
**Question Number:** 5
**Language:** C

## Problem Statement

A company has the following organisational hierarchy:

```
CEO → HR, Finance, IT
IT → Development, Testing
Development → Frontend, Backend
```

**a)** Represent the hierarchy using a suitable tree structure and implement its construction. Execute the program and display the hierarchy using level-order traversal.

**b)** Store the department names in a suitable searchable representation and compare Linear Search and Binary Search for locating a department. Record the number of comparisons for at least three searches.

**c)** Analyse tree height, traversal behaviour, search comparisons and time complexity of the selected operations. Determine whether the chosen representation is suitable for organisational reporting and department searching.

## Input Format

`input/input.txt` has 4 lines:

```
8
CEO HR Finance IT Development Testing Frontend Backend
3
IT Frontend Marketing
```

Line 1: number of departments. Line 2: department names, in hierarchy order. Line 3: number of search targets. Line 4: the search targets ("Marketing" does not exist, to show an unsuccessful search).

## Approach

1. Build the hierarchy as a general tree: each node stores its name and an array of child pointers, built with `createNode` and `addChild`.
2. Display it with a queue-based level-order traversal, and compute its height recursively.
3. Keep the department names in two arrays: the original hierarchy order (used for Linear Search) and a sorted copy made with bubble sort (used for Binary Search, which requires sorted data).
4. Run Linear Search and Binary Search for each target, counting one comparison per department name checked (one `strcmp`), and print the results.

Choices made where the assignment is silent are listed in the top comment of `src/org_hierarchy.c`.

## Resulting Tree

```
CEO
 ├── HR
 ├── Finance
 └── IT
      ├── Development
      │    ├── Frontend
      │    └── Backend
      └── Testing
```

Height: 4 levels.

## Files in the Repository

| File | Description |
|------|-------------|
| `src/org_hierarchy.c` | C source code |
| `input/input.txt` | Input data (departments and search targets) |
| `output/output.txt` | Program output |
| `trace/trace_table.md` | Trace of tree construction, level-order traversal, and both searches |
| `analysis/complexity.md` | Time and space complexity analysis |
| `analysis/comparison.md` | Comparison table, discussion and conclusion |

## How to Compile

Run from the repository root, because the program reads `input/input.txt`.

```
gcc src/org_hierarchy.c -o org_hierarchy
```

## How to Run

```
./org_hierarchy
```

On Windows (MinGW): `gcc src\org_hierarchy.c -o org_hierarchy.exe` then `org_hierarchy.exe`.

To save the output: `./org_hierarchy > output/output.txt`

## Sample / Actual Output Summary

```
Level-order traversal: CEO HR Finance IT Development Testing Frontend Backend
Tree height: 4 levels

Searching for "IT"        -> Linear: FOUND (4 comparisons)   Binary: FOUND (3 comparisons)
Searching for "Frontend"  -> Linear: FOUND (7 comparisons)   Binary: FOUND (3 comparisons)
Searching for "Marketing" -> Linear: NOT FOUND (8 comparisons) Binary: NOT FOUND (4 comparisons)

Total comparisons -> Linear Search: 19, Binary Search: 10
```

Full output is in `output/output.txt`.

## Complexity Summary

(n = number of departments = 8)

| Operation | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Tree construction | O(n) | O(n) | O(n) | O(n) |
| Level-order traversal | O(n) | O(n) | O(n) | O(n) (queue) |
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |

Details are in `analysis/complexity.md`.

## Conclusion

The organisational hierarchy fits naturally into a tree, and level-order traversal gives a clean, level-by-level view of the company (height 4 levels). For searching, Binary Search clearly outperformed Linear Search on this dataset — 10 total comparisons versus 19 — because it works on the sorted department names and halves the search space each step, while Linear Search must scan from the start. The tree itself is well suited to representing and reporting the organisational structure, but it is the separate sorted array, not the tree, that makes fast department lookup (Binary Search) possible. For this company's dataset, keeping both representations — the tree for structure and reporting, and the sorted array for searching — is the right approach.
