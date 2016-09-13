/*
  Copyright (c) 2016, Antonio SJ Musumeci <trapexit@spawn.link>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef __FS_FADVISE_HPP__
#define __FS_FADVISE_HPP__

#ifndef POSIX_FADV_NORMAL
# define POSIX_FADV_NORMAL 0
#endif

#ifndef POSIX_FADV_RANDOM
# define POSIX_FADV_RANDOM 1
#endif

#ifndef POSIX_FADV_SEQUENTIAL
# define POSIX_FADV_SEQUENTIAL 2
#endif

#ifndef POSIX_FADV_WILLNEED
# define POSIX_FADV_WILLNEED 3
#endif

#ifndef POSIX_FADV_DONTNEED
# define POSIX_FADV_DONTNEED 4
#endif

#ifndef POSIX_FADV_NOREUSE
# define POSIX_FADV_NOREUSE 5
#endif

namespace fs
{
  int
  fadvise(const int   fd,
          const off_t offset,
          const off_t len,
          const int   advice);
}

#endif // __FS_FADVISE_HPP__
