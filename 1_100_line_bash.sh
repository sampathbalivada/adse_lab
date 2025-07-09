#!/bin/bash

# Password Generator Script
# Generates secure passwords with customizable options

# Function to display usage instructions
usage() {
  echo "Usage: $0 [-l LENGTH] [-n COUNT] [-u] [-d] [-s] [-e EXCLUDE] [-h]"
  echo "  -l LENGTH   Specify the length of the password (default: 12)"
  echo "  -n COUNT    Number of passwords to generate (default: 1)"
  echo "  -u          Include uppercase letters"
  echo "  -d          Include digits"
  echo "  -s          Include special characters"
  echo "  -e EXCLUDE  Characters to exclude from the password"
  echo "  -h          Display this help message"
  exit 1
}

# Default values
LENGTH=12
COUNT=1
INCLUDE_UPPER=false
INCLUDE_DIGITS=false
INCLUDE_SPECIAL=false
EXCLUDE=""

# Parse command-line options
while getopts "l:n:udse:h" opt; do
  case $opt in
    l) LENGTH=$OPTARG ;;
    n) COUNT=$OPTARG ;;
    u) INCLUDE_UPPER=true ;;
    d) INCLUDE_DIGITS=true ;;
    s) INCLUDE_SPECIAL=true ;;
    e) EXCLUDE=$OPTARG ;;
    h) usage ;;
    *) usage ;;
  esac
done

# Character sets
LOWERCASE="abcdefghijklmnopqrstuvwxyz"
UPPERCASE="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
DIGITS="0123456789"
SPECIAL="!@#$%^&*()-_=+[]{}|;:,.<>?/"

# Build the character pool
CHAR_POOL=$LOWERCASE
if $INCLUDE_UPPER; then
  CHAR_POOL+=$UPPERCASE
fi
if $INCLUDE_DIGITS; then
  CHAR_POOL+=$DIGITS
fi
if $INCLUDE_SPECIAL; then
  CHAR_POOL+=$SPECIAL
fi

# Remove excluded characters from the character pool
if [ -n "$EXCLUDE" ]; then
  CHAR_POOL=$(echo "$CHAR_POOL" | tr -d "$EXCLUDE")
fi

# Ensure the character pool is not empty
if [ -z "$CHAR_POOL" ]; then
  echo "Error: Character pool is empty after applying exclusions."
  usage
fi

# File to store password hashes
PASSWORD_HISTORY_FILE="password_history.txt"

# Function to check if a password is already in history
is_password_in_history() {
  local password_hash=$1
  if [ -f "$PASSWORD_HISTORY_FILE" ]; then
    grep -q "$password_hash" "$PASSWORD_HISTORY_FILE"
    return $?
  fi
  return 1
}

# Function to add a password hash to history
add_password_to_history() {
  local password_hash=$1
  echo "$password_hash" >> "$PASSWORD_HISTORY_FILE"
}

# Replace bcrypt with OpenSSL for hashing
# Function to hash a password using OpenSSL
hash_password() {
  local password=$1
  echo -n "$password" | openssl dgst -sha256 | awk '{print $2}'
}

# Function to generate a single password
generate_password() {
  local password=""
  for ((i = 0; i < LENGTH; i++)); do
    password+="${CHAR_POOL:RANDOM%${#CHAR_POOL}:1}"
  done

  # Hash the password using OpenSSL
  local password_hash=$(hash_password "$password")

  # Check if the password is already in history
  if is_password_in_history "$password_hash"; then
    echo "Password already exists in history. Generating a new one..."
    generate_password
  else
    # Add the password hash to history
    add_password_to_history "$password_hash"
    echo "$password"
  fi
}

# Generate the requested number of passwords
for ((i = 0; i < COUNT; i++)); do
  generate_password
  echo "Password hash stored in history."
done