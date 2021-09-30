#!/bin/bash

# Each menu item is seperated into a function to keep the code clean and easy to read.
CPU_Info (){
        cat /proc/cpuinfo # Display contents of /proc/cpuinfo
}

Interrupts(){
        cat /proc/interrupts
}

Load(){
        awk '{ print $3, $5 }' /proc/loadavg # Using awk to print the 3rd and 5th columns from the loadavg output.
}

Process(){
        PID=$(ls /proc | head -n1) # Take the first file in the /proc/ directory and assign the PID to a variable.
        echo PID:
        echo $PID # Printing PID variable.
        echo Name:
        ps -p $PID -o comm= # Using ps, find the command name for that PID.
}

while true; do
        options=("Display CPU info" "Display a list of interrupts" "Display the load average" "Display a process" "Exit") # These will be the menu options

        PS3='Please select an option: ' # PS3 is an environmental variable used by the select statement. 
        select option in "${options[@]}"; do # Creates a menu from the options provided in in [options]
                case $option in # Matches the selected menu item to one of the following string patterns.
                        "Display CPU info") # If selected menu item matches this pattern the code indented below is executed.
                                CPU_Info; break;; # Calls the CPU_info function and breaks the first loop.
                        "Display a list of interrupts")
                                Interrupts; break;;
                        "Display the load average")
                                Load; break;;
                        "Display a process")
                                Process; break;;
                        "Exit")
                                break 2 # Break [n] breaks the nth loop
                                ;;
                        *) # Wildcard that always matches, used to catch incorrect inputs.
                            echo "That's not an option is it..."
                            ;;
                esac
        done

done

echo Exiting...