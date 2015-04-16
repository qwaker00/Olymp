python gen.py >.in
hax.exe
copy .out hax.out >nul
del .out  >nul
new.exe
diff .out hax.out
