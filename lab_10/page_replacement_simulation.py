class CWE_PageReplacement:
    """
    Simulates the 'Clock with Escape' (CWE) custom page replacement algorithm.

    This algorithm is a variation of the classic Second-Chance (Clock) algorithm.
    - Memory frames are treated as a circular buffer.
    - A 'clock hand' points to the next potential victim frame.
    - Each page in a frame has a 'referenced bit' (or 'use bit').
    - When a page is accessed (hit), its referenced bit is set to 1.
    - When a page fault occurs, the clock hand sweeps through the frames:
        - If a frame's referenced bit is 1, it gets a "second chance": the bit is
          flipped to 0, and the hand moves to the next frame.
        - If a frame's referenced bit is 0, that frame is the victim. The new
          page replaces the old one, its referenced bit is set to 1, and the
          clock hand advances.
    """

    def __init__(self, frame_size):
        self.frame_size = frame_size
        self.frames = [None] * frame_size
        self.referenced_bits = [0] * frame_size
        self.page_table = {}
        self.clock_hand = 0
        self.hits = 0
        self.faults = 0

    def access_page(self, page_number):
        print(f"Accessing page: {page_number}", end='\t')

        # --- Check for a Page Hit ---
        if page_number in self.page_table:
            self.hits += 1
            frame_index = self.page_table[page_number]
            self.referenced_bits[frame_index] = 1 # Mark as recently used
            print(f"Hit! (Frame {frame_index})")
            self.print_state()
            return

        # --- Handle Page Fault ---
        self.faults += 1
        print("Page Fault!", end=' ')

        # Find a victim frame using the CWE algorithm
        while True:
            if self.referenced_bits[self.clock_hand] == 0:
                # Found a victim
                victim_frame_index = self.clock_hand
                old_page = self.frames[victim_frame_index]

                print(f"Replacing page {old_page} in Frame {victim_frame_index}")

                # Remove old page from page table if it exists
                if old_page is not None:
                    del self.page_table[old_page]

                # Place new page
                self.frames[victim_frame_index] = page_number
                self.referenced_bits[victim_frame_index] = 1 # New page is marked as used
                self.page_table[page_number] = victim_frame_index

                # Advance the clock hand
                self.clock_hand = (self.clock_hand + 1) % self.frame_size
                break # Exit the loop
            else:
                # Give a second chance
                self.referenced_bits[self.clock_hand] = 0
                self.clock_hand = (self.clock_hand + 1) % self.frame_size
        
        self.print_state()

    def print_state(self):
        print("Frames:      ", self.frames)
        print("Ref Bits:    ", self.referenced_bits)
        print("Clock Hand -> Frame", self.clock_hand)
        print("-" * 40)

    def print_summary(self):
        print("\n--- Simulation Summary ---")
        print(f"Total Accesses: {self.hits + self.faults}")
        print(f"Page Hits:      {self.hits}")
        print(f"Page Faults:    {self.faults}")
        hit_ratio = (self.hits / (self.hits + self.faults)) * 100
        print(f"Hit Ratio:      {hit_ratio:.2f}%")


# --- Main Simulation ---
if __name__ == "__main__":
    # A reference string is a sequence of page accesses
    reference_string = [1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5]
    number_of_frames = 3

    print(f"Starting simulation with {number_of_frames} frames.")
    print(f"Reference String: {reference_string}\n")

    simulator = CWE_PageReplacement(number_of_frames)

    for page in reference_string:
        simulator.access_page(page)

    simulator.print_summary()
