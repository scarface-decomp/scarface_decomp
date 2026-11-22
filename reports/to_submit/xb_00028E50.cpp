// bin: xb
// va: 0x00028E50
// what: Creates the game's single 136-byte object of this kind, keeps it in a global and returns it.
// tool: Claude Opus 5.5 (transplanted from xb:0x00097870, nearest by portal/tools/similar.py)
struct Made
{
    Made* sub_00028A30();   // constructor
};

extern "C" Made* DAT_00473FA4;
extern "C" void* __cdecl sub_000275B0(unsigned int a1, unsigned int a2);

// Creates the single instance and keeps it in a global (null if the allocation fails).
extern "C" Made* __cdecl sub_00028E50(void)
{
    void* memory = sub_000275B0(136, 7);
    Made* made = memory ? ((Made*)memory)->sub_00028A30() : 0;
    DAT_00473FA4 = made;
    return made;
}