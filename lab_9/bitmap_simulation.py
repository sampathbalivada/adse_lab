import pandas as pd

# --- Sample Sales Data ---
# Imagine this is a large table in a data warehouse.
# Each row represents a single transaction.
data = {
    'transaction_id': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'product': ['Laptop', 'Mouse', 'Laptop', 'Keyboard', 'Mouse', 'Monitor', 'Laptop', 'Mouse', 'Keyboard', 'Monitor'],
    'region': ['North', 'South', 'North', 'West', 'East', 'West', 'North', 'South', 'East', 'West'],
    'customer_segment': ['Retail', 'Enterprise', 'Retail', 'Retail', 'Enterprise', 'Enterprise', 'Retail', 'Retail', 'Enterprise', 'Enterprise']
}
sales_df = pd.DataFrame(data)

# --- Bitmap Index Creation ---
# In a real database, this is done automatically. Here, we simulate it.
# A bitmap is created for each unique value in the columns we want to index.
# Each bit in the bitmap corresponds to a row in the table.
# A '1' means the row matches the value, a '0' means it doesn't.

# We can represent these bitmaps as integers in Python.
bitmaps = {}

def create_bitmap_index(df, column_name):
    """Creates a dictionary of bitmaps for all unique values in a column."""
    unique_values = df[column_name].unique()
    for value in unique_values:
        bitmap = 0
        for i in range(len(df)):
            if df[column_name][i] == value:
                bitmap |= (1 << i) # Set the i-th bit to 1
        bitmaps[f"{column_name}_{value}"] = bitmap

# Create indexes for our low-cardinality columns
create_bitmap_index(sales_df, 'product')
create_bitmap_index(sales_df, 'region')
create_bitmap_index(sales_df, 'customer_segment')

def print_bitmap(name, bitmap):
    """Helper function to print a bitmap in a readable format."""
    # Reverse the binary string to match row order [row10, row9, ..., row1]
    print(f"{name:>25s}: {bitmap:010b}")

print("--- Generated Bitmaps (1 = match, 0 = no match) ---")
for name, bitmap in bitmaps.items():
    print_bitmap(name, bitmap)
print("-" * 50)


# --- Querying with Bitmap Indexes ---
# Complex queries become simple, fast bitwise operations.

print("\n--- Query Simulation ---")

# Query 1: Find all 'Laptop' sales in the 'North' region.
# SQL: SELECT * FROM sales WHERE product = 'Laptop' AND region = 'North';
print("\nQuery 1: product = 'Laptop' AND region = 'North'")
bitmap_laptop = bitmaps['product_Laptop']
bitmap_north = bitmaps['region_North']
result_1 = bitmap_laptop & bitmap_north # Bitwise AND

print_bitmap("product_Laptop", bitmap_laptop)
print_bitmap("region_North", bitmap_north)
print_bitmap("Result (AND)", result_1)

# Query 2: Find all sales that were either 'Mouse' OR in the 'West' region.
# SQL: SELECT * FROM sales WHERE product = 'Mouse' OR region = 'West';
print("\nQuery 2: product = 'Mouse' OR region = 'West'")
bitmap_mouse = bitmaps['product_Mouse']
bitmap_west = bitmaps['region_West']
result_2 = bitmap_mouse | bitmap_west # Bitwise OR

print_bitmap("product_Mouse", bitmap_mouse)
print_bitmap("region_West", bitmap_west)
print_bitmap("Result (OR)", result_2)


# Query 3: Find all 'Enterprise' sales that were NOT for 'Laptops'.
# SQL: SELECT * FROM sales WHERE customer_segment = 'Enterprise' AND product != 'Laptop';
print("\nQuery 3: customer_segment = 'Enterprise' AND NOT product = 'Laptop'")
bitmap_enterprise = bitmaps['customer_segment_Enterprise']
# The NOT operation requires a mask of all 1s for the number of rows.
all_rows_mask = (1 << len(sales_df)) - 1
result_3 = bitmap_enterprise & ~bitmap_laptop & all_rows_mask # Bitwise AND NOT

print_bitmap("customer_segment_Enterprise", bitmap_enterprise)
print_bitmap("NOT product_Laptop", ~bitmap_laptop & all_rows_mask)
print_bitmap("Result (AND NOT)", result_3)


def decode_bitmap(df, bitmap):
    """Returns the rows from the DataFrame that correspond to set bits in the bitmap."""
    matching_indices = []
    for i in range(len(df)):
        if (bitmap >> i) & 1:
            matching_indices.append(i)
    return df.iloc[matching_indices]

print("\n--- Query Results ---")
print("\nResult for Query 1 (Laptop AND North):")
print(decode_bitmap(sales_df, result_1))

print("\nResult for Query 2 (Mouse OR West):")
print(decode_bitmap(sales_df, result_2))

print("\nResult for Query 3 (Enterprise AND NOT Laptop):")
print(decode_bitmap(sales_df, result_3))
