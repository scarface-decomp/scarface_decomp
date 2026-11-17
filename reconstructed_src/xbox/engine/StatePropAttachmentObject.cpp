// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/StatePropAttachmentObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] StatePropAttachmentObject::vfunc_00 (0x001EECE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropAttachmentObject::vfunc_00 (0x001EECE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043E49C[];

class StatePropAttachmentObject
{
public:
    virtual void* vfunc_00();
};

void* StatePropAttachmentObject::vfunc_00()
{
    return DAT_0043E49C;
}

// ============================================================================
// [VERIFIED] StatePropAttachmentObject::vfunc_00 (0x001EF300, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as StatePropAttachmentObject::vfunc_00 (Proto 0x001B55B0), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropAttachmentObject::vfunc_00 (Proto 0x001EF300, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 32 bytes to the start of the object and jumps to the real function at
// 0x001EF310. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (32 bytes).

class StatePropAttachmentObject_Base0 { public: virtual void sub_001EF310(); char m_pad04[0x1C]; };
class StatePropAttachmentObject_Base1 { public: virtual void sub_001EF310(); };

class StatePropAttachmentObject : public StatePropAttachmentObject_Base0, public StatePropAttachmentObject_Base1
{
public:
    StatePropAttachmentObject();
    virtual void sub_001EF310();          // the real function; the thunk jumps here
};

StatePropAttachmentObject::StatePropAttachmentObject() {}                  // building one is what makes the compiler write its tables and the thunk

// ============================================================================
// [VERIFIED] StatePropAttachmentObject::vfunc_01 (0x001EF350, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as StatePropAttachmentObject::vfunc_01 (Proto 0x001B5600), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropAttachmentObject::vfunc_01 (Proto 0x001EF350, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00087EB0(int);
    int sub_0008FAC0(int);
    void sub_0008F8C0(int);
    void sub_001C6A10(int);
};

extern "C" int __cdecl sub_00027590(int);
extern "C" int __cdecl sub_0002AC90(int);

class StatePropAttachmentObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void StatePropAttachmentObject::vfunc_01(int a1, int a2)
{
    int r_esi, t1;

    r_esi = a1;
    if (a1) {
        t1 = sub_00027590(16);
        if (t1) {
            r_esi = ((Object*)t1)->sub_0008FAC0(a1);
        } else {
            r_esi = 0;
        }
        ((Object*)r_esi)->sub_001C6A10((int)(&m_Field08));
        ((Object*)r_esi)->sub_0008F8C0(sub_0002AC90(m_Field04));
        ((Object*)a2)->sub_00087EB0(r_esi);
    }
}

