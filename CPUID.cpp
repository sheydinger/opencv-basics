#include <string.h>
#include <stdio.h>

static inline void native_cpuid(
    unsigned int *eax, 
    unsigned int *ebx,
    unsigned int *ecx, 
    unsigned int *edx)
{
    /* ecx is often an input as well as an output. */
    asm volatile("cpuid"
        : "=a" (*eax),
        "=b" (*ebx),
        "=c" (*ecx),
        "=d" (*edx)
        : "0" (*eax), "2" (*ecx)
        : "memory");
}


int main()
{
    // Show some basic data about the CPU using the cpuid instruction.
    unsigned int eax, ebx, ecx, edx;
    
    printf("See https://en.wikipedia.org/wiki/CPUID\n");
    

    // VENDOR ID
    // ---------
    
    printf("\neax: 0, vendor id\n");

    // The value in the eax register indicates which information to return.
    // Calling cpuid with eax = 0 returns the vendor name in ebx, edx, ecx,
    // and the highest function supported in eax.
    eax = 0;
    
    native_cpuid(&eax, &ebx, &ecx, &edx);
    printf("    EAX: %08X EBX: %08X ECX: %08X EDX: %08X\n\n", eax, ebx, ecx, edx);
    char vendor[13];
    memcpy(vendor, &ebx, 4);
    memcpy(vendor+4, &edx, 4);
    memcpy(vendor+8, &ecx, 4);
    vendor[12] = '\0';
    printf("    Vendor:                                                     %s\n", vendor);
    printf("    Highest function supported:                                 %d\n", eax);

    
    // PROCESSOR FEATURES
    // ------------------
    
    printf("\neax: 1, processor features\n");
    
    // Calling with eax = 1 returns features, with specific bits shown in
    // the defines.
    eax = 1;

    native_cpuid(&eax, &ebx, &ecx, &edx);
    printf("    EAX: %08X EBX: %08X ECX: %08X EDX: %08X\n\n", eax, ebx, ecx, edx);
    
    printf("    Supplemental SSE3                                           %s\n", ecx & (0x00000001 <<  0) ? "yes" : "no");
    printf("    SSE 4.1                                                     %s\n", ecx & (0x00000001 << 19) ? "yes" : "no");
    printf("    SSE 4.2                                                     %s\n", ecx & (0x00000001 << 20) ? "yes" : "no");
    printf("    POPCNT                                                      %s\n", ecx & (0x00000001 << 23) ? "yes" : "no");
    printf("    AVX                                                         %s\n", ecx & (0x00000001 << 28) ? "yes" : "no");
    printf("    MMX Instructions                                            %s\n", edx & (0x00000001 << 23) ? "yes" : "no");
    printf("    SSE                                                         %s\n", edx & (0x00000001 << 25) ? "yes" : "no");
    printf("    SSE2                                                        %s\n", edx & (0x00000001 << 26) ? "yes" : "no");


    // EXTENDED FEATURES
    // -----------------
    
    printf("\neax: 7 ecx: 0, extended features\n");
    
    eax = 7;
    ecx = 0;
    native_cpuid(&eax, &ebx, &ecx, &edx);
    printf("    EAX: %08X EBX: %08X ECX: %08X EDX: %08X\n\n", eax, ebx, ecx, edx);
    
    printf("    avx2            Advanced Vector Extensions 2                %s\n", ebx & (0x00000001 <<  5) ? "yes" : "no");
    printf("    avx512f         AVX-512 Foundation                          %s\n", ebx & (0x00000001 << 16) ? "yes" : "no");
    printf("    avx512dq        AVX-512 Double/Quad Word Inst.              %s\n", ebx & (0x00000001 << 17) ? "yes" : "no");
    printf("    avx512ifma      AVX-512 Integer Fused Multiply Add Inst.    %s\n", ebx & (0x00000001 << 21) ? "yes" : "no");
    printf("    avx512bw        AVX-512 Byte & Word Inst.                   %s\n", ebx & (0x00000001 << 30) ? "yes" : "no");
    printf("    avx512vi        AVX-512 Vector Length Extensions            %s\n", ebx & (0x00000001 << 31) ? "yes" : "no");
    
    printf("    avx512vbmi      AVX-512 Vector Bit Manipulation Inst.       %s\n", ecx & (0x00000001 <<  1) ? "yes" : "no");
    printf("    avx512vbmi2     AVX-512 Vector Bit Maniuplation Inst. 2     %s\n", ecx & (0x00000001 <<  6) ? "yes" : "no");
    printf("    avx512vnni      AVX-512 Vector Neural Network Inst.         %s\n", ecx & (0x00000001 << 11) ? "yes" : "no");
    printf("    avx512bitalg    AVX-512 BITALG Inst.                        %s\n", ecx & (0x00000001 << 12) ? "yes" : "no");
    printf("    avx512vpopcntdq AVX-512 Vector Population Count Double/Quad %s\n", ecx & (0x00000001 << 14) ? "yes" : "no");

    return 0;
}
