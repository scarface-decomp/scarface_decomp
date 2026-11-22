// bin: xb
// va: 0x00196EC0
// what: Creates the game's single 92-byte object of this kind, keeps it in a global and returns it.
// tool: Claude Opus 5.5 (transplanted from xb:0x00097870, nearest by portal/tools/similar.py)
struct Made
{
    Made* sub_00196A40();   // constructor
};

extern "C" Made* DAT_0048C23C;
extern "C" void* __cdecl sub_000275B0(unsigned int a1, unsigned int a2);

// Creates the single instance and keeps it in a global (null if the allocation fails).
extern "C" Made* __cdecl sub_00196EC0(void)
{
    void* memory = sub_000275B0(92, 7);
    Made* made = memory ? ((Made*)memory)->sub_00196A40() : 0;
    DAT_0048C23C = made;
    return made;
}