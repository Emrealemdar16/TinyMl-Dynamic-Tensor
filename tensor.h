#ifndef TENSOR_H
#define TENSOR_H

#include <stdint.h>

typedef enum {
    TENSOR_FLOAT32,
    TENSOR_INT8
} TensorType;

typedef union {
    float* f32_data;
    int8_t* i8_data;
    void* raw_data;
} TensorData;

typedef struct {
    int shape[3];
    int total_elements;
    TensorType type;
    TensorData data;
} Tensor;

// Function Prototypes
Tensor* create_tensor(int h, int w, int d, TensorType type);
void free_tensor(Tensor* t);
void fill_random(Tensor* t);
void print_tensor_preview(Tensor* t);

#endif
