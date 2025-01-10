#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "person.h"
#include "file_tool.h"

class PersonList
{
public:
	// 初始化列表
	void init()
    {
        std::string file_str;
        this->file_tool.read("save.data", file_str);
        std::stringstream ss_line(file_str);
        std::string str_line;
        while (std::getline(ss_line, str_line, ';'))
        {
            std::stringstream ss(str_line);
            std::string str_name;
            std::string str_number;
            std::getline(ss, str_name, ',');
            std::getline(ss, str_number, ',');
            Preson preson = { str_name, str_number };
            this->list.push_back(preson);
        }
    }

    // 保存列表
    void save()
    {
        std::string file_str = "";
        for (int id = 0; id < this->list.size(); id++)
        {
            file_str += (this->list[id].name + "," + this->list[id].number + ";");
        }
        this->file_tool.write("save.data", file_str);
    }

    // 添加成员
    void add(Preson person)
    {
		this->list.push_back(person);
    }

    // 删除成员
    void del(int id)
    {
		this->list.erase(this->list.begin() + id);
    }

	// 搜索成员
    int find(std::string name)
    {
		for (int id = 0; id < this->list.size(); id++)
		{
            if (this->list[id].name == name)
            {
                return id;
            }
            else
            {
                continue;
            }
        }
        return -1;
    }

    // 重置文件
    void reset()
    {
        this->file_tool.reset();
    }

	std::vector<Preson> list;
private:
    FileTool file_tool;
};