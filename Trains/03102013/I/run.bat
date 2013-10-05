@echo off
python hax.py >.in
new.exe
brute.exe
diff .out .outans -U 2