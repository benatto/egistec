#define PRINT_INFO(s) printk(KERN_INFO "%s", s);
#define VENDOR_ID 1c7e
#define PRODUCT_ID 0603

/*Probe function to test USB device*/
static int usb_egistec0603_probe(struct usb_interface*, const struct usb_device_id*);

struct usb_egistec0603{
	struct input_dev *udev;
	struct usb_interface *interface;

	size_t bulk_in_size;
	__u8   bulk_in_endpointaddr;
	__u8   bulk_out_endpointaddr;

	int errors;
	int open_count; /*count of openers*/	
	spinlock_t err_lock; /*error lock*/
	struct kref kref; /*record the opened times*/
	struct mutex io_mutex; /*mutex to sync I/O with disconnect*/

	struct mutex SCSI_mutex
};


static struct usb_driver usb_egistec0603_driver = {
	.name = "egistec0603",
};
