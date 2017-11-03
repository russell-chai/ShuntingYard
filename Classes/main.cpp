#include "Media.h"
#include "Game.h"
#include "Music.h"
#include "Movie.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::flush;

// start the program off with files already in the vector
void init(vector<Media*> &v);

// method to search by year, returns all indeces found in form of vector
vector<int> search(vector<Media*> &v, int key) {
    vector<int> indeces;
    for (int i = 0; i < v.size(); i++) if (v.at(i)->getYear() == key) indeces.push_back(i);
    return indeces;
}

// method to search by year, returns all indeces found in form of vector
vector<int> search(vector<Media*> &v, char key[]) {
    vector<int> indeces;
    for (int i = 0; i < v.size(); i++) if (strcmp(v.at(i)->getTitle(), key) == 0) indeces.push_back(i);
    return indeces;
}

int main() {

    vector<Media*> folder;
    init(folder); // add some computer generated files
    
    // must create outside of loop so
    // it is visible at condition check
    char command[SHRT_MAX];

    do { // run until quit command
        
        // get the command for action to complete
        cout << "Enter a command (ADD, DELETE, LIST, SEARCH, QUIT)> " << flush;
        cin.getline(command, sizeof(command) / sizeof(command[0]));
        // std::transform(command.begin(), command.end(), command.begin(), ::toupper);

        // check to see which action to perform
        if (strcmp(command, "ADD") == 0) {
            // title and year are shared, do it ouside of if statment
            char medium[SHRT_MAX], title[SHRT_MAX];
            int year;
            cout << "- Enter title> " << flush;
            cin.getline(title, sizeof(title) / sizeof(title[0]));
            cout << "- Enter year> " << flush;
            cin >> year;
            cin.ignore(SHRT_MAX, '\n');
            cout << "- Specify type of media (GAME, MUSIC, MOVIE)> " << flush;
            cin.getline(medium, sizeof(medium) / sizeof(medium[0]));
            // check media type for unique members
            if (strcmp(medium, "GAME") == 0) {
                char publisher[SHRT_MAX], ratingCStr[SHRT_MAX];
                char rating;
                cout << "- Enter publisher> " << flush;
                cin.getline(publisher, sizeof(publisher) / sizeof(publisher[0]));
                cout << "- Enter rating> " << flush;
                cin.getline(ratingCStr, sizeof(ratingCStr) / sizeof(ratingCStr[0]));
                if (std::strlen(ratingCStr) == 1) rating = ratingCStr[0];
                else rating = '\0';
                Media* newMedia = new Game(title, year, publisher, rating);
                folder.push_back(newMedia);
            } else if (strcmp(medium, "MUSIC") == 0) {
                char artist[SHRT_MAX], publisher[SHRT_MAX];
                int duration;
                cout << "- Enter artist> " << flush;
                cin.getline(artist, sizeof(artist) / sizeof(artist[0]));
                cout << "- Enter publisher> " << flush;
                cin.getline(publisher, sizeof(publisher) / sizeof(publisher[0]));
                cout << "- Enter duration in seconds> " << flush;
                cin >> duration;
                cin.ignore(SHRT_MAX, '\n');
                Media* newMedia = new Music(title, year, artist, publisher, duration);
                folder.push_back(newMedia);
            } else if (strcmp(medium, "MOVIE") == 0) {
                char director[SHRT_MAX], rating[SHRT_MAX];
                int duration;
                cout << "- Enter director> " << flush;
                cin.getline(director, sizeof(director) / sizeof(director[0]));
                cout << "- Enter duration in minutes> " << flush;
                cin >> duration;
                cin.ignore(SHRT_MAX, '\n');
                cout << "- Enter rating> " << flush;
                cin.getline(rating, sizeof(rating) / sizeof(rating[0]));
                Media* newMedia = new Movie(title, year, director, duration, rating);
                folder.push_back(newMedia);
            } else cout << "- Not a valid medium. Aborting add... " << endl;
        } 

        // almost same mechanism as search
        else if (strcmp(command, "DELETE") == 0) {
            char deleteType[SHRT_MAX];
            cout << "- Enter deletion type (TITLE, YEAR, ALL)> " << flush;
            cin.getline(deleteType, sizeof(deleteType) / sizeof(deleteType[0]));
            vector<int> indeces; // store indeces to delete in vector
            // check if deletion type is valid
            if (strcmp(deleteType, "TITLE") == 0) {
                char key[SHRT_MAX];
                cout << "- Enter title> " << flush;
                cin.getline(key, sizeof(key) / sizeof(key[0]));
                indeces = search(folder, key); 
            } else if (strcmp(deleteType, "YEAR") == 0) {
                int key;
                cout << "- Enter year> " << flush;
                cin >> key;
                cin.ignore(SHRT_MAX, '\n');
                indeces = search(folder, key);
            } else if (strcmp(deleteType, "ALL") == 0) for (int i = 0; i < folder.size(); i++) indeces.push_back(i);
            else {
                cout << "- Not a valid deletion type. Aborting deletion..." << endl;
                continue; // ignore "nothing to delete" print
            } // otherwise list files to delete and prompt the user for confirmation
            if (indeces.size() == 0) cout << "--- Found nothing to delete." << endl;
            else {
                int deletedCount = 0; // must subtract amount deleted when getting index, vector size decreases
                for (vector<int>::iterator i = indeces.begin(); i != indeces.end(); i++) {
                    printf("--- Delete %s (%d)? (y/n)> ", folder.at((*i) - deletedCount)->getTitle(), folder.at((*i) - deletedCount)->getYear());
                    char yn[SHRT_MAX];
                    cin.getline(yn, sizeof(yn) / sizeof(yn[0]));
                    if (strcmp(yn, "y") == 0) {
                        delete folder.at((*i) - deletedCount); // call object destructor
                        folder.erase(folder.begin() + (*i) - deletedCount++); // erase pointer
                    }
                }
            }
        }

        else if (strcmp(command, "LIST") == 0) {
            if (folder.size() > 0) { // print out all elements in vector if not empty
                for (vector<Media*>::iterator i = folder.begin(); i != folder.end(); i++) {
                    cout << "- " << flush;
                    (*i)->print(false);
                }
            } else cout << "- Nothing to print." << endl;
        }
        
        // since there may be multiple indeces, store search results in vector
        else if (strcmp(command, "SEARCH") == 0) {
            char searchType[SHRT_MAX];
            cout << "- Enter type of search (TITLE, YEAR)> " << flush;
            cin.getline(searchType, sizeof(searchType) / sizeof(searchType[0]));
            vector<int> indeces;
            // check if search type is valid
            if (strcmp(searchType, "TITLE") == 0) {
                char key[SHRT_MAX];
                cout << "- Enter title> " << flush;
                cin.getline(key, sizeof(key) / sizeof(key[0]));
                indeces = search(folder, key); 
            } else if (strcmp(searchType, "YEAR") == 0) {
                int key;
                cout << "- Enter year> " << flush;
                cin >> key;
                cin.ignore(SHRT_MAX, '\n');
                indeces = search(folder, key);
            } else { // exit if not valid
                cout << "- Not a valid search type. Aborting search... " << endl;
                continue; // ignore "no search results" print
            } // otherwise print search results
            if (indeces.size() == 0) cout << "--- Your search matched no results." << endl;
            else {
                for (vector<int>::iterator i = indeces.begin(); i != indeces.end(); i++) {
                    cout << "--- " << flush;
                    folder.at(*i)->print(false);
                }
            }
        }

    } while (strcmp(command, "QUIT") != 0);
    cout << "Program terminated" << endl;
}

void init(vector<Media*> &v) {
    char cstr[28], str[13];
    std::strcpy(cstr, "Low Life (feat. The Weeknd)");
    std::strcpy(str, "Metro Boomin");
    Media* media = new Music(cstr, 2016, new char[7]{'F','u','t','u','r','e','\0'}, str, 313);
    char cstr2[40], cstr3[38];
    std::strcpy(cstr2, "Gospel (feat. XXXTENTACION & Keith Ape)");
    std::strcpy(cstr3, "Rich Chigga, Keith Ape & XXXTENTACION");
    Media* media2 = new Music(cstr2, 2017, cstr3, new char[8]{'R','o','n','n','y',' ','J','\0'}, 179);
    char cstr4[20];
    std::strcpy(cstr4, "Andres Muschietti");
    Media* media3 = new Movie(new char[3]{'I','t','\0'}, 2017, cstr4, 135, new char[2]{'R','\0'});
    char cstr5[18];
    std::strcpy(cstr5, "League of Legends");
    Media* media4 = new Game(cstr5, 2009, new char[11]{'R','i','o','t',' ','G','a','m','e','s','\0'}, 'T');
    char cstr6[24], cstr7[25];
    std::strcpy(cstr6, "0 to 100 / The Catch Up");
    std::strcpy(cstr7, "Frank Dukes & Boi-1da");
    Media* media5 = new Music(cstr6, 2015, new char[6]{'D','r','a','k','e','\0'}, cstr7, 275);
    v.push_back(media);
    v.push_back(media2);
    v.push_back(media3);
    v.push_back(media4);
    v.push_back(media5);
}

