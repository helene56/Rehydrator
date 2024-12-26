#!/bin/bash

# Flag to track if the message has been shown 
MESSAGE_SHOWN=false

while true; do
    # Use PowerShell to list USB devices and find the correct BUSID for the Pico
    BUSID="7-1" # Replace with your Pico's USB bus ID

    # Run USBIPD commands on the Windows host
    # powershell.exe -Command "& { usbipd attach --wsl --busid $BUSID }"

    # Check if the device is already attached
    ATTACHED=$(powershell.exe -Command "& {
        usbipd list | Select-String -Pattern 'Attached' | Select-String -Pattern '$BUSID'
    }" | tr -d '\r')

    # If the device is not attached, attach it
    if [ -z "$ATTACHED" ]; then
        echo "Attaching Pico with BUSID: $BUSID"
        powershell.exe -Command "& { usbipd attach --wsl --busid $BUSID }"
    else
        if [ "$MESSAGE_SHOWN" = false ]; then
            echo "Pico is already attached."
            MESSAGE_SHOWN=true
        fi
    fi

    sleep 1
done
