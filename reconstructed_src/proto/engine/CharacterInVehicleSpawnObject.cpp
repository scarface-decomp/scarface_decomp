// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CharacterInVehicleSpawnObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CharacterInVehicleSpawnObject::vfunc_00 (0x001A1E40, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterInVehicleSpawnObject::vfunc_00 (0x001A1E40, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00417238[];

class CharacterInVehicleSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* CharacterInVehicleSpawnObject::vfunc_00()
{
    return DAT_00417238;
}

// ============================================================================
// [VERIFIED] CharacterInVehicleSpawnObject::vfunc_35 (0x001A1E50, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Sends a message (64) to its main linked object when a flag is set, and to each of four others that are switched on.
// ============================================================================
// bin: proto
// va: 0x001A1E50
// what: Sends a message (64) to its main linked object when a flag is set, and to each of four others that are switched on.
// tool: Claude Opus 5.5 (transplanted from xb:0x001D98E0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field94
{
    void sub_001A6530(int);
};

struct Object
{
    int sub_001A6530(int);
};

class CharacterInVehicleSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    char m_pad04[0x94];
    Field94* m_Field98; // +0x98
    char m_pad9C[0x4];
    bool m_FieldA0; // +0xA0
    char m_padA1[0x107];
    int m_Field1A8; // +0x1A8
};

void CharacterInVehicleSpawnObject::vfunc_37()
{
    int r_eax, r_ebx, r_esi;

    r_eax = m_FieldA0;
    if ((unsigned char)r_eax) {
        m_Field98->sub_001A6530(64);
    }
    r_esi = 0;
    r_ebx = (int)(&m_Field1A8);
    do {
        r_eax = *(bool*)((int)this + r_esi + 456);
        if ((unsigned char)r_eax) {
            r_eax = ((Object*)*(int*)r_ebx)->sub_001A6530(64);
        }
        r_esi += 1;
        r_ebx += 4;
    } while (r_esi < 4);
}

// ============================================================================
// [VERIFIED] CharacterInVehicleSpawnObject::vfunc_01 (0x001A20B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterInVehicleSpawnObject::vfunc_01 (0x001A20B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001A1DE0(void);
extern "C" void __cdecl sub_00025160(int);

class CharacterInVehicleSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CharacterInVehicleSpawnObject* vfunc_01(int a1);
};

CharacterInVehicleSpawnObject* CharacterInVehicleSpawnObject::vfunc_01(int a1)
{
    sub_001A1DE0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

