// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GlobalFunctions.cpp (909 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 909 of 11,142 functions matched (8.16%). NOT COMPLETE YET.
// The 10,233 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] sub_00011AA0 (0x00011AA0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011540 (0x00011540), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037CD24[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00011AA0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037CD24;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00011B10 (0x00011B10, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000115B0 (0x000115B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037CD2C[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00011B10(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0037CD2C;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00011B80 (0x00011B80, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011540 (0x00011540), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037CD38[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00011B80(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037CD38;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00011CC0 (0x00011CC0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011770 (0x00011770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00011CC0 (0x00011CC0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00011CC0
{
public:
    int sub_00011CC0();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int Class_00011CC0::sub_00011CC0()
{
    int r_eax;

    if (m_Field1C == 1) {
        r_eax = m_Field18;
        if (r_eax) goto L_0F;
    }
    r_eax = 0;
L_0F:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00011CD0 (0x00011CD0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011780 (0x00011780), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00011CD0 (0x00011CD0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00011CD0
{
public:
    int sub_00011CD0();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int Class_00011CD0::sub_00011CD0()
{
    int r_eax;

    if (m_Field1C == 2) {
        r_eax = m_Field18;
        if (r_eax) goto L_0F;
    }
    r_eax = 0;
L_0F:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00011D10 (0x00011D10, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000117F0 (0x000117F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00011D10 (0x00011D10, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field18
{
    void sub_002B1C60(int, int);
};

class Class_00011D10
{
public:
    void sub_00011D10(int a1);
    char m_pad00[0x18];
    Field18* m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

void Class_00011D10::sub_00011D10(int a1)
{
    if (m_Field1C == 1) {
        if (!m_Field18) goto L_1C;
        m_Field18->sub_002B1C60(a1, 65535);
    }
L_1C:
    ;
}

// ============================================================================
// [VERIFIED] sub_00011F50 (0x00011F50, 82 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011AE0 (0x00011AE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00011F50 (0x00011F50, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025120(int);

class Class_00011F50
{
public:
    int sub_00011F50(int a1);
    char m_pad00[0x18];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int Class_00011F50::sub_00011F50(int a1)
{
    int r_eax;

    r_eax = m_Field1C;
    if (!r_eax) {
        r_eax = m_Field18;
        if (!r_eax) {
            r_eax = sub_00025120(24);
            m_Field18 = r_eax;
        }
        r_eax = m_Field18;
        *(int*)r_eax = *(int*)a1;
        *(int*)(r_eax + 4) = *(int*)(a1 + 4);
        *(int*)(r_eax + 8) = *(int*)(a1 + 8);
        *(int*)(r_eax + 12) = *(int*)(a1 + 12);
        *(int*)(r_eax + 16) = *(int*)(a1 + 16);
        *(int*)(r_eax + 20) = *(int*)(a1 + 20);
        m_Field1C = 2;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000120B0 (0x000120B0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011C50 (0x00011C50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000120B0 (0x000120B0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000120B0
{
public:
    bool sub_000120B0();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

bool Class_000120B0::sub_000120B0()
{
    int t1;

    if (m_Field1C == 1) {
        t1 = m_Field18;
        if (!m_Field18) goto L_17;
        if (!*(int*)(t1 + 44)) goto L_17;
        return true;
    }
L_17:
    return false;
}

// ============================================================================
// [VERIFIED] sub_00012410 (0x00012410, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011F40 (0x00011F40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012410 (0x00012410, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_00012410
{
public:
    Class_00012410* sub_00012410(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_00012410* Class_00012410::sub_00012410(int a1)
{
    int t2;

    m_Field00 = 0;
    m_Field04 = *(int*)(a1 + 12);
    ((Object*)a1)->vfunc_00();
    t2 = m_Field00;
    if (m_Field00) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field00 = a1;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00012440 (0x00012440, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011F70 (0x00011F70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012440 (0x00012440, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_00012440
{
public:
    void sub_00012440();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

void Class_00012440::sub_00012440()
{
    int t1;

    t1 = m_Field00;
    if (m_Field00) {
        ((Object*)t1)->vfunc_01();
        m_Field00 = 0;
    }
    m_Field04 = -1;
}

// ============================================================================
// [VERIFIED] sub_00012480 (0x00012480, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011FB0 (0x00011FB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012480 (0x00012480, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00440CD8[];
extern "C" int DAT_00441428;

bool __cdecl sub_00012480(int a1)
{
    if (a1 < DAT_00441428) {
        return *(bool*)(((int)DAT_00440CD8) + a1);
    }
    return false;
}

// ============================================================================
// [VERIFIED] sub_00012560 (0x00012560, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012090 (0x00012090), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012560 (0x00012560, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043D910[];
extern "C" int __cdecl sub_000124A0(int);

void __cdecl sub_00012560(int a1, int a2)
{
    int t1;

    if (a2) {
        t1 = sub_000124A0(a1);
        if (t1 < 0) goto L_26;
        if (t1 >= 56) goto L_26;
        DAT_0043D910[t1] = a2;
    }
L_26:
    ;
}

// ============================================================================
// [VERIFIED] sub_00012590 (0x00012590, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000120C0 (0x000120C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012590 (0x00012590, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043D9F0[];

int __cdecl sub_00012590(int a1, int a2)
{
    if (a1 >= 0) {
        if (a1 >= 56) goto L_27;
        if (a2 < 0) goto L_27;
        if (a2 >= 56) goto L_27;
        return DAT_0043D9F0[(a1 * 56) + a2];
    }
L_27:
    return 0;
}

// ============================================================================
// [VERIFIED] sub_000125C0 (0x000125C0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000120F0 (0x000120F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000125C0 (0x000125C0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043D910[];

int __cdecl sub_000125C0(int a1)
{
    if (a1 >= 0) {
        if (a1 >= 56) goto L_15;
        return DAT_0043D910[a1];
    }
L_15:
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00012650 (0x00012650, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000121A0 (0x000121A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012650 (0x00012650, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00011D30(int);
};

int __cdecl sub_00012650(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        r_eax = ((Object*)*(int*)r_eax)->sub_00011D30(a2);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00012670 (0x00012670, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000121A0 (0x000121A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012670 (0x00012670, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000120D0(int);
};

int __cdecl sub_00012670(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        r_eax = ((Object*)*(int*)r_eax)->sub_000120D0(a2);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00012690 (0x00012690, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000121A0 (0x000121A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00012690 (0x00012690, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00012110(int);
};

int __cdecl sub_00012690(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        r_eax = ((Object*)*(int*)r_eax)->sub_00012110(a2);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000126B0 (0x000126B0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000121A0 (0x000121A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000126B0 (0x000126B0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00011D10(int);
};

int __cdecl sub_000126B0(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        r_eax = ((Object*)*(int*)r_eax)->sub_00011D10(a2);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000126D0 (0x000126D0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012230 (0x00012230), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000126D0 (0x000126D0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_000126D0(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        r_eax = *(int*)r_eax;
        *(int*)(r_eax + 20) = a2;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000128C0 (0x000128C0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012420 (0x00012420), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000128C0 (0x000128C0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00441410;

class Class_000128C0
{
public:
    Class_000128C0* sub_000128C0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_000128C0* Class_000128C0::sub_000128C0(int a1)
{
    m_Field00 = a1;
    m_Field04 = DAT_00441410;
    DAT_00441410 = a1;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000128E0 (0x000128E0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012440 (0x00012440), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000128E0 (0x000128E0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00441410;

class Class_000128E0
{
public:
    int sub_000128E0();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_000128E0::sub_000128E0()
{
    int t1;

    t1 = m_Field04;
    DAT_00441410 = m_Field04;
    return t1;
}

// ============================================================================
// [VERIFIED] sub_00016290 (0x00016290, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00015AE0 (0x00015AE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_0037CE58[];
extern "C" int __cdecl sub_002014E0(const char* name, int a2);

// A small object that is nothing but its vtable, made on the stack and handed to the target.
struct Visitor
{
    void* vtable;
};

struct Target
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(Visitor* visitor, int key);
};

void __cdecl sub_00016290(Target* target, const char* name)
{
    int key = sub_002014E0(name, 0);
    Visitor visitor;
    visitor.vtable = DAT_0037CE58;
    target->vfunc_04(&visitor, key);
}

// ============================================================================
// [VERIFIED] sub_00017190 (0x00017190, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000173D0 (0x000173D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00017190 (0x00017190, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00017190
{
public:
    Class_00017190* sub_00017190();
    bool m_Field00; // +0x00
    char m_pad01[0x3F];
    bool m_Field40; // +0x40
    char m_pad41[0x3F];
    int m_Field80; // +0x80
};

Class_00017190* Class_00017190::sub_00017190()
{
    m_Field80 = -1;
    m_Field00 = false;
    m_Field40 = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000173F0 (0x000173F0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00017630 (0x00017630), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000173F0 (0x000173F0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000173F0
{
public:
    Class_000173F0* sub_000173F0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    unsigned short m_Field08; // +0x08
};

Class_000173F0* Class_000173F0::sub_000173F0()
{
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00017400 (0x00017400, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00017640 (0x00017640), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00017400 (0x00017400, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00017400
{
public:
    Class_00017400* sub_00017400(int a1, int a2, int a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    unsigned short m_Field08; // +0x08
};

Class_00017400* Class_00017400::sub_00017400(int a1, int a2, int a3)
{
    m_Field00 = a1;
    m_Field04 = a3;
    m_Field08 = (unsigned short)a2;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000176F0 (0x000176F0, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00017930 (0x00017930), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000176F0 (0x000176F0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002B6FC0(int);
};

extern "C" int __cdecl sub_00014050(int);

class Class_000176F0
{
public:
    int sub_000176F0();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    unsigned short m_Field08; // +0x08
};

int Class_000176F0::sub_000176F0()
{
    int r_eax;

    r_eax = m_Field00;
    if (r_eax) {
        r_eax = *(int*)(r_eax + 36);
        r_eax = *(int*)r_eax;
        r_eax = ((Object*)r_eax)->sub_002B6FC0(m_Field08);
        r_eax = sub_00014050((unsigned char)((unsigned char)r_eax));
        if (!r_eax) goto L_2B;
        r_eax = *(int*)(r_eax + 40);
        return r_eax;
    }
L_2B:
    r_eax |= -1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00017760 (0x00017760, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000179A0 (0x000179A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00017760 (0x00017760, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00441510;
extern "C" int DAT_00441514;

int __cdecl sub_00017760(int a1, int a2)
{
    DAT_00441510 = a1;
    DAT_00441514 = a2;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_000182D0 (0x000182D0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000184E0 (0x000184E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000182D0 (0x000182D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000182D0
{
public:
    int sub_000182D0();
};

int Class_000182D0::sub_000182D0()
{
    int r_ecx;

    r_ecx = (int)this;
    if (*(bool*)(r_ecx + 12)) {
        return *(unsigned short*)(*(int*)r_ecx + 50);
    }
    r_ecx = *(int*)r_ecx;
    return *(unsigned short*)(r_ecx + 48);
}

// ============================================================================
// [VERIFIED] sub_000182F0 (0x000182F0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018500 (0x00018500), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000182F0 (0x000182F0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000182F0
{
public:
    int sub_000182F0();
};

int Class_000182F0::sub_000182F0()
{
    int r_ecx;

    r_ecx = (int)this;
    if (*(bool*)(r_ecx + 12)) {
        return *(unsigned short*)(*(int*)r_ecx + 48);
    }
    r_ecx = *(int*)r_ecx;
    return *(unsigned short*)(r_ecx + 50);
}

// ============================================================================
// [VERIFIED] sub_00018310 (0x00018310, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018520 (0x00018520), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00018310 (0x00018310, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018310
{
public:
    int sub_00018310();
};

int Class_00018310::sub_00018310()
{
    int r_ecx;

    r_ecx = (int)this;
    if (*(bool*)(r_ecx + 12)) {
        return *(int*)(*(int*)r_ecx + 4);
    }
    r_ecx = *(int*)r_ecx;
    return *(int*)(r_ecx + 32);
}

// ============================================================================
// [VERIFIED] sub_00018570 (0x00018570, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000187A0 (0x000187A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00018570 (0x00018570, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018570
{
public:
    Class_00018570* sub_00018570(int a1, int a2, bool a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    bool m_Field08; // +0x08
};

Class_00018570* Class_00018570::sub_00018570(int a1, int a2, bool a3)
{
    m_Field00 = a2;
    m_Field04 = a1;
    m_Field08 = a3;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000185F0 (0x000185F0, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018820 (0x00018820), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000185F0 (0x000185F0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000185F0
{
public:
    int sub_000185F0();
};

int Class_000185F0::sub_000185F0()
{
    int r_ecx;

    r_ecx = (int)this;
    if (*(bool*)(r_ecx + 8)) {
        return *(unsigned short*)(*(int*)r_ecx + 50);
    }
    r_ecx = *(int*)r_ecx;
    return *(unsigned short*)(r_ecx + 48);
}

// ============================================================================
// [VERIFIED] sub_00018790 (0x00018790, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000189E0 (0x000189E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00018790 (0x00018790, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018790
{
public:
    int sub_00018790();
    int m_Field00; // +0x00
};

int Class_00018790::sub_00018790()
{
    return *(int*)(m_Field00 + 24);
}

// ============================================================================
// [VERIFIED] sub_00018BD0 (0x00018BD0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018E20 (0x00018E20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00018BD0 (0x00018BD0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00290CF0();
};

extern "C" void __cdecl sub_00290CF0(void);

class Class_00018BD0
{
public:
    Class_00018BD0* sub_00018BD0();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    Field10 m_Field10; // +0x10
    char m_pad11[0xB];
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_00018BD0* Class_00018BD0::sub_00018BD0()
{
    ::sub_00290CF0();
    m_Field0C = 0;
    m_Field10.sub_00290CF0();
    m_Field1C = 0;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00018D00 (0x00018D00, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F47DC[];
extern "C" void* __cdecl sub_00028CF0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_00018D00(int a1, int a2)
{
    void* object = sub_00028CF0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_003F47DC, 0);
}

// ============================================================================
// [VERIFIED] sub_00018D30 (0x00018D30, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F47F4[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_00018D30(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_003F47F4, 0);
}

// ============================================================================
// [VERIFIED] sub_00018DC0 (0x00018DC0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018FF0 (0x00018FF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00018DC0 (0x00018DC0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018DC0
{
public:
    Class_00018DC0* sub_00018DC0(int a1, int a2, int a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
};

Class_00018DC0* Class_00018DC0::sub_00018DC0(int a1, int a2, int a3)
{
    m_Field00 = *(int*)a1;
    m_Field04 = *(int*)(a1 + 4);
    m_Field08 = *(int*)(a1 + 8);
    m_Field0C = *(int*)a2;
    m_Field10 = *(int*)(a2 + 4);
    m_Field14 = *(int*)(a2 + 8);
    m_Field18 = *(int*)a3;
    m_Field1C = *(int*)(a3 + 4);
    m_Field20 = *(int*)(a3 + 8);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00018E10 (0x00018E10, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00019040 (0x00019040), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00018E10 (0x00018E10, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018E10
{
public:
    Class_00018E10* sub_00018E10(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_00018E10* Class_00018E10::sub_00018E10(int a1)
{
    m_Field00 = *(int*)a1;
    m_Field04 = *(int*)(a1 + 4);
    m_Field08 = *(int*)(a1 + 8);
    m_Field0C = *(int*)(a1 + 12);
    m_Field10 = *(int*)(a1 + 16);
    m_Field14 = *(int*)(a1 + 20);
    return this;
}

// ============================================================================
// [VERIFIED] sub_0001B600 (0x0001B600, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001BFB0 (0x0001BFB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001B600 (0x0001B600, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0001A4C0(void);
extern "C" void __cdecl sub_0001A7A0(void);

void __cdecl sub_0001B600(void)
{
    sub_0001A4C0();
    sub_0001A7A0();
}

// ============================================================================
// [VERIFIED] sub_0001C310 (0x0001C310, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001CE60 (0x0001CE60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001C310 (0x0001C310, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0001C2A0(int, int);
};

extern "C" int DAT_00463B78;

void __cdecl sub_0001C310(int a1, int a2)
{
    ((Object*)DAT_00463B78)->sub_0001C2A0(a1, a2);
}

// ============================================================================
// [VERIFIED] sub_0001C330 (0x0001C330, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001C330 (0x0001C330, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;

void __cdecl sub_0001C330(void)
{
    DAT_00462DD4.sub_0008D4E0(DAT_00462DD8);
}

// ============================================================================
// [VERIFIED] sub_0001D130 (0x0001D130, 58 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E100 (0x0001E100), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001D130 (0x0001D130, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    void sub_0008E240(int);
};

extern "C" char DAT_0037D5CC[];
extern "C" void __stdcall sub_00028470(int, int);

class Class_0001D130
{
public:
    Class_0001D130* sub_0001D130(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    bool m_Field28; // +0x28
    bool m_Field29; // +0x29
    bool m_Field2A; // +0x2A
    char m_pad2B[0x1];
    Field2C m_Field2C; // +0x2C
};

Class_0001D130* Class_0001D130::sub_0001D130(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_0037D5CC;
    m_Field2C.sub_0008E240(a2);
    m_Field24 = 0;
    m_Field20 = 0;
    m_Field28 = false;
    m_Field29 = false;
    m_Field2A = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0001D530 (0x0001D530, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E560 (0x0001E560), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001D530 (0x0001D530, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00446818[];
extern "C" int __cdecl sub_00201440(int, int);

int __cdecl sub_0001D530(int a1)
{
    int r_eax, r_ecx;

    r_eax = a1;
    r_eax = sub_00201440(a1, 0);
    r_ecx = 0;
L_11:
    if (DAT_00446818[r_ecx] != r_eax) {
        r_ecx += 1;
        if (r_ecx < 20) goto L_11;
        r_eax = 0;
        return r_eax;
    }
    r_eax = 1;
    r_eax <<= (unsigned char)r_ecx;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0001D590 (0x0001D590, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001D590 (0x0001D590, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F4DDC;

int __cdecl sub_0001D590(int a1)
{
    DAT_003F4DDC = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0001D630 (0x0001D630, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001D630 (0x0001D630, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00446811;

bool __cdecl sub_0001D630(void)
{
    return DAT_00446811;
}

// ============================================================================
// [VERIFIED] sub_0001D640 (0x0001D640, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047E50 (0x00047E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001D640 (0x0001D640, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008E380();
};

extern "C" int DAT_00446878;

void __cdecl sub_0001D640(void)
{
    ((Object*)DAT_00446878)->sub_0008E380();
}

// ============================================================================
// [VERIFIED] sub_0001DC60 (0x0001DC60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001DC60 (0x0001DC60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0044686B;

bool __cdecl sub_0001DC60(void)
{
    return DAT_0044686B;
}

// ============================================================================
// [VERIFIED] sub_0001DC70 (0x0001DC70, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E680 (0x0001E680), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001DC70 (0x0001DC70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0044686A;

void __cdecl sub_0001DC70(void)
{
    DAT_0044686A = true;
}

// ============================================================================
// [VERIFIED] sub_0001DC80 (0x0001DC80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001DC80 (0x0001DC80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0044686A;

bool __cdecl sub_0001DC80(void)
{
    return DAT_0044686A;
}

// ============================================================================
// [VERIFIED] sub_0001DC90 (0x0001DC90, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001DC90 (0x0001DC90, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00446869;

bool __cdecl sub_0001DC90(bool a1)
{
    DAT_00446869 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0001E970 (0x0001E970, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00020B10 (0x00020B10), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001E970 (0x0001E970, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F4F54;
extern "C" void __cdecl sub_00025250(int);

void __cdecl sub_0001E970(void)
{
    sub_00025250(DAT_003F4F54);
    DAT_003F4F54 = 14;
}

// ============================================================================
// [VERIFIED] sub_0001E990 (0x0001E990, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001E990 (0x0001E990, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F4F54;

int __cdecl sub_0001E990(void)
{
    return DAT_003F4F54;
}

// ============================================================================
// [VERIFIED] sub_0001EA60 (0x0001EA60, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001EA60 (0x0001EA60, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003F4F50;

bool __cdecl sub_0001EA60(bool a1)
{
    DAT_003F4F50 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0001EB10 (0x0001EB10, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00020C30 (0x00020C30), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001EB10 (0x0001EB10, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field68
{
    void sub_0008D4C0(int);
};

class Class_0001EB10
{
public:
    int sub_0001EB10(int a1, int a2);
    char m_pad00[0x68];
    Field68 m_Field68; // +0x68
    char m_pad69[0x3];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
    int m_Field74; // +0x74
};

int Class_0001EB10::sub_0001EB10(int a1, int a2)
{
    int t2;

    m_Field68.sub_0008D4C0(a1);
    m_Field6C = *(int*)a2;
    m_Field70 = *(int*)(a2 + 4);
    t2 = *(int*)(a2 + 8);
    m_Field74 = *(int*)(a2 + 8);
    return t2;
}

// ============================================================================
// [VERIFIED] sub_0001EC30 (0x0001EC30, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00020D50 (0x00020D50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001EC30 (0x0001EC30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00015590(int);
extern "C" void __cdecl sub_00012600(int, int);

class Class_0001EC30
{
public:
    int sub_0001EC30();
    char m_pad00[0x3];
    bool m_Field03; // +0x03
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

int Class_0001EC30::sub_0001EC30()
{
    int r_eax;

    r_eax = m_Field48;
    if (r_eax) {
        sub_00012600(r_eax, 0);
    }
    r_eax = m_Field48;
    if (r_eax) {
        r_eax = sub_00015590(r_eax);
        m_Field48 = 0;
    }
    m_Field03 = false;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0001F5E0 (0x0001F5E0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001F5E0 (0x0001F5E0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D7D8[];
extern "C" void __cdecl sub_001F7720(void);

class Class_0001F5E0
{
public:
    Class_0001F5E0* sub_0001F5E0();
    int m_Field00; // +0x00
};

Class_0001F5E0* Class_0001F5E0::sub_0001F5E0()
{
    sub_001F7720();
    m_Field00 = (int)DAT_0037D7D8;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0001F600 (0x0001F600, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001F600 (0x0001F600, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D7D8[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_0001F600
{
public:
    void sub_0001F600();
    int m_Field00; // +0x00
};

void Class_0001F600::sub_0001F600()
{
    m_Field00 = (int)DAT_0037D7D8;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_0001F660 (0x0001F660, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001F660 (0x0001F660, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D814[];
extern "C" void __cdecl sub_001F7910(void);

class Class_0001F660
{
public:
    Class_0001F660* sub_0001F660();
    int m_Field00; // +0x00
};

Class_0001F660* Class_0001F660::sub_0001F660()
{
    sub_001F7910();
    m_Field00 = (int)DAT_0037D814;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0001F680 (0x0001F680, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001F680 (0x0001F680, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D814[];
extern "C" void __cdecl sub_001F7930(void);

class Class_0001F680
{
public:
    void sub_0001F680();
    int m_Field00; // +0x00
};

void Class_0001F680::sub_0001F680()
{
    m_Field00 = (int)DAT_0037D814;
    sub_001F7930();
}

// ============================================================================
// [VERIFIED] sub_0001F7B0 (0x0001F7B0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000219B0 (0x000219B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001F7B0 (0x0001F7B0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001F7DE0();
};

extern "C" char DAT_0037D878[];
extern "C" int __cdecl sub_00025160(int);

class Class_0001F7B0
{
public:
    void sub_0001F7B0();
    void sub_001F7E30();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void Class_0001F7B0::sub_0001F7B0()
{
    int r_eax, t1, t4;

    r_eax = 0;
    t1 = m_Field14;
    m_Field00 = (int)DAT_0037D878;
    if (m_Field14) {
        ((Object*)t1)->sub_001F7DE0();
        r_eax = sub_00025160(t1);
    }
    t4 = m_Field18;
    if (m_Field18) {
        ((Object*)t4)->sub_001F7DE0();
        r_eax = sub_00025160(t4);
    }
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_0001F900 (0x0001F900, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00021B00 (0x00021B00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001F900 (0x0001F900, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D878[];

class Class_0001F900
{
public:
    Class_0001F900* sub_0001F900();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_0001F900* Class_0001F900::sub_0001F900()
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_0037D878;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0001FAB0 (0x0001FAB0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00021C80 (0x00021C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001FAB0 (0x0001FAB0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001F8810(int);
};

extern "C" int DAT_004469F8;

int __cdecl sub_0001FAB0(int a1)
{
    int r_esi;

    if (DAT_004469F8) {
        r_esi = a1;
        if (a1 >= 0) {
            ((Object*)DAT_004469F8)->sub_001F8810(a1);
        }
        return r_esi;
    }
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0001FB50 (0x0001FB50, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00021D20 (0x00021D20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001FB50 (0x0001FB50, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_0001FB50
{
public:
    void sub_0001FB50(int a1);
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

void Class_0001FB50::sub_0001FB50(int a1)
{
    int t2;

    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t2 = m_Field08;
    if (m_Field08) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field08 = a1;
}

// ============================================================================
// [VERIFIED] sub_0001FF20 (0x0001FF20, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000221B0 (0x000221B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0001FF20 (0x0001FF20, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_004469F8;

void __cdecl sub_0001FF20(void)
{
    int t1;

    t1 = DAT_004469F8;
    if (DAT_004469F8) {
        ((Object*)t1)->vfunc_01();
        DAT_004469F8 = 0;
    }
}

// ============================================================================
// [VERIFIED] sub_000202A0 (0x000202A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000202A0 (0x000202A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004469FC;

int __cdecl sub_000202A0(void)
{
    return DAT_004469FC;
}

// ============================================================================
// [VERIFIED] sub_000202B0 (0x000202B0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000202B0 (0x000202B0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004469FC;

int __cdecl sub_000202B0(int a1)
{
    DAT_004469FC = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_000205E0 (0x000205E0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000205E0 (0x000205E0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037DA84[];
extern "C" void __cdecl sub_001FBFB0(void);

class Class_000205E0
{
public:
    Class_000205E0* sub_000205E0();
    int m_Field00; // +0x00
};

Class_000205E0* Class_000205E0::sub_000205E0()
{
    sub_001FBFB0();
    m_Field00 = (int)DAT_0037DA84;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00020600 (0x00020600, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00020600 (0x00020600, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037DA84[];
extern "C" void __cdecl sub_001FBF40(void);

class Class_00020600
{
public:
    void sub_00020600();
    int m_Field00; // +0x00
};

void Class_00020600::sub_00020600()
{
    m_Field00 = (int)DAT_0037DA84;
    sub_001FBF40();
}

// ============================================================================
// [VERIFIED] sub_00021960 (0x00021960, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023BD0 (0x00023BD0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00021960 (0x00021960, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037E2BC[];

class Class_00021960
{
public:
    Class_00021960* sub_00021960(int a1, int a2, int a3, int a4);
    void sub_000269A0(int, int, int);
    int m_Field00; // +0x00
    char m_pad04[0x3C];
    int m_Field40; // +0x40
};

Class_00021960* Class_00021960::sub_00021960(int a1, int a2, int a3, int a4)
{
    sub_000269A0(1, a3, a4);
    m_Field00 = (int)DAT_0037E2BC;
    m_Field40 = a2;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00021D50 (0x00021D50, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023EC0 (0x00023EC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00021D50 (0x00021D50, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00028CF0(int, int);

void __cdecl sub_00021D50(int a1)
{
    sub_00028CF0(a1, 0);
}

// ============================================================================
// [VERIFIED] sub_00021DA0 (0x00021DA0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023F10 (0x00023F10), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00021DA0 (0x00021DA0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F56AC;
extern "C" int DAT_00446A9C;

void __cdecl sub_00021DA0(void)
{
    DAT_00446A9C += 1;
    DAT_003F56AC = 1;
}

// ============================================================================
// [VERIFIED] sub_00021DC0 (0x00021DC0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00021DC0 (0x00021DC0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003F56B0;

bool __cdecl sub_00021DC0(bool a1)
{
    DAT_003F56B0 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00023530 (0x00023530, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00025350 (0x00025350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037E55C[];
extern "C" const void* __cdecl sub_00023090(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00023530(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037E55C;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_00023090), 1);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00023750 (0x00023750, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00025600 (0x00025600), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00023750 (0x00023750, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002062D0(int, int, int);

class Class_00023750
{
public:
    void sub_00023750(int a1);
};

void Class_00023750::sub_00023750(int a1)
{
    sub_002062D0((int)this + 24, a1, 256);
}

// ============================================================================
// [VERIFIED] sub_00024450 (0x00024450, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000267E0 (0x000267E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00024450 (0x00024450, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025140(int, int);

class Class_00024450
{
public:
    int sub_00024450(int a1);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};

int Class_00024450::sub_00024450(int a1)
{
    int r_eax;

    r_eax = m_Field38;
    if (!r_eax) {
        r_eax = a1 * 4;
        r_eax = sub_00025140(r_eax, 9);
        m_Field34 = a1;
        m_Field38 = r_eax;
        m_Field30 = 0;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00024600 (0x00024600, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000269A0 (0x000269A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00024600 (0x00024600, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0020DC00(int, int);

class Class_00024600
{
public:
    void sub_00024600(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

void Class_00024600::sub_00024600(int a1)
{
    m_Field04 = m_Field04 + sub_0020DC00(a1, m_Field00);
}

// ============================================================================
// [VERIFIED] sub_00024620 (0x00024620, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000269C0 (0x000269C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00024620 (0x00024620, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0020DC00(int, int);

class Class_00024620
{
public:
    int sub_00024620(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_00024620::sub_00024620(int a1, int a2)
{
    int t2;

    t2 = sub_0020DC00(a2, m_Field00);
    m_Field04 = m_Field04 + (t2 * a1);
    return t2 * a1;
}

// ============================================================================
// [VERIFIED] sub_000248E0 (0x000248E0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00026D00 (0x00026D00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000248E0 (0x000248E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000248E0
{
public:
    Class_000248E0* sub_000248E0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_000248E0* Class_000248E0::sub_000248E0()
{
    m_Field00 = 8;
    m_Field04 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00024AB0 (0x00024AB0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00026EC0 (0x00026EC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00024AB0 (0x00024AB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_002018B0(void);
extern "C" void __cdecl sub_002018C0(int);

class Class_00024AB0
{
public:
    Class_00024AB0* sub_00024AB0(int a1);
    int m_Field00; // +0x00
};

Class_00024AB0* Class_00024AB0::sub_00024AB0(int a1)
{
    m_Field00 = sub_002018B0();
    sub_002018C0(a1);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00024AD0 (0x00024AD0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00026EE0 (0x00026EE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00024AD0 (0x00024AD0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002018C0(int);

class Class_00024AD0
{
public:
    void sub_00024AD0();
    int m_Field00; // +0x00
};

void Class_00024AD0::sub_00024AD0()
{
    sub_002018C0(m_Field00);
}

// ============================================================================
// [VERIFIED] sub_00024D50 (0x00024D50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00024D50 (0x00024D50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00446FB1;

bool __cdecl sub_00024D50(void)
{
    return DAT_00446FB1;
}

// ============================================================================
// [VERIFIED] sub_00024E70 (0x00024E70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00024E70 (0x00024E70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00446FA8;

bool __cdecl sub_00024E70(void)
{
    return DAT_00446FA8;
}

// ============================================================================
// [VERIFIED] sub_00025140 (0x00025140, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000275B0 (0x000275B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00025140 (0x00025140, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002018F0(int, int);

void __cdecl sub_00025140(int a1, int a2)
{
    sub_002018F0(a2, a1);
}

// ============================================================================
// [VERIFIED] sub_00025250 (0x00025250, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00025250 (0x00025250, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00024EC0(void);

class Class_00025250
{
public:
    void sub_00025250();
};

void Class_00025250::sub_00025250()
{
    sub_00024EC0();
}

// ============================================================================
// [VERIFIED] sub_00025280 (0x00025280, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00027720 (0x00027720), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00025280 (0x00025280, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00025280
{
public:
    Class_00025280* sub_00025280(int a1);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x28];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

Class_00025280* Class_00025280::sub_00025280(int a1)
{
    int r_ebp, r_ecx, r_esi;

    r_ecx = (int)this;
    r_esi = a1;
    r_ecx = (int)(&m_Field04);
    r_esi -= (int)this;
    r_ebp = 44;
    do {
        *(bool*)r_ecx = *(bool*)(r_esi + r_ecx);
        r_ecx += 1;
        r_ebp -= 1;
    } while (r_ebp);
    r_ecx = *(int*)(a1 + 48);
    m_Field30 = r_ecx;
    m_Field34 = *(int*)(a1 + 52);
    r_ecx = *(int*)(a1 + 56);
    m_Field38 = r_ecx;
    m_Field3C = *(int*)(a1 + 60);
    r_ecx = *(int*)(a1 + 64);
    m_Field40 = r_ecx;
    m_Field44 = *(int*)(a1 + 68);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00026980 (0x00026980, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00026980 (0x00026980, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037E9EC[];

class Class_00026980
{
public:
    Class_00026980* sub_00026980(int a1, int a2);
    void sub_00027100(int, int);
    int m_Field00; // +0x00
};

Class_00026980* Class_00026980::sub_00026980(int a1, int a2)
{
    sub_00027100(a1, a2);
    m_Field00 = (int)DAT_0037E9EC;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000269A0 (0x000269A0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00028FA0 (0x00028FA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000269A0 (0x000269A0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037E9EC[];

class Class_000269A0
{
public:
    Class_000269A0* sub_000269A0(int a1, int a2, int a3);
    void sub_00027170(int, int, int);
    int m_Field00; // +0x00
};

Class_000269A0* Class_000269A0::sub_000269A0(int a1, int a2, int a3)
{
    sub_00027170(a1, a2, a3);
    m_Field00 = (int)DAT_0037E9EC;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00026AD0 (0x00026AD0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000290C0 (0x000290C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00026AD0 (0x00026AD0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037E9EC[];
extern "C" void __cdecl sub_00026A90(void);

class Class_00026AD0
{
public:
    void sub_00026AD0();
    void sub_000275D0();
    int m_Field00; // +0x00
};

void Class_00026AD0::sub_00026AD0()
{
    m_Field00 = (int)DAT_0037E9EC;
    sub_00026A90();
    sub_000275D0();
}

// ============================================================================
// [VERIFIED] sub_00026B70 (0x00026B70, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00029160 (0x00029160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00026B70 (0x00026B70, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0008D4A0(int);
};

extern "C" char DAT_0037EA68[];
extern "C" void __cdecl sub_002002C0(void);

class Class_00026B70
{
public:
    Class_00026B70* sub_00026B70(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
};

Class_00026B70* Class_00026B70::sub_00026B70(int a1)
{
    sub_002002C0();
    m_Field00 = (int)DAT_0037EA68;
    m_Field0C.sub_0008D4A0(a1);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00026D60 (0x00026D60, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00029340 (0x00029340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00026D60 (0x00026D60, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EA9C[];

class Class_00026D60
{
public:
    Class_00026D60* sub_00026D60();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00026D60* Class_00026D60::sub_00026D60()
{
    m_Field04 = 0;
    m_Field08 = 0x8800181;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_0037EA9C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000270B0 (0x000270B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00029790 (0x00029790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000270B0 (0x000270B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F64B0;
extern "C" int __cdecl sub_00025250(int);

int __cdecl sub_000270B0(void)
{
    int r_eax;

    r_eax = DAT_003F64B0;
    if (r_eax != -1) {
        r_eax = sub_00025250(r_eax);
        DAT_003F64B0 = -1;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000276B0 (0x000276B0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00029E60 (0x00029E60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000276B0 (0x000276B0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EBF4[];
extern "C" void __cdecl sub_00029D40(int, int);

class Class_000276B0
{
public:
    Class_000276B0* sub_000276B0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

Class_000276B0* Class_000276B0::sub_000276B0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_0037EBF4;
    sub_00029D40((int)(&m_Field20), 8);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000276E0 (0x000276E0, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00029E90 (0x00029E90), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000276E0 (0x000276E0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EBF4[];
extern "C" void __cdecl sub_00029D40(int, int);

class Class_000276E0
{
public:
    Class_000276E0* sub_000276E0(int a1, int a2, int a3);
    void sub_00028500(int, int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

Class_000276E0* Class_000276E0::sub_000276E0(int a1, int a2, int a3)
{
    sub_00028500(a1, a2, a3);
    m_Field00 = (int)DAT_0037EBF4;
    sub_00029D40((int)(&m_Field20), 8);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000277E0 (0x000277E0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00029F90 (0x00029F90), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000277E0 (0x000277E0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EBF4[];
extern "C" void __cdecl sub_00029D60(int, int);

class Class_000277E0
{
public:
    void sub_000277E0();
    void sub_00029C00();
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

void Class_000277E0::sub_000277E0()
{
    m_Field00 = (int)DAT_0037EBF4;
    sub_00029D60((int)this, (int)(&m_Field20));
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_00027F50 (0x00027F50, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00027F50 (0x00027F50, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EDEC[];
extern "C" void __cdecl sub_00026AD0(void);

class Class_00027F50
{
public:
    void sub_00027F50();
    int m_Field00; // +0x00
};

void Class_00027F50::sub_00027F50()
{
    m_Field00 = (int)DAT_0037EDEC;
    sub_00026AD0();
}

// ============================================================================
// [VERIFIED] sub_00027F60 (0x00027F60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00027F60 (0x00027F60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004493DC;

int __cdecl sub_00027F60(void)
{
    return DAT_004493DC;
}

// ============================================================================
// [VERIFIED] sub_00027FC0 (0x00027FC0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00027FC0 (0x00027FC0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EE74[];
extern "C" void __cdecl sub_00026AD0(void);

class Class_00027FC0
{
public:
    void sub_00027FC0();
    int m_Field00; // +0x00
};

void Class_00027FC0::sub_00027FC0()
{
    m_Field00 = (int)DAT_0037EE74;
    sub_00026AD0();
}

// ============================================================================
// [VERIFIED] sub_00027FE0 (0x00027FE0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00027FE0 (0x00027FE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EEFC[];

class Class_00027FE0
{
public:
    Class_00027FE0* sub_00027FE0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
};

Class_00027FE0* Class_00027FE0::sub_00027FE0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_0037EEFC;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00028010 (0x00028010, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00028010 (0x00028010, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EEFC[];
extern "C" void __cdecl sub_00029C00(void);

class Class_00028010
{
public:
    void sub_00028010();
    int m_Field00; // +0x00
};

void Class_00028010::sub_00028010()
{
    m_Field00 = (int)DAT_0037EEFC;
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_000281A0 (0x000281A0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002AC50 (0x0002AC50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000281A0 (0x000281A0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044950C;

class Class_000281A0
{
public:
    int sub_000281A0();
    char m_pad00[0x1C];
    unsigned short m_Field1C; // +0x1C
};

int Class_000281A0::sub_000281A0()
{
    unsigned short t1;

    t1 = m_Field1C;
    if (m_Field1C != 65535) {
        return *(int*)(DAT_0044950C + (((unsigned short)t1) * 8));
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00028280 (0x00028280, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F47DC[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_00028280(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_003F47DC, 0);
}

// ============================================================================
// [VERIFIED] sub_00028330 (0x00028330, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002AE20 (0x0002AE20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00028330 (0x00028330, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual int vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(int);
};

extern "C" int DAT_004493F4;

int __stdcall sub_00028330(int a1, int a2, int a3)
{
    int r_esi;

    r_esi = ((Object*)DAT_004493F4)->vfunc_16();
    if (r_esi) {
        *(int*)(r_esi + 4) = a2;
        *(int*)(r_esi + 8) = a3;
        *(unsigned char*)(r_esi + 2) = 8;
        *(int*)(r_esi + 12) = 0;
        *(bool*)(r_esi + 3) = false;
        *(unsigned short*)r_esi = 65535;
        *(unsigned short*)a1 = (unsigned short)((Object*)DAT_004493F4)->vfunc_18(r_esi);
    }
    return r_esi;
}

// ============================================================================
// [VERIFIED] sub_00028A80 (0x00028A80, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002B540 (0x0002B540), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00028A80 (0x00028A80, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006C180(int, int);

class Class_00028A80
{
public:
    void sub_00028A80(int a1, int a2);
    void sub_00028880(int, int);
};

void Class_00028A80::sub_00028A80(int a1, int a2)
{
    sub_00028880(sub_0006C180(a1, 0), a2);
}

// ============================================================================
// [VERIFIED] sub_00028F60 (0x00028F60, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002B9E0 (0x0002B9E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00028F60 (0x00028F60, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008CD80(int);
};

extern "C" int DAT_004493F0;

void __cdecl sub_00028F60(int a1)
{
    ((Object*)DAT_004493F0)->sub_0008CD80(a1);
}

// ============================================================================
// [VERIFIED] sub_00029AC0 (0x00029AC0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002C5E0 (0x0002C5E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00029AC0 (0x00029AC0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006C180(int, int);

class Class_00029AC0
{
public:
    bool sub_00029AC0(int a1, int a2, int a3);
    void sub_00029730(int, int, int);
};

bool Class_00029AC0::sub_00029AC0(int a1, int a2, int a3)
{
    sub_00029730(sub_0006C180(a1, 0), a2, a3);
    return true;
}

// ============================================================================
// [VERIFIED] sub_00029AF0 (0x00029AF0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002C5E0 (0x0002C5E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00029AF0 (0x00029AF0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006C180(int, int);

class Class_00029AF0
{
public:
    bool sub_00029AF0(int a1, int a2, int a3);
    void sub_00029840(int, int, int);
};

bool Class_00029AF0::sub_00029AF0(int a1, int a2, int a3)
{
    sub_00029840(sub_0006C180(a1, 0), a2, a3);
    return true;
}

// ============================================================================
// [VERIFIED] sub_00029B20 (0x00029B20, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002C5E0 (0x0002C5E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00029B20 (0x00029B20, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006C180(int, int);

class Class_00029B20
{
public:
    bool sub_00029B20(int a1, int a2, int a3);
    void sub_00029960(int, int, int);
};

bool Class_00029B20::sub_00029B20(int a1, int a2, int a3)
{
    sub_00029960(sub_0006C180(a1, 0), a2, a3);
    return true;
}

// ============================================================================
// [VERIFIED] sub_00029FB0 (0x00029FB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00029FB0 (0x00029FB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00449518;

int __cdecl sub_00029FB0(void)
{
    return DAT_00449518;
}

// ============================================================================
// [VERIFIED] sub_0002AC30 (0x0002AC30, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136830 (0x00136830), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F150[];
extern "C" const void* __cdecl sub_0002AAC0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 1 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0002AC30(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037F150;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAC0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0002AF00 (0x0002AF00, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002D910 (0x0002D910), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F190[];
extern "C" const void* __cdecl sub_0002AD80(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 0 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0002AF00(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_0037F190;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AD80), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0002AF80 (0x0002AF80, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F198[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0002AF80(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037F198;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0002B000 (0x0002B000, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F1A0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0002B000(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037F1A0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0002B860 (0x0002B860, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E2C0 (0x0002E2C0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F250[];
extern "C" const void* __cdecl sub_0002AAC0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0002B860(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0037F250;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAC0), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0002B8D0 (0x0002B8D0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E330 (0x0002E330), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F258[];
extern "C" const void* __cdecl sub_0002AAB0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 8 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0002B8D0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(8);
        *(void**)object = DAT_0037F258;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAB0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0002BBD0 (0x0002BBD0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002BBD0 (0x0002BBD0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037F31C[];
extern "C" void __cdecl sub_00029C00(void);

class Class_0002BBD0
{
public:
    void sub_0002BBD0();
    int m_Field00; // +0x00
};

void Class_0002BBD0::sub_0002BBD0()
{
    m_Field00 = (int)DAT_0037F31C;
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_0002BE70 (0x0002BE70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002BE70 (0x0002BE70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00449AE0;

int __cdecl sub_0002BE70(void)
{
    return DAT_00449AE0;
}

// ============================================================================
// [VERIFIED] sub_0002BF60 (0x0002BF60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002BF60 (0x0002BF60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004498C3;

bool __cdecl sub_0002BF60(void)
{
    return DAT_004498C3;
}

// ============================================================================
// [VERIFIED] sub_0002BF70 (0x0002BF70, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002BF70 (0x0002BF70, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004498C3;

bool __cdecl sub_0002BF70(bool a1)
{
    DAT_004498C3 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0002BF90 (0x0002BF90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002BF90 (0x0002BF90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004498C2;

bool __cdecl sub_0002BF90(void)
{
    return DAT_004498C2;
}

// ============================================================================
// [VERIFIED] sub_0002BFA0 (0x0002BFA0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002BFA0 (0x0002BFA0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004498C2;

bool __cdecl sub_0002BFA0(bool a1)
{
    DAT_004498C2 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0002C020 (0x0002C020, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002C020 (0x0002C020, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004498BC;

bool __cdecl sub_0002C020(void)
{
    return DAT_004498BC;
}

// ============================================================================
// [VERIFIED] sub_0002C050 (0x0002C050, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0002C050 (0x0002C050, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004498B8;

int __cdecl sub_0002C050(void)
{
    return DAT_004498B8;
}

// ============================================================================
// [VERIFIED] sub_00030C30 (0x00030C30, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00034430 (0x00034430), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00030C30 (0x00030C30, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000309F0();
};

class Class_00030C30
{
public:
    void sub_00030C30();
};

void Class_00030C30::sub_00030C30()
{
    ((Object*)(int)this + 4)->sub_000309F0();
}

// ============================================================================
// [VERIFIED] sub_00036CF0 (0x00036CF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00036CF0 (0x00036CF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00449EE4;

int __cdecl sub_00036CF0(void)
{
    return DAT_00449EE4;
}

// ============================================================================
// [VERIFIED] sub_00040B10 (0x00040B10, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047D00 (0x00047D00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040B10 (0x00040B10, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037F730[];

class Class_00040B10
{
public:
    Class_00040B10* sub_00040B10();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_00040B10* Class_00040B10::sub_00040B10()
{
    m_Field00 = (int)DAT_0037F730;
    m_Field04 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00040CB0 (0x00040CB0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047E50 (0x00047E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040CB0 (0x00040CB0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000451B0();
};

extern "C" int DAT_0044A368;

void __cdecl sub_00040CB0(void)
{
    ((Object*)DAT_0044A368)->sub_000451B0();
}

// ============================================================================
// [VERIFIED] sub_00040CC0 (0x00040CC0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047E50 (0x00047E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040CC0 (0x00040CC0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00045230();
};

extern "C" int DAT_0044A368;

void __cdecl sub_00040CC0(void)
{
    ((Object*)DAT_0044A368)->sub_00045230();
}

// ============================================================================
// [VERIFIED] sub_00040CD0 (0x00040CD0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040CD0 (0x00040CD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044A370;

int __cdecl sub_00040CD0(void)
{
    return DAT_0044A370;
}

// ============================================================================
// [VERIFIED] sub_00040CE0 (0x00040CE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040CE0 (0x00040CE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044A374;

int __cdecl sub_00040CE0(void)
{
    return DAT_0044A374;
}

// ============================================================================
// [VERIFIED] sub_00040E30 (0x00040E30, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002B9E0 (0x0002B9E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040E30 (0x00040E30, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00044D80(int);
};

extern "C" int DAT_0044A368;

void __cdecl sub_00040E30(int a1)
{
    ((Object*)DAT_0044A368)->sub_00044D80(a1);
}

// ============================================================================
// [VERIFIED] sub_00040E50 (0x00040E50, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047E50 (0x00047E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040E50 (0x00040E50, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00231ED0();
};

extern "C" int DAT_0044A368;

void __cdecl sub_00040E50(void)
{
    ((Object*)DAT_0044A368)->sub_00231ED0();
}

// ============================================================================
// [VERIFIED] sub_00040E60 (0x00040E60, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002B9E0 (0x0002B9E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040E60 (0x00040E60, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00044DB0(int);
};

extern "C" int DAT_0044A368;

void __cdecl sub_00040E60(int a1)
{
    ((Object*)DAT_0044A368)->sub_00044DB0(a1);
}

// ============================================================================
// [VERIFIED] sub_00040EE0 (0x00040EE0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00048100 (0x00048100), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040EE0 (0x00040EE0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00039F70(int);
};

extern "C" int DAT_0044A368;

void __cdecl sub_00040EE0(int a1)
{
    ((Object*)*(int*)(DAT_0044A368 + 16))->sub_00039F70(a1);
}

// ============================================================================
// [VERIFIED] sub_00040F00 (0x00040F00, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00048100 (0x00048100), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00040F00 (0x00040F00, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00039F80(int);
};

extern "C" int DAT_0044A368;

void __cdecl sub_00040F00(int a1)
{
    ((Object*)*(int*)(DAT_0044A368 + 16))->sub_00039F80(a1);
}

// ============================================================================
// [VERIFIED] sub_00041190 (0x00041190, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00041190 (0x00041190, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0044A248;

bool __cdecl sub_00041190(void)
{
    return DAT_0044A248;
}

// ============================================================================
// [VERIFIED] sub_00041250 (0x00041250, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00048100 (0x00048100), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00041250 (0x00041250, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00039E80(int);
};

extern "C" int DAT_0044A368;

void __cdecl sub_00041250(int a1)
{
    ((Object*)*(int*)(DAT_0044A368 + 16))->sub_00039E80(a1);
}

// ============================================================================
// [VERIFIED] sub_00041300 (0x00041300, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000485A0 (0x000485A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00041300 (0x00041300, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0004EA10(int);
};

int __cdecl sub_00041300(int a1, int a2)
{
    int r_eax, t1;

    r_eax = a1;
    if (a1) {
        t1 = *(int*)(r_eax + 4);
        if (!*(int*)(r_eax + 4)) goto L_21;
        if (*(int*)(t1 + 100) != *(int*)(r_eax + 8)) goto L_21;
        r_eax = a2;
        r_eax = ((Object*)t1)->sub_0004EA10(a2);
    }
L_21:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00041330 (0x00041330, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000485A0 (0x000485A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00041330 (0x00041330, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0004EC10(int);
};

int __cdecl sub_00041330(int a1, int a2)
{
    int r_eax, t1;

    r_eax = a1;
    if (a1) {
        t1 = *(int*)(r_eax + 4);
        if (!*(int*)(r_eax + 4)) goto L_21;
        if (*(int*)(t1 + 100) != *(int*)(r_eax + 8)) goto L_21;
        r_eax = a2;
        r_eax = ((Object*)t1)->sub_0004EC10(a2);
    }
L_21:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00041360 (0x00041360, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000485A0 (0x000485A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00041360 (0x00041360, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0004EA40(int);
};

int __cdecl sub_00041360(int a1, int a2)
{
    int r_eax, t1;

    r_eax = a1;
    if (a1) {
        t1 = *(int*)(r_eax + 4);
        if (!*(int*)(r_eax + 4)) goto L_21;
        if (*(int*)(t1 + 100) != *(int*)(r_eax + 8)) goto L_21;
        r_eax = a2;
        r_eax = ((Object*)t1)->sub_0004EA40(a2);
    }
L_21:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00042640 (0x00042640, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00049CD0 (0x00049CD0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00042640 (0x00042640, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0037F764[];
extern "C" int DAT_0044A394;
extern "C" void __cdecl sub_00040B10(void);

class Class_00042640
{
public:
    Class_00042640* sub_00042640(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00042640* Class_00042640::sub_00042640(int a1, int a2)
{
    int t2, t4;

    sub_00040B10();
    m_Field00 = (int)DAT_0037F764;
    m_Field10 = 0;
    t2 = DAT_0044A394 + 1;
    DAT_0044A394 = DAT_0044A394 + 1;
    m_Field0C = t2;
    m_Field04 = a1;
    m_Field08 = *(int*)(a1 + 100);
    if (a2) {
        ((Object*)a2)->vfunc_00();
    }
    t4 = m_Field10;
    if (m_Field10) {
        ((Object*)t4)->vfunc_01();
    }
    m_Field10 = a2;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000426F0 (0x000426F0, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00049CD0 (0x00049CD0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000426F0 (0x000426F0, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0037F76C[];
extern "C" int DAT_0044A398;
extern "C" void __cdecl sub_00040B10(void);

class Class_000426F0
{
public:
    Class_000426F0* sub_000426F0(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_000426F0* Class_000426F0::sub_000426F0(int a1, int a2)
{
    int t2, t4;

    sub_00040B10();
    m_Field00 = (int)DAT_0037F76C;
    m_Field10 = 0;
    t2 = DAT_0044A398 + 1;
    DAT_0044A398 = DAT_0044A398 + 1;
    m_Field0C = t2;
    m_Field04 = a1;
    m_Field08 = *(int*)(a1 + 100);
    if (a2) {
        ((Object*)a2)->vfunc_00();
    }
    t4 = m_Field10;
    if (m_Field10) {
        ((Object*)t4)->vfunc_01();
    }
    m_Field10 = a2;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00043680 (0x00043680, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00015AE0 (0x00015AE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_0037F7CC[];
extern "C" int __cdecl sub_002014E0(const char* name, int a2);

// A small object that is nothing but its vtable, made on the stack and handed to the target.
struct Visitor
{
    void* vtable;
};

struct Target
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(Visitor* visitor, int key);
};

void __cdecl sub_00043680(Target* target, const char* name)
{
    int key = sub_002014E0(name, 0);
    Visitor visitor;
    visitor.vtable = DAT_0037F7CC;
    target->vfunc_04(&visitor, key);
}

// ============================================================================
// [VERIFIED] sub_000436B0 (0x000436B0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00015AE0 (0x00015AE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_0037F7DC[];
extern "C" int __cdecl sub_002014E0(const char* name, int a2);

// A small object that is nothing but its vtable, made on the stack and handed to the target.
struct Visitor
{
    void* vtable;
};

struct Target
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(Visitor* visitor, int key);
};

void __cdecl sub_000436B0(Target* target, const char* name)
{
    int key = sub_002014E0(name, 0);
    Visitor visitor;
    visitor.vtable = DAT_0037F7DC;
    target->vfunc_04(&visitor, key);
}

// ============================================================================
// [VERIFIED] sub_000436E0 (0x000436E0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00015AE0 (0x00015AE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_0037F7E4[];
extern "C" int __cdecl sub_002014E0(const char* name, int a2);

// A small object that is nothing but its vtable, made on the stack and handed to the target.
struct Visitor
{
    void* vtable;
};

struct Target
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(Visitor* visitor, int key);
};

void __cdecl sub_000436E0(Target* target, const char* name)
{
    int key = sub_002014E0(name, 0);
    Visitor visitor;
    visitor.vtable = DAT_0037F7E4;
    target->vfunc_04(&visitor, key);
}

// ============================================================================
// [VERIFIED] sub_00045F10 (0x00045F10, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0004D5C0 (0x0004D5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00045F10 (0x00045F10, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0003EF00();
};

class Class_00045F10
{
public:
    void sub_00045F10();
    char m_pad00[0x20];
    Field20* m_Field20; // +0x20
};

void Class_00045F10::sub_00045F10()
{
    m_Field20->sub_0003EF00();
}

// ============================================================================
// [VERIFIED] sub_00048FB0 (0x00048FB0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00050CC0 (0x00050CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00048FB0 (0x00048FB0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00229700();
};

extern "C" int __cdecl sub_0004EED0(void);

class Class_00048FB0
{
public:
    void sub_00048FB0();
    int sub_0004EEB0(int);
    int sub_0004EED0();
};

void Class_00048FB0::sub_00048FB0()
{
    int r_esi;

    r_esi = 0;
    if (::sub_0004EED0() > 0) {
        do {
            ((Object*)sub_0004EEB0(r_esi))->sub_00229700();
            r_esi += 1;
        } while (r_esi < sub_0004EED0());
    }
}

// ============================================================================
// [VERIFIED] sub_00049030 (0x00049030, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00050CC0 (0x00050CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00049030 (0x00049030, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00229720();
};

extern "C" int __cdecl sub_0004EED0(void);

class Class_00049030
{
public:
    void sub_00049030();
    int sub_0004EEB0(int);
    int sub_0004EED0();
};

void Class_00049030::sub_00049030()
{
    int r_esi;

    r_esi = 0;
    if (::sub_0004EED0() > 0) {
        do {
            ((Object*)sub_0004EEB0(r_esi))->sub_00229720();
            r_esi += 1;
        } while (r_esi < sub_0004EED0());
    }
}

// ============================================================================
// [VERIFIED] sub_00049A70 (0x00049A70, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00049A70 (0x00049A70, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F8258;

int __cdecl sub_00049A70(int a1)
{
    DAT_003F8258 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00051CD0 (0x00051CD0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00051CD0 (0x00051CD0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044A5F0;

int __cdecl sub_00051CD0(int a1)
{
    DAT_0044A5F0 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00056270 (0x00056270, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00056270 (0x00056270, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044A984;

int __cdecl sub_00056270(void)
{
    return DAT_0044A984;
}

// ============================================================================
// [VERIFIED] sub_00056410 (0x00056410, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00056410 (0x00056410, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044A988;

int __cdecl sub_00056410(void)
{
    return DAT_0044A988;
}

// ============================================================================
// [VERIFIED] sub_00057150 (0x00057150, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00057150 (0x00057150, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044ADD0;

int __cdecl sub_00057150(void)
{
    return DAT_0044ADD0;
}

// ============================================================================
// [VERIFIED] sub_00058B10 (0x00058B10, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00058B10 (0x00058B10, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00056F40(void);

class Class_00058B10
{
public:
    void sub_00058B10();
};

void Class_00058B10::sub_00058B10()
{
    sub_00056F40();
}

// ============================================================================
// [VERIFIED] sub_00058B40 (0x00058B40, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00058B40 (0x00058B40, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00056DA0(void);

class Class_00058B40
{
public:
    void sub_00058B40();
};

void Class_00058B40::sub_00058B40()
{
    sub_00056DA0();
}

// ============================================================================
// [VERIFIED] sub_00058B90 (0x00058B90, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00058B90 (0x00058B90, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00056DF0(void);

class Class_00058B90
{
public:
    void sub_00058B90();
};

void Class_00058B90::sub_00058B90()
{
    sub_00056DF0();
}

// ============================================================================
// [VERIFIED] sub_00058BC0 (0x00058BC0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00058BC0 (0x00058BC0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000587B0(void);

class Class_00058BC0
{
public:
    void sub_00058BC0();
};

void Class_00058BC0::sub_00058BC0()
{
    sub_000587B0();
}

// ============================================================================
// [VERIFIED] sub_00058BD0 (0x00058BD0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00058BD0 (0x00058BD0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00057F00(void);

class Class_00058BD0
{
public:
    void sub_00058BD0();
};

void Class_00058BD0::sub_00058BD0()
{
    sub_00057F00();
}

// ============================================================================
// [VERIFIED] sub_00058BE0 (0x00058BE0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00058BE0 (0x00058BE0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00057F70(void);

class Class_00058BE0
{
public:
    void sub_00058BE0();
};

void Class_00058BE0::sub_00058BE0()
{
    sub_00057F70();
}

// ============================================================================
// [VERIFIED] sub_00058BF0 (0x00058BF0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00058BF0 (0x00058BF0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00058020(void);

class Class_00058BF0
{
public:
    void sub_00058BF0();
};

void Class_00058BF0::sub_00058BF0()
{
    sub_00058020();
}

// ============================================================================
// [VERIFIED] sub_000590C0 (0x000590C0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000590C0 (0x000590C0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0044AE38;

bool __cdecl sub_000590C0(bool a1)
{
    DAT_0044AE38 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0005A620 (0x0005A620, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005A620 (0x0005A620, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044AE7C[];

void* __cdecl sub_0005A620(void)
{
    return DAT_0044AE7C;
}

// ============================================================================
// [VERIFIED] sub_0005B420 (0x0005B420, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005B420 (0x0005B420, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_00381080[];
extern "C" char DAT_003811B8[];
extern "C" int DAT_0044AED4;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005B420
{
public:
    Class_0005B420* sub_0005B420(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005B420* Class_0005B420::sub_0005B420(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003811B8;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_00381080;
        DAT_0044AED4 = t2;
        return this;
    }
    DAT_0044AED4 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005B540 (0x0005B540, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005B540 (0x0005B540, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_00381098[];
extern "C" char DAT_0038120C[];
extern "C" int DAT_0044AED8;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005B540
{
public:
    Class_0005B540* sub_0005B540(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005B540* Class_0005B540::sub_0005B540(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_0038120C;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_00381098;
        DAT_0044AED8 = t2;
        return this;
    }
    DAT_0044AED8 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005B6C0 (0x0005B6C0, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005B6C0 (0x0005B6C0, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003810B0[];
extern "C" char DAT_00381264[];
extern "C" int DAT_0044AEDC;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005B6C0
{
public:
    Class_0005B6C0* sub_0005B6C0(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005B6C0* Class_0005B6C0::sub_0005B6C0(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00381264;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003810B0;
        DAT_0044AEDC = t2;
        return this;
    }
    DAT_0044AEDC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005B800 (0x0005B800, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005B800 (0x0005B800, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003810C8[];
extern "C" char DAT_003812BC[];
extern "C" int DAT_0044AEE0;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005B800
{
public:
    Class_0005B800* sub_0005B800(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005B800* Class_0005B800::sub_0005B800(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003812BC;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003810C8;
        DAT_0044AEE0 = t2;
        return this;
    }
    DAT_0044AEE0 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005B940 (0x0005B940, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005B940 (0x0005B940, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003810E0[];
extern "C" char DAT_00381314[];
extern "C" int DAT_0044AEE4;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005B940
{
public:
    Class_0005B940* sub_0005B940(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005B940* Class_0005B940::sub_0005B940(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00381314;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003810E0;
        DAT_0044AEE4 = t2;
        return this;
    }
    DAT_0044AEE4 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005B9D0 (0x0005B9D0, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005B9D0 (0x0005B9D0, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003810F8[];
extern "C" char DAT_00381328[];
extern "C" int DAT_0044AEE8;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005B9D0
{
public:
    Class_0005B9D0* sub_0005B9D0(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005B9D0* Class_0005B9D0::sub_0005B9D0(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00381328;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003810F8;
        DAT_0044AEE8 = t2;
        return this;
    }
    DAT_0044AEE8 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005BB10 (0x0005BB10, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005BB10 (0x0005BB10, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_00381110[];
extern "C" char DAT_0038137C[];
extern "C" int DAT_0044AEEC;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005BB10
{
public:
    Class_0005BB10* sub_0005BB10(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005BB10* Class_0005BB10::sub_0005BB10(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_0038137C;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_00381110;
        DAT_0044AEEC = t2;
        return this;
    }
    DAT_0044AEEC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005BC60 (0x0005BC60, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005BC60 (0x0005BC60, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_00381128[];
extern "C" char DAT_003813D4[];
extern "C" int DAT_0044AEF0;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005BC60
{
public:
    Class_0005BC60* sub_0005BC60(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005BC60* Class_0005BC60::sub_0005BC60(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003813D4;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_00381128;
        DAT_0044AEF0 = t2;
        return this;
    }
    DAT_0044AEF0 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005BDB0 (0x0005BDB0, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005BDB0 (0x0005BDB0, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_00381140[];
extern "C" char DAT_0038142C[];
extern "C" int DAT_0044AEF4;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005BDB0
{
public:
    Class_0005BDB0* sub_0005BDB0(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005BDB0* Class_0005BDB0::sub_0005BDB0(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_0038142C;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_00381140;
        DAT_0044AEF4 = t2;
        return this;
    }
    DAT_0044AEF4 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005BE40 (0x0005BE40, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005BE40 (0x0005BE40, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_00381158[];
extern "C" char DAT_00381440[];
extern "C" int DAT_0044AEF8;
extern "C" int __cdecl sub_00291D70(int);

class Class_0005BE40
{
public:
    Class_0005BE40* sub_0005BE40(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_0005BE40* Class_0005BE40::sub_0005BE40(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00381440;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_00381158;
        DAT_0044AEF8 = t2;
        return this;
    }
    DAT_0044AEF8 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0005BED0 (0x0005BED0, 83 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065E70 (0x00065E70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005BED0 (0x0005BED0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F91F0[];
extern "C" char DAT_003F94A4[];
extern "C" int __cdecl sub_00292EA0(int);
extern "C" int __cdecl sub_002932C0(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

int __cdecl sub_0005BED0(int a1)
{
    int r_eax, r_esi;

    r_eax = sub_002932C0(a1);
    r_esi = r_eax;
    if (!r_esi) goto L_4E;
L_15:
    r_eax = *(int*)(r_esi + 24);
    if (r_eax == *(int*)a1) {
        if (*(int*)(r_esi + 28) != *(int*)(a1 + 4)) goto L_4E;
        r_eax = sub_002C92F8(r_esi, 0, (int)DAT_003F91F0, (int)DAT_003F94A4, 0);
        if (r_eax) goto L_50;
        r_eax = sub_00292EA0(r_esi);
        r_esi = r_eax;
        if (r_esi) goto L_15;
    }
L_4E:
    r_eax = 0;
L_50:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0005BF30 (0x0005BF30, 83 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065E70 (0x00065E70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005BF30 (0x0005BF30, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F91F0[];
extern "C" char DAT_003F94C4[];
extern "C" int __cdecl sub_00292EA0(int);
extern "C" int __cdecl sub_002932C0(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

int __cdecl sub_0005BF30(int a1)
{
    int r_eax, r_esi;

    r_eax = sub_002932C0(a1);
    r_esi = r_eax;
    if (!r_esi) goto L_4E;
L_15:
    r_eax = *(int*)(r_esi + 24);
    if (r_eax == *(int*)a1) {
        if (*(int*)(r_esi + 28) != *(int*)(a1 + 4)) goto L_4E;
        r_eax = sub_002C92F8(r_esi, 0, (int)DAT_003F91F0, (int)DAT_003F94C4, 0);
        if (r_eax) goto L_50;
        r_eax = sub_00292EA0(r_esi);
        r_esi = r_eax;
        if (r_esi) goto L_15;
    }
L_4E:
    r_eax = 0;
L_50:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0005D070 (0x0005D070, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005D070 (0x0005D070, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00065640(void);

class Class_0005D070
{
public:
    void sub_0005D070();
};

void Class_0005D070::sub_0005D070()
{
    sub_00065640();
}

// ============================================================================
// [VERIFIED] sub_0005EDC0 (0x0005EDC0, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000690C0 (0x000690C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0005EDC0 (0x0005EDC0, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0005EC40(int);
extern "C" void __cdecl sub_0008EAE0(int, int);

class Class_0005EDC0
{
public:
    int sub_0005EDC0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x2460];
    int m_Field2464; // +0x2464
    int m_Field2468; // +0x2468
    int m_Field246C; // +0x246C
};

int Class_0005EDC0::sub_0005EDC0(int a1)
{
    int r_eax, r_edx;
    bool t3;

    r_eax = m_Field2464;
    r_eax += 32;
    sub_0005EC40(r_eax);
    r_edx = m_Field00;
    r_edx += m_Field2464;
    sub_0008EAE0(r_edx, a1);
    r_eax = m_Field00;
    r_eax += m_Field2464;
    r_edx = r_eax + 1;
    do {
        t3 = *(bool*)r_eax;
        r_eax += 1;
    } while (t3);
    r_eax -= r_edx;
    m_Field2468 = r_eax;
    r_eax = m_Field246C;
    *(bool*)(r_eax + (int)this + 8280) = t3;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00064980 (0x00064980, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006EC60 (0x0006EC60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00064980 (0x00064980, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00069F60(int);
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381A8C[];
extern "C" int DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

int __cdecl sub_00064980(void)
{
    int r_esi;

    r_esi = ((Object*)DAT_0044E08C)->sub_00069F60(16);
    if (r_esi) {
        *(int*)r_esi = (int)DAT_003819DC;
        *(int*)(r_esi + 4) = 0;
        *(int*)(r_esi + 8) = sub_0006B230();
        *(int*)(r_esi + 12) = sub_0006B240();
        *(int*)r_esi = (int)DAT_00381A8C;
    }
    return r_esi;
}

// ============================================================================
// [VERIFIED] sub_000649C0 (0x000649C0, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006EC60 (0x0006EC60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000649C0 (0x000649C0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00069F60(int);
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381A9C[];
extern "C" int DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

int __cdecl sub_000649C0(void)
{
    int r_esi;

    r_esi = ((Object*)DAT_0044E08C)->sub_00069F60(16);
    if (r_esi) {
        *(int*)r_esi = (int)DAT_003819DC;
        *(int*)(r_esi + 4) = 0;
        *(int*)(r_esi + 8) = sub_0006B230();
        *(int*)(r_esi + 12) = sub_0006B240();
        *(int*)r_esi = (int)DAT_00381A9C;
    }
    return r_esi;
}

// ============================================================================
// [VERIFIED] sub_00064A00 (0x00064A00, 77 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006ECE0 (0x0006ECE0), which was matched first;
// its addresses and names were swapped for this function's.
struct Heap
{
    void* sub_00069F60(unsigned int size);
};

struct Made
{
    void* vtable;
    int m_04;
    int m_08;
    int m_0C;
    int m_value; // +0x10
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381AAC[];
extern "C" Heap* DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

// Allocates a 20-byte object from the heap and builds it (base part first, then its own vtable).
// The value is stored after the null check, so a failed allocation writes to address 0x10.
Made* __cdecl sub_00064A00(int value)
{
    Made* made = (Made*)DAT_0044E08C->sub_00069F60(20);
    if (made) {
        made->vtable = DAT_003819DC;
        made->m_04 = 0;
        made->m_08 = sub_0006B230();
        made->m_0C = sub_0006B240();
        made->vtable = DAT_00381AAC;
    }
    made->m_value = value;
    return made;
}

// ============================================================================
// [VERIFIED] sub_00064B20 (0x00064B20, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006EE00 (0x0006EE00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00064B20 (0x00064B20, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00069F60(int);
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381ADC[];
extern "C" int DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

int __cdecl sub_00064B20(int a1, int a2, int a3)
{
    int r_esi;

    r_esi = ((Object*)DAT_0044E08C)->sub_00069F60(28);
    if (r_esi) {
        *(int*)r_esi = (int)DAT_003819DC;
        *(int*)(r_esi + 4) = 0;
        *(int*)(r_esi + 8) = sub_0006B230();
        *(int*)(r_esi + 12) = sub_0006B240();
        *(int*)r_esi = (int)DAT_00381ADC;
    }
    *(int*)(r_esi + 16) = a1;
    *(int*)(r_esi + 20) = a2;
    *(int*)(r_esi + 24) = a3;
    return r_esi;
}

// ============================================================================
// [VERIFIED] sub_00064F50 (0x00064F50, 77 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006ECE0 (0x0006ECE0), which was matched first;
// its addresses and names were swapped for this function's.
struct Heap
{
    void* sub_00069F60(unsigned int size);
};

struct Made
{
    void* vtable;
    int m_04;
    int m_08;
    int m_0C;
    int m_value; // +0x10
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381C1C[];
extern "C" Heap* DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

// Allocates a 20-byte object from the heap and builds it (base part first, then its own vtable).
// The value is stored after the null check, so a failed allocation writes to address 0x10.
Made* __cdecl sub_00064F50(int value)
{
    Made* made = (Made*)DAT_0044E08C->sub_00069F60(20);
    if (made) {
        made->vtable = DAT_003819DC;
        made->m_04 = 0;
        made->m_08 = sub_0006B230();
        made->m_0C = sub_0006B240();
        made->vtable = DAT_00381C1C;
    }
    made->m_value = value;
    return made;
}

// ============================================================================
// [VERIFIED] sub_00064FA0 (0x00064FA0, 77 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006ECE0 (0x0006ECE0), which was matched first;
// its addresses and names were swapped for this function's.
struct Heap
{
    void* sub_00069F60(unsigned int size);
};

struct Made
{
    void* vtable;
    int m_04;
    int m_08;
    int m_0C;
    int m_value; // +0x10
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381C38[];
extern "C" Heap* DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

// Allocates a 20-byte object from the heap and builds it (base part first, then its own vtable).
// The value is stored after the null check, so a failed allocation writes to address 0x10.
Made* __cdecl sub_00064FA0(int value)
{
    Made* made = (Made*)DAT_0044E08C->sub_00069F60(20);
    if (made) {
        made->vtable = DAT_003819DC;
        made->m_04 = 0;
        made->m_08 = sub_0006B230();
        made->m_0C = sub_0006B240();
        made->vtable = DAT_00381C38;
    }
    made->m_value = value;
    return made;
}

// ============================================================================
// [VERIFIED] sub_00065080 (0x00065080, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006EE00 (0x0006EE00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00065080 (0x00065080, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00069F60(int);
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381C70[];
extern "C" int DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

int __cdecl sub_00065080(int a1, int a2, int a3)
{
    int r_esi;

    r_esi = ((Object*)DAT_0044E08C)->sub_00069F60(28);
    if (r_esi) {
        *(int*)r_esi = (int)DAT_003819DC;
        *(int*)(r_esi + 4) = 0;
        *(int*)(r_esi + 8) = sub_0006B230();
        *(int*)(r_esi + 12) = sub_0006B240();
        *(int*)r_esi = (int)DAT_00381C70;
    }
    *(int*)(r_esi + 16) = a1;
    *(int*)(r_esi + 20) = a2;
    *(int*)(r_esi + 24) = a3;
    return r_esi;
}

// ============================================================================
// [VERIFIED] sub_00065210 (0x00065210, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006EE00 (0x0006EE00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00065210 (0x00065210, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00069F60(int);
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381CFC[];
extern "C" int DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

int __cdecl sub_00065210(int a1, int a2, int a3)
{
    int r_esi;

    r_esi = ((Object*)DAT_0044E08C)->sub_00069F60(28);
    if (r_esi) {
        *(int*)r_esi = (int)DAT_003819DC;
        *(int*)(r_esi + 4) = 0;
        *(int*)(r_esi + 8) = sub_0006B230();
        *(int*)(r_esi + 12) = sub_0006B240();
        *(int*)r_esi = (int)DAT_00381CFC;
    }
    *(int*)(r_esi + 16) = a1;
    *(int*)(r_esi + 20) = a2;
    *(int*)(r_esi + 24) = a3;
    return r_esi;
}

// ============================================================================
// [VERIFIED] sub_00065630 (0x00065630, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006F910 (0x0006F910), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00065630 (0x00065630, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044F598;

void __cdecl sub_00065630(void)
{
    DAT_0044F598 -= 1;
}

// ============================================================================
// [VERIFIED] sub_00065670 (0x00065670, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006F950 (0x0006F950), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00065670 (0x00065670, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044ED84[];
extern "C" int DAT_0044F598;

int __cdecl sub_00065670(void)
{
    int t1;

    t1 = DAT_0044F598;
    if (DAT_0044F598 > 0) {
        return DAT_0044ED84[t1 + (t1 * 4)];
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00065690 (0x00065690, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006F950 (0x0006F950), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00065690 (0x00065690, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044ED8C[];
extern "C" int DAT_0044F598;

int __cdecl sub_00065690(void)
{
    int t1;

    t1 = DAT_0044F598;
    if (DAT_0044F598 > 0) {
        return DAT_0044ED8C[t1 + (t1 * 4)];
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_000660A0 (0x000660A0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000704F0 (0x000704F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000660A0 (0x000660A0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0(int);
};

extern "C" Object DAT_0044F59C;

void __cdecl sub_000660A0(int a1)
{
    DAT_0044F59C.sub_0008D4C0(a1);
}

// ============================================================================
// [VERIFIED] sub_000660C0 (0x000660C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000704F0 (0x000704F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000660C0 (0x000660C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0(int);
};

extern "C" Object DAT_0044F5A0;

void __cdecl sub_000660C0(int a1)
{
    DAT_0044F5A0.sub_0008D4C0(a1);
}

// ============================================================================
// [VERIFIED] sub_00067AC0 (0x00067AC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00067AC0 (0x00067AC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044FE58;

int __cdecl sub_00067AC0(void)
{
    return DAT_0044FE58;
}

// ============================================================================
// [VERIFIED] sub_00068D30 (0x00068D30, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00068D30 (0x00068D30, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EF74[];

class Class_00068D30
{
public:
    void sub_00068D30();
    int m_Field00; // +0x00
};

void Class_00068D30::sub_00068D30()
{
    m_Field00 = (int)DAT_0037EF74;
}

// ============================================================================
// [VERIFIED] sub_0006A010 (0x0006A010, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006A010 (0x0006A010, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00069FD0(void);

class Class_0006A010
{
public:
    void sub_0006A010();
};

void Class_0006A010::sub_0006A010()
{
    sub_00069FD0();
}

// ============================================================================
// [VERIFIED] sub_0006B230 (0x0006B230, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006B230 (0x0006B230, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00450F94;

int __cdecl sub_0006B230(void)
{
    return DAT_00450F94;
}

// ============================================================================
// [VERIFIED] sub_0006B240 (0x0006B240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006B240 (0x0006B240, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00452FAC;

int __cdecl sub_0006B240(void)
{
    return DAT_00452FAC;
}

// ============================================================================
// [VERIFIED] sub_0006BF70 (0x0006BF70, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006BF70 (0x0006BF70, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038275C[];

class Class_0006BF70
{
public:
    void sub_0006BF70();
    int m_Field00; // +0x00
};

void Class_0006BF70::sub_0006BF70()
{
    m_Field00 = (int)DAT_0038275C;
}

// ============================================================================
// [VERIFIED] sub_0006C030 (0x0006C030, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006C030 (0x0006C030, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00382784[];
extern "C" void __cdecl sub_0008ECF0(int, int);

void __cdecl sub_0006C030(int a1)
{
    sub_0008ECF0((int)DAT_00382784, a1);
}

// ============================================================================
// [VERIFIED] sub_0006C370 (0x0006C370, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001CE60 (0x0001CE60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006C370 (0x0006C370, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006C280(int, int);
};

extern "C" int DAT_00452FD4;

void __cdecl sub_0006C370(int a1, int a2)
{
    ((Object*)DAT_00452FD4)->sub_0006C280(a1, a2);
}

// ============================================================================
// [VERIFIED] sub_0006D050 (0x0006D050, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D050 (0x0006D050, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002916B0(void);

class Class_0006D050
{
public:
    void sub_0006D050();
};

void Class_0006D050::sub_0006D050()
{
    sub_002916B0();
}

// ============================================================================
// [VERIFIED] sub_0006D090 (0x0006D090, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D090 (0x0006D090, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00295C80(void);

class Class_0006D090
{
public:
    void sub_0006D090();
};

void Class_0006D090::sub_0006D090()
{
    sub_00295C80();
}

// ============================================================================
// [VERIFIED] sub_0006D0A0 (0x0006D0A0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D0A0 (0x0006D0A0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00295CB0(void);

class Class_0006D0A0
{
public:
    void sub_0006D0A0();
};

void Class_0006D0A0::sub_0006D0A0()
{
    sub_00295CB0();
}

// ============================================================================
// [VERIFIED] sub_0006D4D0 (0x0006D4D0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00077BA0 (0x00077BA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D4D0 (0x0006D4D0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00076150(int);
};

void __cdecl sub_0006D4D0(int a1, int a2)
{
    ((Object*)*(int*)(a1 + 4))->sub_00076150(a2);
}

// ============================================================================
// [VERIFIED] sub_0006D510 (0x0006D510, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00077BA0 (0x00077BA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D510 (0x0006D510, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000762E0(int);
};

void __cdecl sub_0006D510(int a1, int a2)
{
    ((Object*)*(int*)(a1 + 4))->sub_000762E0(a2);
}

// ============================================================================
// [VERIFIED] sub_0006D530 (0x0006D530, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00077BA0 (0x00077BA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D530 (0x0006D530, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00076360(int);
};

void __cdecl sub_0006D530(int a1, int a2)
{
    ((Object*)*(int*)(a1 + 4))->sub_00076360(a2);
}

// ============================================================================
// [VERIFIED] sub_0006D750 (0x0006D750, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D750 (0x0006D750, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453740;

bool __cdecl sub_0006D750(bool a1)
{
    DAT_00453740 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0006D760 (0x0006D760, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D760 (0x0006D760, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453741;

bool __cdecl sub_0006D760(bool a1)
{
    DAT_00453741 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0006D770 (0x0006D770, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D770 (0x0006D770, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453741;

bool __cdecl sub_0006D770(void)
{
    return DAT_00453741;
}

// ============================================================================
// [VERIFIED] sub_0006D780 (0x0006D780, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D780 (0x0006D780, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453742;

bool __cdecl sub_0006D780(bool a1)
{
    DAT_00453742 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0006D790 (0x0006D790, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D790 (0x0006D790, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453742;

bool __cdecl sub_0006D790(void)
{
    return DAT_00453742;
}

// ============================================================================
// [VERIFIED] sub_0006D7A0 (0x0006D7A0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D7A0 (0x0006D7A0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453743;

bool __cdecl sub_0006D7A0(bool a1)
{
    DAT_00453743 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0006D7B0 (0x0006D7B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006D7B0 (0x0006D7B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453743;

bool __cdecl sub_0006D7B0(void)
{
    return DAT_00453743;
}

// ============================================================================
// [VERIFIED] sub_0006E940 (0x0006E940, 83 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065E70 (0x00065E70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006E940 (0x0006E940, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F91F0[];
extern "C" char DAT_003FD4D4[];
extern "C" int __cdecl sub_00292EA0(int);
extern "C" int __cdecl sub_002932C0(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

int __cdecl sub_0006E940(int a1)
{
    int r_eax, r_esi;

    r_eax = sub_002932C0(a1);
    r_esi = r_eax;
    if (!r_esi) goto L_4E;
L_15:
    r_eax = *(int*)(r_esi + 24);
    if (r_eax == *(int*)a1) {
        if (*(int*)(r_esi + 28) != *(int*)(a1 + 4)) goto L_4E;
        r_eax = sub_002C92F8(r_esi, 0, (int)DAT_003F91F0, (int)DAT_003FD4D4, 0);
        if (r_eax) goto L_50;
        r_eax = sub_00292EA0(r_esi);
        r_esi = r_eax;
        if (r_esi) goto L_15;
    }
L_4E:
    r_eax = 0;
L_50:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0006EC40 (0x0006EC40, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006EC40 (0x0006EC40, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0006E940(void);

class Class_0006EC40
{
public:
    void sub_0006EC40();
};

void Class_0006EC40::sub_0006EC40()
{
    sub_0006E940();
}

// ============================================================================
// [VERIFIED] sub_0006F7A0 (0x0006F7A0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0006F7A0 (0x0006F7A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004537BC[];
extern "C" void __stdcall sub_00293590(int);

class Class_0006F7A0
{
public:
    void sub_0006F7A0(int a1);
};

void Class_0006F7A0::sub_0006F7A0(int a1)
{
    a1 = (int)DAT_004537BC;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00071C40 (0x00071C40, 83 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065E70 (0x00065E70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00071C40 (0x00071C40, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F91F0[];
extern "C" char DAT_003F9234[];
extern "C" int __cdecl sub_00292EA0(int);
extern "C" int __cdecl sub_002932C0(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

int __cdecl sub_00071C40(int a1)
{
    int r_eax, r_esi;

    r_eax = sub_002932C0(a1);
    r_esi = r_eax;
    if (!r_esi) goto L_4E;
L_15:
    r_eax = *(int*)(r_esi + 24);
    if (r_eax == *(int*)a1) {
        if (*(int*)(r_esi + 28) != *(int*)(a1 + 4)) goto L_4E;
        r_eax = sub_002C92F8(r_esi, 0, (int)DAT_003F91F0, (int)DAT_003F9234, 0);
        if (r_eax) goto L_50;
        r_eax = sub_00292EA0(r_esi);
        r_esi = r_eax;
        if (r_esi) goto L_15;
    }
L_4E:
    r_eax = 0;
L_50:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000728A0 (0x000728A0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002DCB0 (0x0002DCB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000728A0 (0x000728A0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00071CA0(int);
};

void __cdecl sub_000728A0(int a1, int a2)
{
    ((Object*)a1)->sub_00071CA0(a2);
}

// ============================================================================
// [VERIFIED] sub_000729E0 (0x000729E0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000209E0 (0x000209E0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_00072990();
};

void __cdecl sub_000729E0(Object* object)
{
    object->sub_00072990();
}

// ============================================================================
// [VERIFIED] sub_00072A50 (0x00072A50, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00072A50 (0x00072A50, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004537F0;

int __cdecl sub_00072A50(int a1)
{
    DAT_004537F0 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00072DC0 (0x00072DC0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000209E0 (0x000209E0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_00072D60();
};

void __cdecl sub_00072DC0(Object* object)
{
    object->sub_00072D60();
}

// ============================================================================
// [VERIFIED] sub_00073AF0 (0x00073AF0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002DCB0 (0x0002DCB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00073AF0 (0x00073AF0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000737C0(int);
};

void __cdecl sub_00073AF0(int a1, int a2)
{
    ((Object*)a1)->sub_000737C0(a2);
}

// ============================================================================
// [VERIFIED] sub_000740C0 (0x000740C0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000740C0 (0x000740C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004538EC[];
extern "C" void __stdcall sub_00293590(int);

class Class_000740C0
{
public:
    void sub_000740C0(int a1);
};

void Class_000740C0::sub_000740C0(int a1)
{
    a1 = (int)DAT_004538EC;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_000741B0 (0x000741B0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000741B0 (0x000741B0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00453904[];
extern "C" void __stdcall sub_00293590(int);

class Class_000741B0
{
public:
    void sub_000741B0(int a1);
};

void Class_000741B0::sub_000741B0(int a1)
{
    a1 = (int)DAT_00453904;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00074A20 (0x00074A20, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00080350 (0x00080350), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00074A20 (0x00074A20, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00074550(int, int, int);
};

extern "C" int DAT_00453900;

void __cdecl sub_00074A20(int a1, int a2, int a3)
{
    if (DAT_00453900) {
        ((Object*)DAT_00453900)->sub_00074550(a1, a2, a3);
    }
}

// ============================================================================
// [VERIFIED] sub_00074A40 (0x00074A40, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00080350 (0x00080350), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00074A40 (0x00074A40, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00074610(int, int, int);
};

extern "C" int DAT_00453900;

void __cdecl sub_00074A40(int a1, int a2, int a3)
{
    if (DAT_00453900) {
        ((Object*)DAT_00453900)->sub_00074610(a1, a2, a3);
    }
}

// ============================================================================
// [VERIFIED] sub_00074A60 (0x00074A60, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00080370 (0x00080370), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00074A60 (0x00074A60, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000746D0(int, int);
};

extern "C" int DAT_00453900;

void __cdecl sub_00074A60(int a1, int a2)
{
    if (DAT_00453900) {
        ((Object*)DAT_00453900)->sub_000746D0(a1, a2);
    }
}

// ============================================================================
// [VERIFIED] sub_00074AD0 (0x00074AD0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00080370 (0x00080370), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00074AD0 (0x00074AD0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00074730(int, int);
};

extern "C" int DAT_00453900;

void __cdecl sub_00074AD0(int a1, int a2)
{
    if (DAT_00453900) {
        ((Object*)DAT_00453900)->sub_00074730(a1, a2);
    }
}

// ============================================================================
// [VERIFIED] sub_000757C0 (0x000757C0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000757C0 (0x000757C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00453930[];
extern "C" void __stdcall sub_00293590(int);

class Class_000757C0
{
public:
    void sub_000757C0(int a1);
};

void Class_000757C0::sub_000757C0(int a1)
{
    a1 = (int)DAT_00453930;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00076120 (0x00076120, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00076120 (0x00076120, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045394C[];
extern "C" void __stdcall sub_00293590(int);

class Class_00076120
{
public:
    void sub_00076120(int a1);
};

void Class_00076120::sub_00076120(int a1)
{
    a1 = (int)DAT_0045394C;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00076130 (0x00076130, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00076130 (0x00076130, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045394C[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00076130(int a1)
{
    sub_002935D0((int)DAT_0045394C, a1);
}

// ============================================================================
// [VERIFIED] sub_00076CE0 (0x00076CE0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002DCB0 (0x0002DCB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00076CE0 (0x00076CE0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00076BF0(int);
};

void __cdecl sub_00076CE0(int a1, int a2)
{
    ((Object*)a1)->sub_00076BF0(a2);
}

// ============================================================================
// [VERIFIED] sub_00076E60 (0x00076E60, 83 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065E70 (0x00065E70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00076E60 (0x00076E60, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F91F0[];
extern "C" char DAT_003F93A0[];
extern "C" int __cdecl sub_00292EA0(int);
extern "C" int __cdecl sub_002932C0(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

int __cdecl sub_00076E60(int a1)
{
    int r_eax, r_esi;

    r_eax = sub_002932C0(a1);
    r_esi = r_eax;
    if (!r_esi) goto L_4E;
L_15:
    r_eax = *(int*)(r_esi + 24);
    if (r_eax == *(int*)a1) {
        if (*(int*)(r_esi + 28) != *(int*)(a1 + 4)) goto L_4E;
        r_eax = sub_002C92F8(r_esi, 0, (int)DAT_003F91F0, (int)DAT_003F93A0, 0);
        if (r_eax) goto L_50;
        r_eax = sub_00292EA0(r_esi);
        r_esi = r_eax;
        if (r_esi) goto L_15;
    }
L_4E:
    r_eax = 0;
L_50:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00077140 (0x00077140, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00077140 (0x00077140, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453980;

int __cdecl sub_00077140(void)
{
    return DAT_00453980;
}

// ============================================================================
// [VERIFIED] sub_00077280 (0x00077280, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00077280 (0x00077280, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004539BC[];
extern "C" void __stdcall sub_00293590(int);

class Class_00077280
{
public:
    void sub_00077280(int a1);
};

void Class_00077280::sub_00077280(int a1)
{
    a1 = (int)DAT_004539BC;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_0007CD70 (0x0007CD70, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087300 (0x00087300), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007CD70 (0x0007CD70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0007CD10(int);

void __cdecl sub_0007CD70(void)
{
    sub_0007CD10(0);
}

// ============================================================================
// [VERIFIED] sub_0007D850 (0x0007D850, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087DC0 (0x00087DC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007D850 (0x0007D850, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00058B40(int);

class Class_0007D850
{
public:
    void sub_0007D850(int a1);
    void sub_0007D570(int, int);
};

void Class_0007D850::sub_0007D850(int a1)
{
    sub_0007D570(sub_00058B40(a1), 0);
}

// ============================================================================
// [VERIFIED] sub_0007D9A0 (0x0007D9A0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087DC0 (0x00087DC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007D9A0 (0x0007D9A0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00058B40(int);

class Class_0007D9A0
{
public:
    void sub_0007D9A0(int a1);
    void sub_0007D8F0(int, int);
};

void Class_0007D9A0::sub_0007D9A0(int a1)
{
    sub_0007D8F0(sub_00058B40(a1), 0);
}

// ============================================================================
// [VERIFIED] sub_0007DA20 (0x0007DA20, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087E60 (0x00087E60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007DA20 (0x0007DA20, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003834E8[];

class Class_0007DA20
{
public:
    Class_0007DA20* sub_0007DA20();
    int m_Field00; // +0x00
};

Class_0007DA20* Class_0007DA20::sub_0007DA20()
{
    m_Field00 = (int)DAT_003834E8;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0007DA30 (0x0007DA30, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007DA30 (0x0007DA30, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003834E8[];

class Class_0007DA30
{
public:
    void sub_0007DA30();
    int m_Field00; // +0x00
};

void Class_0007DA30::sub_0007DA30()
{
    m_Field00 = (int)DAT_003834E8;
}

// ============================================================================
// [VERIFIED] sub_0007DC60 (0x0007DC60, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000880C0 (0x000880C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007DC60 (0x0007DC60, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000412A0(int, int);

class Class_0007DC60
{
public:
    int sub_0007DC60(int a1);
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_0007DC60::sub_0007DC60(int a1)
{
    int r_eax;

    r_eax = m_Field04;
    if (r_eax) {
        r_eax = sub_000412A0(r_eax, a1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0007DC80 (0x0007DC80, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000880C0 (0x000880C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007DC80 (0x0007DC80, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001B7A10(int, int);

class Class_0007DC80
{
public:
    int sub_0007DC80(int a1);
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_0007DC80::sub_0007DC80(int a1)
{
    int r_eax;

    r_eax = m_Field04;
    if (r_eax) {
        r_eax = sub_001B7A10(r_eax, a1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0007DCA0 (0x0007DCA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007DCA0 (0x0007DCA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FDC58;

int __cdecl sub_0007DCA0(void)
{
    return DAT_003FDC58;
}

// ============================================================================
// [VERIFIED] sub_0007F9C0 (0x0007F9C0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007F9C0 (0x0007F9C0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0007F780(void);

class Class_0007F9C0
{
public:
    void sub_0007F9C0();
};

void Class_0007F9C0::sub_0007F9C0()
{
    sub_0007F780();
}

// ============================================================================
// [VERIFIED] sub_0007FA10 (0x0007FA10, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006F910 (0x0006F910), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0007FA10 (0x0007FA10, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453B1C;

void __cdecl sub_0007FA10(void)
{
    DAT_00453B1C -= 1;
}

// ============================================================================
// [VERIFIED] sub_00084CE0 (0x00084CE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00084CE0 (0x00084CE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003FE020;

bool __cdecl sub_00084CE0(void)
{
    return DAT_003FE020;
}

// ============================================================================
// [VERIFIED] sub_00084CF0 (0x00084CF0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00084CF0 (0x00084CF0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003FE020;

bool __cdecl sub_00084CF0(bool a1)
{
    DAT_003FE020 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_000852B0 (0x000852B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000852B0 (0x000852B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453F04;

int __cdecl sub_000852B0(void)
{
    return DAT_00453F04;
}

// ============================================================================
// [VERIFIED] sub_000852F0 (0x000852F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000852F0 (0x000852F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453F31;

bool __cdecl sub_000852F0(void)
{
    return DAT_00453F31;
}

// ============================================================================
// [VERIFIED] sub_00085300 (0x00085300, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00085300 (0x00085300, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453F14;

int __cdecl sub_00085300(void)
{
    return DAT_00453F14;
}

// ============================================================================
// [VERIFIED] sub_00085310 (0x00085310, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00085310 (0x00085310, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453F18;

int __cdecl sub_00085310(void)
{
    return DAT_00453F18;
}

// ============================================================================
// [VERIFIED] sub_00085320 (0x00085320, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00085320 (0x00085320, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453F20;

int __cdecl sub_00085320(void)
{
    return DAT_00453F20;
}

// ============================================================================
// [VERIFIED] sub_00085330 (0x00085330, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00085330 (0x00085330, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FE024;

int __cdecl sub_00085330(void)
{
    return DAT_003FE024;
}

// ============================================================================
// [VERIFIED] sub_00085340 (0x00085340, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00085340 (0x00085340, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453F00;

int __cdecl sub_00085340(void)
{
    return DAT_00453F00;
}

// ============================================================================
// [VERIFIED] sub_00085350 (0x00085350, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E680 (0x0001E680), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00085350 (0x00085350, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00453F30;

void __cdecl sub_00085350(void)
{
    DAT_00453F30 = true;
}

// ============================================================================
// [VERIFIED] sub_00085360 (0x00085360, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00085360 (0x00085360, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453F34;

int __cdecl sub_00085360(int a1)
{
    DAT_00453F34 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_000865C0 (0x000865C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000865C0 (0x000865C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453F50;

int __cdecl sub_000865C0(void)
{
    return DAT_00453F50;
}

// ============================================================================
// [VERIFIED] sub_000893F0 (0x000893F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000893F0 (0x000893F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045417C;

int __cdecl sub_000893F0(void)
{
    return DAT_0045417C;
}

// ============================================================================
// [VERIFIED] sub_0008B880 (0x0008B880, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0008B880 (0x0008B880, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004541A0;

int __cdecl sub_0008B880(void)
{
    return DAT_004541A0;
}

// ============================================================================
// [VERIFIED] sub_0008B890 (0x0008B890, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0008B890 (0x0008B890, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FE3A4;

int __cdecl sub_0008B890(void)
{
    return DAT_003FE3A4;
}

// ============================================================================
// [VERIFIED] sub_0008C180 (0x0008C180, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000179A0 (0x000179A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0008C180 (0x0008C180, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004541DC;
extern "C" int DAT_004541D8;

int __cdecl sub_0008C180(int a1, int a2)
{
    DAT_004541DC = a1;
    DAT_004541D8 = a2;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0008C3C0 (0x0008C3C0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000179A0 (0x000179A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0008C3C0 (0x0008C3C0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004541D4;
extern "C" int DAT_004541D0;

int __cdecl sub_0008C3C0(int a1, int a2)
{
    DAT_004541D4 = a1;
    DAT_004541D0 = a2;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0008DEA0 (0x0008DEA0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E2C0 (0x0002E2C0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00383DD4[];
extern "C" const void* __cdecl sub_0005CDD0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0008DEA0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_00383DD4;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0005CDD0), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0008DF10 (0x0008DF10, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00099540 (0x00099540), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00383DDC[];
extern "C" const void* __cdecl sub_0002A890(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0008DF10(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_00383DDC;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002A890), 12);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0008DF80 (0x0008DF80, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000995B0 (0x000995B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00383DE4[];
extern "C" const void* __cdecl sub_0005CDD0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0008DF80(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_00383DE4;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0005CDD0), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0008DFF0 (0x0008DFF0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00099620 (0x00099620), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00383DEC[];
extern "C" const void* __cdecl sub_0002A890(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0008DFF0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_00383DEC;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002A890), 12);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0008E060 (0x0008E060, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00099620 (0x00099620), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00383DF4[];
extern "C" const void* __cdecl sub_0002A890(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0008E060(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_00383DF4;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002A890), 12);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0008E0D0 (0x0008E0D0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000995B0 (0x000995B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00383DFC[];
extern "C" const void* __cdecl sub_0005CC70(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0008E0D0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_00383DFC;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0005CC70), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00095510 (0x00095510, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090310 (0x00090310), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00095510 (0x00095510, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00095190(int);

class Class_00095510
{
public:
    void sub_00095510(int a1);
    void sub_00095410(int);
};

void Class_00095510::sub_00095510(int a1)
{
    sub_00095190(a1);
    sub_00095410(a1);
}

// ============================================================================
// [VERIFIED] sub_00098D30 (0x00098D30, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000A4CA0 (0x000A4CA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00098D30 (0x00098D30, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000ACB70();
};

class Class_00098D30
{
public:
    void sub_00098D30();
};

void Class_00098D30::sub_00098D30()
{
    ((Object*)(int)this + 32)->sub_000ACB70();
}

// ============================================================================
// [VERIFIED] sub_00099AB0 (0x00099AB0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00099AB0 (0x00099AB0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038401C[];

class Class_00099AB0
{
public:
    void sub_00099AB0();
    int m_Field00; // +0x00
};

void Class_00099AB0::sub_00099AB0()
{
    m_Field00 = (int)DAT_0038401C;
}

// ============================================================================
// [VERIFIED] sub_0009AFD0 (0x0009AFD0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00034430 (0x00034430), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0009AFD0 (0x0009AFD0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0007D1E0();
};

class Class_0009AFD0
{
public:
    void sub_0009AFD0();
};

void Class_0009AFD0::sub_0009AFD0()
{
    ((Object*)(int)this + 4)->sub_0007D1E0();
}

// ============================================================================
// [VERIFIED] sub_0009B020 (0x0009B020, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0009B020 (0x0009B020, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0007D210(void);

class Class_0009B020
{
public:
    void sub_0009B020();
};

void Class_0009B020::sub_0009B020()
{
    sub_0007D210();
}

// ============================================================================
// [VERIFIED] sub_0009E9D0 (0x0009E9D0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00015AE0 (0x00015AE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003841C4[];
extern "C" int __cdecl sub_002014E0(const char* name, int a2);

// A small object that is nothing but its vtable, made on the stack and handed to the target.
struct Visitor
{
    void* vtable;
};

struct Target
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(Visitor* visitor, int key);
};

void __cdecl sub_0009E9D0(Target* target, const char* name)
{
    int key = sub_002014E0(name, 0);
    Visitor visitor;
    visitor.vtable = DAT_003841C4;
    target->vfunc_04(&visitor, key);
}

// ============================================================================
// [VERIFIED] sub_0009EC40 (0x0009EC40, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087E60 (0x00087E60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0009EC40 (0x0009EC40, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003841F4[];

class Class_0009EC40
{
public:
    Class_0009EC40* sub_0009EC40();
    int m_Field00; // +0x00
};

Class_0009EC40* Class_0009EC40::sub_0009EC40()
{
    m_Field00 = (int)DAT_003841F4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0009EC50 (0x0009EC50, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0009EC50 (0x0009EC50, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003841F4[];

class Class_0009EC50
{
public:
    void sub_0009EC50();
    int m_Field00; // +0x00
};

void Class_0009EC50::sub_0009EC50()
{
    m_Field00 = (int)DAT_003841F4;
}

// ============================================================================
// [VERIFIED] sub_0009EF90 (0x0009EF90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0009EF90 (0x0009EF90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FEF50;

int __cdecl sub_0009EF90(void)
{
    return DAT_003FEF50;
}

// ============================================================================
// [VERIFIED] sub_0009EFA0 (0x0009EFA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0009EFA0 (0x0009EFA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FEF60;

int __cdecl sub_0009EFA0(void)
{
    return DAT_003FEF60;
}

// ============================================================================
// [VERIFIED] sub_0009EFE0 (0x0009EFE0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006F910 (0x0006F910), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0009EFE0 (0x0009EFE0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00458DF0;

void __cdecl sub_0009EFE0(void)
{
    DAT_00458DF0 -= 1;
}

// ============================================================================
// [VERIFIED] sub_000A14C0 (0x000A14C0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000A14C0 (0x000A14C0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000A03A0(void);

class Class_000A14C0
{
public:
    void sub_000A14C0();
};

void Class_000A14C0::sub_000A14C0()
{
    sub_000A03A0();
}

// ============================================================================
// [VERIFIED] sub_000A3F90 (0x000A3F90, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000A3F90 (0x000A3F90, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000A3B60(void);

class Class_000A3F90
{
public:
    void sub_000A3F90();
};

void Class_000A3F90::sub_000A3F90()
{
    sub_000A3B60();
}

// ============================================================================
// [VERIFIED] sub_000A47C0 (0x000A47C0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000A47C0 (0x000A47C0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003844B8[];

class Class_000A47C0
{
public:
    void sub_000A47C0();
    int m_Field00; // +0x00
};

void Class_000A47C0::sub_000A47C0()
{
    m_Field00 = (int)DAT_003844B8;
}

// ============================================================================
// [VERIFIED] sub_000A4BF0 (0x000A4BF0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047D00 (0x00047D00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000A4BF0 (0x000A4BF0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00384500[];

class Class_000A4BF0
{
public:
    Class_000A4BF0* sub_000A4BF0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_000A4BF0* Class_000A4BF0::sub_000A4BF0()
{
    m_Field00 = (int)DAT_00384500;
    m_Field04 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000A4C00 (0x000A4C00, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000A4C00 (0x000A4C00, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00384500[];

class Class_000A4C00
{
public:
    void sub_000A4C00();
    int m_Field00; // +0x00
};

void Class_000A4C00::sub_000A4C00()
{
    m_Field00 = (int)DAT_00384500;
}

// ============================================================================
// [VERIFIED] sub_000AA830 (0x000AA830, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000B7EE0 (0x000B7EE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000AA830 (0x000AA830, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00383534[];

class Class_000AA830
{
public:
    Class_000AA830* sub_000AA830(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

Class_000AA830* Class_000AA830::sub_000AA830(int a1, int a2)
{
    m_Field00 = (int)DAT_00383534;
    m_Field04 = a1;
    m_Field08 = a2;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000AAD30 (0x000AAD30, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000B83C0 (0x000B83C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000AAD30 (0x000AAD30, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00012600(int, int);

class Class_000AAD30
{
public:
    int sub_000AAD30(int a1);
    int m_Field00; // +0x00
};

int Class_000AAD30::sub_000AAD30(int a1)
{
    int r_eax;

    r_eax = m_Field00;
    if (r_eax) {
        r_eax = sub_00012600(r_eax, a1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000AAE50 (0x000AAE50, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000880C0 (0x000880C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000AAE50 (0x000AAE50, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00041420(int, int);

class Class_000AAE50
{
public:
    int sub_000AAE50(int a1);
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_000AAE50::sub_000AAE50(int a1)
{
    int r_eax;

    r_eax = m_Field04;
    if (r_eax) {
        r_eax = sub_00041420(r_eax, a1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000AB670 (0x000AB670, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000B83C0 (0x000B83C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000AB670 (0x000AB670, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00041EB0(int, int);

class Class_000AB670
{
public:
    int sub_000AB670(int a1);
    int m_Field00; // +0x00
};

int Class_000AB670::sub_000AB670(int a1)
{
    int r_eax;

    r_eax = m_Field00;
    if (r_eax) {
        r_eax = sub_00041EB0(r_eax, a1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000AF370 (0x000AF370, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001EF60 (0x0001EF60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000AF370 (0x000AF370, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003845B8;

float __cdecl sub_000AF370(void)
{
    return DAT_003845B8;
}

// ============================================================================
// [VERIFIED] sub_000B6120 (0x000B6120, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00034430 (0x00034430), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B6120 (0x000B6120, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0();
};

class Class_000B6120
{
public:
    void sub_000B6120();
};

void Class_000B6120::sub_000B6120()
{
    ((Object*)(int)this + 4)->sub_0008D4C0();
}

// ============================================================================
// [VERIFIED] sub_000B77B0 (0x000B77B0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00082DB0 (0x00082DB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B77B0 (0x000B77B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0();
};

class Class_000B77B0
{
public:
    void sub_000B77B0();
};

void Class_000B77B0::sub_000B77B0()
{
    ((Object*)(int)this + 20)->sub_0008D4C0();
}

// ============================================================================
// [VERIFIED] sub_000B7C80 (0x000B7C80, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000C57F0 (0x000C57F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B7C80 (0x000B7C80, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FFE20(void);
extern "C" void __cdecl sub_00201890(void);
extern "C" void __cdecl sub_0023F3C0(void);

void __cdecl sub_000B7C80(void)
{
    sub_00201890();
    sub_0023F3C0();
    sub_001FFE20();
}

// ============================================================================
// [VERIFIED] sub_000B8640 (0x000B8640, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B8640 (0x000B8640, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459500;

int __cdecl sub_000B8640(void)
{
    return DAT_00459500;
}

// ============================================================================
// [VERIFIED] sub_000B8850 (0x000B8850, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000C6320 (0x000C6320), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B8850 (0x000B8850, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    void sub_00205320();
};

class Class_000B8850
{
public:
    void sub_000B8850();
    char m_pad00[0x5C];
    Field5C* m_Field5C; // +0x5C
};

void Class_000B8850::sub_000B8850()
{
    m_Field5C->sub_00205320();
}

// ============================================================================
// [VERIFIED] sub_000B8860 (0x000B8860, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000C6320 (0x000C6320), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B8860 (0x000B8860, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    void sub_000B7D90();
};

class Class_000B8860
{
public:
    void sub_000B8860();
    char m_pad00[0x5C];
    Field5C* m_Field5C; // +0x5C
};

void Class_000B8860::sub_000B8860()
{
    m_Field5C->sub_000B7D90();
}

// ============================================================================
// [VERIFIED] sub_000B8870 (0x000B8870, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000C6320 (0x000C6320), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B8870 (0x000B8870, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    void sub_000B7DB0();
};

class Class_000B8870
{
public:
    void sub_000B8870();
    char m_pad00[0x5C];
    Field5C* m_Field5C; // +0x5C
};

void Class_000B8870::sub_000B8870()
{
    m_Field5C->sub_000B7DB0();
}

// ============================================================================
// [VERIFIED] sub_000B9340 (0x000B9340, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000B9340 (0x000B9340, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459518;

int __cdecl sub_000B9340(void)
{
    return DAT_00459518;
}

// ============================================================================
// [VERIFIED] sub_000BA150 (0x000BA150, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000BA150 (0x000BA150, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000BA0A0(void);

class Class_000BA150
{
public:
    void sub_000BA150();
};

void Class_000BA150::sub_000BA150()
{
    sub_000BA0A0();
}

// ============================================================================
// [VERIFIED] sub_000BB190 (0x000BB190, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000BB190 (0x000BB190, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003FF68C;

bool __cdecl sub_000BB190(bool a1)
{
    DAT_003FF68C = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_000C5330 (0x000C5330, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00034FB0 (0x00034FB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000C5330 (0x000C5330, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459C00[];

int __cdecl sub_000C5330(int a1)
{
    return DAT_00459C00[a1];
}

// ============================================================================
// [VERIFIED] sub_000C64C0 (0x000C64C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000C64C0 (0x000C64C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459CD8;

int __cdecl sub_000C64C0(void)
{
    return DAT_00459CD8;
}

// ============================================================================
// [VERIFIED] sub_000C6770 (0x000C6770, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001EF60 (0x0001EF60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000C6770 (0x000C6770, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003FFAA4;

float __cdecl sub_000C6770(void)
{
    return DAT_003FFAA4;
}

// ============================================================================
// [VERIFIED] sub_000CB380 (0x000CB380, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD0E0 (0x000DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB380 (0x000CB380, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_0038568C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB380
{
public:
    Class_000CB380* sub_000CB380();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

Class_000CB380* Class_000CB380::sub_000CB380()
{
    sub_0001F660();
    m_Field00 = (int)DAT_0038568C;
    m_Field10.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB3E0 (0x000CB3E0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB3E0 (0x000CB3E0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003856D4[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB3E0
{
public:
    Class_000CB3E0* sub_000CB3E0();
    int m_Field00; // +0x00
};

Class_000CB3E0* Class_000CB3E0::sub_000CB3E0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_003856D4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB400 (0x000CB400, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB400 (0x000CB400, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038571C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB400
{
public:
    Class_000CB400* sub_000CB400();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_000CB400* Class_000CB400::sub_000CB400()
{
    sub_0001F660();
    m_Field00 = (int)DAT_0038571C;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB440 (0x000CB440, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB440 (0x000CB440, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385764[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB440
{
public:
    Class_000CB440* sub_000CB440();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_000CB440* Class_000CB440::sub_000CB440()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385764;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB480 (0x000CB480, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB480 (0x000CB480, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003857AC[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB480
{
public:
    Class_000CB480* sub_000CB480();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_000CB480* Class_000CB480::sub_000CB480()
{
    sub_0001F660();
    m_Field00 = (int)DAT_003857AC;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB4C0 (0x000CB4C0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB4C0 (0x000CB4C0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003857F4[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB4C0
{
public:
    Class_000CB4C0* sub_000CB4C0();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_000CB4C0* Class_000CB4C0::sub_000CB4C0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_003857F4;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB500 (0x000CB500, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB500 (0x000CB500, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459E54[];
extern "C" char DAT_00459E58[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000CB500(void)
{
    sub_001FC310((int)DAT_00459E54, (int)DAT_00459E58);
}

// ============================================================================
// [VERIFIED] sub_000CB560 (0x000CB560, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB560 (0x000CB560, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459E5C[];
extern "C" char DAT_00459E60[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000CB560(void)
{
    sub_001FC310((int)DAT_00459E5C, (int)DAT_00459E60);
}

// ============================================================================
// [VERIFIED] sub_000CB5C0 (0x000CB5C0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB5C0 (0x000CB5C0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459E64[];
extern "C" char DAT_00459E68[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000CB5C0(void)
{
    sub_001FC310((int)DAT_00459E64, (int)DAT_00459E68);
}

// ============================================================================
// [VERIFIED] sub_000CB5F0 (0x000CB5F0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB5F0 (0x000CB5F0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003858CC[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB5F0
{
public:
    Class_000CB5F0* sub_000CB5F0();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_000CB5F0* Class_000CB5F0::sub_000CB5F0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_003858CC;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB620 (0x000CB620, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD0E0 (0x000DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB620 (0x000CB620, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00385914[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB620
{
public:
    Class_000CB620* sub_000CB620();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

Class_000CB620* Class_000CB620::sub_000CB620()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385914;
    m_Field10.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB690 (0x000CB690, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD0E0 (0x000DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB690 (0x000CB690, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_0038595C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB690
{
public:
    Class_000CB690* sub_000CB690();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

Class_000CB690* Class_000CB690::sub_000CB690()
{
    sub_0001F660();
    m_Field00 = (int)DAT_0038595C;
    m_Field10.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB6D0 (0x000CB6D0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD0E0 (0x000DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB6D0 (0x000CB6D0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_003859A4[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB6D0
{
public:
    Class_000CB6D0* sub_000CB6D0();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

Class_000CB6D0* Class_000CB6D0::sub_000CB6D0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_003859A4;
    m_Field10.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB740 (0x000CB740, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD0E0 (0x000DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB740 (0x000CB740, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_003859EC[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB740
{
public:
    Class_000CB740* sub_000CB740();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

Class_000CB740* Class_000CB740::sub_000CB740()
{
    sub_0001F660();
    m_Field00 = (int)DAT_003859EC;
    m_Field10.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB780 (0x000CB780, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD0E0 (0x000DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB780 (0x000CB780, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00385A34[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB780
{
public:
    Class_000CB780* sub_000CB780();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

Class_000CB780* Class_000CB780::sub_000CB780()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385A34;
    m_Field10.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB7E0 (0x000CB7E0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB7E0 (0x000CB7E0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385A7C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB7E0
{
public:
    Class_000CB7E0* sub_000CB7E0();
    int m_Field00; // +0x00
};

Class_000CB7E0* Class_000CB7E0::sub_000CB7E0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385A7C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB800 (0x000CB800, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB800 (0x000CB800, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385AC4[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB800
{
public:
    Class_000CB800* sub_000CB800();
    int m_Field00; // +0x00
};

Class_000CB800* Class_000CB800::sub_000CB800()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385AC4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB820 (0x000CB820, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB820 (0x000CB820, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385B0C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB820
{
public:
    Class_000CB820* sub_000CB820();
    int m_Field00; // +0x00
};

Class_000CB820* Class_000CB820::sub_000CB820()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385B0C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB870 (0x000CB870, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB870 (0x000CB870, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385B54[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB870
{
public:
    Class_000CB870* sub_000CB870();
    int m_Field00; // +0x00
};

Class_000CB870* Class_000CB870::sub_000CB870()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385B54;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB890 (0x000CB890, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB890 (0x000CB890, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385B9C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB890
{
public:
    Class_000CB890* sub_000CB890();
    int m_Field00; // +0x00
};

Class_000CB890* Class_000CB890::sub_000CB890()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385B9C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000CB8B0 (0x000CB8B0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000CB8B0 (0x000CB8B0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385BE4[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB8B0
{
public:
    Class_000CB8B0* sub_000CB8B0();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_000CB8B0* Class_000CB8B0::sub_000CB8B0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00385BE4;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000D2370 (0x000D2370, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_004010CC[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_000D2370(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_004010CC, 0);
}

// ============================================================================
// [VERIFIED] sub_000D3180 (0x000D3180, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D3180 (0x000D3180, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459F48;

int __cdecl sub_000D3180(void)
{
    return DAT_00459F48;
}

// ============================================================================
// [VERIFIED] sub_000D3ED0 (0x000D3ED0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E62F0 (0x000E62F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D3ED0 (0x000D3ED0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00386A18[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_000D3ED0
{
public:
    Class_000D3ED0* sub_000D3ED0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_000D3ED0* Class_000D3ED0::sub_000D3ED0(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00386A18;
    m_Field08 = 0;
    m_Field0C = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    if (a2) {
        m_Field0C = a2;
        ((Object*)a2)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_000D3FA0 (0x000D3FA0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E62F0 (0x000E62F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D3FA0 (0x000D3FA0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00386A90[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_000D3FA0
{
public:
    Class_000D3FA0* sub_000D3FA0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_000D3FA0* Class_000D3FA0::sub_000D3FA0(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00386A90;
    m_Field08 = 0;
    m_Field0C = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    if (a2) {
        m_Field0C = a2;
        ((Object*)a2)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_000D4CF0 (0x000D4CF0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D4CF0 (0x000D4CF0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459F5C[];
extern "C" char DAT_00459F60[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D4CF0(void)
{
    sub_001FC310((int)DAT_00459F5C, (int)DAT_00459F60);
}

// ============================================================================
// [VERIFIED] sub_000D4DB0 (0x000D4DB0, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E7440 (0x000E7440), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D4DB0 (0x000D4DB0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC4F0(int);
};

extern "C" char DAT_0038663C[];
extern "C" char DAT_00386BE0[];
extern "C" char DAT_00459F5C[];
extern "C" int DAT_00459F60;
extern "C" char sub_000D5260[];
extern "C" int __cdecl sub_00025120(int);
extern "C" int __cdecl sub_001FC2C0(int, int, int);

int __cdecl sub_000D4DB0(void)
{
    int local_4, r_eax;

    r_eax = DAT_00459F60;
    if (!r_eax) {
        r_eax = sub_00025120(12);
        if (r_eax) {
            ((Object*)r_eax)->sub_001FC4F0((int)DAT_0038663C);
            *(int*)r_eax = (int)DAT_00386BE0;
            *(int*)(r_eax + 8) = (int)sub_000D5260;
            local_4 = r_eax;
        } else {
            local_4 = 0;
        }
        r_eax = (int)(&local_4);
        r_eax = sub_001FC2C0((int)DAT_00459F5C, r_eax, 1);
    }
    DAT_00459F60 += 1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_000D4E80 (0x000D4E80, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D4E80 (0x000D4E80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459F68[];
extern "C" char DAT_00459F6C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D4E80(void)
{
    sub_001FC310((int)DAT_00459F68, (int)DAT_00459F6C);
}

// ============================================================================
// [VERIFIED] sub_000D5220 (0x000D5220, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D5220 (0x000D5220, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459F70[];
extern "C" char DAT_00459F74[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D5220(void)
{
    sub_001FC310((int)DAT_00459F70, (int)DAT_00459F74);
}

// ============================================================================
// [VERIFIED] sub_000D58A0 (0x000D58A0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D58A0 (0x000D58A0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459F7C[];
extern "C" char DAT_00459F80[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D58A0(void)
{
    sub_001FC310((int)DAT_00459F7C, (int)DAT_00459F80);
}

// ============================================================================
// [VERIFIED] sub_000D5AD0 (0x000D5AD0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D5AD0 (0x000D5AD0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459F88[];
extern "C" char DAT_00459F8C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D5AD0(void)
{
    sub_001FC310((int)DAT_00459F88, (int)DAT_00459F8C);
}

// ============================================================================
// [VERIFIED] sub_000D5C60 (0x000D5C60, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D5C60 (0x000D5C60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459F94[];
extern "C" char DAT_00459F98[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D5C60(void)
{
    sub_001FC310((int)DAT_00459F94, (int)DAT_00459F98);
}

// ============================================================================
// [VERIFIED] sub_000D5F90 (0x000D5F90, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D5F90 (0x000D5F90, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459FAC[];
extern "C" char DAT_00459FB0[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D5F90(void)
{
    sub_001FC310((int)DAT_00459FAC, (int)DAT_00459FB0);
}

// ============================================================================
// [VERIFIED] sub_000D63A0 (0x000D63A0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D63A0 (0x000D63A0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459FB8[];
extern "C" char DAT_00459FBC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D63A0(void)
{
    sub_001FC310((int)DAT_00459FB8, (int)DAT_00459FBC);
}

// ============================================================================
// [VERIFIED] sub_000D6B60 (0x000D6B60, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D6B60 (0x000D6B60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459FC0[];
extern "C" char DAT_00459FC4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D6B60(void)
{
    sub_001FC310((int)DAT_00459FC0, (int)DAT_00459FC4);
}

// ============================================================================
// [VERIFIED] sub_000D6EF0 (0x000D6EF0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D6EF0 (0x000D6EF0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00459FD0[];
extern "C" char DAT_00459FD4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D6EF0(void)
{
    sub_001FC310((int)DAT_00459FD0, (int)DAT_00459FD4);
}

// ============================================================================
// [VERIFIED] sub_000D75E0 (0x000D75E0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D75E0 (0x000D75E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045A0B0[];
extern "C" char DAT_0045A0B4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D75E0(void)
{
    sub_001FC310((int)DAT_0045A0B0, (int)DAT_0045A0B4);
}

// ============================================================================
// [VERIFIED] sub_000D7610 (0x000D7610, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E9C90 (0x000E9C90), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D7610 (0x000D7610, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_00290CF0();
};

extern "C" char DAT_00387ED4[];
extern "C" void __cdecl sub_00020610(void);

class Class_000D7610
{
public:
    Class_000D7610* sub_000D7610();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
    Field20 m_Field20; // +0x20
};

Class_000D7610* Class_000D7610::sub_000D7610()
{
    sub_00020610();
    m_Field00 = (int)DAT_00387ED4;
    m_Field1C = 0;
    m_Field20.sub_00290CF0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_000D7660 (0x000D7660, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000A4CA0 (0x000A4CA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D7660 (0x000D7660, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00291030();
};

class Class_000D7660
{
public:
    void sub_000D7660();
};

void Class_000D7660::sub_000D7660()
{
    ((Object*)(int)this + 32)->sub_00291030();
}

// ============================================================================
// [VERIFIED] sub_000D76A0 (0x000D76A0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D76A0 (0x000D76A0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045A0B8[];
extern "C" char DAT_0045A0BC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D76A0(void)
{
    sub_001FC310((int)DAT_0045A0B8, (int)DAT_0045A0BC);
}

// ============================================================================
// [VERIFIED] sub_000D76D0 (0x000D76D0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E9C90 (0x000E9C90), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D76D0 (0x000D76D0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_00290CF0();
};

extern "C" char DAT_00387F5C[];
extern "C" void __cdecl sub_00020610(void);

class Class_000D76D0
{
public:
    Class_000D76D0* sub_000D76D0();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
    Field20 m_Field20; // +0x20
};

Class_000D76D0* Class_000D76D0::sub_000D76D0()
{
    sub_00020610();
    m_Field00 = (int)DAT_00387F5C;
    m_Field1C = 0;
    m_Field20.sub_00290CF0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_000D7760 (0x000D7760, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D7760 (0x000D7760, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045A0C0[];
extern "C" char DAT_0045A0C4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_000D7760(void)
{
    sub_001FC310((int)DAT_0045A0C0, (int)DAT_0045A0C4);
}

// ============================================================================
// [VERIFIED] sub_000D7D00 (0x000D7D00, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D7D00 (0x000D7D00, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CDCC[];

class Class_000D7D00
{
public:
    void sub_000D7D00();
    int m_Field00; // +0x00
};

void Class_000D7D00::sub_000D7D00()
{
    m_Field00 = (int)DAT_0037CDCC;
}

// ============================================================================
// [VERIFIED] sub_000D8D10 (0x000D8D10, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000EB3F0 (0x000EB3F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D8D10 (0x000D8D10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000D7FD0(int, int, int);

class Class_000D8D10
{
public:
    Class_000D8D10* sub_000D8D10(int a1, int a2, int a3);
};

Class_000D8D10* Class_000D8D10::sub_000D8D10(int a1, int a2, int a3)
{
    sub_000D7FD0(a1, a2, a3);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000D8D30 (0x000D8D30, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000EB3F0 (0x000EB3F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D8D30 (0x000D8D30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000D8060(int, int, int);

class Class_000D8D30
{
public:
    Class_000D8D30* sub_000D8D30(int a1, int a2, int a3);
};

Class_000D8D30* Class_000D8D30::sub_000D8D30(int a1, int a2, int a3)
{
    sub_000D8060(a1, a2, a3);
    return this;
}

// ============================================================================
// [VERIFIED] sub_000D8FA0 (0x000D8FA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000D8FA0 (0x000D8FA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045B4FC;

int __cdecl sub_000D8FA0(void)
{
    return DAT_0045B4FC;
}

// ============================================================================
// [VERIFIED] sub_000DAB10 (0x000DAB10, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000ED9B0 (0x000ED9B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000DAB10 (0x000DAB10, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D9C70(int, int);
};

class Class_000DAB10
{
public:
    void sub_000DAB10(int a1, int a2, int a3);
};

void Class_000DAB10::sub_000DAB10(int a1, int a2, int a3)
{
    ((Object*)(int)this + (a1 * 8) + 4)->sub_000D9C70(a2, a3);
}

// ============================================================================
// [VERIFIED] sub_000DAB30 (0x000DAB30, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000ED9B0 (0x000ED9B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000DAB30 (0x000DAB30, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D9C80(int, int);
};

class Class_000DAB30
{
public:
    void sub_000DAB30(int a1, int a2, int a3);
};

void Class_000DAB30::sub_000DAB30(int a1, int a2, int a3)
{
    ((Object*)(int)this + (a1 * 8) + 4)->sub_000D9C80(a2, a3);
}

// ============================================================================
// [VERIFIED] sub_000DB860 (0x000DB860, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000DB860 (0x000DB860, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045B950;

int __cdecl sub_000DB860(void)
{
    return DAT_0045B950;
}

// ============================================================================
// [VERIFIED] sub_000DE020 (0x000DE020, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_00402904[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_000DE020(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_00402904, 0);
}

// ============================================================================
// [VERIFIED] sub_000DE050 (0x000DE050, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_00402920[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_000DE050(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_00402920, 0);
}

// ============================================================================
// [VERIFIED] sub_000E9260 (0x000E9260, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000E9260 (0x000E9260, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000E8540(void);

class Class_000E9260
{
public:
    void sub_000E9260();
};

void Class_000E9260::sub_000E9260()
{
    sub_000E8540();
}

// ============================================================================
// [VERIFIED] sub_000EC990 (0x000EC990, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00034430 (0x00034430), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000EC990 (0x000EC990, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000E9270();
};

class Class_000EC990
{
public:
    void sub_000EC990();
};

void Class_000EC990::sub_000EC990()
{
    ((Object*)(int)this + 4)->sub_000E9270();
}

// ============================================================================
// [VERIFIED] sub_000ECEF0 (0x000ECEF0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000ECEF0 (0x000ECEF0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003834CC[];

class Class_000ECEF0
{
public:
    void sub_000ECEF0();
    int m_Field00; // +0x00
};

void Class_000ECEF0::sub_000ECEF0()
{
    m_Field00 = (int)DAT_003834CC;
}

// ============================================================================
// [VERIFIED] sub_000ED700 (0x000ED700, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00026990 (0x00026990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000ED700 (0x000ED700, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000ED700
{
public:
    void sub_000ED700();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

void Class_000ED700::sub_000ED700()
{
    m_Field04 = 0;
}

// ============================================================================
// [VERIFIED] sub_000EFBA0 (0x000EFBA0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000EFBA0 (0x000EFBA0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045BA8C;

int __cdecl sub_000EFBA0(int a1)
{
    DAT_0045BA8C = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_000F2900 (0x000F2900, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F2900 (0x000F2900, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038A204[];

class Class_000F2900
{
public:
    Class_000F2900* sub_000F2900(int a1, int a2);
    void sub_000F0360(int, int);
    int m_Field00; // +0x00
};

Class_000F2900* Class_000F2900::sub_000F2900(int a1, int a2)
{
    sub_000F0360(a1, a2);
    m_Field00 = (int)DAT_0038A204;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000F2930 (0x000F2930, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F2930 (0x000F2930, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000F26E0(void);

class Class_000F2930
{
public:
    void sub_000F2930();
};

void Class_000F2930::sub_000F2930()
{
    sub_000F26E0();
}

// ============================================================================
// [VERIFIED] sub_000F38F0 (0x000F38F0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F38F0 (0x000F38F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038A704[];

class Class_000F38F0
{
public:
    Class_000F38F0* sub_000F38F0(int a1, int a2);
    void sub_000F0360(int, int);
    int m_Field00; // +0x00
};

Class_000F38F0* Class_000F38F0::sub_000F38F0(int a1, int a2)
{
    sub_000F0360(a1, a2);
    m_Field00 = (int)DAT_0038A704;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000F4FB0 (0x000F4FB0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F4FB0 (0x000F4FB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038A96C[];

class Class_000F4FB0
{
public:
    Class_000F4FB0* sub_000F4FB0(int a1, int a2);
    void sub_000F0360(int, int);
    int m_Field00; // +0x00
};

Class_000F4FB0* Class_000F4FB0::sub_000F4FB0(int a1, int a2)
{
    sub_000F0360(a1, a2);
    m_Field00 = (int)DAT_0038A96C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000F5070 (0x000F5070, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F5070 (0x000F5070, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038A81C[];

class Class_000F5070
{
public:
    Class_000F5070* sub_000F5070(int a1, int a2);
    void sub_000F0360(int, int);
    int m_Field00; // +0x00
};

Class_000F5070* Class_000F5070::sub_000F5070(int a1, int a2)
{
    sub_000F0360(a1, a2);
    m_Field00 = (int)DAT_0038A81C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_000F5210 (0x000F5210, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F5210 (0x000F5210, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045BB50;

int __cdecl sub_000F5210(void)
{
    return DAT_0045BB50;
}

// ============================================================================
// [VERIFIED] sub_000F6310 (0x000F6310, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_00402E94[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_000F6310(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_00402E94, 0);
}

// ============================================================================
// [VERIFIED] sub_000F6340 (0x000F6340, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_00402FF0[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_000F6340(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_00402FF0, 0);
}

// ============================================================================
// [VERIFIED] sub_000F7DA0 (0x000F7DA0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F7DA0 (0x000F7DA0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027270(void);

class Class_000F7DA0
{
public:
    void sub_000F7DA0();
};

void Class_000F7DA0::sub_000F7DA0()
{
    sub_00027270();
}

// ============================================================================
// [VERIFIED] sub_000F8650 (0x000F8650, 58 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0010FBF0 (0x0010FBF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_000F8650 (0x000F8650, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F8510();
};

extern "C" Object DAT_0045BB90;
extern "C" bool DAT_0045BC74;
extern "C" char sub_002F17F0[];
extern "C" void __cdecl sub_002C8EB3(int);

Object* __cdecl sub_000F8650(void)
{
    if (!(1 & DAT_0045BC74)) {
        *(int*)&DAT_0045BC74 = *(int*)&DAT_0045BC74 | 1;
        DAT_0045BB90.sub_000F8510();
        sub_002C8EB3((int)sub_002F17F0);
    }
    return &DAT_0045BB90;
}

// ============================================================================
// [VERIFIED] sub_000FC930 (0x000FC930, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136830 (0x00136830), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B3AC[];
extern "C" const void* __cdecl sub_0002AD80(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 1 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_000FC930(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B3AC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AD80), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FEBD0 (0x000FEBD0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119F60 (0x00119F60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4A0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_000FEBD0(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4A0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FECD0 (0x000FECD0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119E60 (0x00119E60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4A8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_000FECD0(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038B4A8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FED50 (0x000FED50, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119EE0 (0x00119EE0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4B0[];
extern "C" const void* __cdecl sub_00023090(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 1 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_000FED50(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4B0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_00023090), 1);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FEDD0 (0x000FEDD0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119F60 (0x00119F60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F198[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_000FEDD0(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037F198;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FEE50 (0x000FEE50, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119E60 (0x00119E60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4B8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_000FEE50(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038B4B8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FEED0 (0x000FEED0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119F60 (0x00119F60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4C0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_000FEED0(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4C0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FEF50 (0x000FEF50, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011A0E0 (0x0011A0E0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4C8[];
extern "C" const void* __cdecl sub_0002AAB0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 1 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_000FEF50(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4C8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAB0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FF050 (0x000FF050, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011A0E0 (0x0011A0E0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4E0[];
extern "C" const void* __cdecl sub_0002AD80(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 1 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_000FF050(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4E0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AD80), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FF0D0 (0x000FF0D0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119E60 (0x00119E60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4E8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_000FF0D0(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038B4E8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_000FF150 (0x000FF150, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119F60 (0x00119F60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F1A0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_000FF150(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037F1A0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00100EC0 (0x00100EC0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BD30 (0x0011BD30), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038BBD8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 4 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00100EC0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038BBD8;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00100F30 (0x00100F30, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BDA0 (0x0011BDA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F0FC[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_00100F30(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_0037F0FC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00100FB0 (0x00100FB0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119F60 (0x00119F60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4D8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_00100FB0(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4D8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00101030 (0x00101030, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119E60 (0x00119E60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038BBE0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_00101030(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038BBE0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00102780 (0x00102780, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000D3C80 (0x000D3C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00102780 (0x00102780, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_001024F0(int, int);

void __stdcall sub_00102780(int a1)
{
    sub_001024F0(a1, 1);
}

// ============================================================================
// [VERIFIED] sub_00102BD0 (0x00102BD0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011DDA0 (0x0011DDA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00102BD0 (0x00102BD0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F0340(int);
};

extern "C" char DAT_00389160[];
extern "C" char DAT_0038C5EC[];

class Class_00102BD0
{
public:
    Class_00102BD0* sub_00102BD0(int a1, int a2, int a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_00102BD0* Class_00102BD0::sub_00102BD0(int a1, int a2, int a3)
{
    m_Field00 = (int)DAT_00389160;
    ((Object*)a2)->sub_000F0340((int)this);
    m_Field08 = a3;
    m_Field04 = 0;
    m_Field00 = (int)DAT_0038C5EC;
    m_Field0C = a1;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00102CB0 (0x00102CB0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011DDA0 (0x0011DDA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00102CB0 (0x00102CB0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F0340(int);
};

extern "C" char DAT_00389160[];
extern "C" char DAT_0038C614[];

class Class_00102CB0
{
public:
    Class_00102CB0* sub_00102CB0(int a1, int a2, int a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_00102CB0* Class_00102CB0::sub_00102CB0(int a1, int a2, int a3)
{
    m_Field00 = (int)DAT_00389160;
    ((Object*)a2)->sub_000F0340((int)this);
    m_Field08 = a3;
    m_Field04 = 0;
    m_Field00 = (int)DAT_0038C614;
    m_Field0C = a1;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001030D0 (0x001030D0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011E2C0 (0x0011E2C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001030D0 (0x001030D0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00104900(int);
};

extern "C" int __cdecl sub_00025120(int);

int __stdcall sub_001030D0(int a1)
{
    int t1;

    t1 = sub_00025120(16);
    if (t1) {
        return ((Object*)t1)->sub_00104900(a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_001032B0 (0x001032B0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011E2C0 (0x0011E2C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001032B0 (0x001032B0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00105670(int);
};

extern "C" int __cdecl sub_00025120(int);

int __stdcall sub_001032B0(int a1)
{
    int t1;

    t1 = sub_00025120(16);
    if (t1) {
        return ((Object*)t1)->sub_00105670(a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00103400 (0x00103400, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011E640 (0x0011E640), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00103400 (0x00103400, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00105FB0(int);
};

extern "C" int __cdecl sub_00025120(int);

class Class_00103400
{
public:
    int sub_00103400();
    int m_Field00; // +0x00
};

int Class_00103400::sub_00103400()
{
    int t1;

    t1 = sub_00025120(12);
    if (t1) {
        return ((Object*)t1)->sub_00105FB0(m_Field00);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00103580 (0x00103580, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011E640 (0x0011E640), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00103580 (0x00103580, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00105FD0(int);
};

extern "C" int __cdecl sub_00025120(int);

class Class_00103580
{
public:
    int sub_00103580();
    int m_Field00; // +0x00
};

int Class_00103580::sub_00103580()
{
    int t1;

    t1 = sub_00025120(12);
    if (t1) {
        return ((Object*)t1)->sub_00105FD0(m_Field00);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00104A50 (0x00104A50, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011FD50 (0x0011FD50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00104A50 (0x00104A50, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038C720[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00104A50
{
public:
    Class_00104A50* sub_00104A50(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_00104A50* Class_00104A50::sub_00104A50(int a1)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038C720;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00105E80 (0x00105E80, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00121470 (0x00121470), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00105E80 (0x00105E80, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_00105350(int);
};

extern "C" char DAT_0038CA0C[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00105E80
{
public:
    Class_00105E80* sub_00105E80(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

Class_00105E80* Class_00105E80::sub_00105E80(int a1, int a2)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038CA0C;
    m_Field0C.sub_00105350(a2);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00105F50 (0x00105F50, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00121470 (0x00121470), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00105F50 (0x00105F50, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_00105110(int);
};

extern "C" char DAT_0038CA3C[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00105F50
{
public:
    Class_00105F50* sub_00105F50(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

Class_00105F50* Class_00105F50::sub_00105F50(int a1, int a2)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038CA3C;
    m_Field0C.sub_00105110(a2);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00105FB0 (0x00105FB0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011FD50 (0x0011FD50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00105FB0 (0x00105FB0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038CA6C[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00105FB0
{
public:
    Class_00105FB0* sub_00105FB0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_00105FB0* Class_00105FB0::sub_00105FB0(int a1)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038CA6C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00105FD0 (0x00105FD0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011FD50 (0x0011FD50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00105FD0 (0x00105FD0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038CA9C[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00105FD0
{
public:
    Class_00105FD0* sub_00105FD0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_00105FD0* Class_00105FD0::sub_00105FD0(int a1)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038CA9C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00106020 (0x00106020, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00121470 (0x00121470), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00106020 (0x00106020, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_00105350(int);
};

extern "C" char DAT_0038CAFC[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00106020
{
public:
    Class_00106020* sub_00106020(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

Class_00106020* Class_00106020::sub_00106020(int a1, int a2)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038CAFC;
    m_Field0C.sub_00105350(a2);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00106080 (0x00106080, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011FD50 (0x0011FD50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00106080 (0x00106080, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038CB2C[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00106080
{
public:
    Class_00106080* sub_00106080(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_00106080* Class_00106080::sub_00106080(int a1)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038CB2C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00109A50 (0x00109A50, 58 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0010FBF0 (0x0010FBF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00109A50 (0x00109A50, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00109980();
};

extern "C" Object DAT_0045BFF0;
extern "C" bool DAT_0045C000;
extern "C" char sub_002F27C0[];
extern "C" void __cdecl sub_002C8EB3(int);

Object* __cdecl sub_00109A50(void)
{
    if (!(1 & DAT_0045C000)) {
        *(int*)&DAT_0045C000 = *(int*)&DAT_0045C000 | 1;
        DAT_0045BFF0.sub_00109980();
        sub_002C8EB3((int)sub_002F27C0);
    }
    return &DAT_0045BFF0;
}

// ============================================================================
// [VERIFIED] sub_0010A9F0 (0x0010A9F0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_0040266C[];
extern "C" void* __cdecl sub_000281E0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_0010A9F0(int a1, int a2)
{
    void* object = sub_000281E0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_0040266C, 0);
}

// ============================================================================
// [VERIFIED] sub_0010B910 (0x0010B910, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0010B910 (0x0010B910, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038DE64[];

void* __cdecl sub_0010B910(void)
{
    return DAT_0038DE64;
}

// ============================================================================
// [VERIFIED] sub_0010CB90 (0x0010CB90, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0010CB90 (0x0010CB90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038E484[];

class Class_0010CB90
{
public:
    Class_0010CB90* sub_0010CB90(int a1, int a2);
    void sub_0010DC20(int, int);
    int m_Field00; // +0x00
};

Class_0010CB90* Class_0010CB90::sub_0010CB90(int a1, int a2)
{
    sub_0010DC20(a1, a2);
    m_Field00 = (int)DAT_0038E484;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0010CBC0 (0x0010CBC0, 68 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001287F0 (0x001287F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0010CBC0 (0x0010CBC0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FF300();
};

extern "C" Object DAT_0045C0D8;
extern "C" int DAT_0045C0F4;
extern "C" bool DAT_0045C0F8;
extern "C" char sub_002F2800[];
extern "C" void __cdecl sub_002C8EB3(int);

Object* __cdecl sub_0010CBC0(void)
{
    if (!(1 & DAT_0045C0F8)) {
        *(int*)&DAT_0045C0F8 = *(int*)&DAT_0045C0F8 | 1;
        DAT_0045C0D8.sub_001FF300();
        DAT_0045C0F4 = 32;
        sub_002C8EB3((int)sub_002F2800);
    }
    return &DAT_0045C0D8;
}

// ============================================================================
// [VERIFIED] sub_0010E4C0 (0x0010E4C0, 68 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001287F0 (0x001287F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0010E4C0 (0x0010E4C0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FF300();
};

extern "C" Object DAT_0045C18C;
extern "C" int DAT_0045C1A8;
extern "C" bool DAT_0045C1AC;
extern "C" char sub_002F2820[];
extern "C" void __cdecl sub_002C8EB3(int);

Object* __cdecl sub_0010E4C0(void)
{
    if (!(1 & DAT_0045C1AC)) {
        *(int*)&DAT_0045C1AC = *(int*)&DAT_0045C1AC | 1;
        DAT_0045C18C.sub_001FF300();
        DAT_0045C1A8 = 32;
        sub_002C8EB3((int)sub_002F2820);
    }
    return &DAT_0045C18C;
}

// ============================================================================
// [VERIFIED] sub_0010E7D0 (0x0010E7D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0010E7D0 (0x0010E7D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045C1C0;

int __cdecl sub_0010E7D0(void)
{
    return DAT_0045C1C0;
}

// ============================================================================
// [VERIFIED] sub_00116580 (0x00116580, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000A4CA0 (0x000A4CA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00116580 (0x00116580, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0();
};

class Class_00116580
{
public:
    void sub_00116580();
};

void Class_00116580::sub_00116580()
{
    ((Object*)(int)this + 32)->sub_0008D4C0();
}

// ============================================================================
// [VERIFIED] sub_00118EA0 (0x00118EA0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00239CC0 (0x00239CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00118EA0 (0x00118EA0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F644[];

class Class_00118EA0
{
public:
    Class_00118EA0* sub_00118EA0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_00118EA0* Class_00118EA0::sub_00118EA0()
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_0038F644;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0011B770 (0x0011B770, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136830 (0x00136830), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FCD0[];
extern "C" const void* __cdecl sub_0002AD80(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 1 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0011B770(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038FCD0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AD80), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011B7F0 (0x0011B7F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FCD8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011B7F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038FCD8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011B870 (0x0011B870, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FCE0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011B870(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038FCE0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011B8F0 (0x0011B8F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FCE8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011B8F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038FCE8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011B970 (0x0011B970, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FCF0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011B970(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FCF0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011B9F0 (0x0011B9F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FCF8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011B9F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FCF8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BAF0 (0x0011BAF0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD08[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BAF0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038FD08;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BB70 (0x0011BB70, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD10[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BB70(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038FD10;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BBF0 (0x0011BBF0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD18[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BBF0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FD18;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BC70 (0x0011BC70, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD20[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BC70(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038FD20;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BCF0 (0x0011BCF0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD28[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BCF0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FD28;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BD70 (0x0011BD70, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136EB0 (0x00136EB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD30[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BD70(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(5);
        *(void**)object = DAT_0038FD30;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BDF0 (0x0011BDF0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD38[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BDF0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FD38;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BE70 (0x0011BE70, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4B8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BE70(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038B4B8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BEF0 (0x0011BEF0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD40[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BEF0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038FD40;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BF70 (0x0011BF70, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD48[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BF70(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FD48;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011BFF0 (0x0011BFF0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD50[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011BFF0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038FD50;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C070 (0x0011C070, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD58[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C070(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038FD58;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C0F0 (0x0011C0F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038BBD0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C0F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038BBD0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C170 (0x0011C170, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD60[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C170(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038FD60;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C1F0 (0x0011C1F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD68[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C1F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038FD68;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C270 (0x0011C270, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD70[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C270(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038FD70;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C2F0 (0x0011C2F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD78[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C2F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038FD78;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C370 (0x0011C370, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD80[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C370(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FD80;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C3F0 (0x0011C3F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD88[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C3F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FD88;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C470 (0x0011C470, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD90[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C470(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038FD90;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C4F0 (0x0011C4F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FD98[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C4F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0038FD98;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0011C570 (0x0011C570, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038FDA0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0011C570(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038FDA0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00121DD0 (0x00121DD0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E42D0 (0x000E42D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00121DD0 (0x00121DD0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0008D4C0(int);

class Class_00121DD0
{
public:
    Class_00121DD0* sub_00121DD0(int a1);
};

Class_00121DD0* Class_00121DD0::sub_00121DD0(int a1)
{
    sub_0008D4C0(a1);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00129DD0 (0x00129DD0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00129DD0 (0x00129DD0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003903AC[];
extern "C" void __cdecl sub_0012DC20(void);

class Class_00129DD0
{
public:
    void sub_00129DD0();
    int m_Field00; // +0x00
};

void Class_00129DD0::sub_00129DD0()
{
    m_Field00 = (int)DAT_003903AC;
    sub_0012DC20();
}

// ============================================================================
// [VERIFIED] sub_0012D7E0 (0x0012D7E0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0012D7E0 (0x0012D7E0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004094FC;

int __cdecl sub_0012D7E0(int a1)
{
    DAT_004094FC = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0012DA30 (0x0012DA30, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0012DA30 (0x0012DA30, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003909EC[];
extern "C" void __cdecl sub_00029C00(void);

class Class_0012DA30
{
public:
    void sub_0012DA30();
    int m_Field00; // +0x00
};

void Class_0012DA30::sub_0012DA30()
{
    m_Field00 = (int)DAT_003909EC;
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_0012DBE0 (0x0012DBE0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0014A5B0 (0x0014A5B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0012DBE0 (0x0012DBE0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00390A8C[];

class Class_0012DBE0
{
public:
    Class_0012DBE0* sub_0012DBE0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

Class_0012DBE0* Class_0012DBE0::sub_0012DBE0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field00 = (int)DAT_00390A8C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0012DC20 (0x0012DC20, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0012DC20 (0x0012DC20, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00390A8C[];
extern "C" void __cdecl sub_00029C00(void);

class Class_0012DC20
{
public:
    void sub_0012DC20();
    int m_Field00; // +0x00
};

void Class_0012DC20::sub_0012DC20()
{
    m_Field00 = (int)DAT_00390A8C;
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_00130DD0 (0x00130DD0, 58 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0010FBF0 (0x0010FBF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00130DD0 (0x00130DD0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00130B50();
};

extern "C" Object DAT_0045C370;
extern "C" bool DAT_0045C3A0;
extern "C" char sub_002F2CF0[];
extern "C" void __cdecl sub_002C8EB3(int);

Object* __cdecl sub_00130DD0(void)
{
    if (!(1 & DAT_0045C3A0)) {
        *(int*)&DAT_0045C3A0 = *(int*)&DAT_0045C3A0 | 1;
        DAT_0045C370.sub_00130B50();
        sub_002C8EB3((int)sub_002F2CF0);
    }
    return &DAT_0045C370;
}

// ============================================================================
// [VERIFIED] sub_00133750 (0x00133750, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00133750 (0x00133750, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045C3F4;

int __cdecl sub_00133750(void)
{
    return DAT_0045C3F4;
}

// ============================================================================
// [VERIFIED] sub_00135B00 (0x00135B00, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00135B00 (0x00135B00, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039102C[];

class Class_00135B00
{
public:
    void sub_00135B00();
    int m_Field00; // +0x00
};

void Class_00135B00::sub_00135B00()
{
    m_Field00 = (int)DAT_0039102C;
}

// ============================================================================
// [VERIFIED] sub_0013A550 (0x0013A550, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0013A550 (0x0013A550, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045C4C0;
extern "C" int DAT_0045C4C4;

void __cdecl sub_0013A550(void)
{
    DAT_0045C4C0.sub_0008D4E0(DAT_0045C4C4);
}

// ============================================================================
// [VERIFIED] sub_0013CCF0 (0x0013CCF0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0013CCF0 (0x0013CCF0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045C518;
extern "C" int DAT_0045C51C;

void __cdecl sub_0013CCF0(void)
{
    DAT_0045C518.sub_0008D4E0(DAT_0045C51C);
}

// ============================================================================
// [VERIFIED] sub_00142FC0 (0x00142FC0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00142FC0 (0x00142FC0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045CB50;
extern "C" int DAT_0045CB54;

void __cdecl sub_00142FC0(void)
{
    DAT_0045CB50.sub_0008D4E0(DAT_0045CB54);
}

// ============================================================================
// [VERIFIED] sub_001431C0 (0x001431C0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001431C0 (0x001431C0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00142DF0(void);

class Class_001431C0
{
public:
    void sub_001431C0();
};

void Class_001431C0::sub_001431C0()
{
    sub_00142DF0();
}

// ============================================================================
// [VERIFIED] sub_001431D0 (0x001431D0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001431D0 (0x001431D0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045CB60;
extern "C" int DAT_0045CB64;

void __cdecl sub_001431D0(void)
{
    DAT_0045CB60.sub_0008D4E0(DAT_0045CB64);
}

// ============================================================================
// [VERIFIED] sub_00144F30 (0x00144F30, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00144F30 (0x00144F30, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045CBF8;
extern "C" int DAT_0045CBFC;

void __cdecl sub_00144F30(void)
{
    DAT_0045CBF8.sub_0008D4E0(DAT_0045CBFC);
}

// ============================================================================
// [VERIFIED] sub_00145560 (0x00145560, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00145560 (0x00145560, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045CC00;
extern "C" int DAT_0045CC04;

void __cdecl sub_00145560(void)
{
    DAT_0045CC00.sub_0008D4E0(DAT_0045CC04);
}

// ============================================================================
// [VERIFIED] sub_00145FE0 (0x00145FE0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00145FE0 (0x00145FE0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045CC10;
extern "C" int DAT_0045CC14;

void __cdecl sub_00145FE0(void)
{
    DAT_0045CC10.sub_0008D4E0(DAT_0045CC14);
}

// ============================================================================
// [VERIFIED] sub_00146060 (0x00146060, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00146060 (0x00146060, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00391DF0[];

class Class_00146060
{
public:
    void sub_00146060();
    int m_Field00; // +0x00
};

void Class_00146060::sub_00146060()
{
    m_Field00 = (int)DAT_00391DF0;
}

// ============================================================================
// [VERIFIED] sub_00147650 (0x00147650, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018EB0 (0x00018EB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00147650 (0x00147650, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_001B7A10();
};

class Class_00147650
{
public:
    void sub_00147650();
    char m_pad00[0x18];
    Field1C m_Field18; // +0x18
    char m_pad19[0x3];
    Field1C m_Field1C; // +0x1C
};

void Class_00147650::sub_00147650()
{
    m_Field1C.sub_001B7A10();
    m_Field18.sub_001B7A10();
}

// ============================================================================
// [VERIFIED] sub_00147CD0 (0x00147CD0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00163FA0 (0x00163FA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00147CD0 (0x00147CD0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00152100();
};

extern "C" Object DAT_0045CC98;

void __cdecl sub_00147CD0(void)
{
    DAT_0045CC98.sub_00152100();
}

// ============================================================================
// [VERIFIED] sub_00147CE0 (0x00147CE0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00163FA0 (0x00163FA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00147CE0 (0x00147CE0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00152130();
};

extern "C" Object DAT_0045CC98;

void __cdecl sub_00147CE0(void)
{
    DAT_0045CC98.sub_00152130();
}

// ============================================================================
// [VERIFIED] sub_00147D80 (0x00147D80, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001640D0 (0x001640D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00147D80 (0x00147D80, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;
extern "C" int DAT_0045CC64;

int __cdecl sub_00147D80(void)
{
    int t1;

    t1 = DAT_0045A0EC;
    DAT_0045CC64 = *(int*)(DAT_0045A0EC + 44);
    return t1;
}

// ============================================================================
// [VERIFIED] sub_001482D0 (0x001482D0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001482D0 (0x001482D0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045CC88;

int __cdecl sub_001482D0(int a1)
{
    DAT_0045CC88 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_001482E0 (0x001482E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001482E0 (0x001482E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045CC88;

int __cdecl sub_001482E0(void)
{
    return DAT_0045CC88;
}

// ============================================================================
// [VERIFIED] sub_00148790 (0x00148790, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00148790 (0x00148790, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0040AA34;

bool __cdecl sub_00148790(bool a1)
{
    DAT_0040AA34 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00149900 (0x00149900, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00163FA0 (0x00163FA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00149900 (0x00149900, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0();
};

extern "C" Object DAT_0045CC94;

void __cdecl sub_00149900(void)
{
    DAT_0045CC94.sub_0008D4C0();
}

// ============================================================================
// [VERIFIED] sub_00150170 (0x00150170, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00150170 (0x00150170, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003924BC[];

class Class_00150170
{
public:
    Class_00150170* sub_00150170(int a1, int a2);
    void sub_0014AA60(int, int);
    int m_Field00; // +0x00
};

Class_00150170* Class_00150170::sub_00150170(int a1, int a2)
{
    sub_0014AA60(a1, a2);
    m_Field00 = (int)DAT_003924BC;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001501A0 (0x001501A0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001501A0 (0x001501A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003925A4[];

class Class_001501A0
{
public:
    Class_001501A0* sub_001501A0(int a1, int a2);
    void sub_0014AA60(int, int);
    int m_Field00; // +0x00
};

Class_001501A0* Class_001501A0::sub_001501A0(int a1, int a2)
{
    sub_0014AA60(a1, a2);
    m_Field00 = (int)DAT_003925A4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001501D0 (0x001501D0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001501D0 (0x001501D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039268C[];

class Class_001501D0
{
public:
    Class_001501D0* sub_001501D0(int a1, int a2);
    void sub_0014AA60(int, int);
    int m_Field00; // +0x00
};

Class_001501D0* Class_001501D0::sub_001501D0(int a1, int a2)
{
    sub_0014AA60(a1, a2);
    m_Field00 = (int)DAT_0039268C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00150200 (0x00150200, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00150200 (0x00150200, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00392774[];

class Class_00150200
{
public:
    Class_00150200* sub_00150200(int a1, int a2);
    void sub_0014AA60(int, int);
    int m_Field00; // +0x00
};

Class_00150200* Class_00150200::sub_00150200(int a1, int a2)
{
    sub_0014AA60(a1, a2);
    m_Field00 = (int)DAT_00392774;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00150250 (0x00150250, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00150250 (0x00150250, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039286C[];

class Class_00150250
{
public:
    Class_00150250* sub_00150250(int a1, int a2);
    void sub_0014AA60(int, int);
    int m_Field00; // +0x00
};

Class_00150250* Class_00150250::sub_00150250(int a1, int a2)
{
    sub_0014AA60(a1, a2);
    m_Field00 = (int)DAT_0039286C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00150440 (0x00150440, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00150440 (0x00150440, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00392AF4[];

class Class_00150440
{
public:
    Class_00150440* sub_00150440(int a1, int a2);
    void sub_0014AA60(int, int);
    int m_Field00; // +0x00
};

Class_00150440* Class_00150440::sub_00150440(int a1, int a2)
{
    sub_0014AA60(a1, a2);
    m_Field00 = (int)DAT_00392AF4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00157670 (0x00157670, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00157670 (0x00157670, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045CF2C;
extern "C" int DAT_0045CF30;

void __cdecl sub_00157670(void)
{
    DAT_0045CF2C.sub_0008D4E0(DAT_0045CF30);
}

// ============================================================================
// [VERIFIED] sub_00158840 (0x00158840, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_0040295C[];
extern "C" void* __cdecl sub_00028CF0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_00158840(int a1, int a2)
{
    void* object = sub_00028CF0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_0040295C, 0);
}

// ============================================================================
// [VERIFIED] sub_00159160 (0x00159160, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00216C70 (0x00216C70), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4D0[];
extern "C" const void* __cdecl sub_00023090(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 0 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00159160(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_0038B4D0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_00023090), 1);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001591E0 (0x001591E0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002169F0 (0x002169F0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F0FC[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001591E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_0037F0FC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00159260 (0x00159260, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0039369C[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_00159260(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0039369C;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001592E0 (0x001592E0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003936A4[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001592E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_003936A4;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00159360 (0x00159360, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003936AC[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_00159360(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_003936AC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001593E0 (0x001593E0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002D910 (0x0002D910), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003936B4[];
extern "C" const void* __cdecl sub_0002AAC0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 0 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001593E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_003936B4;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAC0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00159460 (0x00159460, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003936BC[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_00159460(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_003936BC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00159F20 (0x00159F20, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000115B0 (0x000115B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00393840[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00159F20(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_00393840;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00159F90 (0x00159F90, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017A140 (0x0017A140), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00393848[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 3 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00159F90(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_00393848;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0015A970 (0x0015A970, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015A970 (0x0015A970, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_0045DD3C;
extern "C" int DAT_0045DD40;

void __cdecl sub_0015A970(void)
{
    DAT_0045DD3C.sub_0008D4E0(DAT_0045DD40);
}

// ============================================================================
// [VERIFIED] sub_0015DD80 (0x0015DD80, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DD80 (0x0015DD80, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393B6C[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DD80
{
public:
    Class_0015DD80* sub_0015DD80(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DD80* Class_0015DD80::sub_0015DD80(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393B6C;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015DDB0 (0x0015DDB0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DDB0 (0x0015DDB0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393BA8[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DDB0
{
public:
    Class_0015DDB0* sub_0015DDB0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DDB0* Class_0015DDB0::sub_0015DDB0(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393BA8;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015DF00 (0x0015DF00, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DF00 (0x0015DF00, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393BE4[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DF00
{
public:
    Class_0015DF00* sub_0015DF00(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DF00* Class_0015DF00::sub_0015DF00(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393BE4;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015DF30 (0x0015DF30, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DF30 (0x0015DF30, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393C20[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DF30
{
public:
    Class_0015DF30* sub_0015DF30(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DF30* Class_0015DF30::sub_0015DF30(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393C20;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015DF60 (0x0015DF60, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DF60 (0x0015DF60, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393C5C[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DF60
{
public:
    Class_0015DF60* sub_0015DF60(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DF60* Class_0015DF60::sub_0015DF60(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393C5C;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015DF90 (0x0015DF90, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DF90 (0x0015DF90, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393C98[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DF90
{
public:
    Class_0015DF90* sub_0015DF90(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DF90* Class_0015DF90::sub_0015DF90(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393C98;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015DFC0 (0x0015DFC0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DFC0 (0x0015DFC0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393CD4[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DFC0
{
public:
    Class_0015DFC0* sub_0015DFC0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DFC0* Class_0015DFC0::sub_0015DFC0(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393CD4;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015DFF0 (0x0015DFF0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015DFF0 (0x0015DFF0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393D10[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015DFF0
{
public:
    Class_0015DFF0* sub_0015DFF0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015DFF0* Class_0015DFF0::sub_0015DFF0(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393D10;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015E020 (0x0015E020, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E7D0 (0x0017E7D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015E020 (0x0015E020, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393D4C[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015E020
{
public:
    Class_0015E020* sub_0015E020(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

Class_0015E020* Class_0015E020::sub_0015E020(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393D4C;
    m_Field08 = 0;
    m_Field0C = false;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015E050 (0x0015E050, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015E050 (0x0015E050, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393D88[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015E050
{
public:
    Class_0015E050* sub_0015E050(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015E050* Class_0015E050::sub_0015E050(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393D88;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015E110 (0x0015E110, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015E110 (0x0015E110, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393E0C[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015E110
{
public:
    Class_0015E110* sub_0015E110(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015E110* Class_0015E110::sub_0015E110(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393E0C;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_0015E180 (0x0015E180, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0017E770 (0x0017E770), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0015E180 (0x0015E180, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00393E48[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_0015E180
{
public:
    Class_0015E180* sub_0015E180(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_0015E180* Class_0015E180::sub_0015E180(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00393E48;
    m_Field08 = 0;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_00160E30 (0x00160E30, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00160E30 (0x00160E30, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00394134[];
extern "C" void __cdecl sub_0001F660(void);

class Class_00160E30
{
public:
    Class_00160E30* sub_00160E30();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_00160E30* Class_00160E30::sub_00160E30()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00394134;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00160E70 (0x00160E70, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00160E70 (0x00160E70, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039417C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_00160E70
{
public:
    Class_00160E70* sub_00160E70();
    int m_Field00; // +0x00
};

Class_00160E70* Class_00160E70::sub_00160E70()
{
    sub_0001F660();
    m_Field00 = (int)DAT_0039417C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00160E90 (0x00160E90, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00160E90 (0x00160E90, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003941C4[];
extern "C" void __cdecl sub_0001F660(void);

class Class_00160E90
{
public:
    Class_00160E90* sub_00160E90();
    int m_Field00; // +0x00
};

Class_00160E90* Class_00160E90::sub_00160E90()
{
    sub_0001F660();
    m_Field00 = (int)DAT_003941C4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00160EB0 (0x00160EB0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00160EB0 (0x00160EB0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039420C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_00160EB0
{
public:
    Class_00160EB0* sub_00160EB0();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_00160EB0* Class_00160EB0::sub_00160EB0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_0039420C;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00160EF0 (0x00160EF0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD160 (0x000DD160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00160EF0 (0x00160EF0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00394254[];
extern "C" void __cdecl sub_0001F660(void);

class Class_00160EF0
{
public:
    Class_00160EF0* sub_00160EF0();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

Class_00160EF0* Class_00160EF0::sub_00160EF0()
{
    sub_0001F660();
    m_Field00 = (int)DAT_00394254;
    m_Field10 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163380 (0x00163380, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163380 (0x00163380, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DE68[];
extern "C" char DAT_0045DE6C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163380(void)
{
    sub_001FC310((int)DAT_0045DE68, (int)DAT_0045DE6C);
}

// ============================================================================
// [VERIFIED] sub_00163410 (0x00163410, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163410 (0x00163410, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DE70[];
extern "C" char DAT_0045DE74[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163410(void)
{
    sub_001FC310((int)DAT_0045DE70, (int)DAT_0045DE74);
}

// ============================================================================
// [VERIFIED] sub_001634B0 (0x001634B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001634B0 (0x001634B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DE78[];
extern "C" char DAT_0045DE7C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_001634B0(void)
{
    sub_001FC310((int)DAT_0045DE78, (int)DAT_0045DE7C);
}

// ============================================================================
// [VERIFIED] sub_00163550 (0x00163550, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163550 (0x00163550, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DE80[];
extern "C" char DAT_0045DE84[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163550(void)
{
    sub_001FC310((int)DAT_0045DE80, (int)DAT_0045DE84);
}

// ============================================================================
// [VERIFIED] sub_001635B0 (0x001635B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001635B0 (0x001635B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DE88[];
extern "C" char DAT_0045DE8C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_001635B0(void)
{
    sub_001FC310((int)DAT_0045DE88, (int)DAT_0045DE8C);
}

// ============================================================================
// [VERIFIED] sub_00163630 (0x00163630, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163630 (0x00163630, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DE90[];
extern "C" char DAT_0045DE94[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163630(void)
{
    sub_001FC310((int)DAT_0045DE90, (int)DAT_0045DE94);
}

// ============================================================================
// [VERIFIED] sub_00163660 (0x00163660, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001852A0 (0x001852A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163660 (0x00163660, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00394E34[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163660
{
public:
    Class_00163660* sub_00163660();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    Field14 m_Field18; // +0x18
};

Class_00163660* Class_00163660::sub_00163660()
{
    sub_000205E0();
    m_Field00 = (int)DAT_00394E34;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_001636C0 (0x001636C0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001636C0 (0x001636C0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DE98[];
extern "C" char DAT_0045DE9C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_001636C0(void)
{
    sub_001FC310((int)DAT_0045DE98, (int)DAT_0045DE9C);
}

// ============================================================================
// [VERIFIED] sub_001636F0 (0x001636F0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185330 (0x00185330), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001636F0 (0x001636F0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00394EBC[];
extern "C" void __cdecl sub_000205E0(void);

class Class_001636F0
{
public:
    Class_001636F0* sub_001636F0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    bool m_Field18; // +0x18
};

Class_001636F0* Class_001636F0::sub_001636F0()
{
    sub_000205E0();
    m_Field00 = (int)DAT_00394EBC;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18 = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163750 (0x00163750, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163750 (0x00163750, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEA0[];
extern "C" char DAT_0045DEA4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163750(void)
{
    sub_001FC310((int)DAT_0045DEA0, (int)DAT_0045DEA4);
}

// ============================================================================
// [VERIFIED] sub_00163780 (0x00163780, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001852A0 (0x001852A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163780 (0x00163780, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00394F44[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163780
{
public:
    Class_00163780* sub_00163780();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    Field14 m_Field18; // +0x18
};

Class_00163780* Class_00163780::sub_00163780()
{
    sub_000205E0();
    m_Field00 = (int)DAT_00394F44;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_001637E0 (0x001637E0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001637E0 (0x001637E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEA8[];
extern "C" char DAT_0045DEAC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_001637E0(void)
{
    sub_001FC310((int)DAT_0045DEA8, (int)DAT_0045DEAC);
}

// ============================================================================
// [VERIFIED] sub_00163810 (0x00163810, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185330 (0x00185330), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163810 (0x00163810, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00394FCC[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163810
{
public:
    Class_00163810* sub_00163810();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    bool m_Field18; // +0x18
};

Class_00163810* Class_00163810::sub_00163810()
{
    sub_000205E0();
    m_Field00 = (int)DAT_00394FCC;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18 = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163870 (0x00163870, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163870 (0x00163870, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEB0[];
extern "C" char DAT_0045DEB4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163870(void)
{
    sub_001FC310((int)DAT_0045DEB0, (int)DAT_0045DEB4);
}

// ============================================================================
// [VERIFIED] sub_00163920 (0x00163920, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163920 (0x00163920, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEB8[];
extern "C" char DAT_0045DEBC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163920(void)
{
    sub_001FC310((int)DAT_0045DEB8, (int)DAT_0045DEBC);
}

// ============================================================================
// [VERIFIED] sub_00163950 (0x00163950, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001852A0 (0x001852A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163950 (0x00163950, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_003950DC[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163950
{
public:
    Class_00163950* sub_00163950();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    Field14 m_Field18; // +0x18
};

Class_00163950* Class_00163950::sub_00163950()
{
    sub_000205E0();
    m_Field00 = (int)DAT_003950DC;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_001639B0 (0x001639B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001639B0 (0x001639B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEC0[];
extern "C" char DAT_0045DEC4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_001639B0(void)
{
    sub_001FC310((int)DAT_0045DEC0, (int)DAT_0045DEC4);
}

// ============================================================================
// [VERIFIED] sub_001639E0 (0x001639E0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001852A0 (0x001852A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001639E0 (0x001639E0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00395164[];
extern "C" void __cdecl sub_000205E0(void);

class Class_001639E0
{
public:
    Class_001639E0* sub_001639E0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    Field14 m_Field18; // +0x18
};

Class_001639E0* Class_001639E0::sub_001639E0()
{
    sub_000205E0();
    m_Field00 = (int)DAT_00395164;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163A40 (0x00163A40, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163A40 (0x00163A40, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEC8[];
extern "C" char DAT_0045DECC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163A40(void)
{
    sub_001FC310((int)DAT_0045DEC8, (int)DAT_0045DECC);
}

// ============================================================================
// [VERIFIED] sub_00163AD0 (0x00163AD0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163AD0 (0x00163AD0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DED0[];
extern "C" char DAT_0045DED4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163AD0(void)
{
    sub_001FC310((int)DAT_0045DED0, (int)DAT_0045DED4);
}

// ============================================================================
// [VERIFIED] sub_00163B30 (0x00163B30, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163B30 (0x00163B30, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DED8[];
extern "C" char DAT_0045DEDC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163B30(void)
{
    sub_001FC310((int)DAT_0045DED8, (int)DAT_0045DEDC);
}

// ============================================================================
// [VERIFIED] sub_00163B60 (0x00163B60, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001852A0 (0x001852A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163B60 (0x00163B60, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_003952FC[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163B60
{
public:
    Class_00163B60* sub_00163B60();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    Field14 m_Field18; // +0x18
};

Class_00163B60* Class_00163B60::sub_00163B60()
{
    sub_000205E0();
    m_Field00 = (int)DAT_003952FC;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163BC0 (0x00163BC0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163BC0 (0x00163BC0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEE0[];
extern "C" char DAT_0045DEE4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163BC0(void)
{
    sub_001FC310((int)DAT_0045DEE0, (int)DAT_0045DEE4);
}

// ============================================================================
// [VERIFIED] sub_00163C70 (0x00163C70, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163C70 (0x00163C70, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEE8[];
extern "C" char DAT_0045DEEC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163C70(void)
{
    sub_001FC310((int)DAT_0045DEE8, (int)DAT_0045DEEC);
}

// ============================================================================
// [VERIFIED] sub_00163D10 (0x00163D10, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163D10 (0x00163D10, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEF0[];
extern "C" char DAT_0045DEF4[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163D10(void)
{
    sub_001FC310((int)DAT_0045DEF0, (int)DAT_0045DEF4);
}

// ============================================================================
// [VERIFIED] sub_00163D40 (0x00163D40, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185980 (0x00185980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163D40 (0x00163D40, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00395494[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163D40
{
public:
    Class_00163D40* sub_00163D40();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    bool m_Field14; // +0x14
    char m_pad15[0x3F];
    bool m_Field54; // +0x54
};

Class_00163D40* Class_00163D40::sub_00163D40()
{
    sub_000205E0();
    m_Field14 = false;
    m_Field54 = false;
    m_Field00 = (int)DAT_00395494;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163DB0 (0x00163DB0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163DB0 (0x00163DB0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DEF8[];
extern "C" char DAT_0045DEFC[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163DB0(void)
{
    sub_001FC310((int)DAT_0045DEF8, (int)DAT_0045DEFC);
}

// ============================================================================
// [VERIFIED] sub_00163DE0 (0x00163DE0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185A70 (0x00185A70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163DE0 (0x00163DE0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_0039551C[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163DE0
{
public:
    Class_00163DE0* sub_00163DE0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

Class_00163DE0* Class_00163DE0::sub_00163DE0()
{
    sub_000205E0();
    m_Field00 = (int)DAT_0039551C;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163E00 (0x00163E00, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163E00 (0x00163E00, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DF00[];
extern "C" char DAT_0045DF04[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163E00(void)
{
    sub_001FC310((int)DAT_0045DF00, (int)DAT_0045DF04);
}

// ============================================================================
// [VERIFIED] sub_00163E30 (0x00163E30, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185A70 (0x00185A70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163E30 (0x00163E30, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_003955A4[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163E30
{
public:
    Class_00163E30* sub_00163E30();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

Class_00163E30* Class_00163E30::sub_00163E30()
{
    sub_000205E0();
    m_Field00 = (int)DAT_003955A4;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163E50 (0x00163E50, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163E50 (0x00163E50, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DF08[];
extern "C" char DAT_0045DF0C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163E50(void)
{
    sub_001FC310((int)DAT_0045DF08, (int)DAT_0045DF0C);
}

// ============================================================================
// [VERIFIED] sub_00163E80 (0x00163E80, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185A70 (0x00185A70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163E80 (0x00163E80, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_0039562C[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163E80
{
public:
    Class_00163E80* sub_00163E80();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

Class_00163E80* Class_00163E80::sub_00163E80()
{
    sub_000205E0();
    m_Field00 = (int)DAT_0039562C;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163EC0 (0x00163EC0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163EC0 (0x00163EC0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DF10[];
extern "C" char DAT_0045DF14[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163EC0(void)
{
    sub_001FC310((int)DAT_0045DF10, (int)DAT_0045DF14);
}

// ============================================================================
// [VERIFIED] sub_00163EF0 (0x00163EF0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163EF0 (0x00163EF0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DF18[];
extern "C" char DAT_0045DF1C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163EF0(void)
{
    sub_001FC310((int)DAT_0045DF18, (int)DAT_0045DF1C);
}

// ============================================================================
// [VERIFIED] sub_00163F20 (0x00163F20, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185BE0 (0x00185BE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163F20 (0x00163F20, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039573C[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163F20
{
public:
    Class_00163F20* sub_00163F20();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    bool m_Field14; // +0x14
};

Class_00163F20* Class_00163F20::sub_00163F20()
{
    sub_000205E0();
    m_Field00 = (int)DAT_0039573C;
    m_Field14 = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00163F70 (0x00163F70, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163F70 (0x00163F70, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DF20[];
extern "C" char DAT_0045DF24[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00163F70(void)
{
    sub_001FC310((int)DAT_0045DF20, (int)DAT_0045DF24);
}

// ============================================================================
// [VERIFIED] sub_00163FD0 (0x00163FD0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00163FD0 (0x00163FD0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039584C[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163FD0
{
public:
    Class_00163FD0* sub_00163FD0();
    int m_Field00; // +0x00
};

Class_00163FD0* Class_00163FD0::sub_00163FD0()
{
    sub_000205E0();
    m_Field00 = (int)DAT_0039584C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00164020 (0x00164020, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00164020 (0x00164020, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DF28[];
extern "C" char DAT_0045DF2C[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00164020(void)
{
    sub_001FC310((int)DAT_0045DF28, (int)DAT_0045DF2C);
}

// ============================================================================
// [VERIFIED] sub_00164080 (0x00164080, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00164080 (0x00164080, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045DF30[];
extern "C" char DAT_0045DF34[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_00164080(void)
{
    sub_001FC310((int)DAT_0045DF30, (int)DAT_0045DF34);
}

// ============================================================================
// [VERIFIED] sub_001640B0 (0x001640B0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185BE0 (0x00185BE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001640B0 (0x001640B0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039595C[];
extern "C" void __cdecl sub_000205E0(void);

class Class_001640B0
{
public:
    Class_001640B0* sub_001640B0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    bool m_Field14; // +0x14
};

Class_001640B0* Class_001640B0::sub_001640B0()
{
    sub_000205E0();
    m_Field00 = (int)DAT_0039595C;
    m_Field14 = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00164E90 (0x00164E90, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E7440 (0x000E7440), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00164E90 (0x00164E90, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC360(int);
};

extern "C" char DAT_00395E08[];
extern "C" char DAT_00395D38[];
extern "C" char DAT_0045DF30[];
extern "C" int DAT_0045DF34;
extern "C" char sub_00163370[];
extern "C" int __cdecl sub_00025120(int);
extern "C" int __cdecl sub_001FC2C0(int, int, int);

int __cdecl sub_00164E90(void)
{
    int local_4, r_eax;

    r_eax = DAT_0045DF34;
    if (!r_eax) {
        r_eax = sub_00025120(12);
        if (r_eax) {
            ((Object*)r_eax)->sub_001FC360((int)DAT_00395E08);
            *(int*)r_eax = (int)DAT_00395D38;
            *(int*)(r_eax + 8) = (int)sub_00163370;
            local_4 = r_eax;
        } else {
            local_4 = 0;
        }
        r_eax = (int)(&local_4);
        r_eax = sub_001FC2C0((int)DAT_0045DF30, r_eax, 1);
    }
    DAT_0045DF34 += 1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00165C20 (0x00165C20, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E7440 (0x000E7440), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00165C20 (0x00165C20, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC4F0(int);
};

extern "C" char DAT_00394374[];
extern "C" char DAT_00395FF4[];
extern "C" char DAT_0045DEF8[];
extern "C" int DAT_0045DEFC;
extern "C" char sub_0015DD70[];
extern "C" int __cdecl sub_00025120(int);
extern "C" int __cdecl sub_001FC2C0(int, int, int);

int __cdecl sub_00165C20(void)
{
    int local_4, r_eax;

    r_eax = DAT_0045DEFC;
    if (!r_eax) {
        r_eax = sub_00025120(12);
        if (r_eax) {
            ((Object*)r_eax)->sub_001FC4F0((int)DAT_00394374);
            *(int*)r_eax = (int)DAT_00395FF4;
            *(int*)(r_eax + 8) = (int)sub_0015DD70;
            local_4 = r_eax;
        } else {
            local_4 = 0;
        }
        r_eax = (int)(&local_4);
        r_eax = sub_001FC2C0((int)DAT_0045DEF8, r_eax, 1);
    }
    DAT_0045DEFC += 1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00165C80 (0x00165C80, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E7440 (0x000E7440), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00165C80 (0x00165C80, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC4F0(int);
};

extern "C" char DAT_0037DBE0[];
extern "C" char DAT_00396014[];
extern "C" char DAT_0045DF00[];
extern "C" int DAT_0045DF04;
extern "C" char sub_0015DD70[];
extern "C" int __cdecl sub_00025120(int);
extern "C" int __cdecl sub_001FC2C0(int, int, int);

int __cdecl sub_00165C80(void)
{
    int local_4, r_eax;

    r_eax = DAT_0045DF04;
    if (!r_eax) {
        r_eax = sub_00025120(12);
        if (r_eax) {
            ((Object*)r_eax)->sub_001FC4F0((int)DAT_0037DBE0);
            *(int*)r_eax = (int)DAT_00396014;
            *(int*)(r_eax + 8) = (int)sub_0015DD70;
            local_4 = r_eax;
        } else {
            local_4 = 0;
        }
        r_eax = (int)(&local_4);
        r_eax = sub_001FC2C0((int)DAT_0045DF00, r_eax, 1);
    }
    DAT_0045DF04 += 1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00165CE0 (0x00165CE0, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E7440 (0x000E7440), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00165CE0 (0x00165CE0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC4F0(int);
};

extern "C" char DAT_00395DE4[];
extern "C" char DAT_00396034[];
extern "C" char DAT_0045DF08[];
extern "C" int DAT_0045DF0C;
extern "C" char sub_0015DD70[];
extern "C" int __cdecl sub_00025120(int);
extern "C" int __cdecl sub_001FC2C0(int, int, int);

int __cdecl sub_00165CE0(void)
{
    int local_4, r_eax;

    r_eax = DAT_0045DF0C;
    if (!r_eax) {
        r_eax = sub_00025120(12);
        if (r_eax) {
            ((Object*)r_eax)->sub_001FC4F0((int)DAT_00395DE4);
            *(int*)r_eax = (int)DAT_00396034;
            *(int*)(r_eax + 8) = (int)sub_0015DD70;
            local_4 = r_eax;
        } else {
            local_4 = 0;
        }
        r_eax = (int)(&local_4);
        r_eax = sub_001FC2C0((int)DAT_0045DF08, r_eax, 1);
    }
    DAT_0045DF0C += 1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_00166750 (0x00166750, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00166750 (0x00166750, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000B79E0();
};

extern "C" char DAT_0039627C[];

class Class_00166750
{
public:
    Class_00166750* sub_00166750(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_00166750* Class_00166750::sub_00166750(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_0039627C;
    m_Field24.sub_000B79E0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001668A0 (0x001668A0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000995B0 (0x000995B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003962FC[];
extern "C" const void* __cdecl sub_0002AAC0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001668A0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_003962FC;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAC0), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_00166910 (0x00166910, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E2C0 (0x0002E2C0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_00396304[];
extern "C" const void* __cdecl sub_0002AAC0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_00166910(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_00396304;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAC0), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_0016E0D0 (0x0016E0D0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0016E0D0 (0x0016E0D0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00397D9C[];

class Class_0016E0D0
{
public:
    void sub_0016E0D0();
    int m_Field00; // +0x00
};

void Class_0016E0D0::sub_0016E0D0()
{
    m_Field00 = (int)DAT_00397D9C;
}

// ============================================================================
// [VERIFIED] sub_0016E130 (0x0016E130, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0016E130 (0x0016E130, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00397DA4[];
extern "C" void __cdecl sub_00029C00(void);

class Class_0016E130
{
public:
    void sub_0016E130();
    int m_Field00; // +0x00
};

void Class_0016E130::sub_0016E130()
{
    m_Field00 = (int)DAT_00397DA4;
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_0016FA10 (0x0016FA10, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0016FA10 (0x0016FA10, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003985F8[];

class Class_0016FA10
{
public:
    void sub_0016FA10();
    int m_Field00; // +0x00
};

void Class_0016FA10::sub_0016FA10()
{
    m_Field00 = (int)DAT_003985F8;
}

// ============================================================================
// [VERIFIED] sub_001758B0 (0x001758B0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001758B0 (0x001758B0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0045E820;

bool __cdecl sub_001758B0(bool a1)
{
    DAT_0045E820 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0017BA20 (0x0017BA20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0017BA20 (0x0017BA20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045E824;

int __cdecl sub_0017BA20(void)
{
    return DAT_0045E824;
}

// ============================================================================
// [VERIFIED] sub_0017E3D0 (0x0017E3D0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E680 (0x0001E680), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0017E3D0 (0x0017E3D0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0045E866;

void __cdecl sub_0017E3D0(void)
{
    DAT_0045E866 = true;
}

// ============================================================================
// [VERIFIED] sub_0017E3E0 (0x0017E3E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0017E3E0 (0x0017E3E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045E860;

int __cdecl sub_0017E3E0(void)
{
    return DAT_0045E860;
}

// ============================================================================
// [VERIFIED] sub_0017E3F0 (0x0017E3F0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001A8A80 (0x001A8A80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0017E3F0 (0x0017E3F0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0040FAB4;

bool __cdecl sub_0017E3F0(void)
{
    return DAT_0040FAB4 != 1;
}

// ============================================================================
// [VERIFIED] sub_00181390 (0x00181390, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00181390 (0x00181390, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039B264[];
extern "C" void __cdecl sub_00029C00(void);

class Class_00181390
{
public:
    void sub_00181390();
    int m_Field00; // +0x00
};

void Class_00181390::sub_00181390()
{
    m_Field00 = (int)DAT_0039B264;
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_0018BF60 (0x0018BF60, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00119F60 (0x00119F60), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038BBD0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0018BF60(int a1, int a2, int a3, int a4, int unused, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038BBD0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0018EBC0 (0x0018EBC0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136B30 (0x00136B30), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0039DAB4[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0018EBC0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(7);
        *(void**)object = DAT_0039DAB4;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0018EC40 (0x0018EC40, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136930 (0x00136930), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0039DABC[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_0018EC40(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_0039DABC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_0018ED90 (0x0018ED90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0018ED90 (0x0018ED90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045FF5C;

int __cdecl sub_0018ED90(void)
{
    return DAT_0045FF5C;
}

// ============================================================================
// [VERIFIED] sub_00190490 (0x00190490, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00190490 (0x00190490, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0045FF74;

bool __cdecl sub_00190490(bool a1)
{
    DAT_0045FF74 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_001920D0 (0x001920D0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002D910 (0x0002D910), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0039E104[];
extern "C" const void* __cdecl sub_0005CC70(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 0 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001920D0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_0039E104;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0005CC70), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00192630 (0x00192630, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_004126B8[];
extern "C" void* __cdecl sub_00028CF0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_00192630(int a1, int a2)
{
    void* object = sub_00028CF0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_004126B8, 0);
}

// ============================================================================
// [VERIFIED] sub_001935F0 (0x001935F0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002D910 (0x0002D910), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0039E298[];
extern "C" const void* __cdecl sub_0005CDD0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 0 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001935F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_0039E298;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0005CDD0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_00193880 (0x00193880, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00193880 (0x00193880, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00460118;

int __cdecl sub_00193880(void)
{
    return DAT_00460118;
}

// ============================================================================
// [VERIFIED] sub_00194160 (0x00194160, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011FD50 (0x0011FD50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00194160 (0x00194160, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E580[];
extern "C" void __cdecl sub_0016F9D0(void);

class Class_00194160
{
public:
    Class_00194160* sub_00194160(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Class_00194160* Class_00194160::sub_00194160(int a1)
{
    sub_0016F9D0();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0039E580;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00197D90 (0x00197D90, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00197D90 (0x00197D90, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_00460220;
extern "C" int DAT_00460224;

void __cdecl sub_00197D90(void)
{
    DAT_00460220.sub_0008D4E0(DAT_00460224);
}

// ============================================================================
// [VERIFIED] sub_00198E20 (0x00198E20, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_00413A4C[];
extern "C" void* __cdecl sub_00028CF0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_00198E20(int a1, int a2)
{
    void* object = sub_00028CF0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_00413A4C, 0);
}

// ============================================================================
// [VERIFIED] sub_00198E50 (0x00198E50, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00018F30 (0x00018F30), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003F45D8[];
extern "C" char DAT_00413A74[];
extern "C" void* __cdecl sub_00028CF0(int a1, int a2);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Finds an object and casts it to the wanted type (null when it is something else).
void* __cdecl sub_00198E50(int a1, int a2)
{
    void* object = sub_00028CF0(a1, a2);
    return sub_002C92F8(object, 0, DAT_003F45D8, DAT_00413A74, 0);
}

// ============================================================================
// [VERIFIED] sub_0019BD40 (0x0019BD40, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019BD40 (0x0019BD40, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004605C8;

int __cdecl sub_0019BD40(void)
{
    return DAT_004605C8;
}

// ============================================================================
// [VERIFIED] sub_0019BDB0 (0x0019BDB0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001D38B0 (0x001D38B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019BDB0 (0x0019BDB0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00040D80(int);

void __stdcall sub_0019BDB0(int a1)
{
    sub_00040D80(a1);
}

// ============================================================================
// [VERIFIED] sub_0019BDC0 (0x0019BDC0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001D38B0 (0x001D38B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019BDC0 (0x0019BDC0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00040D10(int);

void __stdcall sub_0019BDC0(int a1)
{
    sub_00040D10(a1);
}

// ============================================================================
// [VERIFIED] sub_0019BDE0 (0x0019BDE0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001D3900 (0x001D3900), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019BDE0 (0x0019BDE0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00042CA0(int, int, int);

void __stdcall sub_0019BDE0(int a1, int a2, int a3)
{
    sub_00042CA0(a1, a2, a3);
}

// ============================================================================
// [VERIFIED] sub_0019BE00 (0x0019BE00, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001D3900 (0x001D3900), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019BE00 (0x0019BE00, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00040CF0(int, int, int);

void __stdcall sub_0019BE00(int a1, int a2, int a3)
{
    sub_00040CF0(a1, a2, a3);
}

// ============================================================================
// [VERIFIED] sub_0019C1C0 (0x0019C1C0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019C1C0 (0x0019C1C0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0041489C;

bool __cdecl sub_0019C1C0(bool a1)
{
    DAT_0041489C = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0019D9A0 (0x0019D9A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019D9A0 (0x0019D9A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0046063C;

bool __cdecl sub_0019D9A0(void)
{
    return DAT_0046063C;
}

// ============================================================================
// [VERIFIED] sub_0019DA50 (0x0019DA50, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0019DA50 (0x0019DA50, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0046064C;

bool __cdecl sub_0019DA50(bool a1)
{
    DAT_0046064C = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0019F0B0 (0x0019F0B0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000995B0 (0x000995B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003A0B70[];
extern "C" const void* __cdecl sub_0002AAB0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_0019F0B0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_003A0B70;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAB0), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_001A8140 (0x001A8140, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047E50 (0x00047E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001A8140 (0x001A8140, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E7F40();
};

extern "C" int DAT_00462ED0;

void __cdecl sub_001A8140(void)
{
    ((Object*)DAT_00462ED0)->sub_001E7F40();
}

// ============================================================================
// [VERIFIED] sub_001AA010 (0x001AA010, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001E3420 (0x001E3420), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001AA010 (0x001AA010, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E6E80(int);
};

extern "C" char DAT_003A1FAC[];
extern "C" int DAT_00462ED0;

class Class_001AA010
{
public:
    void sub_001AA010();
    void sub_00026AD0();
    int m_Field00; // +0x00
};

void Class_001AA010::sub_001AA010()
{
    m_Field00 = (int)DAT_003A1FAC;
    ((Object*)DAT_00462ED0)->sub_001E6E80((int)this);
    sub_00026AD0();
}

// ============================================================================
// [VERIFIED] sub_001AA8E0 (0x001AA8E0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001AA8E0 (0x001AA8E0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00460AF8;

int __cdecl sub_001AA8E0(int a1)
{
    DAT_00460AF8 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_001AEAC0 (0x001AEAC0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001369B0 (0x001369B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038BBE8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001AEAC0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_0038BBE8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001AEB40 (0x001AEB40, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136EB0 (0x00136EB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003A286C[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001AEB40(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(5);
        *(void**)object = DAT_003A286C;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001AEBC0 (0x001AEBC0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038BBF0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001AEBC0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_0038BBF0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001B0CB0 (0x001B0CB0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001E3420 (0x001E3420), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001B0CB0 (0x001B0CB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E6DD0(int);
};

extern "C" char DAT_003A2B6C[];
extern "C" int DAT_00462ED0;

class Class_001B0CB0
{
public:
    void sub_001B0CB0();
    void sub_000277E0();
    int m_Field00; // +0x00
};

void Class_001B0CB0::sub_001B0CB0()
{
    m_Field00 = (int)DAT_003A2B6C;
    ((Object*)DAT_00462ED0)->sub_001E6DD0((int)this);
    sub_000277E0();
}

// ============================================================================
// [VERIFIED] sub_001B1080 (0x001B1080, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001EA570 (0x001EA570), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001B1080 (0x001B1080, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A2C94[];

class Class_001B1080
{
public:
    Class_001B1080* sub_001B1080(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

Class_001B1080* Class_001B1080::sub_001B1080(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A2C94;
    m_Field20 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001B3F00 (0x001B3F00, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4C0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001B3F00(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4C0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001B3F80 (0x001B3F80, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003A3708[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001B3F80(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_003A3708;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001B4000 (0x001B4000, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BF20 (0x0011BF20), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003A3710[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001B4000(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(3);
        *(void**)object = DAT_003A3710;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001B4CA0 (0x001B4CA0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001EEC80 (0x001EEC80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001B4CA0 (0x001B4CA0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A38EC[];

class Class_001B4CA0
{
public:
    Class_001B4CA0* sub_001B4CA0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
};

Class_001B4CA0* Class_001B4CA0::sub_001B4CA0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field00 = (int)DAT_003A38EC;
    m_Field22 = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001B5E00 (0x001B5E00, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001B5E00 (0x001B5E00, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_00462EA4;
extern "C" int DAT_00462EA8;

void __cdecl sub_001B5E00(void)
{
    DAT_00462EA4.sub_0008D4E0(DAT_00462EA8);
}

// ============================================================================
// [VERIFIED] sub_001B7940 (0x001B7940, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001F2040 (0x001F2040), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001B7940 (0x001B7940, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0007D010();
};

extern "C" char DAT_003A3C54[];

class Class_001B7940
{
public:
    Class_001B7940* sub_001B7940(int a1, int a2);
    void sub_001B4CA0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

Class_001B7940* Class_001B7940::sub_001B7940(int a1, int a2)
{
    sub_001B4CA0(a1, a2);
    m_Field00 = (int)DAT_003A3C54;
    m_Field24.sub_0007D010();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001B90B0 (0x001B90B0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00163C80 (0x00163C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001B90B0 (0x001B90B0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0();
};

class Class_001B90B0
{
public:
    void sub_001B90B0();
};

void Class_001B90B0::sub_001B90B0()
{
    ((Object*)(int)this + 304)->sub_0008D4C0();
}

// ============================================================================
// [VERIFIED] sub_001BB7D0 (0x001BB7D0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001BB7D0 (0x001BB7D0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_004615B0;
extern "C" int DAT_004615B4;

void __cdecl sub_001BB7D0(void)
{
    DAT_004615B0.sub_0008D4E0(DAT_004615B4);
}

// ============================================================================
// [VERIFIED] sub_001BD8D0 (0x001BD8D0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00155790 (0x00155790), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001BD8D0 (0x001BD8D0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4E0(int);
};

extern "C" Object DAT_004615EC;
extern "C" int DAT_004615F0;

void __cdecl sub_001BD8D0(void)
{
    DAT_004615EC.sub_0008D4E0(DAT_004615F0);
}

// ============================================================================
// [VERIFIED] sub_001BFA00 (0x001BFA00, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001BFA00 (0x001BFA00, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_000CA600();
};

extern "C" char DAT_003A465C[];

class Class_001BFA00
{
public:
    Class_001BFA00* sub_001BFA00(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001BFA00* Class_001BFA00::sub_001BFA00(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A465C;
    m_Field20.sub_000CA600();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001BFD20 (0x001BFD20, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FB200 (0x001FB200), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001BFD20 (0x001BFD20, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A47F4[];

class Class_001BFD20
{
public:
    Class_001BFD20* sub_001BFD20(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    int m_Field24; // +0x24
};

Class_001BFD20* Class_001BFD20::sub_001BFD20(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field22 = false;
    m_Field24 = 0;
    m_Field20 = 65535;
    m_Field00 = (int)DAT_003A47F4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C0BB0 (0x001C0BB0, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C0BB0 (0x001C0BB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0007CEF0();
};

extern "C" char DAT_003A4A9C[];

class Class_001C0BB0
{
public:
    Class_001C0BB0* sub_001C0BB0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_001C0BB0* Class_001C0BB0::sub_001C0BB0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A4A9C;
    m_Field24.sub_0007CEF0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C0C40 (0x001C0C40, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C0C40 (0x001C0C40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000AABF0();
};

extern "C" char DAT_003A4B0C[];

class Class_001C0C40
{
public:
    Class_001C0C40* sub_001C0C40(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_001C0C40* Class_001C0C40::sub_001C0C40(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A4B0C;
    m_Field24.sub_000AABF0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C0D50 (0x001C0D50, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FC260 (0x001FC260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C0D50 (0x001C0D50, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4B7C[];

class Class_001C0D50
{
public:
    Class_001C0D50* sub_001C0D50(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

Class_001C0D50* Class_001C0D50::sub_001C0D50(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field22 = false;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field20 = 65535;
    m_Field00 = (int)DAT_003A4B7C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C3970 (0x001C3970, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FC260 (0x001FC260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C3970 (0x001C3970, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A50E4[];

class Class_001C3970
{
public:
    Class_001C3970* sub_001C3970(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

Class_001C3970* Class_001C3970::sub_001C3970(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field22 = false;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field20 = 65535;
    m_Field00 = (int)DAT_003A50E4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C3E10 (0x001C3E10, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C3E10 (0x001C3E10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009B350();
};

extern "C" char DAT_003A5274[];

class Class_001C3E10
{
public:
    Class_001C3E10* sub_001C3E10(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_001C3E10* Class_001C3E10::sub_001C3E10(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A5274;
    m_Field24.sub_0009B350();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C3E80 (0x001C3E80, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00034FB0 (0x00034FB0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C3E80 (0x001C3E80, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041AAA8[];

int __cdecl sub_001C3E80(int a1)
{
    return DAT_0041AAA8[a1];
}

// ============================================================================
// [VERIFIED] sub_001C4A40 (0x001C4A40, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200020 (0x00200020), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C4A40 (0x001C4A40, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A56B4[];

class Class_001C4A40
{
public:
    Class_001C4A40* sub_001C4A40(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
};

Class_001C4A40* Class_001C4A40::sub_001C4A40(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A56B4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C5700 (0x001C5700, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C5700 (0x001C5700, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009E030();
};

extern "C" char DAT_003A5A7C[];

class Class_001C5700
{
public:
    Class_001C5700* sub_001C5700(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_001C5700* Class_001C5700::sub_001C5700(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A5A7C;
    m_Field24.sub_0009E030();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C5850 (0x001C5850, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C5850 (0x001C5850, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_00092680();
};

extern "C" char DAT_003A5B64[];

class Class_001C5850
{
public:
    Class_001C5850* sub_001C5850(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001C5850* Class_001C5850::sub_001C5850(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A5B64;
    m_Field20.sub_00092680();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001C58E0 (0x001C58E0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_0041B11C[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001C58E0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_0041B11C, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001C5960 (0x001C5960, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_0041AF80[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001C5960(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_0041AF80, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001C59E0 (0x001C59E0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_0041B0F4[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001C59E0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_0041B0F4, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001C6140 (0x001C6140, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001C6140 (0x001C6140, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5D84[];

class Class_001C6140
{
public:
    Class_001C6140* sub_001C6140(int a1, int a2);
    void sub_001D1220(int, int);
    int m_Field00; // +0x00
};

Class_001C6140* Class_001C6140::sub_001C6140(int a1, int a2)
{
    sub_001D1220(a1, a2);
    m_Field00 = (int)DAT_003A5D84;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D0F20 (0x001D0F20, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200020 (0x00200020), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D0F20 (0x001D0F20, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A6E0C[];

class Class_001D0F20
{
public:
    Class_001D0F20* sub_001D0F20(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
};

Class_001D0F20* Class_001D0F20::sub_001D0F20(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A6E0C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D0FB0 (0x001D0FB0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D0FB0 (0x001D0FB0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009B0D0();
};

extern "C" char DAT_003A6EF4[];

class Class_001D0FB0
{
public:
    Class_001D0FB0* sub_001D0FB0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D0FB0* Class_001D0FB0::sub_001D0FB0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A6EF4;
    m_Field20.sub_0009B0D0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D1600 (0x001D1600, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D1600 (0x001D1600, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009AE70();
};

extern "C" char DAT_003A6FDC[];

class Class_001D1600
{
public:
    Class_001D1600* sub_001D1600(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D1600* Class_001D1600::sub_001D1600(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A6FDC;
    m_Field20.sub_0009AE70();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D1660 (0x001D1660, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D1660 (0x001D1660, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009E3E0();
};

extern "C" char DAT_003A704C[];

class Class_001D1660
{
public:
    Class_001D1660* sub_001D1660(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D1660* Class_001D1660::sub_001D1660(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A704C;
    m_Field20.sub_0009E3E0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D1790 (0x001D1790, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D1790 (0x001D1790, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009BA70();
};

extern "C" char DAT_003A70BC[];

class Class_001D1790
{
public:
    Class_001D1790* sub_001D1790(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_001D1790* Class_001D1790::sub_001D1790(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A70BC;
    m_Field24.sub_0009BA70();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D1890 (0x001D1890, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D1890 (0x001D1890, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009ACD0();
};

extern "C" char DAT_003A71B4[];

class Class_001D1890
{
public:
    Class_001D1890* sub_001D1890(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D1890* Class_001D1890::sub_001D1890(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A71B4;
    m_Field20.sub_0009ACD0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D18F0 (0x001D18F0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D18F0 (0x001D18F0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009D260();
};

extern "C" char DAT_003A7224[];

class Class_001D18F0
{
public:
    Class_001D18F0* sub_001D18F0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D18F0* Class_001D18F0::sub_001D18F0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A7224;
    m_Field20.sub_0009D260();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D1950 (0x001D1950, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D1950 (0x001D1950, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009DB50();
};

extern "C" char DAT_003A7294[];

class Class_001D1950
{
public:
    Class_001D1950* sub_001D1950(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D1950* Class_001D1950::sub_001D1950(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A7294;
    m_Field20.sub_0009DB50();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D19B0 (0x001D19B0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D19B0 (0x001D19B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009B210();
};

extern "C" char DAT_003A7304[];

class Class_001D19B0
{
public:
    Class_001D19B0* sub_001D19B0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D19B0* Class_001D19B0::sub_001D19B0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A7304;
    m_Field20.sub_0009B210();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D19F0 (0x001D19F0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D19F0 (0x001D19F0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009B170();
};

extern "C" char DAT_003A7374[];

class Class_001D19F0
{
public:
    Class_001D19F0* sub_001D19F0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D19F0* Class_001D19F0::sub_001D19F0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A7374;
    m_Field20.sub_0009B170();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D1A60 (0x001D1A60, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D1A60 (0x001D1A60, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009E190();
};

extern "C" char DAT_003A73E4[];

class Class_001D1A60
{
public:
    Class_001D1A60* sub_001D1A60(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D1A60* Class_001D1A60::sub_001D1A60(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A73E4;
    m_Field20.sub_0009E190();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D1AC0 (0x001D1AC0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D1AC0 (0x001D1AC0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037F29C[];
extern "C" void __cdecl sub_00029C00(void);

class Class_001D1AC0
{
public:
    void sub_001D1AC0();
    int m_Field00; // +0x00
};

void Class_001D1AC0::sub_001D1AC0()
{
    m_Field00 = (int)DAT_0037F29C;
    sub_00029C00();
}

// ============================================================================
// [VERIFIED] sub_001D1B90 (0x001D1B90, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424B38[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D1B90(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424B38, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D1C10 (0x001D1C10, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424B60[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D1C10(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424B60, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D1C90 (0x001D1C90, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424B8C[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D1C90(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424B8C, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D1D10 (0x001D1D10, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424BBC[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D1D10(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424BBC, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D1D90 (0x001D1D90, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424C14[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D1D90(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424C14, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D2140 (0x001D2140, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D2140 (0x001D2140, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009DAB0();
};

extern "C" char DAT_003A773C[];

class Class_001D2140
{
public:
    Class_001D2140* sub_001D2140(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D2140* Class_001D2140::sub_001D2140(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A773C;
    m_Field20.sub_0009DAB0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D2340 (0x001D2340, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D2340 (0x001D2340, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_00097E90();
};

extern "C" char DAT_003A7AC4[];

class Class_001D2340
{
public:
    Class_001D2340* sub_001D2340(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D2340* Class_001D2340::sub_001D2340(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A7AC4;
    m_Field20.sub_00097E90();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D3C70 (0x001D3C70, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D3C70 (0x001D3C70, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009AD90();
};

extern "C" char DAT_003A7E7C[];

class Class_001D3C70
{
public:
    Class_001D3C70* sub_001D3C70(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D3C70* Class_001D3C70::sub_001D3C70(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A7E7C;
    m_Field20.sub_0009AD90();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D3D10 (0x001D3D10, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D3D10 (0x001D3D10, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009DB90();
};

extern "C" char DAT_003A7FCC[];

class Class_001D3D10
{
public:
    Class_001D3D10* sub_001D3D10(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D3D10* Class_001D3D10::sub_001D3D10(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A7FCC;
    m_Field20.sub_0009DB90();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D3D80 (0x001D3D80, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D3D80 (0x001D3D80, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009B070();
};

extern "C" char DAT_003A80AC[];

class Class_001D3D80
{
public:
    Class_001D3D80* sub_001D3D80(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D3D80* Class_001D3D80::sub_001D3D80(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A80AC;
    m_Field20.sub_0009B070();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D3DE0 (0x001D3DE0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D3DE0 (0x001D3DE0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009B140();
};

extern "C" char DAT_003A811C[];

class Class_001D3DE0
{
public:
    Class_001D3DE0* sub_001D3DE0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D3DE0* Class_001D3DE0::sub_001D3DE0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A811C;
    m_Field20.sub_0009B140();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D3E20 (0x001D3E20, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D3E20 (0x001D3E20, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009DBF0();
};

extern "C" char DAT_003A818C[];

class Class_001D3E20
{
public:
    Class_001D3E20* sub_001D3E20(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D3E20* Class_001D3E20::sub_001D3E20(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A818C;
    m_Field20.sub_0009DBF0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D3EC0 (0x001D3EC0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D3EC0 (0x001D3EC0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009B320();
};

extern "C" char DAT_003A83BC[];

class Class_001D3EC0
{
public:
    Class_001D3EC0* sub_001D3EC0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D3EC0* Class_001D3EC0::sub_001D3EC0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A83BC;
    m_Field20.sub_0009B320();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D40D0 (0x001D40D0, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D40D0 (0x001D40D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009DF60();
};

extern "C" char DAT_003A8514[];

class Class_001D40D0
{
public:
    Class_001D40D0* sub_001D40D0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_001D40D0* Class_001D40D0::sub_001D40D0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A8514;
    m_Field24.sub_0009DF60();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D4520 (0x001D4520, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_0041B1BC[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4520(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_0041B1BC, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D45A0 (0x001D45A0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424AA8[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D45A0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424AA8, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4620 (0x001D4620, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424AD8[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4620(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424AD8, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D46A0 (0x001D46A0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424EBC[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D46A0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424EBC, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4720 (0x001D4720, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_004250C4[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4720(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_004250C4, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D47A0 (0x001D47A0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_0042502C[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D47A0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_0042502C, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4820 (0x001D4820, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00425090[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4820(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00425090, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D48A0 (0x001D48A0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424FA8[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D48A0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424FA8, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4920 (0x001D4920, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00425004[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4920(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00425004, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D49A0 (0x001D49A0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_004250F0[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D49A0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_004250F0, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4A20 (0x001D4A20, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424BEC[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4A20(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424BEC, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4AA0 (0x001D4AA0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_0042514C[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4AA0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_0042514C, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4BA0 (0x001D4BA0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00424C3C[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4BA0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00424C3C, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4CA0 (0x001D4CA0, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00425118[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4CA0(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00425118, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D4D20 (0x001D4D20, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00425058[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D4D20(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00425058, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D6020 (0x001D6020, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D6020 (0x001D6020, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A89FC[];
extern "C" void __cdecl sub_001D1AC0(void);

class Class_001D6020
{
public:
    void sub_001D6020();
    int m_Field00; // +0x00
};

void Class_001D6020::sub_001D6020()
{
    m_Field00 = (int)DAT_003A89FC;
    sub_001D1AC0();
}

// ============================================================================
// [VERIFIED] sub_001D6030 (0x001D6030, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D6030 (0x001D6030, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_000B4210();
};

extern "C" char DAT_003A8A6C[];

class Class_001D6030
{
public:
    Class_001D6030* sub_001D6030(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D6030* Class_001D6030::sub_001D6030(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A8A6C;
    m_Field20.sub_000B4210();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D6090 (0x001D6090, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FAED0 (0x001FAED0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D6090 (0x001D6090, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_000B26C0();
};

extern "C" char DAT_003A8ADC[];

class Class_001D6090
{
public:
    Class_001D6090* sub_001D6090(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

Class_001D6090* Class_001D6090::sub_001D6090(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003A8ADC;
    m_Field20.sub_000B26C0();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D6180 (0x001D6180, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00425284[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D6180(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00425284, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D6200 (0x001D6200, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00425220[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D6200(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_00425220, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D6280 (0x001D6280, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00200EA0 (0x00200EA0), which was matched first;
// its addresses and names were swapped for this function's.
struct Holder
{
    void* object;
    void sub_0008D4C0(void* object);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_0042524C[];
extern "C" void* __cdecl sub_00028120(void* object);
extern "C" void* __cdecl sub_00028CF0(const char* name, int flags);
extern "C" void* __cdecl sub_002C92F8(void* object, int offset, void* from, void* to, int isReference);

// Looks a name up, casts what it finds to the wanted type, keeps it in the holder, and
// hands back the address 0x20 bytes into it. False when the name is empty or nothing is found.
bool __cdecl sub_001D6280(const char* name, Holder* holder, void** out)
{
    bool found = false;
    *out = 0;
    if (name && *name) {
        void* object = sub_00028CF0(name, 0);
        holder->sub_0008D4C0(sub_002C92F8(object, 0, DAT_003F45D8, DAT_0042524C, 0));
        sub_00028120(holder->object);
        if (sub_00028120(holder->object)) {
            *out = (char*)sub_00028120(holder->object) + 0x20;
            found = true;
        }
    }
    return found;
}

// ============================================================================
// [VERIFIED] sub_001D65A0 (0x001D65A0, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001888A0 (0x001888A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D65A0 (0x001D65A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000B3310();
};

extern "C" char DAT_003A8DBC[];

class Class_001D65A0
{
public:
    Class_001D65A0* sub_001D65A0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

Class_001D65A0* Class_001D65A0::sub_001D65A0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A8DBC;
    m_Field24.sub_000B3310();
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D7050 (0x001D7050, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001FB200 (0x001FB200), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D7050 (0x001D7050, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9004[];

class Class_001D7050
{
public:
    Class_001D7050* sub_001D7050(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    int m_Field24; // +0x24
};

Class_001D7050* Class_001D7050::sub_001D7050(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field22 = false;
    m_Field24 = 0;
    m_Field20 = 65535;
    m_Field00 = (int)DAT_003A9004;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001D7560 (0x001D7560, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0004D5C0 (0x0004D5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D7560 (0x001D7560, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0008B0F0();
};

class Class_001D7560
{
public:
    void sub_001D7560();
    char m_pad00[0x20];
    Field20* m_Field20; // +0x20
};

void Class_001D7560::sub_001D7560()
{
    m_Field20->sub_0008B0F0();
}

// ============================================================================
// [VERIFIED] sub_001D8780 (0x001D8780, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001D8780 (0x001D8780, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A94D4[];
extern "C" void __cdecl sub_001DB870(void);

class Class_001D8780
{
public:
    void sub_001D8780();
    int m_Field00; // +0x00
};

void Class_001D8780::sub_001D8780()
{
    m_Field00 = (int)DAT_003A94D4;
    sub_001DB870();
}

// ============================================================================
// [VERIFIED] sub_001DAF60 (0x001DAF60, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4A0[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001DAF60(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4A0;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001DAFE0 (0x001DAFE0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0038B4D8[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001DAFE0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0038B4D8;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001DB060 (0x001DB060, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00216AF0 (0x00216AF0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003A9ABC[];
extern "C" const void* __cdecl sub_0002AAC0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 4 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001DB060(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(4);
        *(void**)object = DAT_003A9ABC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAC0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001DB0E0 (0x001DB0E0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00216B70 (0x00216B70), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003A9AC4[];
extern "C" const void* __cdecl sub_0002AAC0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 5 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001DB0E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(5);
        *(void**)object = DAT_003A9AC4;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAC0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001DB160 (0x001DB160, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002D910 (0x0002D910), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037F148[];
extern "C" const void* __cdecl sub_0002AAB0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 0 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001DB160(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_0037F148;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAB0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001DB7A0 (0x001DB7A0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002172B0 (0x002172B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001DB7A0 (0x001DB7A0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009FF60();
};

class Class_001DB7A0
{
public:
    void sub_001DB7A0();
};

void Class_001DB7A0::sub_001DB7A0()
{
    ((Object*)(int)this + 72)->sub_0009FF60();
}

// ============================================================================
// [VERIFIED] sub_001DB7B0 (0x001DB7B0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002172B0 (0x002172B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001DB7B0 (0x001DB7B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000A00C0();
};

class Class_001DB7B0
{
public:
    void sub_001DB7B0();
};

void Class_001DB7B0::sub_001DB7B0()
{
    ((Object*)(int)this + 72)->sub_000A00C0();
}

// ============================================================================
// [VERIFIED] sub_001DB7C0 (0x001DB7C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002172B0 (0x002172B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001DB7C0 (0x001DB7C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000A0120();
};

class Class_001DB7C0
{
public:
    void sub_001DB7C0();
};

void Class_001DB7C0::sub_001DB7C0()
{
    ((Object*)(int)this + 72)->sub_000A0120();
}

// ============================================================================
// [VERIFIED] sub_001DFDC0 (0x001DFDC0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001DFDC0 (0x001DFDC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9D5C[];

class Class_001DFDC0
{
public:
    Class_001DFDC0* sub_001DFDC0(int a1, int a2);
    void sub_001D8710(int, int);
    int m_Field00; // +0x00
};

Class_001DFDC0* Class_001DFDC0::sub_001DFDC0(int a1, int a2)
{
    sub_001D8710(a1, a2);
    m_Field00 = (int)DAT_003A9D5C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001DFE90 (0x001DFE90, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A6D0 (0x0002A6D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001DFE90 (0x001DFE90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9F2C[];

class Class_001DFE90
{
public:
    Class_001DFE90* sub_001DFE90(int a1, int a2);
    void sub_001D8710(int, int);
    int m_Field00; // +0x00
};

Class_001DFE90* Class_001DFE90::sub_001DFE90(int a1, int a2)
{
    sub_001D8710(a1, a2);
    m_Field00 = (int)DAT_003A9F2C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001E1050 (0x001E1050, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_001EA570 (0x001EA570), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E1050 (0x001E1050, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AA20C[];

class Class_001E1050
{
public:
    Class_001E1050* sub_001E1050(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

Class_001E1050* Class_001E1050::sub_001E1050(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field00 = (int)DAT_003AA20C;
    m_Field20 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001E1570 (0x001E1570, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E1570 (0x001E1570, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00461F94;

int __cdecl sub_001E1570(void)
{
    return DAT_00461F94;
}

// ============================================================================
// [VERIFIED] sub_001E2ED0 (0x001E2ED0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E2ED0 (0x001E2ED0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00462048;

int __cdecl sub_001E2ED0(void)
{
    return DAT_00462048;
}

// ============================================================================
// [VERIFIED] sub_001E2EE0 (0x001E2EE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E2EE0 (0x001E2EE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0046204C;

int __cdecl sub_001E2EE0(void)
{
    return DAT_0046204C;
}

// ============================================================================
// [VERIFIED] sub_001E2EF0 (0x001E2EF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E2EF0 (0x001E2EF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004626DD;

bool __cdecl sub_001E2EF0(void)
{
    return DAT_004626DD;
}

// ============================================================================
// [VERIFIED] sub_001E2F90 (0x001E2F90, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E680 (0x0001E680), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E2F90 (0x001E2F90, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004626E2;

void __cdecl sub_001E2F90(void)
{
    DAT_004626E2 = true;
}

// ============================================================================
// [VERIFIED] sub_001E2FA0 (0x001E2FA0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001EF60 (0x0001EF60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E2FA0 (0x001E2FA0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00462634;

float __cdecl sub_001E2FA0(void)
{
    return DAT_00462634;
}

// ============================================================================
// [VERIFIED] sub_001E30A0 (0x001E30A0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E30A0 (0x001E30A0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004626D9;

bool __cdecl sub_001E30A0(bool a1)
{
    DAT_004626D9 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_001E30B0 (0x001E30B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E30B0 (0x001E30B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004626D9;

bool __cdecl sub_001E30B0(void)
{
    return DAT_004626D9;
}

// ============================================================================
// [VERIFIED] sub_001E3110 (0x001E3110, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E3110 (0x001E3110, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00462610[];

void* __cdecl sub_001E3110(void)
{
    return DAT_00462610;
}

// ============================================================================
// [VERIFIED] sub_001E3280 (0x001E3280, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E3280 (0x001E3280, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00462478[];

void* __cdecl sub_001E3280(void)
{
    return DAT_00462478;
}

// ============================================================================
// [VERIFIED] sub_001E5640 (0x001E5640, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00136830 (0x00136830), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003AAFFC[];
extern "C" const void* __cdecl sub_0002AAB0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

// Makes a 16-byte object of kind 1 (a4 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001E5640(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_003AAFFC;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0002AAB0), 4);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001E6200 (0x001E6200, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001E6200 (0x001E6200, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E6070(void);

class Class_001E6200
{
public:
    void sub_001E6200();
};

void Class_001E6200::sub_001E6200()
{
    sub_001E6070();
}

// ============================================================================
// [VERIFIED] sub_001ECAF0 (0x001ECAF0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001ECAF0 (0x001ECAF0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00427844;

int __cdecl sub_001ECAF0(int a1)
{
    DAT_00427844 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_001ECBC0 (0x001ECBC0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E680 (0x0001E680), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001ECBC0 (0x001ECBC0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00462F90;

void __cdecl sub_001ECBC0(void)
{
    DAT_00462F90 = true;
}

// ============================================================================
// [VERIFIED] sub_001EF410 (0x001EF410, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00025350 (0x00025350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003AC150[];
extern "C" const void* __cdecl sub_00023090(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001EF410(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_003AC150;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_00023090), 1);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_001EF480 (0x001EF480, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011540 (0x00011540), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003AC158[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 1 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001EF480(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_003AC158;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_001EF4F0 (0x001EF4F0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000115B0 (0x000115B0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003AC160[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 2 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001EF4F0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(2);
        *(void**)object = DAT_003AC160;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_001EF560 (0x001EF560, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00230BD0 (0x00230BD0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003AC168[];
extern "C" const void* __cdecl sub_00023090(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 0 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001EF560(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_003AC168;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_00023090), 1);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_001EF5D0 (0x001EF5D0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00230C40 (0x00230C40), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_003AC170[];
extern "C" const void* __cdecl sub_0005CC80(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_000657F0(int a1, int a2, Object* object, int a6, int a4, int a5);

// Makes a 16-byte object of kind 0 (a3 kept at +0x0C, a type check at +0x09) and registers it.
void __cdecl sub_001EF5D0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(0);
        *(void**)object = DAT_003AC170;
        *(int*)((char*)object + 12) = a3;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_0005CC80), 4);
    } else {
        object = 0;
    }
    sub_000657F0(a1, a2, object, a6, a4, a5);
}

// ============================================================================
// [VERIFIED] sub_001F0FB0 (0x001F0FB0, 114 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0011BCB0 (0x0011BCB0), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_0005CE70(int kind);
};

// A type, named by the address of a function that is unique to it.
struct TypeRef
{
    const void* tag;
    TypeRef(const void* t) : tag(t) {}
};

extern "C" char DAT_0037CD24[];
extern "C" const void* __cdecl sub_000116A0(void);
extern "C" void* __cdecl sub_00025140(unsigned int size, unsigned int align);
extern "C" bool __cdecl sub_0005CEA0(const TypeRef& type, int a2);
extern "C" void __cdecl sub_00065E70(int a1, int a2, int a3, Object* object, int a7, int a5, int a6);

void __cdecl sub_001F0FB0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Object* object = (Object*)sub_00025140(16, 4);
    if (object) {
        object->sub_0005CE70(1);
        *(void**)object = DAT_0037CD24;
        *(int*)((char*)object + 12) = a4;
        *((bool*)object + 9) = sub_0005CEA0(TypeRef((const void*)&sub_000116A0), 0);
    } else {
        object = 0;
    }
    sub_00065E70(a1, a2, a3, object, a7, a5, a6);
}

// ============================================================================
// [VERIFIED] sub_001F4558 (0x001F4558, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F4558 (0x001F4558, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00497034;

int __cdecl sub_001F4558(void)
{
    return DAT_00497034;
}

// ============================================================================
// [VERIFIED] sub_001F47B0 (0x001F47B0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E3560 (0x000E3560), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F47B0 (0x001F47B0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __stdcall sub_001F47B0(int a1, int a2, int a3, int a4)
{
}

// ============================================================================
// [VERIFIED] sub_001F6C8B (0x001F6C8B, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F6C8B (0x001F6C8B, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001F770E(void);

class Class_001F6C8B
{
public:
    void sub_001F6C8B();
};

void Class_001F6C8B::sub_001F6C8B()
{
    sub_001F770E();
}

// ============================================================================
// [VERIFIED] sub_001F76F4 (0x001F76F4, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F76F4 (0x001F76F4, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C6B0;

class Class_001F76F4
{
public:
    void sub_001F76F4();
};

void Class_001F76F4::sub_001F76F4()
{
    ((void (__cdecl*)(void))DAT_0037C6B0)();
}

// ============================================================================
// [VERIFIED] sub_001F7702 (0x001F7702, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7702 (0x001F7702, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C6CC;

class Class_001F7702
{
public:
    void sub_001F7702();
};

void Class_001F7702::sub_001F7702()
{
    ((void (__cdecl*)(void))DAT_0037C6CC)();
}

// ============================================================================
// [VERIFIED] sub_001F7708 (0x001F7708, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7708 (0x001F7708, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C6E0;

class Class_001F7708
{
public:
    void sub_001F7708();
};

void Class_001F7708::sub_001F7708()
{
    ((void (__cdecl*)(void))DAT_0037C6E0)();
}

// ============================================================================
// [VERIFIED] sub_001F770E (0x001F770E, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F770E (0x001F770E, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C6E4;

class Class_001F770E
{
public:
    void sub_001F770E();
};

void Class_001F770E::sub_001F770E()
{
    ((void (__cdecl*)(void))DAT_0037C6E4)();
}

// ============================================================================
// [VERIFIED] sub_001F7714 (0x001F7714, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7714 (0x001F7714, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C6E8;

class Class_001F7714
{
public:
    void sub_001F7714();
};

void Class_001F7714::sub_001F7714()
{
    ((void (__cdecl*)(void))DAT_0037C6E8)();
}

// ============================================================================
// [VERIFIED] sub_001F771A (0x001F771A, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F771A (0x001F771A, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C730;

class Class_001F771A
{
public:
    void sub_001F771A();
};

void Class_001F771A::sub_001F771A()
{
    ((void (__cdecl*)(void))DAT_0037C730)();
}

// ============================================================================
// [VERIFIED] sub_001F7720 (0x001F7720, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00239CC0 (0x00239CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7720 (0x001F7720, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ACC40[];

class Class_001F7720
{
public:
    Class_001F7720* sub_001F7720();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_001F7720* Class_001F7720::sub_001F7720()
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_003ACC40;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001F7730 (0x001F7730, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7730 (0x001F7730, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ACC8C[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_001F7730
{
public:
    void sub_001F7730();
    int m_Field00; // +0x00
};

void Class_001F7730::sub_001F7730()
{
    m_Field00 = (int)DAT_003ACC8C;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_001F7900 (0x001F7900, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7900 (0x001F7900, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385F44[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_001F7900
{
public:
    void sub_001F7900();
    int m_Field00; // +0x00
};

void Class_001F7900::sub_001F7900()
{
    m_Field00 = (int)DAT_00385F44;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_001F7910 (0x001F7910, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00239EE0 (0x00239EE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7910 (0x001F7910, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ACD2C[];
extern "C" void __cdecl sub_002002C0(void);

class Class_001F7910
{
public:
    Class_001F7910* sub_001F7910();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_001F7910* Class_001F7910::sub_001F7910()
{
    sub_002002C0();
    m_Field00 = (int)DAT_003ACD2C;
    m_Field0C = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001F7930 (0x001F7930, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7930 (0x001F7930, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ACD2C[];
extern "C" void __cdecl sub_001F7730(void);

class Class_001F7930
{
public:
    void sub_001F7930();
    int m_Field00; // +0x00
};

void Class_001F7930::sub_001F7930()
{
    m_Field00 = (int)DAT_003ACD2C;
    sub_001F7730();
}

// ============================================================================
// [VERIFIED] sub_001F7E30 (0x001F7E30, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F7E30 (0x001F7E30, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D85C[];

class Class_001F7E30
{
public:
    void sub_001F7E30();
    int m_Field00; // +0x00
};

void Class_001F7E30::sub_001F7E30()
{
    m_Field00 = (int)DAT_0037D85C;
}

// ============================================================================
// [VERIFIED] sub_001F82D0 (0x001F82D0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00185980 (0x00185980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F82D0 (0x001F82D0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ACDE4[];
extern "C" void __cdecl sub_001FBFB0(void);

class Class_001F82D0
{
public:
    Class_001F82D0* sub_001F82D0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    bool m_Field14; // +0x14
    char m_pad15[0x3F];
    bool m_Field54; // +0x54
};

Class_001F82D0* Class_001F82D0::sub_001F82D0()
{
    sub_001FBFB0();
    m_Field14 = false;
    m_Field54 = false;
    m_Field00 = (int)DAT_003ACDE4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001F82F0 (0x001F82F0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001F82F0 (0x001F82F0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ACDE4[];
extern "C" void __cdecl sub_001FBF40(void);

class Class_001F82F0
{
public:
    void sub_001F82F0();
    int m_Field00; // +0x00
};

void Class_001F82F0::sub_001F82F0()
{
    m_Field00 = (int)DAT_003ACDE4;
    sub_001FBF40();
}

// ============================================================================
// [VERIFIED] sub_001FB630 (0x001FB630, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217D0 (0x000217D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FB630 (0x001FB630, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AD6A4[];
extern "C" void __cdecl sub_001F86E0(void);

class Class_001FB630
{
public:
    Class_001FB630* sub_001FB630();
    int m_Field00; // +0x00
};

Class_001FB630* Class_001FB630::sub_001FB630()
{
    sub_001F86E0();
    m_Field00 = (int)DAT_003AD6A4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_001FB8B0 (0x001FB8B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FB8B0 (0x001FB8B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0046390C[];
extern "C" char DAT_00463910[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_001FB8B0(void)
{
    sub_001FC310((int)DAT_0046390C, (int)DAT_00463910);
}

// ============================================================================
// [VERIFIED] sub_001FB960 (0x001FB960, 95 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E7440 (0x000E7440), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FB960 (0x001FB960, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC3F0(int);
};

extern "C" char DAT_003AD760[];
extern "C" char DAT_003AD748[];
extern "C" char DAT_0046390C[];
extern "C" int DAT_00463910;
extern "C" char sub_000CB610[];
extern "C" int __cdecl sub_00025120(int);
extern "C" int __cdecl sub_001FC2C0(int, int, int);

int __cdecl sub_001FB960(void)
{
    int local_4, r_eax;

    r_eax = DAT_00463910;
    if (!r_eax) {
        r_eax = sub_00025120(12);
        if (r_eax) {
            ((Object*)r_eax)->sub_001FC3F0((int)DAT_003AD760);
            *(int*)r_eax = (int)DAT_003AD748;
            *(int*)(r_eax + 8) = (int)sub_000CB610;
            local_4 = r_eax;
        } else {
            local_4 = 0;
        }
        r_eax = (int)(&local_4);
        r_eax = sub_001FC2C0((int)DAT_0046390C, r_eax, 1);
    }
    DAT_00463910 += 1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_001FBF30 (0x001FBF30, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FBF30 (0x001FBF30, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D8F4[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_001FBF30
{
public:
    void sub_001FBF30();
    int m_Field00; // +0x00
};

void Class_001FBF30::sub_001FBF30()
{
    m_Field00 = (int)DAT_0037D8F4;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_001FBF40 (0x001FBF40, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FBF40 (0x001FBF40, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AD994[];
extern "C" void __cdecl sub_001F7730(void);

class Class_001FBF40
{
public:
    void sub_001FBF40();
    int m_Field00; // +0x00
};

void Class_001FBF40::sub_001FBF40()
{
    m_Field00 = (int)DAT_003AD994;
    sub_001F7730();
}

// ============================================================================
// [VERIFIED] sub_001FC000 (0x001FC000, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000DD260 (0x000DD260), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FC000 (0x001FC000, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00463B24[];
extern "C" char DAT_00463B28[];
extern "C" void __cdecl sub_001FC310(int, int);

void __cdecl sub_001FC000(void)
{
    sub_001FC310((int)DAT_00463B24, (int)DAT_00463B28);
}

// ============================================================================
// [VERIFIED] sub_001FC2B0 (0x001FC2B0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FC2B0 (0x001FC2B0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ADB78[];

class Class_001FC2B0
{
public:
    void sub_001FC2B0();
    int m_Field00; // +0x00
};

void Class_001FC2B0::sub_001FC2B0()
{
    m_Field00 = (int)DAT_003ADB78;
}

// ============================================================================
// [VERIFIED] sub_001FCF20 (0x001FCF20, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FCF20 (0x001FCF20, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025120(void);

class Class_001FCF20
{
public:
    void sub_001FCF20();
};

void Class_001FCF20::sub_001FCF20()
{
    sub_00025120();
}

// ============================================================================
// [VERIFIED] sub_001FCF60 (0x001FCF60, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FCF60 (0x001FCF60, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(void);

class Class_001FCF60
{
public:
    void sub_001FCF60();
};

void Class_001FCF60::sub_001FCF60()
{
    sub_00025160();
}

// ============================================================================
// [VERIFIED] sub_001FE6B0 (0x001FE6B0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00047E50 (0x00047E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_001FE6B0 (0x001FE6B0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FE600();
};

extern "C" int DAT_00463B64;

void __cdecl sub_001FE6B0(void)
{
    ((Object*)DAT_00463B64)->sub_001FE600();
}

// ============================================================================
// [VERIFIED] sub_00200280 (0x00200280, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023EC0 (0x00023EC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00200280 (0x00200280, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002014E0(int, int);

void __cdecl sub_00200280(int a1)
{
    sub_002014E0(a1, 0);
}

// ============================================================================
// [VERIFIED] sub_002014E0 (0x002014E0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002014E0 (0x002014E0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00201440(void);

class Class_002014E0
{
public:
    void sub_002014E0();
};

void Class_002014E0::sub_002014E0()
{
    sub_00201440();
}

// ============================================================================
// [VERIFIED] sub_002016D0 (0x002016D0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00244230 (0x00244230), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002016D0 (0x002016D0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00200AE0(int, int);
};

class Class_002016D0
{
public:
    void sub_002016D0(int a1, int a2);
};

void Class_002016D0::sub_002016D0(int a1, int a2)
{
    ((Object*)a2)->sub_00200AE0(a1, (int)this);
}

// ============================================================================
// [VERIFIED] sub_00201720 (0x00201720, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00244230 (0x00244230), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00201720 (0x00201720, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00200BE0(int, int);
};

class Class_00201720
{
public:
    void sub_00201720(int a1, int a2);
};

void Class_00201720::sub_00201720(int a1, int a2)
{
    ((Object*)a2)->sub_00200BE0(a1, (int)this);
}

// ============================================================================
// [VERIFIED] sub_002018B0 (0x002018B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002018B0 (0x002018B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004647F4;

int __cdecl sub_002018B0(void)
{
    return DAT_004647F4;
}

// ============================================================================
// [VERIFIED] sub_002018C0 (0x002018C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00244420 (0x00244420), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002018C0 (0x002018C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004647F4;

int __cdecl sub_002018C0(int a1)
{
    int t1;

    t1 = DAT_004647F4;
    DAT_004647F4 = a1;
    return t1;
}

// ============================================================================
// [VERIFIED] sub_002018D0 (0x002018D0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000179A0 (0x000179A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002018D0 (0x002018D0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004647F8;
extern "C" int DAT_004647FC;

int __cdecl sub_002018D0(int a1, int a2)
{
    DAT_004647F8 = a1;
    DAT_004647FC = a2;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00204D10 (0x00204D10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00204D10 (0x00204D10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00464814;

int __cdecl sub_00204D10(void)
{
    return DAT_00464814;
}

// ============================================================================
// [VERIFIED] sub_00205D60 (0x00205D60, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00205D60 (0x00205D60, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AE174[];
extern "C" void __cdecl sub_00249300(void);

class Class_00205D60
{
public:
    void sub_00205D60();
    int m_Field00; // +0x00
};

void Class_00205D60::sub_00205D60()
{
    m_Field00 = (int)DAT_003AE174;
    sub_00249300();
}

// ============================================================================
// [VERIFIED] sub_00206400 (0x00206400, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00206400 (0x00206400, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00464C20;

int __cdecl sub_00206400(void)
{
    return DAT_00464C20;
}

// ============================================================================
// [VERIFIED] sub_002065C0 (0x002065C0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002065C0 (0x002065C0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AE1D0[];

class Class_002065C0
{
public:
    void sub_002065C0();
    int m_Field00; // +0x00
};

void Class_002065C0::sub_002065C0()
{
    m_Field00 = (int)DAT_003AE1D0;
}

// ============================================================================
// [VERIFIED] sub_0020BC50 (0x0020BC50, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020BC50 (0x0020BC50, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0020B5F0(void);

class Class_0020BC50
{
public:
    void sub_0020BC50();
};

void Class_0020BC50::sub_0020BC50()
{
    sub_0020B5F0();
}

// ============================================================================
// [VERIFIED] sub_0020BEE0 (0x0020BEE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020BEE0 (0x0020BEE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00429334;

int __cdecl sub_0020BEE0(void)
{
    return DAT_00429334;
}

// ============================================================================
// [VERIFIED] sub_0020DC30 (0x0020DC30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DC30 (0x0020DC30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AE674[];

void* __cdecl sub_0020DC30(void)
{
    return DAT_003AE674;
}

// ============================================================================
// [VERIFIED] sub_0020DD00 (0x0020DD00, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD00 (0x0020DD00, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024DD90(void);

class Class_0020DD00
{
public:
    void sub_0020DD00();
};

void Class_0020DD00::sub_0020DD00()
{
    sub_0024DD90();
}

// ============================================================================
// [VERIFIED] sub_0020DD10 (0x0020DD10, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD10 (0x0020DD10, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E180(void);

class Class_0020DD10
{
public:
    void sub_0020DD10();
};

void Class_0020DD10::sub_0020DD10()
{
    sub_0024E180();
}

// ============================================================================
// [VERIFIED] sub_0020DD20 (0x0020DD20, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD20 (0x0020DD20, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024DE10(void);

class Class_0020DD20
{
public:
    void sub_0020DD20();
};

void Class_0020DD20::sub_0020DD20()
{
    sub_0024DE10();
}

// ============================================================================
// [VERIFIED] sub_0020DD30 (0x0020DD30, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD30 (0x0020DD30, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E1E0(void);

class Class_0020DD30
{
public:
    void sub_0020DD30();
};

void Class_0020DD30::sub_0020DD30()
{
    sub_0024E1E0();
}

// ============================================================================
// [VERIFIED] sub_0020DD40 (0x0020DD40, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD40 (0x0020DD40, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E340(void);

class Class_0020DD40
{
public:
    void sub_0020DD40();
};

void Class_0020DD40::sub_0020DD40()
{
    sub_0024E340();
}

// ============================================================================
// [VERIFIED] sub_0020DD50 (0x0020DD50, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD50 (0x0020DD50, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E4B0(void);

class Class_0020DD50
{
public:
    void sub_0020DD50();
};

void Class_0020DD50::sub_0020DD50()
{
    sub_0024E4B0();
}

// ============================================================================
// [VERIFIED] sub_0020DD60 (0x0020DD60, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD60 (0x0020DD60, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024DE90(void);

class Class_0020DD60
{
public:
    void sub_0020DD60();
};

void Class_0020DD60::sub_0020DD60()
{
    sub_0024DE90();
}

// ============================================================================
// [VERIFIED] sub_0020DD70 (0x0020DD70, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD70 (0x0020DD70, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E4E0(void);

class Class_0020DD70
{
public:
    void sub_0020DD70();
};

void Class_0020DD70::sub_0020DD70()
{
    sub_0024E4E0();
}

// ============================================================================
// [VERIFIED] sub_0020DD80 (0x0020DD80, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD80 (0x0020DD80, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E020(void);

class Class_0020DD80
{
public:
    void sub_0020DD80();
};

void Class_0020DD80::sub_0020DD80()
{
    sub_0024E020();
}

// ============================================================================
// [VERIFIED] sub_0020DD90 (0x0020DD90, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DD90 (0x0020DD90, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E0A0(void);

class Class_0020DD90
{
public:
    void sub_0020DD90();
};

void Class_0020DD90::sub_0020DD90()
{
    sub_0024E0A0();
}

// ============================================================================
// [VERIFIED] sub_0020DDA0 (0x0020DDA0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020DDA0 (0x0020DDA0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024DEE0(void);

class Class_0020DDA0
{
public:
    void sub_0020DDA0();
};

void Class_0020DDA0::sub_0020DDA0()
{
    sub_0024DEE0();
}

// ============================================================================
// [VERIFIED] sub_0020F3B0 (0x0020F3B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0020F3B0 (0x0020F3B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00464CD8;

int __cdecl sub_0020F3B0(void)
{
    return DAT_00464CD8;
}

// ============================================================================
// [VERIFIED] sub_00212140 (0x00212140, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00212140 (0x00212140, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AEB70[];
extern "C" char sub_00011000[];

class Class_00212140
{
public:
    Class_00212140* sub_00212140();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00212140* Class_00212140::sub_00212140()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00011000;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003AEB70;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00212A60 (0x00212A60, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00212A60 (0x00212A60, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0042976D;

bool __cdecl sub_00212A60(bool a1)
{
    DAT_0042976D = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_002167C0 (0x002167C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00239CC0 (0x00239CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002167C0 (0x002167C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AECF4[];

class Class_002167C0
{
public:
    Class_002167C0* sub_002167C0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_002167C0* Class_002167C0::sub_002167C0()
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_003AECF4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00217400 (0x00217400, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00217400 (0x00217400, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AEDCC[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_00217400
{
public:
    void sub_00217400();
    int m_Field00; // +0x00
};

void Class_00217400::sub_00217400()
{
    m_Field00 = (int)DAT_003AEDCC;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_00217A80 (0x00217A80, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00217A80 (0x00217A80, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AEE78[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_00217A80
{
public:
    void sub_00217A80();
    int m_Field00; // +0x00
};

void Class_00217A80::sub_00217A80()
{
    m_Field00 = (int)DAT_003AEE78;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_0021F720 (0x0021F720, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0021F720 (0x0021F720, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AF6CC[];
extern "C" char sub_0001800D[];

class Class_0021F720
{
public:
    Class_0021F720* sub_0021F720();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_0021F720* Class_0021F720::sub_0021F720()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_0001800D;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003AF6CC;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00220AC0 (0x00220AC0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00220AC0 (0x00220AC0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AF7A4[];
extern "C" char sub_00021000[];

class Class_00220AC0
{
public:
    Class_00220AC0* sub_00220AC0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00220AC0* Class_00220AC0::sub_00220AC0()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00021000;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003AF7A4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00220AE0 (0x00220AE0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00220AE0 (0x00220AE0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AF7C4[];
extern "C" char sub_00021001[];

class Class_00220AE0
{
public:
    Class_00220AE0* sub_00220AE0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00220AE0* Class_00220AE0::sub_00220AE0()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00021001;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003AF7C4;
    return this;
}

// ============================================================================
// [VERIFIED] sub_002213A0 (0x002213A0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002213A0 (0x002213A0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AF82C[];
extern "C" char sub_00021002[];

class Class_002213A0
{
public:
    Class_002213A0* sub_002213A0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_002213A0* Class_002213A0::sub_002213A0()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00021002;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003AF82C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00221CD0 (0x00221CD0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00221CD0 (0x00221CD0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048CD70;

int __cdecl sub_00221CD0(int a1)
{
    DAT_0048CD70 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00224870 (0x00224870, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00224870 (0x00224870, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AFA28[];
extern "C" char sub_00121202[];

class Class_00224870
{
public:
    Class_00224870* sub_00224870();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00224870* Class_00224870::sub_00224870()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00121202;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003AFA28;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00228940 (0x00228940, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00228940 (0x00228940, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AFE2C[];
extern "C" char sub_00123000[];

class Class_00228940
{
public:
    Class_00228940* sub_00228940();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00228940* Class_00228940::sub_00228940()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00123000;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003AFE2C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_002296E0 (0x002296E0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00277C80 (0x00277C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002296E0 (0x002296E0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    void sub_0024F0B0();
};

class Class_002296E0
{
public:
    void sub_002296E0();
    char m_pad00[0x58];
    Field58* m_Field58; // +0x58
};

void Class_002296E0::sub_002296E0()
{
    m_Field58->sub_0024F0B0();
}

// ============================================================================
// [VERIFIED] sub_002296F0 (0x002296F0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00277C80 (0x00277C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002296F0 (0x002296F0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    void sub_0024F0E0();
};

class Class_002296F0
{
public:
    void sub_002296F0();
    char m_pad00[0x58];
    Field58* m_Field58; // +0x58
};

void Class_002296F0::sub_002296F0()
{
    m_Field58->sub_0024F0E0();
}

// ============================================================================
// [VERIFIED] sub_00229700 (0x00229700, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00277C80 (0x00277C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00229700 (0x00229700, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    void sub_0024F100();
};

class Class_00229700
{
public:
    void sub_00229700();
    char m_pad00[0x58];
    Field58* m_Field58; // +0x58
};

void Class_00229700::sub_00229700()
{
    m_Field58->sub_0024F100();
}

// ============================================================================
// [VERIFIED] sub_00229710 (0x00229710, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00277C80 (0x00277C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00229710 (0x00229710, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    void sub_0024F680();
};

class Class_00229710
{
public:
    void sub_00229710();
    char m_pad00[0x58];
    Field58* m_Field58; // +0x58
};

void Class_00229710::sub_00229710()
{
    m_Field58->sub_0024F680();
}

// ============================================================================
// [VERIFIED] sub_00229720 (0x00229720, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00277C80 (0x00277C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00229720 (0x00229720, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    void sub_0024F120();
};

class Class_00229720
{
public:
    void sub_00229720();
    char m_pad00[0x58];
    Field58* m_Field58; // +0x58
};

void Class_00229720::sub_00229720()
{
    m_Field58->sub_0024F120();
}

// ============================================================================
// [VERIFIED] sub_0022CEE0 (0x0022CEE0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00014F70 (0x00014F70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0022CEE0 (0x0022CEE0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_0022CEE0(int a1, int a2, int a3)
{
    int r_eax, r_ecx, r_edx;

    r_eax = a2;
    if (a2) {
        r_edx = a3;
        r_ecx = a2;
        r_eax = a1;
        do {
            if (r_eax) {
                *(int*)r_eax = *(int*)r_edx;
            }
            r_eax += 4;
            r_ecx -= 1;
        } while (r_ecx);
        return r_eax;
    }
    r_eax = a1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0022F480 (0x0022F480, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0022F480 (0x0022F480, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B0280[];
extern "C" char sub_00022002[];

class Class_0022F480
{
public:
    Class_0022F480* sub_0022F480();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_0022F480* Class_0022F480::sub_0022F480()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00022002;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003B0280;
    return this;
}

// ============================================================================
// [VERIFIED] sub_002302C0 (0x002302C0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002302C0 (0x002302C0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B0330[];
extern "C" char sub_00022000[];

class Class_002302C0
{
public:
    Class_002302C0* sub_002302C0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_002302C0* Class_002302C0::sub_002302C0()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00022000;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003B0330;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00230FC0 (0x00230FC0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00230FC0 (0x00230FC0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B036C[];
extern "C" char sub_00013000[];

class Class_00230FC0
{
public:
    Class_00230FC0* sub_00230FC0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00230FC0* Class_00230FC0::sub_00230FC0()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00013000;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003B036C;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00231350 (0x00231350, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00255FC0 (0x00255FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00231350 (0x00231350, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B03E8[];
extern "C" char sub_00014000[];

class Class_00231350
{
public:
    Class_00231350* sub_00231350();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00231350* Class_00231350::sub_00231350()
{
    m_Field04 = 0;
    m_Field08 = (int)sub_00014000;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field00 = (int)DAT_003B03E8;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00231540 (0x00231540, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00239EE0 (0x00239EE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00231540 (0x00231540, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B0460[];
extern "C" void __cdecl sub_002002C0(void);

class Class_00231540
{
public:
    Class_00231540* sub_00231540();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_00231540* Class_00231540::sub_00231540()
{
    sub_002002C0();
    m_Field00 = (int)DAT_003B0460;
    m_Field0C = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0023E110 (0x0023E110, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002A160 (0x0002A160), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0023E110 (0x0023E110, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0023E110
{
public:
    int sub_0023E110(int a1);
    char m_pad00[0x90];
    int m_Field90; // +0x90
};

int Class_0023E110::sub_0023E110(int a1)
{
    m_Field90 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0023F080 (0x0023F080, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0023F080 (0x0023F080, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0026A200(void);

class Class_0023F080
{
public:
    void sub_0023F080();
};

void Class_0023F080::sub_0023F080()
{
    sub_0026A200();
}

// ============================================================================
// [VERIFIED] sub_0023F090 (0x0023F090, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0023F090 (0x0023F090, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0026A480(void);

class Class_0023F090
{
public:
    void sub_0023F090();
};

void Class_0023F090::sub_0023F090()
{
    sub_0026A480();
}

// ============================================================================
// [VERIFIED] sub_0023F0A0 (0x0023F0A0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0023F0A0 (0x0023F0A0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0026A650(void);

class Class_0023F0A0
{
public:
    void sub_0023F0A0();
};

void Class_0023F0A0::sub_0023F0A0()
{
    sub_0026A650();
}

// ============================================================================
// [VERIFIED] sub_0023F170 (0x0023F170, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0023F170 (0x0023F170, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C74C;

void __cdecl sub_0023F170(int a1)
{
    ((void (__stdcall*)(int))DAT_0037C74C)(a1);
}

// ============================================================================
// [VERIFIED] sub_0023F180 (0x0023F180, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0023F180 (0x0023F180, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C684;

void __cdecl sub_0023F180(int a1)
{
    ((void (__stdcall*)(int))DAT_0037C684)(a1);
}

// ============================================================================
// [VERIFIED] sub_0023F190 (0x0023F190, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0023F190 (0x0023F190, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C688;

void __cdecl sub_0023F190(int a1)
{
    ((void (__stdcall*)(int))DAT_0037C688)(a1);
}

// ============================================================================
// [VERIFIED] sub_00240720 (0x00240720, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E680 (0x0001E680), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00240720 (0x00240720, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0048CEB8;

void __cdecl sub_00240720(void)
{
    DAT_0048CEB8 = true;
}

// ============================================================================
// [VERIFIED] sub_00240790 (0x00240790, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00240790 (0x00240790, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0048CEBC;

bool __cdecl sub_00240790(void)
{
    return DAT_0048CEBC;
}

// ============================================================================
// [VERIFIED] sub_00247900 (0x00247900, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00247900 (0x00247900, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B15B4[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_00247900
{
public:
    void sub_00247900();
    int m_Field00; // +0x00
};

void Class_00247900::sub_00247900()
{
    m_Field00 = (int)DAT_003B15B4;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_00248120 (0x00248120, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0028C390 (0x0028C390), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00248120 (0x00248120, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B165C[];
extern "C" void __cdecl sub_00225B20(void);

class Class_00248120
{
public:
    Class_00248120* sub_00248120();
    int m_Field00; // +0x00
    char m_pad04[0xA4];
    int m_FieldA8; // +0xA8
    int m_FieldAC; // +0xAC
};

Class_00248120* Class_00248120::sub_00248120()
{
    sub_00225B20();
    m_Field00 = (int)DAT_003B165C;
    m_FieldA8 = -1;
    m_FieldAC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00249300 (0x00249300, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00249300 (0x00249300, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B184C[];
extern "C" void __cdecl sub_001F7E30(void);

class Class_00249300
{
public:
    void sub_00249300();
    int m_Field00; // +0x00
};

void Class_00249300::sub_00249300()
{
    m_Field00 = (int)DAT_003B184C;
    sub_001F7E30();
}

// ============================================================================
// [VERIFIED] sub_002495E0 (0x002495E0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002495E0 (0x002495E0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B18E8[];
extern "C" void __cdecl sub_00249530(void);

class Class_002495E0
{
public:
    void sub_002495E0();
    int m_Field00; // +0x00
};

void Class_002495E0::sub_002495E0()
{
    m_Field00 = (int)DAT_003B18E8;
    sub_00249530();
}

// ============================================================================
// [VERIFIED] sub_00249E30 (0x00249E30, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00249E30 (0x00249E30, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002494D0(void);

class Class_00249E30
{
public:
    void sub_00249E30();
};

void Class_00249E30::sub_00249E30()
{
    sub_002494D0();
}

// ============================================================================
// [VERIFIED] sub_0024DEC0 (0x0024DEC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0024DEC0 (0x0024DEC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048E028;

int __cdecl sub_0024DEC0(void)
{
    return DAT_0048E028;
}

// ============================================================================
// [VERIFIED] sub_0024DED0 (0x0024DED0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0024DED0 (0x0024DED0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042C3E0;

int __cdecl sub_0024DED0(void)
{
    return DAT_0042C3E0;
}

// ============================================================================
// [VERIFIED] sub_0024EB70 (0x0024EB70, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000C57F0 (0x000C57F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0024EB70 (0x0024EB70, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B7A10(void);
extern "C" void __cdecl sub_001B7A10(void);
extern "C" void __cdecl sub_001B7A10(void);

void __cdecl sub_0024EB70(void)
{
    sub_001B7A10();
    sub_001B7A10();
    sub_001B7A10();
}

// ============================================================================
// [VERIFIED] sub_002526C0 (0x002526C0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002526C0 (0x002526C0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048E0B8;

int __cdecl sub_002526C0(int a1)
{
    DAT_0048E0B8 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00254620 (0x00254620, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087E60 (0x00087E60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00254620 (0x00254620, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B23FC[];

class Class_00254620
{
public:
    Class_00254620* sub_00254620();
    int m_Field00; // +0x00
};

Class_00254620* Class_00254620::sub_00254620()
{
    m_Field00 = (int)DAT_003B23FC;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00257D20 (0x00257D20, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00239CC0 (0x00239CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00257D20 (0x00257D20, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2754[];

class Class_00257D20
{
public:
    Class_00257D20* sub_00257D20();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_00257D20* Class_00257D20::sub_00257D20()
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_003B2754;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0025ADC0 (0x0025ADC0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00239CC0 (0x00239CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0025ADC0 (0x0025ADC0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2A78[];

class Class_0025ADC0
{
public:
    Class_0025ADC0* sub_0025ADC0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_0025ADC0* Class_0025ADC0::sub_0025ADC0()
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_003B2A78;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0025B110 (0x0025B110, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A6D00 (0x002A6D00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0025B110 (0x0025B110, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2AB4[];
extern "C" void __cdecl sub_002250E0(void);

class Class_0025B110
{
public:
    Class_0025B110* sub_0025B110();
    int m_Field00; // +0x00
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

Class_0025B110* Class_0025B110::sub_0025B110()
{
    sub_002250E0();
    m_Field00 = (int)DAT_003B2AB4;
    m_Field34 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0025B6B0 (0x0025B6B0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0028C390 (0x0028C390), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0025B6B0 (0x0025B6B0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2BE4[];
extern "C" void __cdecl sub_00225B20(void);

class Class_0025B6B0
{
public:
    Class_0025B6B0* sub_0025B6B0();
    int m_Field00; // +0x00
    char m_pad04[0xA4];
    int m_FieldA8; // +0xA8
    int m_FieldAC; // +0xAC
};

Class_0025B6B0* Class_0025B6B0::sub_0025B6B0()
{
    sub_00225B20();
    m_Field00 = (int)DAT_003B2BE4;
    m_FieldA8 = -1;
    m_FieldAC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0025C150 (0x0025C150, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A6D00 (0x002A6D00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0025C150 (0x0025C150, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2C84[];
extern "C" void __cdecl sub_002250E0(void);

class Class_0025C150
{
public:
    Class_0025C150* sub_0025C150();
    int m_Field00; // +0x00
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

Class_0025C150* Class_0025C150::sub_0025C150()
{
    sub_002250E0();
    m_Field00 = (int)DAT_003B2C84;
    m_Field34 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0025C400 (0x0025C400, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A6D00 (0x002A6D00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0025C400 (0x0025C400, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2D1C[];
extern "C" void __cdecl sub_002250E0(void);

class Class_0025C400
{
public:
    Class_0025C400* sub_0025C400();
    int m_Field00; // +0x00
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

Class_0025C400* Class_0025C400::sub_0025C400()
{
    sub_002250E0();
    m_Field00 = (int)DAT_003B2D1C;
    m_Field34 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0025C620 (0x0025C620, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A6D00 (0x002A6D00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0025C620 (0x0025C620, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2DB4[];
extern "C" void __cdecl sub_002250E0(void);

class Class_0025C620
{
public:
    Class_0025C620* sub_0025C620();
    int m_Field00; // +0x00
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

Class_0025C620* Class_0025C620::sub_0025C620()
{
    sub_002250E0();
    m_Field00 = (int)DAT_003B2DB4;
    m_Field34 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_002605A0 (0x002605A0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000179A0 (0x000179A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002605A0 (0x002605A0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042F954;
extern "C" int DAT_0042F958;

int __cdecl sub_002605A0(int a1, int a2)
{
    DAT_0042F954 = a1;
    DAT_0042F958 = a2;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00263470 (0x00263470, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00263470 (0x00263470, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048E8C0;

int __cdecl sub_00263470(int a1)
{
    DAT_0048E8C0 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00263790 (0x00263790, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00263790 (0x00263790, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0048E8C4;

bool __cdecl sub_00263790(bool a1)
{
    DAT_0048E8C4 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_002637A0 (0x002637A0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002637A0 (0x002637A0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048E8E0;

int __cdecl sub_002637A0(int a1)
{
    DAT_0048E8E0 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00264490 (0x00264490, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000732F0 (0x000732F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00264490 (0x00264490, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3858[];

class Class_00264490
{
public:
    void sub_00264490();
    int m_Field00; // +0x00
};

void Class_00264490::sub_00264490()
{
    m_Field00 = (int)DAT_003B3858;
}

// ============================================================================
// [VERIFIED] sub_0026C140 (0x0026C140, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A9880 (0x002A9880), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026C140 (0x0026C140, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual int vfunc_16();
};

extern "C" char DAT_0048E974[];
extern "C" int DAT_0048E990;
extern "C" void __cdecl sub_0023F180(int);
extern "C" void __cdecl sub_0023F190(int);

int __cdecl sub_0026C140(void)
{
    int t3;

    sub_0023F190((int)DAT_0048E974);
    t3 = ((Object*)DAT_0048E990)->vfunc_16();
    sub_0023F180((int)DAT_0048E974);
    return t3;
}

// ============================================================================
// [VERIFIED] sub_0026CD40 (0x0026CD40, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA530 (0x002AA530), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026CD40 (0x0026CD40, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_17(int, int, int);
};

extern "C" char DAT_0048E974[];
extern "C" int DAT_0048E990;
extern "C" void __cdecl sub_001B7A10(int);

void __cdecl sub_0026CD40(void)
{
    int local_4, local_8, local_C;

    sub_001B7A10((int)DAT_0048E974);
    ((Object*)DAT_0048E990)->vfunc_17((int)(&local_4), (int)(&local_8), (int)(&local_C));
    ((Object*)DAT_0048E990)->vfunc_01();
    DAT_0048E990 = 0;
}

// ============================================================================
// [VERIFIED] sub_0026D110 (0x0026D110, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D110 (0x0026D110, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3C3C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D110
{
public:
    Class_0026D110* sub_0026D110(int a1);
    int m_Field00; // +0x00
};

Class_0026D110* Class_0026D110::sub_0026D110(int a1)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3C3C;
    sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D130 (0x0026D130, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D130 (0x0026D130, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3C5C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D130
{
public:
    Class_0026D130* sub_0026D130(int a1);
    int m_Field00; // +0x00
};

Class_0026D130* Class_0026D130::sub_0026D130(int a1)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3C5C;
    sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D150 (0x0026D150, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA9D0 (0x002AA9D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D150 (0x0026D150, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020DC30();
};

extern "C" char DAT_003B3C7C[];
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D150
{
public:
    Class_0026D150* sub_0026D150(int a1, int a2, int a3, int a4);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_0026D150* Class_0026D150::sub_0026D150(int a1, int a2, int a3, int a4)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3C7C;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    ((Object*)a2)->sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D190 (0x0026D190, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA9D0 (0x002AA9D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D190 (0x0026D190, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020DC30();
};

extern "C" char DAT_003B3C9C[];
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D190
{
public:
    Class_0026D190* sub_0026D190(int a1, int a2, int a3, int a4);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_0026D190* Class_0026D190::sub_0026D190(int a1, int a2, int a3, int a4)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3C9C;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    ((Object*)a2)->sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D1D0 (0x0026D1D0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D1D0 (0x0026D1D0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020DC30();
};

extern "C" char DAT_003B3CBC[];
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D1D0
{
public:
    Class_0026D1D0* sub_0026D1D0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_0026D1D0* Class_0026D1D0::sub_0026D1D0(int a1, int a2)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3CBC;
    m_Field0C = a2;
    ((Object*)a2)->sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D200 (0x0026D200, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D200 (0x0026D200, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020DC30();
};

extern "C" char DAT_003B3CDC[];
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D200
{
public:
    Class_0026D200* sub_0026D200(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_0026D200* Class_0026D200::sub_0026D200(int a1, int a2)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3CDC;
    m_Field0C = a2;
    ((Object*)a2)->sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D230 (0x0026D230, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D230 (0x0026D230, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020DC30();
};

extern "C" char DAT_003B3CFC[];
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D230
{
public:
    Class_0026D230* sub_0026D230(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_0026D230* Class_0026D230::sub_0026D230(int a1, int a2)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3CFC;
    m_Field0C = a2;
    ((Object*)a2)->sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D2D0 (0x0026D2D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D2D0 (0x0026D2D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3D1C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D020(int);

class Class_0026D2D0
{
public:
    Class_0026D2D0* sub_0026D2D0(int a1);
    int m_Field00; // +0x00
};

Class_0026D2D0* Class_0026D2D0::sub_0026D2D0(int a1)
{
    sub_0026D020(a1);
    m_Field00 = (int)DAT_003B3D1C;
    sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D340 (0x0026D340, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D340 (0x0026D340, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3D3C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D2F0(int);

class Class_0026D340
{
public:
    Class_0026D340* sub_0026D340(int a1);
    int m_Field00; // +0x00
};

Class_0026D340* Class_0026D340::sub_0026D340(int a1)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3D3C;
    sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D360 (0x0026D360, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D360 (0x0026D360, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020DC30();
};

extern "C" char DAT_003B3D5C[];
extern "C" void __stdcall sub_0026D2F0(int);

class Class_0026D360
{
public:
    Class_0026D360* sub_0026D360(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_0026D360* Class_0026D360::sub_0026D360(int a1, int a2)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3D5C;
    m_Field0C = a2;
    ((Object*)a2)->sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D400 (0x0026D400, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D400 (0x0026D400, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3D7C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D2F0(int);

class Class_0026D400
{
public:
    Class_0026D400* sub_0026D400(int a1);
    int m_Field00; // +0x00
};

Class_0026D400* Class_0026D400::sub_0026D400(int a1)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3D7C;
    sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D420 (0x0026D420, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAC30 (0x002AAC30), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D420 (0x0026D420, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3D9C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D2F0(int);
extern "C" void __cdecl sub_002C9710(int, int, int);

class Class_0026D420
{
public:
    Class_0026D420* sub_0026D420(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xC];
    bool m_Field1C; // +0x1C
};

Class_0026D420* Class_0026D420::sub_0026D420(int a1, int a2)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3D9C;
    sub_0020DC30();
    sub_002C9710((int)(&m_Field0C), a2, 16);
    m_Field1C = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D460 (0x0026D460, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAC30 (0x002AAC30), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D460 (0x0026D460, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3DBC[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D2F0(int);
extern "C" void __cdecl sub_002C9710(int, int, int);

class Class_0026D460
{
public:
    Class_0026D460* sub_0026D460(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xC];
    bool m_Field1C; // +0x1C
};

Class_0026D460* Class_0026D460::sub_0026D460(int a1, int a2)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3DBC;
    sub_0020DC30();
    sub_002C9710((int)(&m_Field0C), a2, 16);
    m_Field1C = false;
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D4F0 (0x0026D4F0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D4F0 (0x0026D4F0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020DC30();
};

extern "C" char DAT_003B3DFC[];
extern "C" void __stdcall sub_0026D2F0(int);

class Class_0026D4F0
{
public:
    Class_0026D4F0* sub_0026D4F0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_0026D4F0* Class_0026D4F0::sub_0026D4F0(int a1, int a2)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3DFC;
    m_Field0C = a2;
    ((Object*)a2)->sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D520 (0x0026D520, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D520 (0x0026D520, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3E1C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D2F0(int);

class Class_0026D520
{
public:
    Class_0026D520* sub_0026D520(int a1);
    int m_Field00; // +0x00
};

Class_0026D520* Class_0026D520::sub_0026D520(int a1)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3E1C;
    sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D580 (0x0026D580, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D580 (0x0026D580, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3E5C[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __stdcall sub_0026D2F0(int);

class Class_0026D580
{
public:
    Class_0026D580* sub_0026D580(int a1);
    int m_Field00; // +0x00
};

Class_0026D580* Class_0026D580::sub_0026D580(int a1)
{
    sub_0026D2F0(a1);
    m_Field00 = (int)DAT_003B3E5C;
    sub_0020DC30();
    return this;
}

// ============================================================================
// [VERIFIED] sub_0026D5E0 (0x0026D5E0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A9880 (0x002A9880), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026D5E0 (0x0026D5E0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual int vfunc_16();
};

extern "C" char DAT_0048E994[];
extern "C" int DAT_0048E9B0;
extern "C" void __cdecl sub_0023F180(int);
extern "C" void __cdecl sub_0023F190(int);

int __cdecl sub_0026D5E0(void)
{
    int t3;

    sub_0023F190((int)DAT_0048E994);
    t3 = ((Object*)DAT_0048E9B0)->vfunc_16();
    sub_0023F180((int)DAT_0048E994);
    return t3;
}

// ============================================================================
// [VERIFIED] sub_0026DB20 (0x0026DB20, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA530 (0x002AA530), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026DB20 (0x0026DB20, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_17(int, int, int);
};

extern "C" char DAT_0048E994[];
extern "C" int DAT_0048E9B0;
extern "C" void __cdecl sub_001B7A10(int);

void __cdecl sub_0026DB20(void)
{
    int local_4, local_8, local_C;

    sub_001B7A10((int)DAT_0048E994);
    ((Object*)DAT_0048E9B0)->vfunc_17((int)(&local_4), (int)(&local_8), (int)(&local_C));
    ((Object*)DAT_0048E9B0)->vfunc_01();
    DAT_0048E9B0 = 0;
}

// ============================================================================
// [VERIFIED] sub_0026DE00 (0x0026DE00, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A9880 (0x002A9880), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026DE00 (0x0026DE00, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual int vfunc_16();
};

extern "C" char DAT_0048E9B4[];
extern "C" int DAT_0048E9D0;
extern "C" void __cdecl sub_0023F180(int);
extern "C" void __cdecl sub_0023F190(int);

int __cdecl sub_0026DE00(void)
{
    int t3;

    sub_0023F190((int)DAT_0048E9B4);
    t3 = ((Object*)DAT_0048E9D0)->vfunc_16();
    sub_0023F180((int)DAT_0048E9B4);
    return t3;
}

// ============================================================================
// [VERIFIED] sub_0026E760 (0x0026E760, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA530 (0x002AA530), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026E760 (0x0026E760, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_17(int, int, int);
};

extern "C" char DAT_0048E9B4[];
extern "C" int DAT_0048E9D0;
extern "C" void __cdecl sub_001B7A10(int);

void __cdecl sub_0026E760(void)
{
    int local_4, local_8, local_C;

    sub_001B7A10((int)DAT_0048E9B4);
    ((Object*)DAT_0048E9D0)->vfunc_17((int)(&local_4), (int)(&local_8), (int)(&local_C));
    ((Object*)DAT_0048E9D0)->vfunc_01();
    DAT_0048E9D0 = 0;
}

// ============================================================================
// [VERIFIED] sub_0026EE10 (0x0026EE10, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AC690 (0x002AC690), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026EE10 (0x0026EE10, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldD4
{
    void sub_00285090();
};

class Class_0026EE10
{
public:
    void sub_0026EE10();
    char m_pad00[0xD4];
    FieldD4* m_FieldD4; // +0xD4
};

void Class_0026EE10::sub_0026EE10()
{
    m_FieldD4->sub_00285090();
}

// ============================================================================
// [VERIFIED] sub_0026EE20 (0x0026EE20, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AC690 (0x002AC690), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026EE20 (0x0026EE20, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldD4
{
    void sub_00285120();
};

class Class_0026EE20
{
public:
    void sub_0026EE20();
    char m_pad00[0xD4];
    FieldD4* m_FieldD4; // +0xD4
};

void Class_0026EE20::sub_0026EE20()
{
    m_FieldD4->sub_00285120();
}

// ============================================================================
// [VERIFIED] sub_0026EE30 (0x0026EE30, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AC690 (0x002AC690), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0026EE30 (0x0026EE30, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldD4
{
    void sub_002851C0();
};

class Class_0026EE30
{
public:
    void sub_0026EE30();
    char m_pad00[0xD4];
    FieldD4* m_FieldD4; // +0xD4
};

void Class_0026EE30::sub_0026EE30()
{
    m_FieldD4->sub_002851C0();
}

// ============================================================================
// [VERIFIED] sub_0027A5E0 (0x0027A5E0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0027A5E0 (0x0027A5E0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00288E00(void);

class Class_0027A5E0
{
public:
    void sub_0027A5E0();
};

void Class_0027A5E0::sub_0027A5E0()
{
    sub_00288E00();
}

// ============================================================================
// [VERIFIED] sub_002807A0 (0x002807A0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000179A0 (0x000179A0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002807A0 (0x002807A0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004327E8;
extern "C" int DAT_004327EC;

int __cdecl sub_002807A0(int a1, int a2)
{
    DAT_004327E8 = a1;
    DAT_004327EC = a2;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_002910F0 (0x002910F0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E42D0 (0x000E42D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002910F0 (0x002910F0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00291070(int);

class Class_002910F0
{
public:
    Class_002910F0* sub_002910F0(int a1);
};

Class_002910F0* Class_002910F0::sub_002910F0(int a1)
{
    sub_00291070(a1);
    return this;
}

// ============================================================================
// [VERIFIED] sub_002913C0 (0x002913C0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002913C0 (0x002913C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490AE8[];
extern "C" void __stdcall sub_00293590(int);

class Class_002913C0
{
public:
    void sub_002913C0(int a1);
};

void Class_002913C0::sub_002913C0(int a1)
{
    a1 = (int)DAT_00490AE8;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002913D0 (0x002913D0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002913D0 (0x002913D0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490AE8[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_002913D0(int a1)
{
    sub_002935D0((int)DAT_00490AE8, a1);
}

// ============================================================================
// [VERIFIED] sub_00291530 (0x00291530, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291530 (0x00291530, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B00[];
extern "C" void __stdcall sub_00293590(int);

class Class_00291530
{
public:
    void sub_00291530(int a1);
};

void Class_00291530::sub_00291530(int a1)
{
    a1 = (int)DAT_00490B00;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00291540 (0x00291540, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291540 (0x00291540, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B00[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00291540(int a1)
{
    sub_002935D0((int)DAT_00490B00, a1);
}

// ============================================================================
// [VERIFIED] sub_00291560 (0x00291560, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291560 (0x00291560, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B14[];
extern "C" void __stdcall sub_00293590(int);

class Class_00291560
{
public:
    void sub_00291560(int a1);
};

void Class_00291560::sub_00291560(int a1)
{
    a1 = (int)DAT_00490B14;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00291570 (0x00291570, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291570 (0x00291570, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B28[];
extern "C" void __stdcall sub_00293590(int);

class Class_00291570
{
public:
    void sub_00291570(int a1);
};

void Class_00291570::sub_00291570(int a1)
{
    a1 = (int)DAT_00490B28;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00291580 (0x00291580, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291580 (0x00291580, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B28[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00291580(int a1)
{
    sub_002935D0((int)DAT_00490B28, a1);
}

// ============================================================================
// [VERIFIED] sub_002915A0 (0x002915A0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002915A0 (0x002915A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B3C[];
extern "C" void __stdcall sub_00293590(int);

class Class_002915A0
{
public:
    void sub_002915A0(int a1);
};

void Class_002915A0::sub_002915A0(int a1)
{
    a1 = (int)DAT_00490B3C;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002915B0 (0x002915B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002915B0 (0x002915B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B3C[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_002915B0(int a1)
{
    sub_002935D0((int)DAT_00490B3C, a1);
}

// ============================================================================
// [VERIFIED] sub_002916B0 (0x002916B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002916B0 (0x002916B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490AFC;

int __cdecl sub_002916B0(void)
{
    return DAT_00490AFC;
}

// ============================================================================
// [VERIFIED] sub_00291B30 (0x00291B30, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291B30 (0x00291B30, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00291930(void);

class Class_00291B30
{
public:
    void sub_00291B30();
};

void Class_00291B30::sub_00291B30()
{
    sub_00291930();
}

// ============================================================================
// [VERIFIED] sub_00291D70 (0x00291D70, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291D70 (0x00291D70, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B64[];
extern "C" void __stdcall sub_00293590(int);

class Class_00291D70
{
public:
    void sub_00291D70(int a1);
};

void Class_00291D70::sub_00291D70(int a1)
{
    a1 = (int)DAT_00490B64;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00291D80 (0x00291D80, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00291D80 (0x00291D80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B64[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00291D80(int a1)
{
    sub_002935D0((int)DAT_00490B64, a1);
}

// ============================================================================
// [VERIFIED] sub_002923B0 (0x002923B0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000704F0 (0x000704F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002923B0 (0x002923B0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00291E30(int);
};

extern "C" Object DAT_00490B78;

void __cdecl sub_002923B0(int a1)
{
    DAT_00490B78.sub_00291E30(a1);
}

// ============================================================================
// [VERIFIED] sub_002927D0 (0x002927D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002927D0 (0x002927D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490B8C[];

void* __cdecl sub_002927D0(void)
{
    return DAT_00490B8C;
}

// ============================================================================
// [VERIFIED] sub_002932C0 (0x002932C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000704F0 (0x000704F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002932C0 (0x002932C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00293030(int);
};

extern "C" Object DAT_00490BC4;

void __cdecl sub_002932C0(int a1)
{
    DAT_00490BC4.sub_00293030(a1);
}

// ============================================================================
// [VERIFIED] sub_00293580 (0x00293580, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00244420 (0x00244420), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00293580 (0x00293580, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00434418;

int __cdecl sub_00293580(int a1)
{
    int t1;

    t1 = DAT_00434418;
    DAT_00434418 = a1;
    return t1;
}

// ============================================================================
// [VERIFIED] sub_00293670 (0x00293670, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000B7EE0 (0x000B7EE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00293670 (0x00293670, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B927C[];

class Class_00293670
{
public:
    Class_00293670* sub_00293670(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

Class_00293670* Class_00293670::sub_00293670(int a1, int a2)
{
    m_Field00 = (int)DAT_003B927C;
    m_Field04 = a1;
    m_Field08 = a2;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00293AC0 (0x00293AC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00293AC0 (0x00293AC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043444C[];

void* __cdecl sub_00293AC0(void)
{
    return DAT_0043444C;
}

// ============================================================================
// [VERIFIED] sub_00294A80 (0x00294A80, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00294A80 (0x00294A80, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490C2C[];
extern "C" void __stdcall sub_00293590(int);

class Class_00294A80
{
public:
    void sub_00294A80(int a1);
};

void Class_00294A80::sub_00294A80(int a1)
{
    a1 = (int)DAT_00490C2C;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00294A90 (0x00294A90, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00294A90 (0x00294A90, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490C2C[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00294A90(int a1)
{
    sub_002935D0((int)DAT_00490C2C, a1);
}

// ============================================================================
// [VERIFIED] sub_00294AB0 (0x00294AB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00294AB0 (0x00294AB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490C10;

int __cdecl sub_00294AB0(void)
{
    return DAT_00490C10;
}

// ============================================================================
// [VERIFIED] sub_00294C80 (0x00294C80, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00294C80 (0x00294C80, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003B93FC[];
extern "C" char DAT_003B9444[];
extern "C" int DAT_00490C20;
extern "C" int __cdecl sub_00291D70(int);

class Class_00294C80
{
public:
    Class_00294C80* sub_00294C80(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_00294C80* Class_00294C80::sub_00294C80(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003B9444;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003B93FC;
        DAT_00490C20 = t2;
        return this;
    }
    DAT_00490C20 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00294D40 (0x00294D40, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00294D40 (0x00294D40, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003B9414[];
extern "C" char DAT_003B9458[];
extern "C" int DAT_00490C24;
extern "C" int __cdecl sub_00291D70(int);

class Class_00294D40
{
public:
    Class_00294D40* sub_00294D40(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_00294D40* Class_00294D40::sub_00294D40(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003B9458;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003B9414;
        DAT_00490C24 = t2;
        return this;
    }
    DAT_00490C24 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00294E70 (0x00294E70, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00294E70 (0x00294E70, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003B942C[];
extern "C" char DAT_003B94AC[];
extern "C" int DAT_00490C28;
extern "C" int __cdecl sub_00291D70(int);

class Class_00294E70
{
public:
    Class_00294E70* sub_00294E70(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_00294E70* Class_00294E70::sub_00294E70(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003B94AC;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003B942C;
        DAT_00490C28 = t2;
        return this;
    }
    DAT_00490C28 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00295BA0 (0x00295BA0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00295BA0 (0x00295BA0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490CC8[];
extern "C" void __stdcall sub_00293590(int);

class Class_00295BA0
{
public:
    void sub_00295BA0(int a1);
};

void Class_00295BA0::sub_00295BA0(int a1)
{
    a1 = (int)DAT_00490CC8;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00295BB0 (0x00295BB0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00295BB0 (0x00295BB0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490CC8[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00295BB0(int a1)
{
    sub_002935D0((int)DAT_00490CC8, a1);
}

// ============================================================================
// [VERIFIED] sub_00295CA0 (0x00295CA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00090660 (0x00090660), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00295CA0 (0x00295CA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490C88[];

void* __cdecl sub_00295CA0(void)
{
    return DAT_00490C88;
}

// ============================================================================
// [VERIFIED] sub_00295D20 (0x00295D20, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00295D20 (0x00295D20, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_00490CC4;

bool __cdecl sub_00295D20(bool a1)
{
    DAT_00490CC4 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_00296350 (0x00296350, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00296350 (0x00296350, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490D00[];
extern "C" void __stdcall sub_00293590(int);

class Class_00296350
{
public:
    void sub_00296350(int a1);
};

void Class_00296350::sub_00296350(int a1)
{
    a1 = (int)DAT_00490D00;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00296360 (0x00296360, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00296360 (0x00296360, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490D00[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00296360(int a1)
{
    sub_002935D0((int)DAT_00490D00, a1);
}

// ============================================================================
// [VERIFIED] sub_00297430 (0x00297430, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00297430 (0x00297430, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490D14[];
extern "C" void __stdcall sub_00293590(int);

class Class_00297430
{
public:
    void sub_00297430(int a1);
};

void Class_00297430::sub_00297430(int a1)
{
    a1 = (int)DAT_00490D14;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_00297440 (0x00297440, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00297440 (0x00297440, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490D14[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_00297440(int a1)
{
    sub_002935D0((int)DAT_00490D14, a1);
}

// ============================================================================
// [VERIFIED] sub_00298040 (0x00298040, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00298040 (0x00298040, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003B95C0[];
extern "C" char DAT_003B961C[];
extern "C" int DAT_00490D3C;
extern "C" int __cdecl sub_00291D70(int);

class Class_00298040
{
public:
    Class_00298040* sub_00298040(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_00298040* Class_00298040::sub_00298040(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003B961C;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003B95C0;
        DAT_00490D3C = t2;
        return this;
    }
    DAT_00490D3C = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_00298900 (0x00298900, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00298900 (0x00298900, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00434A2C;

int __cdecl sub_00298900(void)
{
    return DAT_00434A2C;
}

// ============================================================================
// [VERIFIED] sub_00298A20 (0x00298A20, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00298A20 (0x00298A20, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490D5C[];
extern "C" void __stdcall sub_00293590(int);

class Class_00298A20
{
public:
    void sub_00298A20(int a1);
};

void Class_00298A20::sub_00298A20(int a1)
{
    a1 = (int)DAT_00490D5C;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_0029B4E0 (0x0029B4E0, 83 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065E70 (0x00065E70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029B4E0 (0x0029B4E0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F91F0[];
extern "C" char DAT_003FD824[];
extern "C" int __cdecl sub_00292EA0(int);
extern "C" int __cdecl sub_002932C0(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

int __cdecl sub_0029B4E0(int a1)
{
    int r_eax, r_esi;

    r_eax = sub_002932C0(a1);
    r_esi = r_eax;
    if (!r_esi) goto L_4E;
L_15:
    r_eax = *(int*)(r_esi + 24);
    if (r_eax == *(int*)a1) {
        if (*(int*)(r_esi + 28) != *(int*)(a1 + 4)) goto L_4E;
        r_eax = sub_002C92F8(r_esi, 0, (int)DAT_003F91F0, (int)DAT_003FD824, 0);
        if (r_eax) goto L_50;
        r_eax = sub_00292EA0(r_esi);
        r_esi = r_eax;
        if (r_esi) goto L_15;
    }
L_4E:
    r_eax = 0;
L_50:
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_0029C6A0 (0x0029C6A0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029C6A0 (0x0029C6A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490DB4[];
extern "C" void __stdcall sub_00293590(int);

class Class_0029C6A0
{
public:
    void sub_0029C6A0(int a1);
};

void Class_0029C6A0::sub_0029C6A0(int a1)
{
    a1 = (int)DAT_00490DB4;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_0029C6B0 (0x0029C6B0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029C6B0 (0x0029C6B0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490DC8[];
extern "C" void __stdcall sub_00293590(int);

class Class_0029C6B0
{
public:
    void sub_0029C6B0(int a1);
};

void Class_0029C6B0::sub_0029C6B0(int a1)
{
    a1 = (int)DAT_00490DC8;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_0029CDA0 (0x0029CDA0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_002916D0();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_0029CDA0
{
public:
    void sub_0029CDA0();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_0029CDA0::sub_0029CDA0()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_002916D0();
    }
}

// ============================================================================
// [VERIFIED] sub_0029CDD0 (0x0029CDD0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_002916E0();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_0029CDD0
{
public:
    void sub_0029CDD0();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_0029CDD0::sub_0029CDD0()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_002916E0();
    }
}

// ============================================================================
// [VERIFIED] sub_0029CE00 (0x0029CE00, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_002916F0();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_0029CE00
{
public:
    void sub_0029CE00();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_0029CE00::sub_0029CE00()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_002916F0();
    }
}

// ============================================================================
// [VERIFIED] sub_0029CE30 (0x0029CE30, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_00291700();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_0029CE30
{
public:
    void sub_0029CE30();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_0029CE30::sub_0029CE30()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_00291700();
    }
}

// ============================================================================
// [VERIFIED] sub_0029E580 (0x0029E580, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5C0 (0x0001E5C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029E580 (0x0029E580, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490E80;

int __cdecl sub_0029E580(int a1)
{
    DAT_00490E80 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] sub_0029EF10 (0x0029EF10, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029EF10 (0x0029EF10, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490E98[];
extern "C" void __stdcall sub_00293590(int);

class Class_0029EF10
{
public:
    void sub_0029EF10(int a1);
};

void Class_0029EF10::sub_0029EF10(int a1)
{
    a1 = (int)DAT_00490E98;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_0029EF20 (0x0029EF20, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029EF20 (0x0029EF20, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490E98[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_0029EF20(int a1)
{
    sub_002935D0((int)DAT_00490E98, a1);
}

// ============================================================================
// [VERIFIED] sub_0029F610 (0x0029F610, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029F610 (0x0029F610, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490EC4[];
extern "C" void __stdcall sub_00293590(int);

class Class_0029F610
{
public:
    void sub_0029F610(int a1);
};

void Class_0029F610::sub_0029F610(int a1)
{
    a1 = (int)DAT_00490EC4;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_0029FFA0 (0x0029FFA0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0029FFA0 (0x0029FFA0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490F04[];
extern "C" void __stdcall sub_00293590(int);

class Class_0029FFA0
{
public:
    void sub_0029FFA0(int a1);
};

void Class_0029FFA0::sub_0029FFA0(int a1)
{
    a1 = (int)DAT_00490F04;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002A0000 (0x002A0000, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002A0000 (0x002A0000, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002926C0(int, int);
};

extern "C" char DAT_003B9C78[];
extern "C" char DAT_003B9C90[];
extern "C" int DAT_00490F2C;
extern "C" int __cdecl sub_00291D70(int);

class Class_002A0000
{
public:
    Class_002A0000* sub_002A0000(int a1, int a2, int a3, int a4);
    void sub_00293130(int, int, int, int);
    int m_Field00; // +0x00
};

Class_002A0000* Class_002A0000::sub_002A0000(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_00293130(a1, a2, a3, a4);
    m_Field00 = (int)DAT_003B9C90;
    t2 = sub_00291D70(88);
    if (t2) {
        ((Object*)t2)->sub_002926C0(a1, 0);
        *(int*)t2 = (int)DAT_003B9C78;
        DAT_00490F2C = t2;
        return this;
    }
    DAT_00490F2C = 0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_002AC4B0 (0x002AC4B0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC4B0 (0x002AC4B0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004913F4[];
extern "C" void __stdcall sub_00293590(int);

class Class_002AC4B0
{
public:
    void sub_002AC4B0(int a1);
};

void Class_002AC4B0::sub_002AC4B0(int a1)
{
    a1 = (int)DAT_004913F4;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002AC4C0 (0x002AC4C0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC4C0 (0x002AC4C0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004913F4[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_002AC4C0(int a1)
{
    sub_002935D0((int)DAT_004913F4, a1);
}

// ============================================================================
// [VERIFIED] sub_002AC4E0 (0x002AC4E0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC4E0 (0x002AC4E0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491408[];
extern "C" void __stdcall sub_00293590(int);

class Class_002AC4E0
{
public:
    void sub_002AC4E0(int a1);
};

void Class_002AC4E0::sub_002AC4E0(int a1)
{
    a1 = (int)DAT_00491408;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002AC4F0 (0x002AC4F0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC4F0 (0x002AC4F0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0049141C[];
extern "C" void __stdcall sub_00293590(int);

class Class_002AC4F0
{
public:
    void sub_002AC4F0(int a1);
};

void Class_002AC4F0::sub_002AC4F0(int a1)
{
    a1 = (int)DAT_0049141C;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002AC680 (0x002AC680, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC680 (0x002AC680, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491430[];
extern "C" void __stdcall sub_00293590(int);

class Class_002AC680
{
public:
    void sub_002AC680(int a1);
};

void Class_002AC680::sub_002AC680(int a1)
{
    a1 = (int)DAT_00491430;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002AC690 (0x002AC690, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC690 (0x002AC690, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491430[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_002AC690(int a1)
{
    sub_002935D0((int)DAT_00491430, a1);
}

// ============================================================================
// [VERIFIED] sub_002AC6B0 (0x002AC6B0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC6B0 (0x002AC6B0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491444[];
extern "C" void __stdcall sub_00293590(int);

class Class_002AC6B0
{
public:
    void sub_002AC6B0(int a1);
};

void Class_002AC6B0::sub_002AC6B0(int a1)
{
    a1 = (int)DAT_00491444;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002AC6C0 (0x002AC6C0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AC6C0 (0x002AC6C0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491444[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_002AC6C0(int a1)
{
    sub_002935D0((int)DAT_00491444, a1);
}

// ============================================================================
// [VERIFIED] sub_002ADB70 (0x002ADB70, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002ADB70 (0x002ADB70, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491494[];
extern "C" void __stdcall sub_00293590(int);

class Class_002ADB70
{
public:
    void sub_002ADB70(int a1);
};

void Class_002ADB70::sub_002ADB70(int a1)
{
    a1 = (int)DAT_00491494;
    sub_00293590(a1);
}

// ============================================================================
// [VERIFIED] sub_002ADB80 (0x002ADB80, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002ADB80 (0x002ADB80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491494[];
extern "C" void __cdecl sub_002935D0(int, int);

void __cdecl sub_002ADB80(int a1)
{
    sub_002935D0((int)DAT_00491494, a1);
}

// ============================================================================
// [VERIFIED] sub_002AFC20 (0x002AFC20, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002AFC20 (0x002AFC20, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002AFBF0(void);

class Class_002AFC20
{
public:
    void sub_002AFC20();
};

void Class_002AFC20::sub_002AFC20()
{
    sub_002AFBF0();
}

// ============================================================================
// [VERIFIED] sub_002B21E0 (0x002B21E0, 135 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00013870 (0x00013870), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002B21E0 (0x002B21E0, 135 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_002B21E0
{
public:
    Class_002B21E0* sub_002B21E0(int a1);
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
    unsigned short m_Field30; // +0x30
    unsigned short m_Field32; // +0x32
    int m_Field34; // +0x34
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    unsigned short m_Field44; // +0x44
    unsigned short m_Field46; // +0x46
};

Class_002B21E0* Class_002B21E0::sub_002B21E0(int a1)
{
    m_Field00 = *(int*)a1;
    m_Field04 = *(int*)(a1 + 4);
    m_Field08 = *(int*)(a1 + 8);
    m_Field0C = *(int*)(a1 + 12);
    m_Field10 = *(int*)(a1 + 16);
    m_Field14 = *(int*)(a1 + 20);
    m_Field18 = *(int*)(a1 + 24);
    m_Field1C = *(int*)(a1 + 28);
    m_Field20 = *(int*)(a1 + 32);
    m_Field24 = *(int*)(a1 + 36);
    m_Field28 = *(int*)(a1 + 40);
    m_Field2C = *(int*)(a1 + 44);
    m_Field30 = *(unsigned short*)(a1 + 48);
    m_Field32 = *(unsigned short*)(a1 + 50);
    m_Field34 = *(int*)(a1 + 52);
    m_Field38 = *(int*)(a1 + 56);
    m_Field3C = *(int*)(a1 + 60);
    m_Field40 = *(int*)(a1 + 64);
    m_Field44 = *(unsigned short*)(a1 + 68);
    m_Field46 = *(unsigned short*)(a1 + 70);
    return this;
}

// ============================================================================
// [VERIFIED] sub_002B6620 (0x002B6620, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002E8E50 (0x002E8E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002B6620 (0x002B6620, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002C47A0();
};

extern "C" Object DAT_004915D8;
extern "C" int DAT_004915DC;
extern "C" int DAT_004915E0;
extern "C" int DAT_004915E4;

class Class_002B6620
{
public:
    void sub_002B6620();
    char m_pad00[0x8];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Class_002B6620::sub_002B6620()
{
    DAT_004915DC = m_Field08;
    DAT_004915E0 = m_Field0C;
    DAT_004915E4 = m_Field10;
    DAT_004915D8.sub_002C47A0();
}

// ============================================================================
// [VERIFIED] sub_002B6650 (0x002B6650, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002E8E50 (0x002E8E50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002B6650 (0x002B6650, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002C44A0();
};

extern "C" Object DAT_004915D8;
extern "C" int DAT_004915DC;
extern "C" int DAT_004915E0;
extern "C" int DAT_004915E4;

class Class_002B6650
{
public:
    void sub_002B6650();
    char m_pad00[0x8];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Class_002B6650::sub_002B6650()
{
    DAT_004915DC = m_Field08;
    DAT_004915E0 = m_Field0C;
    DAT_004915E4 = m_Field10;
    DAT_004915D8.sub_002C44A0();
}

// ============================================================================
// [VERIFIED] sub_002B76F0 (0x002B76F0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002E9670 (0x002E9670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002B76F0 (0x002B76F0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00202300(int);
};

class Class_002B76F0
{
public:
    void sub_002B76F0();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

void Class_002B76F0::sub_002B76F0()
{
    ((Object*)(int)this + 28)->sub_00202300((int)(&m_Field04));
}

// ============================================================================
// [VERIFIED] sub_002B7890 (0x002B7890, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002E9670 (0x002E9670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002B7890 (0x002B7890, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00201E30(int);
};

class Class_002B7890
{
public:
    void sub_002B7890();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

void Class_002B7890::sub_002B7890()
{
    ((Object*)(int)this + 28)->sub_00201E30((int)(&m_Field04));
}

// ============================================================================
// [VERIFIED] sub_002B7F80 (0x002B7F80, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00163FA0 (0x00163FA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002B7F80 (0x002B7F80, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002BCBE0();
};

extern "C" Object DAT_004916A0;

void __cdecl sub_002B7F80(void)
{
    DAT_004916A0.sub_002BCBE0();
}

// ============================================================================
// [VERIFIED] sub_002BBEC0 (0x002BBEC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002BBEC0 (0x002BBEC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491698;

int __cdecl sub_002BBEC0(void)
{
    return DAT_00491698;
}

// ============================================================================
// [VERIFIED] sub_002BC300 (0x002BC300, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0006DCA0 (0x0006DCA0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002BC300 (0x002BC300, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002BBFA0();
};

extern "C" int DAT_00491698;
extern "C" void __cdecl sub_00025160(int);

void __cdecl sub_002BC300(void)
{
    int t1;

    t1 = DAT_00491698;
    if (DAT_00491698) {
        ((Object*)DAT_00491698)->sub_002BBFA0();
        sub_00025160(t1);
    }
    DAT_00491698 = 0;
}

// ============================================================================
// [VERIFIED] sub_002C8DAE (0x002C8DAE, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FBAEA (0x002FBAEA), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002C8DAE (0x002C8DAE, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002C8DAE(void)
{
    sub_002CCC48(14);
}

// ============================================================================
// [VERIFIED] sub_002C96FE (0x002C96FE, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002C96FE (0x002C96FE, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002C96A6(void);

class Class_002C96FE
{
public:
    void sub_002C96FE();
};

void Class_002C96FE::sub_002C96FE()
{
    sub_002C96A6();
}

// ============================================================================
// [VERIFIED] sub_002CA3ED (0x002CA3ED, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FD0ED (0x002FD0ED), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CA3ED (0x002CA3ED, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCCFA(int);

void __cdecl sub_002CA3ED(void)
{
    sub_002CCCFA(8);
}

// ============================================================================
// [VERIFIED] sub_002CA3F6 (0x002CA3F6, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FD0ED (0x002FD0ED), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CA3F6 (0x002CA3F6, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CA3F6(void)
{
    sub_002CCC48(8);
}

// ============================================================================
// [VERIFIED] sub_002CA7A1 (0x002CA7A1, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FBAEA (0x002FBAEA), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CA7A1 (0x002CA7A1, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CA7A1(void)
{
    sub_002CCC48(14);
}

// ============================================================================
// [VERIFIED] sub_002CB479 (0x002CB479, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FE199 (0x002FE199), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CB479 (0x002CB479, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CB479(void)
{
    sub_002CCC48(4);
}

// ============================================================================
// [VERIFIED] sub_002CC6DE (0x002CC6DE, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FEF14 (0x002FEF14), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CC6DE (0x002CC6DE, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CC6DE(void)
{
    sub_002CCC48(13);
}

// ============================================================================
// [VERIFIED] sub_002CCCF1 (0x002CCCF1, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FF527 (0x002FF527), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CCCF1 (0x002CCCF1, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CCCF1(void)
{
    sub_002CCC48(10);
}

// ============================================================================
// [VERIFIED] sub_002CCDCF (0x002CCDCF, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FE199 (0x002FE199), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CCDCF (0x002CCDCF, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CCDCF(void)
{
    sub_002CCC48(4);
}

// ============================================================================
// [VERIFIED] sub_002CCE65 (0x002CCE65, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FE199 (0x002FE199), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CCE65 (0x002CCE65, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CCE65(void)
{
    sub_002CCC48(4);
}

// ============================================================================
// [VERIFIED] sub_002CCF25 (0x002CCF25, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FF75B (0x002FF75B), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CCF25 (0x002CCF25, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BBEB8[];
extern "C" void __stdcall sub_002CCE6E(int);

class Class_002CCF25
{
public:
    Class_002CCF25* sub_002CCF25(int a1);
    int m_Field00; // +0x00
};

Class_002CCF25* Class_002CCF25::sub_002CCF25(int a1)
{
    sub_002CCE6E((int)(&a1));
    m_Field00 = (int)DAT_003BBEB8;
    return this;
}

// ============================================================================
// [VERIFIED] sub_002CCF56 (0x002CCF56, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CCF56 (0x002CCF56, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BBEB8[];
extern "C" void __cdecl sub_002CCF02(void);

class Class_002CCF56
{
public:
    void sub_002CCF56();
    int m_Field00; // +0x00
};

void Class_002CCF56::sub_002CCF56()
{
    m_Field00 = (int)DAT_003BBEB8;
    sub_002CCF02();
}

// ============================================================================
// [VERIFIED] sub_002CCF61 (0x002CCF61, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FF75B (0x002FF75B), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CCF61 (0x002CCF61, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BBEC0[];
extern "C" void __stdcall sub_002CCE6E(int);

class Class_002CCF61
{
public:
    Class_002CCF61* sub_002CCF61(int a1);
    int m_Field00; // +0x00
};

Class_002CCF61* Class_002CCF61::sub_002CCF61(int a1)
{
    sub_002CCE6E((int)(&a1));
    m_Field00 = (int)DAT_003BBEC0;
    return this;
}

// ============================================================================
// [VERIFIED] sub_002CCFC2 (0x002CCFC2, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000217F0 (0x000217F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CCFC2 (0x002CCFC2, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BBEC0[];
extern "C" void __cdecl sub_002CCF02(void);

class Class_002CCFC2
{
public:
    void sub_002CCFC2();
    int m_Field00; // +0x00
};

void Class_002CCFC2::sub_002CCFC2()
{
    m_Field00 = (int)DAT_003BBEC0;
    sub_002CCF02();
}

// ============================================================================
// [VERIFIED] sub_002CEB59 (0x002CEB59, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00063CC0 (0x00063CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CEB59 (0x002CEB59, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CEB59(void)
{
    sub_002CCC48(1);
}

// ============================================================================
// [VERIFIED] sub_002CECB9 (0x002CECB9, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00063CC0 (0x00063CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CECB9 (0x002CECB9, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002CECB9(void)
{
    sub_002CCC48(1);
}

// ============================================================================
// [VERIFIED] sub_002CECC2 (0x002CECC2, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00063CC0 (0x00063CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002CECC2 (0x002CECC2, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CEBED(int);

void __cdecl sub_002CECC2(void)
{
    sub_002CEBED(1);
}

// ============================================================================
// [VERIFIED] sub_002D51FF (0x002D51FF, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00063CC0 (0x00063CC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002D51FF (0x002D51FF, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002D51FF(void)
{
    sub_002CCC48(1);
}

// ============================================================================
// [VERIFIED] sub_002D54F3 (0x002D54F3, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FEF14 (0x002FEF14), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002D54F3 (0x002D54F3, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002D54F3(void)
{
    sub_002CCC48(13);
}

// ============================================================================
// [VERIFIED] sub_002D5D8D (0x002D5D8D, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00702F18 (PC 0x00702F18), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002D5D8D (PC 0x002D5D8D, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_002D5D8D(void)
{
    return 0;
}

// ============================================================================
// [VERIFIED] sub_002D65C0 (0x002D65C0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FF527 (0x002FF527), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002D65C0 (0x002D65C0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002D65C0(void)
{
    sub_002CCC48(10);
}

// ============================================================================
// [VERIFIED] sub_002D66C4 (0x002D66C4, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002FF527 (0x002FF527), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002D66C4 (0x002D66C4, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CCC48(int);

void __cdecl sub_002D66C4(void)
{
    sub_002CCC48(10);
}

// ============================================================================
// [VERIFIED] sub_002D89B4 (0x002D89B4, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_002D89B4 (0x002D89B4, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0037C7D4;

class Class_002D89B4
{
public:
    void sub_002D89B4();
};

void Class_002D89B4::sub_002D89B4()
{
    ((void (__cdecl*)(void))DAT_0037C7D4)();
}

