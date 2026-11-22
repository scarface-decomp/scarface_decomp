// bin: proto
// va: 0x00121DA0
// what: 
// tool: the portal's starter code (no AI)

// sub_00121DA0 (Proto 0x00121DA0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00408DD8;
extern "C" float DAT_00408DDC;

class Class_00121DA0
{
public:
    void sub_00121DA0(float a1);
    char m_pad00[0x110];
    float m_Field110; // +0x110
};

void Class_00121DA0::sub_00121DA0(float a1)
{
    float t1;

    t1 = DAT_00408DDC;
    m_Field110 = ((DAT_00408DD8 - t1) * a1) + t1;
}
