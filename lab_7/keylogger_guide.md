## How to Compile and Use the Keylogger Kernel Module

**DISCLAIMER:** This is for educational purposes only. Keyloggers can be used for malicious activities and may be illegal. Only run this on systems you own and have explicit permission to monitor.

**Prerequisites:** You need to have the kernel headers installed. On Debian-based systems (like Ubuntu), you can install them with:

```bash
sudo apt-get install linux-headers-$(uname -r)
```

### 1. Compile the Module

Open a terminal in the `lab_7` directory. Run `make` to compile the module. This will create a file named `keylogger.ko`.

```bash
make
```

### 2. Insert the Module

Use `insmod` to insert the module into the kernel. You will need root privileges.

```bash
sudo insmod keylogger.ko
```

### 3. Test the Keylogger

Now, type anything on your keyboard. For example, open a text editor or a web browser and type a dummy password.

### 4. Check Kernel Messages

Use `dmesg` to view the kernel log. You will see the keycodes of the keys you pressed.

```bash
dmesg | grep 'Keylogger: keycode'
```

This will show you output like:

```
[timestamp] Keylogger: keycode 30
[timestamp] Keylogger: keycode 48
[timestamp] Keylogger: keycode 25
...
```

*Note: This basic keylogger captures keycodes, not characters. You would need a mapping table to translate these codes into 'a', 'b', 'p', etc.* 

### 5. Remove the Module

When you are finished, remove the module using `rmmod`. You will need root privileges.

```bash
sudo rmmod keylogger
```
