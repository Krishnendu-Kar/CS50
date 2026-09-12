In PowerShell, from anywhere:

gcc "C:\Users\sukri\Documents\GitFirst\CS50\week-1-C\first.c" -o "C:\Users\sukri\Documents\GitFirst\CS50\week-1-C\first.exe"
& "C:\Users\sukri\Documents\GitFirst\CS50\week-1-C\first.exe"

Or cd into the folder first, which is less typing:

cd C:\Users\sukri\Documents\GitFirst\CS50\week-1-C
gcc first.c -o first.exe
.\first.exe

Two things to watch for on your setup:

- .\ is required to run the exe — PowerShell won't run programs from the current directory without it.
- #include <cs50.h> won't compile — you don't have the CS50 library locally. If the file uses get_string/get_int, either use the CS50 codespace/web IDE, or swap to plain C (scanf / fgets with stdio.h).

Useful flags while learning: gcc -Wall -g first.c -o first.exe turns on warnings and debug info.