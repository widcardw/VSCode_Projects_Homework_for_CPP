#include <iostream>
#include "date.h"
#include "course.h"
#include "stu.h"
#include "queue.h"
#include <fstream>
#include <cassert>
using namespace std;
/*
int main()
{
    ifstream fin("stu.txt");
    if (!fin)
    {
        cout << "Cannot open the file!" << endl;
        exit(1);
    }
    int num;
    fin >> num;
    Student *stu;
    stu = new Student[num];
    for (int i = 0; i < num; ++i)
    {
        fin >> stu[i];
        cout << stu[i] << endl;
    }
    return 0;
}*/
Node *find_data(Queue *q, string str);
int main()
{
    int opt = 0;
    Queue q;
    QueueInit(&q);

    while (1)
    {
        cout << "====================\n|  1: add student  |\n|  2: read file    |\n|  3: find data    |\n|  4: delete data  |\n|  5: print data   |\n|  6: output file  |\n|  0: exit         |" << endl;
        cout << "====================\nChoice: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            Student s;
            cout << "name;id;birthdate;term;course_name;teacher;score" << endl;
            cin >> s;
            QueuePush(&q, s);
            break;
        }
        case 2:
        {
            string str;
            cout << "input file name: ";
            cin >> str;
            ifstream fin;
            fin.open(str);
            if (!fin)
            {
                cout << "Cannot open the file!" << endl;
                exit(1);
            }
            int num;
            fin >> num;
            Student s;
            for (int i = 0; i < num; ++i)
            {
                fin >> s;
                QueuePush(&q, s);
            }
            fin.close();
            break;
        }
        case 3:
        {
            cout << "input id:";
            string strid;
            cin >> strid;
            cout << find_data(&q, strid)->data_ << endl;
            break;
        }
        case 4:
        {
            cout << "input id: ";
            string strid;
            cin >> strid;
            Node *target = find_data(&q, strid);
            if (target != NULL)
            {
                Node *p1 = q.front_->pNext_, *p2 = q.front_;
                while (p1 != NULL && p1 != target)
                {
                    p1 = p1->pNext_;
                    p2 = p2->pNext_;
                }
                p2->pNext_ = p1->pNext_;
                free(p1);
                p1 = p2->pNext_;
            }
            break;
        }
        case 5:
        {
            Node *pCur = q.front_;
            while (pCur != NULL)
            {
                cout << pCur->data_ << endl;
                pCur = pCur->pNext_;
            }
            break;
        }
        case 6:
        {
            ofstream fout;
            cout << "output file name: ";
            string str;
            cin >> str;
            fout.open(str);
            if (!fout)
            {
                cout << "Cannot open the file!" << endl;
                exit(-1);
            }
            Node *pCur = q.front_;
            while (pCur != NULL)
            {
                fout << pCur->data_ << endl;
                pCur = pCur->pNext_;
            }
            fout.close();
            break;
        }
        default:
            exit(0);
        }
    }
    return 0;
}

Node *find_data(Queue *q, string str)
{
    int count = 0;
    Node *pCur = q->front_;
    while (str != pCur->data_.rtn_id())
    {
        ++count;
    }
    if (count > QueueSize(q))
    {
        cout << "cannot find data" << endl;
        return NULL;
    }
    return pCur;
}