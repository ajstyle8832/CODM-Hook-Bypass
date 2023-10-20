//Android-Mod-Menu-master
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
#include <list>
#include <vector>
#include <pthread.h>
#include <thread>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <memory.h>
#include <array>
#include <iterator>
#include <stdexcept>
#include <filesystem>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "KittyMemory/MemoryPatch.h"
#include "Substrate/SubstrateHook.h"
#include <Substrate/CydiaSubstrate.h>
#include "vampysupplies/obfuscate.h"
#include "vampysupplies/Logger.h"
#include "vampysupplies/Type.h"
#include "vampysupplies/Macros.h"
#include "vampysupplies/Utils.h"
#include "vampysupplies/Tools.h"
#include <cstdint>

#include <cstring>
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
using byte = uint8_t; 
pthread_t ptid;
#define targetLibName OBFUSCATE("libanogs.so")
#define SLEEP_TIME 1000LL / 60LL
#define GET_FUNC_PTR(lib, func) (void*)getLibraryFunctionAddress(lib, func) 

std::string getLibraryName(void* address) {
    std::vector<std::string> libraries = {"libil2cpp.so", "libTDataMaster.so", "libgcloud.so", "libanogs.so", "libanort.so", "libCrashSight.so", "libapp.so", "libav1d.so", "libav1d_jni.so", "libavif_android.so", "libc++_shared.so", "libc++_shared.so", "libcubehawk.so", "libflutter.so", "libgamemaster.so", "libgcloudarch.so", "libgcloudcore.so", "libGCloudVoice.so", "libgnustl_shared.so", "libGvoiceNN.so", "libijkffmpeg.so", "libINTLCompliance.so", "libINTLFoundation.so", "libITOP.so", "libkk-image.so", "libmarsxlog.so", "libmmkv.so", "libnpps-jni.so", "libopenplatform.so", "libPandoraVideo.so", "libPixUI_PXPlugin.so", "libpixuiCurl.so", "libPxExtFFi.so", "libsentry.so", "libsentry-android.so", "libspecialgem.so", "libswappy.so", "libtgpa.so", "libtool-checker.so", "libvlink.so" };
    for (const auto& lib : libraries) {
        uintptr_t baseAddr = KittyMemory::getAbsoluteAddress(lib.c_str(), 0, true);
        if (baseAddr != 0) {
            Dl_info info;
            if (dladdr(address, &info)) {
                if (std::string(info.dli_fname).find(lib) != std::string::npos) {
                    return lib;
                }
            }
        }
    }
    return "";
}
///////////////////////////////////////////////////////////////////////////
void (*originalAnoSDKForExport_0)();

void myAnoSDKForExport_0() {

  void* v0 = malloc(0x31u);

  // Zero out the buffer to block sending data
  memset(v0, 0, 0x31u);  

  originalAnoSDKForExport_0();

  free(v0);
}

int (*osub_27A94E)(byte** a1, byte** a2); // __attribute__((weak));

int __fastcall hsub_27A94E(byte** a1, byte** a2) {

  static byte dummy[100];
  *a1 = dummy;

  return osub_27A94E(a1, a2);
} 

int (*sub_28C1E0)(int a1, unsigned int a2);  //__attribute__((weak));
int hsub_28C1E0(int a1, unsigned int a2);

int hsub_28C1E0(int a1, unsigned int a2) {

  // Do not pass a1 to original function
  a1 = 0; 

  return sub_28C1E0(a1, a2);

}
int (*sub_244F1E)(int a1, int a2); //  __attribute__((weak));
int hsub_244F1E(int a1, int a2);

int hsub_244F1E(int a1, int a2) {

  // Modify a1 to avoid sending client data
  a1 = 0;

  // Call original function
  return sub_244F1E(a1, a2); 

}

int (*sub_2463E0)(int a1, int a2, unsigned char a3, unsigned char* a4);
int hsub_2463E0(int a1, int a2, unsigned char a3, unsigned char* a4);

// Hook function
int hsub_2463E0(int a1, int a2, unsigned char a3, unsigned char* a4) {

  // Modify a1 and a2 to avoid sending client data
  a1 = 0;
  a2 = 0;

  return sub_2463E0(a1, a2, a3, a4);

}

// Function prototype
int (*sub_246720)(int a1, int a2, int a3);
int  hsub_246720(int a1, int a2, int a3);

// Hook function 
int  hsub_246720(int a1, int a2, int a3) {

  // Set a1 and a2 to 0 to not send client data
  a1 = 0;
  a2 = 0;

  // Call original function
  return sub_246720(a1, a2, a3);
}


// Function prototype
typedef DWORD (__fastcall* tsub_28BE90)(DWORD, int);

// Global variables 
tsub_28BE90 original_sub_28BE90;

// Hook function
DWORD __fastcall hooked_sub_28BE90(DWORD result, int a2) {

  // Hook logic
  // Don't send any data, just return success
  return 1; 

}
/////////////////////////////////////////////////////////////////////////
//FixCrash
int (*sub_E20C2)(const char *a1, unsigned int a2);
int hsub_E20C2(const char *a1, unsigned int a2)
{
	while(true)
	{
		sleep(10000);
	}
	return sub_E20C2(a1,a2);
}

//CASE16
int (*old_IsEnable)(int a1, char *a2, int a3);
int IsEnable(int a1, char *NameOfThread, int a3)
{
    if (
	strstr(NameOfThread, "opcode_scan") //
    ){
     LOGI(OBFUSCATE("BLOCKED|%s"),NameOfThread);
        return 0;
    } else {
        LOGI(OBFUSCATE("ALLOWED|%s"),NameOfThread);
        return old_IsEnable(a1, NameOfThread, a3);
    }
}
	
//CASE CALL
int (*AnoSDKIoctlOld_0)(int a1, char *a2, void **a3, unsigned int a4, int *a5);
int hAnoSDKIoctlOld_0(int a1, char *a2, void **a3, unsigned int a4, int *a5)
{
    void* caller = __builtin_extract_return_addr(__builtin_return_address(0));
    std::string libName = getLibraryName(caller);
    uintptr_t libBaseAddr = KittyMemory::getAbsoluteAddress(libName.c_str(), 0, true);
    LOGI(OBFUSCATE("%s : %lx -> Case -> %d"), libName.c_str(), (uintptr_t)caller - libBaseAddr, a1);
    return AnoSDKIoctlOld_0(a1,a2,a3,a4,a5);
}
	
	
// Add this code before hack_thread()

#include <dlfcn.h> // for dlopen, dlsym

void* getLibraryFunctionAddress(const char* libraryName, unsigned long long functionHash) {

  void* library = dlopen(libraryName, RTLD_LAZY);
  if (!library) {
    LOGE("Failed to load library %s", libraryName);
    return NULL;
  }

  // Convert hash to a string
  char hashStr[18];
  snprintf(hashStr, sizeof(hashStr), "%llX", functionHash);

  // Lookup symbol
  void* funcPtr = dlsym(library, hashStr);
  if (!funcPtr) {
    LOGE("Failed to find %s in %s", hashStr, libraryName);  
    return NULL;
  }

  return funcPtr;
}


void *main_thread(void *) {

	 do {
        sleep(1);
    } while (!isLibraryLoaded("libanogs.so"));
	
	LOGI("anogs done");
	VampyStrMsHook_LIB("libanort.so", "0xE20C3", hsub_E20C2, sub_E20C2);///FIXCRASH LOGO
	VampyStrMsHook_LIB("libanogs.so", "0x96F35", IsEnable, old_IsEnable);///CASE16
	PATCH_LIB("libanogs.so", "0x46BAC", "00 00 A0 E3 1E FF 2F E1");///FIXCRASH LOBBY
//	PATCH_LIB("libanogs.so", "0xE3A14", "00 00 A0 E3 1E FF 2F E1");///FIX 10Y - 7D - 3D
//-	PATCH_LIB("libanogs.so", "0xFCCF0", "00 00 A0 E3 1E FF 2F E1");//memcheck branch
//	PATCH_LIB("libanogs.so", "0xFB7BC", "00 00 A0 E3 1E FF 2F E1");///memory branch checke
//	VampyStrMsHook_LIB("libanogs.so", "0x49725", hAnoSDKIoctlOld_0, AnoSDKIoctlOld_0);//LOGER CASE
//	PATCH_LIB("libanogs.so", "0xFCCF0", "00 00 A0 E3 1E FF 2F E1");//FIX MEMORY CHK
//	VampyStrMsHook_LIB("libanogs.so", "0x8E02D", hook_sub_8E02C, sub_8E02C);//CASE37
	VampyStrMsHook_LIB("libanogs.so", "0x33F58", myAnoSDKForExport_0, originalAnoSDKForExport_0);
   // HOOK_LIB("libanogs.so", "0x60B5C", hSub60B5C, oSub60B5C);
    PATCH_LIB("libUE4.so", "0x38D938C", "64 09 A0 E3 1E FF 2F E1");//emulator bypass
   // VampyStrMsHook_LIB("libanogs.so", "0x27A94E", hsub_27A94E, osub_27A94E);
	//VampyStrMsHook_LIB("libanogs.so", "0x28C1E0", hsub_28C1E0, sub_28C1E0);
	VampyStrMsHook_LIB("libanogs.so", "0x244F1E", hsub_244F1E, sub_244F1E);
	VampyStrMsHook_LIB("libanogs.so", "0x2463E0", hsub_2463E0, sub_2463E0);
    VampyStrMsHook_LIB("libanogs.so", "0x246720", hsub_246720, sub_246720);
	VampyStrMsHook_LIB("libanogs.so", "0x28BE90", hooked_sub_28BE90, original_sub_28BE90);
	  return NULL;
}

    __attribute__((constructor)) void Vampy_init() {
		
        pthread_create(&ptid, 0, main_thread, 0);
    }
  