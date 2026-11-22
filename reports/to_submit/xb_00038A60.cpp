// bin: xb
// va: 0x00038A60
// what: Creates the game's single 4-byte object of this kind, keeps it in a global and returns it.
// tool: Claude Opus 5.5 (transplanted from xb:0x00016030, nearest by portal/tools/similar.py)
struct Made
{
    Made* sub_00038670();   // constructor
};

extern "C" Made* DAT_00474B28;
extern "C" void* __cdecl sub_000275B0(unsigned int a1, unsigned int a2);

// Creates the single instance and keeps it in a global (null if the allocation fails).
extern "C" Made* __cdecl sub_00038A60(void)
{
    void* memory = sub_000275B0(4, 11);
    Made* made = memory ? ((Made*)memory)->sub_00038670() : 0;
    DAT_00474B28 = made;
    return made;
}