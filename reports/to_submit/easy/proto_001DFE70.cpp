// bin: proto
// va: 0x001DFE70
// tool: the portal's starter code (no AI)
// sub_001DFE70 (0x001DFE70, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD90;

class Class_001DFE70
{
public:
    bool sub_001DFE70();
    char m_pad00[0x104];
    float m_Field104; // +0x104
};

bool Class_001DFE70::sub_001DFE70()
{
    if (m_Field104 > DAT_0037CD90) {
        return true;
    }
    return false;
}
