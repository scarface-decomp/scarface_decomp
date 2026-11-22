// bin: xb
// va: 0x00068740
// what: Creates the game's single 4-byte object of this kind, keeps it in a global and returns it.
// tool: Claude Opus 5.5 (transplanted from xb:0x00016030, nearest by portal/tools/similar.py)
struct Made
{
    Made* sub_000684F0();   // constructor
};

extern "C" Made* DAT_00476A54;
extern "C" void* __cdecl sub_000275B0(unsigned int a1, unsigned int a2);

// Creates the single instance and keeps it in a global (null if the allocation fails).
extern "C" Made* __cdecl sub_00068740(void)
{
    void* memory = sub_000275B0(4, 4);
    Made* made = memory ? ((Made*)memory)->sub_000684F0() : 0;
    DAT_00476A54 = made;
    return made;
}