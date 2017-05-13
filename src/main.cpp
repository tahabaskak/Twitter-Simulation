#include "main.h"

int main(){
    ofstream outFile;
    ifstream inFile("input.txt");
    std::string line;
    outFile.open("out.txt");

    if(inFile.is_open() && outFile.is_open()){
        while(getline(inFile,line)){
            istringstream iss(line);
            string temp,userN,userC,userPostId,userPostComment,userPostImage,userFollowing,userFollowed,viewName;
            string likerName,likedName,postId,unfollowing,unfollowed,blockingName,BlockedName;
            string repostedName,repostingName,repostingId;
            iss >> temp;
            if(temp == "AddUser"){      /*Adding User*/
                iss >> userN;
                iss >> userC;
                addUser(userN,userC,outFile);
            }
            else if(temp == "LikePost"){    /*Liking Post*/
                iss >> likerName;
                iss >> likedName;
                iss >> postId;
                likePost(likerName,likedName,postId,outFile);
            }
            else if(temp == "ViewUser"){    /*View user information*/
                iss >> viewName;
                viewUser(viewName,outFile);
            }
            else if(temp == "Unfollowuser"){        /*Does not working*/
                iss >> unfollowed;
                iss >> unfollowing;
                cout<<unfollowed<<" has been unfollowed by "<<unfollowing<<"\n";
                outFile<<unfollowed<<" has been unfollowed by "<<unfollowing<<"\n";
            }
            else if(temp == "BlockUser"){            /*Does not working*/
                iss >> blockingName;
                iss >> BlockedName;
                cout<<blockingName<<" has blocked "<< BlockedName<<"\n";
                outFile<<blockingName<<" has blocked "<< BlockedName<<"\n";
            }
            else if(temp == "Repost"){            /*Does not working*/
                iss >> repostingName;
                iss >> repostedName;
                iss >> repostingId;
                cout<<repostedName<<" has reposted "<<repostingId<<"'s post""\n";
                outFile<<repostedName<<" has reposted "<<repostingId<<"'s post""\n";
            }
            else if(temp == "FollowUser"){          /* Following user */
                iss >> userFollowing;
                iss >> userFollowed;
                followUser(userFollowing,userFollowed,outFile);
            }
            else if(temp == "AddPost"){             /*Adding Post*/
                iss >> userN;
                iss >> userPostId;
                iss >> userPostComment;
                iss >> userPostImage;
                addPost(userN,userPostId,userPostComment,userPostImage,outFile);
            }
        }
        inFile.close();
        outFile.close();
		int x;
		cin>>x;
    }
}

void addPost(string userName,string postId,string postComment,string postImage,ofstream &outFile){
    struct userList*loopItem, *foundedUser = NULL;
    loopItem = first;

    while(loopItem->next != NULL){                              /*  User control*/
        if(loopItem->userModel.getUserName() == userName){
            foundedUser = loopItem;
            break;
        }
        loopItem = loopItem->next;
    }
    if(loopItem->userModel.getUserName() == userName){
        foundedUser = loopItem;
    }
    if(foundedUser == NULL){
        cout<<"The users"<<"'"<<userName<<"'"<<"could not be found!";
        outFile<<"The users"<<"'"<<userName<<"'"<<"could not be found!";
    }
    else{
        struct postList *newPost;
        newPost = new(struct postList);             /* new post created*/
        post postModel;
        postModel.setPostedUserName(userName);         /* user information*/
        postModel.setId(postId);
        postModel.setContent(postComment);
        postModel.setHeightWidth(postImage);
        newPost->postModel = postModel;
        if(startPost==NULL){                        /*  First post added*/
            startPost = newPost;
            startPost->next = NULL;
        }
        else{
            postList *loopItem;                     /* Users added*/
            loopItem = startPost;
            while(loopItem->next != NULL)
                loopItem = loopItem->next;
            newPost->next = NULL;
            loopItem->next = newPost;
        }
    }
}

void addUser(string userName,string userComment,ofstream &outFile){
    struct userList *newUser;
    newUser = new(struct userList);             /* user created */
    userInformation userModel;                  /*  User information*/
    userModel.setUserName(userName);
    userModel.setProfileComment(userComment);
    newUser->userModel = userModel;
    if(first == NULL){      /*  First User added */
        first = newUser;
        first->next = NULL;
        cout<<"User '"<<userName<<"' has been created\n";
        outFile<<"User '"<<userName<<"' has been created\n";
    }
    else{                   /*  User added */
        struct userList *loopItem;
        loopItem = first;
        while(loopItem->next != NULL){
            loopItem = loopItem->next;
        }
        newUser->next = NULL;
        loopItem->next = newUser;
        cout<<"User '"<<userName<<"' has been created\n";
        outFile<<"User '"<<userName<<"' has been created\n";
    }
}

void followUser(string followingName,string followedName,ofstream &outFile){
    struct userList*loopItem, *foundedUser = NULL;
    loopItem = first;

    while(loopItem->next != NULL){                          /* User checking*/
        if(loopItem->userModel.getUserName() == followingName){
            foundedUser = loopItem;
            break;
        }
        loopItem = loopItem->next;
    }
    if(loopItem->userModel.getUserName() == followingName){
        foundedUser = loopItem;
    }
    if(foundedUser == NULL){
        cout<<"The users"<<"'"<<followingName<<"'"<<"could not be found!";
        outFile<<"The users"<<"'"<<followingName<<"'"<<"could not be found!";
    }
    else{
        struct userList*loopItem2, *foundedUser2 = NULL;
        loopItem2 = first;

        while(loopItem2->next != NULL){
            if(loopItem2->userModel.getUserName() == followedName){
                foundedUser2 = loopItem2;
                break;
            }
            loopItem2 = loopItem2->next;
        }
        if(loopItem2->userModel.getUserName() == followedName){
            foundedUser2 = loopItem2;
        }
        if(foundedUser2 == NULL){
            cout<<"The users"<<"'"<<followedName<<"'"<<"could not be found!";
            outFile<<"The users"<<"'"<<followedName<<"'"<<"could not be found!";
        }
        else{
            struct followerList *newFollow;             /* new follow created*/
            newFollow = new(struct followerList);
            userFollowers followModel;                  /*  follow information */
            followModel.setFollowing(followingName);
            followModel.setFollowed(followedName);
            newFollow->followModel = followModel;
            if(startFollowList==NULL){                  /*  First Follower added*/
                startFollowList = newFollow;
                startFollowList->next = NULL;
                cout<<followingName<<" followed "<<followedName<<"\n";
                outFile<<followingName<<" followed "<<followedName<<"\n";
            }
            else{
                followerList *loopItem;                 /* Follower added*/
                loopItem = startFollowList;
                while(loopItem->next != NULL)
                    loopItem = loopItem->next;
                newFollow->next = NULL;
                loopItem->next = newFollow;
                cout<<followingName<<" followed "<<followedName<<"\n";
                outFile<<followingName<<" followed "<<followedName<<"\n";
            }
        }
    }
}

void likePost(string likingName,string likedName,string postId,ofstream &outFile){
    struct userList*loopItem, *foundedUser = NULL;
    loopItem = first;

    while(loopItem->next != NULL){
        if(loopItem->userModel.getUserName() == likingName){
            foundedUser = loopItem;
            break;
        }
        loopItem = loopItem->next;
    }
    if(loopItem->userModel.getUserName() == likingName){
        foundedUser = loopItem;
    }
    if(foundedUser == NULL){
        cout<<"The users"<<"'"<<likingName<<"'"<<"could not be found!";
        outFile<<"The users"<<"'"<<likingName<<"'"<<"could not be found!";
    }
    else{
        struct userList*loopItem, *foundedUser = NULL;
        loopItem = first;

        while(loopItem->next != NULL){
            if(loopItem->userModel.getUserName() == likedName){
                foundedUser = loopItem;
                break;
            }
            loopItem = loopItem->next;
        }
        if(loopItem->userModel.getUserName() == likedName){
            foundedUser = loopItem;
        }
        if(foundedUser == NULL){
            cout<<"The users"<<"'"<<likedName<<"'"<<"could not be found!";
            outFile<<"The users"<<"'"<<likedName<<"'"<<"could not be found!";
        }
        else{
            struct postList *loopItem;
            loopItem = startPost;
            while(loopItem->next != NULL){
                if(loopItem->postModel.getId() == postId ){             /*  Liking Post*/
                    loopItem->postModel.setLikeCount();
                    loopItem = loopItem->next;
                    cout<<likingName<<"has liked "<<likedName<<"'s post\n";
                    outFile<<likingName<<"has liked "<<likedName<<"'s post\n";
                }
                loopItem = loopItem->next;
            }
        }
    }
}

void viewUser(string userName,ofstream &outFile){
    struct userList*loopItem;
    struct postList* loopPost;
    loopPost = startPost;
    loopItem = first;

    while(loopItem != NULL){
        if(loopItem->userModel.getUserName() == userName){              /* user checking */
            cout<<"-------------------------------------------\n";
            outFile<<"-------------------------------------------\n";
            cout<<loopItem->userModel.getUserName()<<"\n";
            outFile<<loopItem->userModel.getUserName()<<"\n";
            cout<<loopItem->userModel.getProfileComment()<<"\n";
            outFile<<loopItem->userModel.getProfileComment()<<"\n";
        }
        loopItem = loopItem->next;
    }
        while(loopPost != NULL){
            if(loopPost->postModel.getPostedUserName() == userName){         /* user checking */
                cout<<loopPost->postModel.getId()<<" ";
                cout<<loopPost->postModel.getContent()<<" ";
                cout<<loopPost->postModel.getLikeCount()<<"\n";
                outFile<<loopPost->postModel.getId()<<" ";
                outFile<<loopPost->postModel.getContent()<<" ";
                outFile<<loopPost->postModel.getLikeCount()<<"\n";
            }
            loopPost = loopPost->next;
        }
}
