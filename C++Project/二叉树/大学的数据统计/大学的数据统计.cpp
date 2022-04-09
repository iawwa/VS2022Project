// 大学的数据统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include<string>
#include<vector>
#include<fstream>

//#include"TSonNode.h"

using namespace std;

typedef struct tsonode
{
    string data="";
    struct tsonode* sons[3] = {NULL,NULL,NULL};
}TSonNode;

void hahagive(TSonNode*& b, string value);

TSonNode* Find(TSonNode *b,string a) 
{
    if (b == NULL)
        return NULL;
    else if (b->data == a)
        return b;
    else 
    {
        if (Find(b->sons[0], a) != NULL)
            return Find(b->sons[0], a);
        else 
        {
            if (Find(b->sons[1], a) != NULL)
                return Find(b->sons[1], a);
            else
                return Find(b->sons[2], a);
        }
    }
   
}

vector<string> read_file_arr()
{
    vector<string> a;
    string str;
    fstream infile;
    infile.open("abc.txt");
    while (infile)
    {
        infile >> str;
        a.push_back(str);
    }
    a.pop_back();
    return a;
}

TSonNode* create_ts_tree(vector<string>& a) 
{
    TSonNode* m;
    TSonNode* t;
    t = new TSonNode();
    t->sons[0] = NULL;
    t->sons[1] = NULL;
    t->sons[2] = NULL;
    int i = 0,n=0;
    string key, value;
    while (i < a.size())
    {
        n = 0;
        key = a[i];
        i++;
        value = a[i];
        i++;
        m = Find(t, key);
        if (m == NULL)
        {
            t->data = key;
            hahagive(t->sons[0], value);
        }
        else 
        {
            while (n<3)
            {
                if (m->sons[n] == NULL)
                {
                    //m = new TSonNode();
                   // m->sons[0] = NULL;
                   // m->sons[1] = NULL;
                   // m->sons[2] = NULL;
                    //Find(t, key)->sons[i] = m;
                   // m->data = value;
                   hahagive(m->sons[n], value);
                    break;
                }
                n++;
            }
        }
    }

    return t;
}

void hahagive(TSonNode *&b,string value) 
{
    TSonNode *m;
    m = new TSonNode();
    m->sons[0] = NULL;
    m->sons[1] = NULL;
    m->sons[2] = NULL;
    m->data = value;
    b = m;
}

void Display_TS(TSonNode *b) 
{
    if (b != NULL)
        cout << b->data;
    if (b->sons[0] != NULL || b->sons[1] != NULL || b->sons[2] != NULL) 
    {
        cout << "(";
        Display_TS(b->sons[0]);
        if (b->sons[1] != NULL || b->sons[2] != NULL)
        {
            cout << ",";
            Display_TS(b->sons[1]);
            if ( b->sons[2] != NULL)
            {
                cout << ",";
                Display_TS(b->sons[2]);
            }
        }
        cout << ")";
    }
}

int sum_s(TSonNode *t) //学生数
{
    int i = 0, j = 0,k=0;
    int sum = 0;
    while (i < 3)
    {
        j = 0;
        if (t->sons[i] != NULL)
            while (j < 3)
            {
                k = 0;
                if (t->sons[i]->sons[j] != NULL)
                    while (k < 3)
                    {
                        if (t->sons[i]->sons[j]->sons[k] != NULL)
                        {
                            sum = sum + atoi(t->sons[i]->sons[j]->sons[k]->data.c_str());
                        }
                        k++;
                    }
                j++;
            }
        i++;
    }
    return sum;
}


int sum_m(TSonNode *t) //专业数
{
    int i = 0;
    int sum = 0;
    while (i < 3)
    {
        if (t->sons[i] != NULL)
            sum++;
        i++;
    }
    return sum;
}

int sum_c(TSonNode* t) //班级数
{
    int i = 0,j=0;
    int sum = 0;
    while (i < 3)
    {
        j = 0;
        if (t->sons[i] != NULL)
            while (j < 3)
            {
                if (t->sons[i]->sons[j] != NULL)
                    sum++;
                j++;
            }
        i++;
    }
    return sum;
}


void Des_TS(TSonNode*& t) 
{
    if (t != NULL)
    {
        Des_TS(t->sons[0]);
        Des_TS(t->sons[1]);
        Des_TS(t->sons[2]);
        free(t);
        //delete t;
    }
}

void menu() 
{
    vector<string> R;
    TSonNode* t;
    t = new TSonNode;
    string str;
    int i = 0;
    while (true) 
    {
        cout << "输入对应操作编号：" << endl;
        cout << "(1)从abc.txt文件读取数据到数组：" << endl;
        cout << "(2)由数组创建孩子链存储结构的树：" << endl;
        cout << "(3)用括号表示法输出树：" << endl;
        cout << "(4)求某学院的专业数：" << endl;
        cout << "(5)求某学院的班数：" << endl;
        cout << "(6)求某学院学生数" << endl;
        cout << "(7)销毁树：" << endl;
        cin >> i;
        if (i == 1)
        {
            R=read_file_arr();
            cout << "do it." << endl;
        }
        else if (i == 2)
        {
            t=create_ts_tree(R);
            cout << "do it." << endl;
        }
        else if (i == 3)
        {
            Display_TS(t);
            cout << "do it." << endl;
        }
        else if (i == 4)
        {
            cout << "输入该学院名称：" << endl;
            cin >> str;
            cout << "专业数:" << sum_m(Find(t, str)) << endl;
        }
        else if (i == 5)
        {
            cout << "输入该学院名称：" << endl;
            cin >> str;
            cout << " 班数:" << sum_c(Find(t, str)) << endl;
        }
        else if (i == 6)
        {
            cout << "输入该学院名称：" << endl;
            cin >> str;
            cout << "学生数:" << sum_s(Find(t, str)) << endl;
        }
        else if (i == 7)
        {
            Des_TS(t);
        }
        else 
        {
            break;
        }
    }
}

int main()
{
    menu();
    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
