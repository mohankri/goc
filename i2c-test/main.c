#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include "./i2c.h"

i2c_dev_t i2c_node[] = {
    {.dev_name="i2c-0", .read = i2c_read, .write = i2c_write },
    {.dev_name="i2c-1", .read = i2c_read, .write = i2c_write },
    {.dev_name="i2c-2", .read = dac_read, .write = dac_write },
    {.dev_name="i2c-3", .read = dac_read, .write = dac_write }
};

void probe_i2c()
{
    for (int i = 0; i < sizeof(i2c_node)/sizeof(i2c_node[0]); i++) {
        i2c_node[i].read(i2c_node[i].dev_name);
        i2c_node[i].write(i2c_node[i].dev_name);
    }
}

int
main()
{
	probe_i2c();
}
