#include <linux/kernel.h>
#include "egistec0603.h"


/*Read function
 * param1: file to be read
 * param2: buffer
 * param3: count
 * param4: offset*/
static ssize_t egistec_read(struct file*, char*, size_t, loff_t);

/*Egistec fingerprint reader file operations struct*/
const struct file_operations egistec_fops = {
		.owner = THIS_MODULE,

		.read = egistec_read,
		.write = egistec_write,
		
		.compat_ioctl = egistec_ctl,

		.open = egistec_open,
		.release = egistec_release,
		.flush = egistec_flush,

		.fasync = egistec_fasync
};
