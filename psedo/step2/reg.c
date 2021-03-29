#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>

dev_t pdevid;
struct cdev cdev;
int ndevices=1;


int pseudo_open(struct inode* inode , struct file* file)

{

	printk("Pseudo--open method\n");
	return 0;
}

int pseudo_close(struct inode* inode , struct file* file)
{

      printk("Pseudo--release method\n");
      return 0;
}
ssize_t pseudo_read(struct file * file, char __user * buf , size_t size, loff_t * off)
{
	printk("Pseudo--read method\n");
	return 0;
}
ssize_t pseudo_write(struct file * file, const char __user * buf , size_t size, loff_t * off)
{
	printk("Pseudo--write method\n");
	return -ENOSPC;
}

struct file_operations fops = {
      .open = pseudo_open,
      .release = pseudo_close,
      .write = pseudo_write,
      .read = pseudo_read
};

static int __init pseudo_init(void)
{
 int ret,i=0;
 ret=alloc_chrdev_region(&pdevid, 0, ndevices, "pseudo_sample");
 if(ret) {
   printk("Pseudo: Failed to register driver\n");
   return -EINVAL;
}
  printk("Successfully registered,major=%d,minor=%d\n",MAJOR(pdevid), MINOR(pdevid));
  printk("Pseudo Driver Sample..welcome\n");
  cdev_init(&cdev, &fops);
  kobject_set_name(&cdev.kobj,"pdevice%d",i);
  ret = cdev_add(&cdev, pdevid, 1);
 return 0;
}
static void __exit pseudo_exit(void) {
	unregister_chrdev_region(pdevid, ndevices);
  	printk("Pseudo Driver Sample..Bye\n");
  	cdev_del(&cdev);
}
module_init(pseudo_init);
module_exit(pseudo_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("A Hello, World Module");
