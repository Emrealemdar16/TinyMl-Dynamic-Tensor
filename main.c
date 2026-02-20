#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tensor.h"

int main() {
    srand(time(NULL));

    printf("=== TINYML DYNAMIC TENSOR DEMO ===\n\n");

    // 1. Input Layer (Float32)
    printf("--- 1. Creating Input Layer (Float32) ---\n");
    Tensor* input_layer = create_tensor(10, 10, 1, TENSOR_FLOAT32);
    if (input_layer) {
        fill_random(input_layer);
        print_tensor_preview(input_layer);
    }
    printf("\n");

    // 2. Weights Layer (Int8 - Quantized)
    printf("--- 2. Creating Weights Layer (Int8) ---\n");
    Tensor* weights_layer = create_tensor(10, 10, 1, TENSOR_INT8);
    if (weights_layer) {
        fill_random(weights_layer);
        print_tensor_preview(weights_layer);
    }
    printf("\n");

    // Memory Cleanup
    free_tensor(input_layer);
    free_tensor(weights_layer);

    return 0;
}
