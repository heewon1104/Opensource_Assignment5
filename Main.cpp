#include "CommunityBoard.cpp"
#include "LoginFunction.cpp"

int main(){
    list<UserInfo> userlist;
    bool exitcheck = false;
    int logincommand;

    UserInfo tmpuser;
    list<PostingInfo> postingboard; 
    int boardsize = 0;

    while (!exitcheck)
    {   
        GuidePrint();

        cin >> logincommand;

        switch (logincommand)
        {
            case 1:
                AddUser(userlist);
                break;
            case 2:
                tmpuser = Login(userlist);
                startboard(tmpuser, postingboard, boardsize);
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
