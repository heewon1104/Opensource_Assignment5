#pragma once
#include "UserInfo.h"

//처음 로그인 했을때 메인회면을 띄워주는 함수
void GuidePrint(){
    cout << endl << "*************************************************" << endl << endl;

    cout << "안녕하세요! 오픈소스 게시판입니다" << endl << endl;
    cout << "* 사용 방법 *" << endl;
    cout << "회원가입을 하려면 1을 입력해주세요" << endl;    
    cout << "로그인을 하려면 2를 입력해주세요" << endl;
    cout << "비밀번호를 찾으려면 하려면 3을 입력해주세요" << endl;
    cout << "비밀번호를 변경하려면 하려면 4를 입력해주세요" << endl;
    cout << "종료하려면 0를 입력해주세요" << endl;

    cout << endl << "*************************************************" << endl << endl;
}

//입력된 아이디와 비밀번호가 영어 혹은 숫자인지 확인하는 함수
//만약 아이디나 비밀번호 중 영어나 숫자가 아닌 문자가 섞여있다면 false 반환
//아이디와 비밀번호 모두 영어와 숫자로 이루어져 있으면 true 반환
bool CheckLetter(string id, string password){
    bool lettercheck = true;
     
    for (int i = 0; i < id.length(); i++){
        if(isalpha(id[i]) == 0 && isdigit(id[i]) == false)
            lettercheck = false;
    }

    for (int i = 0; i < password.length(); i++){
        if(isalpha(password[i]) == 0 && isdigit(password[i]) == false)
            lettercheck = false;
    }

    return lettercheck;
}

//회원가입을 도와주는 함수
//아이디와 비밀번호를 입력받고 리스트에 회원가입한 유저 추가
void AddUser(list<UserInfo>& list){
    UserInfo user;
    string id, password;
    bool inputcheck = false;
    bool duplicationcheck = true;
    bool lettercheck = true;
    
    //회원가입이 완료될때까지 반복
    while(!inputcheck){

        //아이디와 비밀번호 입력
        cout << endl << "사용할 아이디를 입력해주세요" << endl;
        cout << "처음 화면으로 나가려면 ~ 을 입력해주세요" << endl << endl;
        cin >> id;

        //처음 화면으로 되돌아가려면 ~ 입력
        if(id == "~")
            return;
        
        cout << endl << "사용할 비밀번호를 입력해주세요" << endl;
        cin >> password;

        //아이디와 비밀번호가 모두 숫자 혹은 영어로 이루어져ㅍ있는지 확인
        lettercheck = CheckLetter(id, password);

        //만약 영어나 숫자가 아닌 이상한 문자가 섞여있으면
        if(lettercheck == false){
            //경고문 띄우고 아이디와 비밀번호 다시 입력하도록 반복
            cout << endl << "아이디나 비밀번호는 공백없이 숫자나 영어로만 입력되어야 합니다!" << endl;
            lettercheck = true;
            continue;
        }
        //만약 아이디와 비밀번호 모두 제대로 입력 되었을때 
        if(id.length() != 0 && password.length() != 0){
            //중복되는 아이디가 존재하는지 확인
            for(auto itr : list){
                if(itr.GetUserID() == id)
                    duplicationcheck = false;
            }

            //중복되는 아이디가 있으면
            if(duplicationcheck == false){
                duplicationcheck = true;
                //경고문 띄우고 아이디와 비밀번호 다시 입력하도록 반복
                cout << endl << "중복되는 아이디입니다! 아이디와 비밀번호를 다시 입력해주세요" << endl;
            }

            //위의 조건들 만족하면 회원가입 완료후 반복문 탈출
            else
                inputcheck = true;
        }
        else
        cout << endl << "아이디와 비밀번호가 제대로 입력되지 않았습니다! 다시 입력해주세요" << endl;
    }

    //유저 정보의 아이디와 비밀번호를 위의 값으로 설정 
    user.SetUserID(id);
    user.SetPassword(password);

    //유저 리스트에 회원가입한 유저 추가
    list.push_back(user);

    cout << endl << "회원가입 되었습니다!" << endl;
} 

//로그인을 도와주는 함수
UserInfo Login(list<UserInfo>& list, bool& quitcmd){
    UserInfo searchuser;
    string id, password;
    bool logincheck = false;
    
    //로그인이 될때까지 반복
    while(!logincheck){
        //아이디와 비밀번호 입력
        cout << endl << "아이디를 입력해주세요" << endl;

        //처음 화면으로 되돌아가려면 ~ 입력
        cout << "처음 화면으로 나가려면 ~ 을 입력해주세요" << endl << endl;
        cin >> id;

        if(id == "~"){
            quitcmd = true;
            return searchuser;
        }
        cout << endl << "비밀번호를 입력해주세요" << endl;
        cin >> password;

        //유저 리스트 돌면서 해당 아이디와 비밀번호를 인자로 가지는 유저가 있는지 확인
        for(auto itr : list){
            if(itr.GetUserID() == id && itr.GetPassword() == password){
                logincheck = true;
                searchuser = itr;
            }
        }
        //로그인 되면 해당 안내문 띄우고 반복문 탈출
        if(logincheck == true)
            cout << endl << "로그인 되었습니다!" << endl;
        //아니면 안내문 띄우고 로그인 반복
        else
            cout << endl << "아이디나 비밀번호를 잘못 입력하였습니다 다시 입력 해주세요" << endl;
    }

    //로그인 한 유저 정보 반환
    return searchuser;
}

//비밀번호를 찾는 함수
void SearchPassword(list<UserInfo>& list){
    string id, password = "";
    bool searchcheck = false;
    
    //찾을 계정 아이디 입력
    cout << endl << "찾으려는 계정의 아이디를 입력해주세요" << endl;
    cin >> id;

    //반복문 돌며 해당 아이디를 가진 유저가 있는지 확인
    for(auto itr : list){
        if(itr.GetUserID() == id)
            password = itr.GetPassword();
    }

    //해당 아이디가 없으면 
    if(password.length() == 0)
        cout << endl << "존재하지 않는 계정입니다" << endl;
    //해당 아이디가 있으면 아래 안내문 띄우고 비밀번호 반환
    else
        cout << endl << "해당 계정의 비밀번호는 "  << password << " 입니다 "<< endl;
    
}

//비밀번호 바꿔주는 함수
void ChangePassword(list<UserInfo>& userlist){
    string id, password;
    bool lettercheck = true;

    UserInfo* user = nullptr;
    bool usercheck = false;

    //아이디 입력
    cout << endl << "아이디를 입력해주세요" << endl;
    cin >> id;

    // 해당 아이디가 존재하는지 확인
    for (auto& itr : userlist) {
        if (itr.GetUserID() == id) {
            user = &itr;
            usercheck = true;
            break; 
        }
    }

    //아이디가 없으면 종료
    if (usercheck == false) {
        cout << endl << "존재하지 않는 아이디입니다" << endl;
        return;
    }

    //아이디가 존재하면 비밀번호 입력
    cout << endl << "변경할 비밀번호를 입력해주세요" << endl;
    cin >> password;

    //아이디가 영어, 숫자로만 이루어져 있는지 확인
    for (int i = 0; i < password.length(); i++) {
        if (isalpha(password[i]) == 0 && isdigit(password[i]) == false)
            lettercheck = false;
    }

    //영어 숫자가 아닌 문자가 있으면 변경하지 않고 종료
    if (lettercheck == false) {
        cout << endl << "비밀번호는 공백없이 숫자나 영어로만 입력되어야 합니다!" << endl;
        cout << endl << "비밀번호가 변경되지 않았습니다" << endl;
    }

    //영어 숫자로만 이루어져 있으면 비밀번호 변경
    else {
        user->SetPassword(password);
        cout << endl << "비밀번호가 변경되었습니다" << endl;
    }
}
