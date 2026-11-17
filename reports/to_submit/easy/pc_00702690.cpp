// bin: pc
// va: 0x00702690
// tool: the portal's starter code (no AI)
// movie::BinkCallback::vfunc_00 (0x00702690, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0073523C[];
extern "C" char DAT_00736074[];
extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);

namespace movie {

class BinkCallback
{
public:
    virtual int vfunc_00(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

int BinkCallback::vfunc_00(int a1)
{
    int r_eax;

    if (this) {
        r_eax = (int)(&m_Field08);
    } else {
        r_eax = 0;
    }
    *(int*)r_eax = (int)DAT_0073523C;
    r_eax = m_Field04;
    DAT_007F5A70 = r_eax;
    *(int*)this = (int)DAT_00736074;
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    r_eax = (int)this;
    return r_eax;
}

}
