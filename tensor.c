#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tensor.h"

Tensor* create_tensor(int h, int w, int d, TensorType type) {
    Tensor* t = (Tensor*)malloc(sizeof(Tensor));
    if (!t) return NULL;

    t->shape[0] = h;
    t->shape[1] = w;
    t->shape[2] = d;
    t->total_elements = h * w * d;
    t->type = type;

    size_t data_size = 0;

    if (type == TENSOR_FLOAT32) {
        data_size = t->total_elements * sizeof(float);
        t->data.f32_data = (float*)malloc(data_size);
    } else if (type == TENSOR_INT8) {
        data_size = t->total_elements * sizeof(int8_t);
        t->data.i8_data = (int8_t*)malloc(data_size);
    }

    if (!t->data.raw_data) {
        free(t);
        return NULL;
    }

    printf("[INFO] Tensor Created (%s): %d elements, %zu Bytes allocated.\n",
           (type == TENSOR_FLOAT32 ? "FLOAT32" : "INT8"),
           t->total_elements, data_size);

    return t;
}

void free_tensor(Tensor* t) {
    if (t) {
        if (t->data.raw_data) {
            free(t->data.raw_data);
        }
        free(t);
        printf("[INFO] Tensor memory freed.\n");
    }
}

void fill_random(Tensor* t) {
    for (int i = 0; i < t->total_elements; i++) {
        if (t->type == TENSOR_FLOAT32) {
            t->data.f32_data[i] = (float)rand() / (float)(RAND_MAX);
        } else if (t->type == TENSOR_INT8) {
            t->data.i8_data[i] = (int8_t)(rand() % 256 - 128);
        }
    }
}

void print_tensor_preview(Tensor* t) {
    printf("Tensor Data (First 5): [ ");
    int limit = (t->total_elements > 5) ? 5 : t->total_elements;

    for (int i = 0; i < limit; i++) {
        if (t->type == TENSOR_FLOAT32) {
            printf("%.4f ", t->data.f32_data[i]);
        } else if (t->type == TENSOR_INT8) {
            printf("%d ", t->data.i8_data[i]);
        }
    }
    printf("... ]\n");
}
