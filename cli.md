# Complete Linux/Unix CLI Reference

A practical, detailed reference for the most-used terminal commands: what they do, every common flag, and real examples.

---

## Table of Contents

1. [Navigation](#navigation) — `pwd`, `cd`, `ls`
2. [File & Directory Creation](#file--directory-creation) — `mkdir`, `touch`
3. [Copy, Move, Remove](#copy-move-remove) — `cp`, `mv`, `rm`, `rmdir`
4. [Viewing Files](#viewing-files) — `cat`, `less`, `more`, `head`, `tail`
5. [Searching](#searching) — `find`, `grep`, `locate`, `which`
6. [Permissions & Ownership](#permissions--ownership) — `chmod`, `chown`, `chgrp`
7. [Links](#links) — `ln`
8. [Compression & Archives](#compression--archives) — `tar`, `zip`, `unzip`, `gzip`
9. [Text Processing](#text-processing) — `sed`, `awk`, `sort`, `uniq`, `wc`, `cut`, `tr`
10. [Process Management](#process-management) — `ps`, `top`, `kill`, `jobs`, `bg`, `fg`
11. [Disk & System Info](#disk--system-info) — `df`, `du`, `free`, `uname`
12. [Networking](#networking) — `curl`, `wget`, `ping`, `ssh`, `scp`
13. [Redirection & Pipes](#redirection--pipes)
14. [Environment & Shell](#environment--shell) — `echo`, `export`, `alias`, `history`
15. [Package Management](#package-management) — `apt`, `dnf`, `pacman`
16. [Misc Essentials](#misc-essentials) — `man`, `xargs`, `date`, `whoami`, `sudo`

---

## Navigation

### `pwd` — Print Working Directory
Shows the full path of the directory you're currently in.
```bash
pwd
```

### `cd` — Change Directory
```bash
cd /path/to/dir      # go to absolute path
cd folder            # go to relative path
cd ..                # go up one level
cd ../..             # go up two levels
cd ~                 # go to home directory
cd -                 # go to previous directory
cd                   # (no argument) also goes home
```

### `ls` — List Directory Contents
```bash
ls                   # basic list
ls -l                # long format: permissions, owner, size, date
ls -a                # show hidden files (dotfiles) too
ls -la               # combine: long + hidden
ls -lh               # long format, human-readable sizes (K/M/G)
ls -R                # recursive, list subdirectories too
ls -t                # sort by modification time, newest first
ls -S                # sort by file size, largest first
ls -r                # reverse the sort order
ls -d */             # list only directories
ls -1                # one entry per line
ls --color=auto      # colorize output by file type
ls -i                # show inode numbers
ls -F                # append indicator (/ for dir, * for executable, @ for symlink)
```
**Common combos:** `ls -lah` (long, all, human-readable) is the most-used variant.

---

## File & Directory Creation

### `mkdir` — Make Directory
```bash
mkdir myfolder                  # create one directory
mkdir dir1 dir2 dir3            # create multiple at once
mkdir -p a/b/c                  # create nested directories (parents as needed), no error if exists
mkdir -m 755 myfolder           # create with specific permissions
mkdir -v myfolder               # verbose — print a message for each created dir
```
**Notes:** Without `-p`, `mkdir a/b/c` fails if `a` or `a/b` don't already exist.

### `touch` — Create Empty File / Update Timestamp
```bash
touch file.txt                  # create empty file, or update its modified time if it exists
touch -c file.txt                # don't create the file if it doesn't exist
touch -t 202601011200 file.txt  # set a specific timestamp (YYYYMMDDhhmm)
touch file{1..5}.txt            # create file1.txt ... file5.txt via brace expansion
```

---

## Copy, Move, Remove

### `cp` — Copy
```bash
cp source.txt dest.txt          # copy file (dest content overwritten if exists)
cp file1 file2 dir/             # copy multiple files into a directory
cp -r sourcedir/ destdir/       # copy directory recursively (required for directories)
cp -i source dest                # interactive — prompt before overwrite
cp -v source dest                # verbose — show what's being copied
cp -u source dest                # update — copy only if source is newer than dest
cp -a source dest                # archive — preserve permissions, timestamps, symlinks, recursive
cp -p source dest                # preserve mode, ownership, timestamps
cp -n source dest                # no-clobber — never overwrite existing files
cp -f source dest                # force — overwrite without prompting, remove dest first if needed
cp -l source dest                # create hard link instead of copying
cp -s source dest                # create symbolic link instead of copying
```
**Notes:** `cp -r` is required for directories; plain `cp` on a directory fails with "omitting directory."

### `mv` — Move / Rename
```bash
mv oldname.txt newname.txt      # rename a file (same directory = rename)
mv file.txt /path/to/dir/       # move file into another directory
mv file1 file2 dir/             # move multiple files into a directory
mv -i source dest                # interactive — prompt before overwrite
mv -v source dest                # verbose
mv -u source dest                # move only if source is newer than dest
mv -n source dest                # no-clobber — don't overwrite existing files
mv -f source dest                # force — overwrite without prompt
mv -b source dest                # make a backup of any file that would be overwritten
```
**Notes:** `mv` doesn't need `-r` for directories — it works directly since it's just relinking the path (unless crossing filesystems, in which case it copies then deletes).

### `rm` — Remove
```bash
rm file.txt                     # delete a file
rm file1 file2 file3            # delete multiple files
rm -r dir/                      # delete a directory and its contents recursively
rm -f file.txt                  # force — ignore nonexistent files, never prompt
rm -rf dir/                     # force-delete directory tree — NO CONFIRMATION, use with extreme care
rm -i file.txt                  # interactive — prompt before every removal
rm -I file.txt                  # prompt once before removing 3+ files, or recursively
rm -v file.txt                  # verbose — show what's being deleted
rm --preserve-root -rf /        # refuses to operate recursively on / (default behavior actually)
```
**⚠️ Danger zone:** `rm -rf /` or `rm -rf *` (run from the wrong directory) can wipe critical data with zero recovery — there is no trash/undo in the terminal. Always double-check your current directory (`pwd`) and the target path before running `rm -rf`. Consider `rm -ri` for anything destructive, or aliasing `rm` to `rm -i`.

### `rmdir` — Remove Empty Directory
```bash
rmdir emptyfolder                # only works if the directory is empty
rmdir -p a/b/c                   # remove nested empty dirs (removes c, then b, then a if all become empty)
```
**Notes:** Use `rm -r` instead if the directory has contents.

---

## Viewing Files

### `cat` — Concatenate & Print
```bash
cat file.txt                    # print entire file to terminal
cat file1 file2                 # print both files concatenated
cat -n file.txt                 # show line numbers
cat -A file.txt                 # show all hidden chars ($ for line end, ^I for tab, etc.)
cat file1 file2 > merged.txt    # combine files into a new file
cat >> file.txt                 # append typed input to file (Ctrl+D to end)
```

### `less` — Paginated Viewer (recommended for large files)
```bash
less file.txt
# inside less:
#   space / f   → next page
#   b           → previous page
#   /term       → search forward for "term"
#   ?term       → search backward
#   n / N       → next / previous search match
#   g / G       → go to top / bottom of file
#   q           → quit
```

### `more` — Simpler Pager (older, more limited than `less`)
```bash
more file.txt                   # space to page forward, q to quit (no backward scroll)
```

### `head` — First Lines of a File
```bash
head file.txt                   # first 10 lines (default)
head -n 20 file.txt              # first 20 lines
head -n -5 file.txt              # all except the last 5 lines
head -c 100 file.txt             # first 100 bytes
```

### `tail` — Last Lines of a File
```bash
tail file.txt                   # last 10 lines (default)
tail -n 20 file.txt               # last 20 lines
tail -f file.txt                  # follow — keep printing new lines as they're added (great for logs)
tail -F file.txt                  # like -f but also handles log rotation
tail -c 100 file.txt              # last 100 bytes
```

---

## Searching

### `find` — Search for Files/Directories
```bash
find . -name "*.txt"                       # find by name (case-sensitive) in current dir, recursively
find . -iname "*.txt"                      # case-insensitive name match
find / -type f -name "config.yml"          # search entire filesystem for a file
find . -type d -name "node_modules"        # find only directories
find . -mtime -7                           # modified in the last 7 days
find . -mtime +30                          # modified more than 30 days ago
find . -size +100M                         # files larger than 100 MB
find . -empty                              # find empty files/directories
find . -name "*.log" -delete               # find and delete matches
find . -name "*.tmp" -exec rm {} \;        # find and run a command on each match
find . -name "*.js" -exec grep -l "TODO" {} \;  # find files containing "TODO"
find . -maxdepth 2 -name "*.md"            # limit search depth
find . -perm 644                           # find files with specific permissions
find . -user krishnendu                    # find files owned by a specific user
```

### `grep` — Search Text Inside Files
```bash
grep "pattern" file.txt          # search for a pattern in a file
grep -i "pattern" file.txt       # case-insensitive search
grep -r "pattern" .              # recursive search through all files in a directory
grep -n "pattern" file.txt       # show line numbers of matches
grep -v "pattern" file.txt       # invert match — show lines that DON'T match
grep -c "pattern" file.txt       # count matching lines
grep -l "pattern" *.txt          # list only filenames that contain matches
grep -w "word" file.txt          # match whole word only
grep -A 3 "pattern" file.txt     # show 3 lines After each match
grep -B 3 "pattern" file.txt     # show 3 lines Before each match
grep -C 3 "pattern" file.txt     # show 3 lines of Context (before+after)
grep -E "regex|pattern" file.txt # extended regex (supports |, +, ?, etc.)
grep --include="*.js" -r "TODO" .   # recursive, only search .js files
grep --exclude-dir=node_modules -r "pattern" .  # skip a directory
```

### `locate` — Fast File Search (uses a prebuilt index)
```bash
locate filename.txt              # instant search using the mlocate database
sudo updatedb                    # refresh the search database (run periodically)
```
**Notes:** Faster than `find` but can be out of date if `updatedb` hasn't run recently.

### `which` / `whereis` — Locate a Command
```bash
which python3                    # show the path of the executable that would run
which -a python                  # show all matches in PATH
whereis python3                  # show binary, source, and man page locations
```

---

## Permissions & Ownership

### `chmod` — Change Permissions
```bash
chmod 755 file.sh                # rwxr-xr-x (owner: rwx, group: r-x, others: r-x)
chmod 644 file.txt               # rw-r--r-- (common default for regular files)
chmod +x script.sh               # add execute permission for everyone
chmod -x script.sh               # remove execute permission
chmod u+x script.sh              # add execute for owner (user) only
chmod g+w file.txt               # add write for group
chmod o-r file.txt               # remove read for others
chmod a+r file.txt               # add read for all (user, group, others)
chmod -R 755 folder/             # apply recursively to a directory tree
chmod u=rwx,g=rx,o=r file.txt    # set exact permissions per category
```
**Permission numbers cheat sheet:**
| Number | Permission | Symbol |
|---|---|---|
| 7 | read+write+execute | rwx |
| 6 | read+write | rw- |
| 5 | read+execute | r-x |
| 4 | read only | r-- |
| 0 | none | --- |

Format is `chmod [owner][group][others]`, e.g. `755` = owner:7, group:5, others:5.

### `chown` — Change Owner
```bash
chown user file.txt              # change owner
chown user:group file.txt        # change owner and group together
chown -R user:group folder/      # apply recursively
chown :group file.txt            # change only the group
```

### `chgrp` — Change Group Only
```bash
chgrp groupname file.txt
chgrp -R groupname folder/
```

---

## Links

### `ln` — Create Links
```bash
ln source.txt hardlink.txt       # create a hard link (same inode, same data)
ln -s /path/to/source linkname   # create a symbolic link (symlink) — a pointer/shortcut
ln -sf source linkname           # force — overwrite existing symlink
```
**Hard link vs symlink:** A hard link points to the same data on disk (deleting the original doesn't break it). A symlink is a pointer to a path (deleting/moving the original breaks it).

---

## Compression & Archives

### `tar` — Tape Archive (bundle files, often combined with compression)
```bash
tar -cvf archive.tar folder/        # create an archive (c=create, v=verbose, f=filename)
tar -xvf archive.tar                # extract an archive
tar -czvf archive.tar.gz folder/    # create + gzip compress
tar -xzvf archive.tar.gz            # extract a gzip-compressed archive
tar -cjvf archive.tar.bz2 folder/   # create + bzip2 compress
tar -xjvf archive.tar.bz2           # extract a bzip2 archive
tar -tvf archive.tar                # list contents without extracting
tar -xvf archive.tar -C /target/dir # extract into a specific directory
tar --exclude="*.log" -czvf archive.tar.gz folder/  # exclude files matching a pattern
```

### `zip` / `unzip`
```bash
zip archive.zip file1 file2      # zip specific files
zip -r archive.zip folder/       # zip a whole directory recursively
zip -e archive.zip file.txt      # create a password-protected zip
unzip archive.zip                # extract a zip in current directory
unzip archive.zip -d /target/dir # extract into a specific directory
unzip -l archive.zip             # list contents without extracting
unzip -o archive.zip             # overwrite existing files without prompting
```

### `gzip` / `gunzip`
```bash
gzip file.txt                    # compress file.txt → file.txt.gz (removes original)
gzip -k file.txt                 # keep the original file too
gunzip file.txt.gz               # decompress back to file.txt
gzip -d file.txt.gz              # same as gunzip
```

---

## Text Processing

### `sort`
```bash
sort file.txt                    # sort lines alphabetically
sort -r file.txt                 # reverse order
sort -n file.txt                 # numeric sort (important — alphabetic sort gets "10" before "2" wrong)
sort -u file.txt                 # sort and remove duplicate lines
sort -k2 file.txt                # sort by the 2nd column/field
sort -t"," -k2 file.csv          # sort CSV by 2nd column, using comma as delimiter
```

### `uniq` — Filter Duplicate Lines (input must already be sorted)
```bash
sort file.txt | uniq             # remove adjacent duplicate lines
sort file.txt | uniq -c          # count occurrences of each line
sort file.txt | uniq -d          # show only duplicated lines
sort file.txt | uniq -u          # show only unique (non-duplicated) lines
```

### `wc` — Word Count
```bash
wc file.txt                      # lines, words, bytes
wc -l file.txt                   # count lines only
wc -w file.txt                   # count words only
wc -c file.txt                   # count bytes
wc -m file.txt                   # count characters
```

### `cut` — Extract Columns/Fields
```bash
cut -d"," -f1 file.csv           # extract field 1, using comma as delimiter
cut -d"," -f1,3 file.csv         # extract fields 1 and 3
cut -c1-5 file.txt               # extract characters 1 through 5 of each line
```

### `tr` — Translate/Replace Characters
```bash
echo "hello" | tr 'a-z' 'A-Z'    # uppercase everything
tr -d '\n' < file.txt            # delete all newline characters
tr -s ' ' < file.txt              # squeeze repeated spaces into one
```

### `sed` — Stream Editor (find & replace, line editing)
```bash
sed 's/old/new/' file.txt              # replace first occurrence per line, print to stdout
sed 's/old/new/g' file.txt             # replace ALL occurrences per line
sed -i 's/old/new/g' file.txt          # edit the file in place
sed -i.bak 's/old/new/g' file.txt      # edit in place, keep a .bak backup
sed -n '5,10p' file.txt                # print only lines 5 through 10
sed '3d' file.txt                      # delete line 3
sed '/pattern/d' file.txt              # delete lines matching pattern
```

### `awk` — Pattern Scanning & Text Processing
```bash
awk '{print $1}' file.txt              # print the first column/field of each line
awk -F"," '{print $2}' file.csv        # use comma as field separator, print 2nd field
awk '{print $1, $3}' file.txt          # print columns 1 and 3
awk '/pattern/ {print}' file.txt       # print lines matching a pattern
awk '{sum+=$1} END {print sum}' file.txt   # sum up column 1 across all lines
awk 'NR==5' file.txt                   # print only line number 5
```

---

## Process Management

### `ps` — Process Status (snapshot)
```bash
ps                                # processes in current shell
ps aux                            # ALL processes, all users, detailed (most common usage)
ps -ef                            # similar to aux, different format (POSIX style)
ps aux | grep nginx               # find a specific process
```

### `top` / `htop` — Live Process Monitor
```bash
top                               # live view of CPU/memory usage by process
# inside top: press 'q' to quit, 'k' to kill a process, 'M' to sort by memory, 'P' by CPU
htop                              # nicer, colorized version (often needs separate install)
```

### `kill` / `killall` / `pkill`
```bash
kill 1234                         # send SIGTERM (graceful stop) to process ID 1234
kill -9 1234                      # send SIGKILL (force kill, cannot be ignored)
kill -l                           # list all available signals
killall firefox                   # kill all processes matching a name
pkill -f "node server.js"         # kill by matching the full command string
```

### `jobs`, `bg`, `fg`, `&`, `Ctrl+Z`
```bash
long-running-command &            # run in background immediately
Ctrl+Z                            # suspend the current foreground process
jobs                              # list background/suspended jobs
bg %1                             # resume job 1 in the background
fg %1                             # bring job 1 to the foreground
nohup command &                   # run a command immune to hangups (survives terminal close)
```

---

## Disk & System Info

### `df` — Disk Free Space
```bash
df -h                             # human-readable disk usage per filesystem
df -h /home                       # usage for a specific mount point
```

### `du` — Disk Usage (per file/folder)
```bash
du -h file.txt                    # size of a specific file, human-readable
du -sh folder/                    # total size of a folder, summarized
du -sh */                         # size of each subfolder in current directory
du -h --max-depth=1               # sizes one level deep
```

### `free` — Memory Usage
```bash
free -h                           # RAM and swap usage, human-readable
```

### `uname` — System Info
```bash
uname -a                          # all system info (kernel, hostname, arch, etc.)
uname -r                          # kernel release version
```

---

## Networking

### `curl` — Transfer Data / Test APIs
```bash
curl https://example.com                       # fetch and print a URL's content
curl -o file.html https://example.com          # save output to a file
curl -O https://example.com/file.zip           # save with the remote filename
curl -I https://example.com                    # fetch headers only (HEAD request)
curl -X POST https://api.example.com/data \
  -H "Content-Type: application/json" \
  -d '{"key":"value"}'                         # send a POST request with JSON body
curl -L https://short.url                      # follow redirects
curl -s https://example.com                    # silent mode (no progress bar)
```

### `wget` — Download Files
```bash
wget https://example.com/file.zip              # download a file
wget -O newname.zip https://example.com/file.zip  # save with a custom name
wget -c https://example.com/largefile.iso      # resume a partial download
wget -r https://example.com                    # recursive download (mirror a site)
```

### `ping`
```bash
ping google.com                   # test connectivity (Ctrl+C to stop)
ping -c 4 google.com              # send exactly 4 packets then stop
```

### `ssh` — Secure Shell
```bash
ssh user@hostname                 # connect to a remote machine
ssh -p 2222 user@hostname         # connect on a custom port
ssh -i ~/.ssh/key.pem user@host   # connect using a specific private key
```

### `scp` — Secure Copy (over SSH)
```bash
scp file.txt user@host:/remote/path/      # copy a local file to a remote server
scp user@host:/remote/file.txt .          # copy a remote file to local current dir
scp -r folder/ user@host:/remote/path/    # copy a directory recursively
scp -P 2222 file.txt user@host:/path/     # use a custom port (capital P for scp)
```

---

## Redirection & Pipes

```bash
command > file.txt                # redirect stdout to a file (overwrite)
command >> file.txt               # redirect stdout to a file (append)
command 2> errors.txt             # redirect stderr only
command > out.txt 2>&1            # redirect both stdout and stderr to the same file
command &> out.txt                # shorthand for the above (bash)
command < input.txt               # use a file as stdin
command1 | command2               # pipe: send command1's output as command2's input
command1 | command2 | command3    # chain multiple pipes
command1 && command2              # run command2 only if command1 succeeds
command1 || command2              # run command2 only if command1 fails
command1 ; command2               # run command2 regardless of command1's result
```

---

## Environment & Shell

### `echo`
```bash
echo "Hello World"                # print text
echo $HOME                        # print an environment variable
echo -n "no newline"              # suppress the trailing newline
echo -e "line1\nline2"            # interpret escape sequences like \n
```

### `export` — Set Environment Variables
```bash
export MY_VAR="value"             # set for current shell session and child processes
echo $MY_VAR                      # read it back
unset MY_VAR                      # remove it
```

### `alias`
```bash
alias ll="ls -lah"                # create a shortcut command
unalias ll                        # remove an alias
alias                             # list all current aliases
```
Add aliases to `~/.bashrc` or `~/.zshrc` to make them permanent.

### `history`
```bash
history                           # show command history
history 20                        # show last 20 commands
!123                              # re-run command number 123 from history
!!                                # re-run the last command
!curl                             # re-run the most recent command starting with "curl"
Ctrl+R                            # interactive reverse search through history
```

---

## Package Management

### Debian/Ubuntu — `apt`
```bash
sudo apt update                   # refresh package index
sudo apt upgrade                  # upgrade all installed packages
sudo apt install packagename      # install a package
sudo apt remove packagename       # remove a package (keep config files)
sudo apt purge packagename        # remove a package and its config files
sudo apt autoremove               # remove unused dependencies
apt search keyword                # search for a package
apt show packagename              # show package details
```

### Fedora/RHEL — `dnf`
```bash
sudo dnf install packagename
sudo dnf remove packagename
sudo dnf update
sudo dnf search keyword
```

### Arch — `pacman`
```bash
sudo pacman -S packagename        # install
sudo pacman -R packagename        # remove
sudo pacman -Syu                  # sync + full system upgrade
sudo pacman -Ss keyword           # search
```

---

## Misc Essentials

### `man` — Manual Pages
```bash
man ls                            # full documentation for a command
man -k keyword                    # search man page descriptions for a keyword
```

### `xargs` — Build Commands from Input
```bash
find . -name "*.tmp" | xargs rm           # pass find results as arguments to rm
echo "file1 file2" | xargs touch          # create multiple files from piped input
find . -name "*.txt" | xargs -I{} cp {} /backup/   # {} substitutes each input item
```

### `date`
```bash
date                               # current date and time
date "+%Y-%m-%d"                   # custom format: 2026-09-12
date "+%H:%M:%S"                   # just the time
```

### `whoami` / `id`
```bash
whoami                             # current logged-in username
id                                 # UID, GID, and group memberships
```

### `sudo` — Run as Superuser
```bash
sudo command                       # run a single command with root privileges
sudo -i                            # start an interactive root shell
sudo -u username command           # run a command as a different user
```

### `df`, `du`, `top` combo for quick health check
```bash
df -h && free -h && uptime
```

### `chmod +x` for making scripts runnable
```bash
chmod +x script.sh
./script.sh
```

---

## Quick Danger List (commands to run carefully)

- `rm -rf` — permanent, unrecoverable deletion
- `dd` — can overwrite entire disks if the target is wrong
- `chmod -R 777` — opens up permissions system-wide, a security risk
- `> file` — truncates a file to zero bytes instantly, even accidentally (e.g. mistyped redirect)
- `kill -9 1` / killing PID 1 — can crash the system
- Any command with `sudo` and a wildcard (`*`) — expand the wildcard mentally before hitting enter

---

*Tip: run `command --help` or `man command` any time you need the full, authoritative flag list for your specific OS/distro — flag availability can vary slightly between GNU (Linux) and BSD (macOS) versions of these tools.*
