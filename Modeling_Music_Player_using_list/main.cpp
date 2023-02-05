#include<iostream>
#include<list>
#include<iomanip>
#include<cstring>
#include<string>
#include<iterator>
using namespace std;
class Song{
    friend std::ostream &operator<<(std::ostream &os,const Song &rhs);
    std::string Song_name;
    std::string Singer_name;
    int rate;
public:
    Song()=default;
    Song(string Song_name,string Singer_name,int rate)
    :Song_name{Song_name},Singer_name{Singer_name},rate{rate}{}
    string get_song()const{
        return this->Song_name;
    }
    string get_singer()const {
        return this->Singer_name;
    }
    int get_rate()const{
        return this->rate;
    }
    //to savely use objects with stl objects we must overload the operations (<)and (==)
    bool operator==(const Song &rhs){
        return (this->Song_name==rhs.Song_name);
    }
    bool operator<(const Song &rhs){
        return (this->Song_name<rhs.Song_name);
    }



};

void Display_list(const std::list<Song> &collection){

    for(auto song:collection){//song is a Song object
        cout
        <<setw(20)<<std::left<<song.get_song()
        <<setw(40)<<left<<song.get_singer()
        <<setw(10)<<left<<song.get_rate()<<"\n";
    }
    cout<<"\n";
}
void Display_Current(const std::list<Song>::iterator &it){

    cout<<"Current playing song:\n"
        <<setw(20)<<std::left<<it->get_song()
        <<setw(40)<<left<<it->get_singer()
        <<setw(10)<<left<<it->get_rate()<<"\n";
    
}
void First_Song(std::list<Song> &song,std::list<Song>::iterator &current){
    current=song.begin(); 
}
void pNext_Song(std::list<Song> &song,std::list<Song>::iterator &current){
    current++;
    if(current==song.end()) current =song.begin();
    
}
void pPervious_Song(std::list<Song> &song,std::list<Song>::iterator &current){
    if(current==song.begin()) std::advance(current,song.size()-1);
    else current --;
}
void Add_Song(std::list<Song> &song,std::list<Song>::iterator &current){
    string songname,singername;
    int Rate;
    cout<<"Enter the rate of this song: ";
    cin>>Rate;
    cin.ignore();
    cout<<"Enter the Song name: ";
    getline(cin,songname);
    cout<<"Enter the Singer name: ";
    getline(cin,singername);
    
    

    song.emplace(current,songname,singername,Rate);
    cout<<"Succesfully added\n";

    
}
void drive_menu(){
    cout<<"F - Play First Song\n";//list and current as an arguament 
    cout<<"N - Play Next Song\n";//current_song as an arguament
    cout<<"P - Play Pervious Song\n";//current_song as an arguament
    cout<<"A - Add and play a new Song at current location\n";//emplace(it,singname,singername,reate);list and current_song as an aruament
    cout<<"L - List the current playlist\n";//list as an arguament
    cout<<"===============================================\n";
    
}
int main(){
    std::list<Song> Songs
    {
        Song{"God's Plan","Drake",5},
        Song{"Never Be The Same","Camila Cabello",5},
        Song{"Pray For Me","The Weeknd and K. Lamar",4},
        Song{"The Middle","Zedd, Maren Morris & Grey",5},
        Song{"Wait","Maroone 5",4},
        Song{"Whatever It Takes","Imagine Dragons",3}
    };
    auto current_song=Songs.begin();
    Display_list(Songs);
    char selection;
    do{
        Display_Current(current_song);
        cout<<"\n";
        drive_menu();
        cout<<"Enter a Selection (Q for Quit): ";
        cin>>selection;
        selection=tolower(selection);
        switch(selection){
            case 'f':
                First_Song(Songs,current_song);
                break;
            case 'n':
                pNext_Song(Songs,current_song);
                break;
            case 'p':
                pPervious_Song(Songs,current_song);
                break;
            case 'a':
                Add_Song(Songs,current_song);
                break;
            case 'l':
                Display_list(Songs);
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
