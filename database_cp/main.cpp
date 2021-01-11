#include <iostream>
using namespace std;
#include <string.h>
#include<regex>
#include <fstream>

#include "select.cpp"


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
            else if (startswith(sql, select_sql))
                selectData(username, sql);
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
