#include<bits/stdc++.h>
using namespace std;

int wrong, hint = 1;
string the_word, guessed;

/*
the_word: The word to be guessed (will be chosen randomly from the list of words available)
guessed: Status of your correct guesses after each new guess
av: The list of available characters
*/

string av = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const int max_lives = 8;   // Max chances available to the player

void guess(string word, int n, string &guessed);
void hangman(int w);

// Asks if the player wants to play again.
bool playAgain(){

    char again;
    cout<<"Do you wish to play again?";
    cin>>again;

    cin.clear();
    cin.ignore();

    return (again == 'y' || again == 'Y');
}


int main(){

    srand(time(0));    // to get random word every time program runs
    int n; // size of word to be guessed

    // words list
    vector<string> words = {"guess", "hangman", "difficult", "book", "digital", "program", "extremist", "flag", "pork", "panoramic", "rain", "beginner", "percussive", "own", "barnburner", "kiss", "strategy", "childish", "like", "herb", "gutsy", "logical", "cosmic", "dimensional", "fornicator", "rastling", "imported", "huge", "level", "succinct", "different", "equation", "boundless", "wound", "ink", "clothe", "limping", "presumed", "serenity", "amateur", "gladness", "afterlife", "cleanup", "honest", "republic", "pan"};  // collection of possible words to guess

    // Asking the player his name and welcoming him
    string name;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<endl<<"Welcome to Hangman "<<name<<". Let's start."<<endl;


    do{
        wrong = 0;

        random_shuffle(words.begin(), words.end());
        the_word = words[0];
        transform(the_word.begin(), the_word.end(), the_word.begin(), ::toupper);
        n = the_word.size();

        guessed = string(n, '-');

    while((wrong < max_lives) && (guessed != the_word)){

        cout<<endl;
        cout<<"----------------------------------------------------------------------------"<<endl<<endl;
        cout<<"Word: "<<guessed<<endl<<endl;
        cout<<"Available Letters: "<<av<<endl<<endl;
        cout<<"Lives Remaining: "<<max_lives-wrong<<endl<<endl;
        guess(the_word, n, guessed);
    }

    if(guessed == the_word){

        cout<<"Word: "<<guessed<<endl<<endl;
        cout<<"-----------------Heyyyyyyyyyy, YOU WON!!!!-----------------"<<endl<<endl;
    }
    if(wrong == max_lives){

        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"  0   |"<<endl;
        cout<<" /|\\  |"<<endl;
        cout<<"  |   |"<<endl;
        cout<<" / \\  |"<<endl;
        cout<<"      ========="<<endl;
        cout<<endl<<endl<<"--------------Uh Ohhh!     GAME OVER---------------"<<endl<<endl;
        // transform(the_word.begin(), the_word.end(), the_word.begin(), ::toupper);
        cout<<"The word was \""<<the_word<<"\""<<endl<<endl;
    }


    }while(playAgain());

    return 0;
}

// Guessing the word and displaying if the geuss was correct
void guess(string word, int n, string &guessed){

    char your_guess;
    int f = 0;
    cout<<"Your guess('0' for hint): ";             // TO-DO: condition for invalid i/p
    cin>>your_guess;

    if(!((your_guess>='a' && your_guess<='z') || (your_guess>='A' && your_guess<='Z') || (your_guess == '0'))){

        cout<<"Please Enter a valid input."<<endl;
        cout<<"Your guess('0' for hint): ";
        cin>>your_guess;
    }

    if(your_guess == '0'){


        if(hint < 1){
            cout<<"Sorry! No more hints available"<<endl;
            cout<<"Your guess: ";
            cin>>your_guess;
        }

        else{

            for(int i = 0; i < guessed.size(); i++){

                if(guessed[i] == '-'){
                    guessed[i] = toupper(the_word[i]);
                    av.erase(remove(av.begin(), av.end(), toupper(the_word[i])), av.end());
                    break;
                }
            }
        }

        hint--;
    }

    cout<<endl;

    for(int i = 0; i < n; i++){

        if(word[i] == toupper(your_guess)){
            guessed[i] = toupper(your_guess);
            f++;
        }
    }
        if(f==0 && your_guess != '0'){
            cout<<'\''<<your_guess<<'\''<<" is not present in the word"<<endl<<endl;
            wrong++;

            hangman(wrong);
        }
        
        av.erase(remove(av.begin(), av.end(), toupper(your_guess)), av.end()); // remove a letter which has been guessed(even if the guess is wrong)
        
}



// The images that will be shown with each wrong guess.

void hangman(int w){

    switch(w){

        case 1:
        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      ========="<<endl;
        break;


        case 2:
        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"  0   |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      ========="<<endl;
        break;


        case 3:
        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"  0   |"<<endl;
        cout<<" /    |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      ========="<<endl;
        break;


        case 4:
        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"  0   |"<<endl;
        cout<<" /|   |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      ========="<<endl;
        break;


        case 5:
        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"  0   |"<<endl;
        cout<<" /|\\  |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      ========="<<endl;
        break;


        case 6:
        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"  0   |"<<endl;
        cout<<" /|\\  |"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"      |"<<endl;
        cout<<"      ========="<<endl;
        break;


        case 7:
        cout<<"  +---+"<<endl;
        cout<<"  |   |"<<endl;
        cout<<"  0   |"<<endl;
        cout<<" /|\\  |"<<endl;
        cout<<"  |   |"<<endl;
        cout<<" /    |"<<endl;
        cout<<"      ========="<<endl;
        break;

    }
}

