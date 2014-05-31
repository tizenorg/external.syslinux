/*
 * Codepage data structure as generated by cptable.pl
 */
#ifndef CODEPAGE_H
#define CODEPAGE_H

#include <stdint.h>

#define CODEPAGE_MAGIC	UINT64_C(0x51d21eb158a8b3d4)

struct codepage {
    uint64_t	magic;
    uint32_t	reserved[6];

    uint8_t	upper[256];	/* Codepage upper case table */
    uint8_t	lower[256];	/* Codepage lower case table */

    /*
     * The primary Unicode match is the same case, i.e. A -> A,
     * the secondary Unicode match is the opposite case, i.e. A -> a.
     */
    uint16_t	uni[2][256];	/* Primary and alternate Unicode matches */
};

extern const struct codepage codepage;

#endif /* CODEPAGE_H */
