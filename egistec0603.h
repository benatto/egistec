#define PRINT_INFO(s) printk(KERN_INFO "%s", s);
#define VENDOR_ID 1c7e
#define PRODUCT_ID 0603

/*Probe function to test USB device*/
static int usb_egistec0603_probe(struct usb_interface*, const struct usb_device_id*);

struct usb_egistec0603{
	struct input_dev *dev;
};


static struct usb_driver usb_egistec0603_driver = {
	.name = "egistec0603",
};
