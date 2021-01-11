#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <vector>
#include <sstream>
#include<regex>
#include <fstream>
#include <typeinfo>
#include <direct.h>
using namespace std;

int main()
{
   ifstream infile;
   ofstream outfile;
   char data[100];

   infile.open("test.csv");

   cout << "Reading from the file" << endl;

//select时读文件for(i;maxsize;i++)
//data建立个结构体
//create的同时建立一个tablename_data(*).csv用于存储数据
//
//insert正则解析写入
//delete懒惰删除？

   infile >> data;

   // 在屏幕上写入数据
   cout << data << endl;

   // 再次从文件读取数据，并显示它
   infile >> data;
   cout << data << endl;

   // 关闭打开的文件
   infile.close();

   outfile.open("test.csv", ios::binary | ios::app | ios::in | ios::out);
   outfile.close();

   return 0;
}

