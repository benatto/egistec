#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/slab.h>

#include "egistec0603.h"

static int __init egistec_0603_init(void)
{
	PRINT_INFO("Egistec fingerprint reader loaded\n");

	return 0;
}

static void __exit egistec_0603_exit(void){
	PRINT_INFO("Egistec fingerprint module unloaded\n");
}


static int usb_egistec0603_probe(struct usb_interface *interface, const struct usb_device_id *id){
	int vid;
	int pid;
	struct usb_egistec0603 *dev;

	/*getting udev entry to this usb device*/
	struct usb_device *udev = interface_to_usbdev(interface);

	/*getting interface USB vendor and product id's*/
	vid = le16_to_cpu(udev->descriptor.idVendor);
	pid = le16_to_cpu(udev->descriptor.idProduct);

	printk(KERN_DEBUG "egistec0603: Devices found: %d:%d\n", vid, pid);

	dev = kmalloc(sizeof(struct usb_egistec0603), GFP_KERNEL);

	if (!dev){
		printk(KERN_ERR "[egistec0603]: Not able to allocate USB device data struct, possible out of memory\n");
		return -ENOMEM;
	}
}

module_init(egistec_0603_init);
module_exit(egistec_0603_exit);
MODULE_LICENSE("GPL");
