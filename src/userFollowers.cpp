#include <iostream>

using namespace std;

class userFollowers{
private:
    string following;
    string followed;
public:
    void setFollowing(string userFollowingName){
        following = userFollowingName;
    }
    void setFollowed(string userFollowedName){
        followed = userFollowedName;
    }
    string getFollowing(){
        return following;
    }
    string getFollowed(){
        return followed;
    }
};
