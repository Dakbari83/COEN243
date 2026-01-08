#include "post.h"
#include <iostream>
using namespace std;

int counttt = 1; // A counter for the post ID, it starts with 1 and goes up by each new post created
 
Post::Post() : postID(counttt++), content(""), likes(0){} // Constructor, each time a Post object is created, it increments count

void Post::addLike(){ // Add a like, increase the like count by one
    likes++; 
}
void Post::addComment(string s){ // Add new comment to the end of the comments array
    comments.push_back(s);
}
void Post::viewPost(){
    cout<<"\n- Post ID: "<<postID<<endl;
    cout<<"  Content: "<<content<<endl;
    cout<<"  Likes: "<<likes<<endl;
    if(comments.empty()) // If there are no comments, tell the user
        cout << "  No comments yet." << endl;
    else {
        cout << "  Comments: " << endl;
        for (string comment : comments) // Show all the comments in the comments array
            cout << "\t" << comment << endl;
        
    }
}

int Post::getLikes(){
    return likes;
}

int Post::getPostID(){
    return postID;
}

string Post::getContent(){
    return content;
}

vector<string>& Post::getComments(){ // Call by reference
    return comments;
}

void Post::setContent(string c){
    content = c;
}
