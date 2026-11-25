// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PS2 SLUS_211.11, engine/AirplaneObject.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 64 functions matched (10.94%). NOT COMPLETE YET.
// The 57 still to do are listed in their place in Original_Binary_Order_PS2.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Metrowerks CodeWarrior for PS2 3.0.1 (decomp.me: mwcps2-3.0.1b103-040528, -O3 -lang c++ -str readonly).
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_44 (0x003BB860, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Stores its argument as a float at +0xD0 of its object.
class Object
{
public:
    void Set(float value);
    char m_pad00[0xD0];
    float m_FieldD0; // +0xD0
};

void Object::Set(float value)
{
    m_FieldD0 = value;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_45 (0x003BB870, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the float at +0xD0 of its object.
class Object
{
public:
    float Get();
    char m_pad00[0xD0];
    float m_FieldD0; // +0xD0
};

float Object::Get()
{
    return m_FieldD0;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_00 (0x003BB880, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080BC60.
extern char D_0080BC60[];

char* Get()
{
    return D_0080BC60;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_74 (0x003BCEC0, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns 0.
int Zero()
{
    return 0;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_00 (0x003C1FA0, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080BE10.
extern char D_0080BE10[];

char* Get()
{
    return D_0080BE10;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_00 (0x003C2D50, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080BD80.
extern char D_0080BD80[];

char* Get()
{
    return D_0080BD80;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_00 (0x003C4450, 12 B)
// By: RRutherrfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the address of the global D_0080BDD0.
extern char D_0080BDD0[];

char* Get()
{
    return D_0080BDD0;
}

