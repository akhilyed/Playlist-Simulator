/* 
* Names: Raymond Zhang & Akhil Yeduvaka
* Program Name: Playlist Project
* Date: 1/29/25
* Extra: We gave the user the option to move around songs in the playlist.
* https://www.vsixhub.com/vsix/1507/#google_vignette for liveshare
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <ctime>                                       
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib, "winmm.lib")

int getIDX(int min, int max);
void shufflePlaylist(vector<string>& playlist, vector<string>& artists); // Declaration of functions
void swapper(string& str1, string& str2);

int main() {
    bool end = false;
    int choice, choice2, choice3, choice4;
    int pos;
    string user_song, artist_name;
    vector<string> songs = {"Dry Hands", "Wet Hands", "Mice On Venus", "Pigstep", "Subwoofer Lullaby", "Haggstrom"};
    vector<string> artists = {"C418", "C418", "C418", "Lena Raine", "C418", "C418"};
    
    // Duplicate vectors to manipulate
    
    vector<string> songs2 = {"Dry Hands", "Wet Hands", "Mice On Venus", "Pigstep", "Subwoofer Lullaby", "Haggstrom"};
    vector<string> artists2 = {"C418", "C418", "C418", "Lena Raine", "C418", "C418"};
    
    cout << "Welcome to Raymond & Akhil's Playlist Maker! we have chosen several songs for you that we thought you might like." << endl;
    while (!end) {
        cout << "Choose one of the following options for your personalized playlist.\n1. Play a Song\n2. Add Your Own Song\n3. Play Songs in Order\n4. Play Shuffled Songs\n5. Change Song Order\n6. Exit Playlist" << endl;
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1:
                cout << "Here are the current songs in your playlist: " << endl;
                for (int i = 0; i < songs.size(); i++) {
                    cout << i + 1 << ". " << songs[i] << " by " << artists[i] << endl;
                }
                cout << "Which song would you like to play? Enter the number corresponding to the song's spot in the playlist: ";
                cin >> choice2;
                if (choice2 <= 0 || choice2 > songs.size()) {
                    cout << "You entered an invalid choice." << endl;
                }
                else {
                    cout << "Now playing " << songs[choice2 - 1] << " by " << artists[choice2 - 1] << "." << endl;
                    if (songs[choice2 - 1] == "Dry Hands") {
                        PlaySound(TEXT("dry_hands.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[choice2 - 1] == "Wet Hands") {
                        PlaySound(TEXT("wet_hands.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[choice2 - 1] == "Mice On Venus") {
                        PlaySound(TEXT("mice_on_venus.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[choice2 - 1] == "Pigstep") {
                        PlaySound(TEXT("pigstep.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[choice2 - 1] == "Subwoofer Lullaby") {
                        PlaySound(TEXT("subwoofer_lullaby.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[choice2 - 1] == "Haggstrom") {
                        PlaySound(TEXT("haggstrom.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else {
                        cout << "This song has not yet been downloaded. Instead, Life Could Be Dream by The Chords will now play." << endl;
                        PlaySound(TEXT("life_could_be_dream.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                }
                break;
            case 2:
                cout << "Okay, what song would you like to add? (Enter the name of the song here): " << endl;
                getline(cin, user_song); // Ensures user is able to enter something with spaces.
                cout << "Enter the artist name: ";
                getline(cin, artist_name);
                cout << "What spot should it be in? (it should be a number between 1 and " << songs.size() + 1 << ")" << endl;
                cin >> pos;
                if (pos <= 0 || pos > songs.size() + 1) {
                    cout << "You entered an invalid choice. Please try again." << endl;
                }
                else {
                    songs.insert(songs.begin() + pos - 1, user_song);
                    artists.insert(artists.begin() + pos - 1, artist_name);
                }
                break;
            case 3:
                for (int i = 0; i < songs.size(); i++) {
                    cout << "Now playing " << songs[i] << " by " << artists[i] << "." << endl;
                    if (songs[i] == "Dry Hands") {
                        PlaySound(TEXT("dry_hands.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[i] == "Wet Hands") {
                        PlaySound(TEXT("wet_hands.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[i] == "Mice On Venus") {
                        PlaySound(TEXT("mice_on_venus.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[i] == "Pigstep") {
                        PlaySound(TEXT("pigstep.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[i] == "Subwoofer Lullaby") {
                        PlaySound(TEXT("subwoofer_lullaby.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs[i] == "Haggstrom") {
                        PlaySound(TEXT("haggstrom.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else {
                        cout << "This song has not yet been downloaded. Instead, Life Could Be Dream by The Chords will now play." << endl;
                        PlaySound(TEXT("life_could_be_dream.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                } 
                break;
            case 4:
                shufflePlaylist(songs2, artists2);
                for (int i = 0; i < songs2.size(); i++) {
                    cout << "Now playing " << songs2[i] << " by " << artists2[i] << "." << endl;
                    if (songs2[i] == "Dry Hands") {
                        PlaySound(TEXT("dry_hands.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs2[i] == "Wet Hands") {
                        PlaySound(TEXT("wet_hands.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs2[i] == "Mice On Venus") {
                        PlaySound(TEXT("mice_on_venus.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs2[i] == "Pigstep") {
                        PlaySound(TEXT("pigstep.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs2[i] == "Subwoofer Lullaby") {
                        PlaySound(TEXT("subwoofer_lullaby.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else if (songs2[i] == "Haggstrom") {
                        PlaySound(TEXT("haggstrom.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                    else {
                        cout << "This song has not yet been downloaded. Instead, Life Could Be Dream by The Chords will now play." << endl;
                        PlaySound(TEXT("life_could_be_dream.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                }
                break;
            case 5:
                // Extra:
                cout << "Which song would you like to move? Enter the number corresponding to the song's spot in the playlist: " << endl;
                cin >> choice3;
                cout << "Which song would you like to swap it with? Enter the number corresponding to the song's spot in the playlist: " << endl;
                cin >> choice4;
                swapper(songs[choice3 - 1], songs[choice4 - 1]);
                swapper(artists[choice3 - 1], artists[choice4 - 1]);
                break;
            case 6:
                cout << "Thank you for using our playlist!" << endl;
                end = true;
                break;
            default:
                cout << "You entered an invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}

int getIDX(int min, int max) {
    return min + rand() % (max - min + 1);
}

void shufflePlaylist(vector<string>& playlist, vector<string>& artists) { // References arguments to alter them
    srand(time(0));
    for (int i = playlist.size() - 1; i > 0; i--) { // Fisher-Yates Shuffle
        int j = getIDX(0, i);
        swapper(playlist[i], playlist[j]);
        swapper(artists[i], artists[j]);
    }
}
void swapper(string& str1, string& str2) { // Swaps the two arguments
    string temp = str1;
    str1 = str2;
    str2 = temp;
}
