// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/ParamEnumConstList_DirectionalGetHitCondition_.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_06 (0x000CB8F0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_06 (Proto 0x000CB8F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class DirectionalGetHitCondition;

namespace fight { 
template <class T0> class ParamEnumConstList
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> int fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_06(int a1)
{
    return m_Field0C;
}

// ============================================================================
// [VERIFIED] fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01 (0x000CB900, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01 (Proto 0x000CB900, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class DirectionalGetHitCondition;

namespace fight { 
template <class T0> class ParamEnumConstList
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01()
{
    return 5;
}

// ============================================================================
// [VERIFIED] fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_05 (0x000D4FA0, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_05 (Proto 0x000D4FA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CD30[];

class DirectionalGetHitCondition;

namespace fight { 
template <class T0> class ParamEnumConstList
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1, int a2);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};
}

template <> int fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_05(int a1, int a2)
{
    if (a2 >= 0) {
        if (a2 >= m_Field0C) goto L_16;
        return *(int*)(m_Field08 + (a2 * 4));
    }
L_16:
    return (int)DAT_0037CD30;
}

