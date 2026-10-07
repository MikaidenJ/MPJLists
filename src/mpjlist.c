//
//  mpjlist.c
//  ListImplementationProject
//
//  Created by Mikaiden Jarrell on 10/7/26.
//

#include "mpjlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


list_t mpjlist_create_intlist(int length, int size) {
    
    
    void* array;
    array = malloc(length * size);
    
    for (int i = 0; i < length; i++) {
        
        printf("Enter number at position %d:", i);
        scanf("%d", &((int*)array)[i]);
        
    }
    
    list_t newList = {.array = array, .length = length, .size = size};
    
    return newList;
    
}

void mpjlist_print_list(list_t list) {
    
    int* intArray = (int*)list.array;
    
    printf("{");
    
    for (int i = 0; i < list.length; i++) {
        
        printf("%d", intArray[i]);
        
        if (i != list.length - 1) {
            
            printf(", ");
            
        }
        
    }
    
    printf("}\n");
    
}

void mpjlist_add_list(list_t* list, void* newValue) {
    
    void* newArray = malloc((list->length + 1) * list->size);
    
    
    for (int i = 0; i < list->length; i++) {
        
        memcpy((char*)newArray + (i * list->size), (char*)list->array + (i * list->size), list->size);
        
    }
    
    memcpy((char*)newArray + (list->length * list->size), newValue, list->size);
    
    free(list->array);

    list->array = newArray;
    list->length++;
    
}

void mpjlist_removelast_list(list_t *list) {
    
    if (list->length <= 0) return;
    
    void* newArray = malloc((list->length - 1) * list->size);
    
    for (int i = 0; i < list->length - 1; i++) {
        
        memcpy((char*)newArray + (i * list->size), (char*)list->array + (i * list->size), list->size);
        
    }
    
    free(list->array);
    
    list->array = newArray;
    list->length--;
    
}

void mpjlist_removeat_list(list_t *list, int index) {
    
    if (list->length <= 0) return;
    
    void* newArray = malloc((list->length - 1) * list->size);
    
    int newIndex = 0;
    
    for (int i = 0; i < list->length; i++) {
        
        if (i == index) continue;
        memcpy((char*)newArray + (newIndex * list->size), (char*)list->array + (i * list->size), list->size);
        newIndex++;
    }
    
    free(list->array);
    list->array = newArray;
    list->length--;
    
}

list_t mpjlist_copy_list(list_t *list) {
    
    void* newArray = malloc(list->length * list->size);
    
    for (int i = 0; i < list->length; i++) {
        
        memcpy((char*)newArray + (i * list->size), (char*)list->array + (i * list->size), list->size);
        
    }
    
    list_t newList = {.array = newArray, .length = list->length, .size = list->size};
    
    return newList;
    
}

list_t mpjlist_concatenate_list(list_t *list1, list_t *list2) {
    
    if (list1->size != list2->size) {
        list_t nullList = {.size = 0, .length = 0, .array = NULL};
        return nullList;
    }
    
    int newLength = list1->length + list2->length;
    
    void* newArray = malloc(newLength * list1->size);
    
    int i = 0;
    
    for (;i < list1->length; i++) {
        
        memcpy((char*)newArray + (i * list1->size), (char*)list1->array + (i * list1->size), list1->size);
        
    }
    
    for (int j = 0; j < list2->length; i++, j++) {
        
        memcpy((char*)newArray + (i * list2->size), (char*)list2->array + (j * list2->size), list2->size);
        
    }
    
    list_t newList = {.array = newArray, .length = newLength, .size = list1->size};
    
    return newList;
    
}

void mpjlist_insert_list(list_t *list, int index, void* newValue) {
    
    void* newArray = malloc((list->length + 1) * list->size);
    
    int j = 0;
    
    for (int i = 0; i < list->length + 1; i++) {
        
        if (i != index) {
            
            memcpy((char*)newArray + (i * list->size), (char*)list->array + (j * list->size), list->size);
            j++;
        } else {
            
            memcpy((char*)newArray + (i * list->size), newValue, list->size);

            
        }
        
    }
    
    free(list->array);
    list->array = newArray;
    list->length++;
    
}

int mpjlist_contains_list(list_t list, void* value) {
    
    for (int i = 0; i < list.length; i++) {
        
        if (!memcmp((char*)list.array + (i * list.size), value, list.size)) {
            
            return 1;
            
        }
        
    }
    
    return 0;
    
}

int mpjlist_getindex_list(list_t list, void* value) {
    
    
    for (int i = 0; i < list.length; i++) {
        
        if (!memcmp((char*)list.array + (i * list.size), value, list.size)) {
            
            return i;
            
        }
        
    }
    
    return -1;
    
}

int getIntLastListIndex(list_t list, void* value) {
    
    int lastIndex = -1;
    
    for (int i = 0; i < list.length; i++) {
        
        if (!memcmp((char*)list.array + (i * list.size), value, list.size)) {
            
            lastIndex = i;
            
        }
        
    }
    
    return lastIndex;
}
    

void mpjlist_Remove_list(list_t *list, void* value) {
    
    if(!mpjlist_contains_list(*list, value)) return;
    
    int index = mpjlist_getindex_list(*list, value);
    
    if (index == -1) return;
    
    mpjlist_removeat_list(list, index);
    
}

void mpjlist_Free_list(list_t *list) {
    
    free(list->array);
    
}
