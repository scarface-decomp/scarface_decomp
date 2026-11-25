// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PS2 SLUS_211.11, engine/CharacterObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 61 functions matched (9.84%). NOT COMPLETE YET.
// The 55 still to do are listed in their place in Original_Binary_Order_PS2.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Metrowerks CodeWarrior for PS2 3.0.1 (decomp.me: mwcps2-3.0.1b103-040528, -O3 -lang c++ -str readonly).
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

