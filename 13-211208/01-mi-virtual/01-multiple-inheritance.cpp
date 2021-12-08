#include <chrono>
#include <string>
#include <iostream>

struct PieceOfArt { std::chrono::time_point<std::chrono::steady_clock> date; };
struct Music : PieceOfArt { int bpm; };
struct Lyrics : PieceOfArt { std::string text; };
struct Song : Music, Lyrics {  // sizeof(Song) >= 2.
     std::string album;

     // Order of construction: Music, Lyrics (same order as after :), fields of Song.
     // Full order: Music::PieceOfArt, Music, Lyrics::PieceOfArt, Lyrics, Song.

     // Song(....) : Music(.....), Lyrics(....), album(....) { ... }
};

/*
Class diagram:

PieceOfArt   PieceOfArt
    ^            ^
    |            |
  Music        Music
    ^            ^
      \        /
        \    /
         Song

Layout is guaranteed, exact sides and padding vary:

0                  8      16               24      56       88
+---------------------------------------------------------+
| +---------------------+ +----------------------+        |
| | +------------+      | | +------------+       |        |
| | | PieceOfArt |      | | | PieceOfArt |       |        |
| | | +date      |      | | | +date      |       |        |
| | +------------+      | | +------------+       |        |
| |   Music             | |   Lyrics             |        |
| |                +bmp | |                +text |        |
| +---------------------+ +----------------------+        |
| Song                                                    |
|                                                  +album |
+---------------------------------------------------------+
*/

int main() {
   Song s;
   [[maybe_unused]] auto f1 = s.bpm;
   [[maybe_unused]] auto f2 = s.text;
   [[maybe_unused]] auto x = s.Music::date;
   [[maybe_unused]] auto y = s.Lyrics::date;
   // [[maybe_unused]] auto z = s.date;  // ambiguous member, clang++ has good error message, `using Music::date` won't help for some reason.

   std::cout << &s << " " << sizeof(s) << "\n";

   // [[maybe_unused]] PieceOfArt &p = s;  // ambiguous base, upcast is impossible

   Music &m = s;
   PieceOfArt &mp = m;
   // [[maybe_unused]] Song &ms1 = static_cast<Song&>(mp);  // ambiguous base, downcast is impossible
   [[maybe_unused]] Song &ms2 = static_cast<Song&>(m);  // unambiguous base, downcast is possible
   std::cout << "Music:\n";
   std::cout << &m << " " << &mp << " " << sizeof(m) << " " << sizeof(mp) << "\n";
   std::cout << &m.date << " " << &m.bpm << "\n";
   std::cout << "  downcast: " << &m << " --> " << &ms2 << "\n";

   Lyrics &l = s;
   PieceOfArt &lp = l;
   std::cout << "Lyrics:\n";
   std::cout << &l << " " << &lp << " " << sizeof(l) << " " << sizeof(lp) << "\n";
   std::cout << &l.date << " " << &l.text << "\n";
   std::cout << "  downcast: " << &l << " --> " << &static_cast<Song&>(l) << "\n";
}
