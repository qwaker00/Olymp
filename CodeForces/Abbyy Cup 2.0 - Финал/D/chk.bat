@echo off
echo >res1
echo >res2
echo >res3
for %%i in (train/1/*.txt) do python sol.py<train/1/%%i >>res1
for %%i in (train/2/*.txt) do python sol.py<train/2/%%i >>res2
for %%i in (train/3/*.txt) do python sol.py<train/3/%%i >>res3
