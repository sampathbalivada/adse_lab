
# Understanding a Custom Page Replacement Algorithm

In an operating system, virtual memory allows a program to use more memory than is physically available. This is achieved by storing pages of the program on the disk and loading them into physical memory (frames) when needed. 

A page replacement algorithm decides which page in memory to swap out to the disk when a new page needs to be loaded and no frames are free.

This lab implements a custom algorithm called **Clock with Escape (CWE)**, which is a variation of the classic "Second-Chance" or "Clock" algorithm.

---

## The "Clock with Escape" (CWE) Algorithm

The `page_replacement_simulation.py` script simulates this algorithm. Here’s how it works:

1.  **Circular Buffer**: The memory frames are imagined as a circular clock face. A pointer, or "clock hand", points to one of the frames, which is the next candidate for replacement.

2.  **The Referenced Bit**: Each page loaded into a frame has a single extra bit associated with it, called the "referenced bit" or "use bit". 
    - When the CPU accesses a page that is already in a frame (a page hit), the hardware sets that page's referenced bit to `1`.

3.  **Page Fault Handling**: When a page fault occurs (the required page is not in memory), the algorithm must choose a "victim" page to evict. The clock hand comes into play:
    - The algorithm looks at the frame pointed to by the clock hand.
    - It checks the frame's referenced bit:
        - If the bit is `1`: This means the page was used recently. The algorithm gives it an "escape" or a second chance. It flips the referenced bit to `0` and advances the clock hand to the next frame.
        - If the bit is `0`: This is our victim. The page in this frame has not been referenced since the last time the clock hand swept over it. The new page is loaded into this frame, the old one is evicted, and the new page's referenced bit is set to `1`. The clock hand then advances to the *next* frame, so it doesn't immediately consider the newly loaded page for replacement.

### Why is it a good algorithm?

- **Performance**: It is a good and efficient approximation of the Least Recently Used (LRU) algorithm. True LRU requires keeping a timestamp for every memory access, which is computationally expensive. CWE provides similar performance with much lower overhead (just one bit per frame).
- **Fairness**: Unlike pure FIFO (First-In, First-Out), it prevents frequently used pages from being evicted just because they were loaded a long time ago.
- **Simplicity**: The implementation is relatively straightforward compared to more complex algorithms.

---

## How the Simulation Works

The Python script `page_replacement_simulation.py` models this process:

- The `CWE_PageReplacement` class holds the state: `frames`, `referenced_bits`, and the `clock_hand`.
- The `access_page` method simulates a memory access. It checks for a hit or a fault and updates the state accordingly.
- The script runs a `reference_string` (a list of page accesses) through the simulator and prints the state of memory at each step, making it easy to visualize how pages are swapped.
- Finally, it calculates the hit ratio, a key metric for the performance of a page replacement algorithm.
