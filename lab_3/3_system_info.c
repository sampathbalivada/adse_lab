#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h> // For uname
#include <sys/sysinfo.h> // For sysinfo
#include <sys/statvfs.h> // For statvfs
#include <pwd.h>         // For getpwuid
#include <ifaddrs.h>     // For getifaddrs
#include <netinet/in.h>  // For sockaddr_in
#include <arpa/inet.h>   // For inet_ntop
#include <sys/socket.h>  // For AF_INET, AF_INET6
#include <netdb.h>       // For getnameinfo, NI_MAXHOST, etc.
#include <net/if.h>      // For IFF_UP
#include <linux/if_link.h> // For RTMGRP_LINK
#include <linux/if_packet.h> // For struct sockaddr_ll
#include <dirent.h>      // For opendir, readdir, closedir
#include <ctype.h>       // For isdigit

#define MAX_LINE_LEN 256
#define HOSTNAME_MAX_LEN 256

// Helper function to read a specific line from a file
// Returns 1 on success, 0 on failure
int get_line_from_file(const char *filepath, const char *search_key, char *buffer, size_t buffer_size) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        // perror_msg is not a standard function, using perror
        // perror_msg("Error opening file", filepath); 
        // Simplified error handling for this context
        return 0; 
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, search_key) != NULL) {
            strncpy(buffer, line, buffer_size - 1);
            buffer[buffer_size - 1] = '\0'; // Ensure null termination
            // Remove trailing newline if present
            char *newline = strchr(buffer, '\n');
            if (newline) *newline = '\0';
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0; // Key not found
}

// Function to print OS and Kernel Information
void print_os_info() {
    printf("\n--- Operating System & Kernel ---\n");
    struct utsname uts;
    if (uname(&uts) == -1) {
        perror("uname error");
        return;
    }
    printf("OS Name: %s\n", uts.sysname);
    printf("Nodename (Hostname): %s\n", uts.nodename);
    printf("Kernel Release: %s\n", uts.release);
    printf("Kernel Version: %s\n", uts.version);
    printf("Machine Arch: %s\n", uts.machine);

    // Distribution information (more complex, often requires parsing /etc/os-release)
    char os_release_line[MAX_LINE_LEN];
    if (get_line_from_file("/etc/os-release", "PRETTY_NAME=", os_release_line, sizeof(os_release_line))) {
        char *distro_name = strchr(os_release_line, '=');
        if (distro_name != NULL) {
            distro_name++; // Move past '='
            // Remove quotes if present
            if (distro_name[0] == '"') {
                distro_name++;
                char *last_quote = strrchr(distro_name, '"');
                if (last_quote) *last_quote = '\0';
            }
            printf("Distribution: %s\n", distro_name);
        }
    } else {
        printf("Distribution: Could not determine (requires parsing /etc/os-release)\n");
    }
}

// Function to print CPU Information
void print_cpu_info() {
    printf("\n--- CPU Information ---\n");
    FILE *cpuinfo_fp = fopen("/proc/cpuinfo", "r");
    if (cpuinfo_fp == NULL) {
        perror("Error opening /proc/cpuinfo");
        return;
    }

    char line[MAX_LINE_LEN];
    char model_name[MAX_LINE_LEN] = "N/A";
    int processor_count = 0;
    char cpu_mhz[MAX_LINE_LEN] = "N/A";
    char cache_size[MAX_LINE_LEN] = "N/A";
    char bogomips[MAX_LINE_LEN] = "N/A";

    while (fgets(line, sizeof(line), cpuinfo_fp) != NULL) {
        if (strncmp(line, "model name", 10) == 0) {
            char *colon = strchr(line, ':');
            if (colon != NULL && strlen(colon) > 2) {
                strncpy(model_name, colon + 2, sizeof(model_name) - 1); // +2 to skip ": "
                model_name[strlen(model_name) -1] = '\0'; // Remove newline
            }
        } else if (strncmp(line, "processor", 9) == 0) {
            processor_count++;
        } else if (strncmp(line, "cpu MHz", 7) == 0) {
             char *colon = strchr(line, ':');
            if (colon != NULL && strlen(colon) > 2) {
                strncpy(cpu_mhz, colon + 2, sizeof(cpu_mhz) -1);
                cpu_mhz[strlen(cpu_mhz)-1] = '\0';
            }
        } else if (strncmp(line, "cache size", 10) == 0) {
             char *colon = strchr(line, ':');
            if (colon != NULL && strlen(colon) > 2) {
                strncpy(cache_size, colon + 2, sizeof(cache_size) -1);
                cache_size[strlen(cache_size)-1] = '\0';
            }
        } else if (strncmp(line, "bogomips", 8) == 0) {
             char *colon = strchr(line, ':');
            if (colon != NULL && strlen(colon) > 2) {
                strncpy(bogomips, colon + 2, sizeof(bogomips) -1);
                bogomips[strlen(bogomips)-1] = '\0';
            }
        }
    }
    fclose(cpuinfo_fp);

    printf("Model Name: %s\n", model_name);
    printf("Cores/Processors: %d\n", processor_count);
    printf("CPU Speed: %s MHz\n", cpu_mhz);
    printf("Cache Size: %s\n", cache_size);
    printf("Bogomips: %s\n", bogomips);
}

// Function to print Memory Information
void print_memory_info() {
    printf("\n--- Memory Information ---\n");
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo error");
        return;
    }

    unsigned long long total_ram_mb = info.totalram * info.mem_unit / (1024 * 1024);
    unsigned long long free_ram_mb = info.freeram * info.mem_unit / (1024 * 1024);
    unsigned long long shared_ram_mb = info.sharedram * info.mem_unit / (1024 * 1024);
    unsigned long long buffer_ram_mb = info.bufferram * info.mem_unit / (1024 * 1024);
    unsigned long long total_swap_mb = info.totalswap * info.mem_unit / (1024 * 1024);
    unsigned long long free_swap_mb = info.freeswap * info.mem_unit / (1024 * 1024);

    printf("Total RAM: %llu MB\n", total_ram_mb);
    printf("Free RAM: %llu MB\n", free_ram_mb);
    // For "Available" memory, /proc/meminfo is more accurate
    char mem_available_line[MAX_LINE_LEN];
    if (get_line_from_file("/proc/meminfo", "MemAvailable:", mem_available_line, sizeof(mem_available_line))) {
        unsigned long mem_available_kb;
        if (sscanf(mem_available_line, "MemAvailable: %lu kB", &mem_available_kb) == 1) {
            printf("Available RAM: %lu MB\n", mem_available_kb / 1024);
        }
    }

    printf("Shared RAM: %llu MB\n", shared_ram_mb);
    printf("Buffer RAM: %llu MB\n", buffer_ram_mb);
    printf("Total Swap: %llu MB\n", total_swap_mb);
    printf("Free Swap: %llu MB\n", free_swap_mb);
    
    // Additional details from /proc/meminfo
    char line_buffer[MAX_LINE_LEN];
    if (get_line_from_file("/proc/meminfo", "Cached:", line_buffer, sizeof(line_buffer))) printf("%s\n", line_buffer);
    if (get_line_from_file("/proc/meminfo", "Slab:", line_buffer, sizeof(line_buffer))) printf("%s\n", line_buffer);

}

// Function to print Filesystem Information
void print_filesystem_info() {
    printf("\n--- Filesystem Information (Root Mount Point) ---\n");
    struct statvfs stat;
    if (statvfs("/", &stat) == -1) {
        perror("statvfs error for /");
        return;
    }

    unsigned long long block_size = stat.f_bsize;
    unsigned long long total_space_bytes = stat.f_blocks * block_size;
    unsigned long long free_space_bytes = stat.f_bfree * block_size;
    unsigned long long available_space_bytes = stat.f_bavail * block_size;
    unsigned long long used_space_bytes = total_space_bytes - free_space_bytes;

    printf("Mount Point: /\n");
    printf("  Total Space: %.2f GB\n", (double)total_space_bytes / (1024 * 1024 * 1024));
    printf("  Free Space: %.2f GB\n", (double)free_space_bytes / (1024 * 1024 * 1024));
    printf("  Available Space (for non-root): %.2f GB\n", (double)available_space_bytes / (1024 * 1024 * 1024));
    printf("  Used Space: %.2f GB\n", (double)used_space_bytes / (1024 * 1024 * 1024));
    printf("  Filesystem Type ID: %lx\n", stat.f_type); // May need to map to string
    
    // Listing all mounted filesystems (simplified from /proc/mounts)
    printf("\n--- Mounted Filesystems (from /proc/mounts) ---\n");
    FILE *mounts_fp = fopen("/proc/mounts", "r");
    if (mounts_fp == NULL) {
        perror("Error opening /proc/mounts");
    } else {
        char line[MAX_LINE_LEN * 2]; // Mount lines can be long
        printf("%-30s %-20s %-15s %s\n", "Device", "Mount Point", "Type", "Options");
        printf("------------------------------------------------------------------------------------------\n");
        while (fgets(line, sizeof(line), mounts_fp) != NULL) {
            char device[MAX_LINE_LEN], mount_point[MAX_LINE_LEN], type[MAX_LINE_LEN], options[MAX_LINE_LEN];
            if (sscanf(line, "%s %s %s %s %*d %*d", device, mount_point, type, options) == 4) {
                 printf("%-30s %-20s %-15s %s\n", device, mount_point, type, options);
            }
        }
        fclose(mounts_fp);
    }
}

// Function to print User Information
void print_user_info() {
    printf("\n--- User Information ---\n");
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (pw) {
        printf("Current User: %s (UID: %d)\n", pw->pw_name, uid);
        printf("User Home Directory: %s\n", pw->pw_dir);
        printf("User Shell: %s\n", pw->pw_shell);
    } else {
        printf("Current User UID: %d (Could not get username)\n", uid);
    }
}

// Function to print Hostname
void print_host_info() {
    printf("\n--- Hostname Information ---\n");
    char hostname[HOSTNAME_MAX_LEN];
    if (gethostname(hostname, HOSTNAME_MAX_LEN) == -1) {
        perror("gethostname error");
        strncpy(hostname, "N/A", HOSTNAME_MAX_LEN);
    }
    printf("Hostname: %s\n", hostname);
}

// Function to print Network Information
void print_network_info() {
    printf("\n--- Network Interfaces ---\n");
    struct ifaddrs *ifaddr, *ifa;
    int family, n;
    char host[NI_MAXHOST];
    unsigned char *mac_addr;


    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }

    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        printf("%d: Interface: %s\n", n, ifa->ifa_name);
        printf("    Flags: 0x%x ", ifa->ifa_flags);
        if (ifa->ifa_flags & IFF_UP) printf("(UP) ");
        if (ifa->ifa_flags & IFF_BROADCAST) printf("(BROADCAST) ");
        if (ifa->ifa_flags & IFF_LOOPBACK) printf("(LOOPBACK) ");
        if (ifa->ifa_flags & IFF_MULTICAST) printf("(MULTICAST) ");
        if (ifa->ifa_flags & IFF_RUNNING) printf("(RUNNING) ");
        printf("\n");
        
        printf("    MTU: ");
        // Reading MTU from /sys/class/net/<interface>/mtu
        char mtu_path[MAX_LINE_LEN];
        snprintf(mtu_path, sizeof(mtu_path), "/sys/class/net/%s/mtu", ifa->ifa_name);
        FILE *mtu_file = fopen(mtu_path, "r");
        if (mtu_file) {
            int mtu_val;
            if (fscanf(mtu_file, "%d", &mtu_val) == 1) {
                printf("%d\n", mtu_val);
            } else {
                printf("N/A\n");
            }
            fclose(mtu_file);
        } else {
            printf("N/A\n");
        }


        if (family == AF_INET || family == AF_INET6) {
            int s = getnameinfo(ifa->ifa_addr,
                               (family == AF_INET) ? sizeof(struct sockaddr_in) :
                                                     sizeof(struct sockaddr_in6),
                               host, NI_MAXHOST,
                               NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("    getnameinfo() failed: %s\n", gai_strerror(s));
            } else {
                printf("    Address (%s): %s\n", (family == AF_INET) ? "IPv4" : "IPv6", host);
            }
        } else if (family == AF_PACKET && ifa->ifa_data != NULL) {
             struct sockaddr_ll *sll = (struct sockaddr_ll *)ifa->ifa_addr;
             mac_addr = sll->sll_addr;
             printf("    MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n",
                    mac_addr[0], mac_addr[1], mac_addr[2],
                    mac_addr[3], mac_addr[4], mac_addr[5]);
        }
    }

    freeifaddrs(ifaddr);
}

// Function to print System Uptime
void print_uptime_info() {
    printf("\n--- System Uptime ---\n");
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo error for uptime");
        return;
    }
    long uptime_seconds = info.uptime;
    long days = uptime_seconds / (24 * 3600);
    uptime_seconds %= (24 * 3600);
    long hours = uptime_seconds / 3600;
    uptime_seconds %= 3600;
    long minutes = uptime_seconds / 60;
    long seconds = uptime_seconds % 60;

    printf("Uptime: %ld days, %02ld:%02ld:%02ld\n", days, hours, minutes, seconds);
}

// Function to print loaded kernel modules
void print_kernel_modules() {
    printf("\n--- Loaded Kernel Modules (first 20 from /proc/modules) ---\n");
    FILE *modules_fp = fopen("/proc/modules", "r");
    if (modules_fp == NULL) {
        perror("Error opening /proc/modules");
        return;
    }
    char line[MAX_LINE_LEN];
    int count = 0;
    printf("%-30s %-10s %s\n", "Module", "Size", "Used by");
    printf("------------------------------------------------------------------\n");
    while (fgets(line, sizeof(line), modules_fp) != NULL && count < 20) {
        char module_name[MAX_LINE_LEN], size_str[MAX_LINE_LEN], used_by_count_str[MAX_LINE_LEN], dependencies[MAX_LINE_LEN], state[MAX_LINE_LEN];
        // Format of /proc/modules: module_name size used_by_count dependencies state memory_address
        // We are interested in the first few fields.
        if (sscanf(line, "%s %s %s", module_name, size_str, used_by_count_str) >= 2) { // dependencies can be tricky
            // For dependencies, it might be '-' or a list. We'll simplify or show the count.
            char *deps_start = strchr(line, '['); // Check for actual dependencies list
            char *dash_dep = strchr(line, '-'); // Check for '-' indicating no direct users but possibly dependencies
            
            char used_by_display[MAX_LINE_LEN] = "";

            // Attempt to parse dependencies/users more carefully
            // Skip module name, size, used_by count
            char *current_pos = line;
            int fields_to_skip = 3;
            for(int i=0; i<fields_to_skip; ++i) {
                while(*current_pos != '\0' && !isspace(*current_pos)) current_pos++; // skip non-space
                while(*current_pos != '\0' && isspace(*current_pos)) current_pos++;  // skip space
            }
            
            // What remains *should* be dependencies, state, address
            // We'll just grab a portion for "Used by" or "Dependencies"
            if (*current_pos != '\0') {
                char *newline = strchr(current_pos, '\n');
                if (newline) *newline = '\0'; // Remove newline
                // Further parsing for actual "Used by" names is complex from this line alone.
                // The third field is count of modules using this one.
                // The fourth field lists modules this one depends on.
                // We'll display used_by_count and a snippet of the rest.
                snprintf(used_by_display, sizeof(used_by_display), "%s (users) - %s", used_by_count_str, current_pos);
            } else {
                 snprintf(used_by_display, sizeof(used_by_display), "%s (users)", used_by_count_str);
            }


            printf("%-30s %-10s %s\n", module_name, size_str, used_by_display);
        }
        count++;
    }
    if (count == 20) {
        printf("... and more.\n");
    }
    fclose(modules_fp);
}


int main() {
    printf("===== Linux System Configuration Details =====\n");

    print_os_info();
    print_host_info();
    print_user_info();
    print_cpu_info();
    print_memory_info();
    print_uptime_info();
    print_filesystem_info(); // Includes root and all mounts
    print_network_info();
    print_kernel_modules();

    printf("\n=========================================\n");
    return 0;
}
