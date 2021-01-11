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

char * append(char *s1,char *s2){
	char *tmp;
	int length;
	length=strlen(s1)+strlen(s2);
	tmp = new char[length+1];
	strcpy(tmp,s1);
	strcat(tmp,s2);
	return tmp;
}

//create table test(int sno,char sname)

//int startsWith(string s, string sub){
//        return s.find(sub)==0?1:0;
//}
//
//int endsWith(string s,string sub){
//        return s.rfind(sub)==(s.length()-sub.length())?1:0;
//}
typedef struct {
  vector<std::string> name;
  vector<std::string> type;
  vector<bool> NotNull;
  vector<bool> PrimaryKey;
  int Size;

  } TableMode,*PTableMode;

bool is_PrimaryKey(string item)
{
    string clue = "PRIMARY KEY";
    int position = item.find(clue);
    if (position != item.npos)
        return false;
    else
        return true;
}

bool is_NotNull(string item)
{
    string clue = "NOT NULL";
    int position = item.find(clue);
    if (position != item.npos)
        return false;
    else
        return true;
}

int startswith(string s, string sub){
        return s.find(sub)==0?1:0;
}

int endsWith(string s,string sub){
        return s.rfind(sub)==(s.length()-sub.length())?1:0;
}



void split(const string &strtem, const char a , vector<string> &res)
{
	res.clear();
	string::size_type pos1, pos2;
	pos2 = strtem.find(a);
	pos1 = 0;
	while (string::npos != pos2)
	{
		res.push_back(strtem.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
		pos2 = strtem.find(a, pos1);
	}
	res.push_back(strtem.substr(pos1));
}

void createTable(string username,string sql)
{
    std::string str = sql;
    std::string csv = ".csv";
    char* data;
    char* data_csv = "_data.csv";
    smatch result;
    regex pattern("create table (.*) [(](.*)[)];");
    std::string dbf;
    std::string table_name; //接受result进行转换
    ofstream outfile;
    ofstream outfile2;// 开对应data文件
    ifstream infile;
    TableMode Table;Table.Size=0;
    std::string Title = "Name,Type,IsPrimaryKey,IsNotNULL";


    if (regex_match(str, result, pattern)){
        char* filePath;
        char* head = "//";
        char* tail = ".csv";
        _getcwd(filePath, 256);

        table_name= std::string(result[1]);
         //dbf =(char*)table_name.data();
         dbf = table_name.data();
         char* temp = (char*)(table_name.data());

         data = append(temp, data_csv); //对应的data文本
         head = append(head,temp);
         head = append(head,tail);
         filePath= append(filePath,head);

         //判断表是否已存在
         if (_access(filePath,0) == -1)
         {
             dbf.append(csv);//拼接文件名
             string strt = string(result[2]);

             vector<string> vctt;
             split(strt,',',vctt);

            //cout<<vctt.size()<<endl;

            for(int i = 0; i < vctt.size(); i++)
            {
                smatch result2;
                //空格也要对应
                regex pattern2("(.*) (int|char([(])(.*)([)])|datetime)(.*)");
                //cout<<vctt[i]<<endl;
                std::string str2 = vctt[i];
                //std::string str2 = "name char(20)";
                 if (regex_match(str2, result2, pattern2)){
//                     cout<<"属性名:"<<result2[1]<<endl;
//                     cout<<"类型:"<<result2[2]<<endl;
//                     cout<<"约束:"<<result2[6]<<endl;
                     Table.name.push_back(result2[1]);
                     Table.type.push_back(result2[2]);

                     if (is_PrimaryKey(result2[6]))
                        Table.PrimaryKey.push_back(true);
                     else
                        Table.PrimaryKey.push_back(false);

                    if (is_NotNull(result2[6]))
                        Table.NotNull.push_back(true);
                     else
                        Table.NotNull.push_back(false);
                    Table.Size ++;
                 }
            }

            //cout<<Table.Size<<endl;

            outfile.open(dbf); //创建table
            outfile2.open(data); //创建对应数据库
           if(!outfile||!outfile2){
               printf("open or create file error!");
               exit(1);
            }
           else{
                outfile << Title << endl;
                for(int i = 0; i < Table.Size; i++)
                {
                    outfile << Table.name[i] <<","<< Table.type[i] <<","<<  Table.PrimaryKey[i]<<","<<  Table.NotNull[i]<< endl;
                    outfile2 << Table.name[i]<<",";
                }
                outfile2 << endl;
           }
            cout<<table_name<<" has been successfully created"<<endl;
            outfile.close();
            outfile2.close();
        }
        else
            cout<<table_name<<" has exisited or is system file"<<endl;
    }

    else cout<<"sql语法有错误"<<endl;
}


void create_database(string username,string sql)
{
    cout<<"成功create database"<<endl;
}


