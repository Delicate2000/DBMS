#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

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
//int main()
//{
//    ofstream outfile;
//    std::string out = "dbf";
//    std::string ap = ".csv";
//    out.append(ap);
//    outfile.open(out);
//
//    return 0;
//}
int  main()
{
      ifstream infile;
      string data;
   infile.open("student.csv");

   cout << "Reading from the file" << endl;
   infile >> data;
   cout << data << endl;
   infile >> data;

   // ����Ļ��д������
   cout << data << endl;

   // �ٴδ��ļ���ȡ���ݣ�����ʾ��
//   infile >> data;
//   cout << data << endl;

   // �رմ򿪵��ļ�
   infile.close();

   return 0;
}


//{
//
//    char* filePath;
//    char* filename = "//student.csv";
//    _getcwd(filePath, 256);
//    filePath= append(filePath,filename);
//    cout<<endl;
//
//    if (_access(filePath,0) == -1)
//
//    {
//        printf("The  file/dir doesn't exisit");
//
//    }
//
//    else
//
//    {
//         printf("Exisit ");
//
//    }
//
//    return 0;

