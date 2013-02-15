/* ----------------------------------------------------------------------- *
 *
 *   Copyright 2008 H. Peter Anvin - All Rights Reserved
 *
 *   Permission is hereby granted, free of charge, to any person
 *   obtaining a copy of this software and associated documentation
 *   files (the "Software"), to deal in the Software without
 *   restriction, including without limitation the rights to use,
 *   copy, modify, merge, publish, distribute, sublicense, and/or
 *   sell copies of the Software, and to permit persons to whom
 *   the Software is furnished to do so, subject to the following
 *   conditions:
 *
 *   The above copyright notice and this permission notice shall
 *   be included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------------------------------------------------------- */

#include <syslinux/config.h>
#include <klibc/compiler.h>
#include <com32.h>

struct syslinux_version __syslinux_version;

void __constructor __syslinux_get_version(void)
{
    static com32sys_t reg;

    reg.eax.w[0] = 0x0001;
    __intcall(0x22, &reg, &reg);

    __syslinux_version.version = reg.ecx.w[0];
    __syslinux_version.max_api = reg.eax.w[0];
    __syslinux_version.filesystem = reg.edx.b[0];
    __syslinux_version.version_string = MK_PTR(reg.es, reg.esi.w[0]);
    __syslinux_version.copyright_string = MK_PTR(reg.es, reg.edi.w[0]);
}
