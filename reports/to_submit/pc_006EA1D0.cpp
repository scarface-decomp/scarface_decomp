// bin: pc
// va: 0x006EA1D0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EA1D0 (PC 0x006EA1D0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DC000(void);

class Class_006EA1D0
{
public:
    int sub_006EA1D0();
    int sub_006E9F60(int, int);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

int Class_006EA1D0::sub_006EA1D0()
{
    int r_eax;

    r_eax = sub_006DC000();
    r_eax -= m_Field08;
    m_Field14 = 0;
    m_Field10 = r_eax;
    if ((unsigned int)r_eax > (unsigned int)m_Field04) {
        r_eax = sub_006E9F60(2, 0);
    }
    return r_eax;
}
