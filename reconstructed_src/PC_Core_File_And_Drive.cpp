namespace core {

extern int g_FileClassDesc;          // 0x0085CDF8
extern int g_InstanceDriveClassDesc; // 0x0085CE14
void* __cdecl ResolveClassDescA(int* pDesc);
void* __cdecl ResolveClassDescB(int* pDesc);

struct ILockObject04 {
    virtual void Lock();   // +0x00
    virtual void Unlock(); // +0x04
};

struct IDriveParent0C {
    virtual void vfunc_00(); virtual void vfunc_01(); virtual void vfunc_02(); virtual void vfunc_03();
    virtual void vfunc_04(); virtual void vfunc_05(); virtual void vfunc_06(); virtual void vfunc_07();
    virtual unsigned char GetDriveFlags08(); // +0x20
};

class File {
public:
    ILockObject04   m_Lock04;            // +0x04
    int             m_RefCount08;        // +0x08
    IDriveParent0C* m_pDrive0C;          // +0x0C
    int             m_Field10;           // +0x10
    int             m_Field14;           // +0x14
    int             m_PendingCount18;    // +0x18
    short           m_Field1C;           // +0x1C
    char            m_InlineName1E[258]; // +0x1E..+0x11F
    int             m_Field120;          // +0x120
    int             m_Field124;          // +0x124
    int             m_Field128;          // +0x128

    virtual void  vfunc_00();                              // PC VA 0x006E4D70 (12 B)
    virtual void  vfunc_01();                              // PC VA 0x006E4D80 (12 B)
    virtual void  vfunc_02();
    virtual void  vfunc_03();
    virtual void  vfunc_04(void* a, int b, int c);         // +0x10
    virtual void  vfunc_05(const void* a, int b, int c);   // +0x14
    virtual void  vfunc_06(int a);                         // +0x18
    virtual void  vfunc_07(int a);                         // +0x1C
    virtual void  vfunc_08(int a);                         // +0x20
    virtual void  vfunc_09();                              // +0x24
    virtual void  vfunc_10(void* a, int b, int c);         // PC VA 0x006E4F60 (36 B)
    virtual void  vfunc_11(const void* a, int b, int c);   // PC VA 0x006E4F90 (36 B)
    virtual void  vfunc_12(int a);                         // PC VA 0x006E4FC0 (26 B)
    virtual void  vfunc_13(int a);                         // PC VA 0x006E4FE0 (26 B)
    virtual void  vfunc_14(int a);                         // PC VA 0x006E5000 (26 B)
    virtual void  vfunc_15();                              // PC VA 0x006E5020 (16 B)
    virtual int   vfunc_16();                              // PC VA 0x006E5030 (7 B)
    virtual void  vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual bool  vfunc_21();                              // PC VA 0x006E50E0 (35 B)
    virtual void  vfunc_22();                              // +0x58 (WaitForCompletion)
    virtual int   vfunc_23();                              // PC VA 0x006E5140 (29 B)
    virtual void  vfunc_24();
    virtual char* vfunc_25();                              // PC VA 0x006E5160 (24 B)
    virtual void  vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30();
    virtual void  vfunc_31(int val);                       // PC VA 0x006E51C0 (13 B)

    void AddRefLocked();                                   // PC VA 0x006E54B0 (27 B)
};

void File::vfunc_00() {
    ResolveClassDescA(&g_FileClassDesc);
}

void File::vfunc_01() {
    ResolveClassDescB(&g_FileClassDesc);
}

void File::vfunc_10(void* a, int b, int c) {
    vfunc_04(a, b, c);
    vfunc_22();
}

void File::vfunc_11(const void* a, int b, int c) {
    vfunc_05(a, b, c);
    vfunc_22();
}

void File::vfunc_12(int a) {
    vfunc_06(a);
    vfunc_22();
}

void File::vfunc_13(int a) {
    vfunc_07(a);
    vfunc_22();
}

void File::vfunc_14(int a) {
    vfunc_08(a);
    vfunc_22();
}

void File::vfunc_15() {
    vfunc_09();
    vfunc_22();
}

int File::vfunc_16() {
    return m_Field128;
}

bool File::vfunc_21() {
    m_Lock04.Lock();
    bool bEmpty = (m_PendingCount18 == 0);
    m_Lock04.Unlock();
    return bEmpty;
}

int File::vfunc_23() {
    m_Lock04.Lock();
    int val = m_Field14;
    m_Lock04.Unlock();
    return val;
}

char* File::vfunc_25() {
    // test al,al / jns: the name is returned when bit 7 is CLEAR.
    if (m_pDrive0C->GetDriveFlags08() & 0x80) {
        return 0;
    }
    return m_InlineName1E;
}

void File::vfunc_31(int val) {
    m_Field120 = val;
}

void File::AddRefLocked() {
    m_Lock04.Lock();
    ++m_RefCount08;
    m_Lock04.Unlock();
}

class InstanceDrive {
public:
    virtual void  vfunc_00();       // PC VA 0x006E5550 (12 B)
    virtual void  vfunc_01();       // PC VA 0x006E5560 (12 B)
    virtual void  vfunc_02(); virtual void vfunc_03(); virtual void vfunc_04();
    virtual void  vfunc_05(int a);  // +0x14
    virtual void  vfunc_06();       // +0x18
    virtual void  vfunc_07(int a);  // +0x1C
    virtual void  vfunc_08(int a);  // +0x20
    virtual void  vfunc_09();
    virtual void  vfunc_10(int a);  // +0x28
    virtual void  vfunc_11();
    virtual void  vfunc_12(int a);  // PC VA 0x006E58B0 (26 B)
    virtual void  vfunc_13();       // PC VA 0x006E58D0 (16 B)
    virtual void  vfunc_14(int a);  // PC VA 0x006E58E0 (26 B)
    virtual void  vfunc_15(int a);  // PC VA 0x006E5900 (26 B)
    virtual void  vfunc_16();
    virtual void  vfunc_17(int a);  // PC VA 0x006E5940 (26 B)
    virtual void  vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual void  vfunc_23();       // +0x5C (WaitForDriveCompletion)
};

void InstanceDrive::vfunc_00() {
    ResolveClassDescA(&g_InstanceDriveClassDesc);
}

void InstanceDrive::vfunc_01() {
    ResolveClassDescB(&g_InstanceDriveClassDesc);
}

void InstanceDrive::vfunc_12(int a) {
    vfunc_05(a);
    vfunc_23();
}

void InstanceDrive::vfunc_13() {
    vfunc_06();
    vfunc_23();
}

void InstanceDrive::vfunc_14(int a) {
    vfunc_07(a);
    vfunc_23();
}

void InstanceDrive::vfunc_15(int a) {
    vfunc_08(a);
    vfunc_23();
}

void InstanceDrive::vfunc_17(int a) {
    vfunc_10(a);
    vfunc_23();
}

} // namespace core
