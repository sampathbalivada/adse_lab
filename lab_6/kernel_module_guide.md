## How to Compile and Run the Kernel Module

**Prerequisites:** You need to have the kernel headers installed to compile the module. On Debian-based systems (like Ubuntu), you can install them with:

```bash
sudo apt-get install linux-headers-$(uname -r)
```

### 1. Compile the Module

Open a terminal in the directory containing `hello_module.c` and `Makefile`. Run the `make` command to compile the module. This will create a file named `hello_module.ko`.

```bash
make
```

### 2. Insert the Module

Use the `insmod` command to insert the module into the kernel. You will need root privileges.

```bash
sudo insmod hello_module.ko
```

### 3. Check Kernel Messages

Use the `dmesg` command to view the kernel log buffer. You should see the "Hello, World!" message from your module.

```bash
dmesg
```

Look for a line similar to this at the end of the output:

```
[timestamp] Hello, World!
```

### 4. Remove the Module

Use the `rmmod` command to remove the module from the kernel. You will need root privileges.

```bash
sudo rmmod hello_module
```

If you run `dmesg` again, you will see the "Goodbye, World!" message.
