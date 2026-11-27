// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/InstanceDrive.cpp (40 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 40 of 44 functions matched (90.91%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_00 (0x006E5550, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_00 (0x006E5550, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CE14[];
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
};

void InstanceDrive::vfunc_00()
{
    sub_006DF080((int)DAT_0085CE14);
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_01 (0x006E5560, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_01 (0x006E5560, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CE14[];
extern "C" void __cdecl sub_006DF070(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_01();
};

void InstanceDrive::vfunc_01()
{
    sub_006DF070((int)DAT_0085CE14);
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_04 (0x006E5570, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_04 (Proto 0x0026DEF0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_04 (Proto 0x006E5570, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
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
};

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_04()
{
    m_Field0C->vfunc_08();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_05 (0x006E5580, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_08 (0x002AB0F0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E5580
// what: Queues a request for this file's size; the answer goes where the argument points.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileGetSizeRequest
    {
    public:
        FileGetSizeRequest* sub_006E4A00(InstanceDrive* file, int a);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_05(int a);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_05(int a)
{
    FileGetSizeRequest* memory = (FileGetSizeRequest*)sub_006E3670(sizeof(FileGetSizeRequest));
    FileGetSizeRequest* request = memory ? memory->sub_006E4A00(this, a) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_06 (0x006E55D0, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_09 (0x002AAF70), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E55D0
// what: Queues a commit request for this file on its drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCommitRequest
    {
    public:
        FileCommitRequest* sub_006E4AA0(InstanceDrive* file);     // the constructor
        char m_Data[0xC];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_06();

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_06()
{
    FileCommitRequest* memory = (FileCommitRequest*)sub_006E3670(sizeof(FileCommitRequest));
    FileCommitRequest* request = memory ? memory->sub_006E4AA0(this) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_07 (0x006E5610, 135 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_07 (0x002AB830), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E5610
// what: Splits the name and queues a create-directory request for it on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_006DCB40(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveCreateDirectoryRequest
    {
    public:
        DriveCreateDirectoryRequest* sub_006E4AC0(InstanceDrive* drive, const char* path);     // the constructor
        char m_Data[0x20];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_07(const char* name);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_07(const char* name)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_006DCB40(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveCreateDirectoryRequest* memory = (DriveCreateDirectoryRequest*)sub_006E3670(sizeof(DriveCreateDirectoryRequest));
    DriveCreateDirectoryRequest* request = memory ? memory->sub_006E4AC0(this, path) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_08 (0x006E56A0, 135 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_07 (0x002AB830), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E56A0
// what: Splits the name and queues a create-directory request for it on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_006DCB40(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_08();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveCreateDirectoryRequest
    {
    public:
        DriveCreateDirectoryRequest* sub_006E4B00(InstanceDrive* drive, const char* path);     // the constructor
        char m_Data[0x20];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_08(const char* name);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_08(const char* name)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_006DCB40(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveCreateDirectoryRequest* memory = (DriveCreateDirectoryRequest*)sub_006E3670(sizeof(DriveCreateDirectoryRequest));
    DriveCreateDirectoryRequest* request = memory ? memory->sub_006E4B00(this, path) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_09 (0x006E5730, 146 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_09 (0x002AB950), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E5730
// what: Splits the name and queues a find-first request (a directory search) on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_006DCB40(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveFindFirstRequest
    {
    public:
        DriveFindFirstRequest* sub_006E4B40(InstanceDrive* drive, const char* path, int b);     // the constructor
        char m_Data[0x114];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_09(const char* name, int b);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_09(const char* name, int b)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_006DCB40(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveFindFirstRequest* memory = (DriveFindFirstRequest*)sub_006E3670(sizeof(DriveFindFirstRequest));
    DriveFindFirstRequest* request = memory ? memory->sub_006E4B40(this, path, b) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_10 (0x006E57D0, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_06 (0x002AB050), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E57D0
// what: Queues a request that sets this file's position.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_10();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileSetPositionRequest
    {
    public:
        FileSetPositionRequest* sub_006E4B90(InstanceDrive* file, int a);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_10(int a);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_10(int a)
{
    FileSetPositionRequest* memory = (FileSetPositionRequest*)sub_006E3670(sizeof(FileSetPositionRequest));
    FileSetPositionRequest* request = memory ? memory->sub_006E4B90(this, a) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_11 (0x006E5820, 138 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_11 (0x002ABA40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E5820
// what: Splits the name and queues a request that deletes that file on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_006DCB40(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveFileDestroyRequest
    {
    public:
        DriveFileDestroyRequest* sub_006E4BE0(InstanceDrive* drive, const char* path);     // the constructor
        char m_Data[0x110];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_11(const char* name);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_11(const char* name)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_006DCB40(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveFileDestroyRequest* memory = (DriveFileDestroyRequest*)sub_006E3670(sizeof(DriveFileDestroyRequest));
    DriveFileDestroyRequest* request = memory ? memory->sub_006E4BE0(this, path) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_12 (0x006E58B0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_12 (Proto 0x0026E230), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_12 (Proto 0x006E58B0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a1);
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
};

void InstanceDrive::vfunc_12(int a1)
{
    vfunc_05(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_13 (0x006E58D0, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_13 (Proto 0x0026E250), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_13 (Proto 0x006E58D0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
};

void InstanceDrive::vfunc_13()
{
    vfunc_06();
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_14 (0x006E58E0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_14 (Proto 0x0026E260), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_14 (Proto 0x006E58E0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(int a1);
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_14(int a1)
{
    vfunc_07(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_15 (0x006E5900, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_15 (Proto 0x0026E280), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_15 (Proto 0x006E5900, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_08(int);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(int a1);
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_15(int a1)
{
    vfunc_08(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_16 (0x006E5920, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_16 (Proto 0x0026E2A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_16 (Proto 0x006E5920, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_09(int, int);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(int a1, int a2);
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_16(int a1, int a2)
{
    vfunc_09(a1, a2);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_17 (0x006E5940, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_17 (Proto 0x0026E2C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_17 (Proto 0x006E5940, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_10(int);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int a1);
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_17(int a1)
{
    vfunc_10(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_18 (0x006E5960, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_18 (Proto 0x0026E2E0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_18 (Proto 0x006E5960, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_11(int);
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int a1);
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_18(int a1)
{
    vfunc_11(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_19 (0x006E5980, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_18 (0x002AB220), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E5980
// what: Queues a cancel request for this file at the head of the drive's queue.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCancelRequest
    {
    public:
        FileCancelRequest* sub_006E4C20(InstanceDrive* file);     // the constructor
        char m_Data[0xC];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_19();

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_19()
{
    FileCancelRequest* memory = (FileCancelRequest*)sub_006E3670(sizeof(FileCancelRequest));
    FileCancelRequest* request = memory ? memory->sub_006E4C20(this) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, true);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_20 (0x006E59C0, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_19 (0x002AB260), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E59C0
// what: Queues a request that calls the caller's thread back once this file's earlier requests are done.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_006DF3A0();                     // the calling thread's record
void* __cdecl sub_006E3670(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_006E6370(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCompletionRequest
    {
    public:
        FileCompletionRequest* sub_006E4530(Thread* thread, InstanceDrive* file, int a, int b);     // the constructor
        char m_Data[0x18];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_20(int a, int b);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_20(int a, int b)
{
    FileCompletionRequest* memory = (FileCompletionRequest*)sub_006E3670(sizeof(FileCompletionRequest));
    FileCompletionRequest* request = memory ? memory->sub_006E4530(sub_006DF3A0(), this, a, b) : 0;
    m_Drive->sub_006E6370((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_23 (0x006E5AA0, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_23 (Proto 0x0026E420), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_23 (Proto 0x006E5AA0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

extern "C" void __cdecl sub_006DEFA0(int);

namespace core {

class InstanceDrive
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
    virtual bool vfunc_22();
    virtual void vfunc_23();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_23()
{
    if (!vfunc_22()) {
        do {
            m_Field0C->vfunc_04();
            sub_006DEFA0(0);
        } while (!vfunc_22());
    }
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_24 (0x006E5AD0, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_24 (0x002ABCF0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x006E5AD0
// what: Under the lock, returns the real drive's last error if it is in its error state, else this handle's own.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_002A9880(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_002AC690(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_006E6290();    // whether the drive is in its error state
        int sub_006E60C0();     // the drive's last error
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        int vfunc_24();

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

int core::InstanceDrive::vfunc_24()
{
    int error;
    Lock();
    if (m_Drive->sub_006E6290())
    {
        error = m_Drive->sub_006E60C0();
    }
    else
    {
        error = m_LastError;
    }
    Unlock();
    return error;
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_25 (0x006E5B10, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_25 (0x006E5B10, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6160();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_25()
{
    m_Field0C->sub_006E6160();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_26 (0x006E5B20, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_26 (0x006E5B20, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E61A0();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_26()
{
    m_Field0C->sub_006E61A0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_27 (0x006E5B30, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_27 (0x006E5B30, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E61D0();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_27()
{
    m_Field0C->sub_006E61D0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_29 (0x006E5B40, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_29 (0x006E5B40, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6290();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_29()
{
    m_Field0C->sub_006E6290();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_30 (0x006E5B50, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_30 (0x006E5B50, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6250();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_30();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_30()
{
    m_Field0C->sub_006E6250();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_31 (0x006E5B60, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_31 (0x006E5B60, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6200();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_31()
{
    m_Field0C->sub_006E6200();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_32 (0x006E5B70, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_32 (0x006E5B70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6350();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_32()
{
    m_Field0C->sub_006E6350();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_33 (0x006E5B80, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_33 (0x006E5B80, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E62F0();
};

namespace core {

class InstanceDrive
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_33()
{
    m_Field0C->sub_006E62F0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_35 (0x006E5C60, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_35 (Proto 0x0026E5E0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_35 (Proto 0x006E5C60, 64 bytes)
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
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_34(int, int, int, int, int, int, int, int);
    virtual void vfunc_35(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void InstanceDrive::vfunc_35(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int t2;

    vfunc_34(a1, a2, a3, a4, a5, a6, a7, a8);
    t2 = *(int*)a1;
    if (*(int*)a1) {
        ((Object*)t2)->vfunc_22();
    }
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_37 (0x006E5D70, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_37 (Proto 0x0026E6F0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_37 (Proto 0x006E5D70, 59 bytes)
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
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_36(int, int, int, int, int, int, int);
    virtual void vfunc_37(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

void InstanceDrive::vfunc_37(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int t2;

    vfunc_36(a1, a2, a3, a4, a5, a6, a7);
    t2 = *(int*)a1;
    if (*(int*)a1) {
        ((Object*)t2)->vfunc_22();
    }
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_41 (0x006E5DB0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_41 (0x006E5DB0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6390();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_41()
{
    m_Field0C->sub_006E6390();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_40 (0x006E5DC0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_40 (0x006E5DC0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63B0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_40();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_40()
{
    m_Field0C->sub_006E63B0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_43 (0x006E5DD0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_43 (0x006E5DD0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63C0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_43()
{
    m_Field0C->sub_006E63C0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_42 (0x006E5DE0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_42 (0x006E5DE0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63E0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_42();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_42()
{
    m_Field0C->sub_006E63E0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_44 (0x006E5DF0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_44 (0x006E5DF0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63F0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_44()
{
    m_Field0C->sub_006E63F0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_45 (0x006E5E00, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_45 (0x002AC020), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_45 (0x006E5E00, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6370(int, int, int);
};

struct Object
{
    int sub_006E4C40(int, int, int);
};

extern "C" int __cdecl sub_006E3670(int);

namespace core {

class InstanceDrive
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
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual int vfunc_45(int a1, int a2, int a3);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

int InstanceDrive::vfunc_45(int a1, int a2, int a3)
{
    int r_esi, t1;

    t1 = sub_006E3670(28);
    if (t1) {
        r_esi = ((Object*)t1)->sub_006E4C40((int)this, a1, a2);
    } else {
        r_esi = 0;
    }
    m_Field0C->sub_006E6370(r_esi, a3, 0);
    return r_esi;
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_46 (0x006E5E50, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_46 (0x002AC070), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_46 (0x006E5E50, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E4330();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46(int a1);
};

void InstanceDrive::vfunc_46(int a1)
{
    ((Object*)a1)->sub_006E4330();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_48 (0x006E5E60, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_41 (Proto 0x0026E740), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_48 (Proto 0x006E5E60, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
};

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
 