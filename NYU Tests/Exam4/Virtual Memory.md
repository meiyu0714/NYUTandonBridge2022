Not enough memory(when the memory is super expensive); Holes in our address space(memory split up)(Translation in the memory address and trick the program have the sequential address but they are not in the physical address); programs run over each other

Key words: page table/Translation, **Indirection**. 

If we have access to the same 32-bit memory space:

can crash if less than 4GB of RAM memory in the system; can run out of space; can corrupt other programs' data.

Without virtual memory: Program address = RAM address

Virtual memory gives us flexibility to use our memory(RAM memory + disk) 

page out: moves oldest data to disk(update the map table). **Give us the illusion of unlimited memory.**

You can split the program to RAM. we can put our program where ever we want.

Virtual memory can make your data more secure. Mapping ensures different programs use different physical addresses.(program isolation)=>(we can use the same mapping to allow programs to share data by simply having their maps point to the same data)

Virtual memory: what the programs sees. Physical address: the physical RAM in the computer. 

#### Page Table

One Page Table Entry for every Virtual Address. 2^30 words that need Page Table Entries(1 billion entries) If we don't have a Page table entry, we cannot access them because we cannot find the physical address. 

We divided memory up into chunks(pages) instead of words. We call a chunk of memory a page. each entry now covers **4kb of data**. So our page table is much smaller. 

The page Table manages large chunks(pages) of data. coarse-grain: maps chunks of address. 

The Page Table manages **larger chunks (pages)** of memory: - Fewer Page Table Entries needed to cover the whole address space. - But, **less flexibility** in how to use RAM(have to move a page at a time) Today- Typically 4kB per page(1024 words per page) 

we make 1 billion entries into 1 million Page Table Entries. Sometimes 2 MB per page. 

Virtual address => virtual page number(Page Table convert it to disk/RAM/ or Page offsets-> stay the same and do not change at all.)

If we have 64kB pages, how many bits do wo use for the page offset?->16 2^16 is 64k. so we use the lowest 16 bits as the page offset. 4kB->12 bits offset

#### What happens if the page is not in RAM?

If the Page Table Entry says the page is on disk. Hardware(CPU) generates a **page fault** exception. The hardware jumps to the OS page fault hander to clean up. The OS chooses a page to evict from RAM and write to disk. If the page is dirty, it need to be written back to disk first. The OS then reads the page fro disk and puts it in RAM. The OS then chages the Page table to map the new page. The OS then changes the Page Table to map the new page. The OS jumps back to the instruction that causes the page fault. Page faults are slowest possible thing that can happen to a computer. => that is why buying memory makes your computer faster. That is why buying more memory may make your computer faster. 

VM is great: -Unlimited program/memory, protection, flexibility, etc.

But it comes a t a high cost: - Every memory operation has to look up in the page table. - Need to access 1) page table 2) memory address(2* memory accesses)

How can we make a page table look up really really fast?

- software would be far too slow
- Perhaps a **hardware page table cache.** 

TLB(Translation Lookaside Buffer) = MMU(memory management unit)

Once we got data in TLB, it goes to be much faster. TLB must be smaller. processor pipeline.If it is not in the TLB, we look it up in the Full page table. => page either in the RAM/Disk 

1.Larger page.2. second TLB that is larger, but a bit slower. 3. Hardware 

How to find the physical address: 11) find the page number. by finding the virtual memory top numbers in the page table and find the physical page number and then find the page offset. If the translation is not in TLB or MMU, we find in the full page table in main memory,. And then we can do our translation.  And we record the location in the MMU or TLB.

#### Multi-level page table. 

**Each program needs its own page table.** We cannot swap the page tables out in the disk-> If the page table is not in the RAM, we have no way to access it to find it. By using multi-level page table, we can page our page table. So not all the page table need to be in the memory. 

With multi-level page tables, the smallest amount of page table data we need to keep in memory for each 32-bit application is 4kB+4kB. We always need the 1st level page table so we can find the 2nd level ones. But the 1st level page table only helps us to find other page tables. It isn't enough by itself to translate any program addresses. So we need at least 2nd level page table to actually translate memory addresses. It is much better for 4MB per program. If we have 100 applications, that is 100*(4kB + 4kB) or 800 kB. 

TLB(Translation Lookaside Buffer) is part of the chip's memory-management unit.

 总结：how faster: 1) faster because bigger page(4kB), smaller page table 2) hardware: faster than memory. TLB and MMU. cache.3) Multi-level page table.