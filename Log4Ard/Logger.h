#pragma once

enum Level {
	TRACE = 0,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

class Logger
{
public:
	virtual void trace(const __FlashStringHelper *, ...) = 0;
	virtual void debug(const __FlashStringHelper *, ...) = 0;
	virtual void info(const __FlashStringHelper *, ...) = 0;
	virtual void warning(const __FlashStringHelper *, ...) = 0;
	virtual void error(const __FlashStringHelper *, ...) = 0;
	virtual void critical(const __FlashStringHelper *, ...) = 0;

	virtual void begin(Level level)=0 ;
protected:
	Level level;
}; 

extern Logger& logger;