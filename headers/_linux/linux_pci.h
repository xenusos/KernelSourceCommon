#pragma once

#define PCI_REGION_FLAG_MASK	0x0fU	/* These bits of resource flags tell us the PCI region flags */


#define PCIBIOS_SUCCESSFUL		0x00
#define PCIBIOS_FUNC_NOT_SUPPORTED	0x81
#define PCIBIOS_BAD_VENDOR_ID		0x83
#define PCIBIOS_DEVICE_NOT_FOUND	0x86
#define PCIBIOS_BAD_REGISTER_NUMBER	0x87
#define PCIBIOS_SET_FAILED		0x88
#define PCIBIOS_BUFFER_TOO_SMALL	0x89

#define BUS_NOTIFY_ADD_DEVICE		0x00000001 /* device added */
#define BUS_NOTIFY_DEL_DEVICE		0x00000002 /* device removed */
#define BUS_NOTIFY_BOUND_DRIVER		0x00000003 /* driver bound to device */
#define BUS_NOTIFY_UNBIND_DRIVER	0x00000004 /* driver about to be
							  unbound */
#define BUS_NOTIFY_UNBOUND_DRIVER	0x00000005 /* driver is unbound
							  from the device */

#define PCI_VGA_STATE_CHANGE_BRIDGE (1 << 0)
#define PCI_VGA_STATE_CHANGE_DECODES (1 << 1)

#define PCI_PM_D2_DELAY		200
#define PCI_PM_D3_WAIT		10
#define PCI_PM_D3COLD_WAIT	100
#define PCI_PM_BUS_WAIT		50


#define PCI_IRQ_LEGACY		(1 << 0) /* Allow legacy interrupts */
#define PCI_IRQ_MSI		(1 << 1) /* Allow MSI interrupts */
#define PCI_IRQ_MSIX		(1 << 2) /* Allow MSI-X interrupts */
#define PCI_IRQ_AFFINITY	(1 << 3) /* Auto-assign affinity */
#define PCI_IRQ_ALL_TYPES \
	(PCI_IRQ_LEGACY | PCI_IRQ_MSI | PCI_IRQ_MSIX)

//#define PCI_D0		0
//#define PCI_D1		1
//#define PCI_D2		2
//#define PCI_D3hot	    3
//#define PCI_D3cold	4
//#define PCI_UNKNOWN	5
//#define PCI_POWER_ERROR	-1

struct msix_entry {
	uint32_t	vector;	/* Kernel uses to write allocated vector */
	uint16_t	entry;	/* Driver uses to specify entry, OS writes */ //TODO (Reece): check padding
};

enum pcie_bus_config_types {
	PCIE_BUS_TUNE_OFF,	/* Don't touch MPS at all */
	PCIE_BUS_DEFAULT,	/* Ensure MPS matches upstream bridge */
	PCIE_BUS_SAFE,		/* Use largest MPS boot-time devices support */
	PCIE_BUS_PERFORMANCE,	/* Use MPS and MRRS for best performance */
	PCIE_BUS_PEER2PEER,	/* Set MPS = 128 for all devices */
};




enum {
	PCI_REASSIGN_ALL_RSRC = 0x00000001,	/* Ignore firmware setup */
	PCI_REASSIGN_ALL_BUS = 0x00000002,	/* Reassign all bus numbers */
	PCI_PROBE_ONLY = 0x00000004,	/* Use existing setup */
	PCI_CAN_SKIP_ISA_ALIGN = 0x00000008,	/* Don't do ISA alignment */
	PCI_ENABLE_PROC_DOMAINS = 0x00000010,	/* Enable domains in /proc */
	PCI_COMPAT_DOMAIN_0 = 0x00000020,	/* ... except domain 0 */
	PCI_SCAN_ALL_PCIE_DEVS = 0x00000040,	/* Scan all, not just dev 0 */
};

enum pci_irq_reroute_variant {
	INTEL_IRQ_REROUTE_VARIANT = 1,
	MAX_IRQ_REROUTE_VARIANTS = 3
};



/* Values from Link Status register, PCIe r3.1, sec 7.8.8 */
enum pcie_link_width {
	PCIE_LNK_WIDTH_RESRV = 0x00,
	PCIE_LNK_X1 = 0x01,
	PCIE_LNK_X2 = 0x02,
	PCIE_LNK_X4 = 0x04,
	PCIE_LNK_X8 = 0x08,
	PCIE_LNK_X12 = 0x0c,
	PCIE_LNK_X16 = 0x10,
	PCIE_LNK_X32 = 0x20,
	PCIE_LNK_WIDTH_UNKNOWN = 0xff,
};

/* Based on the PCI Hotplug Spec, but some values are made up by us */
enum pci_bus_speed {
	PCI_SPEED_33MHz = 0x00,
	PCI_SPEED_66MHz = 0x01,
	PCI_SPEED_66MHz_PCIX = 0x02,
	PCI_SPEED_100MHz_PCIX = 0x03,
	PCI_SPEED_133MHz_PCIX = 0x04,
	PCI_SPEED_66MHz_PCIX_ECC = 0x05,
	PCI_SPEED_100MHz_PCIX_ECC = 0x06,
	PCI_SPEED_133MHz_PCIX_ECC = 0x07,
	PCI_SPEED_66MHz_PCIX_266 = 0x09,
	PCI_SPEED_100MHz_PCIX_266 = 0x0a,
	PCI_SPEED_133MHz_PCIX_266 = 0x0b,
	AGP_UNKNOWN = 0x0c,
	AGP_1X = 0x0d,
	AGP_2X = 0x0e,
	AGP_4X = 0x0f,
	AGP_8X = 0x10,
	PCI_SPEED_66MHz_PCIX_533 = 0x11,
	PCI_SPEED_100MHz_PCIX_533 = 0x12,
	PCI_SPEED_133MHz_PCIX_533 = 0x13,
	PCIE_SPEED_2_5GT = 0x14,
	PCIE_SPEED_5_0GT = 0x15,
	PCIE_SPEED_8_0GT = 0x16,
	PCI_SPEED_UNKNOWN = 0xff,
};
#define PCI_SUBTRACTIVE_DECODE	0x1


struct pci_bus_resource {
	struct list_head	list;
	union {
		struct _resource *res;
		resource_k		 res_ptr;
	};
	l_uint		flags;
};

typedef struct pm_message {
	l_int event;
} pm_message_t;


typedef l_int	pci_power_t;