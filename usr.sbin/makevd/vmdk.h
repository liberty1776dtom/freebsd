/*-
 * Copyright (c) 2011
 *	Hiroki Sato <hrs@FreeBSD.org>  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 *
 */
#ifndef _VMDK_H
#define _VMDK_H

#include <sys/endian.h>
#include <stdint.h>

typedef uint64_t SectorType;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;
typedef uint8_t Bool;

struct SparseExtentHeader {
	uint32	     magicNumber;
	uint32	     version;
	uint32	     flags;
	SectorType   capacity;
	SectorType   grainSize;
	SectorType   descriptorOffset;
	SectorType   descriptorSize;
	uint32	     numGTEsPerGT;
	SectorType   rgdOffset;
	SectorType   gdOffset;
	SectorType   overHead;
	Bool	     uncleanShutdown;
	char	     singleEndLineChar;
	char	     nonEndLineChar;
	char	     doubleEndLineChar1;
	char	     doubleEndLineChar2;
	uint16	     compressAlgorithm;
	uint8	     pad[433];
} __attribute__((__packed__));

#if _BYTE_ORDER == _BIG_ENDIAN
#define	SPARSE_MAGICNUMBER		(0x4b444d56)	/* 'K' 'D' 'M' 'V' */
#else
#define	SPARSE_MAGICNUMBER		(0x564d444b)	/* 'V' 'M' 'D' 'K' */
#endif

#define	SPARSE_VERSION_DEFAULT		2

#endif	/* _VMDK_H */
