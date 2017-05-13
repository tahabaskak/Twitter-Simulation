#include <iostream>
#include "post.cpp"
using namespace std;

class userInformation{
private:
    string userName;
    string profileComment;

public:
    void setUserName(string name){
        userName = name;
    }
    void setProfileComment(string comment){
        profileComment = comment;
    }
    string getUserName(){
        return userName;
    }
    string getProfileComment(){
        return profileComment;
    }

};
