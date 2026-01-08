#ifndef POST_H
#define POST_H

#include <string>
#include <vector>
using namespace std;

class Post{
    private:
        int likes;
        int postID;
        string content;
        vector<string> comments;

    public:
        Post(); // Constructor
        void addLike(); // Add a like to a post
        void addComment(string); // Add a comment to a post
        void viewPost(); // View a post
        int getLikes(); // Get a post's likes
        int getPostID(); // Get a post's post ID
        string getContent(); // Get the content of a post
        void setContent(string); // Set the content of a post
        vector<string>& getComments(); // Get the comments of a post, call by reference


};
#endif