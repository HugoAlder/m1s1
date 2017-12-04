#define HARDWARE_INI "etc/hardware.ini"
#define MMU_IRQ 13
#define MMU_FAULT_ADDR 0xCD
#define MMU_CMD 0x66

/* En Ko */
#define PAGE_SIZE 4

/* Physical Memory */
#define PM_PAGES 256
#define PM_SIZE PM_PAGES * PAGE_SIZE

/* Virtual Memory */
#define VM_PAGES 4096
#define VM_SIZE VM_PAGES * PAGE_SIZE

#define TLB_ADD_ENTRY	0xCE
