#pragma once

#include <string>
#include <iostream>

#include "person.h"
#include "person_list.h"

class App
{
public:
    // 初始化
    void init()
    {
        this->person_list.init();
        this->isRunning = true;
    }

    // 程序循环
    void run()
    {
        while (this->isRunning)
        {
            system("cls");
            std::cout << "#欢迎使用通讯录管理系统" << std::endl;
            std::cout << "======================" << std::endl;
            std::cout << "1 --> 添加成员" << std::endl;
            std::cout << "2 --> 删除成员" << std::endl;
            std::cout << "3 --> 搜索成员" << std::endl;
            std::cout << "4 --> 查看类表" << std::endl;
            std::cout << "5 --> 重置通讯录" << std::endl;
            std::cout << "6 --> 保存" << std::endl;
            std::cout << "======================" << std::endl;
            std::cout << "请输入:";
            std::string input;
            getline(std::cin, input);
            if (input == "1")
            {
                this->add();
            }
            else if (input == "2")
            {
                this->del();
            }
            else if (input == "3")
            {
                this->find();
            }
            else if (input == "4")
            {
                this->check_list();
            }
            else if (input == "5")
            {
                this->reset();
            }
            else if (input == "6")
            {
                this->save();
            }
            else
            {
                std::cout << "输入异常" << std::endl;
                system("pause");
            }
        }
    }

    // 退出
    void quit()
    {
		exit(0);
    }
private:
		// 添加成员
    void add()
    {
	    std::string name;
	    std::cout << "姓名:";
        getline(std::cin, name);
        std::string number;
        std::cout << std::endl;
        std::cout << "号码:";
        std::cin >> number;
        Preson person = {name, number};
        this->person_list.add(person);
        std::cout << "添加成功" << std::endl;
        system("pause");
    }

    // 删除成员
    void del()
    {
		std::string name;
        std::cout << "姓名:";
        getline(std::cin, name);
        int id = this->person_list.find(name);
        if (id == -1)
        {
			std::cout << "不存在此人" << std::endl;
        }
        else
        {
            this->person_list.del(id);
            std::cout << "删除成功" << std::endl;
        }
        system("pause");
    }

    // 查找成员
    void find()
    {
	    std::string name;
        std::cout << "姓名:";
        getline(std::cin, name);
        int id = this->person_list.find(name);
        if (id == -1)
        {
			std::cout << "不存在此人" << std::endl;
        }
        else
        {
            std::cout << "号码:" << this->person_list.list[id].number << std::endl;
        }
        system("pause");
    }

    // 查看成员列表
    void check_list()
    {
        for (int id = 0; id < this->person_list.list.size(); id++)
        {
            std::cout << this->person_list.list[id].name << " " << this->person_list.list[id].number << std::endl;
        }
        system("pause");
    }

    // 重置文件
    void reset()
    {
        this->person_list.reset();
        this->person_list.list.clear();
        std::cout << "已重置通讯录" << std::endl;
        system("pause");
    }

    // 保存
    void save()
    {
        this->person_list.save();
        std::cout << "通讯录已保存" << std::endl;
        system("pause");
    }

    PersonList person_list;
    bool isRunning;
};
