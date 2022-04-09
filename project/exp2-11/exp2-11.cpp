// exp2-11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
using namespace std;
class sdata 
{
public:
    sdata() :no(0), depno(0), name(""), salary(0)
    {}
    int no, depno;
    char name[3];
    float salary;
};
typedef struct work
{
    sdata data;
    struct work* next;
}staff;
staff* sread()
{
    staff *list,*newlist;
    list= (staff *)malloc(sizeof(staff));
    list->next = NULL;
    ifstream infile;
    infile.open("D:\\project\\emp.dat");
    while (infile)
    {
        newlist = (staff *)malloc(sizeof(staff));
        infile >> newlist->data.no >> newlist->data.name >> newlist->data.depno >> newlist->data.salary;
        newlist->next = list->next;
        list->next = newlist;
    }
    infile.close();
    list->next = list->next->next;
    cout << endl << "done!"<<endl;
    return list;
}
void sinput(staff* list) 
{   
    staff* newlist;
    newlist = (staff *)malloc(sizeof(staff));
    cout << "input the staff's information(no,name,depno,salary):" << endl;
    cin >> newlist->data.no>>newlist->data.name>> newlist->data.depno >> newlist->data.salary;
    newlist->next = list->next;
    list->next = newlist;
    cout << endl << "done!" << endl;
}
void sshow(staff* list)
{
    list = list->next;
    while (list != NULL) 
    {
        cout << endl << "no=" << list->data.no << " name=" << list->data.name << " depno=" << list->data.depno << " salary=" << list->data.salary;
        list = list->next;
    }
    cout << endl << "done!" << endl;
}
void ssort(staff* &list) 
{
    int stmp;
    cout << "input the sort you want to rely on(no:1,depno:2,salary:3):" << endl;
    cin >> stmp;
    if (stmp == 1)
    {
        staff* p, * pre, * q;
        p = list->next->next;
        list->next->next = NULL;
        while (p != NULL)
        {
            q = p->next;
            pre = list;
            while (pre->next != NULL && pre->next->data.no < p->data.no)
            {
                pre = pre->next;
            }
            p->next = pre->next;
            pre->next = p;
            p = q;
        }
    }

    else if (stmp == 2) 
    {
        staff* p, * pre, * q;
        p = list->next->next;
        list->next->next = NULL;
        while (p != NULL)
        {
            q = p->next;
            pre = list;
            while (pre->next != NULL && pre->next->data.depno < p->data.depno)
            {
                pre = pre->next;
            }
            p->next = pre->next;
            pre->next = p;
            p = q;
        }
    }
    else if (stmp == 3) 
    {
        staff* p, * pre, * q;
        p = list->next->next;
        list->next->next = NULL;
        while (p != NULL)
        {
            q = p->next;
            pre = list;
            while (pre->next != NULL && pre->next->data.salary < p->data.salary)
            {
                pre = pre->next;
            }
            p->next = pre->next;
            pre->next = p;
            p = q;
        }
    }
    else 
    {
        cout << "No operation."<<endl;
    }
    cout << endl << "done!" << endl;

}
void sdelete(staff* &list)
{
    int nono;
    cout << "input the no:" << endl;
    cin >> nono;
    staff *pre,*p;
    pre = list;
    while (pre->next!= NULL)
    {
        if (pre->next->data.no == nono)
        {
            p = pre->next;
            pre->next = p->next;
            free(p);
        }
        pre = pre->next;
        if (pre== NULL)break;
    }
    cout << endl << "done!" << endl;
}
void sdestroy(staff* &list) 
{
    staff* pre = list, * p = list->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
    cout << endl << "done!" << endl;
}
void ssave(staff* list) 
{
    ofstream outfile;
    list = list->next;
    outfile.open("D:\\project\\emp.dat");
    while (list != NULL)
    {
        outfile << list->data.no << " " << list->data.name << " " << list->data.depno << " " << list->data.salary << " ";
        list = list->next;
    }
    cout << endl << "done!" << endl;
}
void menu(staff* &list) 
{
    
    cout <<endl<< "(1)从emp.dat文件中读出职工记录，并建立一个带头节点的单链表L。(自动)"<<endl;
    cout << "(2)输入一个职工记录。" << endl;
    cout << "(3)显示所有职工记录。" << endl;
    cout << "(4)进行递增排序。" << endl;
    cout << "(5)删除指定职工号的职工记录。"<<endl;
    cout << "(6)删除职工文件中的全部记录。" << endl;
    cout << "(7)将单链表L中的所有职工记录存储到职工文件emp.dat中。" << endl;
    cout << "(0)结束" << endl;
    cout << "输入你操作的编号:" << endl;
    int num;
    while (true) 
    {
        cin >> num;
        if (num == 1)
        {    
        }
        else if (num == 2)
        {
            sinput(list);
        }
        else if (num == 3)
        {
            sshow(list);
        }
        else if (num == 4)
        {
            ssort(list);
        }
        else if (num == 5)
        {
            sdelete(list);
        }
        else if (num == 6)
        {
            sdestroy(list);
        }
        else if (num == 7)
        {
            ssave(list);
        }
        else if (num == 0)
        {
            break;
        }
        else 
        { 
            continue; 
        }
    }
    cout << endl << "done!" << endl;
}
int main()
{    
    staff* list;
    list = sread();
    menu(list);
    system("pause");
    return 0;
}




/*
#include<iostream>
#include<string>
                      //(1) 将用户输入的十进制整数字符串转化为带头结点的单链表，每个结点存放一个整数位using namespace std;//（2）求两个整数单链表相加的结果单链表
typedef struct num //（2）求结果单链表的中间位，如123的中间位为2，1234的中间位为2.
{
    char n;
    struct num* next;
}Num;
Num *read_num(string &m) 
{
    Num *L,*r,*p;
    L = (Num*)malloc(sizeof(Num));
    L->next = NULL;
    r = L;
    int i=0;
    while (m[i] != NULL)
    {
        p=(Num*)malloc(sizeof(Num));
        p->next=NULL;
        p->n = int(m[i]);
        r->next = p;
        r = p;
        i = i + 1;
    }
    return L;
}
void display(Num *list) 
{
    Num* p;
    p = list->next;
    while (p!= NULL)
    {
        cout << p->n << " ";
        p = p->next;
    }
    cout << endl;
}
int main() 
{
    string m;
    Num* List;
    cout << "input the num:" << endl;
    cin >> m;
    List=read_num(m);
    display(List);
    system("pause");
    return 0;
}   

*/
















// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
