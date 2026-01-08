#ifndef USER_H
#define USER_H

#include "post.h"

class User{
    private:
        string username;
        vector<Post> posts;
        string bio;
        int userID;

        
    public:
        User(); // Constructor
        
        void setUsername(string); // Set the username
        string getUsername(); // Get the username
        void createPost(string); // Create a post
        void listPosts(); // List the posts
        vector<Post>& getPosts(); // Get the array of posts, call by reference
        string getBio(); // Get the bio
        int getID(); // Get the user ID
        void setBio(string); // Set the user bio
};

#endif