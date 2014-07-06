---
layout: post
title: Docker on BeagleBone Black using ArchLinux
---

With the recent interest in containers [LxC](https://linuxcontainers.org/), more specifically with [Docker](http://www.docker.com), I decided to create a cluster of 3 [BeagleBone Black](http://beagleboard.org/black) on which I could deploy Docker-based applications and tinker around with this new piece of technology. With no prior experience with the BBBs, nor Docker, this was a learning experience, thus pardon my many misguided assumptions or steps that I took on the way to success.

#Out of the box
The BBB runs a version of Linux called [Ångström](http://www.angstrom-distribution.org/) which was created in the scope of providing a stable user-friendly distribution with a focus on embedded devices. The BBBs are ARM-based embedded micro-computers, thus will only run ARM-based Linux distributions.

##First Attempt
My initial thoughts were that Docker would run on *any* Linux platform, and I was wrong. Therefore, my first attempt consisted of trying to install Docker on the BBB as-is, but to no avail, the Docker package is not part of the [opkg](http://en.wikipedia.org/wiki/Opkg) [list of packages](http://feeds.angstrom-distribution.org/feeds/unstable/ipk/glibc/armv7a/).
 
##Next Step: Choosing The Distribution
The next step was then to find a armv7 compatible Linux distribution that supported Docker. My choice was ArchLinux, having never used it before, I wasn't biased towards this distro it simply appeared to be the most active Linux ARM distribution that supported Docker. 

###Creating a Boot Disk in OS X (10.9.3)
In order to flash the BBBs with the ArchLinux distro, I needed to create a Boot Disk. I thought to myself simply download the OS then make a bootable disk with the SD Card and voilà! Not so fast... First OS-related problem, OS X doesn't handle [ext4](http://en.wikipedia.org/wiki/Ext4) out-of-the box although some [alternatives](http://apple.stackexchange.com/questions/29842/how-can-i-mount-an-ext4-file-system-on-os-x) exists, I decided to use my Lubuntu VM to create it and here's how I proceeded.

First to access an SD Card from the VM, since (as stated [here](http://superuser.com/questions/373463/how-to-access-an-sd-card-from-a-virtual-machine)) newer MacBook Pro's no longer exposes the SD Card slot as a USB device, we need to attach the raw device to the VM to a access the whole card and create/delete/modify all the partitions. In order to do this we followed these [instructions](http://superuser.com/a/458085), which are the following:

1. Insert the SD Card.
2. Identify raw device volume using the `mount` command:
```
TechnoCORE:~ danywilson$ mount
/dev/disk0s2 on / (hfs, local, journaled)
devfs on /dev (devfs, local, nobrowse)
map -hosts on /net (autofs, nosuid, automounted, nobrowse)
map auto_home on /home (autofs, automounted, nobrowse)
/dev/disk1s3 on /Volumes/Mac OS X Install DVD (hfs, local, nodev, nosuid, read-only, noowners)
/dev/disk2s2 on /Volumes/Silverlight (hfs, local, nodev, nosuid, read-only, noowners, quarantine, mounted by danywilson)
```
3. In this case the SD Card is represented by `/dev/disk1`.
4. Now we need to `unmount` the volume, via `Utilities > DiskUtility` locate and select the SD Card and click on the `Unmount` button. It may be required to Unmount several time during the process since OS X Disk Arbitration or `diskarbitrationd` will attempt to mount unmounted devices (with mountable filesystems) such as the SD Card after a certain delay.
5. Next
