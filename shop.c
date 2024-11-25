#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the heap
typedef struct {
    int cost;
    int x, y;
} HeapNode;
typedef struct {
    HeapNode *data;
    int size;
    int capacity;
} MinHeap;
// Min-Heap utility functions
MinHeap* createHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->data = (HeapNode *)malloc(sizeof(HeapNode) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}
void insertHeap(MinHeap *heap, HeapNode node) {
    int i = heap->size++;
    while (i > 0 && heap->data[(i - 1) / 2].cost > node.cost) {
        heap->data[i] = heap->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->data[i] = node;
}
HeapNode deleteMin(MinHeap *heap) {
    HeapNode minNode = heap->data[0];
    HeapNode lastNode = heap->data[--heap->size];
    int i = 0, child;
    while ((child = 2 * i + 1) < heap->size) {
        if (child + 1 < heap->size && heap->data[child].cost > heap->data[child + 1].cost) {
            child++;
        }
        if (lastNode.cost <= heap->data[child].cost) {
            break;
        }
        heap->data[i] = heap->data[child];
        i = child;
    }
    heap->data[i] = lastNode;
    return minNode;
}
// Comparator for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}
int compareDesc(const void *a, const void *b) {
    return (*(int *)b) - (*(int *)a);
}


int main() {
    int N, D;
    scanf("%d %d", &N, &D);
    int *items = (int *)malloc(sizeof(int) * N);
    int *coupons = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &items[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &coupons[i]);
    }

    // Sort items and coupons
    qsort(items, N, sizeof(int), compare);
    qsort(coupons, N, sizeof(int), compareDesc);

    int **unlock = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        unlock[i] = (int *)calloc(N, sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        memset(unlock[i], 0, N * sizeof(int));
    }
    for(int i = 0; i < N; i++){
        unlock[0][i] = 1;
        unlock[i][0] = 1;
    }

    MinHeap *heap = createHeap(N * N);

    insertHeap(heap, (HeapNode){items[0] - coupons[0], 0, 0});
    int count = 0;
    while (heap->size > 0) {
        HeapNode node = deleteMin(heap);
        int cost = node.cost, x = node.x, y = node.y;

        if (cost > D) {
            break;
        }
        D -= cost;
        count++;
        
        if(x + 1 < N){
            unlock[x + 1][y] += 1;
            if(unlock[x + 1][y] == 2)   //when the left and down side combinations are bought, it's unlocked(added to heap)
                insertHeap(heap, (HeapNode){items[x + 1] - coupons[y], x + 1, y});
        }
        if(y + 1 < N){
            unlock[x][y + 1] += 1;
            if(unlock[x][y + 1] == 2)
                insertHeap(heap, (HeapNode){items[x] - coupons[y + 1], x, y + 1});
        }
    }

    printf("%d %d\n", count, D);
    return 0;
}
