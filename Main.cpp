#include "CommunityBoard.cpp"
#include "LoginFunction.cpp"

int main(){
    list<UserInfo> userlist;
    bool exitcheck = false, quitcmd=false;
    int logincommand;

    UserInfo tmpuser;
    list<PostingInfo> postingboard; 
    int boardsize = 0;

    //반복
    while (!exitcheck)
    {   
        //로그인 메인페이지 출력
        GuidePrint();

        quitcmd = false;
        //커맨드 입력
        cin >> logincommand;

        switch (logincommand)
        {
            //1 입력시 회원가입
            case 1:
                AddUser(userlist);
                break;
            //2 입력시 로그인 후 게시판 실행 
            case 2:
                tmpuser = Login(userlist, quitcmd);
                if(quitcmd == false)
                    startboard(tmpuser, postingboard, boardsize);
                break;
            //3 입력시 비밀번호 찾기
            case 3:
                SearchPassword(userlist);
                break;
            //4 입력시 비밀번호 변경
            case 4:
                ChangePassword(userlist);
                break;
            //0 입력시 프로그램 종료
            case 0:
                exitcheck = true;
                cout << endl << "프로그램을 종료합니다" << endl << endl;
                break;
            default:
                break;
        }
    }
}
