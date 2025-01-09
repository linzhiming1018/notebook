@echo off
FOR /F "tokens=2 delims==" %%I IN ('wmic os get localdatetime /value') DO SET datetime=%%I
SET formattedDate=%datetime:~4,2%/%datetime:~6,2%/%datetime:~0,4%

git commit -m "Committed %formattedDate%"

SET /P choice="Do you want to push commits to the remote repository? [Y/n] "
IF /I "%choice%"=="Y" (
    git push origin master
) ELSE (
    IF /I "%choice%"=="y" (
        git push origin master
    )
)
