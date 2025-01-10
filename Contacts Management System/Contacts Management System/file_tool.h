#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "person.h"

class FileTool
{
public:
	// 读文件
	void read(std::string path, std::string& str)
	{
		std::ifstream f;
		f.open(path, std::ios::in);
		std::getline(f, str, (char)EOF);
		f.close();
	}

	// 写文件
	void write(std::string path, std::string str)
	{
		std::ofstream f;
		f.open(path, std::ios::out);
		f.write(str.c_str(), str.size());
		f.close();
	}

	// 重置文件
	void reset()
	{
		std::ofstream file;
		file.open("save.data", std::ios::out);
		file.close();
	}
};