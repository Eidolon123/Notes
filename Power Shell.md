-----------------------------------------------
# Power Shell
Tags:  #Cheatsheet #Hacking #Tools 
Creation date: 2021-10-18

-----------------------------------------------

## Downloading Files

```powershell
$URL = "http://cueh.coventry.ac.uk"
$OUTPUT = "output.html"
(New-Object System.Net.Webclient).DownloadFile($URL,$OUTPUT)
```

## Bypass execution policy

```powershell
powershell.exe -executionpolicy bypass -file dlscript.ps1
```

