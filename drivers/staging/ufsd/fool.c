#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include "config.h"
#include "ufsdapi.h"

static void fool(const char * name)
{
	printk("fatal error: fool function %s called\n", name);
	mdelay(1000);
	BUG();
	*(int*)0=0;
}

#define MAKE_FOOL(x) void x(void){fool(#x);}

MAKE_FOOL(posix_acl_clone);
MAKE_FOOL(posix_acl_create_masq);
MAKE_FOOL(posix_acl_chmod_masq);
MAKE_FOOL(d_alloc_root);
MAKE_FOOL(_clear_bit_le);
MAKE_FOOL(__bug);
MAKE_FOOL(_test_and_set_bit_le);
MAKE_FOOL(get_sb_bdev);
MAKE_FOOL(block_sync_page);
MAKE_FOOL(_set_bit_le);

#if defined(UFSD_BUILT_AS_MODULE)
MAKE_FOOL(posix_acl_from_xattr);
MAKE_FOOL(posix_acl_valid);
MAKE_FOOL(posix_acl_permission);
MAKE_FOOL(posix_acl_equiv_mode);
MAKE_FOOL(posix_acl_to_xattr);
#endif
