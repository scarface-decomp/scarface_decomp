// bin: proto
// va: 0x002065D0
// tool: the portal's starter code (no AI)
// pure3d::frontend::FeTextBibleString::vfunc_00 (0x002065D0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0020B670(int);

namespace pure3d { namespace frontend {

class FeTextBibleString
{
public:
    virtual int vfunc_00();
    int m_Field04; // +0x04
};

int FeTextBibleString::vfunc_00()
{
    return sub_0020B670(m_Field04);
}

} }
