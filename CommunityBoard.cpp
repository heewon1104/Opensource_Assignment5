#include "UserInfo.h"
#include "PostingInfo.h"

//로그인 후 게시판 메인화면을 띄워주는 함수
void PrintBoard(){
    cout << endl << "*****************************" << endl << endl;

    cout << "게시판 메인화면" << endl << endl;

    cout << "1번 입력시 게시글들을 조회할 수 있습니다" << endl;
    cout << "2번 입력시 게시글을 작성할 수 있습니다" << endl;
    cout << "3번 입력시 회원 정보를 볼수 있습니다" << endl;
    cout << "0번 입력시 로그아웃합니다" << endl;

    cout << endl << "*****************************" << endl << endl;
}

//보드의 모든 게시글을 띄워주는 함수
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

//게시글 작성시에 주의사항을 띄워주는 함수
void NoticeAboutPosting(){
    cout << endl << "** 주의사항 **" << endl << endl;

    cout << "제목을 전부 쓰고나서 엔터를 입력하면 엔터전까지의 내용들이 입력됩니다" << endl;
    cout << "내용을 전부 쓰고나서 엔터를 입력하면 엔터전까지의 내용들이 입력됩니다" << endl << endl;
}

//게시글 작성하는 함수
void AddPostings(UserInfo& user, list<PostingInfo>& board, int size){
    PostingInfo tmp;

    string writetitle, writecontent;

    //시글 작성시에 주의사항을 띄움
    NoticeAboutPosting();

    //제목과 내용을 공백포함 입력하도록 함
    cout << "제목을 입력하세요" << endl << endl;
    getline(cin, writetitle);   

    cout << "내용을 입력하세요" << endl << endl;
    getline(cin, writecontent);   

    //제목, 내용, 작성자 아이디, 게시글 아이디 설정
    tmp.Settitle(writetitle);
    tmp.Setcontents(writecontent);
    tmp.SetUserID(user.GetUserID());
    tmp.SetpostingID(size + 1);

    //게시글 리스트에 해당 게시글 추가
    board.push_back(tmp);
}

void UserInfomationBoard(UserInfo& user){
    cout << endl << "*****************************" << endl << endl;

    cout << " "<< user.GetUserID() << "님의 개인정보 " << endl << endl;

    cout << "1번 입력시 아이디, 비밀번호를 확인할 수 있습니다" << endl;
    cout << "2번 입력시 내가 작성한 게시글들을 보여줍니다" << endl;
    cout << "0번 입력시 게시판 화면으로 돌아갑니다" << endl;

    cout << endl << "*****************************" << endl << endl;
}

void PrintUserInfomation(UserInfo& user){
    cout << endl << "*****************************" << endl << endl;

    cout << "아이디 : " << user.GetUserID() << endl;
    cout << "비밀번호 : " << user.GetPassword() << endl;

    cout << endl << "*****************************" << endl << endl;
}

void UserPostings(list<PostingInfo> board, UserInfo& user){
    int count = 0;
    for(auto itr : board){
        if(itr.GetUserID() == user.GetUserID()){
            count++;
            cout << endl << "*****************************************************" << endl << endl;
            cout << endl << itr.GetpostingID() << ". "<< "제목 : " << itr.Gettitle() << endl << endl;
            cout << endl << "내용 : " << endl << itr.Getcontents() << endl << endl;
            cout << endl << "*****************************************************" << endl << endl;
        }
    }

    if(count == 0){
        cout << endl << "작성한 게시글이 없습니다!" << endl << endl;
    }
}

void startboard(UserInfo& user, list<PostingInfo>& postingboard){
    bool exitcheck = false;
    int command;

     //반복
    while (!exitcheck)
    {  
        UserInfomationBoard(user);

        cin >> command;

        switch (command)
        {
            //1 입력시 회원가입
            case 1:
                PrintUserInfomation(user);
                break;
            //2 입력시 게시글 작성
            case 2:
                UserPostings(postingboard, user);
                break;

            //0 입력시 반복문 종료(로그아웃)
            case 0:
                exitcheck = true;
                cout << endl << "게시판 화면으로 돌아갑니다" << endl << endl;
                break;
            default:
                break;
        }
    }    
}

//게시판 실행 함수
void startboard(UserInfo& user, list<PostingInfo>& postingboard, int& boardsize){
    bool exitcheck = false;
    int command;

    //반복
    while (!exitcheck)
    {  
        //게시판 메인화면 출력
        PrintBoard();

        //커맨드 입력
        cin >> command;
        boardsize = postingboard.size();

        switch (command)
        {
            //1 입력시 회원가입
            case 1:
                CheckPostings(postingboard, boardsize);
                break;
            //2 입력시 게시글 작성
            case 2:
                getchar();
                AddPostings(user, postingboard, boardsize);
                break;

            case 3:
                startboard(user, postingboard);
                break;

            //0 입력시 반복문 종료(로그아웃)
            case 0:
                exitcheck = true;
                cout << endl << "로그아웃 했습니다" << endl << endl;
                break;
            default:
                break;
        }
    }
}