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
    //유저가 작성한 게시글 목록
    list<int> PostInfo;

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

    //유저가 글을 작성할 때 유저의 PostInfo 리스트에 작성한 게시글의 id를 추가하는 함수 
    void AddPostInfo(int postid){
        PostInfo.push_back(postid);
    }
    
    //유저가 글을 지울 때 유저의 PostInfo 리스트에서 지울 게시글의 id를 제거하는 함수 
    void DeletePostInfo(int postid){
        PostInfo.remove(postid);
    }
};