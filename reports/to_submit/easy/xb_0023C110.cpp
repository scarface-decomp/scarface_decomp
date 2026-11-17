// bin: xb
// va: 0x0023C110
// tool: the portal's starter code (no AI)
// sub_0023C110 (0x0023C110, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00457BE4;
extern "C" int DAT_00492C40;

class Class_0023C110
{
public:
    bool sub_0023C110();
    char m_pad00[0x10];
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
    char m_pad12[0x102];
    int m_Field114; // +0x114
    char m_pad118[0x208];
    bool m_Field320; // +0x320
};

bool Class_0023C110::sub_0023C110()
{
    int t1;
    bool t2;

    if (!m_Field10) {
        return true;
    }
    t1 = DAT_00457BE4;
    if (DAT_00457BE4) {
        t2 = ((bool (__cdecl*)(int, int))t1)((int)this, DAT_00492C40);
        m_Field11 = false;
        m_Field10 = false;
        m_Field114 = -1;
        m_Field320 = true;
        return t2;
    }
    return false;
}
