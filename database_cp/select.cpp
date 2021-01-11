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
#include <iomanip>
#include "insert.cpp"

using namespace std;
struct Data
{
    int type_num;
    vector<std::string>type_name;
    vector<vector<std::string>> content;
    vector<string> vn; //用于push到content中
};

void selectData(string username,string sql)
{
    //int x,y;定义存储维度
    std::string str = sql;
    std::string csv = "_data.csv";
    std::string title;// 表的属性名
    std::string table_name;// 表文件名
    std::string result_name;
    std::string condition;
    vector<string> title_name;
    vector<string> splited_raw_data;
    vector<string> need_title;
    vector<vector<std::string>> temp_answer;
    vector<vector<std::string>> answer;//搜索结果，行列倒置？
    vector<string> temp;
    vector<string> condition_construct;

    char* data;
    std::string data_csv = "_data.csv";
    smatch result;
    regex pattern("select (.*) from (.*);");
    ifstream infile;

    smatch result2;
    regex pattern2("select (.*) from (.*) where (.*);");

    //无where查询

     if (regex_match(str, result, pattern) && string(result[0]).find("where")==string(result[0]).npos)
     {
         table_name = std::string(result[2]);
         result_name = std::string(result[1]);
         table_name = table_name + csv;
         char * temp_table_name = (char*)(table_name.data());

         infile.open(temp_table_name);

         if(!infile){
            printf("open or create file error!");
            exit(1);
         }
        else{
             infile >> title;
             title = string(title);
             split(title,',',title_name);

             int x = title_name.size();
             int y = get_line(table_name)-1;

             string content[y][x];//存储所有数据;y为行数，为列数
             //cout<<x;

            for(int i=0;i<y;i++)
            {
                string raw_data;
                infile >> raw_data;
                split(raw_data,',',splited_raw_data);
                for(int j=0;j<x;j++)
                {
                    content[i][j] = splited_raw_data[j];
                }
            }

            if(result_name == "*"){
                for(int k=0;k<x;k++)
                {
                    cout<<setw(8)<<title_name[k]<<"|";
                }
                cout<<endl;
                cout<<"---------------------------"<<endl;

                for(int i=0;i<y;i++)
                {
                    for(int j=0;j<x;j++)
                    {
                        cout<< setw(8)<<content[i][j]<<"|";
                    }
                    cout<<endl;
                }
            }
            else{
                split(result_name,',',need_title);
                for(int z=0;z<need_title.size();z++)
                {
                    cout<<setw(8)<<need_title[z]<<"|";
                }
                cout<<endl;
                cout<<"---------------------------"<<endl;

                for(int i=0;i<x;i++)
                {
                    for(int j=0;j<need_title.size();j++)
                    {
                        if ((need_title[j]==title_name[i]))
                        {
                            for(int k=0;k<y;k++)
                            //cout<< setw(8)<<content[k][i]<<"|"<<endl;
                            temp.push_back(content[k][i]);
                            //cout<<temp[2]<<endl;
                            answer.push_back(temp);//需要倒置输出
                            temp.clear();
                        }
                        //cout<<endl;
                    }
                }

               for(int i=0;i<y;i++)
                {
                    for(int j=0;j<answer.size();j++)
                        cout<<setw(8)<<answer[j][i]<<"|";
                    cout<<endl;
                }
                //cout<<1;
            }
            infile.close();
        }

     }

     //带where的sql查询
     else if(regex_match(str, result2, pattern2))
     {
         table_name = std::string(result2[2]);
         result_name = std::string(result2[1]);
         condition = std::string(result2[3]);
         table_name = table_name + csv;
         char * temp_table_name = (char*)(table_name.data());

        // cout<<condition<<endl;

         infile.open(temp_table_name);

         if(!infile){
            printf("open or create file error!");
            exit(1);
         }
        else{
             infile >> title;
             title = string(title);
             split(title,',',title_name);

             int x = title_name.size();
             int y = get_line(table_name)-1;

             string content[y][x];
             //将所有数据存储到content中
             for(int i=0;i<y;i++)
             {
                string raw_data;
                infile >> raw_data;
                split(raw_data,',',splited_raw_data);
                for(int j=0;j<x;j++)
                {
                    content[i][j] = splited_raw_data[j];
                }
             }

            if (condition.find("and")!= condition.npos)
                cout<<"unsupported function"<<endl;
            else if (condition.find("or")!= condition.npos)
                cout<<"unsupported function"<<endl;
            else{
                 if(condition.find("=")!= condition.npos)
                 {
                     split(condition,'=',condition_construct);
                     if (result_name == "*")//放最外面
                     {
                        for(int k=0;k<x;k++)
                        {
                            cout<<setw(8)<<title_name[k]<<"|";
                        }
                        cout<<endl;
                        cout<<"---------------------------"<<endl;

                        for(int i=0;i<title_name.size();i++)
                        {
                                if (condition_construct[0]==title_name[i])  //寻找条件对应的属性,i控制列相同
                                {
                                    for(int k=0;k<y;k++)
                                    {
                                        if(condition_construct[1]== content[k][i])   //寻找满足条件的值
                                        {
                                            //cout<<2<<endl;
                                            for(int m=0;m<x;m++)
                                            {
                                                temp.push_back(content[k][m]);
                                                //cout<<content[k][m];
                                            }
                                            answer.push_back(temp);//把这一行存放到anwser中
                                            temp.clear();
                                        }
                                    }
                                }
                        }
                        for(int i=0;i<y;i++)
                        {
                            for(int j=0;j<x;j++)
                            {
                                cout<< setw(8)<<answer[i][j]<<"|";
                            }
                            cout<<endl;
                        }
                     }
                     else
                     {
                         split(result_name,',',need_title);
                         //先如上挑选数据
                         for(int i=0;i<title_name.size();i++)
                         {
                                if (condition_construct[0]==title_name[i])  //寻找条件对应的属性,i控制列相同
                                {
                                    for(int k=0;k<y;k++)
                                    {
                                        if(condition_construct[1]== content[k][i])   //寻找满足条件的值
                                        {
                                            //cout<<2<<endl;
                                            for(int m=0;m<x;m++)
                                            {
                                                temp.push_back(content[k][m]);
                                                //cout<<content[k][m];
                                            }
                                            temp_answer.push_back(temp);//把这一行存放到anwser中
                                            temp.clear();
                                        }
                                    }
                                }
                         }

                        for(int i=0;i<x;i++)
                        {
                            for(int j=0;j<need_title.size();j++)
                            {
                                if ((need_title[j]==title_name[i]))
                                {
                                    for(int k=0;k<temp_answer.size();k++)
                                    //cout<< setw(8)<<content[k][i]<<"|"<<endl;
                                    temp.push_back(temp_answer[k][i]);
                                    //cout<<temp[2]<<endl;
                                    answer.push_back(temp);//需要倒置输出
                                    temp.clear();
                                }
                                //cout<<endl;
                            }
                        }
                        for(int z=0;z<need_title.size();z++)
                        {
                            cout<<setw(8)<<need_title[z]<<"|";
                        }
                        cout<<endl;
                        cout<<"---------------------------"<<endl;

                        for(int i=0;i<x;i++)
                        {
                            for(int j=0;j<answer.size();j++)
                                cout<<setw(8)<<answer[j][i]<<"|";
                            cout<<endl;
                        }

                     }

                 }
                 //for(int i=0;i<title_name.size())
                 /*for(int i=0;i<answer.size();i++)
                 {
                     for(int j=0;j<3;j++)
                     {
                         cout<<answer[i][j];
                     }
                     cout<<endl;
                 }
                for(int i=0;i<temp_answer.size();i++)
                 {
                     for(int j=0;j<answer.size();j++)
                     {
                         cout<<answer[j][i];
                     }
                     cout<<endl;
                 }*/


            }
            infile.close();
        }
     }
     else
        cout<<"wrong with sql"<<endl;

}
