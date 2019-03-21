#include <stdio.h>
#include "./i2c.h"

int i2c_read(char *name) 
{
    printf("%s %s \n", __func__, name);
    return 0;
}

int
i2c_write(char *name) 
{
    printf("%s %s \n", __func__, name);
    return 0;
}
