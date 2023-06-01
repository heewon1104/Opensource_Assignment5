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

void CheckPostings(list<PostingInfo> board, int size){
    if(size == 0){
        cout << endl << "게시글이 없습니다!" << endl << endl;
    }

    else{
        for(auto itr : board){
            cout << endl << "*****************************************************" << endl << endl;
            cout << endl << itr.GetpostingID() << ". "<< "제목 : " << itr.Gettitle() << endl << endl;
            cout << endl << "내용 : " << endl << itr.Getcontents() << endl << endl;
            cout << endl << "*****************************************************" << endl << endl;
        }
    }
}
void NoticeAboutPosting(){
    cout << endl << "** 주의사항 **" << endl << endl;

    cout << "제목을 전부 쓰고나서 엔터를 입력하면 엔터전까지의 내용들이 입력됩니다" << endl;
    cout << "내용을 전부 쓰고나서 엔터를 입력하면 엔터전까지의 내용들이 입력됩니다" << endl << endl;
}

void AddPostings(UserInfo& user, list<PostingInfo>& board, int size){
    PostingInfo tmp;

    string writetitle, writecontent;

    NoticeAboutPosting();

    cout << "제목을 입력하세요" << endl << endl;
    getline(cin, writetitle);   

    cout << "내용을 입력하세요" << endl << endl;
    getline(cin, writecontent);   

    tmp.Settitle(writetitle);
    tmp.Setcontents(writecontent);
    tmp.SetUserID(user.GetUserID());
    tmp.SetpostingID(size + 1);

    user.AddPostInfo(size + 1);

    board.push_back(tmp);
}

void board(){
    UserInfo user;
    list<PostingInfo> board;
    
    bool exitcheck = false;
    int command;
    int size;

    while (!exitcheck)
    {  
        PrintBoard();

        cin >> command;
        size = board.size();

        switch (command)
        {
            case 1:
                CheckPostings(board, size);
                break;
            case 2:
                getchar();
                AddPostings(user, board, size);
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