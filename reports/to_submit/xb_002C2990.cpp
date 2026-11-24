// bin: xb
// va: 0x002C2990
// what: 
// tool: the portal's starter code (no AI)

// sub_002C2990 (0x002C2990, 136 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003DB74C[];
extern "C" char DAT_00461D3C[];
extern "C" char DAT_00461E34[];
extern "C" int DAT_004BFE68;
extern "C" int DAT_004BFE6C;
extern "C" void __stdcall sub_0029A250(int);
extern "C" void __stdcall sub_0032F5F0(int, int);

class Class_002C2990
{
public:
    Class_002C2990* sub_002C2990(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
    bool m_Field90; // +0x90
    bool m_Field91; // +0x91
    bool m_Field92; // +0x92
    char m_pad93[0x1];
    int m_Field94; // +0x94
    int m_Field98; // +0x98
};

Class_002C2990* Class_002C2990::sub_002C2990(int a1)
{
    sub_0029A250(a1);
    m_Field00 = (int)DAT_003DB74C;
    m_Field80 = 0;
    m_Field84 = 0;
    m_Field88 = 4;
    m_Field8C = 0;
    m_Field90 = false;
    m_Field91 = false;
    m_Field92 = false;
    m_Field94 = 0;
    m_Field98 = 0;
    if (!DAT_004BFE68) {
        sub_0032F5F0((int)DAT_00461D3C, (int)&DAT_004BFE68);
    }
    if (!DAT_004BFE6C) {
        sub_0032F5F0((int)DAT_00461E34, (int)&DAT_004BFE6C);
    }
    return this;
}
