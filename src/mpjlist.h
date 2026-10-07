//
//  mpjlist.h
//  ListImplementationProject
//
//  Created by Mikaiden Jarrell on 10/7/26.
//

#ifndef MPJLIST_H
#define MPJLIST_H

typedef struct {
    
    void* array;
    int length;
    int size;
    
} list_t;

list_t mpjlist_create_intlist(int length, int size);
void mpjlist_print_list(list_t list);
void mpjlist_add_list(list_t* list, void* newValue);
void mpjlist_removelast_list(list_t *list);
void mpjlist_removeat_list(list_t *list, int index);
list_t mpjlist_concatenate_list(list_t *list1, list_t *list2);
list_t mpjlist_copy_list(list_t *list);
void mpjlist_insert_list(list_t *list, int index, void* newValue);
int mpjlist_contains_list(list_t list, void* value);
int mpjlist_getindex_list(list_t list, void* value);
void mpjlist_Remove_list(list_t *list, void* value);
void mpjlist_Free_list(list_t *list);
#endif
