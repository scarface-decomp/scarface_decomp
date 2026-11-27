// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/File.cpp (33 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 33 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::File::vfunc_01 (0x0026D610, 123 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_01 (0x002AAED0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D610
// what: Drops a reference under the lock; at zero it queues a close request if the file is open, else destroys itself.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCloseRequest
    {
    public:
        FileCloseRequest* sub_0026D110(File* file);     // the constructor
        char m_Data[0xC];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_01();

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

void core::File::vfunc_01()
{
    Lock();
    m_RefCount--;
    if (m_RefCount == 0)
    {
        if (m_Open)
        {
            Unlock();
            FileCloseRequest* memory = (FileCloseRequest*)sub_0026C140(sizeof(FileCloseRequest));
            FileCloseRequest* request = memory ? memory->sub_0026D110(this) : 0;
            m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
        }
        else
        {
            m_RefCount = 0x5DC;
            Unlock();
            Destroy(1);
        }
    }
    else
    {
        Unlock();
    }
}

// ============================================================================
// [VERIFIED] core::File::vfunc_00 (0x0026D690, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_00 (0x0026D690, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0048E994[];
extern "C" void __cdecl sub_0023F190(int);

namespace core {

class File
{
public:
    virtual void vfunc_00();
};

void File::vfunc_00()
{
    sub_0023F190((int)DAT_0048E994);
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_01 (0x0026D6A0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_01 (0x0026D6A0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0048E994[];
extern "C" void __cdecl sub_0023F180(int);

namespace core {

class File
{
public:
    virtual void vfunc_01();
};

void File::vfunc_01()
{
    sub_0023F180((int)DAT_0048E994);
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_09 (0x0026D6B0, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_09 (0x002AAF70), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D6B0
// what: Queues a commit request for this file on its drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCommitRequest
    {
    public:
        FileCommitRequest* sub_0026D130(File* file);     // the constructor
        char m_Data[0xC];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_09();

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

void core::File::vfunc_09()
{
    FileCommitRequest* memory = (FileCommitRequest*)sub_0026C140(sizeof(FileCommitRequest));
    FileCommitRequest* request = memory ? memory->sub_0026D130(this) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_04 (0x0026D6F0, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_04 (0x002AAFB0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D6F0
// what: Queues a read request for this file on its drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileReadRequest
    {
    public:
        FileReadRequest* sub_0026D150(File* file, int a, int b, int c);     // the constructor
        char m_Data[0x18];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_04(int a, int b, int c);

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

void core::File::vfunc_04(int a, int b, int c)
{
    FileReadRequest* memory = (FileReadRequest*)sub_0026C140(sizeof(FileReadRequest));
    FileReadRequest* request = memory ? memory->sub_0026D150(this, a, b, c) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_05 (0x0026D740, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_05 (0x002AB000), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D740
// what: Queues a write request for this file on its drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileWriteRequest
    {
    public:
        FileWriteRequest* sub_0026D190(File* file, int a, int b, int c);     // the constructor
        char m_Data[0x18];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_05(int a, int b, int c);

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

void core::File::vfunc_05(int a, int b, int c)
{
    FileWriteRequest* memory = (FileWriteRequest*)sub_0026C140(sizeof(FileWriteRequest));
    FileWriteRequest* request = memory ? memory->sub_0026D190(this, a, b, c) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_06 (0x0026D790, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_06 (0x002AB050), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D790
// what: Queues a request that sets this file's position.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileSetPositionRequest
    {
    public:
        FileSetPositionRequest* sub_0026D1D0(File* file, int a);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_06(int a);

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

void core::File::vfunc_06(int a)
{
    FileSetPositionRequest* memory = (FileSetPositionRequest*)sub_0026C140(sizeof(FileSetPositionRequest));
    FileSetPositionRequest* request = memory ? memory->sub_0026D1D0(this, a) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_07 (0x0026D7E0, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_07 (0x002AB0A0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D7E0
// what: Queues a request for this file's position; the answer goes where the argument points.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileGetPositionRequest
    {
    public:
        FileGetPositionRequest* sub_0026D200(File* file, int a);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_07(int a);

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

void core::File::vfunc_07(int a)
{
    FileGetPositionRequest* memory = (FileGetPositionRequest*)sub_0026C140(sizeof(FileGetPositionRequest));
    FileGetPositionRequest* request = memory ? memory->sub_0026D200(this, a) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_08 (0x0026D830, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_06 (0x002AB050), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D830
// what: Queues a request that sets this file's position.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        virtual void vfunc_08();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileSetPositionRequest
    {
    public:
        FileSetPositionRequest* sub_0026D230(File* file, int a);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_08(int a);

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

void core::File::vfunc_08(int a)
{
    FileSetPositionRequest* memory = (FileSetPositionRequest*)sub_0026C140(sizeof(FileSetPositionRequest));
    FileSetPositionRequest* request = memory ? memory->sub_0026D230(this, a) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_10 (0x0026D880, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_10 (Proto 0x0026D880, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int, int, int);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int a1, int a2, int a3);
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

void File::vfunc_10(int a1, int a2, int a3)
{
    vfunc_04(a1, a2, a3);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_11 (0x0026D8B0, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_11 (Proto 0x0026D8B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int, int, int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11(int a1, int a2, int a3);
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

void File::vfunc_11(int a1, int a2, int a3)
{
    vfunc_05(a1, a2, a3);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_12 (0x0026D8E0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_12 (Proto 0x0026D8E0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
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
};

void File::vfunc_12(int a1)
{
    vfunc_06(a1);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_13 (0x0026D900, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_13 (Proto 0x0026D900, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void vfunc_13(int a1);
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

void File::vfunc_13(int a1)
{
    vfunc_07(a1);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_14 (0x0026D920, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_14 (Proto 0x0026D920, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void vfunc_14(int a1);
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
};

void File::vfunc_14(int a1)
{
    vfunc_08(a1);
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_15 (0x0026D940, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_15 (Proto 0x0026D940, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
};

void File::vfunc_15()
{
    vfunc_09();
    vfunc_22();
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_16 (0x0026D950, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_16 (Proto 0x0026D950, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual int vfunc_16();
    char m_pad04[0x124];
    int m_Field128; // +0x128
};

int File::vfunc_16()
{
    return m_Field128;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_18 (0x0026D960, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_18 (0x002AB220), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D960
// what: Queues a cancel request for this file at the head of the drive's queue.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCancelRequest
    {
    public:
        FileCancelRequest* sub_0026D2D0(File* file);     // the constructor
        char m_Data[0xC];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_18();

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

void core::File::vfunc_18()
{
    FileCancelRequest* memory = (FileCancelRequest*)sub_0026C140(sizeof(FileCancelRequest));
    FileCancelRequest* request = memory ? memory->sub_0026D2D0(this) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, true);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_19 (0x0026D9A0, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_19 (0x002AB260), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026D9A0
// what: Queues a request that calls the caller's thread back once this file's earlier requests are done.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_0023F4C0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCompletionRequest
    {
    public:
        FileCompletionRequest* sub_0026CE60(Thread* thread, File* file, int a, int b);     // the constructor
        char m_Data[0x18];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_19(int a, int b);

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

void core::File::vfunc_19(int a, int b)
{
    FileCompletionRequest* memory = (FileCompletionRequest*)sub_0026C140(sizeof(FileCompletionRequest));
    FileCompletionRequest* request = memory ? memory->sub_0026CE60(sub_0023F4C0(), this, a, b) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_21 (0x0026DA00, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_21 (0x002AB2C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DA00
// what: Under the lock, says whether this file has no requests outstanding.
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
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        bool vfunc_21();

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

bool core::File::vfunc_21()
{
    Lock();
    bool idle = m_Outstanding == 0;
    Unlock();
    return idle;
}

// ============================================================================
// [VERIFIED] core::File::vfunc_22 (0x0026DA30, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_22 (Proto 0x0026DA30, 47 bytes)
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

extern "C" void __cdecl sub_0023F0F0(int);

namespace core {

class File
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
    virtual bool vfunc_21();
    virtual void vfunc_22();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void File::vfunc_22()
{
    if (!vfunc_21()) {
        do {
            m_Field0C->vfunc_04();
            sub_0023F0F0(0);
        } while (!vfunc_21());
    }
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_23 (0x0026DA60, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_23 (0x002AB320), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DA60
// what: Returns this file's last error, read under the lock.
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
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        int vfunc_23();

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

int core::File::vfunc_23()
{
    Lock();
    int error = m_LastError;
    Unlock();
    return error;
}

// ============================================================================
// [VERIFIED] core::File::vfunc_24 (0x0026DA80, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_24 (Proto 0x0026DA80, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual bool vfunc_24();
    char m_pad04[0x18];
    bool m_Field1C; // +0x1C
};

bool File::vfunc_24()
{
    return m_Field1C;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_25 (0x0026DA90, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_25 (0x002AB340), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DA90
// what: Returns the file's name, or null on a drive whose names are used whole.
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
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        const char* vfunc_25();

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

const char* core::File::vfunc_25()
{
    if (m_Drive->GetCapabilities() & 0x80)
    {
        return 0;
    }
    return m_Name;
}

// ============================================================================
// [VERIFIED] core::File::vfunc_26 (0x0026DAB0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_26 (PC 0x006E5180), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_26 (PC 0x0026DAB0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void* vfunc_26();
};

void* File::vfunc_26()
{
    return ((char*)this + 0x1E);
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_30 (0x0026DAD0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_30 (Proto 0x0026DAD0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual bool vfunc_30();
    char m_pad04[0x15C];
    bool m_Field160; // +0x160
};

bool File::vfunc_30()
{
    return m_Field160;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_17 (0x0026DAE0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_17 (Proto 0x0026DAE0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual int vfunc_17();
    char m_pad04[0x160];
    int m_Field164; // +0x164
};

int File::vfunc_17()
{
    return m_Field164;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_31 (0x0026DAF0, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_31 (Proto 0x0026DAF0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual int vfunc_31(int a1);
    char m_pad04[0x11C];
    int m_Field120; // +0x120
};

int File::vfunc_31(int a1)
{
    m_Field120 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_32 (0x0026DB00, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_32 (Proto 0x0026DB00, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual int vfunc_32();
    char m_pad04[0x158];
    int m_Field15C; // +0x15C
};

int File::vfunc_32()
{
    return m_Field15C;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_33 (0x0026DB10, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_33 (Proto 0x0026DB10, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class File
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
    virtual void* vfunc_33();
    char m_pad04[0x128];
    int m_Field12C; // +0x12C
};

void* File::vfunc_33()
{
    return &m_Field12C;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_03 (0x0026DB70, 92 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_03 (Proto 0x0026DB70, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field12C
{
    void sub_001B7A10();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003B3E90[];
extern "C" char DAT_003B3E9C[];
extern "C" char DAT_0048E994[];
extern "C" int DAT_0048E9B0;
extern "C" void __cdecl sub_0023F180(int);
extern "C" void __cdecl sub_0023F190(int);

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual File* vfunc_03(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0x11C];
    Field12C m_Field12C; // +0x12C
};

File* File::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_003B3E9C;
    m_Field04 = (int)DAT_003B3E90;
    ((Object*)t1)->vfunc_01();
    m_Field12C.sub_001B7A10();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_0023F190((int)DAT_0048E994);
        ((Object*)DAT_0048E9B0)->vfunc_05((int)this);
        sub_0023F180((int)DAT_0048E994);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_00 (0x0026DE30, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AB6D0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DE30
// what: Adds a reference under the object's lock.
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
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_00();

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

void core::File::vfunc_00()
{
    Lock();
    m_RefCount++;
    Unlock();
}

// ============================================================================
// [VERIFIED] core::File::vfunc_20 (0x0026E3A0, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_20 (0x002ABC40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026E3A0
// what: Queues a request that signals an event once everything queued before it on the drive is done.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
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
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class CompletionEventRequest
    {
    public:
        CompletionEventRequest* sub_0026CDD0(int a, Drive* drive);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_20(int a);

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

void core::File::vfunc_20(int a)
{
    CompletionEventRequest* memory = (CompletionEventRequest*)sub_0026C140(sizeof(CompletionEventRequest));
    CompletionEventRequest* request = memory ? memory->sub_0026CDD0(a, m_Drive) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::File::vfunc_27 (0x0026E730, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::File::vfunc_27 (Proto 0x0026E730, 8 bytes)
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
};

namespace core {

class File
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

void File::vfunc_27()
{
    m_Field0C->vfunc_05();
}

}

