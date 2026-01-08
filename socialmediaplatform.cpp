#include "socialmediaplatform.h"
#include <iostream>
#include <vector>
using namespace std;

SocialMediaPlatform::SocialMediaPlatform() {} // Constructor

void SocialMediaPlatform::registerUser(string user, string bioo){
    User a;
    a.setUsername(user); // Set the username
    a.setBio(bioo); // Set the user bio
    users.push_back(a); // Add the User object to the users vector
    cout<<"\nUser "<<user<<" was successfully created."<<endl; // Success message
}

void SocialMediaPlatform::removeUser(int ID) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getID() == ID) { // Find the user with the matching ID
            users.erase(it); // Erase the user with the matching ID
            cout << "\nUser with userID " << ID << " has been removed."<<endl;
            return;
        }
    }
    cout << "\nInvalid userID."<<endl; // If userID is not found, tell the user
}


User* SocialMediaPlatform::findUserByUsername(string u){
    for(User &a : users) { // Pass by reference
        if(a.getUsername() == u)
            return &a;
    }
    return nullptr; // Return nullptr if user not found
}


void SocialMediaPlatform::createPostForUser(string u, string con){
    User* user = findUserByUsername(u); // Find the user
    if (user != nullptr) {
        user->createPost(con); // Create post for the user
        cout<<"\nPost created successfully for user "<<u<<"."<<endl; // Success message
    } else 
        cout << "\nUser not found."<<endl; // If user not found
    
        
}

void SocialMediaPlatform::likePost(int i){
    for(User &u : users){ // Search all the users to find the post
        for (Post &p : u.getPosts()) { // Pass by reference
            if (p.getPostID() == i) { // Find the post by postID
                p.addLike(); // Add a like
                cout<<"\nA like has been successfully added to post with ID "<<i<<"."<<endl; // Success message
                return;
            }
        }
    }
    cout << "\nPost not found."<<endl; // If no matching postID, tell the user
    
}

void SocialMediaPlatform::commentOnPost(int i, string c){
    for(User &u: users){ // Search all the users for the post
        for (Post &p : u.getPosts()) { // Pass by reference
            if (p.getPostID() == i) { // Find the post by postID
                p.addComment(c); // Add the comment
                cout<<"\nComment was successfully added to post with ID "<<i<<"."<<endl; // Success message
                return;
            }

        }
    } 
    cout << "\nPost not found."<<endl; // If no matching postID, tell the user

}


void SocialMediaPlatform::viewUserProfile(string u){
    User* user = findUserByUsername(u); // Find the user
    if (user != nullptr) {
        cout << "\nProfile of " << u << ":" << endl;
        cout << "Bio: " << user->getBio() << endl;
        cout<< "Posts:"<<endl;
        user->listPosts(); // Show the user's posts
    } else {
        cout << "\nUser not found."<<endl;
    }
}
    

