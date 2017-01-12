nclude <stdio.h>
#include <stdlib.h>

int add = 0; //dummy add to make ptr unaligned.

void *
amalloc(int size)
{
        int  align = sizeof(int);

        /* extra memory for align size  + sizeof ptr */
        size_t extra = align + sizeof(size_t);

        size_t total_size = size + extra;

        void *orig;
        void *ptr = malloc(total_size);
        if (ptr == NULL) {
                return NULL;
        }
        orig = ptr;

        ptr = ptr+add;

        size_t offset = (size_t)ptr + align + sizeof(size_t);

        void *ptr1 = (void *)(offset - (offset%align));

        *((void **)ptr1-1) = orig;

        return ptr1;
}

void
afree(void *ptr)
{
        /* extract the orignal allocated memory */
        void **ptr1 = ptr;
        if (ptr == NULL) {
                return;
        }
        void *f = *((void **)ptr1-1);
        free(f);
        return;
}

int
main()
{
        void *ptr = amalloc(1024);
        printf("Got Aligned Address allocated %p \n", ptr);
        afree(ptr);
}
