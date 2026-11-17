// bin: proto
// va: 0x000F3240
// tool: the portal's starter code (no AI)
// GameSetIteratorFunctionFilter<CharacterObject>::vfunc_00 (0x000F3240, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CharacterObject;

template <class T0> class GameSetIteratorFunctionFilter
{
public:
    virtual int vfunc_00(int a1);
    int m_Field04; // +0x04
};

template <> int GameSetIteratorFunctionFilter<CharacterObject>::vfunc_00(int a1)
{
    return ((int (__cdecl*)(int))m_Field04)(a1);
}
