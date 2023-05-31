#include "UserInfo.h"
#include "PostingInfo.h"

void PrintBoard(){
    cout << endl << "*****************************" << endl << endl;

    cout << "게시판 메인화면" << endl << endl;

    cout << "1번 입력시 게시글들을 조회할 수 있습니다" << endl;
    cout << "2번 입력시 게시글을 작성할 수 있습니다" << endl;
    cout << "0번 입력시 로그아웃합니다" << endl;

    cout << endl << "*****************************" << endl << endl;
}

void CheckPostings(list<PostingInfo> board){
    for(auto itr : board){
        cout << endl << "*****************************" << endl << endl;
        cout << endl << itr.GetpostingID() << ". "<< "제목 : " << itr.Gettitle() << endl << endl;
        cout << endl << "내용 : " << endl << itr.Getcontents() << endl << endl;
        cout << endl << "*****************************" << endl << endl;
    }
}

void board(){
    list<UserInfo> userlist;
    list<PostingInfo> board;

    bool exitcheck = false;
    int command;

    while (!exitcheck)
    {  
        PrintBoard();

            cin >> command;

        switch (command)
        {
            case 1:
                CheckPostings(board);
                break;
            case 2:

                break;

            case 0:
                exitcheck = true;
                cout << endl << "로그아웃 했습니다" << endl << endl;
                break;
            default:
                break;
        }
    }

}