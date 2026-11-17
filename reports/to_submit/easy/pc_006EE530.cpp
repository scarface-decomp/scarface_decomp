// bin: pc
// va: 0x006EE530
// tool: the portal's starter code (no AI)
// sub_006EE530 (0x006EE530, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006EE4A0(int, int);
};

extern "C" char DAT_007F682C[];
extern "C" int __stdcall sub_006EE3B0(int);
extern "C" int __cdecl sub_006EE870(int);

class Class_006EE530
{
public:
    int sub_006EE530(int a1);
};

int Class_006EE530::sub_006EE530(int a1)
{
    int r_eax;

    r_eax = sub_006EE3B0(a1);
    if (!r_eax) {
        r_eax = sub_006EE870((int)DAT_007F682C);
        if (r_eax) {
            r_eax = ((Object*)r_eax)->sub_006EE4A0((int)this, a1);
            return r_eax;
        }
        r_eax = 0;
    }
    return r_eax;
}
