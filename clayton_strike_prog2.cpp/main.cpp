#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>


using namespace std;


// Our struct for song files.
struct Song
    {
        string title;
        string artist;
        float fileSize;
    };


void show_playlist(Song iPodSongs[], int SIZE)
{
    cout << "- - - - - - - - - - - - - - - - - -" << endl;

    if (SIZE > 0) // Check to ensure playlist is not empty from cleanup()
    {
        cout << "Here is your current playlist: " << endl;

        for (int i = 0; i < SIZE; i++)
        {
            // Prints position in playlist, song title, and song artist.
            cout << i + 1 << ". " << iPodSongs[i].title << " by " << iPodSongs[i].artist << endl;
        }
    }
    else // If playlist has already been emptied (iPodSongs[] SIZE !> 0), print alternative text.
    {
        cout << "There are no songs stored on this iPod." << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - -" << endl;

    return;
}

int remove_a_song(Song *&iPodSongs, int SIZE)
{
    cout << "- - - - - - - - - - - - - - - - - -" << endl;

    string songToDelete; // User-inputted string.
    int indexOfSongToDelete; // Index of matching song title.
    bool flag = 0; // flag for if user-inputted song title matches a song title in our array.

    if (SIZE > 0)
    {
        cout << "Please enter the title of the song you'd like to delete: " << endl;
        cin.ignore();
        getline(cin, songToDelete);

        // This for loop searches every index 0 thru SIZE and sees if songToDelete matches an element of our song array.
        for (int i = 0; i < SIZE; i++)
        {
            if (songToDelete == iPodSongs[i].title)
            {
                indexOfSongToDelete = i;
                flag = 1; // Flips our flag.

                // If songToDelete matches an element, we copy all future elements to its (index - 1).
                for (int j = 0; j < (SIZE - (indexOfSongToDelete + 1)); j++)
                {
                    iPodSongs[indexOfSongToDelete + j].title = iPodSongs[indexOfSongToDelete + j + 1].title;
                    iPodSongs[indexOfSongToDelete + j].artist = iPodSongs[indexOfSongToDelete + j + 1].artist;
                    iPodSongs[indexOfSongToDelete + j].fileSize = iPodSongs[indexOfSongToDelete + j + 1].fileSize;
                }
            }
        }
        if (flag == 0) // If flag was not flipped, i.e. songToDelete does not match an element.
        {
            cout << "Error. There exists no song named " << songToDelete << ". " << endl;
        }



        // We now copy songArray1[] to iPodSongs[] with one fewer element.
        Song *songArray1;
        SIZE = (SIZE - 1);
        songArray1 = new Song[SIZE];

        // We copy iPodSongs[] to temporary array songArray1[]
        for (int i = 0; i < SIZE; i++)
        {
            songArray1[i].title = iPodSongs[i].title;
            songArray1[i].artist = iPodSongs[i].artist;
            songArray1[i].fileSize = iPodSongs[i].fileSize;
        }

        // Since iPodSongs was passed by *&, we can delete it and recreate it with smaller SIZE.
        delete [] iPodSongs;

        iPodSongs = new Song[SIZE];

        // Copy values from the temporary array songArray1[] to new iPodSongs[].
        for (int i = 0; i < SIZE; i++)
        {
            iPodSongs[i].title = songArray1[i].title;
            iPodSongs[i].artist = songArray1[i].artist;
            iPodSongs[i].fileSize = songArray1[i].fileSize;
        }

        // Delete our temporary array songArray1[].
        delete [] songArray1;

    }
    else // If cleanup() has already been run, i.e. playlist is empty, print alternative text.
    {
        cout << "There are no songs remaining to remove." << endl;
    }


    cout << "- - - - - - - - - - - - - - - - - -" << endl;


    return SIZE;

}

int cleanup(Song *&iPodSongs, int SIZE)
{
    cout << "- - - - - - - - - - - - - - - - - -" << endl;

    // Delete iPodSongs[] and recreate it with 0 as the SIZE value.
    if(SIZE > 0)
    {
        delete [] iPodSongs;

        SIZE = 0;

        iPodSongs = new Song[SIZE];

        cout << "iPod has been cleared of all data." << endl;
    }
    else // If cleanup() has already been ran, i.e. playlist is empty, print alternative text.
    {
        cout << "This iPod is already empty of data." << endl;
    }


    cout << "- - - - - - - - - - - - - - - - - -" << endl;
}

void shuffle(Song iPodSongs[], int SIZE)
{

    if (SIZE > 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            int randElement = (rand() % SIZE); // Random number between 0 - (SIZE - 1).
            Song placeholder; // placeholder Song value for copying.

            // Uses placeholder to flip iPodSongs[i] with iPodSongs[randElement].
            placeholder.title = iPodSongs[i].title;
            placeholder.artist = iPodSongs[i].artist;
            placeholder.fileSize = iPodSongs[i].fileSize;
            iPodSongs[i].title = iPodSongs[randElement].title;
            iPodSongs[i].artist = iPodSongs[randElement].artist;
            iPodSongs[i].fileSize = iPodSongs[randElement].fileSize;
            iPodSongs[randElement].title = placeholder.title;
            iPodSongs[randElement].artist = placeholder.artist;
            iPodSongs[randElement].fileSize = placeholder.fileSize;
        }

        cout << "- - - - - - - - - - - - - - - - - -" << endl;
        cout << "Playlist has been shuffled." << endl;
        cout << "- - - - - - - - - - - - - - - - - -" << endl;
    }
    else // If cleanup() has already been run, i.e. playlist is empty, print alternative text.
    {
        cout << "- - - - - - - - - - - - - - - - - -" << endl;
        cout << "Cannot shuffle an empty playlist." << endl;
        cout << "- - - - - - - - - - - - - - - - - -" << endl;
    }

    return;
}



exit (Song iPodSongs[], int SIZE)
{
    if (SIZE > 0) // If playlist is not already empty, delete iPodSongs[] then exit.
    {
        delete [] iPodSongs;

        cout << "- - - - - - - - - - - - - - - - - -" << endl;
        cout << "Exiting program..." << endl;
        cout << "- - - - - - - - - - - - - - - - - -" << endl;
    }
    else // If playlist is already empty, just exit.
    {
        cout << "- - - - - - - - - - - - - - - - - -" << endl;
        cout << "Exiting program..." << endl;
        cout << "- - - - - - - - - - - - - - - - - -" << endl;
    }
}




int main()
{
    // Sets our random seed and initializes some variables.
    srand(time(NULL));
    ifstream songFile;
    int userInput = 0;



    // Opening up the input_song.txt file.
    songFile.open("input_song.txt");



    // Verification that the input_song.txt file opened correctly.
    if(songFile.fail())
    {
        cout << "File failed to load." << endl;
    }



    // Variables needed to initialize text file into an array.
    const int CAPACITY = 250; // Smallest file size is 0.1 MB, 25 MB / 0.1 = 250.
    Song songArray[CAPACITY];
    int COUNT = 0;
    int counter = 1;
    string placeholder;
    float totalData = 0;

    // Code to initialize text file into temporary array songArray[].
    while (!songFile.eof())
    {
        getline(songFile, placeholder, '\n');

        if(totalData > 25) // if data is over 25MB, don't add any more elements.
        {
            continue;
        }
        else if(placeholder.empty()) // If the line is empty skip it.
        {
            continue;
        }
        else
        {
            // This code initializes every three lines into one index (.title, .artist, .fileSize)
            if ((counter) % 3 == 1)
            {
                songArray[COUNT].title = placeholder;

                counter++;
                continue;
            }
            else if ((counter) % 3 == 2)
            {
                songArray[COUNT].artist = placeholder;

                counter++;
                continue;
            }
            else if ((counter) % 3 == 0)
            {
                float floatPlaceholder;

                floatPlaceholder = std::atof(placeholder.c_str()); // Converts string to float.

                songArray[COUNT].fileSize = floatPlaceholder;

                totalData += floatPlaceholder;

                counter++;
                COUNT++; // Actual index value of array.
                continue;
            }
        }
    }

    // Create a new array iPodSongs[] that is only as large as necessary.
    Song *iPodSongs;
    iPodSongs = new Song[COUNT];

    if (totalData > 25) // If statement for if totalData went over the max 25MB.
    {

        COUNT = COUNT - 1; // Essentially removes the last element of array that went over data restriction.

        for (int i = 0; i < COUNT; i++) // Copies array over.
        {
            iPodSongs[i].title = songArray[i].title;
            iPodSongs[i].artist = songArray[i].artist;
            iPodSongs[i].fileSize = songArray[i].fileSize;
        }
    }
    else // Copies over arrays normally if totalData remained under 25MB.
    {
        for (int i = 0; i < COUNT; i++)
        {
            iPodSongs[i].title = songArray[i].title;
            iPodSongs[i].artist = songArray[i].artist;
            iPodSongs[i].fileSize = songArray[i].fileSize;
        }
    }

    // Remove temporary array songArray[].
    delete [] songArray;




    // Do-while loop for menu. If the user input is less than 1 or greater than 5 an error occurs.
    do
    {
        cout << "Welcome to my IPod!" << endl;
        cout << "Please make a selection: " << endl;
        cout << "1. Show the playlist." << endl;
        cout << "2. Remove a song." << endl;
        cout << "3. Clean-up my iPod." << endl;
        cout << "4. Shuffle the playlist." << endl;
        cout << "5. Exit." << endl;

        cout << "- - - - - - - - - - - - - - - - - -" << endl;

        cin >> userInput;

        while (userInput < 1 || userInput > 5)
        {
            cout << "Error. Please enter a choice between 1 and 5." << endl;
            cin >> userInput;
        }



        // User input = 1 starts show_playlist function.
        if (userInput == 1)
        {
            show_playlist(iPodSongs, COUNT);
        }

        // User input = 2 starts remove_a_song function. remove_a_song() updates COUNT.
        if (userInput == 2)
        {
            COUNT = remove_a_song(iPodSongs, COUNT);
        }

        // User input = 3 starts cleanup function. cleanup() updates COUNT.
        if (userInput == 3)
        {
            COUNT = cleanup(iPodSongs, COUNT);
        }

        // User input = 4 starts shuffle function.
        if (userInput == 4)
        {
            shuffle(iPodSongs, COUNT);
        }

        // User input = 5 starts exit function.
        if (userInput == 5)
        {
            exit(iPodSongs, COUNT);
        }
    }
    while (userInput != 5); // Once userInput = 5, program continues and ends.

    return 0;
}
