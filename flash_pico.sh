#!/bin/bash

# Define the path to picotool
PICOTOOL="${HOME}/.pico-sdk/picotool/2.1.0/picotool/picotool"

TARGET_PATH="${1}" # Pass the target path as the first argument to the script

BUSID="7-1" # Replace with your Pico's USB bus ID

# Run USBIPD commands on the Windows host
# powershell.exe -Command "& { usbipd attach --wsl --busid $BUSID }"

# # Ensure the target path is provided
# if [ -z "$TARGET_PATH" ]; then
#     echo "Usage: $0 <target_path>"
#     exit 1
# fi

# Detach and reattach the device to ensure it connects
# usbipd wsl detach --busid $BUSID 2>/dev/null
# usbipd wsl attach --wsl --busid $BUSID

# to allow attach_pico.sh time to attach
sleep 2

# Run picotool command
"$PICOTOOL" load "$TARGET_PATH" -fx

# Terminate the pretask 
pkill -f "./attach_pico.sh"
