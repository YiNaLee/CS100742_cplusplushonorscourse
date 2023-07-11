@echo off
rem ***************************************************
rem *  清除各项目（目录）下的Debug/Release/X64子目录  *
rem ***************************************************
setlocal enabledelayedexpansion

rmdir /s /q .vs 1>nul 2>&1
rmdir /s /q Debug 1>nul 2>&1
rmdir /s /q x64 1>nul 2>&1
rmdir /s /q Release 1>nul 2>&1

for /d %%i in (*.*) do (
    echo -------%%i-------

    cd %%i
    rmdir /s /q Debug 1>nul 2>&1
    rmdir /s /q x64 1>nul 2>&1
    rmdir /s /q Release 1>nul 2>&1
    cd ..
)

pause

