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

####Access the SD Card (from a VM)
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

4. Now we need to `unmount` the volume, via `Utilities > DiskUtility` locate and select the SD Card and click on the `Unmount` button. It may be required to Unmount several time during the process since OS X Disk Arbitration Deamon or `diskarbitrationd` will attempt to mount unmounted devices (with mountable filesystems) such as the SD Card after a certain delay.

5. Next make your VM aware of the SD Card (as a raw device) by executing the following command in your terminal: 
```
$ VBoxManage internalcommands createrawvdmk -filename /path/to/file.vdmk -rawdisk /dev/disk1
```	

	The command above won't work as-is, since you are logged into your user account in OS X and a simple `sudo` won't do the trick either. **DO THIS AT YOUR OWN RISK, AND YOU SHOULD KNOW WHAT YOU ARE DOING BEFORE CHANGING ANY PERMISSIONS.** I found that the only way to actually do this, is to execute the following: `sudo chown $USER /dev/disk1` (disk1 in this case).
	
6. Attach the raw disk to a VM of your choosing, this is done via the GUI for VirtualBox:
    i. Ensure that the said VM is not running, and open the Settings via (⌘+s).
	ii. Then click on `Storage`, then click `Add Hard Disk` next to the Controller.
	iii. Select "Choose existing disk", and locate the `.vdmk` file you've just created then select it.
	iv. If everything was successful, the device should appear in the `Storage` tab.

7. Start the VM.

####Create the boot disk in Lubuntu 14.04 (VM) and Install on BBB
To create the boot disk in Lubuntu, I've followed the **excellent** instructions posted on the ArchLinux ARM [website](http://archlinuxarm.org/platforms/armv7/ti/beaglebone-black), in fact there is no need to replicate them here. I will only point out that on the BBB the eMMC is located in `/dev/mmcblkp[1|2]` where `/dev/mmcblkp1` is the bootable partition, and `/dev/mmcblkp2` is the filesystem. They do provide instructions on how-to install it on the actual BBB, on the same page.

##Next Step: Installing Docker on BBB
If you made that far, you should now have a BBB that runs on ArchLinuxARM and be ready to install Docker. Which is pretty straightforward, and the instructions are the same as for the ArchLinux `x86 architecture`. Let me just point out a couple of suggestions:

1. `ifconfig` is not installed by default in ArchLinux, I personally find it very useful when playing around with containers, and suggest to install it using `pacman -S net-tools` unless you are familiar with `iproute2`.
			

