#include <iostream>
#include "Circular_LL.h"

int main(){

    //creating the playlist head
    SingleSongNode<std::string>* playlist = nullptr;

    //add songs
    std::cout<<"\n";

    addSong(std::string("Song 1"), playlist);
    addSong(std::string("Song 2"), playlist);
    addSong(std::string("Song 3"), playlist); 

     std::cout<<"\n";

    NextSong(playlist);
    PrevSong(playlist);

    std::cout<<"\n";

    std::cout<<"Now playing: \n";
    PlayAll(playlist); 

    std::cout<<"\n";
    DeleteSong(std::string("Song 2"), playlist);
    std::cout<<"\n";

    std::cout<<"Now playing: \n";
    PlayAll(playlist);
    

 return 0;   
}
