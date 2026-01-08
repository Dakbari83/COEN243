#include "user.h"

int countt = 1; // A counter for the user ID, user ID starts from 1 and goes up with each new user created
User::User() { // Constructor, each time a User object is created, it increments count
    userID = countt;
    username = "";
    countt++;
    
} 


string User::getUsername(){
    return username;
}

void User::setUsername(string s){
    username = s;
}

void User::createPost(string c){ 
    Post p; // Create a new Post object
    p.setContent(c); // Set the content
    posts.push_back(p); // Add the Post object to the posts list

    
}

void User::listPosts(){
    for(Post i : posts) // View all posts in the posts list
        i.viewPost();
}

vector<Post>& User::getPosts(){ // Call by reference
    return posts;
}
string User::getBio(){
    return bio;
}

int User::getID(){
    return userID;
}

void User::setBio(string b){
    bio = b;
}