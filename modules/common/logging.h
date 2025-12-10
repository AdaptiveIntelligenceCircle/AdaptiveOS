#pragma once 
#include <string> 

#include <iostream> 
using namespace std; 

enum LogLevel {
    DEBUG, INFO, WARN, ERROR
}; 

void log(LogLevel level, const string &message); 
#define LOG_INFO(msg) log(INFO, msg) 
#define LOG_WARN(msg) log(WARN, msg)
#define LOG_ERROr(msg) log(ERROR, msg)