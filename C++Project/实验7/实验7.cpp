// 实验7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Box 
{
public:
    int x, y;
};
typedef struct haha
{
    int x,y;
    struct haha* next;
}LinkStNode;
void Add(LinkStNode*& l,Box e)
{
    LinkStNode *p;
    p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->next = NULL;
    p->x = e.x;
    p->y = e.y;
    p->next = l->next;
    l->next = p;
}
void Pop(LinkStNode*& l)
{
    if (l->next!=NULL) 
    {
        l->next = l->next->next;
    }
}
void GetHead(LinkStNode* l,Box &e)
{
    if (l->next != NULL) 
    {
        e.x = l->next->x;
        e.y = l->next->y;
    }
    else 
    {
        e.x = 0;
        e.y = 0;
    }
}
bool Judge(LinkStNode* l,Box e) 
{
    LinkStNode *ll;
    ll = l->next;
    while (ll != NULL)
    {
        if (e.x == ll->x) 
        { 
            return false;
        }
        if (e.y == ll->y) 
        { 
            return false;
        }
        if ((e.y - ll->y) == (e.x - ll->x) )
        {
            return false;
        }
        if ((e.y - ll->y) == (ll->x-e.x))
        {
            return false;
        }
        ll = ll->next;
    }
    return true;
}
void Finish() 
{

    int n,k=0,num=0;
    Box e;

    cout<< "输入n：" << endl;
    cin >> n;

    e.x = 1;
    e.y = 1;
    LinkStNode *l,*ll;
    l = (LinkStNode*)malloc(sizeof(LinkStNode));
    l->x = 0;
    l->y = 0;
    l->next = NULL;

    Add(l,e);
    //while(l->next!=NULL)
    while (true)
    {
        
        GetHead(l, e);
        if (l->next!=NULL) 
        {
            if (l->next->y == n)
            {
                ll = l;
                while (ll->next != NULL)
                {
                    cout << "(" << ll->next->x << "," << ll->next->y << ")" << " ";
                    ll = ll->next;
                }
                cout << endl;
                GetHead(l, e);
                Pop(l);
                k = e.x;
                num++;
            }
            
        }
        e.x = 1+k;
        e.y++;
        while (e.x<n)
        {
            if (Judge(l, e) == true)
            {
                break;
            }
            e.x++;
        }
        if (e.x > n && e.y == 1) { break; }
        if (Judge(l, e) == true&&e.x<=n) 
        { 
            Add(l, e);
            k = 0;
        }
        else
        {
            GetHead(l, e);
            Pop(l);
            k = e.x;
        }
        
    }
    cout << "num=" << num<<endl;
}
int main()
{
    Finish();
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






/*
* 
* 
*    
        if (l->la.y == n)//do it 
        {
            ll = l->next;
            while (ll->next != NULL)
            {
                cout << "(" << ll->la.x << "," << ll->la.y << ")" << " ";
                ll = ll->next;
            }
            cout << endl;
            Pop(l);
            GetHead(l, e);
            k = e.x;
        }
* 
* 
* 
* 
* 
* 
* 
* 
*/