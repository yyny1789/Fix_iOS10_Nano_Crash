//
//  FixNanoCrash.c
//  Client
//
//  Created by Yangyang on 2017/8/18.
//  Copyright © 2017年 36Kr. All rights reserved.
//

#include "FixNanoCrash.h"

void fix_nano_crash() {
    vm_size_t allocation_size = 1024 * 1024;
    vm_address_t startAddress = (vm_address_t)0x170000000;
    
    while (startAddress < (vm_address_t)0x180000000) {
        vm_allocate(mach_task_self(), &startAddress, allocation_size, 0);

        startAddress += allocation_size;
    }
}

int is_enable_fix_nano_crash() {
    cpu_type_t type;
    size_t size;
    size = sizeof(type);
    sysctlbyname("hw.cputype", &type, &size, NULL, 0);
    if (type != CPU_TYPE_ARM64)
    {
        return 0;
    }
    
    return 1;
}

void fix_nano_crash_if_enable() {
    if (is_enable_fix_nano_crash() == 1) {
        fix_nano_crash();
    }
}

