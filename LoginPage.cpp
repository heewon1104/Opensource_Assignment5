#include "UserInfo.cpp"

using namespace std;
void GuidePrint(){
    cout << endl << "*************************************************" << endl << endl;

    cout << "안녕하세요! 오픈소스 게시판입니다" << endl << endl;
    cout << "* 사용 방법 *" << endl;
    cout << "회원가입을 하려면 1을 입력해주세요" << endl;    
    cout << "로그인을 하려면 2를 입력해주세요" << endl;
    cout << "비밀번호를 찾으려면 하려면 3을 입력해주세요" << endl;
    cout << "종료하려면 0를 입력해주세요" << endl;

    cout << endl << "*************************************************" << endl << endl;
}
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

void AddUser(list<UserInfo>& list){
    UserInfo user;
    string id, password;
    bool inputcheck = false;
    bool duplicationcheck = true;
    bool lettercheck = true;

    while(!inputcheck){
        cout << endl << "사용할 아이디를 입력해주세요" << endl;
        cin >> id;

        cout << endl << "사용할 비밀번호를 입력해주세요" << endl;
        cin >> password;

        lettercheck = CheckLetter(id, password);

        if(lettercheck == false){
            cout << endl << "아이디나 비밀번호는 공백없이 숫자나 영어로만 입력되어야 합니다!" << endl;
            lettercheck = true;
            continue;
        }

        if(id.length() != 0 && password.length() != 0){

            for(auto itr : list){
                if(itr.GetUserID() == id)
                    duplicationcheck = false;
            }

            if(duplicationcheck == false){
                duplicationcheck = true;

                 cout << endl << "중복되는 아이디입니다! 아이디와 비밀번호를 다시 입력해주세요" << endl;
            }

            else
                inputcheck = true;
        }
        else
        cout << endl << "아이디와 비밀번호가 제대로 입력되지 않았습니다! 다시 입력해주세요" << endl;
    }

    user.SetUserID(id);
    user.SetPassword(password);

    list.push_back(user);

    cout << endl << "회원가입 되었습니다!" << endl;
} 

void CheakCommand(list<UserInfo>& userlist){
    bool exitcheck = false;
    int command;

    while (!exitcheck)
    {   
        GuidePrint();

        cin >> command;

        switch (command)
        {
            case 1:
                AddUser(userlist);
                break;
            case 2:
                break;
            case 3:
                break;

            case 0:
                exitcheck = true;
                cout << endl << "프로그램을 종료합니다" << endl << endl;
                break;
            default:
                break;
        }
    }
}


void RunLogin(){
    list<UserInfo> userlist;

    CheakCommand(userlist);
}