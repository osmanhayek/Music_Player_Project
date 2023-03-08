#include<iostream>
#include "list.cpp"
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
class Song{
    string song_name;
    string singer_name;
    int rate;//between 1 and 5
    friend std::ostream &operator<<(std::ostream &os,const Song &song);
public:
    Song(string song_name="None",string singer_name="None",int rate=1)
    :song_name{song_name},singer_name{singer_name},rate{rate} {}
    string get_name()const{return song_name;}
    string get_sname()const{return singer_name;}
    int get_rate()const {return rate;}


};

std::ostream &operator<<(std::ostream &os,const Song &song ){
    os
        <<setw(20)<<std::left<<song.get_name()
        <<setw(40)<<left<<song.get_sname()
        <<setw(10)<<left<<song.get_rate()<<"\n";
    
    os<<"\n";
    return os;
}


void drive_menu(){
    cout<<"F - Play First Song\n";//list and current as an arguament 
    cout<<"N - Play Next Song\n";//current_song as an arguament
    cout<<"P - Play Pervious Song\n";//current_song as an arguament
    cout<<"A - Add and play a new Song at current location\n";//emplace(it,singname,singername,reate);list and current_song as an aruament
    cout<<"L - List the current playlist\n";//list as an arguament
    cout<<"===============================================\n";
}

void display_current(Node<Song> *current){
    cout<<"Current playing song:\n"
        <<current->value;
}
void add_Song(list<Song> *list,int index){
    string songname,singername;
    int Rate;
    cout<<"Enter the rate of this song: ";
    cin>>Rate;
    cin.ignore();
    cout<<"Enter the Song name: ";
    getline(cin,songname);
    cout<<"Enter the Singer name: ";
    getline(cin,singername);
    Song song{songname,singername,Rate};
    list->insert(index,song);
}
//display_current(),first_song(),pre_song(),addSong(),drive_menu()
int main(){
    vector<Song> vec
    {
        Song{"God's Plan","Drake",5},
        Song{"Never Be The Same","Camila Cabello",5},
        Song{"Pray For Me","The Weeknd and K. Lamar",4},
        Song{"The Middle","Zedd, Maren Morris & Grey",5},
        Song{"Wait","Maroone 5",4},
        Song{"Whatever It Takes","Imagine Dragons",3}
    };
    list<Song> lis{vec};
    auto current_song=lis.begin();
    cout<<"Welcome to my project\n===================================\n";
    lis.display();

    char selection;
    do{
        cout<<"current song:\n"<<current_song->value;
        cout<<"\n";
        drive_menu();
        cout<<"Enter a Selection (Q for Quit): ";
        cin>>selection;
        selection=tolower(selection);
        switch(selection){
            case 'f':
                current_song=lis.begin();
                break;
            case 'n':
                current_song=current_song->next;
                break;
            case 'p':
                current_song=current_song->pre;
                break;
            case 'a':
                add_Song(&lis,2);
                break;
            case 'l':
                lis.display();
                break;
            case 'q':
                break;
            default:
                cout<<"Enter a valid selection please!\n";
                break;     

        }
    }while(selection!='q'&& selection!='Q');

    return 0;
}
