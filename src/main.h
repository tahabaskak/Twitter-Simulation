#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "users.cpp"
#include "userFollowers.cpp"
//#include "blockUser.cpp"

using namespace std;

struct userList{
    userInformation userModel;
    struct userList *next;
}*first=NULL;

struct postList{
    post postModel;
    struct postList *next;
}*startPost=NULL;

struct followerList{
    userFollowers followModel;
    struct followerList *next;
}*startFollowList=NULL;

void addPost(string userName,string postId,string postComment,string postImage,ofstream &outFile);
void addUser(string userName,string userComment,ofstream &outFile);
void followUser(string followingName,string followedName,ofstream &outFile);
void likePost(string likingName,string likedName,string postId,ofstream &outFile);
void viewUser(string userName,ofstream &outFile);
