// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PS2 SLUS_211.11, engine/CharacterObject.cpp (15 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 15 of 61 functions matched (24.59%). NOT COMPLETE YET.
// The 46 still to do are listed in their place in Original_Binary_Order_PS2.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Metrowerks CodeWarrior for PS2 3.0.1 (decomp.me: mwcps2-3.0.1b103-040528).
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_51 (0x0037DA70, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Stores its argument as a byte at +0x451 of its object.
class Object
{
public:
    void Set(char value);
    char m_pad00[0x451];
    char m_Field451; // +0x451
};

void Object::Set(char value)
{
    m_Field451 = value;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x00396150, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080B930.
extern char D_0080B930[];

char* Get()
{
    return D_0080B930;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_44 (0x00396170, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Stores its argument as a float at +0x1C8 of its object.
class Object
{
public:
    void Set(float value);
    char m_pad00[0x1C8];
    float m_Field1C8; // +0x1C8
};

void Object::Set(float value)
{
    m_Field1C8 = value;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_45 (0x00396180, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the float at +0x1C8 of its object.
class Object
{
public:
    float Get();
    char m_pad00[0x1C8];
    float m_Field1C8; // +0x1C8
};

float Object::Get()
{
    return m_Field1C8;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_50 (0x00396190, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns a byte at +0x451 of its object.
class Object
{
public:
    unsigned char Get();
    char m_pad00[0x451];
    unsigned char m_Field451; // +0x451
};

unsigned char Object::Get()
{
    return m_Field451;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_48 (0x00398690, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the float at +0x130 of its object.
class Object
{
public:
    float Get();
    char m_pad00[0x130];
    float m_Field130; // +0x130
};

float Object::Get()
{
    return m_Field130;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_56 (0x003A27F0, 16 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly -Cpp_exceptions off
// ============================================================================
// Calls its own virtual method number 55 and lets it return to this function's caller.
class Object
{
public:
    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
    virtual void Method3();
    virtual void Method4();
    virtual void Method5();
    virtual void Method6();
    virtual void Method7();
    virtual void Method8();
    virtual void Method9();
    virtual void Method10();
    virtual void Method11();
    virtual void Method12();
    virtual void Method13();
    virtual void Method14();
    virtual void Method15();
    virtual void Method16();
    virtual void Method17();
    virtual void Method18();
    virtual void Method19();
    virtual void Method20();
    virtual void Method21();
    virtual void Method22();
    virtual void Method23();
    virtual void Method24();
    virtual void Method25();
    virtual void Method26();
    virtual void Method27();
    virtual void Method28();
    virtual void Method29();
    virtual void Method30();
    virtual void Method31();
    virtual void Method32();
    virtual void Method33();
    virtual void Method34();
    virtual void Method35();
    virtual void Method36();
    virtual void Method37();
    virtual void Method38();
    virtual void Method39();
    virtual void Method40();
    virtual void Method41();
    virtual void Method42();
    virtual void Method43();
    virtual void Method44();
    virtual void Method45();
    virtual void Method46();
    virtual void Method47();
    virtual void Method48();
    virtual void Method49();
    virtual void Method50();
    virtual void Method51();
    virtual void Method52();
    virtual void Method53();
    virtual void Method54();
    virtual void Method55();
    void Forward();
};

void Object::Forward()
{
    Method55();
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B740, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080F160.
extern char D_0080F160[];

char* Get()
{
    return D_0080F160;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B7C0, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080F120.
extern char D_0080F120[];

char* Get()
{
    return D_0080F120;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B840, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080F0E0.
extern char D_0080F0E0[];

char* Get()
{
    return D_0080F0E0;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B850, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080F0A0.
extern char D_0080F0A0[];

char* Get()
{
    return D_0080F0A0;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B8C0, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080F060.
extern char D_0080F060[];

char* Get()
{
    return D_0080F060;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B940, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080F020.
extern char D_0080F020[];

char* Get()
{
    return D_0080F020;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B9C0, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080EFE0.
extern char D_0080EFE0[];

char* Get()
{
    return D_0080EFE0;
}

// ============================================================================
// [VERIFIED] CharacterObject::vfunc_00 (0x0047B9D0, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080EFA0.
extern char D_0080EFA0[];

char* Get()
{
    return D_0080EFA0;
}

