#ifndef _HW_CONFIG_H_
#define _HW_CONFIG_H_

#define HARDWARE_INI	"etc/hardware.ini"

#define MMU_IRQ		13
#define MMU_CMD		0x66
#define MMU_FAULT_ADDR 	0xCD
#define TLB_ADD_ENTRY	0xCE
#define TLB_DEL_ENTRY	0xDE
#define TLB_SIZE	32
#define TLB_ENTRIES	0x800

#define PM_PAGES (1 << 8)
#define VM_PAGES (1 << 12)
#define PAGE_SIZE 4096
#define PM_SIZE (4096 * PM_PAGES)
#define VM_SIZE (4096 * VM_PAGES)

#endif
