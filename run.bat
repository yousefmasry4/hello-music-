@echo off
start "0" html.bat
cd "D:\data structure\jo\public\js"
cmd /c "file.exe"
cd "D:\data structure\jo\public\js"
cmd /c"python .\clear.py"
start "1" main.bat
start "2" lyr.bat