/**
	Log �����������
*/
#pragma once

#include <string>
using namespace std;

class LogUtil
{
public:
	LogUtil();
	~LogUtil();
	static void info(string s);
	static void Error(string s);
	static void Debug(string s);
};

