#pragma once

/* Don't change this without changing skb_csum_unnecessary! */
#define CHECKSUM_NONE		0
#define CHECKSUM_UNNECESSARY	1
#define CHECKSUM_COMPLETE	2
#define CHECKSUM_PARTIAL	3

/* Maximum value in skb->csum_level */
#define SKB_MAX_CSUM_LEVEL	3


/* Definitions for tx_flags in struct skb_shared_info */
enum {
    /* generate hardware time stamp */
    SKBTX_HW_TSTAMP = 1 << 0,

    /* generate software time stamp when queueing packet to NIC */
    SKBTX_SW_TSTAMP = 1 << 1,

    /* device driver is going to provide hardware time stamp */
    SKBTX_IN_PROGRESS = 1 << 2,

    /* device driver supports TX zero-copy buffers */
    SKBTX_DEV_ZEROCOPY = 1 << 3,

    /* generate wifi status information (where possible) */
    SKBTX_WIFI_STATUS = 1 << 4,

    /* This indicates at least one fragment might be overwritten
     * (as in vmsplice(), sendfile() ...)
     * If we need to compute a TX checksum, we'll need to copy
     * all frags to avoid possible bad checksum
     */
    SKBTX_SHARED_FRAG = 1 << 5,

    /* generate software time stamp when entering packet scheduling */
    SKBTX_SCHED_TSTAMP = 1 << 6,
};

#define SKBTX_ZEROCOPY_FRAG	(SKBTX_DEV_ZEROCOPY | SKBTX_SHARED_FRAG)
#define SKBTX_ANY_SW_TSTAMP	(SKBTX_SW_TSTAMP    | \
				 SKBTX_SCHED_TSTAMP)
#define SKBTX_ANY_TSTAMP	(SKBTX_HW_TSTAMP | SKBTX_ANY_SW_TSTAMP)


#define SKB_DATAREF_SHIFT 16
#define SKB_DATAREF_MASK ((1 << SKB_DATAREF_SHIFT) - 1)


enum {
    SKB_FCLONE_UNAVAILABLE,	/* skb has no fclone (from head_cache) */
    SKB_FCLONE_ORIG,	/* orig skb (from fclone_cache) */
    SKB_FCLONE_CLONE,	/* companion fclone skb (from fclone_cache) */
};

enum {
    SKB_GSO_TCPV4 = 1 << 0,

    /* This indicates the skb is from an untrusted source. */
    SKB_GSO_DODGY = 1 << 1,

    /* This indicates the tcp segment has CWR set. */
    SKB_GSO_TCP_ECN = 1 << 2,

    SKB_GSO_TCP_FIXEDID = 1 << 3,

    SKB_GSO_TCPV6 = 1 << 4,

    SKB_GSO_FCOE = 1 << 5,

    SKB_GSO_GRE = 1 << 6,

    SKB_GSO_GRE_CSUM = 1 << 7,

    SKB_GSO_IPXIP4 = 1 << 8,

    SKB_GSO_IPXIP6 = 1 << 9,

    SKB_GSO_UDP_TUNNEL = 1 << 10,

    SKB_GSO_UDP_TUNNEL_CSUM = 1 << 11,

    SKB_GSO_PARTIAL = 1 << 12,

    SKB_GSO_TUNNEL_REMCSUM = 1 << 13,

    SKB_GSO_SCTP = 1 << 14,

    SKB_GSO_ESP = 1 << 15,

    SKB_GSO_UDP = 1 << 16,
};
