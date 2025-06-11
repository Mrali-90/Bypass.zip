#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Macros.h"

#define LibUE4 ("libUE4.so")
#define Libanogs ("libanogs.so")
#define Libanort ("libanort.so")
#define Libgcloud ("libhdmpve.so")
#define Libtdata ("libTDataMaster.so")
#define Libcrashsight ("libCrashKit.so")
uintptr_t TDataMaster;
#define SLEEP_TIME (1000LL / 60LL)
auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));

#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define pkgName "com.pubg.imobile"   
#include <stdio.h>
#include <dlfcn.h>
#define ARM64_SYSREG uint64_t
DWORD libanogsBase = 0;
DWORD libUE4Base = 0;
DWORD libanortBase = 0;
DWORD libEGLBase = 0;
DWORD libanogsAlloc = 0;
DWORD libUE4Alloc = 0;
DWORD libEGLAlloc = 0;
unsigned int libanogsSize = 0x33244D;
unsigned int libUE4Size = 0x79AFDF0;
char *Offset;
DWORD NewBase = 0;

void* sex = dlopen("libpubgm.so",RTLD_LAZY);

#define DefineHook(RET, NAME, ARGS) \
    RET(*orig_##NAME)               \
    ARGS;                           \
    RET hook_##NAME ARGS
	
DWORD roosterBase = 0;
DWORD libUE4Base = 0;
DWORD libanogsBase = 0;
DWORD chut = 0;
DWORD libanortBase = 0;
DWORD libanogsAlloc = 0;
DWORD libUE4Alloc = 0;

unsigned int libanogsSize = 0x527520;
unsigned int libUE4Size = 0xAABDA10;

char *Offset;
DWORD NewBase = 0;
void* hook_memcpy(char *dest, const char *src, size_t size)
{
    if ((DWORD)src >= libanogsBase && (DWORD)src <= (DWORD)(libanogsBase + libanogsSize))
    {
        Offset = (char *)(src - (char *)libanogsBase);
        NewBase = libanogsAlloc;
        src = &Offset[NewBase];
        return memcpy(dest, src, size);
    }
    if ((DWORD)src >= libUE4Base && (DWORD)src <= (DWORD)(libUE4Base + libUE4Size))
    {
        Offset = (char *)(src - (char *)libUE4Base);
        NewBase = libUE4Alloc;
        src = &Offset[NewBase];
        return memcpy(dest, src, size);
    }
    return memcpy(dest, src, size);
}


int (*oGKPxStudio)(const char *a1, unsigned int a2);
int hGKPxStudio(const char *a1, unsigned int a2)
{
    if ( strstr((const char *)a2,"opcode_crash") || /// crash fix 
       strstr((const char *)a2,"crash_various_opcode") || // crash fix 
       strstr((const char *)a2,"root") || // crash fix 
       strstr((const char *)a2,"anti_root") || // crash fix 
       strstr((const char *)a2,"zygisk") || 
       strstr((const char *)a2,"various_opcode") ||
       strstr((const char *)a2,"opcode_crash") ||
       strstr((const char *)a2,"opcode_scan") ||
       strstr((const char *)a2,"vm_vap_ext") || 
       strstr((const char *)a2,"blur_exit")) {
       LOGI("block : a1 -> %d | a2 -> %d", a1, a2);
       return 0;
       } else {
       LOGI("allow : a1 -> %d | a2 -> %d", a1, a2);

    return oGKPxStudio(a1,a2);
}
}

int __fastcall (*Criss31)(int a1, const char *a2);
int __fastcall MG3admin31o(int a1, const char *a2) {
if (strstr(a2, "egl") || 
strstr(a2, "ro.boot.") ||
strstr(a2, "orange.") ||
strstr(a2, "unlocked.") || 
strstr(a2, "SHA-256") || 
strstr(a2, "/dev/") || 
strstr(a2, "sys.oem_unlock_allowed") || 
strstr(a2, "setAttestationChallenge") || 
strstr(a2, "/sdcard/") || 
strstr(a2, "/sys/") || 
strstr(a2, "/data/")) {
return 0LL;
}
return Criss31(a1, a2);
}

int (*SoobTLRx)(int a1);
int SoobLTRx (int a1) {
while (true) {
sleep (100000);
if ( a1 ) {
continue;
}}}


int __fastcall MemoryRobust(int a1)
{
  if ( a1 )
  {
  return 0;
  }
return MemoryRobust(a1);
}

int (*sub_165564) (int a1, unsigned int a2, int a3);
int hooksub_165564(int a1, unsigned int a2, int a3)
{
    {
        return 0;
    }
    return sub_165564(a1, a2, a3);
}

void * antiban_thread(void *) {
do {
sleep(1);
} while (!isLibraryLoaded(Robust));
libanogsBase = findLibrary(OBFUSCATE("libanogs.so"));
libanogsAlloc = (DWORD)malloc(libanogsSize);
memcpy((void *)libanogsAlloc, (void *)libanogsBase, libanogsSize); 
PATCH_LIB("libanogs.so", "0x351B78", "00 20 70 47"); // 10 30 dk Fix
PATCH_LIB("libanogs.so", "0x361780", "00 20 70 47"); //  Lobby Crash Fix Cözücü
 PATCH_LIB("libanogs.so", "0x3B5F58", "00 20 70 47"); // calloc 1
PATCH_LIB("libanogs.so", "0x3B5F5C", "00 20 70 47"); // calloc 2 
PATCH_LIB("libanogs.so", "0x35E812", "00 20 70 47"); // ralloc 1
PATCH_LIB("libanogs.so", "0x9A070", "00 20 70 47"); // ralloc 2
PATCH_LIB("libanogs.so", "0xD5632", "00 20 70 47"); // ralloc 3
PATCH_LIB("libanogs.so", "0x8CBEC", "00 20 70 47"); // setuser info
PATCH_LIB("libanogs.so", "0xA6DB6", "00 20 70 47"); // 10 yıl fix
PATCH_LIB("libanogs.so", "0x9A69C", "00 20 70 47"); // 10 yıl fix 2
PATCH_LIB("libanogs.so", "0x1A6B50", "00 20 70 47"); // oyun crash fix ultra
PATCH_LIB("libanogs.so", "0x38E640", "00 20 70 47"); // Emulator Detection
PATCH_LIB("libanogs.so", "0x38FD68", "00 20 70 47"); // Fix 2 saat
PATCH_LIB("libanogs.so", "0x38FF30", "00 20 70 47"); //Fix Termination
PATCH_LIB("libanogs.so", "0x8BBF8", "00 20 70 47"); // Report Fix
PATCH_LIB("libanogs.so", "0x361780", "00 20 70 47"); //  Lobby Crash Fix Cözücü
 PATCH_LIB("libanogs.so", "0x3B5F58", "00 20 70 47"); // calloc 1
PATCH_LIB("libanogs.so", "0x3B5F5C", "00 20 70 47"); // calloc 2 
PATCH_LIB("libanogs.so", "0x35E812", "00 20 70 47"); // ralloc 1
PATCH_LIB("libanogs.so", "0x9A070", "00 20 70 47"); // ralloc 2
PATCH_LIB("libanogs.so", "0xD5632", "00 20 70 47"); // ralloc 3
PATCH_LIB("libanogs.so", "0x8CBEC", "00 20 70 47"); // setuser info
PATCH_LIB("libanogs.so", "0xA6DB6", "00 20 70 47"); // 10 yıl fix
PATCH_LIB("libanogs.so", "0x9A69C", "00 20 70 47"); // 10 yıl fix 2
PATCH_LIB("libanogs.so", "0x1A6B50", "00 20 70 47"); // oyun crash fix ultra
PATCH_LIB("libanogs.so", "0x38E640", "00 20 70 47"); // Emulator Detection
PATCH_LIB("libanogs.so", "0x38FD68", "00 20 70 47"); // Fix 2 saat
PATCH_LIB("libanogs.so", "0x38FF30", "00 20 70 47"); //Fix Termination
PATCH_LIB("libanogs.so", "0x35E32E", "00 20 70 47"); // Ban Fix Register
PATCH_LIB("libanogs.so", "0xFFFFF81F", "00 20 70 47"); // Karmasık Hex 1
PATCH_LIB("libanogs.so", "0x842AC", "00 20 70 47"); // Karmasık Hex 2
PATCH_LIB("libanogs.so", "0xD8C0C", "00 20 70 47"); // Karmasık Hex 3
PATCH_LIB("libanogs.so", "0xDA2A0", "00 20 70 47"); // Karmasık Hex 4
PATCH_LIB("libanogs.so", "0x3B3B50", "00 20 70 47"); // Karmasık Hex 5
PATCH_LIB("libanogs.so", "0xDE114", "00 20 70 47"); // Karmasık Hex 6
PATCH_LIB("libanogs.so", "0x3669C0", "00 20 70 47"); // Karmasık Hex 7
PATCH_LIB("libanogs.so", "0xD8D24", "00 20 70 47"); // Karmasık Hex 8
PATCH_LIB("libanogs.so", "0x11FF04", "00 20 70 47"); // Karmasık Hex 9
PATCH_LIB("libanogs.so", "0x11FFC0", "00 20 70 47"); // Karmasık Hex 10
PATCH_LIB("libanogs.so", "0x2AD188", "00 20 70 47"); // Karmasık Hex 11
PATCH_LIB("libanogs.so", "0x32FC36", "00 20 70 47"); // Karmasık Hex 12
PATCH_LIB("libanogs.so", "0x32FCA2", "00 20 70 47"); // Karmasık Hex 13
PATCH_LIB("libanogs.so", "0x32FCB2", "00 20 70 47"); // Karmasık Hex 14
PATCH_LIB("libanogs.so", "0x32FD02", "00 20 70 47"); // Karmasık Hex 15
PATCH_LIB("libanogs.so", "0x32FD42", "00 20 70 47"); // Karmasık Hex 16
PATCH_LIB("libanogs.so", "0x32FD5E", "00 20 70 47"); // Karmasık Hex 17
PATCH_LIB("libanogs.so", "0x32FD78", "00 20 70 47"); // Karmasık Hex 18
PATCH_LIB("libanogs.so", "0x25FF46", "00 20 70 47"); // Karmasık Hex 19
PATCH_LIB("libanogs.so", "0x25FF6E", "00 20 70 47"); // Karmasık Hex 20
PATCH_LIB("libanogs.so", "0x25FF9E", "00 20 70 47"); // Karmasık Hex 21
PATCH_LIB("libanogs.so", "0x25FFB6", "00 20 70 47"); // Karmasık Hex 22
PATCH_LIB("libanogs.so", "0x25FFE8", "00 20 70 47"); // Karmasık Hex 23
// HOOK BYPASS //


size_t hook_strlen(const char *s)
{
    if(strstr(s,"Your account has been flagged as high risk. It has been temporarily frozen for inspection. You can sign in to the game regularly after it passes inspection."))
    {
         const char *NewContent = "Your Account Has Been safe";
         size_t NewSize = strlen(NewContent) + 92;
         memcpy(const_cast<char *>(s), NewContent, NewSize);
    }
   // LOGI("string : %s",s);
    return strlen(s);
}

void *ue4_thread(void *) {
    while (!isLibraryLoaded(OBFUSCATE("libUE4.so")))
    {
        sleep(1);
    }
    libUE4Base = findLibrary(OBFUSCATE("libUE4.so"));
PATCH_LIB("libUE4.so","0x4DBBD40","0");
PATCH_LIB("libUE4.so","0x4DC6918","0");
PATCH_LIB("libUE4.so","0x4DC699C","0");
PATCH_LIB("libUE4.so","0x5127AF4","0");
PATCH_LIB("libUE4.so","0x98A2848","0");
PATCH_LIB("libUE4.so","0x6B681FC","0");
PATCH_LIB("libUE4.so","0x764B434","0");
PATCH_LIB("libUE4.so","0x5F43660","0");
PATCH_LIB("libUE4.so","0x5F43214","0");
PATCH_LIB("libUE4.so","0x5F42E34","0");
PATCH_LIB("libUE4.so","0x5E6CB08","0");
PATCH_LIB("libUE4.so","0x5CC9EFC","0");
PATCH_LIB("libUE4.so","0x510AE24","0");
PATCH_LIB("libUE4.so","0x510ABDC","0");
PATCH_LIB("libUE4.so","0x50FB350","0");
PATCH_LIB("libUE4.so","0x9801618","0");
PATCH_LIB("libUE4.so","0x9E19008","0");
PATCH_LIB("libUE4.so","0x59CA9BC","0");
PATCH_LIB("libUE4.so","0x58AB9D0","0");
PATCH_LIB("libUE4.so","0x54C2DA8","0");
PATCH_LIB("libUE4.so","0x54A6324","0");
PATCH_LIB("libUE4.so","0x692438C","0");
PATCH_LIB("libUE4.so","0x5129074","0");
PATCH_LIB("libUE4.so","0x679AA04","0");      
PATCH_LIB("libUE4.so","0x679AB24","0");      
PATCH_LIB("libUE4.so","0x679BE84","0");      
PATCH_LIB("libUE4.so","0x679C00C","0");      
PATCH_LIB("libUE4.so","0x679C85C","0");      
PATCH_LIB("libUE4.so","0x679CA34","0");      
PATCH_LIB("libUE4.so","0x67D8004","0");      
PATCH_LIB("libUE4.so","0x67D8828","0");      
PATCH_LIB("libUE4.so","0x67D9138","0");      
PATCH_LIB("libUE4.so","0x67D9EC8","0");      
PATCH_LIB("libUE4.so","0x67DCA00","0");      
PATCH_LIB("libUE4.so","0x67DCA74","0");      
PATCH_LIB("libUE4.so","0x67DCB7C","0");      
PATCH_LIB("libUE4.so","0x67DCC38","0");      
PATCH_LIB("libUE4.so","0x67DCCAC","0");      
PATCH_LIB("libUE4.so","0x67E1278","0");      
PATCH_LIB("libUE4.so","0x691912C","0");      
PATCH_LIB("libUE4.so","0x6919240","0");      
PATCH_LIB("libUE4.so","0x6919404","0");      
PATCH_LIB("libUE4.so","0x69197D8","0");      
PATCH_LIB("libUE4.so","0x6919A18","0");      
PATCH_LIB("libUE4.so","0x6919A88","0");      
PATCH_LIB("libUE4.so","0x6919C88","0");      
PATCH_LIB("libUE4.so","0x6919E20","0");      
PATCH_LIB("libUE4.so","0x6919F78","0");      
PATCH_LIB("libUE4.so","0x691A1FC","0");      
PATCH_LIB("libUE4.so","0x691A280","0");      
PATCH_LIB("libUE4.so","0x691A480","0");      
PATCH_LIB("libUE4.so","0x691A618","0");      
PATCH_LIB("libUE4.so","0x691A770","0");      
PATCH_LIB("libUE4.so","0x691AD80","0");      
PATCH_LIB("libUE4.so","0x691B448","0");      
PATCH_LIB("libUE4.so","0x691B4EC","0");      
PATCH_LIB("libUE4.so","0x691B740","0");      
PATCH_LIB("libUE4.so","0x691B8DC","0");      
PATCH_LIB("libUE4.so","0x691BA34","0");      
PATCH_LIB("libUE4.so","0x691BCBC","0");      
PATCH_LIB("libUE4.so","0x691BE9C","0");      
PATCH_LIB("libUE4.so","0x691BF24","0");      
PATCH_LIB("libUE4.so","0x691C018","0");      
PATCH_LIB("libUE4.so","0x691C210","0");      
PATCH_LIB("libUE4.so","0x691C3A8","0");      
PATCH_LIB("libUE4.so","0x691C500","0");      
PATCH_LIB("libUE4.so","0x6B873A0","0");      
PATCH_LIB("libUE4.so","0x6B8742C","0");      
PATCH_LIB("libUE4.so","0x6B874B8","0");      
PATCH_LIB("libUE4.so","0x6B875A4","0");      
PATCH_LIB("libUE4.so","0x6B87628","0");      
PATCH_LIB("libUE4.so","0x6B87720","0");      
PATCH_LIB("libUE4.so","0x6B877A4","0");      
PATCH_LIB("libUE4.so","0x6B87830","0");      
PATCH_LIB("libUE4.so","0x6B87930","0");      
PATCH_LIB("libUE4.so","0x6B87984","0");      
PATCH_LIB("libUE4.so","0x6B879D8","0");      
PATCH_LIB("libUE4.so","0x6B87B24","0");      
PATCH_LIB("libUE4.so","0x6B87B78","0");      
PATCH_LIB("libUE4.so","0x6B87EA0","0");      
PATCH_LIB("libUE4.so","0x6B880F4","0");      
PATCH_LIB("libUE4.so","0x6B8819C","0");      
PATCH_LIB("libUE4.so","0x6B88358","0");      
PATCH_LIB("libUE4.so","0x6B885AC","0");      
PATCH_LIB("libUE4.so","0x6B88810","0");      
PATCH_LIB("libUE4.so","0x6B888B8","0");      
PATCH_LIB("libUE4.so","0x6B88968","0");      
PATCH_LIB("libUE4.so","0x6B889BC","0");      
PATCH_LIB("libUE4.so","0x6B88A3C","0");      
PATCH_LIB("libUE4.so","0x6B88AE0","0");      
PATCH_LIB("libUE4.so","0x6B88B34","0");      
PATCH_LIB("libUE4.so","0x6B88BA8","0");      
PATCH_LIB("libUE4.so","0x6C9CD2C","0");      
PATCH_LIB("libUE4.so","0x6C9CE88","0");      
PATCH_LIB("libUE4.so","0x6CA1044","0");      
PATCH_LIB("libUE4.so","0x6CA11F0","0");      
PATCH_LIB("libUE4.so","0x6CA139C","0");      
PATCH_LIB("libUE4.so","0x6CA1548","0");      
PATCH_LIB("libUE4.so","0x6CA16F4","0");      
PATCH_LIB("libUE4.so","0x6CA212C","0");      
PATCH_LIB("libUE4.so","0x6CA21D8","0");      
PATCH_LIB("libUE4.so","0x6CA2408","0");
PATCH_LIB("libUE4.so","0x6CA2690","0");      
PATCH_LIB("libUE4.so","0x6CA28C0","0");      
PATCH_LIB("libUE4.so","0x6CA2A68","0");      
PATCH_LIB("libUE4.so","0x6CA2BC0","0");      
PATCH_LIB("libUE4.so","0x6CA2E4C","0");      
PATCH_LIB("libUE4.so","0x71ABA70","0");      
PATCH_LIB("libUE4.so","0x71ABC18","0");      
PATCH_LIB("libUE4.so","0x71ABD70","0");      
PATCH_LIB("libUE4.so","0x71AC008","0");      
PATCH_LIB("libUE4.so","0x71AC160","0");      
PATCH_LIB("libUE4.so","0x71B2760","0");      
PATCH_LIB("libUE4.so","0x71B3D08","0");      
PATCH_LIB("libUE4.so","0x71B3EB0","0");      
PATCH_LIB("libUE4.so","0x71B4008","0");      
PATCH_LIB("libUE4.so","0x71B42B8","0");      
PATCH_LIB("libUE4.so","0x71B450C","0");      
PATCH_LIB("libUE4.so","0x71B46B4","0");      
PATCH_LIB("libUE4.so","0x71B480C","0");      
PATCH_LIB("libUE4.so","0x71B4D0C","0");      
PATCH_LIB("libUE4.so","0x71B4EA8","0");      
PATCH_LIB("libUE4.so","0x71B5000","0");      
PATCH_LIB("libUE4.so","0x71B53E4","0");      
PATCH_LIB("libUE4.so","0x71B669C","0");      
PATCH_LIB("libUE4.so","0x71B88EC","0");      
PATCH_LIB("libUE4.so","0x7391BF8","0");      
PATCH_LIB("libUE4.so","0x7391F14","0");      
PATCH_LIB("libUE4.so","0x73920AC","0");      
PATCH_LIB("libUE4.so","0x7392204","0");      
PATCH_LIB("libUE4.so","0x73925A4","0");      
PATCH_LIB("libUE4.so","0x739264C","0");      
PATCH_LIB("libUE4.so","0x73926D4","0");      
PATCH_LIB("libUE4.so","0x7392890","0");      
PATCH_LIB("libUE4.so","0x7392AA8","0");      
PATCH_LIB("libUE4.so","0x7392C50","0");      
PATCH_LIB("libUE4.so","0x7392DA8","0");      
PATCH_LIB("libUE4.so","0x7393270","0");      
PATCH_LIB("libUE4.so","0x7393A84","0");      
PATCH_LIB("libUE4.so","0x7393C90","0");      
PATCH_LIB("libUE4.so","0x7393E28","0");      
PATCH_LIB("libUE4.so","0x7393F80","0");      
PATCH_LIB("libUE4.so","0x73942CC","0");      
PATCH_LIB("libUE4.so","0x73944FC","0");      
PATCH_LIB("libUE4.so","0x739472C","0");      
PATCH_LIB("libUE4.so","0x739495C","0");      
PATCH_LIB("libUE4.so","0x7394B8C","0");      
PATCH_LIB("libUE4.so","0x7394D00","0");      
PATCH_LIB("libUE4.so","0x7394F14","0");      
PATCH_LIB("libUE4.so","0x73950BC","0");      
PATCH_LIB("libUE4.so","0x7395214","0");      
PATCH_LIB("libUE4.so","0x73954A0","0");      
PATCH_LIB("libUE4.so","0x73956F0","0");      
PATCH_LIB("libUE4.so","0x7395898","0");      
PATCH_LIB("libUE4.so","0x73959F0","0");      
PATCH_LIB("libUE4.so","0x7395DBC","0");      
PATCH_LIB("libUE4.so","0x739624C","0");      
PATCH_LIB("libUE4.so","0x739646C","0");      
PATCH_LIB("libUE4.so","0x7396614","0");      
PATCH_LIB("libUE4.so","0x739676C","0");      
PATCH_LIB("libUE4.so","0x73969FC","0");      
PATCH_LIB("libUE4.so","0x7396CF8","0");      
PATCH_LIB("libUE4.so","0x7396E00","0");      
PATCH_LIB("libUE4.so","0x7396E74","0");      
PATCH_LIB("libUE4.so","0x7397038","0");      
PATCH_LIB("libUE4.so","0x7397460","0");      
PATCH_LIB("libUE4.so","0x739766C","0");      
PATCH_LIB("libUE4.so","0x7397804","0");      
PATCH_LIB("libUE4.so","0x739795C","0");      
PATCH_LIB("libUE4.so","0x7397BEC","0");      
PATCH_LIB("libUE4.so","0x7397C94","0");      
PATCH_LIB("libUE4.so","0x7399948","0");      
PATCH_LIB("libUE4.so","0x7399C84","0");      
PATCH_LIB("libUE4.so","0x7399E48","0");      
PATCH_LIB("libUE4.so","0x7399E78","0");      
PATCH_LIB("libUE4.so","0x7399F38","0");      
PATCH_LIB("libUE4.so","0x7399FA0","0");      
PATCH_LIB("libUE4.so","0x7399FA8","0");      
PATCH_LIB("libUE4.so","0x758A458","0");      
PATCH_LIB("libUE4.so","0x758A7A0","0");      
PATCH_LIB("libUE4.so","0x758AAD4","0");      
PATCH_LIB("libUE4.so","0x758AE08","0");      
PATCH_LIB("libUE4.so","0x75938D0","0");      
PATCH_LIB("libUE4.so","0x759665C","0");      
PATCH_LIB("libUE4.so","0x7598710","0");      
PATCH_LIB("libUE4.so","0x7653F38","0");      
PATCH_LIB("libUE4.so","0x76544E8","0");      
PATCH_LIB("libUE4.so","0x7654614","0");      
PATCH_LIB("libUE4.so","0x7654DD4","0");      
PATCH_LIB("libUE4.so","0x7654FB4","0");      
PATCH_LIB("libUE4.so","0x781B8F8","0");      
PATCH_LIB("libUE4.so","0x781B9E8","0");      
PATCH_LIB("libUE4.so","0x781BAD8","0");      
PATCH_LIB("libUE4.so","0x781BAF8","0");      
PATCH_LIB("libUE4.so","0x781BB18","0");      
PATCH_LIB("libUE4.so","0x781BB38","0");      
PATCH_LIB("libUE4.so","0x781BB58","0");      
PATCH_LIB("libUE4.so","0x781BC60","0");      
PATCH_LIB("libUE4.so","0x781BC80","0");      
PATCH_LIB("libUE4.so","0x781BD88","0");      
PATCH_LIB("libUE4.so","0x781BDA4","0");      
PATCH_LIB("libUE4.so","0x781BDE8","0");      
PATCH_LIB("libUE4.so","0x781C008","0");      
PATCH_LIB("libUE4.so","0x781C0D4","0");      
PATCH_LIB("libUE4.so","0x78ABED0","0");      
PATCH_LIB("libUE4.so","0x78AC4B8","0");      
PATCH_LIB("libUE4.so","0x78AC4E0","0");      
PATCH_LIB("libUE4.so","0x78AC4FC","0");      
PATCH_LIB("libUE4.so","0x78AC5B4","0");      
PATCH_LIB("libUE4.so","0x78AC664","0");      
PATCH_LIB("libUE4.so","0x78AC800","0");      
PATCH_LIB("libUE4.so","0x78AC9E0","0");      
PATCH_LIB("libUE4.so","0x78B1A64","0");      
PATCH_LIB("libUE4.so","0x78B36B8","0");      
PATCH_LIB("libUE4.so","0x78B3874","0");      
PATCH_LIB("libUE4.so","0x78B38B8","0");      
PATCH_LIB("libUE4.so","0x78B393C","0");      
PATCH_LIB("libUE4.so","0x78B3A0C","0");      
PATCH_LIB("libUE4.so","0x78B3B5C","0");      
PATCH_LIB("libUE4.so","0x78B3B64","0");      
PATCH_LIB("libUE4.so","0x78B3BCC","0");      
PATCH_LIB("libUE4.so","0x78B3DA0","0");      
PATCH_LIB("libUE4.so","0x78B4004","0");      
PATCH_LIB("libUE4.so","0x78B4030","0");      
PATCH_LIB("libUE4.so","0x78B4284","0");      
PATCH_LIB("libUE4.so","0x78B45F4","0");      
PATCH_LIB("libUE4.so","0x78B4C2C","0");      
PATCH_LIB("libUE4.so","0x78B4F80","0");      
PATCH_LIB("libUE4.so","0x78B5150","0");      
PATCH_LIB("libUE4.so","0x78B52C0","0");      
PATCH_LIB("libUE4.so","0x78B52CC","0");      
PATCH_LIB("libUE4.so","0x78B53CC","0");      
PATCH_LIB("libUE4.so","0x78B53E8","0");      
PATCH_LIB("libUE4.so","0x78B5410","0");      
PATCH_LIB("libUE4.so","0x7B56750","0");      
PATCH_LIB("libUE4.so","0x7B567F8","0");      
PATCH_LIB("libUE4.so","0x7B56A04","0");      
PATCH_LIB("libUE4.so","0x7B56B9C","0");      
PATCH_LIB("libUE4.so","0x7B56CF4","0");      
PATCH_LIB("libUE4.so","0x7B61310","0");      
PATCH_LIB("libUE4.so","0x7B61488","0");      
PATCH_LIB("libUE4.so","0x7B61674","0");      
PATCH_LIB("libUE4.so","0x7B61BD0","0");      
PATCH_LIB("libUE4.so","0x7B61D28","0");      
PATCH_LIB("libUE4.so","0x7B61FD8","0");      
PATCH_LIB("libUE4.so","0x7B62250","0");      
PATCH_LIB("libUE4.so","0x7B6253C","0");      
PATCH_LIB("libUE4.so","0x7B63A70","0");      
PATCH_LIB("libUE4.so","0x7B63BE8","0");      
PATCH_LIB("libUE4.so","0x7B63D60","0");      
PATCH_LIB("libUE4.so","0x7B64ED8","0");      
PATCH_LIB("libUE4.so","0x7B65018","0");      
PATCH_LIB("libUE4.so","0x7B65258","0");      
PATCH_LIB("libUE4.so","0x7B65A64","0");      
PATCH_LIB("libUE4.so","0x7B65EF0","0");      
PATCH_LIB("libUE4.so","0x7B66560","0");      
PATCH_LIB("libUE4.so","0x7B669C0","0");      
PATCH_LIB("libUE4.so","0x7B66AF8","0");      
PATCH_LIB("libUE4.so","0x7B66BC0","0");      
PATCH_LIB("libUE4.so","0x7B67818","0");      
PATCH_LIB("libUE4.so","0x7B69B58","0");      
PATCH_LIB("libUE4.so","0x7B69C3C","0");      
PATCH_LIB("libUE4.so","0x7B69D14","0");      
PATCH_LIB("libUE4.so","0x7B69DEC","0");      
PATCH_LIB("libUE4.so","0x7B69EC4","0");      
PATCH_LIB("libUE4.so","0x7F442EC","0");      
PATCH_LIB("libUE4.so","0x7F44418","0");      
PATCH_LIB("libUE4.so","0x7F4891C","0");      
PATCH_LIB("libUE4.so","0x7F48BE0","0");      
PATCH_LIB("libUE4.so","0x7F48EA4","0");      
PATCH_LIB("libUE4.so","0x7F49168","0");      
PATCH_LIB("libUE4.so","0x7F4942C","0");      
PATCH_LIB("libUE4.so","0x7F496F0","0");      
PATCH_LIB("libUE4.so","0x7F499B4","0");      
PATCH_LIB("libUE4.so","0x7F49C78","0");      
PATCH_LIB("libUE4.so","0x7F49F3C","0");      
PATCH_LIB("libUE4.so","0x7F4A200","0");      
PATCH_LIB("libUE4.so","0x7F4A4C4","0");      
PATCH_LIB("libUE4.so","0x7F4A788","0");      
PATCH_LIB("libUE4.so","0x7F4AA4C","0");      
PATCH_LIB("libUE4.so","0x7F4AFD4","0");      
PATCH_LIB("libUE4.so","0x7F4B298","0");      
PATCH_LIB("libUE4.so","0x7F4B55C","0");      
PATCH_LIB("libUE4.so","0x7F4B820","0");      
PATCH_LIB("libUE4.so","0x7F4BAE4","0");      
PATCH_LIB("libUE4.so","0x7F4BDA8","0");      
PATCH_LIB("libUE4.so","0x7F4C06C","0");      
PATCH_LIB("libUE4.so","0x7F4C330","0");      
PATCH_LIB("libUE4.so","0x7F4C5F4","0");      
PATCH_LIB("libUE4.so","0x7F4C8B8","0");      
PATCH_LIB("libUE4.so","0x7F52D50","0");      
PATCH_LIB("libUE4.so","0x7F55474","0");      
PATCH_LIB("libUE4.so","0x7F55710","0");      
PATCH_LIB("libUE4.so","0x7F559AC","0");      
PATCH_LIB("libUE4.so","0x7F55C48","0");      
PATCH_LIB("libUE4.so","0x7F55EE4","0");      
PATCH_LIB("libUE4.so","0x7F56180","0");      
PATCH_LIB("libUE4.so","0x7F5641C","0");      
PATCH_LIB("libUE4.so","0x7F566B8","0");      
PATCH_LIB("libUE4.so","0x7F56954","0");      
PATCH_LIB("libUE4.so","0x7F56BF0","0");      
PATCH_LIB("libUE4.so","0x7F57C28","0");      
PATCH_LIB("libUE4.so","0x7F58638","0");      
PATCH_LIB("libUE4.so","0x82619D4","0");      
PATCH_LIB("libUE4.so","0x8262650","0");      
PATCH_LIB("libUE4.so","0x8262BC4","0");      
PATCH_LIB("libUE4.so","0x8262D64","0");      
PATCH_LIB("libUE4.so","0x8263214","0");      
PATCH_LIB("libUE4.so","0x826345C","0");      
PATCH_LIB("libUE4.so","0x8263CF4","0");      
PATCH_LIB("libUE4.so","0x82640E0","0");      
PATCH_LIB("libUE4.so","0x82644BC","0");      
PATCH_LIB("libUE4.so","0x82646D0","0");      
PATCH_LIB("libUE4.so","0x8264840","0");      
PATCH_LIB("libUE4.so","0x8264984","0");      
PATCH_LIB("libUE4.so","0x8267BC8","0");      
PATCH_LIB("libUE4.so","0x8267D20","0");     
PATCH_LIB("libUE4.so","0x8267FB8","0");      
PATCH_LIB("libUE4.so","0x8268070","0");      
PATCH_LIB("libUE4.so","0x8268114","0");      
PATCH_LIB("libUE4.so","0x8268290","0");      
PATCH_LIB("libUE4.so","0x8268318","0");      
PATCH_LIB("libUE4.so","0x82683FC","0");      
PATCH_LIB("libUE4.so","0x8269264","0");      
PATCH_LIB("libUE4.so","0x8269810","0");      
PATCH_LIB("libUE4.so","0x8269A24","0");      
PATCH_LIB("libUE4.so","0x8269AAC","0");      
PATCH_LIB("libUE4.so","0x8269B28","0");      
PATCH_LIB("libUE4.so","0x8269FAC","0");      
PATCH_LIB("libUE4.so","0x826A600","0");      
PATCH_LIB("libUE4.so","0x826A79C","0");      
PATCH_LIB("libUE4.so","0x826B140","0");      
PATCH_LIB("libUE4.so","0x826B23C","0");      
PATCH_LIB("libUE4.so","0x826CDE8","0");      
PATCH_LIB("libUE4.so","0x8271060","0");      
PATCH_LIB("libUE4.so","0x827116C","0");      
PATCH_LIB("libUE4.so","0x8465224","0");      
PATCH_LIB("libUE4.so","0x8465384","0");      
PATCH_LIB("libUE4.so","0x8465A50","0");      
PATCH_LIB("libUE4.so","0x8468018","0");      
PATCH_LIB("libUE4.so","0x8468C74","0");      
PATCH_LIB("libUE4.so","0x8468DB0","0");      
PATCH_LIB("libUE4.so","0x846CD28","0");      
PATCH_LIB("libUE4.so","0x84755F0","0");      
PATCH_LIB("libUE4.so","0x84757DC","0");      
PATCH_LIB("libUE4.so","0x847602C","0");      
PATCH_LIB("libUE4.so","0x84762C8","0");      
PATCH_LIB("libUE4.so","0x8477678","0");      
PATCH_LIB("libUE4.so","0x8477D64","0");      
PATCH_LIB("libUE4.so","0x84796A8","0");      
PATCH_LIB("libUE4.so","0x847AAF4","0");      
PATCH_LIB("libUE4.so","0x847AB5C","0");      
PATCH_LIB("libUE4.so","0x847ABE4","0");      
PATCH_LIB("libUE4.so","0x847B494","0");      
PATCH_LIB("libUE4.so","0x847B594","0");      
PATCH_LIB("libUE4.so","0x847BAA4","0");      
PATCH_LIB("libUE4.so","0x847BB18","0");      
PATCH_LIB("libUE4.so","0x847BDF4","0");      
PATCH_LIB("libUE4.so","0x847BFBC","0");      
PATCH_LIB("libUE4.so","0x8483010","0");      
PATCH_LIB("libUE4.so","0x8483804","0");      
PATCH_LIB("libUE4.so","0x8483F68","0");      
PATCH_LIB("libUE4.so","0x8485258","0");      
PATCH_LIB("libUE4.so","0x8485460","0");      
PATCH_LIB("libUE4.so","0x84854E8","0");      
PATCH_LIB("libUE4.so","0x86BB2B0","0");      
PATCH_LIB("libUE4.so","0x86BB4AC","0");      
PATCH_LIB("libUE4.so","0x86C1004","0");      
PATCH_LIB("libUE4.so","0x86C1298","0");      
PATCH_LIB("libUE4.so","0x86C14C4","0");      
PATCH_LIB("libUE4.so","0x86C154C","0");      
PATCH_LIB("libUE4.so","0x86C16A4","0");      
PATCH_LIB("libUE4.so","0x86C1934","0");      
PATCH_LIB("libUE4.so","0x86C19BC","0");      
PATCH_LIB("libUE4.so","0x86C1EA8","0");      
PATCH_LIB("libUE4.so","0x86C2050","0");      
PATCH_LIB("libUE4.so","0x86C2290","0");      
PATCH_LIB("libUE4.so","0x86C2318","0");      
PATCH_LIB("libUE4.so","0x86C238C","0");      
PATCH_LIB("libUE4.so","0x86C2930","0");      
PATCH_LIB("libUE4.so","0x86C2A38","0");      
PATCH_LIB("libUE4.so","0x86C2C70","0");      
PATCH_LIB("libUE4.so","0x86C2D68","0");      
PATCH_LIB("libUE4.so","0x86C2DE4","0");      
PATCH_LIB("libUE4.so","0x86C33EC","0");      
PATCH_LIB("libUE4.so","0x86C3B60","0");      
PATCH_LIB("libUE4.so","0x86C3C78","0");      
PATCH_LIB("libUE4.so","0x86C3ECC","0");      
PATCH_LIB("libUE4.so","0x86C4560","0");      
PATCH_LIB("libUE4.so","0x86C47B4","0");      
PATCH_LIB("libUE4.so","0x86C4930","0");      
PATCH_LIB("libUE4.so","0x86C4A00","0");      
PATCH_LIB("libUE4.so","0x8892FE4","0");      
PATCH_LIB("libUE4.so","0x889304C","0");      
PATCH_LIB("libUE4.so","0x8893630","0");      
PATCH_LIB("libUE4.so","0x8893B70","0");      
PATCH_LIB("libUE4.so","0x8894240","0");      
PATCH_LIB("libUE4.so","0x88944C0","0");      
PATCH_LIB("libUE4.so","0x88944C8","0");      
PATCH_LIB("libUE4.so","0x88945FC","0");      
PATCH_LIB("libUE4.so","0x8894928","0");      
PATCH_LIB("libUE4.so","0x8894E90","0");      
PATCH_LIB("libUE4.so","0x8894FB8","0");      
PATCH_LIB("libUE4.so","0x8895104","0");      
PATCH_LIB("libUE4.so","0x88953A8","0");      
PATCH_LIB("libUE4.so","0x88954F0","0");      
PATCH_LIB("libUE4.so","0x8895524","0");      
PATCH_LIB("libUE4.so","0x8895548","0");      
PATCH_LIB("libUE4.so","0x89C9368","0");      
PATCH_LIB("libUE4.so","0x89C940C","0");      
PATCH_LIB("libUE4.so","0x89C9628","0");      
PATCH_LIB("libUE4.so","0x89C97D0","0");      
PATCH_LIB("libUE4.so","0x89C9928","0");      
PATCH_LIB("libUE4.so","0x89C9BB8","0");      
PATCH_LIB("libUE4.so","0x89C9D10","0");      
PATCH_LIB("libUE4.so","0x89C9F94","0");      
PATCH_LIB("libUE4.so","0x89CB604","0");      
PATCH_LIB("libUE4.so","0x89CB68C","0");      
PATCH_LIB("libUE4.so","0x89CB6C8","0");      
PATCH_LIB("libUE4.so","0x89CB6F4","0");      
PATCH_LIB("libUE4.so","0x89CB708","0");      
PATCH_LIB("libUE4.so","0x89CB748","0");      
PATCH_LIB("libUE4.so","0x89CB788","0");      
PATCH_LIB("libUE4.so","0x89CB7B8","0");      
PATCH_LIB("libUE4.so","0x89CB7D8","0");      
PATCH_LIB("libUE4.so","0x89CBB3C","0");      
PATCH_LIB("libUE4.so","0x89CBB54","0");      
PATCH_LIB("libUE4.so","0x8AAA644","0");      
PATCH_LIB("libUE4.so","0x8AAA6F0","0");      
PATCH_LIB("libUE4.so","0x8AAA924","0");      
PATCH_LIB("libUE4.so","0x8AAAAC0","0");      
PATCH_LIB("libUE4.so","0x8AAACFC","0");      
PATCH_LIB("libUE4.so","0x8AAAE94","0");      
PATCH_LIB("libUE4.so","0x8AAAFEC","0");      
PATCH_LIB("libUE4.so","0x8AAB274","0");      
PATCH_LIB("libUE4.so","0x8AAB2E8","0");      
PATCH_LIB("libUE4.so","0x8AAB370","0");      
PATCH_LIB("libUE4.so","0x8DDA884","0");      
PATCH_LIB("libUE4.so","0x8DDA92C","0");      
PATCH_LIB("libUE4.so","0x8DDAB58","0");      
PATCH_LIB("libUE4.so","0x8DDAD00","0");      
PATCH_LIB("libUE4.so","0x8DDAE58","0");      
PATCH_LIB("libUE4.so","0x8DDBF88","0");      
PATCH_LIB("libUE4.so","0x8DDC080","0");      
PATCH_LIB("libUE4.so","0x8DDC2D4","0");      
PATCH_LIB("libUE4.so","0x8DDC5D4","0");      
PATCH_LIB("libUE4.so","0x8DDC86C","0");      
PATCH_LIB("libUE4.so","0x8DDC914","0");      
PATCH_LIB("libUE4.so","0x8DDCB20","0");      
PATCH_LIB("libUE4.so","0x8DDCCB8","0");      
PATCH_LIB("libUE4.so","0x8DE1448","0");      
PATCH_LIB("libUE4.so","0x8DE1E2C","0");      
PATCH_LIB("libUE4.so","0x908A484","0");      
PATCH_LIB("libUE4.so","0x908A8B8","0");      
PATCH_LIB("libUE4.so","0x908B70C","0");      
PATCH_LIB("libUE4.so","0x908B844","0");      
PATCH_LIB("libUE4.so","0x908B968","0");      
PATCH_LIB("libUE4.so","0x908BA24","0");      
PATCH_LIB("libUE4.so","0x908BAE0","0");      
PATCH_LIB("libUE4.so","0x908BBA0","0");      
PATCH_LIB("libUE4.so","0x908CA54","0");      
PATCH_LIB("libUE4.so","0x908CBBC","0");      
PATCH_LIB("libUE4.so","0x936C194","0");      
PATCH_LIB("libUE4.so","0x936C87C","0");      
PATCH_LIB("libUE4.so","0x936C9E8","0");      
PATCH_LIB("libUE4.so","0x936CAC0","0");      
PATCH_LIB("libUE4.so","0x9371054","0");      
PATCH_LIB("libUE4.so","0x93713C8","0");      
PATCH_LIB("libUE4.so","0x9371574","0");      
PATCH_LIB("libUE4.so","0x937184C","0");      
PATCH_LIB("libUE4.so","0x9371AE0","0");      
PATCH_LIB("libUE4.so","0x9371D7C","0");      
PATCH_LIB("libUE4.so","0x93720FC","0");      
PATCH_LIB("libUE4.so","0x93723D4","0");      
PATCH_LIB("libUE4.so","0x9372530","0");      
PATCH_LIB("libUE4.so","0x958B25C","0");      
PATCH_LIB("libUE4.so","0x958B694","0");      
PATCH_LIB("libUE4.so","0x958B8CC","0");      
PATCH_LIB("libUE4.so","0x958BB04","0");      
PATCH_LIB("libUE4.so","0x958BEE4","0");      
PATCH_LIB("libUE4.so","0x958C11C","0");      
PATCH_LIB("libUE4.so","0x958C480","0");      
PATCH_LIB("libUE4.so","0x958C6B8","0");      
PATCH_LIB("libUE4.so","0x958C8F0","0");      
PATCH_LIB("libUE4.so","0x958CB28","0");      
PATCH_LIB("libUE4.so","0x958CD60","0");      
PATCH_LIB("libUE4.so","0x9713AB0","0");      
PATCH_LIB("libUE4.so","0x9713CF4","0");      
PATCH_LIB("libUE4.so","0x9713D94","0");      
PATCH_LIB("libUE4.so","0x9713E34","0");      
PATCH_LIB("libUE4.so","0x9713F90","0");      
PATCH_LIB("libUE4.so","0x97140A8","0");      
PATCH_LIB("libUE4.so","0x9714198","0");      
PATCH_LIB("libUE4.so","0x971474C","0");      
PATCH_LIB("libUE4.so","0x9714774","0");      
PATCH_LIB("libUE4.so","0x9714BEC","0");      
PATCH_LIB("libUE4.so","0x9714E84","0");      
PATCH_LIB("libUE4.so","0x9715480","0");      
PATCH_LIB("libUE4.so","0x9715554","0");      
PATCH_LIB("libUE4.so","0x9715630","0");      
PATCH_LIB("libUE4.so","0x971564C","0");      
PATCH_LIB("libUE4.so","0x9715F88","0");      
PATCH_LIB("libUE4.so","0x97168C4","0");      
PATCH_LIB("libUE4.so","0x9716918","0");      
PATCH_LIB("libUE4.so","0x97EB954","0");      
PATCH_LIB("libUE4.so","0x97EB9C0","0");      
PATCH_LIB("libUE4.so","0x97EB9F0","0");      
PATCH_LIB("libUE4.so","0x97EBA74","0");      
PATCH_LIB("libUE4.so","0x97EBAC0","0");      
PATCH_LIB("libUE4.so","0x97EBB04","0");      
PATCH_LIB("libUE4.so","0x97EBCA4","0");      
PATCH_LIB("libUE4.so","0x97EBCB0","0");      
PATCH_LIB("libUE4.so","0x97EBCBC","0");      
PATCH_LIB("libUE4.so","0x97EBDF8","0");      
PATCH_LIB("libUE4.so","0x97EBE04","0");      
PATCH_LIB("libUE4.so","0x97EBE24","0");      
PATCH_LIB("libUE4.so","0x97EBE3C","0");      
PATCH_LIB("libUE4.so","0x97EBE48","0");      
PATCH_LIB("libUE4.so","0x97EBE54","0");      
PATCH_LIB("libUE4.so","0x97EBEE8","0");      
PATCH_LIB("libUE4.so","0x97EBF20","0");      
PATCH_LIB("libUE4.so","0x97EBF38","0");      
PATCH_LIB("libUE4.so","0x97EBF50","0");      
PATCH_LIB("libUE4.so","0x97EBF64","0");      
PATCH_LIB("libUE4.so","0x97EBF78","0");      
PATCH_LIB("libUE4.so","0x97EC4F0","0");      
PATCH_LIB("libUE4.so","0x97EC6DC","0");      
PATCH_LIB("libUE4.so","0x97ECB08","0");      
PATCH_LIB("libUE4.so","0x97ECCC0","0");      
PATCH_LIB("libUE4.so","0x97ECD6C","0");      
PATCH_LIB("libUE4.so","0x97F100C","0");      
PATCH_LIB("libUE4.so","0x9AA7B30","0");      
PATCH_LIB("libUE4.so","0x9AA7C38","0");      
PATCH_LIB("libUE4.so","0x9AA7CE0","0");      
PATCH_LIB("libUE4.so","0x9AA8390","0");      
PATCH_LIB("libUE4.so","0x9AA8474","0");      
PATCH_LIB("libUE4.so","0x9AA8760","0");      
PATCH_LIB("libUE4.so","0x9AA8A4C","0");      
PATCH_LIB("libUE4.so","0x9AA8B78","0");      
PATCH_LIB("libUE4.so","0x9AA8C5C","0");      
PATCH_LIB("libUE4.so","0x9AA92A0","0");      
PATCH_LIB("libUE4.so","0x9AA9368","0");      
PATCH_LIB("libUE4.so","0x9AA942C","0");      
PATCH_LIB("libUE4.so","0x9AA99F0","0");      
PATCH_LIB("libUE4.so","0x9AA9EC0","0");      
PATCH_LIB("libUE4.so","0x9AA9F34","0");      
PATCH_LIB("libUE4.so","0x9AAA780","0");      
PATCH_LIB("libUE4.so","0x9AAA8F4","0");      
PATCH_LIB("libUE4.so","0x9AAA98C","0");      
PATCH_LIB("libUE4.so","0x9AAAB00","0");      
PATCH_LIB("libUE4.so","0x9AAAB98","0");      
PATCH_LIB("libUE4.so","0x9AAAD94","0");      
PATCH_LIB("libUE4.so","0x9AAAFA0","0");      
PATCH_LIB("libUE4.so","0x9AAB1A8","0");      
PATCH_LIB("libUE4.so","0x9AAB374","0");      
PATCH_LIB("libUE4.so","0x9AAB4C8","0");      
PATCH_LIB("libUE4.so","0x9AABC04","0");      
PATCH_LIB("libUE4.so","0x9AABDE0","0");      
PATCH_LIB("libUE4.so","0x9AABEE8","0");      
PATCH_LIB("libUE4.so","0x9AABF90","0");      
PATCH_LIB("libUE4.so","0x9AAC098","0");      
PATCH_LIB("libUE4.so","0x9AAC140","0");      
PATCH_LIB("libUE4.so","0x9AAC248","0");      
PATCH_LIB("libUE4.so","0x9AAC2F0","0");      
PATCH_LIB("libUE4.so","0x9AAC3D4","0");      
PATCH_LIB("libUE4.so","0x9AACD08","0");      
PATCH_LIB("libUE4.so","0x9F44244","0");      
PATCH_LIB("libUE4.so","0x9F443E4","0");      
PATCH_LIB("libUE4.so","0x9F44484","0");      
PATCH_LIB("libUE4.so","0x9F49210","0");      
PATCH_LIB("libUE4.so","0x9F49368","0");      
PATCH_LIB("libUE4.so","0x9F495F8","0");      
PATCH_LIB("libUE4.so","0x9F49804","0");      
PATCH_LIB("libUE4.so","0x9F49BFC","0");      
PATCH_LIB("libUE4.so","0x9F49E28","0");      
PATCH_LIB("libUE4.so","0x9F4A0E8","0");      
PATCH_LIB("libUE4.so","0x9F4A320","0");      
PATCH_LIB("libUE4.so","0x9F4A394","0");      
PATCH_LIB("libUE4.so","0x9F4A5A8","0");      
PATCH_LIB("libUE4.so","0x9F4A700","0");      
PATCH_LIB("libUE4.so","0x9F4A98C","0");      
PATCH_LIB("libUE4.so","0x9F4AC24","0");      
PATCH_LIB("libUE4.so","0x9F4ADCC","0");      
PATCH_LIB("libUE4.so","0x9F4AE64","0");      
PATCH_LIB("libUE4.so","0x9F4B190","0");      
PATCH_LIB("libUE4.so","0x9F4B39C","0");      
PATCH_LIB("libUE4.so","0x9F4B4F4","0");      
PATCH_LIB("libUE4.so","0x9F4B82C","0");      
PATCH_LIB("libUE4.so","0x9F4BAEC","0");      
PATCH_LIB("libUE4.so","0x9F4BC88","0");      
PATCH_LIB("libUE4.so","0x9F4BE88","0");      
PATCH_LIB("libUE4.so","0x9F4BF30","0");      
PATCH_LIB("libUE4.so","0x9F4BFA4","0");      
PATCH_LIB("libUE4.so","0x9F4C1D4","0");      
PATCH_LIB("libUE4.so","0x9F4C27C","0");      
PATCH_LIB("libUE4.so","0x9F52410","0");      
PATCH_LIB("libUE4.so","0x9F52554","0");      
PATCH_LIB("libUE4.so","0x9F52F24","0");      
PATCH_LIB("libUE4.so","0x9F530CC","0");
HOOK_LIB_THUMB("libanogs.so", "0xFDAEC", hThreads, oThreads);////@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0xF31EA", hC35Main, oC35Main);////@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0xE766C", hsub_E766C, osub_E766C);////@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0xCFF84", hMRPCS, oMRPCS);////@onebiecerr
HOOK_LIB_THUMB("libanogs.so", "0x3797bc", hMonitor, oMonitor);////@onebiecerr
HOOK_LIB("libanogs.so", "0x1C2A4C", hsub_1C2A4C, osub_1C2A4C);////@onebiecerr
HOOK_LIB("libanogs.so", "0x163068", hsub_163068, osub_163068);////@onebiecerr
HOOK_LIB("libanogs.so", "0x164DF8", hsub_164DF8, osub_164DF8);////@onebiecerr
HOOK_LIB("libanogs.so", "0x1DE8E0", hMemcpyParent2, oMemcpyParent2);////@onebiecerr
HOOK_LIB("libanogs.so", "0x19B5A4", hCryzerSetrings, oCryzerSetrings);////block caller strlen//@onebiecerr
HOOK_LIB("libanogs.so", "0x16D1A8", hCryzerSetrings, oCryzerSetrings);////block caller strlen//@onebiecerr
PATCH_LIB("libanogs.so", "0xf32d8", "00 20 70 47"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x27f640", "00 20 70 47"); ////@onebiecerr
PATCH_LIB("libanogs.so", "0x2702e8", "00 00 B0 E3 1E FF 2F E1"); ////@onebiecer
PATCH_LIB("libanogs.so", "0xf31f1", "00 00 B0 E3 1E FF 2F E1"); ////@onebiecer
PATCH_LIB("libanogs.so", "0x2322b4", "00 00 A0 E3 1E FF 2F E1 "); ////@onebiecer
PATCH_LIB("libanogs.so", "0x1de8e0", "00 00 A0 E3 1E FF 2F E1 "); ////@onebiecer
PATCH_LIB("libanogs.so", "0x6f338", "00 00 A0 E3 1E FF 2F E1 "); ////@onebiecer
PATCH_LIB("libUE4.so","0x9F532D4","0");      
PATCH_LIB("libUE4.so","0x9F5342C","0");      
PATCH_LIB("libUE4.so","0x9F534D8","0");      
PATCH_LIB("libUE4.so","0x9F53634","0");      
PATCH_LIB("libUE4.so","0x9F53984","0");      
PATCH_LIB("libUE4.so","0x9F53C48","0");      
PATCH_LIB("libUE4.so","0x9F53CEC","0");      
PATCH_LIB("libUE4.so","0x9F53F90","0");      
PATCH_LIB("libUE4.so","0x9F540E8","0");      
PATCH_LIB("libUE4.so","0x9F54380","0");      
PATCH_LIB("libUE4.so","0x9F5458C","0");      
PATCH_LIB("libUE4.so","0x9F54644","0");      
PATCH_LIB("libUE4.so","0x9F54870","0");      
PATCH_LIB("libUE4.so","0x9F54B38","0");      
PATCH_LIB("libUE4.so","0x9F54D94","0");      
PATCH_LIB("libUE4.so","0x9F54F3C","0");      
PATCH_LIB("libUE4.so","0x5958538","0");      
PATCH_LIB("libUE4.so","0x5958A90","0");      
PATCH_LIB("libUE4.so","0x5958E8C","0");      
PATCH_LIB("libUE4.so","0x595964C","0");      
PATCH_LIB("libUE4.so","0x5959804","0");      
PATCH_LIB("libUE4.so","0x5959E6C","0");      
PATCH_LIB("libUE4.so","0x595A194","0");      
PATCH_LIB("libUE4.so","0x595A7DC","0");      
PATCH_LIB("libUE4.so","0x595B050","0");      
PATCH_LIB("libUE4.so","0x595B5F0","0");      
PATCH_LIB("libUE4.so","0x595B768","0");      
PATCH_LIB("libUE4.so","0x595B8E0","0");      
PATCH_LIB("libUE4.so","0x595BC70","0");      
PATCH_LIB("libUE4.so","0x595BCE4","0");      
PATCH_LIB("libUE4.so","0x595BDB0","0");      
PATCH_LIB("libUE4.so","0x595C530","0");      
PATCH_LIB("libUE4.so","0x595C5B4","0");      
PATCH_LIB("libUE4.so","0x595C810","0");      
PATCH_LIB("libUE4.so","0x59613C4","0");      
PATCH_LIB("libUE4.so","0x5962ECC","0");      
PATCH_LIB("libUE4.so","0x596360C","0");      
PATCH_LIB("libUE4.so","0x59639A8","0");      
PATCH_LIB("libUE4.so","0x5963BBC","0");      
PATCH_LIB("libUE4.so","0x5963CB4","0");      
PATCH_LIB("libUE4.so","0x5964DFC","0");      
PATCH_LIB("libUE4.so","0x5965EE4","0");      
PATCH_LIB("libUE4.so","0x5966BB8","0");      
PATCH_LIB("libUE4.so","0x59678BC","0");      
PATCH_LIB("libUE4.so","0x596807C","0");      
PATCH_LIB("libUE4.so","0x5968248","0");      
PATCH_LIB("libUE4.so","0x5968758","0");      
PATCH_LIB("libUE4.so","0x59687D8","0");      
PATCH_LIB("libUE4.so","0x5968E4C","0");      
PATCH_LIB("libUE4.so","0x5969044","0");      
PATCH_LIB("libUE4.so","0x5969604","0");      
PATCH_LIB("libUE4.so","0x5969808","0");      
PATCH_LIB("libUE4.so","0x5969A18","0");      
PATCH_LIB("libUE4.so","0x5969C8C","0");      
PATCH_LIB("libUE4.so","0x596A65C","0");      
PATCH_LIB("libUE4.so","0x596A97C","0");      
PATCH_LIB("libUE4.so","0x596B0F0","0");      
PATCH_LIB("libUE4.so","0x596B1F8","0");      
PATCH_LIB("libUE4.so","0x596B88C","0");      
PATCH_LIB("libUE4.so","0x5B62534","0");      
PATCH_LIB("libUE4.so","0x5B625D8","0");      
PATCH_LIB("libUE4.so","0x5B6286C","0");      
PATCH_LIB("libUE4.so","0x5B6298C","0");      
PATCH_LIB("libUE4.so","0x5B62E24","0");      
PATCH_LIB("libUE4.so","0x5B62F04","0");      
PATCH_LIB("libUE4.so","0x5B63138","0");      
PATCH_LIB("libUE4.so","0x5B63340","0");      
PATCH_LIB("libUE4.so","0x5B635DC","0");      
PATCH_LIB("libUE4.so","0x5B63784","0");      
PATCH_LIB("libUE4.so","0x5B639AC","0");      
PATCH_LIB("libUE4.so","0x5B63CFC","0");      
PATCH_LIB("libUE4.so","0x5B63F98","0");      
PATCH_LIB("libUE4.so","0x5B64198","0");      
PATCH_LIB("libUE4.so","0x5B64330","0");      
PATCH_LIB("libUE4.so","0x5B64488","0");      
PATCH_LIB("libUE4.so","0x5B6707C","0");      
PATCH_LIB("libUE4.so","0x5B672F0","0");      
PATCH_LIB("libUE4.so","0x5B673A8","0");      
PATCH_LIB("libUE4.so","0x5B6744C","0");      
PATCH_LIB("libUE4.so","0x5B674D4","0");      
PATCH_LIB("libUE4.so","0x5B675F0","0");      
PATCH_LIB("libUE4.so","0x5B67678","0");      
PATCH_LIB("libUE4.so","0x5B67758","0");      
PATCH_LIB("libUE4.so","0x5B67858","0");      
PATCH_LIB("libUE4.so","0x5B6B2C4","0");      
PATCH_LIB("libUE4.so","0x5B6B440","0");      
PATCH_LIB("libUE4.so","0x5B6B498","0");      
PATCH_LIB("libUE4.so","0x5D8BCBC","0");      
PATCH_LIB("libUE4.so","0x5D8BCFC","0");      
PATCH_LIB("libUE4.so","0x5D8BFC0","0");      
PATCH_LIB("libUE4.so","0x5D8C004","0");      
PATCH_LIB("libUE4.so","0x5D8C0E0","0");      
PATCH_LIB("libUE4.so","0x5D8C3C0","0");      
PATCH_LIB("libUE4.so","0x5D8C3EC","0");      
PATCH_LIB("libUE4.so","0x5D8C988","0");      
PATCH_LIB("libUE4.so","0x5D8C990","0");      
PATCH_LIB("libUE4.so","0x5D8CCC4","0");      
PATCH_LIB("libUE4.so","0x5D91F2C","0");      
PATCH_LIB("libUE4.so","0x5D91FBC","0");      
PATCH_LIB("libUE4.so","0x5D9209C","0");      
PATCH_LIB("libUE4.so","0x5D9217C","0");      
PATCH_LIB("libUE4.so","0x5D923BC","0");      
PATCH_LIB("libUE4.so","0x5D92B70","0");      
PATCH_LIB("libUE4.so","0x5D9329C","0");      
PATCH_LIB("libUE4.so","0x5D933CC","0");      
PATCH_LIB("libUE4.so","0x5D934B0","0");      
PATCH_LIB("libUE4.so","0x5D9392C","0");      
PATCH_LIB("libUE4.so","0x5D93A38","0");      
PATCH_LIB("libUE4.so","0x5D93E10","0");      
PATCH_LIB("libUE4.so","0x5D94128","0");      
PATCH_LIB("libUE4.so","0x5D94174","0");      
PATCH_LIB("libUE4.so","0x5D942BC","0");      
PATCH_LIB("libUE4.so","0x5D9446C","0");      
PATCH_LIB("libUE4.so","0x5D94B24","0");      
PATCH_LIB("libUE4.so","0x5D94B7C","0");      
PATCH_LIB("libUE4.so","0x608CE40","0");      
PATCH_LIB("libUE4.so","0x6091098","0");      
PATCH_LIB("libUE4.so","0x60910EC","0");      
PATCH_LIB("libUE4.so","0x60912D0","0");      
PATCH_LIB("libUE4.so","0x609137C","0");      
PATCH_LIB("libUE4.so","0x6091504","0");      
PATCH_LIB("libUE4.so","0x6091560","0");      
PATCH_LIB("libUE4.so","0x60915BC","0");      
PATCH_LIB("libUE4.so","0x6091668","0");      
PATCH_LIB("libUE4.so","0x6091768","0");      
PATCH_LIB("libUE4.so","0x60917C0","0");      
PATCH_LIB("libUE4.so","0x6091898","0");      
PATCH_LIB("libUE4.so","0x6091928","0");      
PATCH_LIB("libUE4.so","0x6091C08","0");      
PATCH_LIB("libUE4.so","0x6391794","0");      
PATCH_LIB("libUE4.so","0x6391934","0");      
PATCH_LIB("libUE4.so","0x6391B3C","0");      
PATCH_LIB("libUE4.so","0x6391CDC","0");      
PATCH_LIB("libUE4.so","0x6391D80","0");      
PATCH_LIB("libUE4.so","0x6391DD0","0");      
PATCH_LIB("libUE4.so","0x639209C","0");      
PATCH_LIB("libUE4.so","0x6392174","0");      
PATCH_LIB("libUE4.so","0x639225C","0");      
PATCH_LIB("libUE4.so","0x6392400","0");      
PATCH_LIB("libUE4.so","0x63924D8","0");      
PATCH_LIB("libUE4.so","0x6392528","0");      
PATCH_LIB("libUE4.so","0x639257C","0");      
PATCH_LIB("libUE4.so","0x63925D0","0");      
PATCH_LIB("libUE4.so","0x639274C","0");      
PATCH_LIB("libUE4.so","0x63927A0","0");      
PATCH_LIB("libUE4.so","0x63928E0","0");      
PATCH_LIB("libUE4.so","0x6392AE8","0");      
PATCH_LIB("libUE4.so","0x6392B3C","0");      
PATCH_LIB("libUE4.so","0x6392BA4","0");      
PATCH_LIB("libUE4.so","0x6392C04","0");      
PATCH_LIB("libUE4.so","0x6392C58","0");      
PATCH_LIB("libUE4.so","0x6392ED8","0");      
PATCH_LIB("libUE4.so","0x6392F30","0");      
PATCH_LIB("libUE4.so","0x6392F84","0");      
PATCH_LIB("libUE4.so","0x6392FDC","0");      
PATCH_LIB("libUE4.so","0x6393030","0");      
PATCH_LIB("libUE4.so","0x6393084","0");      
PATCH_LIB("libUE4.so","0x63930D8","0");      
PATCH_LIB("libUE4.so","0x6393130","0");      
PATCH_LIB("libUE4.so","0x6393228","0");      
PATCH_LIB("libUE4.so","0x639327C","0");      
PATCH_LIB("libUE4.so","0x63932D0","0");      
PATCH_LIB("libUE4.so","0x63933C0","0");      
PATCH_LIB("libUE4.so","0x63934C4","0");      
PATCH_LIB("libUE4.so","0x6393520","0");      
PATCH_LIB("libUE4.so","0x639357C","0");      
PATCH_LIB("libUE4.so","0x63935D8","0");      
PATCH_LIB("libUE4.so","0x6393634","0");      
PATCH_LIB("libUE4.so","0x63936DC","0");      
PATCH_LIB("libUE4.so","0x639384C","0");      
PATCH_LIB("libUE4.so","0x639389C","0");      
PATCH_LIB("libUE4.so","0x6393944","0");      
PATCH_LIB("libUE4.so","0x6393994","0");      
PATCH_LIB("libUE4.so","0x63939E8","0");      
PATCH_LIB("libUE4.so","0x6393A3C","0");      
PATCH_LIB("libUE4.so","0x6393E08","0");      
PATCH_LIB("libUE4.so","0x6393E58","0");      
PATCH_LIB("libUE4.so","0x6393EB0","0");      
PATCH_LIB("libUE4.so","0x6393F58","0");      
PATCH_LIB("libUE4.so","0x6394100","0");      
PATCH_LIB("libUE4.so","0x63941A0","0");      
PATCH_LIB("libUE4.so","0x63941F4","0");      
PATCH_LIB("libUE4.so","0x6394244","0");      
PATCH_LIB("libUE4.so","0x6394398","0");      
PATCH_LIB("libUE4.so","0x6394534","0");      
PATCH_LIB("libUE4.so","0x63945A0","0");      
PATCH_LIB("libUE4.so","0x639470C","0");      
PATCH_LIB("libUE4.so","0x63947C4","0");      
PATCH_LIB("libUE4.so","0x6394874","0");      
PATCH_LIB("libUE4.so","0x6394924","0");      
PATCH_LIB("libUE4.so","0x63949C4","0");      
PATCH_LIB("libUE4.so","0x6394BA4","0");      
PATCH_LIB("libUE4.so","0x6394C00","0");      
PATCH_LIB("libUE4.so","0x6394D44","0");      
PATCH_LIB("libUE4.so","0x6394DE4","0");      
PATCH_LIB("libUE4.so","0x6394ED8","0");      
PATCH_LIB("libUE4.so","0x6394F40","0");      
PATCH_LIB("libUE4.so","0x6395258","0");      
PATCH_LIB("libUE4.so","0x63952E8","0");      
PATCH_LIB("libUE4.so","0x6395368","0");      
PATCH_LIB("libUE4.so","0x63953E8","0");      
PATCH_LIB("libUE4.so","0x6395468","0");      
PATCH_LIB("libUE4.so","0x6395568","0");      
PATCH_LIB("libUE4.so","0x63955E8","0");      
PATCH_LIB("libUE4.so","0x639570C","0");      
PATCH_LIB("libUE4.so","0x6395958","0");      
PATCH_LIB("libUE4.so","0x63959A8","0");      
PATCH_LIB("libUE4.so","0x6395D20","0");      
PATCH_LIB("libUE4.so","0x6395E7C","0");      
PATCH_LIB("libUE4.so","0x6395ED0","0");      
PATCH_LIB("libUE4.so","0x6396004","0");      
PATCH_LIB("libUE4.so","0x6396054","0");      
PATCH_LIB("libUE4.so","0x63960A4","0");      
PATCH_LIB("libUE4.so","0x63960F8","0");      
PATCH_LIB("libUE4.so","0x639614C","0");      
PATCH_LIB("libUE4.so","0x63961B0","0");      
PATCH_LIB("libUE4.so","0x63962AC","0");      
PATCH_LIB("libUE4.so","0x6396310","0");      
PATCH_LIB("libUE4.so","0x6396368","0");      
PATCH_LIB("libUE4.so","0x63963CC","0");      
PATCH_LIB("libUE4.so","0x6396420","0");      
PATCH_LIB("libUE4.so","0x6686D38","0");      
PATCH_LIB("libUE4.so","0x6686FC8","0");      
PATCH_LIB("libUE4.so","0x6687120","0");      
PATCH_LIB("libUE4.so","0x66873B0","0");      
PATCH_LIB("libUE4.so","0x66875DC","0");      
PATCH_LIB("libUE4.so","0x6687784","0");      
PATCH_LIB("libUE4.so","0x6687998","0");      
PATCH_LIB("libUE4.so","0x6687BB8","0");      
PATCH_LIB("libUE4.so","0x6687D60","0");      
PATCH_LIB("libUE4.so","0x6687EB8","0");      
PATCH_LIB("libUE4.so","0x6688144","0");      
PATCH_LIB("libUE4.so","0x6688358","0");      
PATCH_LIB("libUE4.so","0x6688500","0");      
PATCH_LIB("libUE4.so","0x6688590","0");      
PATCH_LIB("libUE4.so","0x6688604","0");      
PATCH_LIB("libUE4.so","0x668875C","0");      
PATCH_LIB("libUE4.so","0x66889EC","0");      
PATCH_LIB("libUE4.so","0x6688A90","0");      
PATCH_LIB("libUE4.so","0x67339DC","0");      
PATCH_LIB("libUE4.so","0x6733C34","0");      
PATCH_LIB("libUE4.so","0x6733DDC","0");      
PATCH_LIB("libUE4.so","0x673415C","0");      
PATCH_LIB("libUE4.so","0x67342F8","0");      
PATCH_LIB("libUE4.so","0x67344F0","0");      
PATCH_LIB("libUE4.so","0x6734648","0");      
PATCH_LIB("libUE4.so","0x6734980","0");      
PATCH_LIB("libUE4.so","0x6734AD8","0");      
PATCH_LIB("libUE4.so","0x6734E10","0");      
PATCH_LIB("libUE4.so","0x6735008","0");      
PATCH_LIB("libUE4.so","0x67352CC","0");      
PATCH_LIB("libUE4.so","0x6735874","0");      
PATCH_LIB("libUE4.so","0x6735ABC","0");      
PATCH_LIB("libUE4.so","0x6735C64","0");      
PATCH_LIB("libUE4.so","0x6736430","0");      
PATCH_LIB("libUE4.so","0x6736748","0");      
PATCH_LIB("libUE4.so","0x67368E4","0");      
PATCH_LIB("libUE4.so","0x6736A3C","0");      
PATCH_LIB("libUE4.so","0x6736D74","0");      
PATCH_LIB("libUE4.so","0x6737038","0");      
PATCH_LIB("libUE4.so","0x4E42544","0");      
PATCH_LIB("libUE4.so","0x4E425CC","0");      
PATCH_LIB("libUE4.so","0x4E42654","0");      
PATCH_LIB("libUE4.so","0x4E4277C","0");      
PATCH_LIB("libUE4.so","0x4E42980","0");      
PATCH_LIB("libUE4.so","0x4E42B28","0");      
PATCH_LIB("libUE4.so","0x4E42C80","0");      
PATCH_LIB("libUE4.so","0x4E42DD0","0");      
PATCH_LIB("libUE4.so","0x4E42EE0","0");      
PATCH_LIB("libUE4.so","0x4E4316C","0");      
PATCH_LIB("libUE4.so","0x4E43380","0");      
PATCH_LIB("libUE4.so","0x4E43528","0");      
PATCH_LIB("libUE4.so","0x4E43680","0");      
PATCH_LIB("libUE4.so","0x4E4390C","0");      
PATCH_LIB("libUE4.so","0x4E43B30","0");      
PATCH_LIB("libUE4.so","0x4E43CD8","0");      
PATCH_LIB("libUE4.so","0x4E43E30","0");      
PATCH_LIB("libUE4.so","0x4E44454","0");      
PATCH_LIB("libUE4.so","0x4E444C4","0");      
PATCH_LIB("libUE4.so","0x4E44568","0");      
PATCH_LIB("libUE4.so","0x4E445F0","0");      
PATCH_LIB("libUE4.so","0x4E44694","0");      
PATCH_LIB("libUE4.so","0x5088418","0");      
PATCH_LIB("libUE4.so","0x50884B4","0");      
PATCH_LIB("libUE4.so","0x5088534","0");      
PATCH_LIB("libUE4.so","0x5088890","0");      
PATCH_LIB("libUE4.so","0x50889A4","0");      
PATCH_LIB("libUE4.so","0x5088BB4","0");      
PATCH_LIB("libUE4.so","0x5088D0C","0");      
PATCH_LIB("libUE4.so","0x5088F98","0");      
PATCH_LIB("libUE4.so","0x5089020","0");      
PATCH_LIB("libUE4.so","0x50892DC","0");      
PATCH_LIB("libUE4.so","0x5089478","0");      
PATCH_LIB("libUE4.so","0x508955C","0");      
PATCH_LIB("libUE4.so","0x50896B4","0");      
PATCH_LIB("libUE4.so","0x5089940","0");      
PATCH_LIB("libUE4.so","0x5089BB0","0");      
PATCH_LIB("libUE4.so","0x5089FF0","0");      
PATCH_LIB("libUE4.so","0x508A010","0");      
PATCH_LIB("libUE4.so","0x508A228","0");      
PATCH_LIB("libUE4.so","0x5154A40","0");      
PATCH_LIB("libUE4.so","0x5154D68","0");      
PATCH_LIB("libUE4.so","0x5154E5C","0");      
PATCH_LIB("libUE4.so","0x51552C4","0");      
PATCH_LIB("libUE4.so","0x515560C","0");      
PATCH_LIB("libUE4.so","0x51565F8","0");      
PATCH_LIB("libUE4.so","0x515666C","0");      
PATCH_LIB("libUE4.so","0x51568EC","0");      
PATCH_LIB("libUE4.so","0x5156B1C","0");      
PATCH_LIB("libUE4.so","0x5156B90","0");      
PATCH_LIB("libUE4.so","0x5156E20","0");      
PATCH_LIB("libUE4.so","0x5156E94","0");      
PATCH_LIB("libUE4.so","0x51570A4","0");      
PATCH_LIB("libUE4.so","0x515714C","0");      
PATCH_LIB("libUE4.so","0x54D5478","0");      
PATCH_LIB("libUE4.so","0x54D7758","0");      
PATCH_LIB("libUE4.so","0x54D7A64","0");      
PATCH_LIB("libUE4.so","0x54D7AF0","0");      
PATCH_LIB("libUE4.so","0x54D7BC8","0");      
PATCH_LIB("libUE4.so","0x54D7E4C","0");      
PATCH_LIB("libUE4.so","0x54D816C","0");      
PATCH_LIB("libUE4.so","0x54D8494","0");      
PATCH_LIB("libUE4.so","0x54D8F64","0");      
PATCH_LIB("libUE4.so","0x54D9244","0");      
PATCH_LIB("libUE4.so","0x54D924C","0");      
PATCH_LIB("libUE4.so","0x54D98C4","0");      
PATCH_LIB("libUE4.so","0x54DA0A0","0");      
PATCH_LIB("libUE4.so","0x54DAE84","0");      
PATCH_LIB("libUE4.so","0x54DB4C4","0");      
PATCH_LIB("libUE4.so","0x54DB780","0");      
PATCH_LIB("libUE4.so","0x57CC8D8","0");      
PATCH_LIB("libUE4.so","0x57CCB60","0");      
PATCH_LIB("libUE4.so","0x57CCDB8","0");      
PATCH_LIB("libUE4.so","0x57D121C","0");      
PATCH_LIB("libUE4.so","0x57D1374","0");      
PATCH_LIB("libUE4.so","0x57D219C","0");      
PATCH_LIB("libUE4.so","0x57D2278","0");      
PATCH_LIB("libUE4.so","0x5928A48","0");      
PATCH_LIB("libUE4.so","0x5928E48","0");      
PATCH_LIB("libUE4.so","0x5928FC0","0");     
PATCH_LIB("libUE4.so","0x59290C8","0");      
PATCH_LIB("libUE4.so","0x5929164","0");      
PATCH_LIB("libUE4.so","0x59295D8","0");      
PATCH_LIB("libUE4.so","0x5929A0C","0");      
PATCH_LIB("libUE4.so","0x5929B6C","0");      
PATCH_LIB("libUE4.so","0x5929D24","0");      
PATCH_LIB("libUE4.so","0x592A234","0");      
PATCH_LIB("libUE4.so","0x592A8C0","0");      
PATCH_LIB("libUE4.so","0x592AEA0","0");      
PATCH_LIB("libUE4.so","0x592B1B0","0");      
PATCH_LIB("libUE4.so","0x592BA48","0");      
PATCH_LIB("libUE4.so","0x592BA64","0");      
PATCH_LIB("libUE4.so","0x592BACC","0");      
PATCH_LIB("libUE4.so","0x592BB44","0");      
PATCH_LIB("libUE4.so","0x592BE90","0");      
PATCH_LIB("libUE4.so","0x592BFD8","0");      
PATCH_LIB("libUE4.so","0x592C09C","0");      
PATCH_LIB("libUE4.so","0x592CD40","0");      
PATCH_LIB("libUE4.so","0x592CDB0","0");      
PATCH_LIB("libUE4.so","0x59311A0","0");      
PATCH_LIB("libUE4.so","0x59312FC","0");      
PATCH_LIB("libUE4.so","0x59313A0","0");      
PATCH_LIB("libUE4.so","0x5931A54","0");      

PATCH_LIB("libUE4.so","0x6009834","0");
PATCH_LIB("libUE4.so","0x6009834","0");
PATCH_LIB("libUE4.so","0x5FB72E0","0");
PATCH_LIB("libUE4.so","0x5F94600","0");
PATCH_LIB("libUE4.so","0x5F94600","0");
PATCH_LIB("libUE4.so","0x5F84304","0");
PATCH_LIB("libUE4.so","0x5F77948","0");
PATCH_LIB("libUE4.so","0x5F84304","0");
PATCH_LIB("libUE4.so","0x5F77948","0");
PATCH_LIB("libUE4.so","0x5F664C4","0");
PATCH_LIB("libUE4.so","0x5F664C4","0");
PATCH_LIB("libUE4.so","0x5F58BE4","0");
PATCH_LIB("libUE4.so","0x5F58BE4","0");
PATCH_LIB("libUE4.so","0x5F52814","0"); 
PATCH_LIB("libUE4.so","0x5F52814","0");
PATCH_LIB("libUE4.so","0x5F477AC","0");
PATCH_LIB("libUE4.so","0x5F3240C","0");
PATCH_LIB("libUE4.so","0x5EF5030","0");
PATCH_LIB("libUE4.so","0x5F268C8","0");  
PATCH_LIB("libUE4.so","0x5EE9910","0");   
PATCH_LIB("libUE4.so","0x5ED27F0","0");  
PATCH_LIB("libUE4.so","0x5EC7984","0"); 
PATCH_LIB("libUE4.so","0x5EB8EA8","0"); 
PATCH_LIB("libUE4.so","0x5E987E8","0");   
PATCH_LIB("libUE4.so","0x5E73028","0");  
PATCH_LIB("libUE4.so","0x5E6547C","0");  
PATCH_LIB("libUE4.so","0x5E0B858","0");  
PATCH_LIB("libUE4.so","0x5DC60E0","0");    
PATCH_LIB("libUE4.so","0x58A4E80","0");    
PATCH_LIB("libUE4.so","0x5867648","0");   
PATCH_LIB("libUE4.so","0x5ACB644","0");   
PATCH_LIB("libUE4.so","0x5949494","0");  
PATCH_LIB("libUE4.so","0x59A9494","0");  
PATCH_LIB("libUE4.so","0x58D24C8","0"); 
PATCH_LIB("libUE4.so","0x58D24C8","0");    
PATCH_LIB("libUE4.so","0x589911C","0"); 
PATCH_LIB("libUE4.so","0x589911C","0");   
PATCH_LIB("libUE4.so","0x57C2524","0");   
PATCH_LIB("libUE4.so","0x57C2524","0");   
PATCH_LIB("libUE4.so","0x577628C","0");   
PATCH_LIB("libUE4.so","0x577628C","0"); 
PATCH_LIB("libUE4.so","0x62F7EF8","0");   
PATCH_LIB("libUE4.so","0x62E2628","0");  
PATCH_LIB("libUE4.so","0x62E2628","0");
PATCH_LIB("libUE4.so","0x620492C","0"); 
PATCH_LIB("libUE4.so","0x6285228","0");
PATCH_LIB("libUE4.so","0x62DA92C","0"); 
PATCH_LIB("libUE4.so","0x6285228","0");    
PATCH_LIB("libUE4.so","0x62A5F44","0");  
PATCH_LIB("libUE4.so","0x62A5F44","0");
PATCH_LIB("libUE4.so","0x62483F0","0");    
PATCH_LIB("libUE4.so","0x62396F8","0");     
PATCH_LIB("libUE4.so","0x62483F0","0");     
PATCH_LIB("libUE4.so","0x6213284","0");    
PATCH_LIB("libUE4.so","0x62396F8","0");      
PATCH_LIB("libUE4.so","0x6213284","0");     
PATCH_LIB("libUE4.so","0x6208780","0");   
PATCH_LIB("libUE4.so","0x61FBDCC","0");  
PATCH_LIB("libUE4.so","0x61E4848","0");   
PATCH_LIB("libUE4.so","0x61E4848","0");    
PATCH_LIB("libUE4.so","0x616AE2C","0"); 
PATCH_LIB("libUE4.so","0x6155988","0");      
PATCH_LIB("libUE4.so","0x6147F2C","0"); 
PATCH_LIB("libUE4.so","0x6139630","0");      
PATCH_LIB("libUE4.so","0x6147F2C","0");      
PATCH_LIB("libUE4.so","0x6139630","0");     
PATCH_LIB("libUE4.so","0x611340C","0");   
PATCH_LIB("libUE4.so","0x611340C","0");   
PATCH_LIB("libUE4.so","0x6107178","0");       
PATCH_LIB("libUE4.so","0x6107178","0");  
PATCH_LIB("libUE4.so","0x60F8434","0");      
PATCH_LIB("libUE4.so","0x60FB434","0");      
PATCH_LIB("libUE4.so","0x60C5E80","0");     
PATCH_LIB("libUE4.so","0x60C5280","0");   
PATCH_LIB("libUE4.so","0x60C5E80","0");   
PATCH_LIB("libUE4.so","0x60B980C","0");    
PATCH_LIB("libUE4.so","0x60A21BC","0");    
PATCH_LIB("libUE4.so","0x608AA04","0");      
PATCH_LIB("libUE4.so","0x6096308","0");     
PATCH_LIB("libUE4.so","0x6077C90","0");       
PATCH_LIB("libUE4.so","0x60687F0","0");     
PATCH_LIB("libUE4.so","0x60521C4","0");      
PATCH_LIB("libUE4.so","0x6035A24","0");      
PATCH_LIB("libUE4.so","0x60430F0","0");  
PATCH_LIB("libUE4.so","0x6014288","0");

PATCH_LIB("libUE4.so","0x510B260","0");
PATCH_LIB("libUE4.so","0x510B378","0");
PATCH_LIB("libUE4.so","0x5106524","0");
PATCH_LIB("libUE4.so","0x51066A8","0");
PATCH_LIB("libUE4.so","0x51067C0","0");
PATCH_LIB("libUE4.so","0x5106864","0");
PATCH_LIB("libUE4.so","0x7B0E220","0");
PATCH_LIB("libUE4.so","0x7B0E230","0");
PATCH_LIB("libUE4.so","0x1EE6E56","0");
PATCH_LIB("libUE4.so","0x6938FBC","0");
PATCH_LIB("libUE4.so","0x7B0E230","0");
PATCH_LIB("libUE4.so","0x7B0E238","0");
PATCH_LIB("libUE4.so","0x7B0E24C","0");
PATCH_LIB("libUE4.so","0x7B0E25C","0");
PATCH_LIB("libUE4.so","0x7B0D01C","0");
PATCH_LIB("libUE4.so","0x7B0D030","0");
PATCH_LIB("libUE4.so","0x7B0D058","0");
PATCH_LIB("libUE4.so","0x1EDEBC4","0");
PATCH_LIB("libUE4.so","0x1EE09A0","0");
PATCH_LIB("libUE4.so","0x1EE6E56","0");
PATCH_LIB("libUE4.so","0x6938FBC","0");
PATCH_LIB("libUE4.so","0x6938FC0","0");
PATCH_LIB("libUE4.so","0x1EE7C05","0");
PATCH_LIB("libUE4.so","0x1EEE0AA","0");
PATCH_LIB("libUE4.so","0x1EEE0AB","0");
PATCH_LIB("libUE4.so","0x1EEE22E","0");
PATCH_LIB("libUE4.so","0x1EEFFE4","0");
PATCH_LIB("libUE4.so","0x1EF7E68","0");
PATCH_LIB("libUE4.so","0x1EF7D9D","0");
PATCH_LIB("libUE4.so","0x69055F0","0");
PATCH_LIB("libUE4.so","0x69055F4","0");
PATCH_LIB("libUE4.so","0x69055F8","0");
PATCH_LIB("libUE4.so","0x6905600","0");
PATCH_LIB("libUE4.so","0x6905608","0");
PATCH_LIB("libUE4.so","0x6905614","0");
PATCH_LIB("libUE4.so","0x1EF7EC9","0");
PATCH_LIB("libUE4.so","0x258077C","00 F0 20 E3");
PATCH_LIB("libUE4.so","0x107BA8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x37A594","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3D1BE6C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x3D49234","00 00 A0 E3 1E FF 2F E1");
HOOK_LIB_NO_ORIG("libUE4.so", "0x7BB5C10", hook_strlen);
return NULL;
    }
    int sub_3672CC(_BYTE *a1, int a2, const char *a3, ...);//fix crash
int udaysub_3672CC(_BYTE *a1, int a2, const char *a3, ...)
{
if ( strstr(a2,"uday cheat ")//

   ( strstr(a2,"uday cheat ")//

   ( strstr(a2,"uday cheat ")){
   result 0;
   }


   if ( !v18 )
            goto LABEL_11;
          v25 = v13;
          v26 = a4;
          sub_366ADA(*(_DWORD *)(v8 - 76), "7.0.47.34014", *(_DWORD *)(v8 - 80));
          a4 = v26;
          *(_DWORD *)(v8 - 64) = -2052673013;
          *(_DWORD *)(v8 - 60) = v12;
          *(_DWORD *)(v8 - 68) = -1395494621;
          *(_DWORD *)(v8 - 72) = 0;
          if ( v26 <= v12 )
          {
            if ( v12 >= v10 )
            {
              if ( v12 < v11 )
              {
                v13 = v25;
                v14 = -976715542;
                v9 = -359451733;
                v7 = -296922295;
                if ( v12 == v10 )
                  goto LABEL_86;
                goto LABEL_11;
              }
              v13 = v25;
              v16 = v12 == v25;
              v27 = v12 < v25;
              v14 = -976715542;
              v9 = -359451733;
              if ( v27 )
              {
                v7 = -296922295;
                if ( v12 == v11 )
                  goto LABEL_99;
                goto LABEL_11;
              }
              v7 = -296922295;
              goto LABEL_33;
            }
            v15 = v12 == v5;
            if ( v12 >= v5 )
            {
              v13 = v25;
              v14 = -976715542;
              v9 = -359451733;
              v7 = -296922295;
              goto LABEL_39;
            }
            v13 = v25;
            v14 = -976715542;
            v9 = -359451733;
            v7 = -296922295;
            if ( v12 != a4 )
              goto LABEL_11;
LABEL_126:
            *(_DWORD *)(v8 - 56) = &v35;
            *(_DWORD *)(v8 - 52) = &v34;
            *(_DWORD *)(v8 - 48) = &v33;
            *(_DWORD *)(v8 - 44) = &v32;
            *(_DWORD *)(v8 - 64) = 1908706246;
            *(_DWORD *)(v8 - 68) = 234111189;
            *(_DWORD *)(v8 - 60) = v13;
            goto LABEL_11;
          }
          v14 = -976715542;
          v13 = v25;
          v9 = -359451733;
          if ( v12 >= -296922295 )
            break;
          v7 = -296922295;
          v18 = v12 == -359451733;
          if ( v12 < -359451733 )
          {
            if ( v12 != -976715542 )
              goto LABEL_11;
            goto LABEL_127;
          }
        }
        if ( v12 >= v6 )
        {
          v7 = -296922295;
          v19 = 1;
          goto LABEL_42;
        }
        v7 = -296922295;
        if ( v12 == -296922295 )
          goto LABEL_130;
LABEL_11:
        v17 = *(_DWORD *)(v8 - 60);
        goto LABEL_12;
      }
      if ( v17 != v10 )
        goto LABEL_11;
LABEL_86:
      while ( 1 )
      {
        *(_DWORD *)(v8 - 60) = v14;
        *(_DWORD *)(v8 - 64) = 1098165939;
        *(_DWORD *)(v8 - 68) = -2068042151;
        *(_BYTE *)(v8 - 37) = *(_DWORD *)(v8 - 76) == 0;
        if ( a4 > v14 )
          break;
        if ( v14 < v10 )
        {
          v15 = v14 == v5;
          if ( v14 < v5 )
          {
            if ( v14 != a4 )
              goto LABEL_11;
            goto LABEL_126;
          }
LABEL_39:
          if ( v15 )
            __asm { POP             {R4-R7,PC}; Pop registers }
          goto LABEL_11;
        }
        if ( v14 >= v11 )
        {
          v16 = v14 == v13;
          if ( v14 < v13 )
          {
            if ( v14 == v11 )
              goto LABEL_99;
            goto LABEL_11;
          }
          goto LABEL_33;
        }
        if ( v14 != v10 )
          goto LABEL_11;
      }
      if ( v14 >= v7 )
      {
        if ( v14 >= v6 )
        {
          v19 = v14 == v12;
          if ( v14 >= v12 )
            goto LABEL_42;
          if ( v14 == v6 )
            goto LABEL_118;
          goto LABEL_11;
        }
        if ( v14 != v7 )
          goto LABEL_11;
        goto LABEL_130;
      }
      v18 = v14 == v9;
      if ( v14 >= v9 )
        goto LABEL_63;
LABEL_127:
      *(_DWORD *)(v8 - 68) = 1167654827;
      *(_DWORD *)(v8 - 64) = -1358181376;
      v17 = v9;
      if ( *(_BYTE *)(v8 - 37) )
        v17 = 695517992;
      *(_DWORD *)(v8 - 72) = -1;
    }
    if ( v17 < v7 )
    {
      v18 = v17 == v9;
      if ( v17 >= v9 )
        goto LABEL_63;
      if ( v17 == v14 )
        goto LABEL_127;
      goto LABEL_11;
    }
    if ( v17 >= v6 )
    {
      v19 = v17 == v12;
      if ( v17 >= v12 )
        goto LABEL_42;
      if ( v17 == v6 )
        goto LABEL_118;
      goto LABEL_11;
    }
    if ( v17 != v7 )
      goto LABEL_11;
LABEL_130:
    **(_DWORD **)(v8 - 48) = 6948;
    v28 = **(_DWORD **)(v8 - 48);
    **(_DWORD **)(v8 - 44) = 7629;
    v29 = **(_DWORD **)(v8 - 44);
    *(_DWORD *)(v8 - 68) = -509339920;
    v30 = v28 & v29;
    v31 = v29 - (v29 & ~v28);
    v24 = -1955557818;
    v15 = v31 == v30;
    v17 = v10;
    if ( !v15 )
      v17 = 2049160944;
}

__int64 __fastcall (*osub_CBD78)(__int64 a1);
__int64 __fastcall sub_CBD78(__int64 a1)
{
 
     auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0)); 
  if ( (ret - libanogsBase) == 0xcd568) {return 0LL;}

  return osub_CBD78(a1);
 
}

int (*osub_E1172)(const char *a1, unsigned int a2);
int hsub_E1172(const char *a1, unsigned int a2)
{
    while(true)
    {
        sleep(10000000000);//166/24
    }
    return osub_E1172(a1,a2);
}


int __fastcall (*osub_12BA2C)(const char *a1, unsigned int a2);
int __fastcall hsub_12BA2C(const char *a1, unsigned int a2)
{
 while(true)
 {
  sleep(10000);
 }
 return osub_12BA2C(a1, a2);
}

//=========================================================LOGIN CRASH FIX (anort hook)============================================================//



__int64_t __fastcall (*osub_1B5688)(__int64_t a1, const char *a2);
__int64_t __fastcall sub_1B5688(__int64_t a1, const char *a2) {
    
   if (strstr(a2, ("egl")) ||
       strstr(a2, ("unlocked")) ||
        strstr(a2, ("ro.")) ||
       strstr(a2, ("sys.oem_unlock_allowed")))
    {
        return 0LL;
    }

    return osub_1B5688(a1, a2);
}



//=========================================================CASE 35  Caller============================================================//


  
//HOOK BYPASS


void *anogs_thread(void *) {
    while (!isLibraryLoaded(OBFUSCATE("libanogs.so"))) {
        sleep(1);
    }
   libanogsBase = findLibrary(OBFUSCATE("libanogs.so"));
   
HOOK_LIB("libanogs.so", "0xCBD78",sub_CBD78 , osub_CBD78  ); // Crash Fiix
HOOK_LIB("libanogs.so", "0x1B5688", sub_1B5688, osub_1B5688);   // strlen caller (egl offline fix)
HOOK_LIB("libanort.so", "0x12BA2C", hsub_E1172, osub_E1172);    // Anort crash fix
PATCH_LIB("libanogs.so","0x46D64","00 00 A0 E3 1E FF 2F E1"); //LOBBY CRASH FIX
PATCH_LIB("libTDataMaster.so","0x3A1FDC","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x3A12B0","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x365FA4","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x365CCC","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x365B4C","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x3658B4","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x3656A4","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x364F24","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x364EAC","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x364DDC","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x364DB0","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x3649AC","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x36472C","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x3646AC","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x3621FC","00 04 6F 80");
PATCH_LIB("libTDataMaster.so","0x31C788","00 04 6F 80");
PATCH_LIB("libanogs.so","0xC8E80","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xc8e80","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xc8f20","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xc9590","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xc8e10","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1365D0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xCBD78","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x13687C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1366AC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x136770","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x10CDA8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xC46CA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3C1CA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x84F6C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xC04BA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xC25CA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x423CA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x446CA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4E0CA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x8F2CA","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xEEAA8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF3E80","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF4850","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF58F8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF5AE0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF5C74","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF5DB4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xFC3AC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xFC4D4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xFDCD0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x10F328","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x116860","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x118018","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x13FF1C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xCB334","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xCB344","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xCC254","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xCF8D8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xD1E58","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xD660C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xDA974","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xDC4AC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xDD544","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xE372C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xE376C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xE3B20","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xE3EAC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xE3EE4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x47506","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1366ac","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x136770","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x136800","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x13687c","00 00 80 D2 C0 03 5F D6");
    return NULL;
    }

__attribute__((constructor))
void lib_main() {

    pthread_t ptid;
	pthread_t ptid1;
    pthread_create(&ptid, NULL, anogs_thread, NULL);
    pthread_create(&ptid, NULL, ue4_thread, NULL);
}

int __fastcall (*osub_3629F6)(int result, _DWORD *a2, unsigned int a3)
int __fastcall hooksub_3629F6(int result, _DWORD *a2, unsigned int a3)
{
  while(true)
 {
  sleep(100000)
 return osub_3629F6(a2,a3);
}

HOOK_LIB("libanogs.so", 0x3629F6", hook_3629F6,osub_3629F6);
}

int *__fastcall (*osub_36139C)(int *a1)
int *__fastcall hooksub_36139C(int *a1)
{
  while(true)
 {
  sleep(100000)
 return osub_36139C(a1);
}

HOOK_LIB("libanogs.so", 0x36139C", hook_36139C,osub_36139C);
}

void (*osub_38CDD8)(_BYTE *a1, const char *a2, ...);
void hooksub_38CDD8(_BYTE *a1, const char *a2, ...)
{
  while(true)
 {
  sleep(100000)
 return osub_38CDD8(a1,a2);
}

HOOK_LIB("libanogs.so", 0x38CDD8", hook_38CDD8,osub_38CDD8);


int __fastcall (*osub_38CD28)(unsigned __int8 *a1, const char *a2)
int __fastcall hooksub_38CD28(unsigned __int8 *a1, const char *a2)
{
  while(true)
 {
  sleep(100000)
 return osub_38CD28(a1,a2);
}

HOOK_LIB("libanogs.so", 0x38CD28", hook_38CD28,osub_38CD28);
{
  char *v4; // r0
  char *v5; // r6
  va_list va; // [sp+20h] [bp+8h] BYREF

  va_start(va, a2);
  if ( *a1 )
  {
    v4 = (char *)malloc(0x1000u);
    if ( v4 )
    {
      v5 = v4;
}


PATCH_LIB("libanogs.so", "0x8FCA2", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8FCA6", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8FD14", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F2C4", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F2D0", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x366A46", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x366D54", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x3672CC", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x367218", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x4A48FC", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x7E68E", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x110908", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x3B5D6C", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F376", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F4A6", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F74E", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F344", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F2D0", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F36A", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F35C", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0x8F350", "00 20 70 47"); 
PATCH_LIB("libanogs.so", "0xCCC14", "00 20 70 47"); 
PATCH_LIB("libanogs.so","0x8C8B8","00 20 70 47");
PATCH_LIB("libanogs.so","0xFD88C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libanogs.so","0x6F338","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libanogs.so","0x6F5FC","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libanogs.so","0x153F64","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x1391E0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4A2DD4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x1394C0", "00 00 80 D2 C0 03 5F D6");
}
//@onebiecerr HOOK_LIB_THUMB("libanogs.so", "0xE766C", hsub_E766C, osub_E766C);//@onebiecerr
 HOOK_LIB("libanogs.so", "0x163068", hsub_163068, osub_163068);
 HOOK_LIB("libanogs.so", "0x1C2A4C", hsub_1C2A4C, osub_1C2A4C);//@onebiecerr
 HOOK_LIB("libanogs.so", "0x2322B4", hMemcpyParent1, oMemcpyParent1);//
 HOOK_LIB("libanogs.so", "0x1DE8E0", hMemcpyParent2, oMemcpyParent2);////@onebiecerr
    HOOK_LIB("libanogs.so", "0x19B5A4", hstrlencaller, ostrlencaller);//@onebiecerr
    HOOK_LIB("libanogs.so", "0x16D1A8", hstrlencaller, ostrlencaller);
 ////@onebiecerr
 PATCH_LIB("libanogs.so", "0x27f640", "00 20 70 47");//
 PATCH_LIB("libanogs.so", "0xf32d8", "00 20 70 47");//
 PATCH_LIB("libanogs.so", "0x3adc34", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x27f644", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x164df8", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x163a24", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x163ec8", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x1643cc", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x164974", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x6f338", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x2702e8", "00 00 B0 E3 1E FF 2F E1");////@onebiecerr
}
HOOK_LIB_THUMB("libanogs.so", "0xFDAEC", hC16, oC16);////C16//@onebiecerr
 HOOK_LIB_THUMB("libanogs.so", "0xF31EA", hC35, oC35);////C35 main//@onebiecerr
 PATCH_LIB("libanogs.so", "0xF31F1", "00 00 B0 E3 1E FF 2F E1");//he edit  PUSH.W {R8} in case 35 he stupid i think//@onebiecerr
 HOOK_LIB_THUMB("libanogs.so", "0xCFF84", hMRPCS, oMRPCS);////C34 MRPCS//@onebiecerr
 HOOK_LIB_THUMB("libanogs.so", "0xE766C", hsub_E766C, osub_E766C);//FOR 1DAY BAN//@onebiecerr
 HOOK_LIB("libanogs.so", "0x3797BD", hMonitor, oMonitor);// FIX 1DAY OFFLINE//@onebiecerr
 HOOK_LIB("libanogs.so", "0x1C2A4C", hsub_1C2A4C, osub_1C2A4C);////@onebiecerr
 HOOK_LIB("libanogs.so", "0x163068", hsub_163068, osub_163068);////@onebiecerr
 HOOK_LIB("libanogs.so", "0x164DF8", hsub_164DF8, osub_164DF8);////@onebiecerr
    HOOK_LIB("libanogs.so", "0x19B5A4", hCryzerSetrings, oCryzerSetrings);////block caller strlen//@onebiecerr
    HOOK_LIB("libanogs.so", "0x16D1A8", hCryzerSetrings, oCryzerSetrings);////block caller strlen//@onebiecerr
 PATCH_LIB("libanogs.so", "0x27f640", "00 20 70 47");////@onebiecerr
 PATCH_LIB("libanogs.so", "0xf32d8", "00 20 70 47");// CASE 35p FIX ONLINE 10Y//@onebiecerr
 PATCH_LIB("libanogs.so", "0x2702e8", "00 00 B0 E3 1E FF 2F E1");//FIX 10Y OFFLINE//@onebiecerr
 PATCH_LIB("libanogs.so", "0x2322b4", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x1de8e0", "00 00 A0 E3 1E FF 2F E1");////@onebiecerr
 PATCH_LIB("libanogs.so", "0x6f338", "00 00 A0 E3 1E FF 2F E1");// fix crash lobby//@onebiecerr
}
int __fastcall osub_3860D4(int a1, int *a2, int a3)
int __fastcall hooksub_3860D4(int a1, int *a2, int a3)
{
  while(true)
 {
  sleep(100000)
 return osub_3860D4(a2,a3);
}

HOOK_LIB("libanogs.so", 0x3860D4", hook_3860D4,osub_3860D4);
}
int *__fastcall osub_36139C(int *a1)
int *__fastcall hooksub_36139C(int *a1)
{
  while(true)
 {
  sleep(100000)
 return osub_36139C(a1);
}

HOOK_LIB("libanogs.so", 0x36139C", hook_36139C,osub_36139C);
}



int __fastcall osub_149404(_DWORD *a1)
int __fastcall hooksub_149404(_DWORD *a1)
{
  while(true)
 {
  sleep(100000)
 return osub_149404(a1);
}

HOOK_LIB("libanogs.so", 0x149404", hook_149404,osub_149404);
}
int64 fastcall sub_F8A88(int64 a1, int64 a2)
{
  __int128 v2; // q0
  __int128 v3; // q1
  __int128 v4; // q2
  int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 result; // x0
  __int64 v10; // x22
  const void *v12; // x1
  __int64 v13; // x8
  __int64 v14; // x21
  __int64 v15; // x20

  *(_QWORD *)a2 = &off_21DC28;
  v2 = *(_OWORD *)(a1 + 8);
  v3 = *(_OWORD *)(a1 + 24);
  v4 = *(_OWORD *)(a1 + 40);
  v5 = *(_DWORD *)(a1 + 56);
  *(_QWORD *)(a2 + 72) = 0LL;
  *(_QWORD *)(a2 + 80) = 0LL;
  *(_QWORD *)(a2 + 64) = 0LL;
  *(_OWORD *)(a2 + 40) = v4;
  *(_DWORD *)(a2 + 56) = v5;
  *(_OWORD *)(a2 + 24) = v3;
  *(_OWORD *)(a2 + 8) = v2;
  v6 = *(_QWORD *)(a1 + 64);
  v7 = *(_QWORD *)(a1 + 72);
  result = v7 - v6;
  if ( v7 != v6 )
  {
    v10 = result >> 3;
    if ( (unsigned __int64)(result >> 3) >> 61 )
      abort();
    result = (__int64)operator new(result);
    *(_QWORD *)(a2 + 64) = result;
    *(_QWORD *)(a2 + 72) = result;
    *(_QWORD *)(a2 + 80) = result + 8 * v10;
    v12 = *(const void **)(a1 + 64);
    v13 = *(_QWORD *)(a1 + 72);
    v14 = result;
    v15 = v13 - (_QWORD)v12;
    if ( v13 - (__int64)v12 >= 1 )
    {
      result = (__int64)memcpy((void *)result, v12, (int)v13 - (int)v12);
      v14 += v15;
    }
    *(_QWORD *)(a2 + 72) = v14;
  }
  return result;
}
HOOK_LIB_NO_ORIG("libanogs.so","0xF8A88",sub_F8A88);
const void *__fastcall sub_1DDCC4(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x8
  unsigned __int64 v4; // x9
  _QWORD *v5; // x8
  const void *v6; // x20
  const void *v7; // t1
  _BYTE *v9; // x0
  _BYTE *v10; // x0
  __int64 v11; // x3

  
  if ( *(_QWORD *)a1 == v4 )
  {
    
  if ( !v6 )
  

    if ( !v6 )
      return v6;
  }
  if (sub_1DDCC4)
  {
    
    if (sub_1DDCC4)

  return v6;
}
}

HOOK_LIB_NO_ORIG("libanogs.so","0x1DDCC4", sub_1DDCC4);
void *__fastcall sub_29B114(__int64 a1, const void *a2, __int64 a3, void **a4)
{
  void *result; // x0
  __int64 v5; // [xsp+8h] [xbp-58h]

  v5 = (a3 - (__int64)a2) / 8;
  *a4 = (char *)*a4 - 8 * v5;
  if ( v5 > 0 )
    return memcpy(*a4, a2, 8 * (int)v5);
  return result;
}
// HOOK
HOOK_LIB_NO_ORIG("libanogs.so","0x29B114", sub_29B114);
int64 fastcall sub_200010(int64 a1, int64 a2, unsigned int *a3)
{
  void *v3; // x0
  unsigned int v8; // [xsp+34h] [xbp+34h]
  _QWORD *v9; // [xsp+38h] [xbp+38h]

  v3 = sub_160EB4();
  v9 = sub_15EA08((__int64)v3);
  if ( v9 )
  {
    sub_15F45C(v9, 0x6Au, 0LL, a2);
    v8 = sub_20009C(a1, (__int64)v9, a3);
    sub_15EB7C(v9);
    return v8;
  }
  else
  {
    sub_187780(
      0xDu,
      193,
      7,
      (__int64)"/Users/bkdevops/DevopsAgent/agent/workspace/p-9588583a786341c5b14d2797024c3756/src/openssl/crypto/asn1/a_i2d_fp.c",
      126);
    return 0LL;
  }
}
static int *(*osub_4BBF64)(__int64, const char *, unsigned int) = 0;

int *hsub_4BBF64(__int64 a1, const char *a2, unsigned int a3) {
    __android_log_print(ANDROID_LOG_DEBUG, "HOOK", "a2: %s, a3: %u", a2 ? a2 : "0", a3);
    int *result = osub_4BBF64(a1, a2, a3);
    __android_log_print(ANDROID_LOG_DEBUG, "HOOK", "Returned pointer: %p", result);
    return result;
}


xhook_register("libanogs.so", "0x4BBF64", hsub_4BBF64, (void **)&osub_4BBF64); xhook_refresh(0);
}
int __fastcall Zentra(int a1) {
if ( a1 ) {
return 0; }
return Zentra(a1);
}


PATCH_LIB("libanogs.so", "0x38CD28", "00 20 70 47");//=OFFLİNE/CRASH FİX
PATCH_LIB("libanogs.so", "0x390014", "00 20 70 47");//=OFFLİNE/CRASH FİX
//@zirveninbiustu
PATCH_LIB("libanogs.so", "0x38FC84", "00 20 70 47");//=OFFLİNE/CRASH FİX
PATCH_LIB("libanogs.so", "0x3900F8", "00 20 70 47");//=OFFLİNE/CRASH FİX
PATCH_LIB("libanogs.so", "0xF3480", "014 F0 BD");//=OFFLİNE/CRASH FİX
PATCH_LIB("libanogs.so", "0x38CCBC", "000 70 47 ");//=OFFLİNE/CRASH FİX
PATCH_LIB("libanogs.so", "0x38FE4C", "014 F0 BD");//=OFFLİNE/CRASH FİX
HOOK_LIB_NO_ORIG("libanogs.so", "0x1A9DAC", Zentra);
PATCH_LIB("libUE4.so", "0x64CAAAC", "00 1F 20 03 D5"); // Offline fix 
PATCH_LIB("libanogs.so", "0x401948", "00 00 A0 E3 1E FF 2F E1"); // 1 Day Ban Fix
}
int __fastcall sub_38D168(_BYTE *a1)
{
  int v2; // r0
  const char *v3; // r0
  int i; // r5
  __pid_t v5; // r0
  char v7[1040]; // [sp+8h] [bp-410h] BYREF

  memset(v7, 0, 0x400u);
  sub_3669A8(v7, "android ver:");
  sub_366A28(v7, "7.0.47.34014");
  sub_366A28(v7, " 20230522");
  sub_38CCBC(a1, 1, v7);
  v2 = sub_38CCBC(a1, 1, "{");
  v3 = (const char *)sub_8BBAC(v2);
  if ( v3 && *v3 )
    sub_38CCBC(a1, 1, v3);
  sub_38CCBC(a1, 1, " __ACE_EXPORT__");
  sub_38CCBC(a1, 1, " __ACE_PRIVATE__");
  sub_38CCBC(a1, 1, " __ENABLE_DATA_ENC__");
  sub_38CCBC(a1, 1, " __ENABLE_MPRCS__");
  sub_38CCBC(a1, 1, " __ENABLE_TPSTL__");
  sub_38CCBC(a1, 1, " __ENABLE_TPLIBC__");
  sub_38CCBC(a1, 1, " __TPSTL_RECRYLE__");
  sub_38CCBC(a1, 1, " __USE_NEW_QOS_ONLY__");
  sub_38CCBC(a1, 1, "}");
  sub_38CCBC(a1, 1, "module");
  sub_38CCBC(a1, 1, "{");
  for ( i = 0; i != 128; ++i )
  {
    if ( *a1 && a1[i + 513] == 57 )
      sub_38CCBC(a1, 1, " %d:%d", i, 1);
  }
  sub_38CCBC(a1, 1, "}");
  sub_38CCBC(a1, 1, "so:arm32");
  v5 = getpid();
  return sub_38CCBC(a1, 1, "pid:%d", v5);
}
HOOK_LIB_NO_ORIG("libanogs.so","0x38D168",sub_38D168);
}
int __fastcall sub_3AC5AC(char *s, int a2, int *a3, int *a4)
{
  int *v5; // r8
  int v6; // r5
  int v7; // r11
  char *v8; // r6
  char *v9; // r8
  _DWORD *v10; // r0
  int v11; // r6
  int v12; // r6
  int v13; // r6
  void *v14; // r0
  int *v16; // [sp+4h] [bp-11C4h]
  _DWORD v17[2]; // [sp+8h] [bp-11C0h] BYREF
  int v18; // [sp+10h] [bp-11B8h] BYREF
  int v19; // [sp+14h] [bp-11B4h] BYREF
  int v20; // [sp+18h] [bp-11B0h]
  int v21; // [sp+1Ch] [bp-11ACh]
  int v22; // [sp+20h] [bp-11A8h]
  int v23; // [sp+24h] [bp-11A4h]
  char *v24; // [sp+28h] [bp-11A0h] BYREF
  char *v25; // [sp+2Ch] [bp-119Ch]
  _BYTE *v26; // [sp+30h] [bp-1198h]
  _BYTE *v27; // [sp+34h] [bp-1194h]
  _DWORD *v28; // [sp+38h] [bp-1190h]
  _BYTE v29[128]; // [sp+3Ch] [bp-118Ch] BYREF
  _DWORD v30[3]; // [sp+BCh] [bp-110Ch] BYREF
  _BYTE v31[128]; // [sp+C8h] [bp-1100h] BYREF
  _DWORD v32[3]; // [sp+148h] [bp-1080h] BYREF
  _BYTE v33[32]; // [sp+154h] [bp-1074h] BYREF
  _DWORD v34[3]; // [sp+174h] [bp-1054h] BYREF
  _BYTE v35[16]; // [sp+180h] [bp-1048h] BYREF
  __int16 v36; // [sp+190h] [bp-1038h] BYREF
  char v37; // [sp+192h] [bp-1036h]
  _DWORD v38[1027]; // [sp+198h] [bp-1030h] BYREF

  if ( !s || (v5 = a3, (v6 = a2) != 0) && !a3 )
  {
    if ( a4 )
      *a4 = -3;
    return 0;
  }
  v38[1024] = v38;
  v38[0] = 0;
  v38[1] = 0;
  v37 = 0;
  v36 = 1;
  v34[2] = &v36;
  v34[0] = v35;
  v34[1] = v35;
  v32[2] = v34;
  v32[0] = v33;
  v32[1] = v33;
  v30[2] = v32;
  v30[0] = v31;
  v30[1] = v31;
  v28 = v30;
  v26 = v29;
  v27 = v29;
  v24 = s;
  v25 = &s[strlen(s)];
  v22 = -1;
  v23 = -1;
  if ( sub_3AC908(&v24, "_Z", "") || sub_3AC908(&v24, "__Z", "") )
  {
    v7 = sub_3AC958(&v24);
    if ( v7 )
    {
      v16 = v5;
      v9 = v24;
      v8 = v25;
      if ( v25 == v24 )
      {
LABEL_13:
        v5 = v16;
        goto LABEL_31;
      }
      if ( *v24 == 46 )
      {
        v10 = (_DWORD *)sub_3ADE20(v38, 20);
        *v10 = &off_44CFA8;
        v10[1] = 16843009;
        v10[2] = v7;
        v10[3] = v9;
        v7 = (int)v10;
        v10[4] = v8;
        v24 = v25;
        goto LABEL_13;
      }
    }
LABEL_34:
    v13 = -2;
    goto LABEL_40;
  }
  if ( sub_3AC908(&v24, "___Z", "") || sub_3AC908(&v24, "____Z", "") )
  {
    v18 = sub_3AC958(&v24);
    if ( !v18 || !sub_3AC908(&v24, "_block_invoke", "") )
    {
LABEL_30:
      v7 = 0;
      goto LABEL_31;
    }
    if ( v24 == v25 || *v24 != 95 )
    {
      v11 = 0;
    }
    else
    {
      v11 = 1;
      ++v24;
    }
    v7 = 0;
    sub_3ACEAC(v17, &v24, 0);
    if ( !v11 || v17[0] != v17[1] )
    {
      if ( v25 == v24 )
      {
LABEL_29:
        v7 = sub_3ACF06(&v24, "invocation function for block in ", &v18);
        goto LABEL_31;
      }
      if ( *v24 == 46 )
      {
        v24 = v25;
        goto LABEL_29;
      }
      goto LABEL_30;
    }
  }
  else
  {
    v7 = sub_3ACF38(&v24);
    if ( v25 != v24 )
      goto LABEL_34;
  }
LABEL_31:
  if ( !v7 )
    goto LABEL_34;
  if ( v6 )
  {
    v12 = *v5;
LABEL_37:
    v21 = v12;
    v19 = v6;
    v20 = 0;
    sub_3AC810(v7, &v19);
    sub_3AC836(&v19, 0);
    if ( v5 )
      *v5 = v20;
    v6 = v19;
    v13 = 0;
    goto LABEL_40;
  }
  v12 = 1024;
  v14 = malloc(0x400u);
  if ( v14 )
  {
    v6 = (int)v14;
    goto LABEL_37;
  }
  v6 = 0;
  v13 = -1;
LABEL_40:
  if ( a4 )
    *a4 = v13;
  sub_3AC850(&v24);
  if ( v13 )
    v6 = 0;
  return v6;
}
HOOK_LIB_NO_ORIG("libanogs.so","0x3AC5AC",sub_3AC5AC);
}
int __fastcall sub_38DC70(int result, const char *a2, int a3)
{
  int v5; // r0
  int v6; // r0
  int v7; // r4
  int v8; // r5
  char *v9; // r0
  __pid_t v10; // r0

  if ( a2 && !result )
  {
    result = *(unsigned __int8 *)a2;
    if ( *a2 )
    {
      v5 = ((int (*)(void))sub_38C990)();
      v6 = sub_38CDD8(v5, "__ASSERT err! %s, ln:%d", a2, a3);
      v7 = sub_38C990(v6);
      v8 = *(_DWORD *)_errno();
      v9 = strerror(v8);
      sub_38CDD8(v7, "errno:%d:%s", v8, v9);
      v10 = getpid();
      result = sub_3648F4(v10, 9);
    }
  }
  return result;
}
HOOK_LIB_NO_ORIG("libanogs.so","0x38DC70",sub_38DC70);
}
int __fastcall sub_F3148(int a1)
{
  int v2; // r0
  int result; // r0

  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  sub_3A9FA6(128);
  *(_DWORD *)a1 = v2;
  *(_DWORD *)(a1 + 4) = v2;
  *(_DWORD *)(a1 + 8) = v2 + 128;
  sub_3612C8(a1 + 1044);
  *(_DWORD *)(a1 + 1056) = 0;
  *(_DWORD *)(a1 + 1060) = 0;
  memset((void *)(a1 + 18), 0, 0x400u);
  *(_WORD *)(a1 + 12) = 0;
  result = a1;
  *(_DWORD *)(a1 + 14) = a1 + 18;
  return result;
}
HOOK_LIB_NO_ORIG("libanogs.so","0xF3148",sub_F3148);
}
_DWORD *__fastcall sub_258F60(_DWORD *a1, int a2)
{
  _DWORD *v4; // r0
  _DWORD *v5; // r6
  _DWORD *v6; // r4

  sub_3A9FA6(264);
  v5 = v4;
  v6 = v4 + 2;
  *v4 = 8;
  v4[1] = 32;
  memset(v4 + 2, 0, 0x100u);
  *a1 = a2;
  a1[1] = 0;
  a1[2] = v6;
  a1[3] = v6;
  a1[4] = v5 + 66;
  return a1;
}
HOOK_LIB_NO_ORIG("libanogs.so","0x258F60",sub_258F60);
}
int __fastcall sub_366D54(_BYTE *a1, int *a2, void (*a3)(void), int a4)
{
  char *v8; // r5
  _BYTE *i; // r4
  int result; // r0
  unsigned int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r0
  int v18; // r0
  int v19; // t1
  __int64 v20; // r0
  int v21; // t1
  _DWORD *v22; // r1
  int v23; // r3
  const char *v24; // r0
  unsigned int v25; // r0
  unsigned int v26; // t1
  unsigned int v27; // r2
  char *v28; // r4
  char *v29; // r1
  char v30; // r5
  bool v31; // cf
  const char *v32; // r1
  const char *v33; // t1
  int v34; // r5
  unsigned int v35; // r11
  int v36; // t1
  __int64 v37; // r0
  int v38; // r0
  int v39; // r5
  int v40; // r11
  int v41; // r0
  int *v42; // r0
  char *v43; // r4
  unsigned int v44; // r8
  __int64 v45; // r0
  char *v46; // r0
  int *v47; // r11
  int v48; // t1
  unsigned int v49; // r3
  char *v50; // r12
  char *v51; // r2
  unsigned int v52; // r5
  char v53; // r4
  int *v54; // r0
  int *v55; // r11
  int v56; // t1
  unsigned int v57; // r3
  unsigned int v58; // r5
  char v59; // r4
  char *v60; // r8
  unsigned int v61; // r9
  __int64 v62; // r0
  char *v63; // r0
  void (*v64)(void); // [sp+4h] [bp-6Ch]
  int *v65; // [sp+8h] [bp-68h]
  int *v66; // [sp+8h] [bp-68h]
  char *v67; // [sp+Ch] [bp-64h]
  char *v68; // [sp+Ch] [bp-64h]
  _QWORD v69[4]; // [sp+10h] [bp-60h] BYREF
  char v70; // [sp+52h] [bp-1Eh] BYREF
  char v71; // [sp+53h] [bp-1Dh]

  v69[0] = 0LL;
  v69[1] = 0LL;
  v69[2] = 0LL;
  v69[3] = 0LL;
  v8 = &v70;
LABEL_2:
  for ( i = a1 + 1; ; ++i )
  {
    result = (unsigned __int8)*a1;
    if ( result == 10 )
    {
      result = 10;
      goto LABEL_8;
    }
    if ( !*a1 )
      break;
    if ( result == 37 )
    {
      a1 = i;
      while ( 2 )
      {
        v11 = (unsigned __int8)*a1;
        if ( v11 > 0x57 )
        {
          switch ( *a1 )
          {
            case 'p':
              ((void (__fastcall *)(int, int))a3)(48, a4);
              ((void (__fastcall *)(int, int))a3)(120, a4);
              v26 = *a2++;
              v25 = v26;
              v71 = 0;
              if ( !v26 )
                goto LABEL_93;
              v27 = 1;
              v28 = v8;
              v29 = v8;
              do
              {
                v30 = (v25 & 0xF) + 48;
                if ( (v25 & 0xF) > 9 )
                  v30 = (v25 & 0xF) + 87;
                *v29-- = v30;
                if ( !(v25 >> 4) )
                  break;
                v31 = v27 >= 0x1F;
                v25 >>= 4;
                ++v27;
              }
              while ( !v31 );
              v24 = v29 + 1;
              v8 = v28;
              goto LABEL_94;
            case 'q':
            case 'r':
            case 't':
            case 'v':
            case 'w':
            case 'y':
LABEL_63:
              a3();
              goto LABEL_95;
            case 's':
              v33 = (const char *)*a2++;
              v32 = v33;
}
HOOK_LIB_NO_ORIG("libanogs.so","0x366D54",sub_366D54);
