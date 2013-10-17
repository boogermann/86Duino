/*****************************  i8259-PIC Access  *****************************/
#define I8259M_OCW2             (0x20)
#define I8259S_OCW2             (0xa0)
#define I8259M_IMR              (0x21)
#define I8259S_IMR              (0xa1)

#define I8259M_VECTOR_START     (0x08)
#define I8259S_VECTOR_START     (0x70)

#ifdef DMP_DOS_DJGPP  // port-I/O functions that is safe to use in interrupt context
    static void i8259_outb(unsigned short addr, unsigned char val) {
        __asm__ volatile ("outb %0, %1" : : "a" (val), "d" (addr));
    }
    DPMI_END_OF_LOCKED_STATIC_FUNC(i8259_outb)

    static unsigned char i8259_inb(unsigned short addr) {
        unsigned char val;
        __asm__ volatile ("inb %1, %0" : "=a" (val) : "d" (addr));
        return val;
    }
    DPMI_END_OF_LOCKED_STATIC_FUNC(i8259_inb)
#else
    #define i8259_outb(addr, val)   portio_outpb(addr, val)
    #define i8259_inb(addr)         portio_inpb(addr)
#endif

DMPAPI(void) i8259_DisableIRQ(int irq) {
    unsigned short imr = (irq > 7)? I8259S_IMR : I8259M_IMR;
    i8259_outb(imr, i8259_inb(imr) | (1 << (irq & 0x07)));
}
#ifdef DMP_DOS_DJGPP
DPMI_END_OF_LOCKED_FUNC(i8259_DisableIRQ)
#endif

DMPAPI(void) i8259_EnableIRQ(int irq) {
    unsigned short imr = (irq > 7)? I8259S_IMR : I8259M_IMR;
    i8259_outb(imr, i8259_inb(imr) & ~(1 << (irq & 0x07)));
}
#ifdef DMP_DOS_DJGPP
DPMI_END_OF_LOCKED_FUNC(i8259_EnableIRQ)
#endif

DMPAPI(bool) i8259_IsIRQEnabled(int irq) {
    unsigned short imr = (irq > 7)? I8259S_IMR : I8259M_IMR;
    if ((i8259_inb(imr) & (1 << (irq & 0x07))) == 0) return true; else return false;
}
#ifdef DMP_DOS_DJGPP
DPMI_END_OF_LOCKED_FUNC(i8259_IsIRQEnabled)
#endif

DMPAPI(void) i8259_SendEOI(int irq) {
    if (irq > 7) i8259_outb(I8259S_OCW2, 0x20);
    i8259_outb(I8259M_OCW2, 0x20);
}
#ifdef DMP_DOS_DJGPP
DPMI_END_OF_LOCKED_FUNC(i8259_SendEOI)
#endif

DMPAPI(int) i8259_GetINTVEC(int irq) {
    return (irq <= 7)? I8259M_VECTOR_START + irq : I8259S_VECTOR_START + irq - 8;
}
#ifdef DMP_DOS_DJGPP
DPMI_END_OF_LOCKED_FUNC(i8259_GetINTVEC)
#endif
/*--------------------------  end. i8259-PIC Access  -------------------------*/
