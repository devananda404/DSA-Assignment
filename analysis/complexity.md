# Complexity Analysis

Let n = number of departments (n = 8) and h = height of the tree.

## Tree construction

Building the tree means creating n nodes and attaching each one to its parent with `addChild`, which is O(1) per call. So building the whole tree is **O(n)**.

## Level-order traversal

Each node is enqueued once and dequeued once, so every node is visited exactly once: **O(n)** time. The queue needs room for the widest level of the tree at any point; here IT's 3 siblings (HR, Finance, IT) is the widest single level, so the queue needs **O(n)** space in the worst case (it never needs more than n, since there are only n nodes total).

## Tree height

The tree has 4 levels: CEO → IT → Development → Frontend/Backend. For a general tree built this way (not necessarily balanced), height can range from O(log n) (bushy, wide tree) to O(n) (a tree that is really a long chain). This hierarchy is 4 levels deep for 8 nodes, which is reasonably shallow.

## Linear Search

| Case | Comparisons | Big-O |
|------|-------------|-------|
| Best | 1 (target is first element) | O(1) |
| Average | about n/2 | O(n) |
| Worst | n (target is last, or absent) | O(n) |

Space: O(1) extra space, searches the array in place.

## Binary Search

| Case | Comparisons | Big-O |
|------|-------------|-------|
| Best | 1 (target is the middle element) | O(1) |
| Average | about log₂ n | O(log n) |
| Worst | about ⌈log₂(n+1)⌉ | O(log n) |

Space: O(1) extra space (the iterative version used here).

**Why Binary Search needs sorted data:** at each step it looks only at the middle element and decides to discard either the left half or the right half, based on whether the target is smaller or larger. This is only a valid shortcut if the array is ordered — in an unsorted array, a smaller or larger comparison result says nothing about which half the target could be in.

## Applied to this dataset (n = 8)

- log₂ 8 = 3, so Binary Search should need about 3–4 comparisons in the worst case. The results (3, 3, 4) match this.
- Linear Search can need up to 8 comparisons, matching the "Marketing" result (8).
