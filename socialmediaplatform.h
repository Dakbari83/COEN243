#ifndef SOCIALMEDIAPLATFORM_H
#define SOCIALMEDIAPLATFORM_H

#include "user.h"

class SocialMediaPlatform{
    private:
        vector<User> users;

    public:
        SocialMediaPlatform(); // Constructor
        void registerUser(string, string); // Register a new user
        void removeUser(int); // Remove a user
        User* findUserByUsername(string); // Find a user by username and return a pointer to the user
        void createPostForUser(string,string); // Create a new post for a user
        void likePost(int); // Like a post
        void commentOnPost(int,string); // Comment on a post
        void viewUserProfile(string); // View a user's profile
};
#endif