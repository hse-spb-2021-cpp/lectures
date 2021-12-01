#include <chrono>
#include <string>
#include <iostream>

struct PieceOfArt { std::chrono::time_point<std::chrono::steady_clock> date; };
struct Music : PieceOfArt { };
struct Lyrics : PieceOfArt { };
struct Song : Music, Lyrics {  // sizeof(Song) >= 2.
     std::string album;
     // using Music::date;  // Можно, но в данном случае не нужно.

     // Song(....) : Music(.....), Lyrics(....), album(....) { ... }
};

int main() {
   Song s;
   auto x = s.Music::date;
   auto y = s.Lyrics::date;

   Music &m = s;
   Lyrics &l = s;
   PieceOfArt &p = static_cast<Music&>(s);
   std::cout << &s << "\n";
   std::cout << &m << "\n";
   std::cout << &l << "\n";
}
