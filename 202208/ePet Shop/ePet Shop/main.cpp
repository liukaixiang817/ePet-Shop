//
//  main.cpp
//  ePet Shop
//
//  Created by 刘凯翔 on 2022/8/29.
//
#include <iostream>
#include <cstring>
#include <fstream>
//#include <windows.h>
#include <unistd.h>
using namespace std;
class usr
{
private:
    int id,type;//Ids were sorted by the order. type=1 is the administrator; type=2 is the shopkeeper.
    string name,passwd;//name is account owner's name; passwd is the password
    bool status;//the normal value is 1
    static int cnt;//the quantity of accounts
public:
    int g_cnt()//"g_" is get and "e_" is edit
    {
        return cnt;
    }
    bool g_status()
    {
        return status;
    }
    void pp_cnt()
    {
        cnt++;
    }
    void mm_cnt()
    {
        cnt--;
    }
    void e_cnt(int x)
    {
        cnt=x;
    }
    void e_status(bool x)
    {
        status=x;
    }
    int g_type()
    {
        return type;
    }
    int g_id()
    {
        return id;
    }
    string g_name()
    {
        return name;
    }
    string g_passwd()
    {
        return passwd;
    }
    void e_id(int x)
    {
        id=x;
    }
    void e_type(int x)
    {
        type=x;
    }
    void e_name(string x)
    {
        name=x;
    }
    void e_passwd(string x)
    {
        passwd=x;
    }
    usr()
    {
        id=0;
        type=0;
        name="0";
        passwd="0";
        status="0";
    }
    usr(string x1,string x2,int type_t)
    {
        id=cnt;
        type=type_t;
        name=x1;
        passwd=x2;
        status=1;
        pp_cnt();
    }
    void read()
    {
        fstream in_usr;
        in_usr.open("user.txt");
        in_usr>>cnt;
        for(int i=0;i<cnt;i++)
        {
            in_usr>>id>>type>>status>>name>>passwd;
        }
        in_usr.close();
    }
};
int usr::cnt=0;
int main(int argc, const char * argv[]) {
    usr u[109];
    fstream in_usr;
    in_usr.open("user.txt");
    int tp;
    in_usr>>tp;
    u[0].e_cnt(tp);
    for(int i=0;i<u[0].g_cnt();i++)
    {
        int q1,q2;
        bool q3;
        string q4,q5;
        in_usr>>q1>>q2>>q3>>q4>>q5;
        u[i].e_id(q1);
        u[i].e_type(q2);
        u[i].e_status(q3);
        u[i].e_name(q4);
        u[i].e_passwd(q5);
    }
    in_usr.close();
    mai:
    cout<<"Welcome to ePet Shop"<<endl;
    cout<<"The default administrator's user id is 0 and user's password is \"Root\""<<endl;
    cout<<"1.Login"<<endl;
    cout<<"2.Add a shopkeeper account"<<endl;
    cout<<"Other:Exit the program"<<endl;
    char t1;
    cout<<"Please input your choice:";
    cin>>t1;
    fflush(stdin);
    switch(t1)
    {
        case '1':
        A1:
        {
            char s1;
            string s2;
            cout<<"Please input your ID and Password..."<<endl;
            cout<<"ID:";
            cin>>s1;
            fflush(stdin);
            cout<<"Password:";
            cin>>s2;
            fflush(stdin);
            for(int i=0;i<u[0].g_cnt();i++)
            {
                if(s1-'0'==u[i].g_id())
                {
                    if(s2==u[i].g_passwd())
                    {
                    Adm:
                        if(u[i].g_status()==0)
                        {
                            cout<<"This account was deleted..."<<endl;
                            goto A1;
                        }
                        if(u[i].g_type()==1)//Administrator
                        {
                            cout<<"Welcome "<<u[i].g_name()<<endl;
                            cout<<"1.View all accounts"<<endl;
                            cout<<"2.Add an administrator account"<<endl;
                            cout<<"3.Delete account"<<endl;
                            cout<<"4.Edit account's password"<<endl;
                            cout<<"Other:Back to the main menu"<<endl;
                            cout<<"Please input your choice:";
                            char t2;
                            cin>>t2;
                            fflush(stdin);
                            switch (t2)
                            {
                                case '1':
                                {
                                    cout<<"ID\tName\tType\n";
                                    for(int j=0;j<u[0].g_cnt();j++)
                                    {
                                        if(u[j].g_status()==1)
                                        {
                                            cout<<u[j].g_id()<<"\t"<<u[j].g_name()<<"\t";
                                            if(u[j].g_type()==1)
                                            {
                                                cout<<"Administrator"<<endl;
                                            }
                                            else
                                            {
                                                cout<<"Shopkeeper"<<endl;
                                            }
                                        }
                                    }
                                    sleep(3);
                                    goto Adm;
                                }
                                    break;
                                case '2':
                                {
                                        string s1,s2,s3;
                                        A3:
                                        cout<<"Please input your name and Password..."<<endl;
                                        cout<<"name:";
                                        cin>>s1;
                                        fflush(stdin);
                                        cout<<"Password:";
                                        cin>>s2;
                                        fflush(stdin);
                                        cout<<"Please input the password again..."<<endl;
                                        cout<<"Password:";
                                        cin>>s3;
                                        fflush(stdin);
                                        if(s2!=s3)
                                        {
                                            cout<<"Please input same passwords..."<<endl;
                                            sleep(1);
                                            goto A3;
                                        }
                                        u[u[0].g_cnt()].e_id(u[0].g_cnt());
                                        u[u[0].g_cnt()].e_name(s1);
                                        u[u[0].g_cnt()].e_passwd(s2);
                                        u[u[0].g_cnt()].e_type(1);
                                        u[u[0].g_cnt()].e_status(1);
                                        u[u[0].g_cnt()].pp_cnt();
                                        cout<<"Successfully add the account..."<<endl;
                                        cout<<"The new ID is "<<u[0].g_cnt()-1<<endl;
                                        fstream file("user.txt",ios::out);
                                        fstream out_usr;//save
                                        out_usr.open("user.txt");
                                        out_usr<<u[0].g_cnt()<<"\n";
                                        for(int j=0;j<u[0].g_cnt();j++)
                                        {
                                            if(u[j].g_status()==1)
                                            {
                                                out_usr<<u[j].g_id()<<" "<<u[j].g_type()<<" "<<u[j].g_status()<<" "<<u[j].g_name()<<"\n";
                                                out_usr<<u[j].g_passwd()<<"\n";
                                            }
                                        }
                                        out_usr.close();
                                        sleep(2);
                                        goto Adm;
                                }
                                    break;
                                case '3':
                                {
                                    cout<<"Please input the ID of account:";
                                    int temp4;
                                    cin>>temp4;
                                    fflush(stdin);
                                    for(int j=0;j<u[0].g_cnt();j++)
                                    {
                                        if(u[j].g_id()==temp4)
                                        {
                                            u[j].e_status(0);
                                            break;
                                        }
                                    }
                                    fstream file("user.txt",ios::out);
                                    fstream out_usr;//save
                                    out_usr.open("user.txt");
                                    out_usr<<u[0].g_cnt()-1<<"\n";
                                    for(int j=0;j<u[0].g_cnt();j++)
                                    {
                                        if(u[j].g_status()==1)
                                        {
                                            out_usr<<u[j].g_id()<<" "<<u[j].g_type()<<" "<<u[j].g_status()<<" "<<u[j].g_name()<<"\n";
                                            out_usr<<u[j].g_passwd()<<"\n";
                                        }
                                    }
                                    u[0].mm_cnt();
                                    out_usr.close();
                                    cout<<"Successfully deleted..."<<endl;
                                    sleep(2);
                                    goto Adm;
                                }
                                case '4':
                                {
                                    A4:
                                    cout<<"Please input the ID of account:";
                                    int temp2;
                                    cin>>temp2;
                                    fflush(stdin);
                                    for(int j=0;j<u[0].g_cnt();j++)
                                    {
                                        if(u[j].g_id()==temp2)
                                        {
                                            cout<<"Please input the new password:";
                                            string temp3;
                                            cin>>temp3;
                                            fflush(stdin);
                                            u[j].e_passwd(temp3);
                                            cout<<"Successfully edit..."<<endl;
                                            sleep(1);
                                            break;
                                        }
                                        else
                                        {
                                           if(j==u[0].g_cnt()-1)
                                           {
                                               cout<<"Please input a correct id..."<<endl;
                                               sleep(1);
                                               goto A4;
                                           }
                                        }
                                    }
                                    fstream file("user.txt",ios::out);
                                    fstream out_usr;//save
                                    out_usr.open("user.txt");
                                    out_usr<<u[0].g_cnt()<<"\n";
                                    for(int j=0;j<u[0].g_cnt();j++)
                                    {
                                        if(u[j].g_status()==1)
                                        {
                                            out_usr<<u[j].g_id()<<" "<<u[j].g_type()<<" "<<u[j].g_status()<<" "<<u[j].g_name()<<"\n";
                                            out_usr<<u[j].g_passwd()<<"\n";
                                        }
                                    }
                                    out_usr.close();
                                    sleep(2);
                                    goto Adm;
                                }
                                    break;
                                default:
                                    goto mai;
                            }
                        }
                        else//shopkeeper
                        {
                            
                        }
                    }
                    else
                    {
                        cout<<"You still have 2 chance..."<<endl;
                        cout<<"Please input your ID and Password..."<<endl;
                        cout<<"Password:";
                        cin>>s2;
                        fflush(stdin);
                        if(s2==u[i].g_passwd())
                        {
                            goto Adm;
                        }
                        else
                        {
                            cout<<"You still have 1 chance..."<<endl;
                            cout<<"Please input your ID and Password..."<<endl;
                            cout<<"Password:";
                            cin>>s2;
                            fflush(stdin);
                            if(s2==u[i].g_passwd())
                            {
                                goto Adm;
                            }
                            else
                            {
                                fstream file("user.txt",ios::out);
                                fstream out_usr;
                                out_usr.open("user.txt");
                                out_usr<<u[0].g_cnt()<<"\n";
                                for(int j=0;j<u[0].g_cnt();j++)
                                {
                                    if(u[j].g_status()==1)
                                    {
                                        out_usr<<u[j].g_id()<<" "<<u[j].g_type()<<" "<<u[j].g_status()<<" "<<u[j].g_name()<<"\n";
                                        out_usr<<u[j].g_passwd()<<"\n";
                                    }
                                }
                                out_usr.close();
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    if(i==u[0].g_cnt()-1)
                    {
                        cout<<"Please check your id..."<<endl;
                        sleep(1);
                        goto mai;
                    }
                }
            }
        }
            break;
        case '2':
        {
            string s1,s2,s3;
            A2:
            cout<<"Please input your name and Password..."<<endl;
            cout<<"name:";
            cin>>s1;
            fflush(stdin);
            cout<<"Password:";
            cin>>s2;
            fflush(stdin);
            cout<<"Please input the password again..."<<endl;
            cout<<"Password:";
            cin>>s3;
            fflush(stdin);
            if(s2!=s3)
            {
                cout<<"Please input same passwords..."<<endl;
                sleep(1);
                goto A2;
            }
            u[u[0].g_cnt()].e_id(u[0].g_cnt());
            u[u[0].g_cnt()].e_name(s1);
            u[u[0].g_cnt()].e_passwd(s2);
            u[u[0].g_cnt()].e_type(2);
            u[u[0].g_cnt()].e_status(1);
            u[u[0].g_cnt()].pp_cnt();
            cout<<"Successfully add the account..."<<endl;
            cout<<"Your ID is "<<u[0].g_cnt()-1<<endl;
            fstream file("user.txt",ios::out);
            fstream out_usr;//save
            out_usr.open("user.txt");
            out_usr<<u[0].g_cnt()<<"\n";
            for(int j=0;j<u[0].g_cnt();j++)
            {
                if(u[j].g_status()==1)
                {
                    out_usr<<u[j].g_id()<<" "<<u[j].g_type()<<" "<<u[j].g_status()<<" "<<u[j].g_name()<<"\n";
                    out_usr<<u[j].g_passwd()<<"\n";
                }
            }
            out_usr.close();
            sleep(2);
            goto A1;
            break;
        }
        default:
            return 0;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
