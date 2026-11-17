// bin: proto
// va: 0x001F9B70
// tool: the portal's starter code (no AI)
// sub_001F9B70 (0x001F9B70, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004285EC;
extern "C" int DAT_004638F4;

class Class_001F9B70
{
public:
    bool sub_001F9B70();
    char m_pad00[0x10];
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
    char m_pad12[0x102];
    int m_Field114; // +0x114
    char m_pad118[0x208];
    bool m_Field320; // +0x320
};

bool Class_001F9B70::sub_001F9B70()
{
    int t1;
    bool t2;

    if (!m_Field10) {
        return true;
    }
    t1 = DAT_004285EC;
    if (DAT_004285EC) {
        t2 = ((bool (__cdecl*)(int, int))t1)((int)this, DAT_004638F4);
        m_Field11 = false;
        m_Field10 = false;
        m_Field114 = -1;
        m_Field320 = true;
        return t2;
    }
    return false;
}
