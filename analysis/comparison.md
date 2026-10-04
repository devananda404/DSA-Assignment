# Comparison: Linear Search vs Binary Search

## Actual results for this dataset (n = 8)

| Search Target | Linear Search Result | Linear Comparisons | Binary Search Result | Binary Comparisons |
|---------------|----------------------|---------------------|-----------------------|---------------------|
| IT | Found | 4 | Found | 3 |
| Frontend | Found | 7 | Found | 3 |
| Marketing | Not found | 8 | Not found | 4 |
| **Total** | – | **19** | – | **10** |

Binary Search used about 47% fewer comparisons overall (9 fewer out of 19).

## Which used fewer comparisons, and why

Binary Search used fewer comparisons in every single search. It works because the department names are sorted first: each comparison eliminates half of the remaining names, so the search needs only about log₂ 8 = 3 steps. Linear Search has no such shortcut — it must check names one at a time from the start until it finds the target or reaches the end, so a name placed later in the list (like "Frontend", 7th in the original order) costs much more.

## Effect of the number of departments

With only 8 departments the difference is already visible (19 vs 10 total comparisons), and it grows with n: Linear Search's worst case grows directly with n, while Binary Search's worst case grows only with log₂ n. For example, with 1000 departments, Linear Search could need up to 1000 comparisons, while Binary Search would need only about 10.

## Advantages and disadvantages

| | Linear Search | Binary Search |
|---|---|---|
| Advantage | Works on unsorted data; simple to implement | Far fewer comparisons for larger n |
| Disadvantage | Slow for large n | Requires the data to be sorted first (sorting itself costs time) |

## Is Binary Search preferable for this dataset?

Yes, for searching: Binary Search is preferable, even though sorting 8 names is a small one-time cost, because departments are looked up repeatedly (reporting, lookups) while the hierarchy itself changes rarely.

## Is the tree representation suitable for organisational reporting and department searching?

The tree is well suited for **reporting the hierarchy**: it naturally shows who reports to whom, and level-order traversal gives a clean, management-level view (CEO, then direct reports, then their reports, and so on). It is not, by itself, suited for **fast searching** — finding a department by name in a tree normally means visiting nodes (similar cost to Linear Search, or worse if the tree isn't ordered by name). That is why department names are also kept in a separate sorted array for Binary Search here: the tree is used to represent structure and relationships, and the sorted array is used purely for fast name lookup.
