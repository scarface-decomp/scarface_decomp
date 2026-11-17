// bin: pc
// va: 0x006EDEF0
// tool: the portal's starter code (no AI)
// sub_006EDEF0 (0x006EDEF0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0077269C[];
extern "C" char sub_006EDB80[];
extern "C" char sub_006EDBD0[];
extern "C" char sub_006EDC20[];
extern "C" char sub_006EDC40[];
extern "C" char sub_006EDC60[];
extern "C" char sub_006EDC80[];

class Class_006EDEF0
{
public:
    Class_006EDEF0* sub_006EDEF0(int a1, int a2, bool a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    char m_pad1D[0x3];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    bool m_Field2C; // +0x2C
};

Class_006EDEF0* Class_006EDEF0::sub_006EDEF0(int a1, int a2, bool a3)
{
    m_Field20 = a2;
    m_Field04 = (int)sub_006EDB80;
    m_Field08 = (int)sub_006EDBD0;
    m_Field0C = (int)sub_006EDC20;
    m_Field10 = (int)sub_006EDC40;
    m_Field14 = (int)sub_006EDC60;
    m_Field18 = (int)sub_006EDC80;
    m_Field1C = false;
    m_Field00 = (int)DAT_0077269C;
    m_Field24 = a1;
    m_Field28 = a1;
    m_Field2C = a3;
    return this;
}
