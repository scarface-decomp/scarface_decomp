# A5 annotated listings (default.xbe) — offset | bytes | insn | reloc | constants/signedness
Reloc: DIR32 = absolute image address in the insn (needs a fixup/symbol); REL32 = call/jmp to another function. Intra-function branches carry no reloc.

## 0x00027590  (20 B, U)
cdecl void* operator new(u32 size) — new on current heap: return 0x244450(0x244410(), size). [esp+4]=size.
```
+000  8b442404             mov     eax, dword ptr [esp + 4]                
+004  50                   push    eax                                     
+005  e876ce2100           call    0x244410                               REL32→0x244410 
+00A  50                   push    eax                                     
+00B  e8b0ce2100           call    0x244450                               REL32→0x244450 
+010  83c408               add     esp, 8                                  
+013  c3                   ret                                             
```

## 0x000275B0  (19 B, M)
cdecl void* operator new(u32 size, int heap) — return 0x244450(heap,size). [esp+4]=size [esp+8]=heap.
```
+000  8b442404             mov     eax, dword ptr [esp + 4]                
+004  8b4c2408             mov     ecx, dword ptr [esp + 8]                
+008  50                   push    eax                                     
+009  51                   push    ecx                                     
+00A  e891ce2100           call    0x244450                               REL32→0x244450 
+00F  83c408               add     esp, 8                                  
+012  c3                   ret                                             
```

## 0x00244450  (65 B, M)
[M] cdecl void* HeapAlloc(int heap, u32 size): obj=*(u32*)(0x493330+heap*16) ; p=obj->vfunc+0x10(size) (thiscall, 1 arg); if !p && cb=*(fn*)0x493B58: cb(*(void**)0x493B5C, heap, size, 1) (cdecl, 4 args, caller pops 0x10); return p (cb result discarded).
```
+000  53                   push    ebx                                     
+001  8b5c240c             mov     ebx, dword ptr [esp + 0xc]              
+005  56                   push    esi                                     
+006  57                   push    edi                                     
+007  8b7c2410             mov     edi, dword ptr [esp + 0x10]             
+00B  8bc7                 mov     eax, edi                                
+00D  c1e004               shl     eax, 4                                  
+010  8b8830334900         mov     ecx, dword ptr [eax + 0x493330]        DIR32 0x493330(.data) 
+016  8b11                 mov     edx, dword ptr [ecx]                    
+018  53                   push    ebx                                     
+019  ff5210               call    dword ptr [edx + 0x10]                  
+01C  8bf0                 mov     esi, eax                                
+01E  85f6                 test    esi, esi                                
+020  7519                 jne     0x24448b                                
+022  a1583b4900           mov     eax, dword ptr [0x493b58]              DIR32 0x493b58(.data) 
+027  85c0                 test    eax, eax                                
+029  7410                 je      0x24448b                                
+02B  8b0d5c3b4900         mov     ecx, dword ptr [0x493b5c]              DIR32 0x493b5c(.data) 
+031  6a01                 push    1                                       
+033  53                   push    ebx                                     
+034  57                   push    edi                                     
+035  51                   push    ecx                                     
+036  ffd0                 call    eax                                     
+038  83c410               add     esp, 0x10                               
+03B  5f                   pop     edi                                     
+03C  8bc6                 mov     eax, esi                                
+03E  5e                   pop     esi                                     
+03F  5b                   pop     ebx                                     
+040  c3                   ret                                             
```

## 0x00243FA0  (75 B, M)
[M] reference for the diff below: cdecl u32 HashFold(const char* s, u32 seed).
```
+000  8b542404             mov     edx, dword ptr [esp + 4]                
+004  85d2                 test    edx, edx                                
+006  743e                 je      0x243fe6                                
+008  8a0a                 mov     cl, byte ptr [edx]                      
+00A  84c9                 test    cl, cl                                  
+00C  7438                 je      0x243fe6                                
+00E  8b442408             mov     eax, dword ptr [esp + 8]                
+012  25ffffff7f           and     eax, 0x7fffffff                         
+017  eb07                 jmp     0x243fc0                                
+019  8da42400000000       lea     esp, [esp]                              
+020  69c03f000100         imul    eax, eax, 0x1003f                       
+026  25ffffff7f           and     eax, 0x7fffffff                         
+02B  80f961               cmp     cl, 0x61                                
+02E  0fbec9               movsx   ecx, cl                                 
+031  7d03                 jge     0x243fd6                                signed
+033  83c120               add     ecx, 0x20                               
+036  33c1                 xor     eax, ecx                                
+038  8a4a01               mov     cl, byte ptr [edx + 1]                  
+03B  42                   inc     edx                                     
+03C  84c9                 test    cl, cl                                  
+03E  75e0                 jne     0x243fc0                                
+040  0d00000080           or      eax, 0x80000000                         
+045  c3                   ret                                             
+046  8b442408             mov     eax, dword ptr [esp + 8]                
+04A  c3                   ret                                             
```

## 0x00243FF0  (67 B, U)
cdecl u32 Hash(const char* s, u32 seed) — case-sensitive twin of 0x243FA0. Byte diff: see DIFF block.
```
+000  8b542404             mov     edx, dword ptr [esp + 4]                
+004  85d2                 test    edx, edx                                
+006  7436                 je      0x24402e                                
+008  8a0a                 mov     cl, byte ptr [edx]                      
+00A  84c9                 test    cl, cl                                  
+00C  7430                 je      0x24402e                                
+00E  8b442408             mov     eax, dword ptr [esp + 8]                
+012  25ffffff7f           and     eax, 0x7fffffff                         
+017  eb07                 jmp     0x244010                                
+019  8da42400000000       lea     esp, [esp]                              
+020  69c03f000100         imul    eax, eax, 0x1003f                       
+026  0fbec9               movsx   ecx, cl                                 
+029  25ffffff7f           and     eax, 0x7fffffff                         
+02E  33c1                 xor     eax, ecx                                
+030  8a4a01               mov     cl, byte ptr [edx + 1]                  
+033  42                   inc     edx                                     
+034  84c9                 test    cl, cl                                  
+036  75e8                 jne     0x244010                                
+038  0d00000080           or      eax, 0x80000000                         
+03D  c3                   ret                                             
+03E  8b442408             mov     eax, dword ptr [esp + 8]                
+042  c3                   ret                                             
```

## 0x00244100  (99 B, U)
thiscall float Vec3::NormalizeSafe() — ecx=float[3]; returns len in ST0; len²<1e-10 (strict: fcom; test ah,1 = C0 = below) → zero vector, return 0.0f. 1.0f @0x39D664, 0.0f @0x39D584, 1e-10f @0x458248.
```
+000  d94108               fld     dword ptr [ecx + 8]                     
+003  d94104               fld     dword ptr [ecx + 4]                     
+006  d901                 fld     dword ptr [ecx]                         
+008  d9c0                 fld     st(0)                                   
+00A  d8c9                 fmul    st(1)                                   
+00C  d9c2                 fld     st(2)                                   
+00E  d8cb                 fmul    st(3)                                   
+010  dec1                 faddp   st(1)                                   
+012  d9c3                 fld     st(3)                                   
+014  d8cc                 fmul    st(4)                                   
+016  dec1                 faddp   st(1)                                   
+018  dddb                 fstp    st(3)                                   
+01A  ddd8                 fstp    st(0)                                   
+01C  ddd8                 fstp    st(0)                                   
+01E  d81548824500         fcom    dword ptr [0x458248]                   DIR32 0x458248(.data) [0x458248]=0x2edbe6fe
+024  dfe0                 fnstsw  ax                                      
+026  f6c401               test    ah, 1                                   
+029  7525                 jne     0x244150                                
+02B  d9fa                 fsqrt                                           
+02D  d83d64d63900         fdivr   dword ptr [0x39d664]                   DIR32 0x39d664(.rdata) [0x39d664]=1
+033  d9c0                 fld     st(0)                                   
+035  d809                 fmul    dword ptr [ecx]                         
+037  d919                 fstp    dword ptr [ecx]                         
+039  d9c0                 fld     st(0)                                   
+03B  d84904               fmul    dword ptr [ecx + 4]                     
+03E  d95904               fstp    dword ptr [ecx + 4]                     
+041  d9c0                 fld     st(0)                                   
+043  d84908               fmul    dword ptr [ecx + 8]                     
+046  d95908               fstp    dword ptr [ecx + 8]                     
+049  d83d64d63900         fdivr   dword ptr [0x39d664]                   DIR32 0x39d664(.rdata) [0x39d664]=1
+04F  c3                   ret                                             
+050  33c0                 xor     eax, eax                                
+052  ddd8                 fstp    st(0)                                   
+054  d90584d53900         fld     dword ptr [0x39d584]                   DIR32 0x39d584(.rdata) [0x39d584]=0
+05A  894108               mov     dword ptr [ecx + 8], eax                
+05D  894104               mov     dword ptr [ecx + 4], eax                
+060  8901                 mov     dword ptr [ecx], eax                    
+062  c3                   ret                                             
```

## 0x0002AC90  (45 B, U)
cdecl void* HandleLookup(u32 h) — Entry{void* p; u32 h;} table *(Entry**)0x4740DC; bound h ≤ *(u32*)0x4740E4 (unsigned ja); idx=h&0x3FFF; idx<6000 (unsigned jae); e.h==h → e.p else 0.
```
+000  8b542404             mov     edx, dword ptr [esp + 4]                
+004  3b15e4404700         cmp     edx, dword ptr [0x4740e4]              DIR32 0x4740e4(.data) 
+00A  771e                 ja      0x2acba                                 unsigned
+00C  8bc2                 mov     eax, edx                                
+00E  25ff3f0000           and     eax, 0x3fff                             
+013  3d70170000           cmp     eax, 0x1770                             
+018  7310                 jae     0x2acba                                 unsigned
+01A  8b0ddc404700         mov     ecx, dword ptr [0x4740dc]              DIR32 0x4740dc(.data) 
+020  3954c104             cmp     dword ptr [ecx + eax*8 + 4], edx        
+024  7504                 jne     0x2acba                                 
+026  8b04c1               mov     eax, dword ptr [ecx + eax*8]            
+029  c3                   ret                                             
+02A  33c0                 xor     eax, eax                                
+02C  c3                   ret                                             
```

## 0x0009A620  (96 B, U)
cdecl float Rand01() — gen=*(Gen**)0x492EE0 {u32 a; u32 b;}; returns ST0 ∈ [0,1). 'lea edx,[ecx+4]' = &gen->b kept in edx for the store.
```
+000  51                   push    ecx                                     
+001  8b0de02e4900         mov     ecx, dword ptr [0x492ee0]              DIR32 0x492ee0(.data) 
+007  8b01                 mov     eax, dword ptr [ecx]                    
+009  56                   push    esi                                     
+00A  8bf0                 mov     esi, eax                                
+00C  81e6ffff0000         and     esi, 0xffff                             
+012  69f669900000         imul    esi, esi, 0x9069                        
+018  c1e810               shr     eax, 0x10                               
+01B  03f0                 add     esi, eax                                
+01D  8931                 mov     dword ptr [ecx], esi                    
+01F  8b4104               mov     eax, dword ptr [ecx + 4]                
+022  8d5104               lea     edx, [ecx + 4]                          
+025  8bf0                 mov     esi, eax                                
+027  81e6ffff0000         and     esi, 0xffff                             
+02D  69f650460000         imul    esi, esi, 0x4650                        
+033  c1e810               shr     eax, 0x10                               
+036  03c6                 add     eax, esi                                
+038  8902                 mov     dword ptr [edx], eax                    
+03A  8b09                 mov     ecx, dword ptr [ecx]                    
+03C  25ffff0000           and     eax, 0xffff                             
+041  c1e110               shl     ecx, 0x10                               
+044  03c1                 add     eax, ecx                                
+046  25ffff7f00           and     eax, 0x7fffff                           
+04B  0d0000803f           or      eax, 0x3f800000                         0x3f800000=1 f32
+050  89442404             mov     dword ptr [esp + 4], eax                
+054  5e                   pop     esi                                     
+055  d90424               fld     dword ptr [esp]                         
+058  d82564d63900         fsub    dword ptr [0x39d664]                   DIR32 0x39d664(.rdata) [0x39d664]=1
+05E  59                   pop     ecx                                     
+05F  c3                   ret                                             
```

## 0x00018F90  (85 B, U)
thiscall float Gen::Next01() — same body on ecx=this; push ecx/pop ecx = 4-byte temp for the int→float pun.
```
+000  51                   push    ecx                                     
+001  8b01                 mov     eax, dword ptr [ecx]                    
+003  8bd0                 mov     edx, eax                                
+005  81e2ffff0000         and     edx, 0xffff                             
+00B  69d269900000         imul    edx, edx, 0x9069                        
+011  c1e810               shr     eax, 0x10                               
+014  03d0                 add     edx, eax                                
+016  8911                 mov     dword ptr [ecx], edx                    
+018  8b4104               mov     eax, dword ptr [ecx + 4]                
+01B  8bd0                 mov     edx, eax                                
+01D  81e2ffff0000         and     edx, 0xffff                             
+023  69d250460000         imul    edx, edx, 0x4650                        
+029  c1e810               shr     eax, 0x10                               
+02C  03c2                 add     eax, edx                                
+02E  894104               mov     dword ptr [ecx + 4], eax                
+031  8b09                 mov     ecx, dword ptr [ecx]                    
+033  25ffff0000           and     eax, 0xffff                             
+038  c1e110               shl     ecx, 0x10                               
+03B  03c1                 add     eax, ecx                                
+03D  25ffff7f00           and     eax, 0x7fffff                           
+042  0d0000803f           or      eax, 0x3f800000                         0x3f800000=1 f32
+047  890424               mov     dword ptr [esp], eax                    
+04A  d90424               fld     dword ptr [esp]                         
+04D  d82564d63900         fsub    dword ptr [0x39d664]                   DIR32 0x39d664(.rdata) [0x39d664]=1
+053  59                   pop     ecx                                     
+054  c3                   ret                                             
```

## 0x0002FAD0  (94 B, U)
cdecl int RandRange(int lo, int hi) — global gen; lo + r % (u32)(hi−lo+1) (div = unsigned).
```
+000  8b0de02e4900         mov     ecx, dword ptr [0x492ee0]              DIR32 0x492ee0(.data) 
+006  8b01                 mov     eax, dword ptr [ecx]                    
+008  56                   push    esi                                     
+009  57                   push    edi                                     
+00A  8bf8                 mov     edi, eax                                
+00C  81e7ffff0000         and     edi, 0xffff                             
+012  69ff69900000         imul    edi, edi, 0x9069                        
+018  c1e810               shr     eax, 0x10                               
+01B  03f8                 add     edi, eax                                
+01D  8d5104               lea     edx, [ecx + 4]                          
+020  8939                 mov     dword ptr [ecx], edi                    
+022  8b02                 mov     eax, dword ptr [edx]                    
+024  8bf1                 mov     esi, ecx                                
+026  8bc8                 mov     ecx, eax                                
+028  81e1ffff0000         and     ecx, 0xffff                             
+02E  69c950460000         imul    ecx, ecx, 0x4650                        
+034  c1e810               shr     eax, 0x10                               
+037  03c8                 add     ecx, eax                                
+039  890a                 mov     dword ptr [edx], ecx                    
+03B  8b06                 mov     eax, dword ptr [esi]                    
+03D  8b742410             mov     esi, dword ptr [esp + 0x10]             
+041  c1e010               shl     eax, 0x10                               
+044  81e1ffff0000         and     ecx, 0xffff                             
+04A  03c1                 add     eax, ecx                                
+04C  8b4c240c             mov     ecx, dword ptr [esp + 0xc]              
+050  2bf1                 sub     esi, ecx                                
+052  46                   inc     esi                                     
+053  33d2                 xor     edx, edx                                
+055  f7f6                 div     esi                                     
+057  5f                   pop     edi                                     
+058  5e                   pop     esi                                     
+059  8bc2                 mov     eax, edx                                
+05B  03c1                 add     eax, ecx                                
+05D  c3                   ret                                             
```

## 0x0002FA70  (84 B, U)
thiscall int Gen::Range(int lo, int hi) ret 8 — same on ecx=this.
```
+000  8b01                 mov     eax, dword ptr [ecx]                    
+002  8bd0                 mov     edx, eax                                
+004  81e2ffff0000         and     edx, 0xffff                             
+00A  69d269900000         imul    edx, edx, 0x9069                        
+010  c1e810               shr     eax, 0x10                               
+013  03d0                 add     edx, eax                                
+015  8911                 mov     dword ptr [ecx], edx                    
+017  8b4104               mov     eax, dword ptr [ecx + 4]                
+01A  8bd0                 mov     edx, eax                                
+01C  81e2ffff0000         and     edx, 0xffff                             
+022  69d250460000         imul    edx, edx, 0x4650                        
+028  c1e810               shr     eax, 0x10                               
+02B  03c2                 add     eax, edx                                
+02D  894104               mov     dword ptr [ecx + 4], eax                
+030  8b09                 mov     ecx, dword ptr [ecx]                    
+032  25ffff0000           and     eax, 0xffff                             
+037  c1e110               shl     ecx, 0x10                               
+03A  03c1                 add     eax, ecx                                
+03C  8b4c2404             mov     ecx, dword ptr [esp + 4]                
+040  56                   push    esi                                     
+041  8b74240c             mov     esi, dword ptr [esp + 0xc]              
+045  2bf1                 sub     esi, ecx                                
+047  46                   inc     esi                                     
+048  33d2                 xor     edx, edx                                
+04A  f7f6                 div     esi                                     
+04C  5e                   pop     esi                                     
+04D  8bc2                 mov     eax, edx                                
+04F  03c1                 add     eax, ecx                                
+051  c20800               ret     8                                       
```

## 0x002445E0  (75 B, U)
cdecl void Free(void* p) — arena=*(Node**)0x493B60; if arena && arena->obj != *(void**)0x4BC294 && arena->obj->vfunc+0x18(p) (Contains): node=0x244540(arena,p) else node=0x244540(&root 0x493B40,p); *(Node**)0x493B60=node; node->obj->vfunc+0x14(p) (thiscall Free). Arena cache updated on every free.
```
+000  a1603b4900           mov     eax, dword ptr [0x493b60]              DIR32 0x493b60(.data) 
+005  85c0                 test    eax, eax                                
+007  56                   push    esi                                     
+008  8b742408             mov     esi, dword ptr [esp + 8]                
+00C  741e                 je      0x24460c                                
+00E  8b08                 mov     ecx, dword ptr [eax]                    
+010  3b0d94c24b00         cmp     ecx, dword ptr [0x4bc294]              DIR32 0x4bc294(.data) 
+016  7414                 je      0x24460c                                
+018  8b01                 mov     eax, dword ptr [ecx]                    
+01A  56                   push    esi                                     
+01B  ff5018               call    dword ptr [eax + 0x18]                  
+01E  84c0                 test    al, al                                  
+020  740a                 je      0x24460c                                
+022  8b0d603b4900         mov     ecx, dword ptr [0x493b60]              DIR32 0x493b60(.data) 
+028  56                   push    esi                                     
+029  51                   push    ecx                                     
+02A  eb06                 jmp     0x244612                                
+02C  56                   push    esi                                     
+02D  68403b4900           push    0x493b40                               DIR32 0x493b40(.data) 
+032  e829ffffff           call    0x244540                               REL32→0x244540 
+037  a3603b4900           mov     dword ptr [0x493b60], eax              DIR32 0x493b60(.data) 
+03C  8b00                 mov     eax, dword ptr [eax]                    
+03E  8b10                 mov     edx, dword ptr [eax]                    
+040  83c408               add     esp, 8                                  
+043  56                   push    esi                                     
+044  8bc8                 mov     ecx, eax                                
+046  ff5214               call    dword ptr [edx + 0x14]                  
+049  5e                   pop     esi                                     
+04A  c3                   ret                                             
```

## 0x00244540  (62 B, U)
cdecl Node* FindOwner(Node* n, void* p) — walk siblings n=n->+8; if n->obj(+0)->vfunc+0x18(p) (bool Contains): deeper=FindOwner(n->child +4, p); return deeper?deeper:n. none → 0. Note +0xE 'mov edi,edi' (8bff) = 2-byte alignment pad before the loop head 0x244550.
```
+000  56                   push    esi                                     
+001  8b742408             mov     esi, dword ptr [esp + 8]                
+005  85f6                 test    esi, esi                                
+007  57                   push    edi                                     
+008  7419                 je      0x244563                                
+00A  8b7c2410             mov     edi, dword ptr [esp + 0x10]             
+00E  8bff                 mov     edi, edi                                
+010  8b0e                 mov     ecx, dword ptr [esi]                    
+012  8b01                 mov     eax, dword ptr [ecx]                    
+014  57                   push    edi                                     
+015  ff5018               call    dword ptr [eax + 0x18]                  
+018  84c0                 test    al, al                                  
+01A  750c                 jne     0x244568                                
+01C  8b7608               mov     esi, dword ptr [esi + 8]                
+01F  85f6                 test    esi, esi                                
+021  75ed                 jne     0x244550                                
+023  33c0                 xor     eax, eax                                
+025  5f                   pop     edi                                     
+026  5e                   pop     esi                                     
+027  c3                   ret                                             
+028  8b4e04               mov     ecx, dword ptr [esi + 4]                
+02B  57                   push    edi                                     
+02C  51                   push    ecx                                     
+02D  e8ceffffff           call    0x244540                                
+032  83c408               add     esp, 8                                  
+035  85c0                 test    eax, eax                                
+037  75ec                 jne     0x244565                                
+039  5f                   pop     edi                                     
+03A  8bc6                 mov     eax, esi                                
+03C  5e                   pop     esi                                     
+03D  c3                   ret                                             
```

## 0x00240570  (144 B, U)
thiscall bool Stream::Read4(a,b,c,d) ret 0x10 — u8 +0x10 'pending open' (cleared), [+8]->vfunc+0x60() bool (status), on false this->0x23FDD0(); second status → u8 +0xC = 1 and this->0x23FFF0() else +0xC = 0; if !+0xC return 0; u8 +0xE selects 0x23FF60 vs 0x240150 (both thiscall, same 4 args, ret 0x10), result returned.
```
+000  56                   push    esi                                     
+001  8bf1                 mov     esi, ecx                                
+003  8a4610               mov     al, byte ptr [esi + 0x10]               
+006  84c0                 test    al, al                                  
+008  7434                 je      0x2405ae                                
+00A  8b4e08               mov     ecx, dword ptr [esi + 8]                
+00D  c6461000             mov     byte ptr [esi + 0x10], 0                
+011  8b01                 mov     eax, dword ptr [ecx]                    
+013  ff5060               call    dword ptr [eax + 0x60]                  
+016  84c0                 test    al, al                                  
+018  7507                 jne     0x240591                                
+01A  8bce                 mov     ecx, esi                                
+01C  e83ff8ffff           call    0x23fdd0                               REL32→0x23fdd0 
+021  8b4e08               mov     ecx, dword ptr [esi + 8]                
+024  8b11                 mov     edx, dword ptr [ecx]                    
+026  ff5260               call    dword ptr [edx + 0x60]                  
+029  84c0                 test    al, al                                  
+02B  740d                 je      0x2405aa                                
+02D  8bce                 mov     ecx, esi                                
+02F  c6460c01             mov     byte ptr [esi + 0xc], 1                 
+033  e848faffff           call    0x23fff0                               REL32→0x23fff0 
+038  eb04                 jmp     0x2405ae                                
+03A  c6460c00             mov     byte ptr [esi + 0xc], 0                 
+03E  8a460c               mov     al, byte ptr [esi + 0xc]                
+041  84c0                 test    al, al                                  
+043  7506                 jne     0x2405bb                                
+045  32c0                 xor     al, al                                  
+047  5e                   pop     esi                                     
+048  c21000               ret     0x10                                    
+04B  8a460e               mov     al, byte ptr [esi + 0xe]                
+04E  84c0                 test    al, al                                  
+050  751f                 jne     0x2405e1                                
+052  8b442414             mov     eax, dword ptr [esp + 0x14]             
+056  8b4c2410             mov     ecx, dword ptr [esp + 0x10]             
+05A  8b54240c             mov     edx, dword ptr [esp + 0xc]              
+05E  50                   push    eax                                     
+05F  8b44240c             mov     eax, dword ptr [esp + 0xc]              
+063  51                   push    ecx                                     
+064  52                   push    edx                                     
+065  50                   push    eax                                     
+066  8bce                 mov     ecx, esi                                
+068  e883f9ffff           call    0x23ff60                               REL32→0x23ff60 
+06D  5e                   pop     esi                                     
+06E  c21000               ret     0x10                                    
+071  8b4c2414             mov     ecx, dword ptr [esp + 0x14]             
+075  8b542410             mov     edx, dword ptr [esp + 0x10]             
+079  8b44240c             mov     eax, dword ptr [esp + 0xc]              
+07D  51                   push    ecx                                     
+07E  8b4c240c             mov     ecx, dword ptr [esp + 0xc]              
+082  52                   push    edx                                     
+083  50                   push    eax                                     
+084  51                   push    ecx                                     
+085  8bce                 mov     ecx, esi                                
+087  e854fbffff           call    0x240150                               REL32→0x240150 
+08C  5e                   pop     esi                                     
+08D  c21000               ret     0x10                                    
```

## 0x00011930  (28 B, U)
thiscall void LoadObject::Release() (slot1) — cnt=u32 +4; if cnt < 2 (unsigned jae) {+4 = 0x08000000; this->slot3(1) [vfunc+0xC, deleting dtor]} else +4 = cnt−1.
```
+000  8b4104               mov     eax, dword ptr [ecx + 4]                
+003  83f802               cmp     eax, 2                                  
+006  730f                 jae     0x11947                                 unsigned
+008  c7410400000008       mov     dword ptr [ecx + 4], 0x8000000          
+00F  8b01                 mov     eax, dword ptr [ecx]                    
+011  6a01                 push    1                                       
+013  ff500c               call    dword ptr [eax + 0xc]                   
+016  c3                   ret                                             
+017  48                   dec     eax                                     
+018  894104               mov     dword ptr [ecx + 4], eax                
+01B  c3                   ret                                             
```

## 0x002CF0E0  (24 B, U)
thiscall void om::Entity::Release() — u16 +0x20; if ==1 → this->slot3(1) ; else +0x20 = cnt−1 (dec eax on the zero-extended ax; stores ax).
```
+000  668b4120             mov     ax, word ptr [ecx + 0x20]               
+004  663d0100             cmp     ax, 1                                   
+008  7508                 jne     0x2cf0f2                                
+00A  8b01                 mov     eax, dword ptr [ecx]                    
+00C  6a01                 push    1                                       
+00E  ff500c               call    dword ptr [eax + 0xc]                   
+011  c3                   ret                                             
+012  48                   dec     eax                                     
+013  66894120             mov     word ptr [ecx + 0x20], ax               
+017  c3                   ret                                             
```

## 0x00242DF0  (50 B, U)
thiscall NameKey* NameKey::NameKey(const char* s) ret 4 — C-range TU (ebp frame); +0=0; if s: +0 = 0x244040(s,0) (cdecl, add esp,8) ; else +0 = 0 again (second store); return this.
```
+000  55                   push    ebp                                     
+001  8bec                 mov     ebp, esp                                
+003  8b4508               mov     eax, dword ptr [ebp + 8]                
+006  85c0                 test    eax, eax                                
+008  56                   push    esi                                     
+009  8bf1                 mov     esi, ecx                                
+00B  c70600000000         mov     dword ptr [esi], 0                      
+011  7414                 je      0x242e17                                
+013  6a00                 push    0                                       
+015  50                   push    eax                                     
+016  e835120000           call    0x244040                               REL32→0x244040 
+01B  8906                 mov     dword ptr [esi], eax                    
+01D  83c408               add     esp, 8                                  
+020  8bc6                 mov     eax, esi                                
+022  5e                   pop     esi                                     
+023  5d                   pop     ebp                                     
+024  c20400               ret     4                                       
+027  33c0                 xor     eax, eax                                
+029  8906                 mov     dword ptr [esi], eax                    
+02B  8bc6                 mov     eax, esi                                
+02D  5e                   pop     esi                                     
+02E  5d                   pop     ebp                                     
+02F  c20400               ret     4                                       
```

## 0x00098B70  (25 B, U)
thiscall Key* Key::Key(const Obj* o) ret 4 — +0 = o ? o->+0x10 : 0; return this (eax=this set first).
```
+000  8bc1                 mov     eax, ecx                                
+002  8b4c2404             mov     ecx, dword ptr [esp + 4]                
+006  85c9                 test    ecx, ecx                                
+008  7408                 je      0x98b82                                 
+00A  8b4910               mov     ecx, dword ptr [ecx + 0x10]             
+00D  8908                 mov     dword ptr [eax], ecx                    
+00F  c20400               ret     4                                       
+012  33c9                 xor     ecx, ecx                                
+014  8908                 mov     dword ptr [eax], ecx                    
+016  c20400               ret     4                                       
```

## 0x002C6360  (417 B, U)
thiscall void d3dNightlightShader::slot14(arg) ret 4 — see V2.
```
+000  53                   push    ebx                                     
+001  56                   push    esi                                     
+002  8bf1                 mov     esi, ecx                                
+004  8b8680000000         mov     eax, dword ptr [esi + 0x80]             
+00A  33db                 xor     ebx, ebx                                
+00C  85c0                 test    eax, eax                                
+00E  57                   push    edi                                     
+00F  741c                 je      0x2c638d                                
+011  8b4e14               mov     ecx, dword ptr [esi + 0x14]             
+014  6a02                 push    2                                       
+016  53                   push    ebx                                     
+017  6a04                 push    4                                       
+019  53                   push    ebx                                     
+01A  e881baffff           call    0x2c1e00                               REL32→0x2c1e00 
+01F  53                   push    ebx                                     
+020  53                   push    ebx                                     
+021  8bce                 mov     ecx, esi                                
+023  e89892fdff           call    0x29f620                               REL32→0x29f620 
+028  bb01000000           mov     ebx, 1                                  
+02D  8b7e14               mov     edi, dword ptr [esi + 0x14]             
+030  8b8e80000000         mov     ecx, dword ptr [esi + 0x80]             
+036  3b4f08               cmp     ecx, dword ptr [edi + 8]                
+039  7420                 je      0x2c63bb                                
+03B  85c9                 test    ecx, ecx                                
+03D  894f08               mov     dword ptr [edi + 8], ecx                
+040  6a00                 push    0                                       
+042  7407                 je      0x2c63ab                                
+044  e8673cfdff           call    0x29a010                               REL32→0x29a010 
+049  eb10                 jmp     0x2c63bb                                
+04B  6a00                 push    0                                       
+04D  e85e450600           call    0x32a910                               REL32→0x32a910 
+052  6a00                 push    0                                       
+054  6a00                 push    0                                       
+056  e805470600           call    0x32aac0                               REL32→0x32aac0 
+05B  8b470c               mov     eax, dword ptr [edi + 0xc]              
+05E  85c0                 test    eax, eax                                
+060  7419                 je      0x2c63db                                
+062  6a00                 push    0                                       
+064  6a01                 push    1                                       
+066  c7470c00000000       mov     dword ptr [edi + 0xc], 0                
+06D  e83e450600           call    0x32a910                               REL32→0x32a910 
+072  6a00                 push    0                                       
+074  6a01                 push    1                                       
+076  e8e5460600           call    0x32aac0                               REL32→0x32aac0 
+07B  8b4710               mov     eax, dword ptr [edi + 0x10]             
+07E  85c0                 test    eax, eax                                
+080  7419                 je      0x2c63fb                                
+082  6a00                 push    0                                       
+084  6a02                 push    2                                       
+086  c7471000000000       mov     dword ptr [edi + 0x10], 0               
+08D  e81e450600           call    0x32a910                               REL32→0x32a910 
+092  6a00                 push    0                                       
+094  6a02                 push    2                                       
+096  e8c5460600           call    0x32aac0                               REL32→0x32aac0 
+09B  8b4714               mov     eax, dword ptr [edi + 0x14]             
+09E  85c0                 test    eax, eax                                
+0A0  7419                 je      0x2c641b                                
+0A2  6a00                 push    0                                       
+0A4  6a03                 push    3                                       
+0A6  c7471400000000       mov     dword ptr [edi + 0x14], 0               
+0AD  e8fe440600           call    0x32a910                               REL32→0x32a910 
+0B2  6a00                 push    0                                       
+0B4  6a03                 push    3                                       
+0B6  e8a5460600           call    0x32aac0                               REL32→0x32aac0 
+0BB  53                   push    ebx                                     
+0BC  8bcf                 mov     ecx, edi                                
+0BE  e81dc2fbff           call    0x282640                               REL32→0x282640 
+0C3  8b4e14               mov     ecx, dword ptr [esi + 0x14]             
+0C6  8b464c               mov     eax, dword ptr [esi + 0x4c]             
+0C9  3b4148               cmp     eax, dword ptr [ecx + 0x48]             
+0CC  741c                 je      0x2c644a                                
+0CE  894148               mov     dword ptr [ecx + 0x48], eax             
+0D1  8b3c8564c24500       mov     edi, dword ptr [eax*4 + 0x45c264]      DIR32 0x45c264(.data) [0x45c264]=0x00001d00
+0D8  8bd7                 mov     edx, edi                                
+0DA  b97c030400           mov     ecx, 0x4037c                           DIR32 0x4037c(.text) 
+0DF  e80c640600           call    0x32c850                               REL32→0x32c850 
+0E4  893d88a93300         mov     dword ptr [0x33a988], edi              DIR32 0x33a988(D3D) 
+0EA  33c9                 xor     ecx, ecx                                
+0EC  8a4e7c               mov     cl, byte ptr [esi + 0x7c]               
+0EF  33d2                 xor     edx, edx                                
+0F1  8a5648               mov     dl, byte ptr [esi + 0x48]               
+0F4  8d4650               lea     eax, [esi + 0x50]                       
+0F7  50                   push    eax                                     
+0F8  51                   push    ecx                                     
+0F9  8b4e14               mov     ecx, dword ptr [esi + 0x14]             
+0FC  52                   push    edx                                     
+0FD  e84ec3fbff           call    0x2827b0                               REL32→0x2827b0 
+102  8b4e14               mov     ecx, dword ptr [esi + 0x14]             
+105  6a01                 push    1                                       
+107  6a01                 push    1                                       
+109  6806800000           push    0x8006                                  
+10E  6a01                 push    1                                       
+110  e8abc3fbff           call    0x282820                               REL32→0x282820 
+115  d94634               fld     dword ptr [esi + 0x34]                  
+118  d80dc40f3a00         fmul    dword ptr [0x3a0fc4]                   DIR32 0x3a0fc4(.rdata) [0x3a0fc4]=255
+11E  e8895d0300           call    0x2fc20c                               REL32→0x2fc20c 
+123  33c9                 xor     ecx, ecx                                
+125  8a4e28               mov     cl, byte ptr [esi + 0x28]               
+128  50                   push    eax                                     
+129  8b462c               mov     eax, dword ptr [esi + 0x2c]             
+12C  50                   push    eax                                     
+12D  51                   push    ecx                                     
+12E  8b4e14               mov     ecx, dword ptr [esi + 0x14]             
+131  e82ac4fbff           call    0x2828c0                               REL32→0x2828c0 
+136  8b8680000000         mov     eax, dword ptr [esi + 0x80]             
+13C  85c0                 test    eax, eax                                
+13E  8b7614               mov     esi, dword ptr [esi + 0x14]             
+141  8b8e10010000         mov     ecx, dword ptr [esi + 0x110]            
+147  7514                 jne     0x2c64bd                                
+149  a188dc4b00           mov     eax, dword ptr [0x4bdc88]              DIR32 0x4bdc88(.data) 
+14E  3bc8                 cmp     ecx, eax                                
+150  7420                 je      0x2c64d2                                
+152  8bd0                 mov     edx, eax                                
+154  898610010000         mov     dword ptr [esi + 0x110], eax            
+15A  52                   push    edx                                     
+15B  eb10                 jmp     0x2c64cd                                
+15D  a184dc4b00           mov     eax, dword ptr [0x4bdc84]              DIR32 0x4bdc84(.data) 
+162  3bc8                 cmp     ecx, eax                                
+164  740c                 je      0x2c64d2                                
+166  898610010000         mov     dword ptr [esi + 0x110], eax            
+16C  50                   push    eax                                     
+16D  e8ae910600           call    0x32f680                               REL32→0x32f680 
+172  a0b4d44b00           mov     al, byte ptr [0x4bd4b4]                DIR32 0x4bd4b4(.data) 
+177  84c0                 test    al, al                                  
+179  5f                   pop     edi                                     
+17A  5e                   pop     esi                                     
+17B  5b                   pop     ebx                                     
+17C  7420                 je      0x2c64fe                                
+17E  a178a63300           mov     eax, dword ptr [0x33a678]              DIR32 0x33a678(D3D) 
+183  0d00300000           or      eax, 0x3000                             
+188  c605b4d44b0000       mov     byte ptr [0x4bd4b4], 0                 DIR32 0x4bd4b4(.data) 
+18F  a378a63300           mov     dword ptr [0x33a678], eax              DIR32 0x33a678(D3D) 
+194  c7051caa330000000000 mov     dword ptr [0x33aa1c], 0                DIR32 0x33aa1c(D3D) 
+19E  c20400               ret     4                                       
```

## 0x002C6150  (452 B, U)
thiscall void d3dNightlightShader::slot24() — ebp frame, 0x234 locals; see V2.
```
+000  55                   push    ebp                                     
+001  8bec                 mov     ebp, esp                                
+003  81ec34020000         sub     esp, 0x234                              
+009  53                   push    ebx                                     
+00A  56                   push    esi                                     
+00B  8bd9                 mov     ebx, ecx                                
+00D  57                   push    edi                                     
+00E  8d55e0               lea     edx, [ebp - 0x20]                       
+011  b960000000           mov     ecx, 0x60                               
+016  c745e000000000       mov     dword ptr [ebp - 0x20], 0               
+01D  c745e40000003f       mov     dword ptr [ebp - 0x1c], 0x3f000000      0x3f000000=0.5 f32
+024  c745e80000803f       mov     dword ptr [ebp - 0x18], 0x3f800000      0x3f800000=1 f32
+02B  c745ec8180803b       mov     dword ptr [ebp - 0x14], 0x3b808081      0x3b808081=0.00392157 f32
+032  e869840600           call    0x32e5f0                               REL32→0x32e5f0 
+037  8d850cffffff         lea     eax, [ebp - 0xf4]                       
+03D  50                   push    eax                                     
+03E  6a06                 push    6                                       
+040  e8bb360600           call    0x329850                               REL32→0x329850 
+045  8d8d8cfeffff         lea     ecx, [ebp - 0x174]                      
+04B  51                   push    ecx                                     
+04C  6a00                 push    0                                       
+04E  e8ad360600           call    0x329850                               REL32→0x329850 
+053  8d950cfeffff         lea     edx, [ebp - 0x1f4]                      
+059  52                   push    edx                                     
+05A  6a01                 push    1                                       
+05C  e89f360600           call    0x329850                               REL32→0x329850 
+061  8d858cfeffff         lea     eax, [ebp - 0x174]                      
+067  50                   push    eax                                     
+068  8d8d0cffffff         lea     ecx, [ebp - 0xf4]                       
+06E  51                   push    ecx                                     
+06F  8d8d4cfeffff         lea     ecx, [ebp - 0x1b4]                      
+075  e8e6d7f7ff           call    0x2439b0                               REL32→0x2439b0 
+07A  8d950cfeffff         lea     edx, [ebp - 0x1f4]                      
+080  52                   push    edx                                     
+081  8d854cfeffff         lea     eax, [ebp - 0x1b4]                      
+087  50                   push    eax                                     
+088  8d8dccfdffff         lea     ecx, [ebp - 0x234]                      
+08E  e84dd9f7ff           call    0x243b30                               REL32→0x243b30 
+093  b910000000           mov     ecx, 0x10                               
+098  8db5ccfdffff         lea     esi, [ebp - 0x234]                      
+09E  8dbd4cffffff         lea     edi, [ebp - 0xb4]                       
+0A4  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]     
+0A6  8d8d4cffffff         lea     ecx, [ebp - 0xb4]                       
+0AC  e8dfd1f7ff           call    0x2433e0                               REL32→0x2433e0 
+0B1  b910000000           mov     ecx, 0x10                               
+0B6  8db50cffffff         lea     esi, [ebp - 0xf4]                       
+0BC  8d7d8c               lea     edi, [ebp - 0x74]                       
+0BF  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]     
+0C1  8d4d8c               lea     ecx, [ebp - 0x74]                       
+0C4  e8c7d1f7ff           call    0x2433e0                               REL32→0x2433e0 
+0C9  6a10                 push    0x10                                    
+0CB  8d558c               lea     edx, [ebp - 0x74]                       
+0CE  b96a000000           mov     ecx, 0x6a                               
+0D3  e8c8840600           call    0x32e6f0                               REL32→0x32e6f0 
+0D8  6a10                 push    0x10                                    
+0DA  8d954cffffff         lea     edx, [ebp - 0xb4]                       
+0E0  b96e000000           mov     ecx, 0x6e                               
+0E5  e8b6840600           call    0x32e6f0                               REL32→0x32e6f0 
+0EA  8b4b10               mov     ecx, dword ptr [ebx + 0x10]             
+0ED  8b11                 mov     edx, dword ptr [ecx]                    
+0EF  ff92cc010000         call    dword ptr [edx + 0x1cc]                 
+0F5  8bf0                 mov     esi, eax                                
+0F7  b910000000           mov     ecx, 0x10                               
+0FC  8dbdccfeffff         lea     edi, [ebp - 0x134]                      
+102  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]     
+104  8d8dccfeffff         lea     ecx, [ebp - 0x134]                      
+10A  e881d1f7ff           call    0x2433e0                               REL32→0x2433e0 
+10F  6a10                 push    0x10                                    
+111  8d95ccfeffff         lea     edx, [ebp - 0x134]                      
+117  b993000000           mov     ecx, 0x93                               
+11C  e87f840600           call    0x32e6f0                               REL32→0x32e6f0 
+121  8b4b10               mov     ecx, dword ptr [ebx + 0x10]             
+124  8b01                 mov     eax, dword ptr [ecx]                    
+126  ff90b0010000         call    dword ptr [eax + 0x1b0]                 
+12C  84c0                 test    al, al                                  
+12E  c745d0000080bf       mov     dword ptr [ebp - 0x30], 0xbf800000      0xbf800000=-1 f32
+135  7507                 jne     0x2c628e                                
+137  c745d000000000       mov     dword ptr [ebp - 0x30], 0               
+13E  8d55cc               lea     edx, [ebp - 0x34]                       
+141  b992000000           mov     ecx, 0x92                               
+146  e855830600           call    0x32e5f0                               REL32→0x32e5f0 
+14B  db4338               fild    dword ptr [ebx + 0x38]                  
+14E  8b4b38               mov     ecx, dword ptr [ebx + 0x38]             
+151  85c9                 test    ecx, ecx                                
+153  c745f00000803f       mov     dword ptr [ebp - 0x10], 0x3f800000      0x3f800000=1 f32
+15A  c745f40000803f       mov     dword ptr [ebp - 0xc], 0x3f800000       0x3f800000=1 f32
+161  c745f80000803f       mov     dword ptr [ebp - 8], 0x3f800000         0x3f800000=1 f32
+168  c745fc0000803f       mov     dword ptr [ebp - 4], 0x3f800000         0x3f800000=1 f32
+16F  7d06                 jge     0x2c62c7                                signed
+171  d8055cf33900         fadd    dword ptr [0x39f35c]                   DIR32 0x39f35c(.rdata) [0x39f35c]=4.29497e+09
+177  d90584d53900         fld     dword ptr [0x39d584]                   DIR32 0x39d584(.rdata) [0x39d584]=0
+17D  5f                   pop     edi                                     
+17E  d9c1                 fld     st(1)                                   
+180  5e                   pop     esi                                     
+181  dae9                 fucompp                                         
+183  5b                   pop     ebx                                     
+184  dfe0                 fnstsw  ax                                      
+186  f6c444               test    ah, 0x44                                
+189  7b26                 jnp     0x2c6301                                
+18B  d80dc0e93900         fmul    dword ptr [0x39e9c0]                   DIR32 0x39e9c0(.rdata) [0x39e9c0]=0.00392157
+191  8d55f0               lea     edx, [ebp - 0x10]                       
+194  b997000000           mov     ecx, 0x97                               
+199  d82d64d63900         fsubr   dword ptr [0x39d664]                   DIR32 0x39d664(.rdata) [0x39d664]=1
+19F  d955f0               fst     dword ptr [ebp - 0x10]                  
+1A2  d955f4               fst     dword ptr [ebp - 0xc]                   
+1A5  d95df8               fstp    dword ptr [ebp - 8]                     
+1A8  e8f3820600           call    0x32e5f0                               REL32→0x32e5f0 
+1AD  8be5                 mov     esp, ebp                                
+1AF  5d                   pop     ebp                                     
+1B0  c3                   ret                                             
+1B1  8d55f0               lea     edx, [ebp - 0x10]                       
+1B4  ddd8                 fstp    st(0)                                   
+1B6  b997000000           mov     ecx, 0x97                               
+1BB  e8e0820600           call    0x32e5f0                               REL32→0x32e5f0 
+1C0  8be5                 mov     esp, ebp                                
+1C2  5d                   pop     ebp                                     
+1C3  c3                   ret                                             
```

## 0x001504F0  (160 B, U)
thiscall void CameraManager::AddShake(int axis, f32 dur, f32 freq, f32 amp, f32 noise) ret 0x14 — see V1.
```
+000  8b442404             mov     eax, dword ptr [esp + 4]                
+004  85c0                 test    eax, eax                                
+006  0f8c91000000         jl      0x15058d                                signed
+00C  83f806               cmp     eax, 6                                  
+00F  0f8d88000000         jge     0x15058d                                signed
+015  0f57c0               xorps   xmm0, xmm0                              
+018  8d54800f             lea     edx, [eax + eax*4 + 0xf]                
+01C  f30f100c91           movss   xmm1, dword ptr [ecx + edx*4]           
+021  0f2fc8               comiss  xmm1, xmm0                              
+024  8d1491               lea     edx, [ecx + edx*4]                      
+027  763e                 jbe     0x150557                                unsigned
+029  d9055cd63900         fld     dword ptr [0x39d65c]                   DIR32 0x39d65c(.rdata) [0x39d65c]=-1
+02F  56                   push    esi                                     
+030  d832                 fdiv    dword ptr [edx]                         
+032  8d3480               lea     esi, [eax + eax*4]                      
+035  8d34b1               lea     esi, [ecx + esi*4]                      
+038  d84e38               fmul    dword ptr [esi + 0x38]                  
+03B  d80d407e3c00         fmul    dword ptr [0x3c7e40]                   DIR32 0x3c7e40(.rdata) [0x3c7e40]=3
+041  d9ea                 fldl2e                                          
+043  dec9                 fmulp   st(1)                                   
+045  d9c0                 fld     st(0)                                   
+047  d9fc                 frndint                                         
+049  d9c9                 fxch    st(1)                                   
+04B  d8e1                 fsub    st(1)                                   
+04D  d9f0                 f2xm1                                           
+04F  d9e8                 fld1                                            
+051  dec1                 faddp   st(1)                                   
+053  d9fd                 fscale                                          
+055  ddd9                 fstp    st(1)                                   
+057  d84e44               fmul    dword ptr [esi + 0x44]                  
+05A  d9442414             fld     dword ptr [esp + 0x14]                  
+05E  5e                   pop     esi                                     
+05F  d9c9                 fxch    st(1)                                   
+061  dff1                 fcompi  st(1)                                   
+063  ddd8                 fstp    st(0)                                   
+065  7736                 ja      0x15058d                                unsigned
+067  8d0480               lea     eax, [eax + eax*4]                      
+06A  8d0481               lea     eax, [ecx + eax*4]                      
+06D  f30f114038           movss   dword ptr [eax + 0x38], xmm0            
+072  f30f10442408         movss   xmm0, dword ptr [esp + 8]               
+078  f30f1102             movss   dword ptr [edx], xmm0                   
+07C  f30f1044240c         movss   xmm0, dword ptr [esp + 0xc]             
+082  f30f114040           movss   dword ptr [eax + 0x40], xmm0            
+087  f30f10442410         movss   xmm0, dword ptr [esp + 0x10]            
+08D  f30f114044           movss   dword ptr [eax + 0x44], xmm0            
+092  f30f10442414         movss   xmm0, dword ptr [esp + 0x14]            
+098  f30f114048           movss   dword ptr [eax + 0x48], xmm0            
+09D  c21400               ret     0x14                                    
```

## 0x00150590  (495 B, U)
thiscall bool CameraManager::IntegrateShake(Frame* f) ret 4 — see V1; 'nop' at +0x1F = loop-head alignment.
```
+000  83ec70               sub     esp, 0x70                               
+003  0f57c9               xorps   xmm1, xmm1                              
+006  f30f101564d63900     movss   xmm2, dword ptr [0x39d664]             DIR32 0x39d664(.rdata) [0x39d664]=1
+00E  55                   push    ebp                                     
+00F  57                   push    edi                                     
+010  33c0                 xor     eax, eax                                
+012  8be9                 mov     ebp, ecx                                
+014  53                   push    ebx                                     
+015  8844240f             mov     byte ptr [esp + 0xf], al                
+019  33ff                 xor     edi, edi                                
+01B  8d5538               lea     edx, [ebp + 0x38]                       
+01E  56                   push    esi                                     
+01F  90                   nop                                             
+020  f30f104204           movss   xmm0, dword ptr [edx + 4]               
+025  0f2fc1               comiss  xmm0, xmm1                              
+028  f30f114cbc28         movss   dword ptr [esp + edi*4 + 0x28], xmm1    
+02E  0f86e8000000         jbe     0x1506ac                                unsigned
+034  d94208               fld     dword ptr [edx + 8]                     
+037  f30f104210           movss   xmm0, dword ptr [edx + 0x10]            
+03C  d80a                 fmul    dword ptr [edx]                         
+03E  0f2ec1               ucomiss xmm0, xmm1                              
+041  9f                   lahf                                            
+042  f6c444               test    ah, 0x44                                
+045  d80d4c2f3b00         fmul    dword ptr [0x3b2f4c]                   DIR32 0x3b2f4c(.rdata) [0x3b2f4c]=6.28319
+04B  d9fe                 fsin                                            
+04D  d95c2414             fstp    dword ptr [esp + 0x14]                  
+051  7b6d                 jnp     0x150650                                
+053  8b0de02e4900         mov     ecx, dword ptr [0x492ee0]              DIR32 0x492ee0(.data) 
+059  8b01                 mov     eax, dword ptr [ecx]                    
+05B  8bd8                 mov     ebx, eax                                
+05D  81e3ffff0000         and     ebx, 0xffff                             
+063  69db69900000         imul    ebx, ebx, 0x9069                        
+069  c1e810               shr     eax, 0x10                               
+06C  03d8                 add     ebx, eax                                
+06E  8919                 mov     dword ptr [ecx], ebx                    
+070  8b4104               mov     eax, dword ptr [ecx + 4]                
+073  8d7104               lea     esi, [ecx + 4]                          
+076  8bd8                 mov     ebx, eax                                
+078  81e3ffff0000         and     ebx, 0xffff                             
+07E  69db50460000         imul    ebx, ebx, 0x4650                        
+084  c1e810               shr     eax, 0x10                               
+087  03c3                 add     eax, ebx                                
+089  8906                 mov     dword ptr [esi], eax                    
+08B  8b09                 mov     ecx, dword ptr [ecx]                    
+08D  25ffff0000           and     eax, 0xffff                             
+092  c1e110               shl     ecx, 0x10                               
+095  03c1                 add     eax, ecx                                
+097  25ffff7f00           and     eax, 0x7fffff                           
+09C  0d0000803f           or      eax, 0x3f800000                         0x3f800000=1 f32
+0A1  89442418             mov     dword ptr [esp + 0x18], eax             
+0A5  f30f10442418         movss   xmm0, dword ptr [esp + 0x18]            
+0AB  f30f5cc2             subss   xmm0, xmm2                              
+0AF  f30f594210           mulss   xmm0, dword ptr [edx + 0x10]            
+0B4  f30f58442414         addss   xmm0, dword ptr [esp + 0x14]            
+0BA  f30f11442414         movss   dword ptr [esp + 0x14], xmm0            
+0C0  d9055cd63900         fld     dword ptr [0x39d65c]                   DIR32 0x39d65c(.rdata) [0x39d65c]=-1
+0C6  8b842484000000       mov     eax, dword ptr [esp + 0x84]             
+0CD  d87204               fdiv    dword ptr [edx + 4]                     
+0D0  f30f10400c           movss   xmm0, dword ptr [eax + 0xc]             
+0D5  f30f5802             addss   xmm0, dword ptr [edx]                   
+0D9  0f2f4204             comiss  xmm0, dword ptr [edx + 4]               
+0DD  d80a                 fmul    dword ptr [edx]                         
+0DF  f30f1102             movss   dword ptr [edx], xmm0                   
+0E3  d80d407e3c00         fmul    dword ptr [0x3c7e40]                   DIR32 0x3c7e40(.rdata) [0x3c7e40]=3
+0E9  d9ea                 fldl2e                                          
+0EB  dec9                 fmulp   st(1)                                   
+0ED  d9c0                 fld     st(0)                                   
+0EF  d9fc                 frndint                                         
+0F1  d9c9                 fxch    st(1)                                   
+0F3  d8e1                 fsub    st(1)                                   
+0F5  d9f0                 f2xm1                                           
+0F7  d9e8                 fld1                                            
+0F9  dec1                 faddp   st(1)                                   
+0FB  d9fd                 fscale                                          
+0FD  ddd9                 fstp    st(1)                                   
+0FF  d84a0c               fmul    dword ptr [edx + 0xc]                   
+102  d84c2414             fmul    dword ptr [esp + 0x14]                  
+106  d95cbc28             fstp    dword ptr [esp + edi*4 + 0x28]          
+10A  7605                 jbe     0x1506a1                                unsigned
+10C  f30f114a04           movss   dword ptr [edx + 4], xmm1               
+111  83ff03               cmp     edi, 3                                  
+114  b001                 mov     al, 1                                   
+116  7c04                 jl      0x1506ac                                signed
+118  88442413             mov     byte ptr [esp + 0x13], al               
+11C  47                   inc     edi                                     
+11D  83c214               add     edx, 0x14                               
+120  83ff06               cmp     edi, 6                                  
+123  0f8cf7feffff         jl      0x1505b0                                signed
+129  84c0                 test    al, al                                  
+12B  5e                   pop     esi                                     
+12C  5b                   pop     ebx                                     
+12D  7508                 jne     0x1506c7                                
+12F  5f                   pop     edi                                     
+130  5d                   pop     ebp                                     
+131  83c470               add     esp, 0x70                               
+134  c20400               ret     4                                       
+137  8d4c2438             lea     ecx, [esp + 0x38]                       
+13B  e8e0270f00           call    0x242eb0                               REL32→0x242eb0 
+140  8a44240b             mov     al, byte ptr [esp + 0xb]                
+144  84c0                 test    al, al                                  
+146  7443                 je      0x15071b                                
+148  f30f1005fc003a00     movss   xmm0, dword ptr [0x3a00fc]             DIR32 0x3a00fc(.rdata) [0x3a00fc]=0.0174533
+150  f30f104c2434         movss   xmm1, dword ptr [esp + 0x34]            
+156  f30f59c8             mulss   xmm1, xmm0                              
+15A  83ec0c               sub     esp, 0xc                                
+15D  f30f114c2408         movss   dword ptr [esp + 8], xmm1               
+163  f30f104c243c         movss   xmm1, dword ptr [esp + 0x3c]            
+169  f30f59c8             mulss   xmm1, xmm0                              
+16D  f30f114c2404         movss   dword ptr [esp + 4], xmm1               
+173  f30f104c2438         movss   xmm1, dword ptr [esp + 0x38]            
+179  f30f59c8             mulss   xmm1, xmm0                              
+17D  8d4c2444             lea     ecx, [esp + 0x44]                       
+181  f30f110c24           movss   dword ptr [esp], xmm1                   
+186  e805290f00           call    0x243020                               REL32→0x243020 
+18B  f30f10442420         movss   xmm0, dword ptr [esp + 0x20]            
+191  f30f11442414         movss   dword ptr [esp + 0x14], xmm0            
+197  f30f10442424         movss   xmm0, dword ptr [esp + 0x24]            
+19D  8d4c2414             lea     ecx, [esp + 0x14]                       
+1A1  f30f11442418         movss   dword ptr [esp + 0x18], xmm0            
+1A7  f30f10442428         movss   xmm0, dword ptr [esp + 0x28]            
+1AD  51                   push    ecx                                     
+1AE  8d4c243c             lea     ecx, [esp + 0x3c]                       
+1B2  f30f11442420         movss   dword ptr [esp + 0x20], xmm0            
+1B8  e8232a0f00           call    0x243170                               REL32→0x243170 
+1BD  8b8db0000000         mov     ecx, dword ptr [ebp + 0xb0]             
+1C3  8b11                 mov     edx, dword ptr [ecx]                    
+1C5  ff5240               call    dword ptr [edx + 0x40]                  
+1C8  50                   push    eax                                     
+1C9  8d44243c             lea     eax, [esp + 0x3c]                       
+1CD  50                   push    eax                                     
+1CE  8bc8                 mov     ecx, eax                                
+1D0  e84b320f00           call    0x2439b0                               REL32→0x2439b0 
+1D5  8b8db0000000         mov     ecx, dword ptr [ebp + 0xb0]             
+1DB  8b11                 mov     edx, dword ptr [ecx]                    
+1DD  8d442438             lea     eax, [esp + 0x38]                       
+1E1  50                   push    eax                                     
+1E2  ff5264               call    dword ptr [edx + 0x64]                  
+1E5  5f                   pop     edi                                     
+1E6  b001                 mov     al, 1                                   
+1E8  5d                   pop     ebp                                     
+1E9  83c470               add     esp, 0x70                               
+1EC  c20400               ret     4                                       
```

## DIFF 0x243FA0 (75 B) vs 0x243FF0 (67 B)
0x243FF0 = 0x243FA0 with the 8-byte fold "cmp cl,0x61 / jge +3 / add ecx,0x20" removed and movsx hoisted before the AND (scheduling):
```
FA: +019  8da42400000000       lea     esp, [esp]                              
FA: +020  69c03f000100         imul    eax, eax, 0x1003f                       
FA: +026  25ffffff7f           and     eax, 0x7fffffff                         
FA: +02B  80f961               cmp     cl, 0x61                                
FA: +02E  0fbec9               movsx   ecx, cl                                 
FA: +031  7d03                 jge     0x243fd6                                signed
FA: +033  83c120               add     ecx, 0x20                               
FF: +019  8da42400000000       lea     esp, [esp]                              
FF: +020  69c03f000100         imul    eax, eax, 0x1003f                       
FF: +026  0fbec9               movsx   ecx, cl                                 
FF: +029  25ffffff7f           and     eax, 0x7fffffff                         
FF: +02E  33c1                 xor     eax, ecx                                
```