#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
int ndevice=1;
module_param(ndevice,int,S_IRUGO);
static int __init pdemo_init(void) {
	printk("Hello World..Welcome\n");
	return 0;
}
static void __exit pdemo_exit(void){
	printk("Bye,Leaving the world\n");
}
module_init(pdemo_init);
module_exit(pdemo_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("Parameter demo Module");

