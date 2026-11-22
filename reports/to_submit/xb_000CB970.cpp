// bin: xb
// va: 0x000CB970
// what: Creates the game's single 24-byte object of this kind, keeps it in a global and returns it.
// tool: Claude Opus 5.5 (transplanted from xb:0x00097870, nearest by portal/tools/similar.py)
struct Made
{
    Made* sub_000CB560();   // constructor
};

extern "C" Made* DAT_004870BC;
extern "C" void* __cdecl sub_000275B0(unsigned int a1, unsigned int a2);

// Creates the single instance and keeps it in a global (null if the allocation fails).
extern "C" Made* __cdecl sub_000CB970(void)
{
    void* memory = sub_000275B0(24, 18);
    Made* made = memory ? ((Made*)memory)->sub_000CB560() : 0;
    DAT_004870BC = made;
    return made;
}