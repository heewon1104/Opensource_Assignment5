#include <iostream>
#include <string>
#include <list>


using namespace std;


//���� ������ ���� Ŭ����
class UserInfo{
    private: 
    //���� ���̵�
    string UserID;
    //���� ��й�ȣ
    string Password;
    //������ �ۼ��� �Խñ� ���
    list<string> PostInfo;

    public:
    //���� ���̵� �������� �Լ�
    string GetUserID(){
        return UserID;
    }
     //���� ���̵� �ٸ� ������ �����ϴ� �Լ�
    string SetUserID(string str){
        UserID = str;
        return UserID;
    }

    //���� ��й�ȣ�� �������� �Լ�
     string GetPassword(){
        return Password;
    }

     //���� ��й�ȣ�� �ٸ� ������ �����ϴ� �Լ�
    string SetPassword(string str){
        Password = str;
        return Password;
    }
};