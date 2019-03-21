#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include "./i2c.h"

#define	I2C_DEV_PATH "/sys/bus/i2c/devices/"

int dac_read(char *name) 
{
    printf("%s %s \n", __func__, name);
    return 0;
}

int dac_write(char *name) 
{
    printf("%s %s \n", __func__, name);
    return 0;
}
