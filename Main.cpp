#include "LoginFunction.cpp"

int main(){
    list<UserInfo> userlist;
    bool exitcheck = false;
    int command;

    while (!exitcheck)
    {   
        GuidePrint();

        cin >> command;

        switch (command)
        {
            case 1:
                AddUser(userlist);
                break;
            case 2:
                Login(userlist);
                break;
            case 3:
                SearchPassword(userlist);
                break;

            case 0:
                exitcheck = true;
                cout << endl << "프로그램을 종료합니다" << endl << endl;
                break;
            default:
                break;
        }
    }
}
