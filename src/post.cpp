#include <iostream>

using namespace std;

class post{
private:
    string userName;
    string id;
    string content;
    int likeCount=0;
    int repostCount;
    string height_width;

public:
    void setPostedUserName(string postedUserName){
        userName = postedUserName;
    }
    void setId(string newId){
        id = newId;
    }
    void setContent(string newContent){
        content = newContent;
    }
    void setLikeCount(){
        likeCount = likeCount + 1 ;
    }
    void setRepostCount(){
        repostCount++;
    }
    void setHeightWidth(string value){
        height_width = value;
    }
    string getHeightWidth(){
        return height_width;
    }
    string getPostedUserName(){
        return userName;
    }
    string getId(){
        return id;
    }
    string getContent(){
        return content;
    }
    int getLikeCount(){
        return likeCount;
    }
    int getRepostCount(){
        return repostCount;
    }
};
