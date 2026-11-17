// bin: xb
// va: 0x00113450
// tool: the portal's starter code (no AI)
// sub_00113450 (0x00113450, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00112060(int, float);
};

extern "C" int DAT_004897F0;

class Class_00113450
{
public:
    int sub_00113450(float a1);
    char m_pad00[0x74];
    int m_Field74; // +0x74
};

int Class_00113450::sub_00113450(float a1)
{
    int r_eax;

    r_eax = m_Field74;
    r_eax &= 2032;
    if (r_eax != 2032) {
        r_eax = ((Object*)DAT_004897F0)->sub_00112060((int)this, a1 * a1);
    }
    return r_eax;
}
