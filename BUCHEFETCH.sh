#!/bin/bash

# Color codes
RESET="\e[0m"
BOLD="\e[1m"
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"
WHITE="\e[97m"

# Path to the ASCII art file
ascii_art="$HOME/dogna.txt"

# Clear the screen for a clean output
clear

# Display ASCII art from the file
if [[ -f "$ascii_art" ]]; then
    echo -e "${CYAN}$BOLD"
    cat "$ascii_art"
    echo -e "$RESET"
else
    echo -e "${RED}ASCII art file not found at $ascii_art${RESET}"
fi

# Display system information header
echo -e "\n${YELLOW}${BOLD}System Information:${RESET}"
echo -e "${BLUE}-------------------------------------${RESET}"

# Neofetch output (you can replace or add any other system info here)
neofetch --stdout

# Add custom system info with colors
echo -e "\n${YELLOW}${BOLD}Custom Info:${RESET}"
echo -e "${BLUE}-------------------------------------${RESET}"
echo -e "${GREEN}Uptime: ${CYAN}$(uptime -p)${RESET}"
echo -e "${GREEN}Kernel: ${CYAN}$(uname -r)${RESET}"
echo -e "${GREEN}Architecture: ${CYAN}$(uname -m)${RESET}"
echo -e "${GREEN}Shell: ${CYAN}$SHELL${RESET}"
echo -e "${GREEN}Home Directory: ${CYAN}$HOME${RESET}"
echo -e "${GREEN}CPU: ${CYAN}$(lscpu | grep 'Model name' | sed 's/Model name: *//')${RESET}"
echo -e "${GREEN}RAM: ${CYAN}$(free -h | grep 'Mem:' | awk '{print $2}')${RESET}"

# Optional: Add more system info if needed
# echo -e "${GREEN}Disk Usage: ${CYAN}$(df -h / | awk 'NR==2 {print $3 " / " $2}')${RESET}"
# echo -e "${GREEN}Battery: ${CYAN}$(upower -i $(upower -e | grep battery) | grep state | awk '{print $2}')${RESET}"
