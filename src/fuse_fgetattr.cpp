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

#include "config.hpp"
#include "errno.hpp"
#include "fileinfo.hpp"
#include "fs_fstat.hpp"
#include "fs_inode.hpp"

#include "fuse.h"


namespace FUSE
{
  int
  fgetattr(const fuse_file_info_t *ffi_,
           struct stat            *st_,
           fuse_timeouts_t        *timeout_)
  {
    int rv;
    Config::Read cfg;
    FileInfo *fi = reinterpret_cast<FileInfo*>(ffi_->fh);

    rv = fs::fstat(fi->fd,st_);
    if(rv == -1)
      return -errno;

    fs::inode::calc(fi->branchpath,
                    fi->fusepath,
                    st_);

    timeout_->entry = ((rv >= 0) ?
                       cfg->cache_entry :
                       cfg->cache_negative_entry);
    timeout_->attr  = cfg->cache_attr;

    return rv;
  }
}
