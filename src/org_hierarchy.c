/*
 * DSA Assignment 2 - Question 5
 * Subject : PCCST303 - Data Structures and Algorithms
 * Topic   : Organisational hierarchy tree, Level-order traversal,
 *           Linear Search vs Binary Search on department names
 *
 * Choices made (not specified in the assignment):
 *  - The tree is a general tree (each node can have more than 2 children),
 *    stored as a node with an array of child pointers.
 *  - Department names and search targets are read from input/input.txt.
 *  - Linear Search uses the departments in their original hierarchy order
 *    (CEO, HR, Finance, IT, Development, Testing, Frontend, Backend).
 *  - Binary Search requires sorted data, so the same names are copied into
 *    a second array and sorted alphabetically before searching.
 *  - One comparison = one department name checked against the target.
 *  - Height is counted in levels (root alone = 1 level).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 3
#define MAX_NAME 20
#define MAX_DEPT 10

struct Node {
    char name[MAX_NAME];
    struct Node *children[MAX_CHILDREN];
    int childCount;
};

/* Create a new tree node for a department */
struct Node *createNode(const char *name) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(node->name, name);
    node->childCount = 0;
    return node;
}

/* Attach child as a child of parent */
void addChild(struct Node *parent, struct Node *child) {
    parent->children[parent->childCount] = child;
    parent->childCount++;
}

/* Level-order traversal using a simple array-based queue */
void levelOrder(struct Node *root) {
    struct Node *queue[MAX_DEPT];
    int front = 0, rear = 0, i;

    queue[rear++] = root;
    while (front < rear) {
        struct Node *current = queue[front++];
        printf(" %s", current->name);
        for (i = 0; i < current->childCount; i++) {
            queue[rear++] = current->children[i];
        }
    }
    printf("\n");
}

/* Height of the tree in levels (a single node has height 1) */
int height(struct Node *root) {
    int i, h, maxH = 0;
    if (root == NULL) {
        return 0;
    }
    if (root->childCount == 0) {
        return 1;
    }
    for (i = 0; i < root->childCount; i++) {
        h = height(root->children[i]);
        if (h > maxH) {
            maxH = h;
        }
    }
    return maxH + 1;
}

/* Linear search: scans the array in its given order.
   Returns the index if found, -1 if not found. Counts comparisons. */
int linearSearch(char arr[][MAX_NAME], int n, const char *target, int *comparisons) {
    int i;
    *comparisons = 0;
    for (i = 0; i < n; i++) {
        (*comparisons)++;
        if (strcmp(arr[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

/* Simple bubble sort, so the array can be used for Binary Search */
void bubbleSort(char arr[][MAX_NAME], int n) {
    int i, j;
    char temp[MAX_NAME];
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

/* Binary search on a SORTED array.
   Returns the index if found, -1 if not found. Counts comparisons. */
int binarySearch(char arr[][MAX_NAME], int n, const char *target, int *comparisons) {
    int low = 0, high = n - 1, mid, cmp;
    *comparisons = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        (*comparisons)++;
        cmp = strcmp(target, arr[mid]);
        printf("    comparing with %-12s -> ", arr[mid]);
        if (cmp == 0) {
            printf("match\n");
            return mid;
        } else if (cmp < 0) {
            printf("target is smaller, search left half\n");
            high = mid - 1;
        } else {
            printf("target is larger, search right half\n");
            low = mid + 1;
        }
    }
    return -1;
}

int main(void) {
    FILE *fp;
    char deptOriginal[MAX_DEPT][MAX_NAME];
    char deptSorted[MAX_DEPT][MAX_NAME];
    char searchTargets[MAX_DEPT][MAX_NAME];
    int n, m, i;
    int index, comparisons;
    int linearTotal = 0, binaryTotal = 0;

    /* Read input data */
    fp = fopen("input/input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input/input.txt\n");
        return 1;
    }
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fp, "%s", deptOriginal[i]);
    }
    fscanf(fp, "%d", &m);
    for (i = 0; i < m; i++) {
        fscanf(fp, "%s", searchTargets[i]);
    }
    fclose(fp);

    /* Build the organisational hierarchy as a tree */
    struct Node *ceo = createNode("CEO");
    struct Node *hr = createNode("HR");
    struct Node *finance = createNode("Finance");
    struct Node *it = createNode("IT");
    struct Node *development = createNode("Development");
    struct Node *testing = createNode("Testing");
    struct Node *frontend = createNode("Frontend");
    struct Node *backend = createNode("Backend");

    addChild(ceo, hr);
    addChild(ceo, finance);
    addChild(ceo, it);
    addChild(it, development);
    addChild(it, testing);
    addChild(development, frontend);
    addChild(development, backend);

    printf("===== DSA Assignment 2 - Question 5 =====\n\n");

    printf("Part (a): Organisational Hierarchy Tree\n");
    printf("Tree construction: CEO is root; HR, Finance, IT added as children of CEO;\n");
    printf("Development, Testing added as children of IT;\n");
    printf("Frontend, Backend added as children of Development.\n\n");

    printf("Level-order traversal:");
    levelOrder(ceo);
    printf("Tree height: %d levels\n", height(ceo));

    /* Part (b): searchable representation */
    printf("\nPart (b): Searching\n");
    printf("Original order (used for Linear Search):");
    for (i = 0; i < n; i++) {
        printf(" %s", deptOriginal[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        strcpy(deptSorted[i], deptOriginal[i]);
    }
    bubbleSort(deptSorted, n);
    printf("Sorted order (used for Binary Search):");
    for (i = 0; i < n; i++) {
        printf(" %s", deptSorted[i]);
    }
    printf("\n");

    for (i = 0; i < m; i++) {
        printf("\nSearching for \"%s\"\n", searchTargets[i]);

        index = linearSearch(deptOriginal, n, searchTargets[i], &comparisons);
        printf("  Linear Search : %s, comparisons = %d\n",
               (index != -1) ? "FOUND" : "NOT FOUND", comparisons);
        linearTotal += comparisons;

        printf("  Binary Search steps:\n");
        index = binarySearch(deptSorted, n, searchTargets[i], &comparisons);
        printf("  Binary Search : %s, comparisons = %d\n",
               (index != -1) ? "FOUND" : "NOT FOUND", comparisons);
        binaryTotal += comparisons;
    }

    printf("\nTotal comparisons -> Linear Search: %d, Binary Search: %d\n",
           linearTotal, binaryTotal);

    return 0;
}
