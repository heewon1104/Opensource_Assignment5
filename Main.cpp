#include <iostream>
#include "UserInfo.cpp"

using namespace std;

int main() {
    UserInfo User = UserInfo();

    User.SetUserID("julian3306");
    User.SetPassword("1234");


    cout << "ID : " << User.GetUserID() << endl;
    cout << "Password : " <<User.GetPassword() << endl;

    return 0;
}