
# Advanced Database and Systems Engineering (ADSE) - Lab Exercises

This repository contains the collection of lab exercises completed for the Advanced Database and Systems Engineering course.

---

## Lab Exercises

### Lab 1: Password Generator - Bash Script
A simple bash script to generate passwords and ensure that each password is generated only once.
- [`1_100_line_bash.sh`](./lab_1/1_100_line_bash.sh)

<img width="772" height="382" alt="Screenshot 2025-07-11 at 2 38 55 PM" src="https://github.com/user-attachments/assets/3825665d-151d-4505-a6c0-12763eedc7ae" />


### Lab 2: Inter-Process Communication (IPC)
Demonstrates IPC using a producer-consumer model with shell scripts.
- [`2_ipc_producer.sh`](./lab_2/2_ipc_producer.sh)
- [`2_ipc_consumer.sh`](./lab_2/2_ipc_consumer.sh)

<img width="1440" height="202" alt="Screenshot 2025-07-11 at 2 48 51 PM" src="https://github.com/user-attachments/assets/7c3b4895-e2da-41d1-83d8-869d3e49d2bb" />

### Lab 3: System Information in C
A C program to retrieve and display system information.
- [`3_system_info.c`](./lab_3/3_system_info.c)

<details>

<summary>Program Output</summary>

```text
===== Linux System Configuration Details =====

--- Operating System & Kernel ---
OS Name: Linux
Nodename (Hostname): lab
Kernel Release: 6.12.0-92.el10.x86_64
Kernel Version: #1 SMP PREEMPT_DYNAMIC Wed Jun  4 13:45:25 UTC 2025
Machine Arch: x86_64
Distribution: CentOS Stream 10 (Coughlan)

--- Hostname Information ---
Hostname: lab

--- User Information ---
Current User: sbalivada (UID: 1000)
User Home Directory: /home/sbalivada
User Shell: /bin/bash

--- CPU Information ---
Model Name: Intel(R) Core(TM) i3-7100 CPU @ 3.90GHz
Cores/Processors: 2
CPU Speed: 3900.049 MHz
Cache Size: 3072 KB
Bogomips: 7799.87

--- Memory Information ---
Total RAM: 7563 MB
Free RAM: 6062 MB
Available RAM: 6524 MB
Shared RAM: 24 MB
Buffer RAM: 4 MB
Total Swap: 7947 MB
Free Swap: 7947 MB
Cached:           695072 kB
Slab:             105548 kB

--- System Uptime ---
Uptime: 0 days, 07:56:45

--- Filesystem Information (Root Mount Point) ---
Mount Point: /
  Total Space: 69.94 GB
  Free Space: 65.62 GB
  Available Space (for non-root): 65.62 GB
  Used Space: 4.32 GB
  Filesystem Type ID: 58465342

--- Mounted Filesystems (from /proc/mounts) ---
Device                         Mount Point          Type            Options
------------------------------------------------------------------------------------------
/dev/mapper/cs-root            /                    xfs             rw,seclabel,relatime,attr2,inode64,logbufs=8,logbsize=32k,noquota
devtmpfs                       /dev                 devtmpfs        rw,seclabel,nosuid,size=4096k,nr_inodes=963084,mode=755,inode64
tmpfs                          /dev/shm             tmpfs           rw,seclabel,nosuid,nodev,inode64
devpts                         /dev/pts             devpts          rw,seclabel,nosuid,noexec,relatime,gid=5,mode=620,ptmxmode=000
sysfs                          /sys                 sysfs           rw,seclabel,nosuid,nodev,noexec,relatime
securityfs                     /sys/kernel/security securityfs      rw,nosuid,nodev,noexec,relatime
cgroup2                        /sys/fs/cgroup       cgroup2         rw,seclabel,nosuid,nodev,noexec,relatime,nsdelegate,memory_recursiveprot
pstore                         /sys/fs/pstore       pstore          rw,seclabel,nosuid,nodev,noexec,relatime
efivarfs                       /sys/firmware/efi/efivars efivarfs        rw,nosuid,nodev,noexec,relatime
bpf                            /sys/fs/bpf          bpf             rw,nosuid,nodev,noexec,relatime,mode=700
configfs                       /sys/kernel/config   configfs        rw,nosuid,nodev,noexec,relatime
proc                           /proc                proc            rw,nosuid,nodev,noexec,relatime
tmpfs                          /run                 tmpfs           rw,seclabel,nosuid,nodev,size=1548940k,nr_inodes=819200,mode=755,inode64
selinuxfs                      /sys/fs/selinux      selinuxfs       rw,nosuid,noexec,relatime
systemd-1                      /proc/sys/fs/binfmt_misc autofs          rw,relatime,fd=36,pgrp=1,timeout=0,minproto=5,maxproto=5,direct,pipe_ino=4923
debugfs                        /sys/kernel/debug    debugfs         rw,seclabel,nosuid,nodev,noexec,relatime
hugetlbfs                      /dev/hugepages       hugetlbfs       rw,seclabel,nosuid,nodev,relatime,pagesize=2M
tracefs                        /sys/kernel/tracing  tracefs         rw,seclabel,nosuid,nodev,noexec,relatime
mqueue                         /dev/mqueue          mqueue          rw,seclabel,nosuid,nodev,noexec,relatime
tmpfs                          /run/credentials/systemd-journald.service tmpfs           ro,seclabel,nosuid,nodev,noexec,relatime,nosymfollow,size=1024k,nr_inodes=1024,mode=700,inode64,noswap
fusectl                        /sys/fs/fuse/connections fusectl         rw,nosuid,nodev,noexec,relatime
/dev/nvme0n1p2                 /boot                xfs             rw,seclabel,relatime,attr2,inode64,logbufs=8,logbsize=32k,noquota
/dev/mapper/cs-home            /home                xfs             rw,seclabel,relatime,attr2,inode64,logbufs=8,logbsize=32k,noquota
/dev/nvme0n1p1                 /boot/efi            vfat            rw,relatime,fmask=0077,dmask=0077,codepage=437,iocharset=ascii,shortname=winnt,errors=remount-ro
binfmt_misc                    /proc/sys/fs/binfmt_misc binfmt_misc     rw,nosuid,nodev,noexec,relatime
tmpfs                          /run/user/0          tmpfs           rw,seclabel,nosuid,nodev,relatime,size=774468k,nr_inodes=193617,mode=700,inode64
tmpfs                          /run/credentials/getty@tty1.service tmpfs           ro,seclabel,nosuid,nodev,noexec,relatime,nosymfollow,size=1024k,nr_inodes=1024,mode=700,inode64,noswap
tmpfs                          /run/user/1000       tmpfs           rw,seclabel,nosuid,nodev,relatime,size=774468k,nr_inodes=193617,mode=700,uid=1000,gid=1000,inode64

--- Network Interfaces ---
0: Interface: lo
    Flags: 0x10049 (UP) (LOOPBACK) (RUNNING)
    MTU: 65536
    MAC Address: 00:00:00:00:00:00
1: Interface: enp0s31f6
    Flags: 0x11043 (UP) (BROADCAST) (MULTICAST) (RUNNING)
    MTU: 1500
    MAC Address: 14:b3:1f:14:89:32
2: Interface: wlp2s0
    Flags: 0x1002 (BROADCAST) (MULTICAST)
    MTU: 1500
    MAC Address: f8:59:71:3c:1a:09
4: Interface: lo
    Flags: 0x10049 (UP) (LOOPBACK) (RUNNING)
    MTU: 65536
    Address (IPv4): 127.0.0.1
5: Interface: enp0s31f6
    Flags: 0x11043 (UP) (BROADCAST) (MULTICAST) (RUNNING)
    MTU: 1500
    Address (IPv4): 192.168.1.21
6: Interface: tailscale0
    Flags: 0x110d1 (UP) (MULTICAST) (RUNNING)
    MTU: 1280
    Address (IPv4): 100.81.35.32
7: Interface: lo
    Flags: 0x10049 (UP) (LOOPBACK) (RUNNING)
    MTU: 65536
    Address (IPv6): ::1
8: Interface: enp0s31f6
    Flags: 0x11043 (UP) (BROADCAST) (MULTICAST) (RUNNING)
    MTU: 1500
    Address (IPv6): 2401:4900:8fcc:bfe1:16b3:1fff:fe14:8932
9: Interface: enp0s31f6
    Flags: 0x11043 (UP) (BROADCAST) (MULTICAST) (RUNNING)
    MTU: 1500
    Address (IPv6): fe80::16b3:1fff:fe14:8932%enp0s31f6
10: Interface: tailscale0
    Flags: 0x110d1 (UP) (MULTICAST) (RUNNING)
    MTU: 1280
    Address (IPv6): fd7a:115c:a1e0::3835:2320
11: Interface: tailscale0
    Flags: 0x110d1 (UP) (MULTICAST) (RUNNING)
    MTU: 1280
    Address (IPv6): fe80::36b1:4b05:2590:f035%tailscale0

--- Loaded Kernel Modules (first 20 from /proc/modules) ---
Module                         Size       Used by
------------------------------------------------------------------
hello_module                   12288      0 (users) - - Live 0x0000000000000000 (OE)
overlay                        245760     1 (users) - - Live 0x0000000000000000
xt_MASQUERADE                  16384      2 (users) - - Live 0x0000000000000000
xt_mark                        12288      2 (users) - - Live 0x0000000000000000
nft_compat                     24576      4 (users) - - Live 0x0000000000000000
binfmt_misc                    28672      1 (users) - - Live 0x0000000000000000
tun                            73728      4 (users) - - Live 0x0000000000000000
nft_fib_inet                   12288      1 (users) - - Live 0x0000000000000000
nft_fib_ipv4                   12288      1 (users) - nft_fib_inet, Live 0x0000000000000000
nft_fib_ipv6                   12288      1 (users) - nft_fib_inet, Live 0x0000000000000000
nft_fib                        12288      3 (users) - nft_fib_inet,nft_fib_ipv4,nft_fib_ipv6, Live 0x0000000000000000
nft_reject_inet                12288      10 (users) - - Live 0x0000000000000000
nf_reject_ipv4                 16384      1 (users) - nft_reject_inet, Live 0x0000000000000000
nf_reject_ipv6                 20480      1 (users) - nft_reject_inet, Live 0x0000000000000000
nft_reject                     12288      1 (users) - nft_reject_inet, Live 0x0000000000000000
nft_ct                         28672      8 (users) - - Live 0x0000000000000000
nft_chain_nat                  12288      5 (users) - - Live 0x0000000000000000
nf_nat                         69632      2 (users) - xt_MASQUERADE,nft_chain_nat, Live 0x0000000000000000
nf_conntrack                   204800     3 (users) - xt_MASQUERADE,nft_ct,nf_nat, Live 0x0000000000000000
nf_defrag_ipv6                 24576      1 (users) - nf_conntrack, Live 0x0000000000000000
... and more.

=========================================
```

</details>

### Lab 4: PostgreSQL C Architecture
A walkthrough of the architecture of postgres.c
- [writeup](./lab_4/4.md)

### Lab 5: Socket Programming (Client/Server)
A client-server application demonstrating socket programming in C.
- [`client.c`](./lab_5/client.c)
- [`server.c`](./lab_5/server.c)

<img width="1440" height="178" alt="Screenshot 2025-07-11 at 2 55 29 PM" src="https://github.com/user-attachments/assets/16acc625-3ba4-4ab3-b3d1-83248be05868" />

### Lab 6: Linux Kernel Module (Hello World)
A simple "Hello World" Linux kernel module.
- [`hello_module.c`](./lab_6/hello_module.c)
- [`Makefile`](./lab_6/Makefile)

<img width="722" height="319" alt="Screenshot 2025-07-11 at 3 19 10 PM" src="https://github.com/user-attachments/assets/811f79db-5266-4ead-b82a-031a5834265e" />

### Lab 7: Linux Kernel Module (Keylogger)
A keylogger implemented as a Linux kernel module.
- [`keylogger.c`](./lab_7/keylogger.c)
- [`Makefile`](./lab_7/Makefile)

> Could not execute as I do not have a physical system at present to generate Keyboard Interrupts. Accessing through SSH.

### Lab 8: Add tables to PostgreSQL and retrieve them using a Python script

- [`8_db_client.py`](./lab_8/8_db_client.py)
- [`8_sql_script.sql`](./lab_8/8_sql_script.sql)

<details>

<summary>Program Output</summary>

```text

--- Records from Employees ---
employee_id          | first_name           | last_name            | email                | phone_number         | hire_date            | job_id               | salary               | department_id
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1                    | John                 | Doe                  | john.doe@example.com | 123-456-7890         | 2023-01-15           | IT_PROG              | 60000.00             | 1
2                    | Jane                 | Smith                | jane.smith@example.com | 987-654-3210         | 2022-11-20           | SA_REP               | 75000.00             | 2
3                    | Peter                | Jones                | peter.jones@example.com | 555-123-4567         | 2023-03-10           | MK_MGR               | 90000.00             | 3
4                    | Mary                 | Johnson              | mary.johnson@example.com | 111-222-3333         | 2023-05-01           | HR_REP               | 55000.00             | 4
5                    | David                | Williams             | david.williams@example.com | 444-555-6666         | 2021-09-01           | FI_ACCOUNT           | 65000.00             | 5
6                    | Emily                | Brown                | emily.brown@example.com | 777-888-9999         | 2023-08-12           | AD_VP                | 120000.00            | 1
7                    | Michael              | Davis                | michael.davis@example.com | 222-333-4444         | 2020-07-18           | PU_CLERK             | 45000.00             | 2
8                    | Jessica              | Miller               | jessica.miller@example.com | 666-777-8888         | 2023-10-25           | SH_CLERK             | 40000.00             | 3
9                    | Christopher          | Wilson               | christopher.wilson@example.com | 999-000-1111         | 2022-02-14           | ST_MAN               | 80000.00             | 4
10                   | Ashley               | Taylor               | ashley.taylor@example.com | 333-444-5555         | 2023-12-01           | IT_PROG              | 62000.00             | 1



--- Records from Departments ---
department_id        | department_name      | location_id
---------------------------------------------------------------------
1                    | IT                   | 1
2                    | Sales                | 2
3                    | Marketing            | 3
4                    | Human Resources      | 4
5                    | Finance              | 5
6                    | Administration       | 1
7                    | Purchasing           | 2
8                    | Shipping             | 3
9                    | Executive            | 4
10                   | Public Relations     | 5



--- Records from Locations ---
location_id          | street_address       | postal_code          | city                 | state_province       | country_id
------------------------------------------------------------------------------------------------------------------------------------------
1                    | 123 Main St          | 12345                | New York             | NY                   | US
2                    | 456 Oak Ave          | 54321                | Los Angeles          | CA                   | US
3                    | 789 Pine St          | 98765                | London               | None                 | UK
4                    | 321 Elm St           | 10101                | Toronto              | ON                   | CA
5                    | 654 Maple Ave        | 20202                | Sydney               | NSW                  | AU
6                    | 987 Birch St         | 30303                | Paris                | None                 | FR
7                    | 111 Cedar St         | 40404                | Tokyo                | None                 | JP
8                    | 222 Spruce St        | 50505                | Berlin               | None                 | DE
9                    | 333 Willow St        | 60606                | Mumbai               | MH                   | IN
10                   | 444 Aspen St         | 70707                | Sao Paulo            | SP                   | BR



--- Records from Products ---
product_id           | product_name         | description          | price                | stock_quantity       | is_available
------------------------------------------------------------------------------------------------------------------------------------------
1                    | Laptop               | A powerful laptop for all your computing needs. | 1200.00              | 50                   | True
2                    | Smartphone           | The latest smartphone with a stunning display. | 800.00               | 100                  | True
3                    | Headphones           | Noise-cancelling headphones for an immersive audio experience. | 250.00               | 200                  | True
4                    | Keyboard             | A mechanical keyboard for a comfortable typing experience. | 100.00               | 150                  | True
5                    | Mouse                | An ergonomic mouse for precise control. | 50.00                | 300                  | True
6                    | Monitor              | A 4K monitor with vibrant colors. | 600.00               | 75                   | True
7                    | Webcam               | A high-definition webcam for clear video calls. | 80.00                | 120                  | False
8                    | Printer              | An all-in-one printer for your home or office. | 300.00               | 60                   | True
9                    | Desk Chair           | A comfortable and adjustable desk chair. | 400.00               | 40                   | True
10                   | External Hard Drive  | A portable hard drive for extra storage. | 150.00               | 250                  | True



--- Records from Orders ---
order_id             | customer_id          | order_date           | total_amount         | status
-------------------------------------------------------------------------------------------------------------------
1                    | 1                    | 2024-01-10 10:30:00  | 250.50               | Shipped
2                    | 2                    | 2024-01-12 14:00:00  | 120.00               | Delivered
3                    | 3                    | 2024-01-15 09:00:00  | 500.75               | Pending
4                    | 4                    | 2024-01-18 11:45:00  | 75.20                | Shipped
5                    | 5                    | 2024-01-20 16:20:00  | 300.00               | Processing
6                    | 1                    | 2024-01-22 13:15:00  | 150.00               | Shipped
7                    | 3                    | 2024-01-25 10:00:00  | 600.00               | Delivered
8                    | 2                    | 2024-01-28 18:00:00  | 90.50                | Pending
9                    | 4                    | 2024-02-01 12:30:00  | 400.25               | Shipped
10                   | 5                    | 2024-02-03 15:00:00  | 200.00               | Processing


Database connection closed.
```
</details>

### Lab 9: Bitmap Index Simulation
A Python script simulating a bitmap index.
- [`bitmap_simulation.py`](./lab_9/bitmap_simulation.py)
- [`explanation.md`](./lab_9/explanation.md)

<details>

<summary>Program Output</summary>

```text
--- Generated Bitmaps (1 = match, 0 = no match) ---
           product_Laptop: 0001000101
            product_Mouse: 0010010010
         product_Keyboard: 0100001000
          product_Monitor: 1000100000
             region_North: 0001000101
             region_South: 0010000010
              region_West: 1000101000
              region_East: 0100010000
  customer_segment_Retail: 0011001101
customer_segment_Enterprise: 1100110010
--------------------------------------------------

--- Query Simulation ---

Query 1: product = 'Laptop' AND region = 'North'
           product_Laptop: 0001000101
             region_North: 0001000101
             Result (AND): 0001000101

Query 2: product = 'Mouse' OR region = 'West'
            product_Mouse: 0010010010
              region_West: 1000101000
              Result (OR): 1010111010

Query 3: customer_segment = 'Enterprise' AND NOT product = 'Laptop'
customer_segment_Enterprise: 1100110010
       NOT product_Laptop: 1110111010
         Result (AND NOT): 1100110010

--- Query Results ---

Result for Query 1 (Laptop AND North):
   transaction_id product region customer_segment
0               1  Laptop  North           Retail
2               3  Laptop  North           Retail
6               7  Laptop  North           Retail

Result for Query 2 (Mouse OR West):
   transaction_id   product region customer_segment
1               2     Mouse  South       Enterprise
3               4  Keyboard   West           Retail
4               5     Mouse   East       Enterprise
5               6   Monitor   West       Enterprise
7               8     Mouse  South           Retail
9              10   Monitor   West       Enterprise

Result for Query 3 (Enterprise AND NOT Laptop):
   transaction_id   product region customer_segment
1               2     Mouse  South       Enterprise
4               5     Mouse   East       Enterprise
5               6   Monitor   West       Enterprise
8               9  Keyboard   East       Enterprise
9              10   Monitor   West       Enterprise
```
</details>

### Lab 10: Custom Page Replacement Algorithm
A Python script simulating a custom page replacement algorithm for memory management.
- [`page_replacement_simulation.py`](./lab_10/page_replacement_simulation.py)
- [`explanation.md`](./lab_10/explanation.md)

<details>

<summary>Program Output</summary>

```text
Starting simulation with 3 frames.
Reference String: [1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5]

Accessing page: 1	Page Fault! Replacing page None in Frame 0
Frames:       [1, None, None]
Ref Bits:     [1, 0, 0]
Clock Hand -> Frame 1
----------------------------------------
Accessing page: 2	Page Fault! Replacing page None in Frame 1
Frames:       [1, 2, None]
Ref Bits:     [1, 1, 0]
Clock Hand -> Frame 2
----------------------------------------
Accessing page: 3	Page Fault! Replacing page None in Frame 2
Frames:       [1, 2, 3]
Ref Bits:     [1, 1, 1]
Clock Hand -> Frame 0
----------------------------------------
Accessing page: 4	Page Fault! Replacing page 1 in Frame 0
Frames:       [4, 2, 3]
Ref Bits:     [1, 0, 0]
Clock Hand -> Frame 1
----------------------------------------
Accessing page: 1	Page Fault! Replacing page 2 in Frame 1
Frames:       [4, 1, 3]
Ref Bits:     [1, 1, 0]
Clock Hand -> Frame 2
----------------------------------------
Accessing page: 2	Page Fault! Replacing page 3 in Frame 2
Frames:       [4, 1, 2]
Ref Bits:     [1, 1, 1]
Clock Hand -> Frame 0
----------------------------------------
Accessing page: 5	Page Fault! Replacing page 4 in Frame 0
Frames:       [5, 1, 2]
Ref Bits:     [1, 0, 0]
Clock Hand -> Frame 1
----------------------------------------
Accessing page: 1	Hit! (Frame 1)
Frames:       [5, 1, 2]
Ref Bits:     [1, 1, 0]
Clock Hand -> Frame 1
----------------------------------------
Accessing page: 2	Hit! (Frame 2)
Frames:       [5, 1, 2]
Ref Bits:     [1, 1, 1]
Clock Hand -> Frame 1
----------------------------------------
Accessing page: 3	Page Fault! Replacing page 1 in Frame 1
Frames:       [5, 3, 2]
Ref Bits:     [0, 1, 0]
Clock Hand -> Frame 2
----------------------------------------
Accessing page: 4	Page Fault! Replacing page 2 in Frame 2
Frames:       [5, 3, 4]
Ref Bits:     [0, 1, 1]
Clock Hand -> Frame 0
----------------------------------------
Accessing page: 5	Hit! (Frame 0)
Frames:       [5, 3, 4]
Ref Bits:     [1, 1, 1]
Clock Hand -> Frame 0
----------------------------------------

--- Simulation Summary ---
Total Accesses: 12
Page Hits:      3
Page Faults:    9
Hit Ratio:      25.00%
```
  
</details>

---
