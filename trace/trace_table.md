# Trace Table – Question 5

Counting rule: one comparison = one department name checked against the target.

## A. Tree construction trace

| Step | Action | Result |
|------|--------|--------|
| 1 | Create CEO | Root node |
| 2 | addChild(CEO, HR) | HR is 1st child of CEO |
| 3 | addChild(CEO, Finance) | Finance is 2nd child of CEO |
| 4 | addChild(CEO, IT) | IT is 3rd child of CEO |
| 5 | addChild(IT, Development) | Development is 1st child of IT |
| 6 | addChild(IT, Testing) | Testing is 2nd child of IT |
| 7 | addChild(Development, Frontend) | Frontend is 1st child of Development |
| 8 | addChild(Development, Backend) | Backend is 2nd child of Development |

Resulting tree:

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

Height = 4 levels (CEO → IT → Development → Frontend/Backend).

## B. Level-order traversal trace

Queue-based traversal (FIFO). Start: queue = [CEO].

| Step | Node visited (dequeued) | Printed | Children enqueued |
|------|--------------------------|---------|--------------------|
| 1 | CEO | CEO | HR, Finance, IT |
| 2 | HR | HR | (none) |
| 3 | Finance | Finance | (none) |
| 4 | IT | IT | Development, Testing |
| 5 | Development | Development | Frontend, Backend |
| 6 | Testing | Testing | (none) |
| 7 | Frontend | Frontend | (none) |
| 8 | Backend | Backend | (none) |

Output: `CEO HR Finance IT Development Testing Frontend Backend`

## C. Linear Search trace

Array (original order): `[CEO, HR, Finance, IT, Development, Testing, Frontend, Backend]`

### Search "IT" → FOUND, 4 comparisons

| Comparison # | Department checked | Match? |
|---|---|---|
| 1 | CEO | No |
| 2 | HR | No |
| 3 | Finance | No |
| 4 | IT | **Yes – stop** |

### Search "Frontend" → FOUND, 7 comparisons

| Comparison # | Department checked | Match? |
|---|---|---|
| 1 | CEO | No |
| 2 | HR | No |
| 3 | Finance | No |
| 4 | IT | No |
| 5 | Development | No |
| 6 | Testing | No |
| 7 | Frontend | **Yes – stop** |

### Search "Marketing" → NOT FOUND, 8 comparisons

| Comparison # | Department checked | Match? |
|---|---|---|
| 1 | CEO | No |
| 2 | HR | No |
| 3 | Finance | No |
| 4 | IT | No |
| 5 | Development | No |
| 6 | Testing | No |
| 7 | Frontend | No |
| 8 | Backend | No (end of array) |

## D. Binary Search trace

Sorted array (index 0–7): `[Backend, CEO, Development, Finance, Frontend, HR, IT, Testing]`

### Search "IT" → FOUND, 3 comparisons

| Comparison # | low | high | mid | Department at mid | Result | Next action |
|---|---|---|---|---|---|---|
| 1 | 0 | 7 | 3 | Finance | IT > Finance | search right half (low=4) |
| 2 | 4 | 7 | 5 | HR | IT > HR | search right half (low=6) |
| 3 | 6 | 7 | 6 | IT | match | **FOUND** |

### Search "Frontend" → FOUND, 3 comparisons

| Comparison # | low | high | mid | Department at mid | Result | Next action |
|---|---|---|---|---|---|---|
| 1 | 0 | 7 | 3 | Finance | Frontend > Finance | search right half (low=4) |
| 2 | 4 | 7 | 5 | HR | Frontend < HR | search left half (high=4) |
| 3 | 4 | 4 | 4 | Frontend | match | **FOUND** |

### Search "Marketing" → NOT FOUND, 4 comparisons

| Comparison # | low | high | mid | Department at mid | Result | Next action |
|---|---|---|---|---|---|---|
| 1 | 0 | 7 | 3 | Finance | Marketing > Finance | search right half (low=4) |
| 2 | 4 | 7 | 5 | HR | Marketing > HR | search right half (low=6) |
| 3 | 6 | 7 | 6 | IT | Marketing > IT | search right half (low=7) |
| 4 | 7 | 7 | 7 | Testing | Marketing < Testing | search left half (high=6); low > high, **NOT FOUND** |

## Summary

| Search Target | Linear comparisons | Binary comparisons |
|---|---|---|
| IT | 4 | 3 |
| Frontend | 7 | 3 |
| Marketing | 8 | 4 |
| **Total** | **19** | **10** |
