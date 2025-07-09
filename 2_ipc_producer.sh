#!/bin/bash

# Create a named pipe (FIFO) if it doesn't exist
PIPE="/tmp/ipc_pipe"
if [[ ! -p $PIPE ]]; then
    mkfifo $PIPE
fi

# Prompt the user for input and write it to the pipe
echo "Enter input for the consumer (P2):"
while read -r input; do
    echo "$input" > $PIPE
    echo "Input sent to consumer. Enter more input or press Ctrl+C to exit:"
done