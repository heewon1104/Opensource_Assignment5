#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

//유저 정보에 관한 클래스
class UserInfo{
    private: 
    //유저 아이디
    string UserID;
    //유저 비밀번호
    string Password;

    public:
    //유저 아이디를 가져오는 함수
    string GetUserID(){
        return UserID;
    }
     //유저 아이디를 다른 값으로 설정하는 함수
    string SetUserID(string str){
        UserID = str;
        return UserID;
    }

    //유저 비밀번호를 가져오는 함수
     string GetPassword(){
        return Password;
    }

    //유저 비밀번호를 다른 값으로 설정하는 함수
    string SetPassword(string str){
        Password = str;
        return Password;
    }
};