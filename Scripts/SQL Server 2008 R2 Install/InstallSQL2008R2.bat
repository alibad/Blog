@ECHO off

echo Installing SQL Server 2008 R2
date/t
time /t
"<path to sql setup folder>\setup.exe" /ConfigurationFile="<path to setup config file>\SQLConfigFile.ini"
date/t
time /t