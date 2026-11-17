// bin: xb
// va: 0x002B7220
// tool: the portal's starter code (no AI)
// sub_002B7220 (0x002B7220, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003DAED4[];

class Class_002B7220
{
public:
    Class_002B7220* sub_002B7220(int a1, int a2, int a3);
    void sub_002AF440(int, int, int);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    char m_pad38[0x18];
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
};

Class_002B7220* Class_002B7220::sub_002B7220(int a1, int a2, int a3)
{
    m_Field08 = a1;
    m_Field04 = 0;
    m_Field00 = (int)DAT_003DAED4;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    m_Field50 = 0;
    m_Field54 = 0;
    m_Field58 = 0;
    sub_002AF440(a1, a2, a3);
    return this;
}
