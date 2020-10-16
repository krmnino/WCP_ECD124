#include <stdio.h>

#include "Pin.h"

typedef struct PinArray{
    Pin* arr;
    size_t size;  
} PinArray;

PinArray* init_arr(size_t size_){
    PinArray* pin_array = (PinArray*)malloc(sizeof(PinArray));
    pin_array->size = size_;
    pin_array->arr = (Pin*)malloc(sizeof(Pin) * size_);
    if(pin_array->arr == NULL){
        printf("Error allocating space.");
        return NULL;
    }
    for(int i = 0; i < size_; i++){
        init_pin(&pin_array->arr[i], i, 0.0);
    }
    return pin_array;
}

//Sort pins by duty cycles using insertion sort
void sort_duty_cycles(PinArray* pin_array){
    Pin* temp = create_pin(0, 0.5);
    for(int i = 0; i < pin_array->size; i++){
        for(int j = 0; j < pin_array->size; j++){
            if(pin_array->arr[j].duty_cycle < pin_array->arr[j - 1].duty_cycle){
                temp = &pin_array->arr[j];
                pin_array->arr[j] = pin_array->arr[j - 1];
                pin_array->arr[j - 1] = *temp;
            }
        }
    }
    free(temp);
}

void print_arr(PinArray* pin_array){
    for(int i = 0; i < pin_array->size; i++){
        print_pin(&pin_array->arr[i]);
    }
}