#include <stdlib.h>
#include <stdio.h>

void* aligned_malloc(size_t size, size_t align)
{
    void* p1 = NULL; // original block
    void** p2; // aligned block
    int offset = align - 1 + sizeof(void*);
    if ((p1 = (void*)malloc(size + offset)) == NULL)
    {
       return NULL;
    }
    p2 = (void**)(((size_t)(p1) + offset) & ~(align) - 1);
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *ptr)
{
    free(((void**)ptr)[-1]);
}

