void printf(const char* str) {
    unsigned short* VideoMemory = (unsigned short*)0xb8000;
    for (int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

typedef void (*constructor)();
extern constructor start_ctors;
extern constructor end_ctors;

void callConstructors(){
    for(constructor * i = &start_ctors;i!=&end_ctors;i++){
        (*i)();
    }
}
void kernelMain(void* multiboot_structure, int magicnumber) {
    printf("helloworld");
    while (1);
}