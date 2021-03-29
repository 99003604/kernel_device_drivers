#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
int __init init_module(void)
{
  printk("hello world \n");
  return 0;
}

void __exit cleanup_module(void)
{
  printk("bye bye \n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MADURA");
MODULE_DESCRIPTION("A SIMPLE MODULE");
