// bin: xb
// va: 0x00112F80
// tool: the portal's starter code (no AI)
// sub_00112F80 (0x00112F80, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00111FE0(int);
};

extern "C" int DAT_004897F0;

class Class_00112F80
{
public:
    bool sub_00112F80();
    char m_pad00[0x74];
    int m_Field74; // +0x74
};

bool Class_00112F80::sub_00112F80()
{
    if ((m_Field74 & 2032) != 2032) {
        return ((Object*)DAT_004897F0)->sub_00111FE0((int)this);
    }
    return true;
}
