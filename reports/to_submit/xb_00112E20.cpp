// bin: xb
// va: 0x00112E20
// what: Creates the game's single 40-byte object of this kind, keeps it in a global and returns it.
// tool: Claude Opus 5.5 (transplanted from xb:0x00097870, nearest by portal/tools/similar.py)
struct Made
{
    Made* sub_00112D50();   // constructor
};

extern "C" Made* DAT_004897F0;
extern "C" void* __cdecl sub_000275B0(unsigned int a1, unsigned int a2);

// Creates the single instance and keeps it in a global (null if the allocation fails).
extern "C" Made* __cdecl sub_00112E20(void)
{
    void* memory = sub_000275B0(40, 10);
    Made* made = memory ? ((Made*)memory)->sub_00112D50() : 0;
    DAT_004897F0 = made;
    return made;
}