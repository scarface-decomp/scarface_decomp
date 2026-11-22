// bin: proto
// va: 0x0015FA70
// what: 
// tool: the portal's starter code (no AI)

// NISWeaponFireAction::vfunc_06 (Proto 0x0015FA70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0015EE60(void);

class NISWeaponFireAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual bool vfunc_06(int a1);
    bool sub_0015EEE0();
};

bool NISWeaponFireAction::vfunc_06(int a1)
{
    if (!sub_0015EE60()) {
        return sub_0015EEE0();
    }
    return true;
}
