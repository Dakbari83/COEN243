#include "socialmediaplatform.h"
#include <iostream>
using namespace std;

void displayMenu() { // Display the main menu of the platform
    cout << "\n=== Social Media Platform ==="<<endl;
    cout << "1. Register new user"<<endl;
    cout << "2. Create a Post for a User"<<endl;
    cout << "3. Like a Post"<<endl;
    cout << "4. Comment on a Post"<<endl;
    cout << "5. View User Profile"<<endl;
    cout << "6. Remove a User"<<endl;
    cout << "7. Exit"<<endl;
    cout << "\nEnter your choice: ";
}

int main(){
    SocialMediaPlatform platform;
    int choice;

    while (true){
        displayMenu();  // Display the main menu
        cin >> choice;  // Get user choice

        if (choice == 7) { // Exit the platform if user chooses option 6
            cout << "Exiting the platform.\n";
            break;
        }

        switch (choice) {

            case 1: {  // Register new user
                string username, bio;
                cout << "Enter username: ";
                cin>>username; // Get username from input
                cin.ignore(); // Ignore the leftover newline character from previous input

                cout << "Enter bio: ";
                getline(cin,bio);  // Get bio from input
                platform.registerUser(username, bio);  // Register the user
                break;
            }

            case 2: {  // Create a post for a user
                string user,con;
                cout<<"Enter username to create post for: ";
                cin>>user;
                cin.ignore(); // Ignore the leftover newline character from previous input

                cout<<"Enter post content: ";
                getline(cin,con); // Get post content from input
                platform.createPostForUser(user,con);  // Handle creating post for a user
                break;
            }

            case 3: {  // Like a post
                string us;
                int idd;
                cout<<"Enter username who likes the post: ";
                cin>>us; // Get username from input
                cout<<"Enter post ID to like: ";
                cin>>idd; // Get post ID from input
                platform.likePost(idd);  // Handle liking a post
                break;
            }

            case 4: {  // Comment on a post
                string u, c;
                int id;
                cout<<"Enter username who comments: ";
                cin>>u; // Get username from input
                cout<<"Enter post ID to comment on: ";
                cin>>id; // Get post ID from input
                cin.ignore(); // Ignore the leftover newline character from previous input

                cout<<"Enter comment: ";
                getline(cin,c); // Get comment from input
                platform.commentOnPost(id,c);  // Handle commenting on a post
                break;
            }

            case 5: {  // View user profile
                string usern;
                cout<<"Enter username to view profile: ";
                cin>>usern; // Get username from input
                platform.viewUserProfile(usern);  // View user profile
                break;
            }

            case 6: { // Remove a User
                int useri;
                cout<<"Enter user ID to remove: ";
                cin>>useri; // Get user ID from input
                platform.removeUser(useri); // Remove the user
                break;
            }

            default:
                cout << "\nInvalid choice. Please try again.\n";

        }
        
        
    }
    return 0;
}

