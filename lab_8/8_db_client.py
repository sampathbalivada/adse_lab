#!/usr/bin/env python3

# This script connects to a PostgreSQL database, executes a series of SELECT queries 
# to fetch all records from predefined tables, and prints the results in a 
# formatted manner. It is designed to work with the tables created in 
# the accompanying SQL script.

# Prerequisites:
# - PostgreSQL server must be running.
# - A database and user must be created.
# - The tables from the SQL script must be loaded into the database.
# - The psycopg2 library must be installed:
#   pip install psycopg2-binary
#
# - Environment variables for database connection must be set:
#   export DB_NAME="your_db_name"
#   export DB_USER="your_db_user"
#   export DB_PASSWORD="your_db_password"
#   export DB_HOST="localhost"  (optional, defaults to localhost)
#   export DB_PORT="5432"      (optional, defaults to 5432)

import os
import psycopg2
import psycopg2.extras

# --- Database Connection Parameters (from Environment Variables) ---
DB_NAME = os.getenv("DB_NAME")
DB_USER = os.getenv("DB_USER")
DB_PASSWORD = os.getenv("DB_PASSWORD")
DB_HOST = os.getenv("DB_HOST", "localhost")
DB_PORT = os.getenv("DB_PORT", "5432")

def get_db_connection():
    """Establishes and returns a connection to the PostgreSQL database."""
    if not all([DB_NAME, DB_USER, DB_PASSWORD]):
        print("Error: Please set the DB_NAME, DB_USER, and DB_PASSWORD environment variables.")
        return None

    try:
        conn = psycopg2.connect(
            dbname=DB_NAME,
            user=DB_USER,
            password=DB_PASSWORD,
            host=DB_HOST,
            port=DB_PORT
        )
        return conn
    except psycopg2.OperationalError as e:
        print(f"Error: Could not connect to the database. Please check your connection settings.")
        print(f"Details: {e}")
        return None

def fetch_and_print_table(cursor, table_name):
    """Fetches all records from a given table and prints them."""
    try:
        cursor.execute(f"SELECT * FROM {table_name};")
        rows = cursor.fetchall()
        
        if not rows:
            print(f"\n--- No records found in {table_name} ---\n")
            return

        # Get column names from the cursor description
        colnames = [desc[0] for desc in cursor.description]
        
        print(f"\n--- Records from {table_name} ---")
        # Print header
        print(" | ".join(f"{name:<20}" for name in colnames))
        print("-" * (23 * len(colnames)))

        # Print rows
        for row in rows:
            print(" | ".join(f"{str(item):<20}" for item in row))
        print("\n")

    except psycopg2.Error as e:
        print(f"\nError fetching data from {table_name}: {e}")

def main():
    """Main function to connect to the DB and print all tables."""
    conn = get_db_connection()
    if conn is None:
        return

    cur = conn.cursor()

    tables_to_print = [
        "Employees",
        "Departments",
        "Locations",
        "Products",
        "Orders"
    ]

    for table in tables_to_print:
        fetch_and_print_table(cur, table)

    # Clean up
    cur.close()
    conn.close()
    print("Database connection closed.")

if __name__ == "__main__":
    main()
