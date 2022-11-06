all: 
	if exist .builder rmdir .builder /s /q
	if exist bin\gepard.exe del bin\gepard.exe
	builder winConfig.json