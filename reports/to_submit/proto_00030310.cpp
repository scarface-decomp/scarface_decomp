// bin: proto
// va: 0x00030310
// what: 
// tool: the portal's starter code (no AI)

// RoadPath::vfunc_01 (Proto 0x00030310, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class RoadPath
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x8];
    short m_Field0C; // +0x0C
};

int RoadPath::vfunc_01()
{
    return m_Field0C >= 2;
}
