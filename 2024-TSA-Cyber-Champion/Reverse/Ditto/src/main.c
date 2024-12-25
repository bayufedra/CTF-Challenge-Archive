#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <dirent.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <link.h>
#include <libgen.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <openssl/md5.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Shdr Elf64_Shdr
#define Elf_Sym  Elf64_Sym
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Shdr Elf32_Shdr
#define Elf_Sym  Elf32_Sym
#endif

char binary_path[512];

const char *md5(const char *str) {
    static char buf[33];
    unsigned char digest[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, str, strlen(str));
    MD5_Final(digest, &ctx);
    for (int i = 0; i < 16; i++) {
        sprintf(buf + i * 2, "%02x", digest[i]);
    }
    return buf;
}

uintptr_t get_base_address(const char *name) {
    FILE *f = fopen("/proc/self/maps", "r");
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, name)) {
            uintptr_t start, end;
            sscanf(line, "%lx-%lx", &start, &end);
            fclose(f);
            return start;
        }
    }
    fclose(f);

    return 0;
}

void decrypt(const char *section_name, const char *key) {
    int fd = open(binary_path, O_RDONLY);
    if (fd == -1) {
        return 0;
    }
    uintptr_t base_address = get_base_address(basename(binary_path)); 

    Elf_Ehdr ehdr;
    read(fd, &ehdr, sizeof(Elf_Ehdr));

    Elf_Shdr shdr;
    lseek(fd, ehdr.e_shoff + ehdr.e_shstrndx * sizeof(Elf_Shdr), SEEK_SET);
    read(fd, &shdr, sizeof(Elf_Shdr));

    char *shstrtab = (char *) malloc(shdr.sh_size);
    lseek(fd, shdr.sh_offset, SEEK_SET);
    read(fd, shstrtab, shdr.sh_size);

    lseek(fd, ehdr.e_shoff, SEEK_SET);
    for (int i = 0; i < ehdr.e_shnum; i++) {
        read(fd, &shdr, sizeof(Elf_Shdr));
        const char *name = shstrtab + shdr.sh_name;
        if (!strcmp(name, section_name)) {
            uint8_t *data = (uint8_t *) ((uintptr_t) base_address + shdr.sh_addr);
            size_t len = shdr.sh_size;

            uintptr_t page = (uintptr_t) sysconf(_SC_PAGESIZE);
            void *start = (void *) ((uintptr_t) data - ((uintptr_t) data % page));
            size_t size = len + ((uintptr_t) data % page);
            if (size % (size_t) page) {
                size += page - (size % page);
            }

            mprotect(start, size, PROT_READ | PROT_WRITE | PROT_EXEC);
            for (int j = 0; j < len; j++) {
                data[j] ^= key[j % strlen(key)];
            }
            mprotect(start, size, PROT_READ | PROT_EXEC);
            break;
        }
    }

    free(shstrtab);
    close(fd);
}

__attribute__((section(".cfcd208495d565ef66e7dff9f98764da")))void process0(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "T"
    unsigned char enc[2] = { 0xAB, 0x6F };
    
    for (unsigned int ydKFi = 0, TGphK = 0; ydKFi < 2; ydKFi++)
    {
    	TGphK = enc[ydKFi];
    	TGphK --;
    	TGphK = (((TGphK & 0xFF) >> 4) | (TGphK << 4)) & 0xFF;
    	TGphK ^= ydKFi;
    	TGphK -= 0xF4;
    	TGphK = (((TGphK & 0xFF) >> 7) | (TGphK << 1)) & 0xFF;
    	TGphK -= ydKFi;
    	TGphK = ((TGphK << 5) | ( (TGphK & 0xFF) >> 3)) & 0xFF;
    	TGphK -= 0x50;
    	TGphK += ydKFi;
    	TGphK += 0xB9;
    	TGphK ^= ydKFi;
    	TGphK = (((TGphK & 0xFF) >> 6) | (TGphK << 2)) & 0xFF;
    	TGphK += 0x56;
    	TGphK ^= 0x49;
    	TGphK += 0x56;
    	TGphK = (((TGphK & 0xFF) >> 3) | (TGphK << 5)) & 0xFF;
    	TGphK -= 0x48;
    	TGphK -= ydKFi;
    	TGphK -= 0x3A;
    	TGphK = ((TGphK << 4) | ( (TGphK & 0xFF) >> 4)) & 0xFF;
    	TGphK += ydKFi;
    	TGphK ^= 0xDC;
    	TGphK = (((TGphK & 0xFF) >> 5) | (TGphK << 3)) & 0xFF;
    	TGphK -= 0x81;
    	TGphK = ~TGphK;
    	TGphK ^= 0xF6;
    	TGphK -= 0x90;
    	TGphK += ydKFi;
    	TGphK --;
    	TGphK ^= 0xBE;
    	TGphK = ((TGphK << 5) | ( (TGphK & 0xFF) >> 3)) & 0xFF;
    	TGphK += 0x49;
    	TGphK ^= ydKFi;
    	TGphK ^= 0x5F;
    	TGphK = ((TGphK << 5) | ( (TGphK & 0xFF) >> 3)) & 0xFF;
    	TGphK += 0x39;
    	TGphK ^= ydKFi;
    	TGphK = (((TGphK & 0xFF) >> 6) | (TGphK << 2)) & 0xFF;
    	TGphK ^= ydKFi;
    	TGphK += 0x75;
    	TGphK += ydKFi;
    	TGphK ^= ydKFi;
    	TGphK += ydKFi;
    	TGphK ^= 0x50;
    	TGphK += ydKFi;
    	TGphK = (((TGphK & 0xFF) >> 3) | (TGphK << 5)) & 0xFF;
    	TGphK -= 0x3A;
    	TGphK = ~TGphK;
    	TGphK += ydKFi;
    	TGphK ++;
    	enc[ydKFi] = TGphK;
    }
    
    if (enc[0] == c) {
        decrypt(".c4ca4238a0b923820dcc509a6f75849b", md5(enc));
    }
}

__attribute__((section(".c4ca4238a0b923820dcc509a6f75849b")))void process1(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "S"
    unsigned char enc[2] = { 0xA2, 0x7B };
    
    for (unsigned int rlxVU = 0, rYbfL = 0; rlxVU < 2; rlxVU++)
    {
    	rYbfL = enc[rlxVU];
    	rYbfL --;
    	rYbfL -= rlxVU;
    	rYbfL = (((rYbfL & 0xFF) >> 3) | (rYbfL << 5)) & 0xFF;
    	rYbfL ^= rlxVU;
    	rYbfL --;
    	rYbfL ^= rlxVU;
    	rYbfL -= 0x2C;
    	rYbfL = ~rYbfL;
    	rYbfL ^= rlxVU;
    	rYbfL -= 0x89;
    	rYbfL = ~rYbfL;
    	rYbfL ^= 0xE6;
    	rYbfL --;
    	rYbfL = ~rYbfL;
    	rYbfL = (((rYbfL & 0xFF) >> 4) | (rYbfL << 4)) & 0xFF;
    	rYbfL ^= rlxVU;
    	rYbfL ++;
    	rYbfL = (((rYbfL & 0xFF) >> 4) | (rYbfL << 4)) & 0xFF;
    	rYbfL -= 0x78;
    	rYbfL -= rlxVU;
    	rYbfL = ((rYbfL << 7) | ( (rYbfL & 0xFF) >> 1)) & 0xFF;
    	rYbfL --;
    	rYbfL -= rlxVU;
    	rYbfL = ((rYbfL << 3) | ( (rYbfL & 0xFF) >> 5)) & 0xFF;
    	rYbfL ^= 0x28;
    	rYbfL -= rlxVU;
    	rYbfL --;
    	rYbfL = (((rYbfL & 0xFF) >> 1) | (rYbfL << 7)) & 0xFF;
    	rYbfL --;
    	rYbfL ^= rlxVU;
    	rYbfL = (((rYbfL & 0xFF) >> 4) | (rYbfL << 4)) & 0xFF;
    	rYbfL += 0x33;
    	rYbfL = ~rYbfL;
    	rYbfL --;
    	rYbfL ^= rlxVU;
    	rYbfL --;
    	rYbfL ^= rlxVU;
    	rYbfL ++;
    	rYbfL = ((rYbfL << 2) | ( (rYbfL & 0xFF) >> 6)) & 0xFF;
    	rYbfL = ~rYbfL;
    	rYbfL = (((rYbfL & 0xFF) >> 5) | (rYbfL << 3)) & 0xFF;
    	rYbfL = ~rYbfL;
    	rYbfL ++;
    	rYbfL ^= 0xF3;
    	rYbfL += 0x03;
    	rYbfL = ((rYbfL << 3) | ( (rYbfL & 0xFF) >> 5)) & 0xFF;
    	rYbfL --;
    	rYbfL ^= 0xF6;
    	rYbfL = ((rYbfL << 7) | ( (rYbfL & 0xFF) >> 1)) & 0xFF;
    	rYbfL ^= rlxVU;
    	enc[rlxVU] = rYbfL;
    }
    
    if (enc[0] == c) {
        decrypt(".c81e728d9d4c2f636f067f89cc14862c", md5(enc));
    }
}

__attribute__((section(".c81e728d9d4c2f636f067f89cc14862c")))void process2(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "A"
    unsigned char enc[2] = { 0x99, 0x5B };
    
    for (unsigned int GYxNf = 0, YTRyP = 0; GYxNf < 2; GYxNf++)
    {
    	YTRyP = enc[GYxNf];
    	YTRyP -= 0x28;
    	YTRyP -= GYxNf;
    	YTRyP ^= GYxNf;
    	YTRyP ++;
    	YTRyP -= GYxNf;
    	YTRyP = ((YTRyP << 6) | ( (YTRyP & 0xFF) >> 2)) & 0xFF;
    	YTRyP ^= GYxNf;
    	YTRyP += GYxNf;
    	YTRyP -= 0xA5;
    	YTRyP = ~YTRyP;
    	YTRyP += GYxNf;
    	YTRyP = ((YTRyP << 7) | ( (YTRyP & 0xFF) >> 1)) & 0xFF;
    	YTRyP ^= 0x20;
    	YTRyP += GYxNf;
    	YTRyP = ~YTRyP;
    	YTRyP = ((YTRyP << 1) | ( (YTRyP & 0xFF) >> 7)) & 0xFF;
    	YTRyP = ~YTRyP;
    	YTRyP += GYxNf;
    	YTRyP = ~YTRyP;
    	YTRyP -= 0x95;
    	YTRyP = (((YTRyP & 0xFF) >> 3) | (YTRyP << 5)) & 0xFF;
    	YTRyP += GYxNf;
    	YTRyP ++;
    	YTRyP ^= GYxNf;
    	YTRyP ++;
    	YTRyP = ((YTRyP << 1) | ( (YTRyP & 0xFF) >> 7)) & 0xFF;
    	YTRyP = ~YTRyP;
    	YTRyP -= 0xCB;
    	YTRyP -= GYxNf;
    	YTRyP --;
    	YTRyP -= GYxNf;
    	YTRyP ^= 0xEA;
    	YTRyP += GYxNf;
    	YTRyP = ((YTRyP << 7) | ( (YTRyP & 0xFF) >> 1)) & 0xFF;
    	YTRyP += 0x0A;
    	YTRyP += GYxNf;
    	YTRyP = ~YTRyP;
    	YTRyP += GYxNf;
    	YTRyP --;
    	YTRyP -= GYxNf;
    	YTRyP = ((YTRyP << 3) | ( (YTRyP & 0xFF) >> 5)) & 0xFF;
    	YTRyP += GYxNf;
    	YTRyP ^= GYxNf;
    	YTRyP --;
    	YTRyP ^= GYxNf;
    	YTRyP --;
    	YTRyP = (((YTRyP & 0xFF) >> 5) | (YTRyP << 3)) & 0xFF;
    	YTRyP ++;
    	YTRyP = (((YTRyP & 0xFF) >> 1) | (YTRyP << 7)) & 0xFF;
    	YTRyP --;
    	enc[GYxNf] = YTRyP;
    }
    
    if (enc[0] == c) {
        decrypt(".eccbc87e4b5ce2fe28308fd9f2a7baf3", md5(enc));
    }
}

__attribute__((section(".eccbc87e4b5ce2fe28308fd9f2a7baf3")))void process3(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "{"
    unsigned char enc[2] = { 0x8F, 0x42 };
    
    for (unsigned int MWiwC = 0, TNABs = 0; MWiwC < 2; MWiwC++)
    {
    	TNABs = enc[MWiwC];
    	TNABs = ((TNABs << 4) | ( (TNABs & 0xFF) >> 4)) & 0xFF;
    	TNABs --;
    	TNABs = ((TNABs << 2) | ( (TNABs & 0xFF) >> 6)) & 0xFF;
    	TNABs -= 0x24;
    	TNABs ^= MWiwC;
    	TNABs = ~TNABs;
    	TNABs -= 0x99;
    	TNABs ^= 0x6B;
    	TNABs = ~TNABs;
    	TNABs -= 0xE7;
    	TNABs += MWiwC;
    	TNABs --;
    	TNABs ^= MWiwC;
    	TNABs --;
    	TNABs = ~TNABs;
    	TNABs ^= 0xEB;
    	TNABs += 0x7B;
    	TNABs += MWiwC;
    	TNABs ^= 0xAD;
    	TNABs -= 0xD7;
    	TNABs = ((TNABs << 5) | ( (TNABs & 0xFF) >> 3)) & 0xFF;
    	TNABs -= 0x49;
    	TNABs = (((TNABs & 0xFF) >> 6) | (TNABs << 2)) & 0xFF;
    	TNABs -= MWiwC;
    	TNABs ^= 0xE4;
    	TNABs -= 0x4A;
    	TNABs = ((TNABs << 3) | ( (TNABs & 0xFF) >> 5)) & 0xFF;
    	TNABs ^= MWiwC;
    	TNABs ++;
    	TNABs = (((TNABs & 0xFF) >> 1) | (TNABs << 7)) & 0xFF;
    	TNABs ^= MWiwC;
    	TNABs += 0xBB;
    	TNABs = ~TNABs;
    	TNABs --;
    	TNABs -= MWiwC;
    	TNABs = (((TNABs & 0xFF) >> 1) | (TNABs << 7)) & 0xFF;
    	TNABs ++;
    	TNABs ^= 0x52;
    	TNABs -= MWiwC;
    	TNABs ^= 0x03;
    	TNABs ^= MWiwC;
    	TNABs += 0xFC;
    	TNABs = (((TNABs & 0xFF) >> 2) | (TNABs << 6)) & 0xFF;
    	TNABs -= 0xBA;
    	TNABs += MWiwC;
    	TNABs += 0x74;
    	TNABs = ~TNABs;
    	TNABs -= MWiwC;
    	TNABs ++;
    	TNABs = (((TNABs & 0xFF) >> 2) | (TNABs << 6)) & 0xFF;
    	enc[MWiwC] = TNABs;
    }
    
    if (enc[0] == c) {
        decrypt(".a87ff679a2f3e71d9181a67b7542122c", md5(enc));
    }
}

__attribute__((section(".a87ff679a2f3e71d9181a67b7542122c")))void process4(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "N"
    unsigned char enc[2] = { 0xEB, 0xDB };
    
    for (unsigned int JQEtR = 0, mlzeR = 0; JQEtR < 2; JQEtR++)
    {
    	mlzeR = enc[JQEtR];
    	mlzeR -= 0x4A;
    	mlzeR -= JQEtR;
    	mlzeR = ~mlzeR;
    	mlzeR ^= JQEtR;
    	mlzeR ++;
    	mlzeR = ((mlzeR << 1) | ( (mlzeR & 0xFF) >> 7)) & 0xFF;
    	mlzeR += 0x1B;
    	mlzeR += JQEtR;
    	mlzeR ^= JQEtR;
    	mlzeR -= JQEtR;
    	mlzeR = ~mlzeR;
    	mlzeR += JQEtR;
    	mlzeR ^= 0x4A;
    	mlzeR -= 0x06;
    	mlzeR = (((mlzeR & 0xFF) >> 1) | (mlzeR << 7)) & 0xFF;
    	mlzeR += JQEtR;
    	mlzeR ++;
    	mlzeR = ((mlzeR << 6) | ( (mlzeR & 0xFF) >> 2)) & 0xFF;
    	mlzeR = ~mlzeR;
    	mlzeR = (((mlzeR & 0xFF) >> 2) | (mlzeR << 6)) & 0xFF;
    	mlzeR ^= JQEtR;
    	mlzeR = ((mlzeR << 4) | ( (mlzeR & 0xFF) >> 4)) & 0xFF;
    	mlzeR -= 0x91;
    	mlzeR ^= 0xDA;
    	mlzeR = (((mlzeR & 0xFF) >> 2) | (mlzeR << 6)) & 0xFF;
    	mlzeR ++;
    	mlzeR = ((mlzeR << 5) | ( (mlzeR & 0xFF) >> 3)) & 0xFF;
    	mlzeR ^= 0xFB;
    	mlzeR --;
    	mlzeR = (((mlzeR & 0xFF) >> 1) | (mlzeR << 7)) & 0xFF;
    	mlzeR -= JQEtR;
    	mlzeR ^= 0x4D;
    	mlzeR --;
    	mlzeR = ~mlzeR;
    	mlzeR ^= 0x41;
    	mlzeR ++;
    	mlzeR -= JQEtR;
    	mlzeR = ((mlzeR << 2) | ( (mlzeR & 0xFF) >> 6)) & 0xFF;
    	mlzeR ^= 0xDA;
    	mlzeR += JQEtR;
    	mlzeR ^= 0x6E;
    	mlzeR = ~mlzeR;
    	mlzeR -= JQEtR;
    	mlzeR --;
    	mlzeR = ((mlzeR << 2) | ( (mlzeR & 0xFF) >> 6)) & 0xFF;
    	mlzeR = ~mlzeR;
    	mlzeR += JQEtR;
    	mlzeR = ((mlzeR << 4) | ( (mlzeR & 0xFF) >> 4)) & 0xFF;
    	mlzeR --;
    	mlzeR += JQEtR;
    	enc[JQEtR] = mlzeR;
    }
    
    if (enc[0] == c) {
        decrypt(".e4da3b7fbbce2345d7772b0674a318d5", md5(enc));
    }
}

__attribute__((section(".e4da3b7fbbce2345d7772b0674a318d5")))void process5(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "1"
    unsigned char enc[2] = { 0xFB, 0x0F };
    
    for (unsigned int wUmhx = 0, RICiE = 0; wUmhx < 2; wUmhx++)
    {
    	RICiE = enc[wUmhx];
    	RICiE -= 0x39;
    	RICiE = ~RICiE;
    	RICiE -= 0xB0;
    	RICiE += wUmhx;
    	RICiE ^= 0x92;
    	RICiE = ~RICiE;
    	RICiE --;
    	RICiE = (((RICiE & 0xFF) >> 4) | (RICiE << 4)) & 0xFF;
    	RICiE -= 0xE3;
    	RICiE = (((RICiE & 0xFF) >> 6) | (RICiE << 2)) & 0xFF;
    	RICiE ^= 0xF7;
    	RICiE ++;
    	RICiE = ((RICiE << 3) | ( (RICiE & 0xFF) >> 5)) & 0xFF;
    	RICiE -= 0x05;
    	RICiE = ((RICiE << 1) | ( (RICiE & 0xFF) >> 7)) & 0xFF;
    	RICiE += 0x9F;
    	RICiE -= wUmhx;
    	RICiE += 0xEE;
    	RICiE = ((RICiE << 6) | ( (RICiE & 0xFF) >> 2)) & 0xFF;
    	RICiE += 0x3E;
    	RICiE ^= 0x46;
    	RICiE += wUmhx;
    	RICiE ^= wUmhx;
    	RICiE -= 0x81;
    	RICiE -= wUmhx;
    	RICiE ++;
    	RICiE = (((RICiE & 0xFF) >> 6) | (RICiE << 2)) & 0xFF;
    	RICiE --;
    	RICiE -= wUmhx;
    	RICiE ++;
    	RICiE -= wUmhx;
    	RICiE = ~RICiE;
    	RICiE += wUmhx;
    	RICiE = (((RICiE & 0xFF) >> 6) | (RICiE << 2)) & 0xFF;
    	RICiE += 0xD7;
    	RICiE += wUmhx;
    	RICiE = ~RICiE;
    	RICiE = ((RICiE << 7) | ( (RICiE & 0xFF) >> 1)) & 0xFF;
    	RICiE -= wUmhx;
    	RICiE = ((RICiE << 7) | ( (RICiE & 0xFF) >> 1)) & 0xFF;
    	RICiE ++;
    	RICiE += wUmhx;
    	RICiE -= 0xB9;
    	RICiE = ~RICiE;
    	RICiE = (((RICiE & 0xFF) >> 6) | (RICiE << 2)) & 0xFF;
    	RICiE ^= wUmhx;
    	RICiE -= 0x5C;
    	RICiE += wUmhx;
    	RICiE ^= wUmhx;
    	RICiE -= 0xB6;
    	enc[wUmhx] = RICiE;
    }
    
    if (enc[0] == c) {
        decrypt(".1679091c5a880faf6fb5e6087eb1b2dc", md5(enc));
    }
}

__attribute__((section(".1679091c5a880faf6fb5e6087eb1b2dc")))void process6(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "c"
    unsigned char enc[2] = { 0xDF, 0xB4 };
    
    for (unsigned int elYAR = 0, bZUGh = 0; elYAR < 2; elYAR++)
    {
    	bZUGh = enc[elYAR];
    	bZUGh ++;
    	bZUGh ^= elYAR;
    	bZUGh ++;
    	bZUGh = ~bZUGh;
    	bZUGh ^= elYAR;
    	bZUGh ^= 0xE7;
    	bZUGh = ((bZUGh << 2) | ( (bZUGh & 0xFF) >> 6)) & 0xFF;
    	bZUGh -= 0x93;
    	bZUGh = (((bZUGh & 0xFF) >> 1) | (bZUGh << 7)) & 0xFF;
    	bZUGh -= 0x19;
    	bZUGh -= elYAR;
    	bZUGh --;
    	bZUGh = ((bZUGh << 7) | ( (bZUGh & 0xFF) >> 1)) & 0xFF;
    	bZUGh ++;
    	bZUGh += elYAR;
    	bZUGh ^= elYAR;
    	bZUGh = ((bZUGh << 1) | ( (bZUGh & 0xFF) >> 7)) & 0xFF;
    	bZUGh ++;
    	bZUGh += elYAR;
    	bZUGh ^= elYAR;
    	bZUGh --;
    	bZUGh ^= 0x24;
    	bZUGh += 0x87;
    	bZUGh += elYAR;
    	bZUGh ^= 0xD6;
    	bZUGh -= elYAR;
    	bZUGh = ((bZUGh << 4) | ( (bZUGh & 0xFF) >> 4)) & 0xFF;
    	bZUGh -= elYAR;
    	bZUGh = ((bZUGh << 6) | ( (bZUGh & 0xFF) >> 2)) & 0xFF;
    	bZUGh ^= 0xC8;
    	bZUGh ++;
    	bZUGh = (((bZUGh & 0xFF) >> 7) | (bZUGh << 1)) & 0xFF;
    	bZUGh -= 0x1C;
    	bZUGh = ((bZUGh << 3) | ( (bZUGh & 0xFF) >> 5)) & 0xFF;
    	bZUGh --;
    	bZUGh += elYAR;
    	bZUGh = ~bZUGh;
    	bZUGh --;
    	bZUGh = ~bZUGh;
    	bZUGh --;
    	bZUGh = ~bZUGh;
    	bZUGh += 0xCF;
    	bZUGh -= elYAR;
    	bZUGh ^= 0x3B;
    	bZUGh += elYAR;
    	bZUGh = ((bZUGh << 6) | ( (bZUGh & 0xFF) >> 2)) & 0xFF;
    	bZUGh ^= elYAR;
    	bZUGh -= 0xF9;
    	bZUGh ^= elYAR;
    	bZUGh -= elYAR;
    	enc[elYAR] = bZUGh;
    }
    
    if (enc[0] == c) {
        decrypt(".8f14e45fceea167a5a36dedd4bea2543", md5(enc));
    }
}

__attribute__((section(".8f14e45fceea167a5a36dedd4bea2543")))void process7(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "3"
    unsigned char enc[2] = { 0x14, 0x93 };
    
    for (unsigned int NEqLd = 0, lWqgy = 0; NEqLd < 2; NEqLd++)
    {
    	lWqgy = enc[NEqLd];
    	lWqgy = (((lWqgy & 0xFF) >> 5) | (lWqgy << 3)) & 0xFF;
    	lWqgy -= NEqLd;
    	lWqgy ^= NEqLd;
    	lWqgy ^= 0x7D;
    	lWqgy ^= NEqLd;
    	lWqgy += 0x45;
    	lWqgy = ~lWqgy;
    	lWqgy ^= 0x50;
    	lWqgy += NEqLd;
    	lWqgy = (((lWqgy & 0xFF) >> 2) | (lWqgy << 6)) & 0xFF;
    	lWqgy ^= NEqLd;
    	lWqgy ++;
    	lWqgy = ((lWqgy << 5) | ( (lWqgy & 0xFF) >> 3)) & 0xFF;
    	lWqgy ^= NEqLd;
    	lWqgy = ((lWqgy << 1) | ( (lWqgy & 0xFF) >> 7)) & 0xFF;
    	lWqgy += NEqLd;
    	lWqgy = ((lWqgy << 5) | ( (lWqgy & 0xFF) >> 3)) & 0xFF;
    	lWqgy += 0x58;
    	lWqgy ^= NEqLd;
    	lWqgy --;
    	lWqgy = (((lWqgy & 0xFF) >> 6) | (lWqgy << 2)) & 0xFF;
    	lWqgy -= NEqLd;
    	lWqgy += 0x38;
    	lWqgy = ~lWqgy;
    	lWqgy ^= NEqLd;
    	lWqgy = ~lWqgy;
    	lWqgy -= NEqLd;
    	lWqgy = ((lWqgy << 4) | ( (lWqgy & 0xFF) >> 4)) & 0xFF;
    	lWqgy = ~lWqgy;
    	lWqgy ^= NEqLd;
    	lWqgy = ~lWqgy;
    	lWqgy = ((lWqgy << 7) | ( (lWqgy & 0xFF) >> 1)) & 0xFF;
    	lWqgy ++;
    	lWqgy = (((lWqgy & 0xFF) >> 4) | (lWqgy << 4)) & 0xFF;
    	lWqgy --;
    	lWqgy ^= NEqLd;
    	lWqgy --;
    	lWqgy = ((lWqgy << 1) | ( (lWqgy & 0xFF) >> 7)) & 0xFF;
    	lWqgy --;
    	lWqgy ^= 0x57;
    	lWqgy += NEqLd;
    	lWqgy += 0xA7;
    	lWqgy = ~lWqgy;
    	lWqgy ^= 0xE6;
    	lWqgy -= 0x3F;
    	lWqgy += NEqLd;
    	lWqgy += 0xE8;
    	lWqgy ^= 0x07;
    	lWqgy = ((lWqgy << 4) | ( (lWqgy & 0xFF) >> 4)) & 0xFF;
    	lWqgy += 0xF8;
    	enc[NEqLd] = lWqgy;
    }
    
    if (enc[0] == c) {
        decrypt(".c9f0f895fb98ab9159f51fd0297e236d", md5(enc));
    }
}

__attribute__((section(".c9f0f895fb98ab9159f51fd0297e236d")))void process8(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "_"
    unsigned char enc[2] = { 0x7B, 0xF3 };
    
    for (unsigned int xfDKQ = 0, iTknA = 0; xfDKQ < 2; xfDKQ++)
    {
    	iTknA = enc[xfDKQ];
    	iTknA -= xfDKQ;
    	iTknA -= 0x78;
    	iTknA = ~iTknA;
    	iTknA = ((iTknA << 3) | ( (iTknA & 0xFF) >> 5)) & 0xFF;
    	iTknA = ~iTknA;
    	iTknA -= 0xFF;
    	iTknA = (((iTknA & 0xFF) >> 4) | (iTknA << 4)) & 0xFF;
    	iTknA -= 0x67;
    	iTknA -= xfDKQ;
    	iTknA -= 0x7D;
    	iTknA += xfDKQ;
    	iTknA -= 0x09;
    	iTknA -= xfDKQ;
    	iTknA ^= 0x48;
    	iTknA --;
    	iTknA = ((iTknA << 4) | ( (iTknA & 0xFF) >> 4)) & 0xFF;
    	iTknA -= 0xB0;
    	iTknA = (((iTknA & 0xFF) >> 3) | (iTknA << 5)) & 0xFF;
    	iTknA ++;
    	iTknA ^= xfDKQ;
    	iTknA = (((iTknA & 0xFF) >> 6) | (iTknA << 2)) & 0xFF;
    	iTknA ^= 0x3C;
    	iTknA += xfDKQ;
    	iTknA = ~iTknA;
    	iTknA = ((iTknA << 1) | ( (iTknA & 0xFF) >> 7)) & 0xFF;
    	iTknA -= 0x06;
    	iTknA ^= xfDKQ;
    	iTknA ^= 0xBB;
    	iTknA -= xfDKQ;
    	iTknA ^= xfDKQ;
    	iTknA --;
    	iTknA = ~iTknA;
    	iTknA --;
    	iTknA ^= xfDKQ;
    	iTknA += 0x7E;
    	iTknA += xfDKQ;
    	iTknA = ((iTknA << 1) | ( (iTknA & 0xFF) >> 7)) & 0xFF;
    	iTknA -= 0x9A;
    	iTknA += xfDKQ;
    	iTknA = ((iTknA << 1) | ( (iTknA & 0xFF) >> 7)) & 0xFF;
    	iTknA -= xfDKQ;
    	iTknA ++;
    	iTknA ^= xfDKQ;
    	iTknA --;
    	iTknA ^= 0xAE;
    	iTknA = ~iTknA;
    	iTknA -= xfDKQ;
    	iTknA ^= 0xA7;
    	iTknA = ((iTknA << 6) | ( (iTknA & 0xFF) >> 2)) & 0xFF;
    	iTknA ^= 0xE2;
    	enc[xfDKQ] = iTknA;
    }
    
    if (enc[0] == c) {
        decrypt(".45c48cce2e2d7fbdea1afc51c7c6ad26", md5(enc));
    }
}

__attribute__((section(".45c48cce2e2d7fbdea1afc51c7c6ad26")))void process9(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "D"
    unsigned char enc[2] = { 0x68, 0x95 };
    
    for (unsigned int eCQAc = 0, aFJNt = 0; eCQAc < 2; eCQAc++)
    {
    	aFJNt = enc[eCQAc];
    	aFJNt ^= eCQAc;
    	aFJNt = (((aFJNt & 0xFF) >> 6) | (aFJNt << 2)) & 0xFF;
    	aFJNt -= 0xAE;
    	aFJNt = ((aFJNt << 2) | ( (aFJNt & 0xFF) >> 6)) & 0xFF;
    	aFJNt += eCQAc;
    	aFJNt --;
    	aFJNt = ((aFJNt << 3) | ( (aFJNt & 0xFF) >> 5)) & 0xFF;
    	aFJNt += 0xB2;
    	aFJNt = ~aFJNt;
    	aFJNt = (((aFJNt & 0xFF) >> 7) | (aFJNt << 1)) & 0xFF;
    	aFJNt = ~aFJNt;
    	aFJNt = ((aFJNt << 4) | ( (aFJNt & 0xFF) >> 4)) & 0xFF;
    	aFJNt += 0xA7;
    	aFJNt ^= 0xE8;
    	aFJNt = ~aFJNt;
    	aFJNt ++;
    	aFJNt ^= 0x87;
    	aFJNt ++;
    	aFJNt ^= 0xD6;
    	aFJNt -= eCQAc;
    	aFJNt = (((aFJNt & 0xFF) >> 2) | (aFJNt << 6)) & 0xFF;
    	aFJNt ++;
    	aFJNt -= eCQAc;
    	aFJNt -= 0xBD;
    	aFJNt ^= eCQAc;
    	aFJNt -= eCQAc;
    	aFJNt ^= eCQAc;
    	aFJNt = ((aFJNt << 3) | ( (aFJNt & 0xFF) >> 5)) & 0xFF;
    	aFJNt ^= 0x78;
    	aFJNt --;
    	aFJNt -= eCQAc;
    	aFJNt ++;
    	aFJNt ^= eCQAc;
    	aFJNt += 0x6E;
    	aFJNt = (((aFJNt & 0xFF) >> 7) | (aFJNt << 1)) & 0xFF;
    	aFJNt += 0xFE;
    	aFJNt = ~aFJNt;
    	aFJNt = (((aFJNt & 0xFF) >> 6) | (aFJNt << 2)) & 0xFF;
    	aFJNt ^= 0xE5;
    	aFJNt ^= eCQAc;
    	aFJNt -= 0xB9;
    	aFJNt = ~aFJNt;
    	aFJNt = ((aFJNt << 1) | ( (aFJNt & 0xFF) >> 7)) & 0xFF;
    	aFJNt = ~aFJNt;
    	aFJNt --;
    	aFJNt ^= eCQAc;
    	aFJNt += eCQAc;
    	aFJNt ++;
    	aFJNt += eCQAc;
    	aFJNt = (((aFJNt & 0xFF) >> 5) | (aFJNt << 3)) & 0xFF;
    	enc[eCQAc] = aFJNt;
    }
    
    if (enc[0] == c) {
        decrypt(".d3d9446802a44259755d38e6d163e820", md5(enc));
    }
}

__attribute__((section(".d3d9446802a44259755d38e6d163e820")))void process10(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "3"
    unsigned char enc[2] = { 0x10, 0x1A };
    
    for (unsigned int DdBHT = 0, PQBrH = 0; DdBHT < 2; DdBHT++)
    {
    	PQBrH = enc[DdBHT];
    	PQBrH = (((PQBrH & 0xFF) >> 7) | (PQBrH << 1)) & 0xFF;
    	PQBrH += 0x22;
    	PQBrH = ~PQBrH;
    	PQBrH -= 0x9E;
    	PQBrH = ~PQBrH;
    	PQBrH ++;
    	PQBrH -= DdBHT;
    	PQBrH = (((PQBrH & 0xFF) >> 2) | (PQBrH << 6)) & 0xFF;
    	PQBrH -= 0x4D;
    	PQBrH += DdBHT;
    	PQBrH = ~PQBrH;
    	PQBrH += 0xEA;
    	PQBrH = (((PQBrH & 0xFF) >> 5) | (PQBrH << 3)) & 0xFF;
    	PQBrH += DdBHT;
    	PQBrH ^= DdBHT;
    	PQBrH += 0x1B;
    	PQBrH -= DdBHT;
    	PQBrH ^= DdBHT;
    	PQBrH -= DdBHT;
    	PQBrH ++;
    	PQBrH = (((PQBrH & 0xFF) >> 4) | (PQBrH << 4)) & 0xFF;
    	PQBrH += 0x6C;
    	PQBrH -= DdBHT;
    	PQBrH += 0x6A;
    	PQBrH -= DdBHT;
    	PQBrH += 0x23;
    	PQBrH += DdBHT;
    	PQBrH = ((PQBrH << 4) | ( (PQBrH & 0xFF) >> 4)) & 0xFF;
    	PQBrH = ~PQBrH;
    	PQBrH ++;
    	PQBrH -= DdBHT;
    	PQBrH = (((PQBrH & 0xFF) >> 1) | (PQBrH << 7)) & 0xFF;
    	PQBrH --;
    	PQBrH ^= DdBHT;
    	PQBrH --;
    	PQBrH = ((PQBrH << 1) | ( (PQBrH & 0xFF) >> 7)) & 0xFF;
    	PQBrH -= DdBHT;
    	PQBrH ^= 0x7D;
    	PQBrH ++;
    	PQBrH ^= DdBHT;
    	PQBrH ++;
    	PQBrH ^= DdBHT;
    	PQBrH += 0x10;
    	PQBrH = ~PQBrH;
    	PQBrH --;
    	PQBrH ^= DdBHT;
    	PQBrH -= DdBHT;
    	PQBrH = ~PQBrH;
    	PQBrH --;
    	PQBrH -= DdBHT;
    	enc[DdBHT] = PQBrH;
    }
    
    if (enc[0] == c) {
        decrypt(".6512bd43d9caa6e02c990b0a82652dca", md5(enc));
    }
}

__attribute__((section(".6512bd43d9caa6e02c990b0a82652dca")))void process11(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "b"
    unsigned char enc[2] = { 0x7D, 0x97 };
    
    for (unsigned int FklSz = 0, uDEcf = 0; FklSz < 2; FklSz++)
    {
    	uDEcf = enc[FklSz];
    	uDEcf ^= 0x7B;
    	uDEcf = ~uDEcf;
    	uDEcf = ((uDEcf << 4) | ( (uDEcf & 0xFF) >> 4)) & 0xFF;
    	uDEcf ++;
    	uDEcf -= FklSz;
    	uDEcf += 0x9A;
    	uDEcf += FklSz;
    	uDEcf ^= FklSz;
    	uDEcf --;
    	uDEcf -= FklSz;
    	uDEcf = ~uDEcf;
    	uDEcf ++;
    	uDEcf = (((uDEcf & 0xFF) >> 6) | (uDEcf << 2)) & 0xFF;
    	uDEcf ^= FklSz;
    	uDEcf ^= 0x9B;
    	uDEcf ^= FklSz;
    	uDEcf += FklSz;
    	uDEcf = ((uDEcf << 6) | ( (uDEcf & 0xFF) >> 2)) & 0xFF;
    	uDEcf ^= FklSz;
    	uDEcf += 0x8A;
    	uDEcf ^= 0x96;
    	uDEcf = ((uDEcf << 6) | ( (uDEcf & 0xFF) >> 2)) & 0xFF;
    	uDEcf ^= 0x3C;
    	uDEcf += 0x77;
    	uDEcf = ~uDEcf;
    	uDEcf ^= FklSz;
    	uDEcf = ((uDEcf << 3) | ( (uDEcf & 0xFF) >> 5)) & 0xFF;
    	uDEcf = ~uDEcf;
    	uDEcf += FklSz;
    	uDEcf --;
    	uDEcf = (((uDEcf & 0xFF) >> 5) | (uDEcf << 3)) & 0xFF;
    	uDEcf ++;
    	uDEcf = (((uDEcf & 0xFF) >> 7) | (uDEcf << 1)) & 0xFF;
    	uDEcf ^= FklSz;
    	uDEcf ^= 0xF6;
    	uDEcf += 0x76;
    	uDEcf = ((uDEcf << 3) | ( (uDEcf & 0xFF) >> 5)) & 0xFF;
    	uDEcf --;
    	uDEcf ^= FklSz;
    	uDEcf ^= 0xF4;
    	uDEcf ^= FklSz;
    	uDEcf -= 0xF4;
    	uDEcf += FklSz;
    	uDEcf ^= 0x00;
    	uDEcf ^= FklSz;
    	uDEcf = ((uDEcf << 1) | ( (uDEcf & 0xFF) >> 7)) & 0xFF;
    	uDEcf --;
    	uDEcf -= FklSz;
    	uDEcf = ~uDEcf;
    	uDEcf ++;
    	enc[FklSz] = uDEcf;
    }
    
    if (enc[0] == c) {
        decrypt(".c20ad4d76fe97759aa27a0c99bff6710", md5(enc));
    }
}

__attribute__((section(".c20ad4d76fe97759aa27a0c99bff6710")))void process12(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "u"
    unsigned char enc[2] = { 0xB6, 0x4C };
    
    for (unsigned int TOQFU = 0, jcJNG = 0; TOQFU < 2; TOQFU++)
    {
    	jcJNG = enc[TOQFU];
    	jcJNG += TOQFU;
    	jcJNG ++;
    	jcJNG -= TOQFU;
    	jcJNG = ~jcJNG;
    	jcJNG ^= TOQFU;
    	jcJNG = ((jcJNG << 4) | ( (jcJNG & 0xFF) >> 4)) & 0xFF;
    	jcJNG ^= 0x3C;
    	jcJNG ++;
    	jcJNG = ~jcJNG;
    	jcJNG += 0x8C;
    	jcJNG = ~jcJNG;
    	jcJNG += TOQFU;
    	jcJNG = ~jcJNG;
    	jcJNG ++;
    	jcJNG = ~jcJNG;
    	jcJNG = (((jcJNG & 0xFF) >> 3) | (jcJNG << 5)) & 0xFF;
    	jcJNG ++;
    	jcJNG ^= TOQFU;
    	jcJNG += 0x7C;
    	jcJNG -= TOQFU;
    	jcJNG ^= 0x9D;
    	jcJNG += TOQFU;
    	jcJNG = ((jcJNG << 7) | ( (jcJNG & 0xFF) >> 1)) & 0xFF;
    	jcJNG += TOQFU;
    	jcJNG --;
    	jcJNG -= TOQFU;
    	jcJNG --;
    	jcJNG ^= TOQFU;
    	jcJNG -= TOQFU;
    	jcJNG --;
    	jcJNG = ((jcJNG << 5) | ( (jcJNG & 0xFF) >> 3)) & 0xFF;
    	jcJNG --;
    	jcJNG -= TOQFU;
    	jcJNG -= 0xDD;
    	jcJNG = (((jcJNG & 0xFF) >> 4) | (jcJNG << 4)) & 0xFF;
    	jcJNG ^= TOQFU;
    	jcJNG = (((jcJNG & 0xFF) >> 7) | (jcJNG << 1)) & 0xFF;
    	jcJNG ^= TOQFU;
    	jcJNG ^= 0xA3;
    	jcJNG ++;
    	jcJNG ^= 0x52;
    	jcJNG -= 0x12;
    	jcJNG ^= 0x4A;
    	jcJNG --;
    	jcJNG += TOQFU;
    	jcJNG -= 0x80;
    	jcJNG -= TOQFU;
    	jcJNG = (((jcJNG & 0xFF) >> 4) | (jcJNG << 4)) & 0xFF;
    	jcJNG += 0x8A;
    	jcJNG -= TOQFU;
    	enc[TOQFU] = jcJNG;
    }
    
    if (enc[0] == c) {
        decrypt(".c51ce410c124a10e0db5e4b97fc2af39", md5(enc));
    }
}

__attribute__((section(".c51ce410c124a10e0db5e4b97fc2af39")))void process13(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "g"
    unsigned char enc[2] = { 0xDF, 0x48 };
    
    for (unsigned int XFghY = 0, vAsMU = 0; XFghY < 2; XFghY++)
    {
    	vAsMU = enc[XFghY];
    	vAsMU -= 0x59;
    	vAsMU -= XFghY;
    	vAsMU = (((vAsMU & 0xFF) >> 4) | (vAsMU << 4)) & 0xFF;
    	vAsMU -= 0x1F;
    	vAsMU = ((vAsMU << 1) | ( (vAsMU & 0xFF) >> 7)) & 0xFF;
    	vAsMU ++;
    	vAsMU ^= 0x52;
    	vAsMU = ~vAsMU;
    	vAsMU = (((vAsMU & 0xFF) >> 2) | (vAsMU << 6)) & 0xFF;
    	vAsMU ^= XFghY;
    	vAsMU += XFghY;
    	vAsMU = ((vAsMU << 7) | ( (vAsMU & 0xFF) >> 1)) & 0xFF;
    	vAsMU --;
    	vAsMU += XFghY;
    	vAsMU -= 0x09;
    	vAsMU = ((vAsMU << 5) | ( (vAsMU & 0xFF) >> 3)) & 0xFF;
    	vAsMU ++;
    	vAsMU -= XFghY;
    	vAsMU += 0x90;
    	vAsMU = ~vAsMU;
    	vAsMU += XFghY;
    	vAsMU = ((vAsMU << 1) | ( (vAsMU & 0xFF) >> 7)) & 0xFF;
    	vAsMU -= 0x3B;
    	vAsMU = (((vAsMU & 0xFF) >> 7) | (vAsMU << 1)) & 0xFF;
    	vAsMU -= XFghY;
    	vAsMU = ((vAsMU << 1) | ( (vAsMU & 0xFF) >> 7)) & 0xFF;
    	vAsMU -= 0x4A;
    	vAsMU += XFghY;
    	vAsMU ^= 0xB3;
    	vAsMU --;
    	vAsMU = ~vAsMU;
    	vAsMU ++;
    	vAsMU = ~vAsMU;
    	vAsMU = (((vAsMU & 0xFF) >> 6) | (vAsMU << 2)) & 0xFF;
    	vAsMU = ~vAsMU;
    	vAsMU = ((vAsMU << 2) | ( (vAsMU & 0xFF) >> 6)) & 0xFF;
    	vAsMU -= 0xCB;
    	vAsMU ^= XFghY;
    	vAsMU ++;
    	vAsMU = ((vAsMU << 3) | ( (vAsMU & 0xFF) >> 5)) & 0xFF;
    	vAsMU ^= 0xCC;
    	vAsMU -= 0x22;
    	vAsMU -= XFghY;
    	vAsMU ^= XFghY;
    	vAsMU -= 0x50;
    	vAsMU = (((vAsMU & 0xFF) >> 4) | (vAsMU << 4)) & 0xFF;
    	vAsMU --;
    	vAsMU ^= XFghY;
    	vAsMU -= 0x3E;
    	vAsMU ^= XFghY;
    	enc[XFghY] = vAsMU;
    }
    
    if (enc[0] == c) {
        decrypt(".aab3238922bcc25a6f606eb525ffdc56", md5(enc));
    }
}

__attribute__((section(".aab3238922bcc25a6f606eb525ffdc56")))void process14(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "g"
    unsigned char enc[2] = { 0xAE, 0xB5 };
    
    for (unsigned int vscaD = 0, yOgWr = 0; vscaD < 2; vscaD++)
    {
    	yOgWr = enc[vscaD];
    	yOgWr ^= 0x54;
    	yOgWr --;
    	yOgWr += vscaD;
    	yOgWr ++;
    	yOgWr ^= vscaD;
    	yOgWr --;
    	yOgWr ^= vscaD;
    	yOgWr = ~yOgWr;
    	yOgWr ++;
    	yOgWr -= vscaD;
    	yOgWr -= 0x6F;
    	yOgWr ^= vscaD;
    	yOgWr ++;
    	yOgWr = ~yOgWr;
    	yOgWr -= vscaD;
    	yOgWr = ~yOgWr;
    	yOgWr -= 0x1F;
    	yOgWr ^= vscaD;
    	yOgWr = ((yOgWr << 2) | ( (yOgWr & 0xFF) >> 6)) & 0xFF;
    	yOgWr ^= vscaD;
    	yOgWr --;
    	yOgWr = ~yOgWr;
    	yOgWr += 0x71;
    	yOgWr -= vscaD;
    	yOgWr --;
    	yOgWr ^= 0xFC;
    	yOgWr = (((yOgWr & 0xFF) >> 7) | (yOgWr << 1)) & 0xFF;
    	yOgWr ^= vscaD;
    	yOgWr = (((yOgWr & 0xFF) >> 5) | (yOgWr << 3)) & 0xFF;
    	yOgWr += vscaD;
    	yOgWr ^= vscaD;
    	yOgWr -= vscaD;
    	yOgWr -= 0x54;
    	yOgWr = ((yOgWr << 5) | ( (yOgWr & 0xFF) >> 3)) & 0xFF;
    	yOgWr = ~yOgWr;
    	yOgWr ^= vscaD;
    	yOgWr = ~yOgWr;
    	yOgWr = ((yOgWr << 2) | ( (yOgWr & 0xFF) >> 6)) & 0xFF;
    	yOgWr -= 0x0D;
    	yOgWr -= vscaD;
    	yOgWr = (((yOgWr & 0xFF) >> 3) | (yOgWr << 5)) & 0xFF;
    	yOgWr ^= vscaD;
    	yOgWr = ~yOgWr;
    	yOgWr += vscaD;
    	yOgWr ++;
    	yOgWr ^= 0xA8;
    	yOgWr -= vscaD;
    	yOgWr = (((yOgWr & 0xFF) >> 3) | (yOgWr << 5)) & 0xFF;
    	yOgWr = ~yOgWr;
    	yOgWr -= vscaD;
    	enc[vscaD] = yOgWr;
    }
    
    if (enc[0] == c) {
        decrypt(".9bf31c7ff062936a96d3c8bd1f8f2ff3", md5(enc));
    }
}

__attribute__((section(".9bf31c7ff062936a96d3c8bd1f8f2ff3")))void process15(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "1"
    unsigned char enc[2] = { 0xA3, 0x68 };
    
    for (unsigned int HfLik = 0, geNFK = 0; HfLik < 2; HfLik++)
    {
    	geNFK = enc[HfLik];
    	geNFK --;
    	geNFK -= HfLik;
    	geNFK ++;
    	geNFK = ((geNFK << 6) | ( (geNFK & 0xFF) >> 2)) & 0xFF;
    	geNFK += 0x0C;
    	geNFK ^= 0xF7;
    	geNFK = (((geNFK & 0xFF) >> 3) | (geNFK << 5)) & 0xFF;
    	geNFK ^= 0xA4;
    	geNFK += 0xA2;
    	geNFK += HfLik;
    	geNFK -= 0xF5;
    	geNFK ^= 0x21;
    	geNFK = (((geNFK & 0xFF) >> 7) | (geNFK << 1)) & 0xFF;
    	geNFK = ~geNFK;
    	geNFK = ((geNFK << 6) | ( (geNFK & 0xFF) >> 2)) & 0xFF;
    	geNFK -= HfLik;
    	geNFK ++;
    	geNFK -= HfLik;
    	geNFK --;
    	geNFK = ((geNFK << 7) | ( (geNFK & 0xFF) >> 1)) & 0xFF;
    	geNFK -= HfLik;
    	geNFK ^= 0x87;
    	geNFK ^= HfLik;
    	geNFK -= 0x6C;
    	geNFK ^= HfLik;
    	geNFK += HfLik;
    	geNFK ++;
    	geNFK -= HfLik;
    	geNFK += 0x5D;
    	geNFK ^= HfLik;
    	geNFK -= 0x49;
    	geNFK ^= HfLik;
    	geNFK = ((geNFK << 6) | ( (geNFK & 0xFF) >> 2)) & 0xFF;
    	geNFK ^= HfLik;
    	geNFK = ((geNFK << 4) | ( (geNFK & 0xFF) >> 4)) & 0xFF;
    	geNFK -= 0x94;
    	geNFK = ((geNFK << 1) | ( (geNFK & 0xFF) >> 7)) & 0xFF;
    	geNFK = ~geNFK;
    	geNFK -= 0xDD;
    	geNFK = ((geNFK << 6) | ( (geNFK & 0xFF) >> 2)) & 0xFF;
    	geNFK += 0x4C;
    	geNFK ^= HfLik;
    	geNFK += 0x82;
    	geNFK -= HfLik;
    	geNFK += 0xA1;
    	geNFK -= HfLik;
    	geNFK += 0xAA;
    	geNFK -= HfLik;
    	geNFK --;
    	geNFK ^= 0xB1;
    	enc[HfLik] = geNFK;
    }
    
    if (enc[0] == c) {
        decrypt(".c74d97b01eae257e44aa9d5bade97baf", md5(enc));
    }
}

__attribute__((section(".c74d97b01eae257e44aa9d5bade97baf")))void process16(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "n"
    unsigned char enc[2] = { 0x9F, 0xC5 };
    
    for (unsigned int pJDiA = 0, SthTw = 0; pJDiA < 2; pJDiA++)
    {
    	SthTw = enc[pJDiA];
    	SthTw = ~SthTw;
    	SthTw = ((SthTw << 7) | ( (SthTw & 0xFF) >> 1)) & 0xFF;
    	SthTw ^= pJDiA;
    	SthTw ++;
    	SthTw = ~SthTw;
    	SthTw ++;
    	SthTw = (((SthTw & 0xFF) >> 3) | (SthTw << 5)) & 0xFF;
    	SthTw -= 0xFE;
    	SthTw = ~SthTw;
    	SthTw += 0x9A;
    	SthTw ^= 0x1A;
    	SthTw = ~SthTw;
    	SthTw ++;
    	SthTw -= pJDiA;
    	SthTw ++;
    	SthTw = ((SthTw << 3) | ( (SthTw & 0xFF) >> 5)) & 0xFF;
    	SthTw ++;
    	SthTw ^= 0x36;
    	SthTw -= 0xE5;
    	SthTw = ~SthTw;
    	SthTw ^= 0x8F;
    	SthTw ++;
    	SthTw ^= 0xBA;
    	SthTw = (((SthTw & 0xFF) >> 2) | (SthTw << 6)) & 0xFF;
    	SthTw = ~SthTw;
    	SthTw += 0x7F;
    	SthTw = ((SthTw << 3) | ( (SthTw & 0xFF) >> 5)) & 0xFF;
    	SthTw += pJDiA;
    	SthTw ++;
    	SthTw ^= 0xCF;
    	SthTw += 0x38;
    	SthTw = ~SthTw;
    	SthTw ^= pJDiA;
    	SthTw += pJDiA;
    	SthTw ^= pJDiA;
    	SthTw --;
    	SthTw = ((SthTw << 4) | ( (SthTw & 0xFF) >> 4)) & 0xFF;
    	SthTw += pJDiA;
    	SthTw --;
    	SthTw ^= 0x78;
    	SthTw -= pJDiA;
    	SthTw ^= 0x6C;
    	SthTw ^= pJDiA;
    	SthTw = ((SthTw << 5) | ( (SthTw & 0xFF) >> 3)) & 0xFF;
    	SthTw -= pJDiA;
    	SthTw ^= pJDiA;
    	SthTw = (((SthTw & 0xFF) >> 3) | (SthTw << 5)) & 0xFF;
    	SthTw = ~SthTw;
    	SthTw ^= pJDiA;
    	SthTw --;
    	enc[pJDiA] = SthTw;
    }
    
    if (enc[0] == c) {
        decrypt(".70efdf2ec9b086079795c442636b55fb", md5(enc));
    }
}

__attribute__((section(".70efdf2ec9b086079795c442636b55fb")))void process17(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "9"
    unsigned char enc[2] = { 0x9D, 0x78 };
    
    for (unsigned int TQuIm = 0, qSUKz = 0; TQuIm < 2; TQuIm++)
    {
    	qSUKz = enc[TQuIm];
    	qSUKz ^= 0x66;
    	qSUKz += 0x0E;
    	qSUKz += TQuIm;
    	qSUKz -= 0xCF;
    	qSUKz = ((qSUKz << 4) | ( (qSUKz & 0xFF) >> 4)) & 0xFF;
    	qSUKz --;
    	qSUKz ^= 0xF8;
    	qSUKz -= 0x8F;
    	qSUKz = ~qSUKz;
    	qSUKz += 0x51;
    	qSUKz ^= 0x8E;
    	qSUKz ++;
    	qSUKz += TQuIm;
    	qSUKz += 0x4C;
    	qSUKz += TQuIm;
    	qSUKz ^= TQuIm;
    	qSUKz = ~qSUKz;
    	qSUKz ++;
    	qSUKz ^= 0x78;
    	qSUKz += 0x8C;
    	qSUKz += TQuIm;
    	qSUKz ++;
    	qSUKz = ((qSUKz << 7) | ( (qSUKz & 0xFF) >> 1)) & 0xFF;
    	qSUKz = ~qSUKz;
    	qSUKz = (((qSUKz & 0xFF) >> 1) | (qSUKz << 7)) & 0xFF;
    	qSUKz += 0x6A;
    	qSUKz += TQuIm;
    	qSUKz += 0xC9;
    	qSUKz = ((qSUKz << 5) | ( (qSUKz & 0xFF) >> 3)) & 0xFF;
    	qSUKz = ~qSUKz;
    	qSUKz --;
    	qSUKz = ~qSUKz;
    	qSUKz += TQuIm;
    	qSUKz = ~qSUKz;
    	qSUKz --;
    	qSUKz ^= 0xC9;
    	qSUKz += TQuIm;
    	qSUKz = (((qSUKz & 0xFF) >> 4) | (qSUKz << 4)) & 0xFF;
    	qSUKz ^= TQuIm;
    	qSUKz -= TQuIm;
    	qSUKz -= 0x9B;
    	qSUKz = ((qSUKz << 4) | ( (qSUKz & 0xFF) >> 4)) & 0xFF;
    	qSUKz += 0xB5;
    	qSUKz ^= 0xE8;
    	qSUKz -= TQuIm;
    	qSUKz --;
    	qSUKz -= TQuIm;
    	qSUKz = (((qSUKz & 0xFF) >> 3) | (qSUKz << 5)) & 0xFF;
    	qSUKz -= TQuIm;
    	qSUKz += 0x84;
    	enc[TQuIm] = qSUKz;
    }
    
    if (enc[0] == c) {
        decrypt(".6f4922f45568161a8cdf4ad2299f6d23", md5(enc));
    }
}

__attribute__((section(".6f4922f45568161a8cdf4ad2299f6d23")))void process18(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "_"
    unsigned char enc[2] = { 0x7C, 0xB3 };
    
    for (unsigned int DhIEl = 0, cxqao = 0; DhIEl < 2; DhIEl++)
    {
    	cxqao = enc[DhIEl];
    	cxqao = (((cxqao & 0xFF) >> 5) | (cxqao << 3)) & 0xFF;
    	cxqao ++;
    	cxqao = ~cxqao;
    	cxqao -= 0x75;
    	cxqao = ~cxqao;
    	cxqao --;
    	cxqao = (((cxqao & 0xFF) >> 7) | (cxqao << 1)) & 0xFF;
    	cxqao += 0x2A;
    	cxqao += DhIEl;
    	cxqao ^= DhIEl;
    	cxqao += 0x4F;
    	cxqao -= DhIEl;
    	cxqao ++;
    	cxqao ^= DhIEl;
    	cxqao ++;
    	cxqao += DhIEl;
    	cxqao ++;
    	cxqao -= DhIEl;
    	cxqao = ((cxqao << 6) | ( (cxqao & 0xFF) >> 2)) & 0xFF;
    	cxqao --;
    	cxqao += DhIEl;
    	cxqao += 0x48;
    	cxqao -= DhIEl;
    	cxqao = (((cxqao & 0xFF) >> 1) | (cxqao << 7)) & 0xFF;
    	cxqao = ~cxqao;
    	cxqao -= 0x85;
    	cxqao = ~cxqao;
    	cxqao ^= 0x03;
    	cxqao --;
    	cxqao = ((cxqao << 2) | ( (cxqao & 0xFF) >> 6)) & 0xFF;
    	cxqao = ~cxqao;
    	cxqao = (((cxqao & 0xFF) >> 7) | (cxqao << 1)) & 0xFF;
    	cxqao -= 0xD5;
    	cxqao = (((cxqao & 0xFF) >> 2) | (cxqao << 6)) & 0xFF;
    	cxqao ^= 0xD0;
    	cxqao = ((cxqao << 5) | ( (cxqao & 0xFF) >> 3)) & 0xFF;
    	cxqao += 0xBF;
    	cxqao -= DhIEl;
    	cxqao += 0x9E;
    	cxqao = (((cxqao & 0xFF) >> 3) | (cxqao << 5)) & 0xFF;
    	cxqao -= 0x36;
    	cxqao ^= DhIEl;
    	cxqao ++;
    	cxqao -= DhIEl;
    	cxqao = (((cxqao & 0xFF) >> 2) | (cxqao << 6)) & 0xFF;
    	cxqao -= 0x29;
    	cxqao ^= 0x09;
    	cxqao = ~cxqao;
    	cxqao ^= DhIEl;
    	cxqao = ~cxqao;
    	enc[DhIEl] = cxqao;
    }
    
    if (enc[0] == c) {
        decrypt(".1f0e3dad99908345f7439f8ffabdffc4", md5(enc));
    }
}

__attribute__((section(".1f0e3dad99908345f7439f8ffabdffc4")))void process19(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "S"
    unsigned char enc[2] = { 0xFA, 0xB8 };
    
    for (unsigned int gAxlU = 0, rZiaf = 0; gAxlU < 2; gAxlU++)
    {
    	rZiaf = enc[gAxlU];
    	rZiaf = (((rZiaf & 0xFF) >> 7) | (rZiaf << 1)) & 0xFF;
    	rZiaf ^= 0x80;
    	rZiaf ++;
    	rZiaf = ~rZiaf;
    	rZiaf --;
    	rZiaf ^= 0x77;
    	rZiaf += gAxlU;
    	rZiaf ++;
    	rZiaf ^= 0xA5;
    	rZiaf ++;
    	rZiaf ^= 0x4E;
    	rZiaf = ((rZiaf << 1) | ( (rZiaf & 0xFF) >> 7)) & 0xFF;
    	rZiaf = ~rZiaf;
    	rZiaf ^= 0xC4;
    	rZiaf += gAxlU;
    	rZiaf = ((rZiaf << 6) | ( (rZiaf & 0xFF) >> 2)) & 0xFF;
    	rZiaf ^= gAxlU;
    	rZiaf -= gAxlU;
    	rZiaf --;
    	rZiaf = (((rZiaf & 0xFF) >> 2) | (rZiaf << 6)) & 0xFF;
    	rZiaf --;
    	rZiaf ^= gAxlU;
    	rZiaf ++;
    	rZiaf = (((rZiaf & 0xFF) >> 6) | (rZiaf << 2)) & 0xFF;
    	rZiaf ^= gAxlU;
    	rZiaf += 0x22;
    	rZiaf ^= 0x31;
    	rZiaf -= gAxlU;
    	rZiaf = ((rZiaf << 1) | ( (rZiaf & 0xFF) >> 7)) & 0xFF;
    	rZiaf ^= gAxlU;
    	rZiaf ^= 0xC3;
    	rZiaf -= gAxlU;
    	rZiaf = (((rZiaf & 0xFF) >> 4) | (rZiaf << 4)) & 0xFF;
    	rZiaf -= gAxlU;
    	rZiaf ^= 0xC5;
    	rZiaf -= gAxlU;
    	rZiaf ++;
    	rZiaf = ((rZiaf << 3) | ( (rZiaf & 0xFF) >> 5)) & 0xFF;
    	rZiaf += gAxlU;
    	rZiaf ++;
    	rZiaf -= gAxlU;
    	rZiaf = (((rZiaf & 0xFF) >> 5) | (rZiaf << 3)) & 0xFF;
    	rZiaf ^= 0x0D;
    	rZiaf ^= gAxlU;
    	rZiaf += 0x33;
    	rZiaf ^= gAxlU;
    	rZiaf -= 0x7A;
    	rZiaf = (((rZiaf & 0xFF) >> 5) | (rZiaf << 3)) & 0xFF;
    	rZiaf -= gAxlU;
    	rZiaf = (((rZiaf & 0xFF) >> 7) | (rZiaf << 1)) & 0xFF;
    	enc[gAxlU] = rZiaf;
    }
    
    if (enc[0] == c) {
        decrypt(".98f13708210194c475687be6106a3b84", md5(enc));
    }
}

__attribute__((section(".98f13708210194c475687be6106a3b84")))void process20(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "k"
    unsigned char enc[2] = { 0xF2, 0x7E };
    
    for (unsigned int reBwz = 0, uNOnD = 0; reBwz < 2; reBwz++)
    {
    	uNOnD = enc[reBwz];
    	uNOnD ^= reBwz;
    	uNOnD -= 0xA1;
    	uNOnD += reBwz;
    	uNOnD += 0xBD;
    	uNOnD -= reBwz;
    	uNOnD -= 0xD1;
    	uNOnD -= reBwz;
    	uNOnD = ~uNOnD;
    	uNOnD --;
    	uNOnD -= reBwz;
    	uNOnD ++;
    	uNOnD += reBwz;
    	uNOnD = ~uNOnD;
    	uNOnD -= 0x52;
    	uNOnD += reBwz;
    	uNOnD ^= reBwz;
    	uNOnD = (((uNOnD & 0xFF) >> 4) | (uNOnD << 4)) & 0xFF;
    	uNOnD += reBwz;
    	uNOnD = ~uNOnD;
    	uNOnD += 0xC8;
    	uNOnD += reBwz;
    	uNOnD --;
    	uNOnD = ~uNOnD;
    	uNOnD = ((uNOnD << 2) | ( (uNOnD & 0xFF) >> 6)) & 0xFF;
    	uNOnD -= reBwz;
    	uNOnD -= 0x7E;
    	uNOnD ^= reBwz;
    	uNOnD = (((uNOnD & 0xFF) >> 2) | (uNOnD << 6)) & 0xFF;
    	uNOnD = ~uNOnD;
    	uNOnD = (((uNOnD & 0xFF) >> 3) | (uNOnD << 5)) & 0xFF;
    	uNOnD = ~uNOnD;
    	uNOnD ^= reBwz;
    	uNOnD -= 0x0B;
    	uNOnD ^= 0xC4;
    	uNOnD += 0x4B;
    	uNOnD = ((uNOnD << 4) | ( (uNOnD & 0xFF) >> 4)) & 0xFF;
    	uNOnD -= reBwz;
    	uNOnD += 0x33;
    	uNOnD ^= reBwz;
    	uNOnD ^= 0x6F;
    	uNOnD -= reBwz;
    	uNOnD = (((uNOnD & 0xFF) >> 4) | (uNOnD << 4)) & 0xFF;
    	uNOnD -= 0x32;
    	uNOnD = ((uNOnD << 5) | ( (uNOnD & 0xFF) >> 3)) & 0xFF;
    	uNOnD --;
    	uNOnD -= reBwz;
    	uNOnD ^= 0x4A;
    	uNOnD = (((uNOnD & 0xFF) >> 6) | (uNOnD << 2)) & 0xFF;
    	uNOnD -= reBwz;
    	uNOnD --;
    	enc[reBwz] = uNOnD;
    }
    
    if (enc[0] == c) {
        decrypt(".3c59dc048e8850243be8079a5c74d079", md5(enc));
    }
}

__attribute__((section(".3c59dc048e8850243be8079a5c74d079")))void process21(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "1"
    unsigned char enc[2] = { 0x02, 0x08 };
    
    for (unsigned int VwKLX = 0, Wxsom = 0; VwKLX < 2; VwKLX++)
    {
    	Wxsom = enc[VwKLX];
    	Wxsom --;
    	Wxsom = ((Wxsom << 1) | ( (Wxsom & 0xFF) >> 7)) & 0xFF;
    	Wxsom = ~Wxsom;
    	Wxsom = ((Wxsom << 6) | ( (Wxsom & 0xFF) >> 2)) & 0xFF;
    	Wxsom += 0x74;
    	Wxsom += VwKLX;
    	Wxsom += 0x85;
    	Wxsom = ~Wxsom;
    	Wxsom += 0x2D;
    	Wxsom ^= VwKLX;
    	Wxsom = (((Wxsom & 0xFF) >> 4) | (Wxsom << 4)) & 0xFF;
    	Wxsom ^= VwKLX;
    	Wxsom += VwKLX;
    	Wxsom --;
    	Wxsom = ((Wxsom << 4) | ( (Wxsom & 0xFF) >> 4)) & 0xFF;
    	Wxsom ^= 0xA5;
    	Wxsom += VwKLX;
    	Wxsom ^= 0xA2;
    	Wxsom ++;
    	Wxsom = ((Wxsom << 1) | ( (Wxsom & 0xFF) >> 7)) & 0xFF;
    	Wxsom ^= VwKLX;
    	Wxsom ++;
    	Wxsom = ~Wxsom;
    	Wxsom ^= 0xDB;
    	Wxsom += VwKLX;
    	Wxsom = (((Wxsom & 0xFF) >> 3) | (Wxsom << 5)) & 0xFF;
    	Wxsom ^= VwKLX;
    	Wxsom = ~Wxsom;
    	Wxsom = (((Wxsom & 0xFF) >> 7) | (Wxsom << 1)) & 0xFF;
    	Wxsom ++;
    	Wxsom = (((Wxsom & 0xFF) >> 6) | (Wxsom << 2)) & 0xFF;
    	Wxsom ^= 0x5C;
    	Wxsom = (((Wxsom & 0xFF) >> 4) | (Wxsom << 4)) & 0xFF;
    	Wxsom -= 0x13;
    	Wxsom ^= VwKLX;
    	Wxsom = ((Wxsom << 6) | ( (Wxsom & 0xFF) >> 2)) & 0xFF;
    	Wxsom ++;
    	Wxsom += VwKLX;
    	Wxsom = ((Wxsom << 5) | ( (Wxsom & 0xFF) >> 3)) & 0xFF;
    	Wxsom ^= 0x3D;
    	Wxsom ^= VwKLX;
    	Wxsom += VwKLX;
    	Wxsom = ((Wxsom << 1) | ( (Wxsom & 0xFF) >> 7)) & 0xFF;
    	Wxsom ^= VwKLX;
    	Wxsom += 0x86;
    	Wxsom = ((Wxsom << 3) | ( (Wxsom & 0xFF) >> 5)) & 0xFF;
    	Wxsom -= VwKLX;
    	Wxsom ++;
    	Wxsom ^= 0x20;
    	Wxsom = (((Wxsom & 0xFF) >> 1) | (Wxsom << 7)) & 0xFF;
    	enc[VwKLX] = Wxsom;
    }
    
    if (enc[0] == c) {
        decrypt(".b6d767d2f8ed5d21a44b0e5886680cb9", md5(enc));
    }
}

__attribute__((section(".b6d767d2f8ed5d21a44b0e5886680cb9")))void process22(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "l"
    unsigned char enc[2] = { 0xD9, 0x12 };
    
    for (unsigned int FsOeE = 0, NaUCo = 0; FsOeE < 2; FsOeE++)
    {
    	NaUCo = enc[FsOeE];
    	NaUCo ^= FsOeE;
    	NaUCo += FsOeE;
    	NaUCo --;
    	NaUCo = ~NaUCo;
    	NaUCo ++;
    	NaUCo = ~NaUCo;
    	NaUCo ^= FsOeE;
    	NaUCo -= FsOeE;
    	NaUCo -= 0x81;
    	NaUCo += FsOeE;
    	NaUCo --;
    	NaUCo -= FsOeE;
    	NaUCo = (((NaUCo & 0xFF) >> 7) | (NaUCo << 1)) & 0xFF;
    	NaUCo -= 0x4D;
    	NaUCo ^= 0xC4;
    	NaUCo += 0xA8;
    	NaUCo = ~NaUCo;
    	NaUCo ^= FsOeE;
    	NaUCo = ~NaUCo;
    	NaUCo ++;
    	NaUCo ^= 0xE6;
    	NaUCo ^= FsOeE;
    	NaUCo --;
    	NaUCo = (((NaUCo & 0xFF) >> 6) | (NaUCo << 2)) & 0xFF;
    	NaUCo --;
    	NaUCo = (((NaUCo & 0xFF) >> 7) | (NaUCo << 1)) & 0xFF;
    	NaUCo --;
    	NaUCo += FsOeE;
    	NaUCo -= 0x05;
    	NaUCo = ~NaUCo;
    	NaUCo -= FsOeE;
    	NaUCo ++;
    	NaUCo ^= FsOeE;
    	NaUCo -= FsOeE;
    	NaUCo = (((NaUCo & 0xFF) >> 6) | (NaUCo << 2)) & 0xFF;
    	NaUCo += 0xF1;
    	NaUCo ^= FsOeE;
    	NaUCo += 0x57;
    	NaUCo -= FsOeE;
    	NaUCo ^= FsOeE;
    	NaUCo ^= 0xE9;
    	NaUCo = ((NaUCo << 2) | ( (NaUCo & 0xFF) >> 6)) & 0xFF;
    	NaUCo ^= FsOeE;
    	NaUCo += FsOeE;
    	NaUCo --;
    	NaUCo += FsOeE;
    	NaUCo ^= 0xFA;
    	NaUCo = ((NaUCo << 3) | ( (NaUCo & 0xFF) >> 5)) & 0xFF;
    	NaUCo ^= FsOeE;
    	NaUCo -= FsOeE;
    	enc[FsOeE] = NaUCo;
    }
    
    if (enc[0] == c) {
        decrypt(".37693cfc748049e45d87b8c7d8b9aacd", md5(enc));
    }
}

__attribute__((section(".37693cfc748049e45d87b8c7d8b9aacd")))void process23(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "l"
    unsigned char enc[2] = { 0x56, 0x9B };
    
    for (unsigned int pIMgX = 0, ZrRGU = 0; pIMgX < 2; pIMgX++)
    {
    	ZrRGU = enc[pIMgX];
    	ZrRGU = (((ZrRGU & 0xFF) >> 3) | (ZrRGU << 5)) & 0xFF;
    	ZrRGU = ~ZrRGU;
    	ZrRGU -= pIMgX;
    	ZrRGU ^= pIMgX;
    	ZrRGU -= 0x9A;
    	ZrRGU = ~ZrRGU;
    	ZrRGU += 0x9B;
    	ZrRGU = ~ZrRGU;
    	ZrRGU --;
    	ZrRGU = (((ZrRGU & 0xFF) >> 5) | (ZrRGU << 3)) & 0xFF;
    	ZrRGU ++;
    	ZrRGU = ~ZrRGU;
    	ZrRGU -= 0x84;
    	ZrRGU = ((ZrRGU << 7) | ( (ZrRGU & 0xFF) >> 1)) & 0xFF;
    	ZrRGU = ~ZrRGU;
    	ZrRGU ^= 0x8E;
    	ZrRGU = ((ZrRGU << 2) | ( (ZrRGU & 0xFF) >> 6)) & 0xFF;
    	ZrRGU ++;
    	ZrRGU += pIMgX;
    	ZrRGU -= 0xB1;
    	ZrRGU ^= 0xA8;
    	ZrRGU += 0x9B;
    	ZrRGU = ((ZrRGU << 3) | ( (ZrRGU & 0xFF) >> 5)) & 0xFF;
    	ZrRGU --;
    	ZrRGU ^= pIMgX;
    	ZrRGU ^= 0x79;
    	ZrRGU += 0x34;
    	ZrRGU = ((ZrRGU << 7) | ( (ZrRGU & 0xFF) >> 1)) & 0xFF;
    	ZrRGU += 0x28;
    	ZrRGU = ~ZrRGU;
    	ZrRGU += 0xB3;
    	ZrRGU = ((ZrRGU << 1) | ( (ZrRGU & 0xFF) >> 7)) & 0xFF;
    	ZrRGU --;
    	ZrRGU -= pIMgX;
    	ZrRGU = ((ZrRGU << 4) | ( (ZrRGU & 0xFF) >> 4)) & 0xFF;
    	ZrRGU -= pIMgX;
    	ZrRGU = (((ZrRGU & 0xFF) >> 4) | (ZrRGU << 4)) & 0xFF;
    	ZrRGU --;
    	ZrRGU ^= pIMgX;
    	ZrRGU ++;
    	ZrRGU = (((ZrRGU & 0xFF) >> 1) | (ZrRGU << 7)) & 0xFF;
    	ZrRGU --;
    	ZrRGU = ((ZrRGU << 5) | ( (ZrRGU & 0xFF) >> 3)) & 0xFF;
    	ZrRGU ^= 0x35;
    	ZrRGU = ((ZrRGU << 2) | ( (ZrRGU & 0xFF) >> 6)) & 0xFF;
    	ZrRGU ++;
    	ZrRGU = (((ZrRGU & 0xFF) >> 2) | (ZrRGU << 6)) & 0xFF;
    	ZrRGU += pIMgX;
    	ZrRGU ^= pIMgX;
    	ZrRGU += pIMgX;
    	enc[pIMgX] = ZrRGU;
    }
    
    if (enc[0] == c) {
        decrypt(".1ff1de774005f8da13f42943881c655f", md5(enc));
    }
}

__attribute__((section(".1ff1de774005f8da13f42943881c655f")))void process24(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "z"
    unsigned char enc[2] = { 0x14, 0x21 };
    
    for (unsigned int iUsxa = 0, jdDcK = 0; iUsxa < 2; iUsxa++)
    {
    	jdDcK = enc[iUsxa];
    	jdDcK = (((jdDcK & 0xFF) >> 3) | (jdDcK << 5)) & 0xFF;
    	jdDcK += 0xA0;
    	jdDcK += iUsxa;
    	jdDcK ^= 0x95;
    	jdDcK --;
    	jdDcK += iUsxa;
    	jdDcK --;
    	jdDcK = ((jdDcK << 1) | ( (jdDcK & 0xFF) >> 7)) & 0xFF;
    	jdDcK --;
    	jdDcK += iUsxa;
    	jdDcK ^= 0xFD;
    	jdDcK -= 0xAC;
    	jdDcK ^= iUsxa;
    	jdDcK -= iUsxa;
    	jdDcK -= 0x30;
    	jdDcK ^= iUsxa;
    	jdDcK += 0x67;
    	jdDcK ^= iUsxa;
    	jdDcK --;
    	jdDcK += iUsxa;
    	jdDcK += 0x2F;
    	jdDcK = (((jdDcK & 0xFF) >> 6) | (jdDcK << 2)) & 0xFF;
    	jdDcK -= 0x7E;
    	jdDcK ^= 0x99;
    	jdDcK ++;
    	jdDcK += iUsxa;
    	jdDcK --;
    	jdDcK += iUsxa;
    	jdDcK ^= iUsxa;
    	jdDcK = ~jdDcK;
    	jdDcK -= iUsxa;
    	jdDcK = ((jdDcK << 7) | ( (jdDcK & 0xFF) >> 1)) & 0xFF;
    	jdDcK += 0x1A;
    	jdDcK += iUsxa;
    	jdDcK -= 0xCC;
    	jdDcK -= iUsxa;
    	jdDcK ^= iUsxa;
    	jdDcK = ((jdDcK << 6) | ( (jdDcK & 0xFF) >> 2)) & 0xFF;
    	jdDcK = ~jdDcK;
    	jdDcK -= iUsxa;
    	jdDcK -= 0xFC;
    	jdDcK = ((jdDcK << 5) | ( (jdDcK & 0xFF) >> 3)) & 0xFF;
    	jdDcK = ~jdDcK;
    	jdDcK += iUsxa;
    	jdDcK ++;
    	jdDcK = ~jdDcK;
    	jdDcK ^= 0x70;
    	jdDcK = ~jdDcK;
    	jdDcK ^= iUsxa;
    	jdDcK += 0x89;
    	enc[iUsxa] = jdDcK;
    }
    
    if (enc[0] == c) {
        decrypt(".8e296a067a37563370ded05f5a3bf3ec", md5(enc));
    }
}

__attribute__((section(".8e296a067a37563370ded05f5a3bf3ec")))void process25(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "!"
    unsigned char enc[2] = { 0x2E, 0x4D };
    
    for (unsigned int fmZiI = 0, OZdIG = 0; fmZiI < 2; fmZiI++)
    {
    	OZdIG = enc[fmZiI];
    	OZdIG = ((OZdIG << 5) | ( (OZdIG & 0xFF) >> 3)) & 0xFF;
    	OZdIG = ~OZdIG;
    	OZdIG ^= fmZiI;
    	OZdIG = (((OZdIG & 0xFF) >> 6) | (OZdIG << 2)) & 0xFF;
    	OZdIG += fmZiI;
    	OZdIG ^= 0x2E;
    	OZdIG ^= fmZiI;
    	OZdIG ++;
    	OZdIG ^= 0xD2;
    	OZdIG -= 0x8A;
    	OZdIG = ((OZdIG << 4) | ( (OZdIG & 0xFF) >> 4)) & 0xFF;
    	OZdIG ++;
    	OZdIG -= fmZiI;
    	OZdIG = ((OZdIG << 4) | ( (OZdIG & 0xFF) >> 4)) & 0xFF;
    	OZdIG -= 0xA3;
    	OZdIG += fmZiI;
    	OZdIG += 0x5B;
    	OZdIG = ~OZdIG;
    	OZdIG = (((OZdIG & 0xFF) >> 4) | (OZdIG << 4)) & 0xFF;
    	OZdIG ^= 0x57;
    	OZdIG --;
    	OZdIG ^= fmZiI;
    	OZdIG ^= 0xEE;
    	OZdIG += 0xED;
    	OZdIG = ((OZdIG << 2) | ( (OZdIG & 0xFF) >> 6)) & 0xFF;
    	OZdIG = ~OZdIG;
    	OZdIG -= 0xE9;
    	OZdIG = ~OZdIG;
    	OZdIG += fmZiI;
    	OZdIG --;
    	OZdIG ^= fmZiI;
    	OZdIG += 0x21;
    	OZdIG = (((OZdIG & 0xFF) >> 4) | (OZdIG << 4)) & 0xFF;
    	OZdIG ^= 0x17;
    	OZdIG -= 0xF0;
    	OZdIG -= fmZiI;
    	OZdIG += 0x33;
    	OZdIG += fmZiI;
    	OZdIG ^= 0xA0;
    	OZdIG += fmZiI;
    	OZdIG = ~OZdIG;
    	OZdIG ^= fmZiI;
    	OZdIG = (((OZdIG & 0xFF) >> 1) | (OZdIG << 7)) & 0xFF;
    	OZdIG ^= fmZiI;
    	OZdIG -= fmZiI;
    	OZdIG ^= 0x4A;
    	OZdIG = ~OZdIG;
    	OZdIG -= fmZiI;
    	OZdIG = ((OZdIG << 6) | ( (OZdIG & 0xFF) >> 2)) & 0xFF;
    	OZdIG = ~OZdIG;
    	enc[fmZiI] = OZdIG;
    }
    
    if (enc[0] == c) {
        decrypt(".4e732ced3463d06de0ca9a15b6153677", md5(enc));
    }
}

__attribute__((section(".4e732ced3463d06de0ca9a15b6153677")))void process26(char c) {
    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // enc = "}"
    unsigned char enc[2] = { 0xB5, 0x35 };
    
    for (unsigned int Kustj = 0, AyaoI = 0; Kustj < 2; Kustj++)
    {
    	AyaoI = enc[Kustj];
    	AyaoI --;
    	AyaoI ^= Kustj;
    	AyaoI -= Kustj;
    	AyaoI ++;
    	AyaoI += Kustj;
    	AyaoI --;
    	AyaoI = (((AyaoI & 0xFF) >> 1) | (AyaoI << 7)) & 0xFF;
    	AyaoI = ~AyaoI;
    	AyaoI -= Kustj;
    	AyaoI = ((AyaoI << 6) | ( (AyaoI & 0xFF) >> 2)) & 0xFF;
    	AyaoI += 0xF7;
    	AyaoI = (((AyaoI & 0xFF) >> 4) | (AyaoI << 4)) & 0xFF;
    	AyaoI --;
    	AyaoI = ~AyaoI;
    	AyaoI += Kustj;
    	AyaoI = ((AyaoI << 6) | ( (AyaoI & 0xFF) >> 2)) & 0xFF;
    	AyaoI += 0xC6;
    	AyaoI ^= 0xE1;
    	AyaoI += Kustj;
    	AyaoI ^= 0xBC;
    	AyaoI = (((AyaoI & 0xFF) >> 3) | (AyaoI << 5)) & 0xFF;
    	AyaoI += Kustj;
    	AyaoI -= 0x81;
    	AyaoI ^= 0x05;
    	AyaoI += Kustj;
    	AyaoI ^= Kustj;
    	AyaoI -= Kustj;
    	AyaoI ^= 0x0D;
    	AyaoI += 0xE7;
    	AyaoI = ~AyaoI;
    	AyaoI --;
    	AyaoI = ((AyaoI << 3) | ( (AyaoI & 0xFF) >> 5)) & 0xFF;
    	AyaoI = ~AyaoI;
    	AyaoI --;
    	AyaoI += Kustj;
    	AyaoI ++;
    	AyaoI -= Kustj;
    	AyaoI ^= 0xE1;
    	AyaoI -= 0x3D;
    	AyaoI -= Kustj;
    	AyaoI ^= Kustj;
    	AyaoI -= Kustj;
    	AyaoI ++;
    	AyaoI ^= 0x90;
    	AyaoI += 0x0E;
    	AyaoI = (((AyaoI & 0xFF) >> 4) | (AyaoI << 4)) & 0xFF;
    	AyaoI ^= 0xF5;
    	AyaoI = ~AyaoI;
    	AyaoI ^= Kustj;
    	AyaoI += Kustj;
    	enc[Kustj] = AyaoI;
    }
    
    if (enc[0] == c) {
        printf("You got it!\n");
    }
}

void (*processes[])(char) = { process0, process1, process2, process3, process4, process5, process6, process7, process8, process9, process10, process11, process12, process13, process14, process15, process16, process17, process18, process19, process20, process21, process22, process23, process24, process25, process26 };

int main(int argc, char **argv) {
    strcpy(binary_path, argv[0]);

    char input[64];
    printf("Enter the flag: ");
    scanf("%s", input);

    if (strlen(input) != 27) {
        printf("Invalid flag length :(\n");
        return 1;
    }

    for (int i = 0; i < strlen(input); i++) {
        processes[i](input[i]);
    }
    return 0;
}