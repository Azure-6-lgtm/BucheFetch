import os
import subprocess

# Color codes
RESET = "\033[0m"
BOLD = "\033[1m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
CYAN = "\033[36m"
WHITE = "\033[97m"

# Path to the ASCII art file
ascii_art = os.path.expanduser("~") + "/dogna.txt"

# Clear the screen for a clean output
os.system("clear")

# Display ASCII art from the file
if os.path.isfile(ascii_art):
    print(f"{CYAN}{BOLD}")
    with open(ascii_art, 'r') as file:
        print(file.read())
    print(RESET)
else:
    print(f"{RED}ASCII art file not found at {ascii_art}{RESET}")

# Display system information header
print(f"\n{YELLOW}{BOLD}System Information:{RESET}")
print(f"{BLUE}-------------------------------------{RESET}")

# Neofetch output (you can replace or add any other system info here)
subprocess.run(["neofetch", "--stdout"])

# Add custom system info with colors
print(f"\n{YELLOW}{BOLD}Custom Info:{RESET}")
print(f"{BLUE}-------------------------------------{RESET}")

# Uptime
uptime = subprocess.getoutput("uptime -p")
print(f"{GREEN}Uptime: {CYAN}{uptime}{RESET}")

# Kernel version
kernel = subprocess.getoutput("uname -r")
print(f"{GREEN}Kernel: {CYAN}{kernel}{RESET}")

# Architecture
architecture = subprocess.getoutput("uname -m")
print(f"{GREEN}Architecture: {CYAN}{architecture}{RESET}")

# Shell
shell = os.environ.get("SHELL")
print(f"{GREEN}Shell: {CYAN}{shell}{RESET}")

# Home Directory
home_directory = os.environ.get("HOME")
print(f"{GREEN}Home Directory: {CYAN}{home_directory}{RESET}")

# CPU Model
cpu = subprocess.getoutput("lscpu | grep 'Model name' | sed 's/Model name: *//'")
print(f"{GREEN}CPU: {CYAN}{cpu}{RESET}")

# RAM
ram = subprocess.getoutput("free -h | grep 'Mem:' | awk '{print $2}'")
print(f"{GREEN}RAM: {CYAN}{ram}{RESET}")
