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
#include "create.cpp"

using namespace std;



void insertData(string username,string sql)
{
   std::string str = sql;
   std::string table_name;
   std::string insert_data;
   std::string data_name;
   char* tail = "_data.csv";
   char* temp;
   char* temp_data;
   char* temp_data_name;
   char* filename;
   ofstream outfile;
   ifstream infile;

   std::string title;// 表的属性名
   vector<string> title_name;
   vector<string> all_data_name;
   vector<string> all_insert_data;


   smatch result;
   regex pattern("insert into (.*) [(](.*)[)] values [(](.*)[)];");

   if (regex_match(str, result, pattern)){
        table_name = std::string(result[1]);
        data_name = std::string(result[2]);
        insert_data = std::string(result[3]);
        //cout<<insert_data;

        temp = (char*)(table_name.data());
        temp_data = (char*)(table_name.data());
        temp_data_name = (char*)(data_name.data());
        filename = append(temp,tail);
        split(data_name,',',all_data_name);
        split(insert_data,',',all_insert_data);

        infile.open(filename);
        if(!infile){
               printf("open or create file error!");
               exit(1);
            }
        else{
            infile >> title;
            title = string(title);
            split(title,',',title_name);
            infile.close();
        }

        outfile.open(filename, ios::binary | ios::app | ios::in | ios::out);
// ios::app 追加模式。所有写入都追加到文件末尾。
//ios::ate 文件打开后定位到文件末尾。
//ios::in 打开文件用于读取。
//ios::out 打开文件用于写入。
//ios::trunc 如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0

        //cout<<title_name[2]<<endl;
        //cout<<title_name.size();

        string record[10000]; //记录最终存放的data样子
        if(!outfile){
               printf("open or create file error!");
               exit(1);
            }
        else
        {
            for(int i = 0; i < title_name.size(); i++)
            {
                record[i] ="NULL";
                for(int j=0;j<all_data_name.size();j++)
                {
//                   cout<<"1"<<all_data_name[j]<<endl;
//                   cout<<"2"<<title_name[i]<<endl;
                   if(all_data_name[j]==title_name[i]) {record[i]= all_insert_data[j];break;}
                }
                //cout<<record[i]<<endl;
                outfile << record[i] <<"," ;
            }
            outfile << endl;
            outfile.close();
        }


   }

}
