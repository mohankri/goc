#ifndef I2C_H_INCLUDE

#define I2C_H_INCLUDE

#include <stdio.h>

typedef struct i2c_dev {
	char dev_name[PATH_MAX];
        int (*read)(char *);
        int (*write)(char *);
} i2c_dev_t;

int i2c_read(char *);
int i2c_write(char *);
int dac_read(char *);
int dac_write(char *);

#endif
