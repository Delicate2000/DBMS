#include <iostream>
using namespace std;
#include <string.h>
#include<regex>
#include <fstream>

#include "insert.cpp"


void initialize();
bool login(string username, string password);

//void split(const string &strtem, const char a , vector<string> &res)
//{
//	res.clear();
//	string::size_type pos1, pos2;
//	pos2 = strtem.find(a);
//	pos1 = 0;
//	while (string::npos != pos2)
//	{
//		res.push_back(strtem.substr(pos1, pos2 - pos1));
//		pos1 = pos2 + 1;
//		pos2 = strtem.find(a, pos1);
//	}
//	res.push_back(strtem.substr(pos1));
//}



int main()
{
    initialize();
    string create_sql = "create table ";
    string create_database_sql = "create database ";
    string insert_sql = "insert into ";
    string select_sql = "select ";
    string update_sql = "update ";
    string delete_sql = "delete ";
    string create_user = "create user ";
    string grant_sql = "grant ";
    string revoke_sql = "revoke ";
    string help_sql = "help table ";
    string use_sql = "use";
    string show_table_sql = "show tables";
    string username;
    string password;
    cout<<"username:";
    cin>>username;
    cout<<("password:");
    cin>>password;
    getchar();

    if (login(username, password))
    {
        string sql;
        while (true){
            cout<<">";
            getline(cin, sql);
            if (startswith(sql, create_sql))
                {createTable(username, sql);}
            else if (startswith(sql, create_database_sql))
                create_database(username, sql);
//            else if startswith(sql, use_sql))
//                use_database(username, sql);
            else if (startswith(sql, insert_sql))
                insertData(username, sql);
//            else if startswith(sql, select_sql))
//                Select.selectData(username, sql);
//            else if startswith(sql, update_sql))
//                Update.updateData(username, sql);
//            else if startswith(sql, delete_sql))
//                Delete.deleteData(username, sql);
//            else if startswith(sql, create_user))
//                CreateUser(sql);
//            else if startswith(sql, grant_sql))
//                GrantUser(sql, username);
//            else if startswith(sql, revoke_sql))
//                RevokeGrant(sql, username);
//            else if startswith(sql, help_sql))
//                HelpTable(sql);
//            else if startswith(sql, show_table_sql))
//                show_tables(username, sql);
//            else if (sql == "exit()")
//                break;
        }
    }
    else
        printf("false");





//    while(true)
//    {
//        cout<<">";
//        string sql;
//        cin>>sql;
//
//    }

//    //string str = "select * from hhh;";
//    //smatch result;
//    //regex pattern("select (.*) from (.*);");	//匹配5个任意单字符 + 下划线 + 4个数字
//    //cout<<regex_match(str, pattern)<<endl;
//
//    //if (regex_match(str, result, pattern))
//    //{
////        cout << result[0] << endl;		//完整匹配结果，Hello_2018
////        cout << result[1] << endl;		//第一组匹配的数据，Hello
////        cout << result[2] << endl;		//第二组匹配的数据，2018
////        cout<<"结果显示形式2"<<endl;
////        cout<< result.str() << endl;	//完整结果，Hello_2018
////        cout<< result.str(1) << endl;	//第一组匹配的数据，Hello
////        cout << result.str(2) << endl;	//第二组匹配的数据，2018
////    }
////
////    //遍历结果
////    for (int i = 0; i < result.size(); ++i)
////    {
////        cout << result[i] << endl;
////    }

	return 0;
}

void initialize()
{
    cout<<"欢迎"<<endl;
}

bool login(string username, string password)
{
    return true;
}
