#include <iostream>
#include <string>
#include <list>

using namespace std;

class PostingInfo{
    private: 
    //작성자 아이디
    string UserID;
    int postingID;
    string title;
    string contents;

    public:
    //작성자 아이디를 가져오는 함수
    string GetUserID(){
        return UserID;
    }
     //작성자 아이디를 다른 값으로 설정하는 함수
    string SetUserID(string str){
        UserID = str;
        return UserID;
    }

    int GetpostingID(){
        return postingID;
    }

    int SetpostingID(int num){
        postingID = num;
        return postingID;
    }

    string Gettitle(){
        return title;
    }

    string Settitle(string str){
        title = str;
        return title;
    }

    string Getcontents(){
        return contents;
    }

    string Setcontents(string str){
        contents = str;
        return contents;
    }
};