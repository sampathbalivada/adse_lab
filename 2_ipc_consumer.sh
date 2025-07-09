#!/bin/bash

# Define the named pipe (FIFO)
PIPE="/tmp/ipc_pipe"

# Check if the pipe exists
if [[ ! -p $PIPE ]]; then
    echo "Error: Named pipe $PIPE does not exist. Please run the producer script first."
    exit 1
fi

# Read from the pipe and print the input
echo "Waiting for input from producer (P1)..."
while read -r line < $PIPE; do
    echo "Received from producer: $line"
done