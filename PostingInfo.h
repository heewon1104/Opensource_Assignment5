#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class PostingInfo{
    private: 
    //작성자 아이디
    string UserID;
    //게시글 아이디(번호)
    int postingID;
    //제목
    string title;
    //내용
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
    //게시글 번호 가져오는 함수
    int GetpostingID(){
        return postingID;
    }
    //게시글 번호 설정하는 함수
    int SetpostingID(int num){
        postingID = num;
        return postingID;
    }
    //게시글 제목 가져오는 함수 
    string Gettitle(){
        return title;
    }
    //게시글 제목 설정하는 함수 
    string Settitle(string str){
        title = str;
        return title;
    }
    //게시글 내용 가져오는 함수 
    string Getcontents(){
        return contents;
    }
    //게시글 내용 설정하는 함수 
    string Setcontents(string str){
        contents = str;
        return contents;
    }
};