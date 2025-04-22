#!/bin/bash

echo "------ OS Version, Release Number, Kernel Version ------"
uname -a
echo

echo "------ Top 10 Processes (by CPU usage, descending) ------"
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head -n 11
echo

echo "------ Processes with Highest Memory Usage ------"
ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 11
echo

echo "------ Logged in User and Log Name ------"
echo "User: $USER"
echo "Logname: $LOGNAME"
echo

echo "------ System Info ------"
echo "Current Shell: $SHELL"
echo "Home Directory: $HOME"
echo "Operating System Type: $(uname -o)"
echo "Current PATH: $PATH"
echo "Current Working Directory: $(pwd)"
