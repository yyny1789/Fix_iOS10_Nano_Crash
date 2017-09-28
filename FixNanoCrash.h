//
//  FixNanoCrash.h
//  Client
//
//  Created by Yangyang on 2017/8/18.
//  Copyright © 2017年 36Kr. All rights reserved.
//

#ifndef FixNanoCrash_h
#define FixNanoCrash_h

#include <stdio.h>
#include <mach/vm_types.h>
#include <mach/vm_map.h>
#include <mach/mach_init.h>
#include <sys/sysctl.h>

void fix_nano_crash_if_enable();

#endif /* FixNanoCrash_h */
